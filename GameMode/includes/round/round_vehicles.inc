/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define ROUND_CARS_NITRO				1
#define ROUND_CARS_HYDRAULICS			2
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Round_VehicleID[MAX_PLAYERS] = {-1, -1, -1, ...};
//------------------------------------------------------------------------------
new g_Round_Vehicles_Tuning = ROUND_CARS_NITRO + ROUND_CARS_HYDRAULICS;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getPlayerRoundVehicleID(&playerid) return g_Player_Round_VehicleID[playerid];
//------------------------------------------------------------------------------
getVehicleTuningFlags() return g_Round_Vehicles_Tuning;
setVehicleTuningFlags(flags) {
	if(0 <= flags <= 3) {
		g_Round_Vehicles_Tuning = flags;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
addVehicleTuningFlag(flag) {
	if(ROUND_CARS_NITRO <= flag <= ROUND_CARS_HYDRAULICS) {
		if(!(g_Round_Vehicles_Tuning & flag)) g_Round_Vehicles_Tuning += flag;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
removeVehicleTuningFlag(flag) {
	if(ROUND_CARS_NITRO <= flag <= ROUND_CARS_HYDRAULICS) {
		if(g_Round_Vehicles_Tuning & flag) g_Round_Vehicles_Tuning -= flag;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
givePlayerRoundVehicle(&playerid, modelid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && getRoundType() == ROUND_TYPE_BASE && 611 >= modelid >= 400 && getPlayerTeam(playerid) != getDefendingTeam()) {
		if(getVehicleFlagsByModel(modelid) & VEHICLE_ROUND_SPAWN) {
			if(!IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_Z]) && !IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_Z))) return -1;

			if(getVehicleTypeByModel(modelid) == TYPE_BOAT && getBoatSpawnPosition(SPAWN_X) == -99999.0) {
				getDialogBodyMessage(g_Chat_String, DIALOG_BODY_VEHICLE_TYPES, 2);
				showPlayerBackDialog(playerid, BACK_VEHICLE_NAMES, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), g_Chat_String);				
				return 1;
			}		
			
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			
			forplayers(i) {
				if(i != playerid && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) != getDefendingTeam() && IsPlayerInRangeOfPoint(i, 5.0, x, y, z)) {
					getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 3);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					return 1;
				}
			}
			
			
			new Float:a, name[20], VEHICLE_TYPES:vehtype;
			if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
			destroyPlayerRoundVehicle(playerid, true);	
			
			if((vehtype = getVehicleTypeByModel(modelid)) == TYPE_BOAT) {
				x = circleVariation(getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_VX));
				y = circleVariation(getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_VY));
				z = getBoatSpawnPosition(SPAWN_Z);
			} else {
				if(IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_Z))) {
					x = circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_VX]);
					y = circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_VY]);
					z = g_Round_Data[SPAWN_TEAM_1][SPAWN_Z];				
				} else GetPlayerPos(playerid, x, y, z);		
			}
			GetPlayerFacingAngle(playerid, a);
			g_Player_Round_VehicleID[playerid] = CreateVehicle(modelid, x, y, z, a, (getPlayerTeam(playerid) == TEAM_ONE ? 3 : 79), 1, -1);
			if(((g_Round_Vehicles_Tuning & ROUND_CARS_NITRO) || (g_Round_Vehicles_Tuning & ROUND_CARS_HYDRAULICS)) && (vehtype == TYPE_INDUSTRIAL || vehtype == TYPE_OFFROAD || vehtype == TYPE_PUBLIC_SERVICES || vehtype == TYPE_CABRIOLET || vehtype == TYPE_LOWRIDER || vehtype == TYPE_SPORT_CAR || vehtype == TYPE_COMBI || vehtype == TYPE_NORMAL_CAR)) {
				if(g_Round_Vehicles_Tuning & ROUND_CARS_NITRO) AddVehicleComponent(g_Player_Round_VehicleID[playerid], 1010);
				if(g_Round_Vehicles_Tuning & ROUND_CARS_HYDRAULICS) AddVehicleComponent(g_Player_Round_VehicleID[playerid], 1087);
			}					
			SetVehicleVirtualWorld(g_Player_Round_VehicleID[playerid], VW_ROUND);
			PutPlayerInVehicle(playerid, g_Player_Round_VehicleID[playerid], 0);
			getVehicleNameByModel(modelid, name);		
			getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 0);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, name, modelid);
		//	strins(name, "~w~", 0);
		//	GameTextForPlayer(playerid, name, 5000, 1);
			SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			
	//		printf("Creating new vehicle: %d | %d | %d", playerid, g_Player_Round_VehicleID[playerid], modelid);
			return 1;
		} else return -2;
	}
	return 0;
}
//------------------------------------------------------------------------------
destroyPlayerRoundVehicle(&playerid, bool:checkplayers = false) {
//	printf("destroyPlayerRoundVehicle: %d | %d | %d  << %d >>", playerid, checkplayers, g_Player_Round_VehicleID[playerid], g_Player_Round_VehicleID[playerid] != -1);
	if(g_Player_Round_VehicleID[playerid] != -1) {
		if(checkplayers == true) {
			forplayers(i) {
		//		printf("Checking ID %d: %d != %d (%d) && %d == PLAYER_STATUS_IN_ROUND (%d) && %d != %d && %d  << %d >>", i, i, playerid, i != playerid, getPlayerStatus(i), getPlayerTeam(i), getDefendingTeam(), getPlayerTeam(i) != getDefendingTeam(), IsPlayerInVehicle(i, g_Player_Round_VehicleID[playerid]), (i != playerid && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) != getDefendingTeam() && IsPlayerInVehicle(i, g_Player_Round_VehicleID[playerid])));
				if(i != playerid && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) != getDefendingTeam() && IsPlayerInVehicle(i, g_Player_Round_VehicleID[playerid])) {
		//			printf("Founded: %d | %d  << %d >>", i, g_Player_Round_VehicleID[i], g_Player_Round_VehicleID[i] != -1);
					if(g_Player_Round_VehicleID[i] != -1) {
						destroyPlayerRoundVehicle(i, true);
					}
					g_Player_Round_VehicleID[i] = g_Player_Round_VehicleID[playerid];
					g_Player_Round_VehicleID[playerid] = -1;
					return 1;
				}
			}			
		}
	//	printf("Destroying: %d | %d", playerid, g_Player_Round_VehicleID[playerid]);
		if(IsPlayerInVehicle(playerid, g_Player_Round_VehicleID[playerid])) RemovePlayerFromVehicle(playerid);
		DestroyVehicle(g_Player_Round_VehicleID[playerid]);
		g_Player_Round_VehicleID[playerid] = -1;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
updateRoundVehicleTime(&vehicleid, &playerid) {

}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerRoundVehSelectMenu(playerid, listitem = -1) {
	if(getPlayerTeam(playerid) != getDefendingTeam() && getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_BASE) {
		if(!IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_Z]) && !IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_Z))) return -1;	
		
		if(listitem == -1) {
	//		new string[400];
			getDialogBodyMessage(g_String_512, DIALOG_BODY_VEHICLE_TYPES, 0);
			ShowPlayerDialog(playerid, DIALOG_ROUND_VEHICLES_TYPES, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));
		} else {
			SetPVarInt(playerid, PV_HELP_VAR_1, listitem);
			showPlayerRoundVehNames(playerid);
		}
		return 1;	
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRoundVehNames(playerid, listitem = -1) {
	if(getPlayerTeam(playerid) != getDefendingTeam() && getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_BASE) {
		if(!IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_Z]) && !IsPlayerInRangeOfPoint(playerid, CAR_SPAWN_DIS, getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_Z))) return -1;			

		new string[700], name[16];
		new counter, VEHICLE_TYPES: type;
		switch(GetPVarInt(playerid, PV_HELP_VAR_1)) {
			case 0: type = TYPE_MOTORBIKE;
			case 1: {
				if(getBoatSpawnPosition(SPAWN_X) == -99999.0) {
					getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 2);
					showPlayerBackDialog(playerid, BACK_VEHICLE_NAMES, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string);				
					return 1;
				}
				type = TYPE_BOAT;
			}
			case 2: type = TYPE_HELICOPTER;
			case 3: type = TYPE_PLANE;
			case 4: type = TYPE_INDUSTRIAL;
			case 5: type = TYPE_OFFROAD;
			case 6: type = TYPE_PUBLIC_SERVICES;
			case 7: type = TYPE_CABRIOLET;
			case 8: type = TYPE_LOWRIDER;
			case 9: type = TYPE_SPORT_CAR;
			case 10: type = TYPE_COMBI;
			case 11: type = TYPE_NORMAL_CAR;
		}

		if(listitem == -1) {
			for(new i; i < sizeof(g_VehicleList); i ++) {
				if(getVehicleTypeByIndex(i) == type && getVehicleFlagsByIndex(i) & VEHICLE_ROUND_SPAWN) {
					strunpack(name, getVehicleNameByIndex(i));
					format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s", string, name);
					counter ++;
				}
			}

			if(counter > 0) {
				ShowPlayerDialog(playerid, DIALOG_ROUND_VEHICLES_NAMES, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_BACK));
			} else {
				getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 1);
				showPlayerBackDialog(playerid, BACK_VEHICLE_NAMES, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string);
			}
		} else {
			for(new i; i < sizeof(g_VehicleList); i ++) {
				if(getVehicleTypeByIndex(i) == type && getVehicleFlagsByIndex(i) & VEHICLE_ROUND_SPAWN) {
					if(counter == listitem) {
						givePlayerRoundVehicle(playerid, getVehicleModelByIndex(i));
						return 1;
					} else counter ++;
				}
			}			
		}
		
		return 1;
	}
	return 0;
}