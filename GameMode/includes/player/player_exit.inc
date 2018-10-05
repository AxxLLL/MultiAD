/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
enum PLAYER_EXIT_DATA {
	EXIT_TIME, 
	EXIT_NAME[7], 
	EXIT_IP[5], 
	EXIT_GPCI[16],
	EXIT_REASON, 
	EXIT_MATCH_ID, 
	EXIT_MATCH_PLAYED_ROUNDS,
	EXIT_ROUND_ID, 
	EXIT_ROUND_STATS[E_PLAYER_STATS_DATA], 
	EXIT_TOTAL_STATS[E_PLAYER_STATS_DATA]
}
new g_Player_Exit_Data[50][PLAYER_EXIT_DATA];
//==============================================================================
saveExitPlayerData(&playerid, &reason) {
	new slot = -1;
	new string[64], pName[MAX_PLAYER_NAME];
	
	GetPlayerName(playerid, pName, sizeof(pName));
	for(new i; i < sizeof(g_Player_Exit_Data); i ++) {
		if(g_Player_Exit_Data[i][EXIT_TIME] != 0) {
			if(strcmp(g_Player_Exit_Data[i][EXIT_NAME], pName) == 0) {
				slot = i;
				break;
			}
		}
	}
	
	if(slot == -1) {
		for(new i, oldest_time = 9999999999; i < sizeof(g_Player_Exit_Data); i ++) {
			if(g_Player_Exit_Data[i][EXIT_TIME] == 0) {
				slot = i;
				break;
			} else {
				if(g_Player_Exit_Data[i][EXIT_TIME] < oldest_time) {
					oldest_time = g_Player_Exit_Data[i][EXIT_TIME];
					slot = i;
				}
			}
		}	
	}
	
	g_Player_Exit_Data[slot][EXIT_TIME] = gettime();
	strpack(g_Player_Exit_Data[slot][EXIT_NAME], pName, 6);	
	GetPlayerIp(playerid, string, 16);
	strpack(g_Player_Exit_Data[slot][EXIT_IP], string, 4);
	gpci(playerid, string, 60);
	strpack(g_Player_Exit_Data[slot][EXIT_GPCI], string, 15);
	g_Player_Exit_Data[slot][EXIT_REASON] = reason;
	g_Player_Exit_Data[slot][EXIT_MATCH_ID] = getMatchRandomKey();
	g_Player_Exit_Data[slot][EXIT_ROUND_ID] = getRoundRandomKey();
	g_Player_Exit_Data[slot][EXIT_MATCH_PLAYED_ROUNDS] = getPlayerPlayedRounds(playerid);
		
	for(new E_PLAYER_STATS_DATA:i; i < E_PLAYER_STATS_DATA; i ++) {
		g_Player_Exit_Data[slot][EXIT_TOTAL_STATS][i] = getPlayerTotalStats(playerid, i);
		g_Player_Exit_Data[slot][EXIT_ROUND_STATS][i] = getPlayerRoundStats(playerid, i);
	}
	
	return slot;
}
//------------------------------------------------------------------------------
searchForPlayerOldData(&playerid, bool:check_gpci = false) {
	new name[MAX_PLAYER_NAME];
	new s_gpci[64];
	GetPlayerName(playerid, name, sizeof(name));
	gpci(playerid, s_gpci, 60);
	for(new i, time = gettime(); i < sizeof(g_Player_Exit_Data); i ++) {
		if(g_Player_Exit_Data[i][EXIT_TIME] > 0 && time < g_Player_Exit_Data[i][EXIT_TIME] + 3600) {
			if(strcmp(g_Player_Exit_Data[i][EXIT_NAME], name) == 0 && (check_gpci == false || strcmp(g_Player_Exit_Data[i][EXIT_GPCI], s_gpci) == 0)) {
				return i;
			}
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
restorePlayerStatsOldData(&playerid, index, bool:compare_name = true) {
	if(sizeof(g_Player_Exit_Data) > index >= 0 && g_Player_Exit_Data[index][EXIT_TIME] != 0) {
		if(compare_name) {
			new pName[MAX_PLAYER_NAME];
			GetPlayerName(playerid, pName, sizeof(pName));
			if(strcmp(pName, g_Player_Exit_Data[index][EXIT_NAME]) != 0) return 0;
		}
		
		if(getMatchRandomKey() == g_Player_Exit_Data[index][EXIT_MATCH_ID]) {		
			setPlayerPlayedRounds(playerid, g_Player_Exit_Data[index][EXIT_MATCH_PLAYED_ROUNDS]);
			for(new E_PLAYER_STATS_DATA:i; i < E_PLAYER_STATS_DATA; i ++) {
				setPlayerTotalStatPoints(playerid, i, g_Player_Exit_Data[index][EXIT_TOTAL_STATS][i]);
			}		
		} 
		
		if(getRoundRandomKey() == g_Player_Exit_Data[index][EXIT_ROUND_ID]) {
			for(new E_PLAYER_STATS_DATA:i; i < E_PLAYER_STATS_DATA; i ++) {
				setPlayerRoundStatPoints(playerid, i, g_Player_Exit_Data[index][EXIT_ROUND_STATS][i]);
			}		
		}
			
		g_Player_Exit_Data[index][EXIT_TIME] = 0;
		strdel(g_Player_Exit_Data[index][EXIT_NAME], 0, 7);
		strdel(g_Player_Exit_Data[index][EXIT_IP], 0, 5);
		strdel(g_Player_Exit_Data[index][EXIT_GPCI], 0, 16);
		g_Player_Exit_Data[index][EXIT_REASON] = 0;
		g_Player_Exit_Data[index][EXIT_MATCH_ID] = 0;
		g_Player_Exit_Data[index][EXIT_ROUND_ID] = 0;
	
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------