/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define TEAM_REASON_LEFT			0
#define TEAM_REASON_JOIN			1
#define TEAM_REASON_SWITCH			2
#define TEAM_REASON_SWAP			3
#define TEAM_REASON_ADMIN_SWAP		4
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Team[MAX_PLAYERS] = {TEAM_NON, TEAM_NON, TEAM_NON, ...};
new g_Player_Team_Password[MAX_PLAYERS][3];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setPlayerTeam(&playerid, newteam, reason, bool:spawn = false) {
	new oldteam;
	if(TEAM_NON <= newteam <= TEAM_REF && ((oldteam = g_Player_Team[playerid]) != newteam || newteam == TEAM_NON)) {	
		SetPlayerColor(playerid, (getTeamColorInt((g_Player_Team[playerid] = newteam), (getPlayerAFKMode(playerid) ? COLOR_STATUS_INACTIVE : COLOR_STATUS_DEATH)) & 0xFFFFFF00));
		SetSpawnInfo(playerid, GLOBAL_TEAM, getTeamSkin(newteam), 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
		if(spawn) {
			if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
			SpawnPlayer(playerid);
		}		
		CallLocalFunction("OnPlayerTeamChange", "dddd", playerid, newteam, oldteam, reason);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getPlayerTeam(&playerid) return g_Player_Team[playerid];
//------------------------------------------------------------------------------
setPlayerTeamPassword(&playerid, teamid, password) {
	if(TEAM_ONE <= teamid <= TEAM_REF && (password == 0 || 1000 <= password <= 9999)) {
		g_Player_Team_Password[playerid][teamid] = password;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getPlayerTeamPassword(&playerid, teamid) return (TEAM_ONE <= teamid <= TEAM_REF) ? g_Player_Team_Password[playerid][teamid] : 0;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================