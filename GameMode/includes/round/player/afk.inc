/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_Player_AFKMode[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getPlayerAFKMode(playerid) return _:g_Player_AFKMode[playerid];
//------------------------------------------------------------------------------
setPlayerAFKMode(playerid, bool:enable, bool:change_color = true) {
	new teamid;
	if(getPlayerStatus(playerid) != PLAYER_STATUS_IN_ROUND && TEAM_TWO >= (teamid = getPlayerTeam(playerid)) >= TEAM_ONE) {
		g_Player_AFKMode[playerid] = enable;
		if(change_color) {
			SetPlayerColor(playerid, (getTeamColorInt(teamid, (enable == true ? COLOR_STATUS_INACTIVE : COLOR_STATUS_DEATH)) & 0xFFFFFF00));
		}
		return 1;
	}
	return 0;
}
