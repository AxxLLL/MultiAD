/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward timer_HideMatchInfo();
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define STOP_MATCH_REASON_CMD			0
#define STOP_MATCH_POINTS_LIMIT			1
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_Match_LogFile[32];
//------------------------------------------------------------------------------
new bool:g_Round_Match_Start = false;
new g_Round_Match_RoundLimit = 0;
//------------------------------------------------------------------------------
new g_Round_Match_RandomKey = -1;
new g_Round_Player_Match_RandomKey[MAX_PLAYERS] = {-1, -1, ...};
//------------------------------------------------------------------------------
enum E_MATCH_DATA {MATCH_MAPID, MATCH_TYPE, bool:MATCH_TDM_MODE, MATCH_WINNER, MATCH_REASON, MATCH_DEFENDER, MATCH_ROUND_TIME}
new g_Round_Match_Data[11][E_MATCH_DATA];
//------------------------------------------------------------------------------
new g_Round_Match_TimerID = -1;
new bool:g_Round_AnyMatchEndSuccess = false;
//------------------------------------------------------------------------------
new g_Match_Player_Played_Rounds[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/round/match/played_rounds.inc"
#include "includes/round/match/restore_match.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setPlayerMatchRandomID(&playerid, id) g_Round_Player_Match_RandomKey[playerid] = id;
stock getPlayerMatchRandomID(&playerid) return g_Round_Player_Match_RandomKey[playerid];
//------------------------------------------------------------------------------
toMatchLogs(log[], bool:force = false) {
	if((g_Round_Match_Start || force) && fexist(DIR_LOGS_MATCH)) {
		static string[256], g, m, s;
		static File:f_match_logs;
		gettime(g, m, s);
		f_match_logs = fopen(g_Round_Match_LogFile, io_append);
		format(string, sizeof(string), "[%02d:%02d:%02d] %s\r\n", g, m, s, log);
		fwrite(f_match_logs, string);
		fclose(f_match_logs);
	}
}
//------------------------------------------------------------------------------
getMatchTimerID() return g_Round_Match_TimerID;
//------------------------------------------------------------------------------
getSuccesMatchEndStatus() return _:g_Round_AnyMatchEndSuccess;
//------------------------------------------------------------------------------
killMatchTimerID() {
	timer_HideMatchInfo();
}
//------------------------------------------------------------------------------
getMatchStatus() return _:g_Round_Match_Start;
//------------------------------------------------------------------------------
getMatchRoundLimit() return g_Round_Match_RoundLimit;
setMatchRoundLimit(limit) {
	if(11 >= limit >= 1) {
		new string[64];
		g_Round_Match_RoundLimit = limit;
		
		format(string, sizeof(string),  "UPDATE `"D_MATCH"` SET `"DM_ROUND_LIMIT"`='%d'", limit);
		db_query(dbase, string);		
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getPlayerPlayedRounds(&playerid) return g_Match_Player_Played_Rounds[playerid];
setPlayerPlayedRounds(&playerid, value) g_Match_Player_Played_Rounds[playerid] = value;
//------------------------------------------------------------------------------
getMatchRandomKey() return g_Round_Match_RandomKey;
forceMatchRandomKey(key_num) g_Round_Match_RandomKey = key_num;
//------------------------------------------------------------------------------
addMatchRoundInfo(&roundid, &mapid, &type, &bool:tdmmode, &win_teamid, &win_reason, defender, time, bool:save_query_data = true) {
	if(g_Round_Match_Start) {
		g_Round_Match_Data[roundid][MATCH_MAPID] = mapid;
		g_Round_Match_Data[roundid][MATCH_TYPE] = type;
		g_Round_Match_Data[roundid][MATCH_TDM_MODE] = tdmmode;
		g_Round_Match_Data[roundid][MATCH_WINNER] = win_teamid;
		g_Round_Match_Data[roundid][MATCH_REASON] = win_reason;
		g_Round_Match_Data[roundid][MATCH_DEFENDER] = defender;
		g_Round_Match_Data[roundid][MATCH_ROUND_TIME] = time;
		
		if(save_query_data) {
			format(g_String_512, sizeof(g_String_512), "INSERT INTO `"D_MATCH_ROUNDS"` VALUES ('%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d');",
				roundid + 1, 
				g_Round_Match_RandomKey,
				mapid,
				type,
				tdmmode,
				win_teamid,
				win_reason,
				defender,
				time
			);
			db_query(dbase, g_String_512);
			
			savePlayerMatchData(INVALID_PLAYER_ID, true);
		}		
		
		if(g_Round_Match_RoundLimit == roundid + 1) {
			endMatch(STOP_MATCH_POINTS_LIMIT, true);
		} else setRoundCounterValue(g_Round_RoundCounter + 1);		
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
savePlayerMatchData(remote_id, bool:add_round = false) {
	new pName[MAX_PLAYER_NAME];
	new DBResult:result;
	
	new starting_id = (remote_id == INVALID_PLAYER_ID ? 0 : remote_id);
	new ending_id = (remote_id == INVALID_PLAYER_ID ? GetPlayerPoolSize() : remote_id);
	for(; starting_id <= ending_id; starting_id ++) {
		if(add_round && getPlayerRoundKey(starting_id) == getRoundRandomKey()) g_Match_Player_Played_Rounds[starting_id] ++;
		
		GetPlayerName(starting_id, pName, sizeof(pName));
		format(g_String_512, sizeof(g_String_512), "SELECT `"DMP_MATCH_ID"` FROM `"D_MATCH_PLAYERS"` WHERE `"DMP_NICK"`='%s' LIMIT 1", pName);
		result = db_query(dbase, g_String_512);
		if(db_num_rows(result)) {
			db_free_result(result);
			format(g_String_512, sizeof(g_String_512), 
					"UPDATE `"D_MATCH_PLAYERS"` SET `"DMP_MATCH_ID"`='%d', `"DMP_TEAM_ID"`='%d', `"DMP_KILLS"`='%d', `"DMP_DEATHS"`='%d', `"DMP_DAMAGE"`='%d', `"DMP_PLAYED_ROUNDS"`='%d' WHERE `"DMP_NICK"`='%s'",   
				g_Round_Player_Match_RandomKey[starting_id],
				getPlayerTeam(starting_id),
				getPlayerTotalStats(starting_id, KILLS),
				getPlayerTotalStats(starting_id, DEATHS),
				getPlayerTotalStats(starting_id, DAMAGE),
				g_Match_Player_Played_Rounds[starting_id],				
				pName
			);				
		} else {
			format(g_String_512, sizeof(g_String_512), "INSERT INTO `"D_MATCH_PLAYERS"` VALUES ('%s', '%d', '%d', '%d', '%d', '%d', '%d');",
				pName,
				g_Round_Player_Match_RandomKey[starting_id],
				getPlayerTeam(starting_id),
				getPlayerTotalStats(starting_id, KILLS),
				getPlayerTotalStats(starting_id, DEATHS),
				getPlayerTotalStats(starting_id, DAMAGE),
				g_Match_Player_Played_Rounds[starting_id]	
			);
		}
		db_query(dbase, g_String_512);
	}
}
//------------------------------------------------------------------------------
startMatch(roundlimit) {
	if(!g_Round_Match_Start) {
		new string[128], y, m, d;
		g_Round_Match_RandomKey = random(999999999);
		g_Round_Match_RoundLimit = roundlimit;
		setTeamPoints(TEAM_ONE, 0);
		setTeamPoints(TEAM_TWO, 0);		

		for(new i; i < sizeof(g_Round_Match_Data); i ++) {
			g_Round_Match_Data[i][MATCH_MAPID] = INVALID_MAP_ID;
			g_Round_Match_Data[i][MATCH_TYPE] = 0;
			g_Round_Match_Data[i][MATCH_TDM_MODE] = false;
			g_Round_Match_Data[i][MATCH_WINNER] = TEAM_NON;
			g_Round_Match_Data[i][MATCH_REASON] = -1;
			g_Round_Match_Data[i][MATCH_DEFENDER] = TEAM_NON;
			g_Round_Match_Data[i][MATCH_ROUND_TIME] = 0;
		}			
		
		forplayers(i) {
			g_Match_Player_Played_Rounds[i] = 0;
			resetPlayerTotalStats(i);
		}
		
		g_Round_Match_Start = true;
		format(string, sizeof(string), "mapname %s 0:0 %s (R: 1/%d)", getTeamName(TEAM_ONE), getTeamName(TEAM_TWO), roundlimit);
		SendRconCommand(string);
		setRoundCounterValue(0, true);
		
		getdate(y, m, d);
		format(string, sizeof(string), DIR_LOGS_MATCH"/%s vs %s (%02d-%02d-%d # %d).txt", getTeamName(TEAM_ONE), getTeamName(TEAM_TWO), d, m, y, g_Round_Match_RandomKey);
		strpack(g_Round_Match_LogFile, string);
		
		deleteRoundDataFromSQL();
		
		format(string, sizeof(string),  "INSERT INTO `"D_MATCH"` VALUES ('%d', '%d', '%s', '%s', '%d');", g_Round_Match_RandomKey, g_Round_Match_RoundLimit, getTeamName(TEAM_ONE), getTeamName(TEAM_TWO), gettime());
		db_query(dbase, string);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
stopMatch() {	
	g_Round_Match_Start = false;
	g_Round_Match_RoundLimit = 0;
	setTeamPoints(TEAM_ONE, 0);
	setTeamPoints(TEAM_TWO, 0);	
	setRoundCounterValue(0, true);
	SendRconCommand("mapname "GM_NAME);
	for(new i; i < sizeof(g_Round_Match_Data); i ++) {
		g_Round_Match_Data[i][MATCH_MAPID] = INVALID_MAP_ID;
		g_Round_Match_Data[i][MATCH_TYPE] = 0;
		g_Round_Match_Data[i][MATCH_TDM_MODE] = false;
		g_Round_Match_Data[i][MATCH_WINNER] = TEAM_NON;
		g_Round_Match_Data[i][MATCH_REASON] = -1;
		g_Round_Match_Data[i][MATCH_DEFENDER] = TEAM_NON;
		g_Round_Match_Data[i][MATCH_ROUND_TIME] = 0;
	}	
	deleteRoundDataFromSQL();
}
//------------------------------------------------------------------------------
deleteMatchRoundData(rowid) {
	new totalsize;
	if(rowid == -1) {
		db_query(dbase, "DELETE FROM `"D_MATCH_ROUNDS"`");	
		for(new i; i < sizeof(g_Round_Match_Data); i ++) {
			g_Round_Match_Data[i][MATCH_MAPID] = INVALID_MAP_ID;
			g_Round_Match_Data[i][MATCH_TYPE] = 0;
			g_Round_Match_Data[i][MATCH_TDM_MODE] = false;
			g_Round_Match_Data[i][MATCH_WINNER] = TEAM_NON;
			g_Round_Match_Data[i][MATCH_REASON] = -1;
			g_Round_Match_Data[i][MATCH_DEFENDER] = TEAM_NON;
			g_Round_Match_Data[i][MATCH_ROUND_TIME] = 0;
		}
	} else if((totalsize = sizeof(g_Round_Match_Data)) > rowid >= 0 && g_Round_Match_Data[rowid][MATCH_MAPID] != INVALID_MAP_ID) {
		new s_query[64];
		format(s_query, sizeof(s_query), "DELETE FROM `"D_MATCH_ROUNDS"` WHERE `"DMR_ROUND"`='%d'", rowid + 1);
		db_query(dbase, s_query);
		format(s_query, sizeof(s_query), "UPDATE `"D_MATCH_ROUNDS"` SET `"DMR_ROUND"`="DMR_ROUND"-1 WHERE `"DMR_ROUND"`>='%d'", rowid + 1);
		db_query(dbase, s_query);
		
		for(new i = rowid; i < sizeof(g_Round_Match_Data) - 1; i ++) {
			g_Round_Match_Data[i][MATCH_MAPID] = g_Round_Match_Data[i + 1][MATCH_MAPID];
			g_Round_Match_Data[i][MATCH_TYPE] = g_Round_Match_Data[i + 1][MATCH_TYPE];
			g_Round_Match_Data[i][MATCH_TDM_MODE] = g_Round_Match_Data[i + 1][MATCH_TDM_MODE];
			g_Round_Match_Data[i][MATCH_WINNER] = g_Round_Match_Data[i + 1][MATCH_WINNER];
			g_Round_Match_Data[i][MATCH_REASON] = g_Round_Match_Data[i + 1][MATCH_REASON];
			g_Round_Match_Data[i][MATCH_DEFENDER] = g_Round_Match_Data[i + 1][MATCH_DEFENDER];
			g_Round_Match_Data[i][MATCH_ROUND_TIME] = g_Round_Match_Data[i + 1][MATCH_ROUND_TIME];
		}
		g_Round_Match_Data[(--totalsize)][MATCH_MAPID] = INVALID_MAP_ID;
		g_Round_Match_Data[totalsize][MATCH_TYPE] = 0;
		g_Round_Match_Data[totalsize][MATCH_TDM_MODE] = false;
		g_Round_Match_Data[totalsize][MATCH_WINNER] = TEAM_NON;
		g_Round_Match_Data[totalsize][MATCH_REASON] = -1;
		g_Round_Match_Data[totalsize][MATCH_DEFENDER] = TEAM_NON;	
		g_Round_Match_Data[totalsize][MATCH_ROUND_TIME] = 0;		
	}
}
//------------------------------------------------------------------------------
endMatch(reason, bool:force = false) {
	if(g_Round_Match_Start && (getRoundState() == ROUND_STATE_LOBBY || force == true)) {
		if(reason == STOP_MATCH_POINTS_LIMIT) {		
			new s_string[4], string[300], string_2[256], string_3[256], s_type_arena[8], s_type_base[8], s_type_arena_tdm[14], s_win[10], s_loss[10], s_draw[10];
			new top_players_IDs[2][10] = { {INVALID_PLAYER_ID, INVALID_PLAYER_ID, ...}, {INVALID_PLAYER_ID, INVALID_PLAYER_ID, ...}}, top_players_Points[2][10], teamid, x, y, points;
			new Day, Month, Year, Hour, Minute;
			
			TextDrawSetString(TD_Round_Match_End_TNames[TEAM_ONE], getTeamName(TEAM_ONE));
			TextDrawSetString(TD_Round_Match_End_TNames[TEAM_TWO], getTeamName(TEAM_TWO));
			
			if(getTeamPoints(TEAM_ONE) == getTeamPoints(TEAM_TWO)) {
				getTextDrawShortMessage(string, TD_SHORT_MESSAGE_END_MATCH, 1);
			} else {
				getTextDrawShortMessage(string, TD_SHORT_MESSAGE_END_MATCH, 0);
				format(string, sizeof(string), string, getTeamName((getTeamPoints(TEAM_ONE) > getTeamPoints(TEAM_TWO) ? TEAM_ONE : TEAM_TWO)));
			}
			TextDrawSetString(TD_Round_Match_End_Winner, string);
			
			valstr(s_string, getTeamPoints(TEAM_ONE));			
			TextDrawSetString(TD_Round_Match_End_TPoints[TEAM_ONE], s_string);
			valstr(s_string, getTeamPoints(TEAM_TWO));	
			TextDrawSetString(TD_Round_Match_End_TPoints[TEAM_TWO], s_string);
			
			getTextDrawShortMessage(s_win, TD_SHORT_MESSAGE_END_MATCH, 3);
			getTextDrawShortMessage(s_loss, TD_SHORT_MESSAGE_END_MATCH, 4);
			getTextDrawShortMessage(s_draw, TD_SHORT_MESSAGE_END_MATCH, 5);			
			getTextDrawShortMessage(s_type_arena, TD_SHORT_MESSAGE_END_MATCH, 6);
			getTextDrawShortMessage(s_type_base, TD_SHORT_MESSAGE_END_MATCH, 7);
			getTextDrawShortMessage(s_type_arena_tdm, TD_SHORT_MESSAGE_END_MATCH, 8);
			
			string[0] = EOS;
			for(new i; i < sizeof(g_Round_Match_Data); i ++) {
				if(g_Round_Match_Data[i][MATCH_MAPID] == INVALID_MAP_ID) {
					format(string, sizeof(string), "%s_~n~", string);
				} else {
					format(string, sizeof(string), "%s%s  %d~n~", string, ((g_Round_Match_Data[i][MATCH_TYPE] == ROUND_TYPE_BASE) ? (s_type_base) : (g_Round_Match_Data[i][MATCH_TDM_MODE] ? s_type_arena_tdm : s_type_arena)), g_Round_Match_Data[i][MATCH_MAPID]);				
					
					if(g_Round_Match_Data[i][MATCH_DEFENDER] == TEAM_ONE) {
						switch(g_Round_Match_Data[i][MATCH_WINNER]) {
							case TEAM_ONE: {
								format(string_2, sizeof(string_2), "%s~g~Defend~n~", string_2);
								format(string_3, sizeof(string_3), "%s~r~Attack~n~", string_3);
							}
							case TEAM_TWO: {
								format(string_2, sizeof(string_2), "%s~r~Defend~n~", string_2);
								format(string_3, sizeof(string_3), "%s~g~Attack~n~", string_3);						
							}
							default: {
								format(string_2, sizeof(string_2), "%s~w~Defend~n~", string_2);
								format(string_3, sizeof(string_3), "%s~w~Attack~n~", string_3);							
							}
						}					
					} else {
						switch(g_Round_Match_Data[i][MATCH_WINNER]) {
							case TEAM_ONE: {
								format(string_2, sizeof(string_2), "%s~g~Attack~n~", string_2);
								format(string_3, sizeof(string_3), "%s~r~Defend~n~", string_3);
							}
							case TEAM_TWO: {
								format(string_2, sizeof(string_2), "%s~r~Attack~n~", string_2);
								format(string_3, sizeof(string_3), "%s~g~Defend~n~", string_3);						
							}
							default: {
								format(string_2, sizeof(string_2), "%s~w~Attack~n~", string_2);
								format(string_3, sizeof(string_3), "%s~w~Defend~n~", string_3);							
							}
						}						
					}
				}
			}			
			
			TextDrawSetString(TD_Round_Match_End_Rounds, string);
			TextDrawSetString(TD_Round_Match_End_TRounds[TEAM_ONE], string_2);
			TextDrawSetString(TD_Round_Match_End_TRounds[TEAM_TWO], string_3);	
			
			gettime(Hour, Minute);
			getdate(Year, Month, Day);
			format(string, sizeof(string), "%02d / %02d / %d    [ %02d:%02d ]", Day, Month, Year, Hour, Minute);
			TextDrawSetString(TD_Round_Match_Result_WWW, string);
			
			#define MATCH_PLAYERS_LIMIT		10
			forplayers(i) {				
				if(TEAM_ONE <= (teamid = getPlayerTeam(i)) <= TEAM_TWO) {
					for(x = 0; x < MATCH_PLAYERS_LIMIT; x ++) {
						if(top_players_IDs[teamid][x] == INVALID_PLAYER_ID) {
							top_players_IDs[teamid][x] = i;
							top_players_Points[teamid][x] = getPlayerTotalStats(i, DAMAGE);
							break;						
						} else {
							if(top_players_Points[teamid][x] < (points = getPlayerTotalStats(i, DAMAGE))) {
								for(y = MATCH_PLAYERS_LIMIT - 1; y > x; y --) {
									top_players_IDs[teamid][y] = top_players_IDs[teamid][y - 1];
									top_players_Points[teamid][y] = top_players_Points[teamid][y - 1];
								}
								top_players_IDs[teamid][x] = i;
								top_players_Points[teamid][x] = points;
								break;
							}						
						}
					} 
				}
			}		
			for(x = TEAM_ONE; x <= TEAM_TWO; x ++) {
				string[0] = EOS;
				string_2[0] = EOS;
				string_3[0] = EOS;			
				for(y = 0; y < MATCH_PLAYERS_LIMIT; y ++) {
					if(top_players_IDs[x][y] == INVALID_PLAYER_ID) {
						format(string, sizeof(string), "%s_~n~", string);
						format(string_2, sizeof(string_2), "%s_~n~", string_2);
						format(string_3, sizeof(string_3), "%s_~n~", string_3);					
					} else {
						format(string, sizeof(string), "%s%s~n~", string, getPlayerName(top_players_IDs[x][y]));
						format(string_2, sizeof(string_2), "%s%d~n~", string_2, top_players_Points[x][y]);
						format(string_3, sizeof(string_3), "%s%d~n~", string_3, getPlayerTotalStats(top_players_IDs[x][y], KILLS));
					}
				}
				TextDrawSetString(TD_Round_Match_End_TPlayers[x], string);
				TextDrawSetString(TD_Round_Match_End_TDamage[x], string_2);
				TextDrawSetString(TD_Round_Match_End_TKills[x], string_3);				
			}			
			#undef MATCH_PLAYERS_LIMIT
	
			forplayers(i) {
				if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {
					showPlayerEndMatchInfo(i);
				}
			}

			prepareSiteMatchResults();
						
			g_Round_AnyMatchEndSuccess = true;
			g_Round_Match_TimerID = SetTimer("timer_HideMatchInfo", 8000, 0);
		}
		
		stopMatch();
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
public timer_HideMatchInfo() {
	if(g_Round_Match_TimerID != -1) {
		new x;
		for(x = 0; x < sizeof(TD_Round_Match_End_Static); x ++) TextDrawHideForAll(TD_Round_Match_End_Static[x]);
		for(x = 0; x < 2; x ++) {
			TextDrawHideForAll(TD_Round_Match_End_TNames[x]);
			TextDrawHideForAll(TD_Round_Match_End_TPoints[x]);
			TextDrawHideForAll(TD_Round_Match_End_TRounds[x]);
			TextDrawHideForAll(TD_Round_Match_End_TPlayers[x]);
			TextDrawHideForAll(TD_Round_Match_End_TDamage[x]);
			TextDrawHideForAll(TD_Round_Match_End_TKills[x]);
		}
		TextDrawHideForAll(TD_Round_Match_Result_WWW);
		TextDrawHideForAll(TD_Round_Match_End_Rounds);	
		TextDrawHideForAll(TD_Round_Match_End_Winner);
		
		KillTimer(g_Round_Match_TimerID);
		g_Round_Match_TimerID = -1;
		
		getChatMessage(g_Chat_String, CHAT_MESSAGE_MATCH_END, 0);
		SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);		

	}
}