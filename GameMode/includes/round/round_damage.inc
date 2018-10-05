/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	TIME_DAMAGE_INFO				3
//------------------------------------------------------------------------------
#define getShowDamageBarTime(%1)		g_Round_TeamBar_Damage_Timer[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_TeamBar_Damage_Timer[2] = {0, 0};
new g_Round_TeamBar_Damage_Status = true;
new g_Round_TeamBar_Damage_PlayerID[2] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID};
new Float:g_Round_TeamBar_Damage_Total[2] = {0.0, 0.0};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
resetRoundDamageInfo(teamid) {
	g_Round_TeamBar_Damage_Total[teamid] = INVALID_PLAYER_ID;
	g_Round_TeamBar_Damage_Total[teamid] = 0.0;
}
//------------------------------------------------------------------------------
getTeamDamageBarInfoStatus() return _:g_Round_TeamBar_Damage_Status;
//------------------------------------------------------------------------------
setTeamDamageBarStatus(bool:enable) {
	g_Round_TeamBar_Damage_Status = enable;
}
//------------------------------------------------------------------------------
updateTeamDamageBarInfo(&playerid, teamid, &Float:amount, &Float:health, &Float:armour) {
	if(g_Round_TeamBar_Damage_Status) {
		static string[80];
		
		if(g_Round_TeamBar_Damage_PlayerID[teamid] != playerid) {
			g_Round_TeamBar_Damage_PlayerID[teamid] = playerid;
			g_Round_TeamBar_Damage_Total[teamid] = 0;
		}
		g_Round_TeamBar_Damage_Total[teamid] += amount;
		
		format(string, sizeof(string), "%s ~w~-%.0f HP  (%.0f | %.1f HP | %.1f AR)", getPlayerName(playerid), amount, g_Round_TeamBar_Damage_Total[teamid], health, armour);
		TextDrawSetString(TD_RoundBar_Damage[teamid], string);
		if(gettime() > g_Round_TeamBar_Damage_Timer[teamid]) {
			forplayers(i) {
				if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {
					TextDrawShowForPlayer(i, TD_RoundBar_Damage[teamid]);
				}
			}
		}
		g_Round_TeamBar_Damage_Timer[teamid] = gettime() + TIME_DAMAGE_INFO;
	}
}



