/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	HELP_TIME					3
#define HELP_ICON_ID				5
//------------------------------------------------------------------------------
#define getHelpIconTime(%1)			g_Round_HelpTimers[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_HelpTimers[2] = {0, 0};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
checkHelpKeys(&newkeys, &oldkeys) return (newkeys & KEY_NO && !(oldkeys & KEY_NO)) ? 1 : 0; 
//------------------------------------------------------------------------------
playerCallsForHelp(&playerid) {
	new teamid;
	if(TEAM_ONE <= (teamid = getPlayerTeam(playerid)) <= TEAM_TWO && getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && g_Round_HelpTimers[teamid] == 0) {
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		TextDrawSetString(TD_Round_Help_Nick[teamid], getPlayerName(playerid));	
		
		forplayers(i) {
			if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == teamid) {
				TextDrawShowForPlayer(i, TD_Round_Help_Static[0]);
				TextDrawShowForPlayer(i, TD_Round_Help_Static[1]);
				TextDrawShowForPlayer(i, TD_Round_Help_Nick[teamid]);
				SetPlayerMapIcon(i, ICON_ROUND_HELP, x, y, z, 22, 0, MAPICON_GLOBAL);
			}
		}			
		
		g_Round_HelpTimers[teamid] = gettime() + HELP_TIME;
		return 1;
	}
	return 0;
}