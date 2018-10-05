/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new const Float:g_Round_SpawnPositions[][5] = {
    {-110.2534,		-1532.8452,		2.7159,		5.0,	5.0},
	{2782.3379,		-2019.2201,		13.5547,	5.0,	5.0},
    {-1733.4202,	-152.6932,		3.5547,		5.0,	5.0},
    {-1543.7382,	-2759.5620,		48.5391,	5.0,	5.0},
    {2328.9490,		1427.4639,		42.8203,	5.0,	5.0},
    {-523.7544,		2605.0623,		53.5703,	5.0,	5.0},
    {1519.7905,		-68.9950,		19.6781,	5.0,	5.0}
};
//------------------------------------------------------------------------------
new g_Round_StartingObject_ID = -1;
new g_Round_LoadedObjects;
new Float:g_Round_ArenaFacingAngles[2];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward Float:getRoundArenaFacingAngle(teamid);
Float:getRoundArenaFacingAngle(teamid) return ((TEAM_ONE <= teamid <= TEAM_TWO) ? g_Round_ArenaFacingAngles[teamid] : 0.0);
//------------------------------------------------------------------------------
deleteRoundObjects() {
	if(g_Round_StartingObject_ID != -1) {
		for(new i = g_Round_StartingObject_ID, ending_id = g_Round_StartingObject_ID + g_Round_LoadedObjects; i < ending_id; i ++) {
			if(i != g_MilitaryBaseObjects) DestroyObject(i);
			else ending_id ++;
		}
		g_Round_LoadedObjects = 0;
		g_Round_StartingObject_ID = -1;
	}
}
//------------------------------------------------------------------------------
startNewRound(type, mapid, bool:arenatdm = false) {
	new ret;
	if(g_Round_MapID == INVALID_MAP_ID && (ret = loadRoundData(type, mapid)) == 1) {
		
		new string[32];		
		
		if(type == ROUND_TYPE_ARENA && arenatdm) format(string, sizeof(string), "A-TDM ~w~%d", mapid);
		else format(string, sizeof(string), "%s ~w~%d", oftenUsedPhrases((type == ROUND_TYPE_ARENA ? LANG_OUP_ARENA : LANG_OUP_BASE), 0), mapid);
		
		string[0] = toupper(string[0]);
		TextDrawSetString(TD_Round_Start_Map, string);
		TextDrawSetString(TD_Round_Start_Teams[0], getTeamName(TEAM_ONE));
		TextDrawSetString(TD_Round_Start_Teams[1], getTeamName(TEAM_TWO));
		
		if(getMatchStatus()) {
			getTextDrawShortMessage(string, TD_SHORT_MESSAGE_ROUND, 1);
			format(string, sizeof(string), string, getRoundCounterValue() + 1, getMatchRoundLimit());		
		} else {
			getTextDrawShortMessage(string, TD_SHORT_MESSAGE_ROUND, 0);
			format(string, sizeof(string), string, getRoundCounterValue() + 1);
		}
		TextDrawSetString(TD_Round_Start_Round, string);
		
		#if SHORT_ROUND != 1
		g_Round_Time = getRoundTime(type, true);
		#else
		g_Round_Time = 3;
		#endif
		g_Round_RandomKey = random(999999999) + 1;
		g_Round_MapID = mapid;
		setArenaTDMPoints(TEAM_ONE, 0);
		setArenaTDMPoints(TEAM_TWO, 0);
		
		for(new i; i < 5; i ++) SendDeathMessage(MAX_PLAYERS + 1, MAX_PLAYERS + 1, 0);

		if((g_Round_Type = type) == ROUND_TYPE_BASE) {
			TextDrawColor(TD_RoundBar_Time, -1);
			setArenaTDMModeStatus(false);
			g_Round_FlagObjectID = CreateObject(2993, CP_Position(0), CP_Position(1), CP_Position(2) - 1,0,0,0);
			SetObjectMaterial(g_Round_FlagObjectID, 1, -1, "none", "none", 0xFFFF0000);		
			g_Round_GangZones[0] = GangZoneCreate(g_Round_Data[SPAWN_TEAM_1][SPAWN_X] - CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_Y] - CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_X] + CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_Y] + CAR_SPAWN_DIS);	
			if(getZonePosition(0) != -99999.0 && getDefendersBaseStatus()) {
				g_Round_GangZones[1] = GangZoneCreate(getZonePosition(0), getZonePosition(1), getZonePosition(2), getZonePosition(3));	
			}
		} else {
			TextDrawColor(TD_RoundBar_Time, (arenatdm ? 126869759 : -1));
			setArenaTDMModeStatus(arenatdm);
		}
		
		setRoundState(ROUND_STATE_STARTING);
		
		forplayers(i) {
			setPlayerRoundRandomKey(i, -1);
			showPlayerStartingCamera(i);
		}		
		
		resetFirstBloodPlayer();
		StartRoundCountdown(ROUND_COUNTDOWN_TIME);
		return 1;
	}
	
	if(ret == -1) deleteRoundObjects();
	
	return ret;
}
//------------------------------------------------------------------------------
loadRoundData(type, mapid) {
	new string[256];
	format(string, sizeof(string), "%s/%d.ini", type == ROUND_TYPE_ARENA ? (DIR_ARENAS) : (DIR_BASES), mapid);
	if(fexist(string)) {
	    new File:f_map = fopen(string, io_read);
	    new index;
		//-----------------------------
	    new load_Interior = 0,
	    	Float:load_Spawn_Team_1[5] = {-99999.0, -99999.0, -99999.0, -99999.0, -99999.0},
	    	Float:load_Spawn_Team_2[5] = {-99999.0, -99999.0, -99999.0, -99999.0, -99999.0},
	    	Float:load_Checkpoint[3] = {-99999.0, -99999.0, -99999.0},
	    	Float:load_Spawn_Boats[5] = {-99999.0, -99999.0, -99999.0, -99999.0, -99999.0},
	    	Float:load_Zone[6] = {-99999.0, -99999.0, -99999.0, -99999.0, -99999.0, -99999.0},
			Float:load_Camera_Data[3], camera_index,
	    	Float:load_CameraPos[MAX_CAMERA_POSITIONS][3] = {{-99999.0, -99999.0, -99999.0}, {-99999.0, -99999.0, -99999.0}, {-99999.0, -99999.0, -99999.0}, {-99999.0, -99999.0, -99999.0}, {-99999.0, -99999.0, -99999.0}},
			Float:load_ObjectPos[6], load_ObjectModel;
	    //-----------------------------
	    while(fread(f_map, string, sizeof(string))) {
	        if((index = strfind(string, "\r")) != -1) string[index] = EOS;
	        if((index = strfind(string, "\n")) != -1) string[index] = EOS;
			if(!isnull(string)) {
				while((index = strfind(string, " ")) != -1) strdel(string, index, index + 1);
			}			
	        if(((index = strfind(string, "=")) > 0 || (index = strfind(string, ":")) > 0) && index + 1 < strlen(string)) {
	            if(strcmp(string, "interior", true, index) == 0 && type == ROUND_TYPE_ARENA) {
					if(!('0' <= string[index + 1] <= '9' && 18 >= (load_Interior = strval(string[index + 1])) >= 0)) {
						printf("Int: %s", string[index + 1]);
						load_Interior = -1;
					}
	            } else if(strcmp(string, "team_1", true, index) == 0) {
					if(sscanf(string[index + 1], "p<,>fffff", load_Spawn_Team_1[0], load_Spawn_Team_1[1], load_Spawn_Team_1[2], load_Spawn_Team_1[3], load_Spawn_Team_1[4]) != 0) {
						if(sscanf(string[index + 1], "p<,>fff", load_Spawn_Team_1[0], load_Spawn_Team_1[1], load_Spawn_Team_1[2]) != 0) {
							load_Spawn_Team_1[0] = load_Spawn_Team_1[1] = load_Spawn_Team_1[2] = load_Spawn_Team_1[3] = load_Spawn_Team_1[4] = -99999.0;
						} else {
							load_Spawn_Team_1[3] = load_Spawn_Team_1[4] = 0.0;
						}
					}
	            } else if(strcmp(string, "team_2", true, index) == 0) {
					if(sscanf(string[index + 1], "p<,>fffff", load_Spawn_Team_2[0], load_Spawn_Team_2[1], load_Spawn_Team_2[2], load_Spawn_Team_2[3], load_Spawn_Team_2[4]) != 0) {
						if(sscanf(string[index + 1], "p<,>fff", load_Spawn_Team_2[0], load_Spawn_Team_2[1], load_Spawn_Team_2[2]) != 0) {
							load_Spawn_Team_2[0] = load_Spawn_Team_2[1] = load_Spawn_Team_2[2] = load_Spawn_Team_2[3] = load_Spawn_Team_2[4] = -99999.0;
						} else {
							load_Spawn_Team_2[3] = load_Spawn_Team_2[4] = 0.0;
						}
					}	
	            } else if(strcmp(string, "checkpoint", true, index) == 0) {
					if(sscanf(string[index + 1], "p<,>fff", load_Checkpoint[0], load_Checkpoint[1], load_Checkpoint[2]) != 0) {
						load_Checkpoint[0] = load_Checkpoint[1] = load_Checkpoint[2] = -99999.0;
					}
	            } else if(strcmp(string, "camera", true, index) == 0) {
					if(sscanf(string[index + 1], "p<,>dfff", camera_index, load_Camera_Data[0], load_Camera_Data[1], load_Camera_Data[2]) != 0) {
						if(sscanf(string[index + 1], "p<,>fff", load_Camera_Data[0], load_Camera_Data[1], load_Camera_Data[2]) != 0) {
							load_Camera_Data[0] = load_Camera_Data[1] = load_Camera_Data[2] = -99999.0;
							camera_index = -1;
						} else camera_index = 0;
					}	
					if(MAX_CAMERA_POSITIONS > camera_index >= 0 && load_Camera_Data[0] != -99999.0 && load_Camera_Data[1] != -99999.0 && load_Camera_Data[2] != -99999.0) {
						load_CameraPos[camera_index][0] = load_Camera_Data[0];
						load_CameraPos[camera_index][1] = load_Camera_Data[1];
						load_CameraPos[camera_index][2] = load_Camera_Data[2];
					}				
	            } else if(strcmp(string, "boat_spawn", true, index) == 0 && type == ROUND_TYPE_BASE) {
					if(sscanf(string[index + 1], "p<,>fffff", load_Spawn_Boats[0], load_Spawn_Boats[1], load_Spawn_Boats[2], load_Spawn_Boats[3], load_Spawn_Boats[4]) != 0) {
						if(sscanf(string[index + 1], "p<,>fff", load_Spawn_Boats[0], load_Spawn_Boats[1], load_Spawn_Boats[2]) != 0) {
							load_Spawn_Boats[0] = load_Spawn_Boats[1] = load_Spawn_Boats[2] = load_Spawn_Boats[3] = load_Spawn_Boats[4] = -99999.0;
						} else {
							load_Spawn_Boats[3] = load_Spawn_Boats[4] = 0.0;
						}
					}		
	            } else if(strcmp(string, "zone", true, index) == 0) {
	                //min_x, min_y, max_x, max_y, min_z, max_z
					if(sscanf(string[index + 1], "p<,>ffffff", load_Zone[0], load_Zone[1], load_Zone[2], load_Zone[3], load_Zone[4], load_Zone[5]) != 0) {
						if(sscanf(string[index + 1], "p<,>ffff", load_Zone[0], load_Zone[1], load_Zone[2], load_Zone[3]) != 0) {
							load_Zone[0] = load_Zone[1] = load_Zone[2] = load_Zone[3] = load_Zone[4] = load_Zone[5] = -99999.0;
						} else {
							load_Zone[4] = -9999.0;
							load_Zone[5] = 9999.0;
						}
					}		
				} else if(strcmp(string, "object", true, index) == 0) {
					if(sscanf(string[index + 1], "p<,>dffffff", load_ObjectModel, load_ObjectPos[0], load_ObjectPos[1], load_ObjectPos[2], load_ObjectPos[3], load_ObjectPos[4], load_ObjectPos[5]) == 0) {
						new objectid;
						if((objectid = CreateObject(load_ObjectModel, load_ObjectPos[0], load_ObjectPos[1], load_ObjectPos[2], load_ObjectPos[3], load_ObjectPos[4], load_ObjectPos[5])) > 0) {
							if(g_Round_StartingObject_ID == -1) g_Round_StartingObject_ID = objectid;							
							g_Round_LoadedObjects ++;
						}					
					}
				}
	        }
	    }	    
	    //-----------------------------------
		if(!(18 >= load_Interior >= 0)) {
			getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 0);
			format(string, sizeof(string), string, mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
			logRoundStart_Error(string);
			return -1;
		}		
		if(!(-9999.0 <= load_Spawn_Team_2[0] <= 9999.0 && -9999.0 <= load_Spawn_Team_2[1] <= 9999.0 && -9999.0 <= load_Spawn_Team_2[2] <= 9999.0)) {
			getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 1);
			format(string, sizeof(string), string, "team_2", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))), load_Spawn_Team_2[0], load_Spawn_Team_2[1], load_Spawn_Team_2[2], load_Spawn_Team_2[3], load_Spawn_Team_2[4]);
			logRoundStart_Error(string);
			return -1;
		}
		if(!(-9999.0 <= load_Checkpoint[0] <= 9999.0 && -9999.0 <= load_Checkpoint[1] <= 9999.0 && -9999.0 <= load_Checkpoint[2] <= 9999.0)) {
			getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 3);
			format(string, sizeof(string), string, "checkpoint", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))), load_Checkpoint[0], load_Checkpoint[1], load_Checkpoint[2]);
			logRoundStart_Error(string);		
			return -1;
		}
	    //-----------------------------------	
	    if(type == ROUND_TYPE_ARENA)  {
			if(!(-9999.0 <= load_Spawn_Team_1[0] <= 9999.0 && -9999.0 <= load_Spawn_Team_1[1] <= 9999.0 && -9999.0 <= load_Spawn_Team_1[2] <= 9999.0)) {
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 1);
				format(string, sizeof(string), string, "team_1", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))), load_Spawn_Team_1[0], load_Spawn_Team_1[1], load_Spawn_Team_1[2], load_Spawn_Team_1[3], load_Spawn_Team_1[4]);
				logRoundStart_Error(string);			
				return -1;
			}
			if(!(1.0 <= load_Spawn_Team_1[3] <= 100.0)) load_Spawn_Team_1[3] = 2.0;
			if(!(1.0 <= load_Spawn_Team_1[4] <= 100.0)) load_Spawn_Team_1[4] = 2.0;
			
			g_Round_ArenaFacingAngles[TEAM_ONE] = angleToPoint(load_Spawn_Team_1[0], load_Spawn_Team_1[1], load_Checkpoint[0], load_Checkpoint[1]);
			g_Round_ArenaFacingAngles[TEAM_TWO] = angleToPoint(load_Spawn_Team_2[0], load_Spawn_Team_2[1], load_Checkpoint[0], load_Checkpoint[1]);
			
	    } else {
			if(!(-9999.0 <= load_Spawn_Team_1[0] <= 9999.0 && -9999.0 <= load_Spawn_Team_1[1] <= 9999.0 && -9999.0 <= load_Spawn_Team_1[2] <= 9999.0)) {
				new base_position;			
				for(new i, Float:max_length = 9999999.0, Float:cur_length; i < sizeof(g_Round_SpawnPositions); i ++) {
					if((cur_length = VectorSize(load_Checkpoint[0] - g_Round_SpawnPositions[i][0], load_Checkpoint[1] - g_Round_SpawnPositions[i][1], load_Checkpoint[2] - g_Round_SpawnPositions[i][2])) <= max_length) {
						base_position = i;
						max_length = cur_length;
					}
				}
				if(load_Spawn_Team_1[0] != -99999.0 || load_Spawn_Team_1[1] != -99999.0 || load_Spawn_Team_1[2] != -99999.0) {
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 1);
					format(string, sizeof(string), string, "team_1", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))), load_Spawn_Team_1[0], load_Spawn_Team_1[1], load_Spawn_Team_1[2], load_Spawn_Team_1[3], load_Spawn_Team_1[4]);
					logRoundStart_Error(string);	
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 4);
					format(string, sizeof(string), string, g_Round_SpawnPositions[0], g_Round_SpawnPositions[1], g_Round_SpawnPositions[2], g_Round_SpawnPositions[3], g_Round_SpawnPositions[4]);
					logRoundStart_Error(string);	
				}
				load_Spawn_Team_1[0] = g_Round_SpawnPositions[base_position][0];
				load_Spawn_Team_1[1] = g_Round_SpawnPositions[base_position][1];
				load_Spawn_Team_1[2] = g_Round_SpawnPositions[base_position][2];
				load_Spawn_Team_1[3] = g_Round_SpawnPositions[base_position][3];
				load_Spawn_Team_1[4] = g_Round_SpawnPositions[base_position][4];
			}		
			
			if(!(-9999.0 <= load_Spawn_Boats[0] <= 9999.0 && -9999.0 <= load_Spawn_Boats[1] <= 9999.0 && -9999.0 <= load_Spawn_Boats[2] <= 9999.0)) {
				if(load_Spawn_Boats[0] != -99999.0 || load_Spawn_Boats[1] != -99999.0 || load_Spawn_Boats[2] != -99999.0) {
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 1);
					format(string, sizeof(string), string, "boat_spawn", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))), load_Spawn_Boats[0], load_Spawn_Boats[1], load_Spawn_Boats[2], load_Spawn_Boats[3], load_Spawn_Boats[4]);
					logRoundStart_Error(string);
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 5);
					logRoundStart_Error(string);					
				}
				load_Spawn_Boats[0] = load_Spawn_Boats[1] = load_Spawn_Boats[2] = load_Spawn_Boats[3] = load_Spawn_Boats[4] = -99999.0;
			} else {
				if(!(1.0 <= load_Spawn_Boats[3] <= 100.0)) load_Spawn_Boats[3] = 10.0;
				if(!(1.0 <= load_Spawn_Boats[4] <= 100.0)) load_Spawn_Boats[3] = 10.0;
			}
			//-------------------------------
	    }
		
		if(!(1.0 <= load_Spawn_Team_1[3] <= 100.0)) load_Spawn_Team_1[3] = 2.0;
		if(!(1.0 <= load_Spawn_Team_1[4] <= 100.0)) load_Spawn_Team_1[4] = 2.0;
	    //-----------------------------
		if(!(-9999.0 <= load_Zone[0] <= 9999.0 && -9999.0 <= load_Zone[1] <= 9999.0 && -9999.0 <= load_Zone[2] <= 9999.0 && -9999.0 <= load_Zone[3] <= 9999.0)) {
			if(!(load_Zone[0] == -99999.0 && load_Zone[1] == -99999.0 && load_Zone[2] == -99999.0 && load_Zone[3] == -99999.0)) {
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 6);
				format(string, sizeof(string), string, "zone", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
				logRoundStart_Error(string);
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 2);
				format(string, sizeof(string), string, load_Zone[0], load_Zone[1], load_Zone[2], load_Zone[3], load_Zone[4], load_Zone[5]);
				logRoundStart_Error(string);	
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 5);
				logRoundStart_Error(string);	
			}
			load_Zone[0] = load_Zone[1] = load_Zone[2] = load_Zone[3] = load_Zone[4] = load_Zone[5] = -99999.0;
		} else {
			if(!(load_Zone[0] < load_Zone[2] && load_Zone[1] < load_Zone[3])) {
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 6);
				format(string, sizeof(string), string, "zone", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
				logRoundStart_Error(string);
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 7);
				format(string, sizeof(string), string, load_Zone[0], load_Zone[2], (load_Zone[0] < load_Zone[2] ? ("true") : ("false")), load_Zone[1], load_Zone[3], (load_Zone[1] < load_Zone[3] ? ("true") : ("false")));
				logRoundStart_Error(string);				
				getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 5);
				logRoundStart_Error(string);
				load_Zone[0] = load_Zone[1] = load_Zone[2] = load_Zone[3] = load_Zone[4] = load_Zone[5] = -99999.0;	
			}
		}
		if(!(load_Zone[0] == -99999.0 && load_Zone[1] == -99999.0 && load_Zone[2] == -99999.0 && load_Zone[3] == -99999.0)) {
			if(load_Zone[4] >= load_Zone[5]) {
				if(load_Zone[5] != -99999.0) {
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 6);
					format(string, sizeof(string), string, "zone", mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
					logRoundStart_Error(string);
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 8);
					format(string, sizeof(string), string, load_Zone[4], load_Zone[5], (load_Zone[4] < load_Zone[5] ? ("true") : ("false")));
					logRoundStart_Error(string);								
				}
				if(load_Zone[4] == -99999.0 || load_Zone[4] == 9999.0) load_Zone[4] = -9999.0;
				load_Zone[5] = 9999.0;
			}
			
			if(type == ROUND_TYPE_ARENA) {			
				new Float:team_one_MinX, Float:team_one_MaxX, Float:team_one_MinY, Float:team_one_MaxY, Float:team_one_Z,
					Float:team_two_MinX, Float:team_two_MaxX, Float:team_two_MinY, Float:team_two_MaxY, Float:team_two_Z;
					
				team_one_MinX = load_Spawn_Team_1[0] - load_Spawn_Team_1[3];
				team_one_MaxX = load_Spawn_Team_1[0] + load_Spawn_Team_1[3];
				team_one_MinY = load_Spawn_Team_1[1] - load_Spawn_Team_1[4];
				team_one_MaxY = load_Spawn_Team_1[1] + load_Spawn_Team_1[4];				
				team_one_Z = load_Spawn_Team_1[2];
				
				team_two_MinX = load_Spawn_Team_2[0] - load_Spawn_Team_2[3];
				team_two_MaxX = load_Spawn_Team_2[0] + load_Spawn_Team_2[3];
				team_two_MinY = load_Spawn_Team_2[1] - load_Spawn_Team_2[4];
				team_two_MaxY = load_Spawn_Team_2[1] + load_Spawn_Team_2[4];				
				team_two_Z = load_Spawn_Team_2[2];
				
				if(!(load_Zone[0] < team_one_MinX && load_Zone[2] > team_one_MaxX && load_Zone[1] < team_one_MinY && load_Zone[3] > team_one_MaxY && load_Zone[4] < team_one_Z < load_Zone[5]) || !(load_Zone[0] < team_two_MinX && load_Zone[2] > team_two_MaxX && load_Zone[1] < team_two_MinY && load_Zone[3] > team_two_MaxY && load_Zone[4] < team_two_Z < load_Zone[5])) {
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 9);
					format(string, sizeof(string), string, mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
					logRoundStart_Error(string);
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 10);
					format(string, sizeof(string), string, "team_1", load_Zone[0], team_one_MinX, (load_Zone[0] < team_one_MinX ? ("true") : ("false")), load_Zone[2], team_one_MaxX, (load_Zone[2] < team_one_MaxX ? ("true") : ("false")), load_Zone[1], team_one_MinY, (load_Zone[1] < team_one_MinY ? ("true") : ("false")), load_Zone[3], team_one_MaxY, (load_Zone[3] < team_one_MaxY ? ("true") : ("false")), load_Zone[4], team_one_Z, load_Zone[5], (load_Zone[4] < team_one_Z < load_Zone[5] ? ("true") : ("false")));
					logRoundStart_Error(string);
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 10);
					format(string, sizeof(string), string, "team_2", load_Zone[0], team_two_MinX, (load_Zone[0] < team_two_MinX ? ("true") : ("false")), load_Zone[2], team_two_MaxX, (load_Zone[2] < team_two_MaxX ? ("true") : ("false")), load_Zone[1], team_two_MinY, (load_Zone[1] < team_two_MinY ? ("true") : ("false")), load_Zone[3], team_two_MaxY, (load_Zone[3] < team_two_MaxY ? ("true") : ("false")), load_Zone[4], team_two_Z, load_Zone[5], (load_Zone[4] < team_two_Z < load_Zone[5] ? ("true") : ("false")));
					logRoundStart_Error(string);						
					return -1;
				}
			} else {
				new Float:team_two_MinX, Float:team_two_MaxX, Float:team_two_MinY, Float:team_two_MaxY, Float:team_two_Z;
				
				team_two_MinX = load_Spawn_Team_2[0] - load_Spawn_Team_2[3];
				team_two_MaxX = load_Spawn_Team_2[0] + load_Spawn_Team_2[3];
				team_two_MinY = load_Spawn_Team_2[1] - load_Spawn_Team_2[4];
				team_two_MaxY = load_Spawn_Team_2[1] + load_Spawn_Team_2[4];				
				team_two_Z = load_Spawn_Team_2[2];
				if(!(load_Zone[0] < team_two_MinX && load_Zone[2] > team_two_MaxX && load_Zone[1] < team_two_MinY && load_Zone[3] > team_two_MaxY && load_Zone[4] < team_two_Z < load_Zone[5])) {
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 9);
					format(string, sizeof(string), string, mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
					logRoundStart_Error(string);
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 10);
					format(string, sizeof(string), string, "team_2", load_Zone[0], team_two_MinX, (load_Zone[0] < team_two_MinX ? ("true") : ("false")), load_Zone[2], team_two_MaxX, (load_Zone[2] < team_two_MaxX ? ("true") : ("false")), load_Zone[1], team_two_MinY, (load_Zone[1] < team_two_MinY ? ("true") : ("false")), load_Zone[3], team_two_MaxY, (load_Zone[3] < team_two_MaxY ? ("true") : ("false")), load_Zone[4], team_two_Z, load_Zone[5], (load_Zone[4] < team_two_Z < load_Zone[5] ? ("true") : ("false")));
					logRoundStart_Error(string);							
					getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, 11);
					logRoundStart_Error(string);
				}
			}
		}		
		//-----------------------------
		camera_index = -1;		
		for(new i; i < MAX_CAMERA_POSITIONS; i ++) {
			if(-9999.0 <= load_CameraPos[i][0] <= 9999.0 && -9999.0 <= load_CameraPos[i][1] <= 9999.0 && -9999.0 <= load_CameraPos[i][2] <= 9999.0) {
				if(camera_index == -1) camera_index = i;
				g_Round_StartingCamera[i][0] = load_CameraPos[i][0];
				g_Round_StartingCamera[i][1] = load_CameraPos[i][1];
				g_Round_StartingCamera[i][2] = load_CameraPos[i][2];				
			} else {
				g_Round_StartingCamera[i][0] = g_Round_StartingCamera[i][1] = g_Round_StartingCamera[i][2] = -99999.0;
			}
		}
		
		if(camera_index != -1) {
			load_Camera_Data[0] = g_Round_StartingCamera[camera_index][0];
			load_Camera_Data[1] = g_Round_StartingCamera[camera_index][1];
			load_Camera_Data[2] = g_Round_StartingCamera[camera_index][2];
			
			for(new i; i < MAX_CAMERA_POSITIONS; i ++) {
				if(g_Round_StartingCamera[i][0] == -99999.0) {
					g_Round_StartingCamera[i][0] = load_Camera_Data[0];
					g_Round_StartingCamera[i][1] = load_Camera_Data[1];
					g_Round_StartingCamera[i][2] = load_Camera_Data[2];	
				} else {
					load_Camera_Data[0] = g_Round_StartingCamera[i][0];
					load_Camera_Data[1] = g_Round_StartingCamera[i][1];
					load_Camera_Data[2] = g_Round_StartingCamera[i][2];				
				}
			}			
		} else {
			for(new i; i < MAX_CAMERA_POSITIONS; i ++) {
				g_Round_StartingCamera[i][0] = load_Checkpoint[0] + 150.0;
				g_Round_StartingCamera[i][1] = load_Checkpoint[1] + 50.0;
				g_Round_StartingCamera[i][2] = load_Checkpoint[2] + 70.0;				
			}
		}

		//-----------------------------
		fclose(f_map);
		//-----------------------------
		g_Round_Data[INTERIOR] = load_Interior;
		g_Round_Data[SPAWN_TEAM_1][SPAWN_X] = load_Spawn_Team_1[0];
		g_Round_Data[SPAWN_TEAM_1][SPAWN_Y] = load_Spawn_Team_1[1];
		g_Round_Data[SPAWN_TEAM_1][SPAWN_Z] = load_Spawn_Team_1[2];
		g_Round_Data[SPAWN_TEAM_1][SPAWN_VX] = floatround(load_Spawn_Team_1[3]);
		g_Round_Data[SPAWN_TEAM_1][SPAWN_VY] = floatround(load_Spawn_Team_1[4]);
		g_Round_Data[SPAWN_TEAM_2][SPAWN_X] = load_Spawn_Team_2[0];
		g_Round_Data[SPAWN_TEAM_2][SPAWN_Y] = load_Spawn_Team_2[1];
		g_Round_Data[SPAWN_TEAM_2][SPAWN_Z] = load_Spawn_Team_2[2];
		g_Round_Data[SPAWN_TEAM_2][SPAWN_VX] = floatround(load_Spawn_Team_2[3]);
		g_Round_Data[SPAWN_TEAM_2][SPAWN_VY] = floatround(load_Spawn_Team_2[4]);	
		g_Round_Data[CHECKPOINT][0] = load_Checkpoint[0];
		g_Round_Data[CHECKPOINT][1] = load_Checkpoint[1];
		g_Round_Data[CHECKPOINT][2] = load_Checkpoint[2];
		g_Round_Data[SPAWN_BOATS][SPAWN_X] = load_Spawn_Boats[0];
		g_Round_Data[SPAWN_BOATS][SPAWN_Y] = load_Spawn_Boats[1];
		g_Round_Data[SPAWN_BOATS][SPAWN_Z] = load_Spawn_Boats[2];
		g_Round_Data[SPAWN_BOATS][SPAWN_VX] = floatround(load_Spawn_Boats[3]);
		g_Round_Data[SPAWN_BOATS][SPAWN_VY] = floatround(load_Spawn_Boats[4]);
		g_Round_Data[ZONE][0] = load_Zone[0];
		g_Round_Data[ZONE][1] = load_Zone[1];
		g_Round_Data[ZONE][2] = load_Zone[2];			
		g_Round_Data[ZONE][3] = load_Zone[3];
		g_Round_Data[ZONE][4] = load_Zone[4];
		g_Round_Data[ZONE][5] = load_Zone[5];				
		
		return 1;
	} else {
		new src[64];
		strins(src, string, 0);
		getConsoleMessage(string, CONSOLE_MESSAGE_ROUND_START_ERROR, -1);
		format(string, sizeof(string), string, src, mapid, (type == ROUND_TYPE_ARENA ? (oftenUsedPhrases(LANG_OUP_ARENA, 0)) : (oftenUsedPhrases(LANG_OUP_BASE, 0))));
		logRoundStart_Error(string);	
	}
	return 0;
}