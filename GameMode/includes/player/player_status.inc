/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward OnPlayerStatusChange(playerid, newstatus, oldstatus);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Status[MAX_PLAYERS];
//==============================================================================
setPlayerStatus(const &playerid, const newstatus) {
	new oldstatus;
	if((oldstatus = g_Player_Status[playerid]) != newstatus) {
		CallLocalFunction("OnPlayerStatusChange", "ddd", playerid, (g_Player_Status[playerid] = newstatus), oldstatus);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
stock getPlayerStatus(const &playerid) return g_Player_Status[playerid];
