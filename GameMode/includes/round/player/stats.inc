/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
//enum E_PLAYER_STATS_DATA {KILLS, DEATHS, DAMAGE}
//------------------------------------------------------------------------------
new g_Round_Player_RoundStats[MAX_PLAYERS][E_PLAYER_STATS_DATA];
new g_Round_Player_TotalStats[MAX_PLAYERS][E_PLAYER_STATS_DATA];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
resetPlayerRoundStats(&playerid) {
	g_Round_Player_RoundStats[playerid][KILLS] = g_Round_Player_RoundStats[playerid][DEATHS] = g_Round_Player_RoundStats[playerid][DAMAGE] = 0;
}
//------------------------------------------------------------------------------
resetPlayerTotalStats(&playerid) {
	g_Round_Player_TotalStats[playerid][KILLS] = g_Round_Player_TotalStats[playerid][DEATHS] = g_Round_Player_TotalStats[playerid][DAMAGE] = 0;
	CallLocalFunction("OnPlayerStatsChange", "ddd", playerid, 0, 0);
}
//------------------------------------------------------------------------------
getPlayerTotalStats(&playerid, E_PLAYER_STATS_DATA:stattype) return g_Round_Player_TotalStats[playerid][stattype];
//------------------------------------------------------------------------------
addPlayerRoundStatPoints(&playerid, E_PLAYER_STATS_DATA:stattype, points) {
	g_Round_Player_RoundStats[playerid][stattype] += points;
	g_Round_Player_TotalStats[playerid][stattype] += points;
	CallLocalFunction("OnPlayerStatsChange", "ddd", playerid, _:stattype, points);
	return 1;
}
//------------------------------------------------------------------------------
setPlayerRoundStatPoints(&playerid, E_PLAYER_STATS_DATA:stattype, points) {
	g_Round_Player_RoundStats[playerid][stattype] = points;
	CallLocalFunction("OnPlayerStatsChange", "ddd", playerid, _:stattype, points);
	return 1;
}
//------------------------------------------------------------------------------
setPlayerTotalStatPoints(&playerid, E_PLAYER_STATS_DATA:stattype, points) {
	g_Round_Player_TotalStats[playerid][stattype] = points;
	CallLocalFunction("OnPlayerStatsChange", "ddd", playerid, _:stattype, points);
	return 1;
}
//------------------------------------------------------------------------------
getPlayerRoundStats(&playerid, E_PLAYER_STATS_DATA:stattype) {
	return g_Round_Player_RoundStats[playerid][stattype];
}
//------------------------------------------------------------------------------
getTop5PlayersInTeam(output[], teamid, E_PLAYER_STATS_DATA:stattype, limit = 5) {
	if(TEAM_REF >= teamid >= TEAM_ONE && MAX_PLAYERS >= limit > 0) {
		new a_Players_IDs[MAX_PLAYERS] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID, ...}, a_Players_Value[MAX_PLAYERS];
		new x, y, counter;
		forplayers(i) {
			if((getPlayerTeam(i) == teamid || (teamid == TEAM_REF && getPlayerTeam(i) != TEAM_REF && getPlayerTeam(i) != TEAM_NON)) && getPlayerRoundKey(i) != -1 && g_Round_Player_RoundStats[i][stattype] > 0) {
				for(x = 0; x < limit; x ++) {
					if(a_Players_IDs[x] == INVALID_PLAYER_ID) {
						a_Players_IDs[x] = i;
						a_Players_Value[x] = g_Round_Player_RoundStats[i][stattype];
						break;
					} else {
						if(a_Players_Value[x] < g_Round_Player_RoundStats[i][stattype]) {
							for(y = limit - 1; y > x; y --) {
								a_Players_IDs[y] = a_Players_IDs[y - 1];
								a_Players_Value[y] = a_Players_Value[y - 1];
							}
							a_Players_IDs[x] = i;
							a_Players_Value[x] = g_Round_Player_RoundStats[i][stattype];
							break;
						}
					}
				}
			}
		}
		
		for(x = 0; x < limit; x ++) {
			if(a_Players_IDs[x] == INVALID_PLAYER_ID) break;
			else {
				output[x] = a_Players_IDs[x];
				counter ++;
			}			
		}		
		return counter;
	}
	return 0;
}
//==============================================================================