/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward Float:getPlayerPLossFromData(&playerid);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	setPlayerFPS(%1,%2)				g_PlayerFPS[%1] = (%2)
#define getPlayerFPS(%1)				g_PlayerFPS[%1]
//#define getPlayerVehicleHealthLabel(%1)	g_Player_VehicleHealth[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Name[MAX_PLAYERS][MAX_PLAYER_NAME];
new g_PlayerFPS[MAX_PLAYERS];
//new Text3D:g_Player_VehicleHealth[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
stock savePlayerName(&playerid) return GetPlayerName(playerid, g_Player_Name[playerid], MAX_PLAYER_NAME);
//------------------------------------------------------------------------------
stock getPlayerName(&playerid) return g_Player_Name[playerid];
//------------------------------------------------------------------------------
stock isPlayerSwimming(&playerid) {
	new index;
	if(1538 <= (index = GetPlayerAnimationIndex(playerid)) <= 1544 || index == 1250) return 1;
	return 0;
}
//------------------------------------------------------------------------------
stock isPlayerUsingParachute(&playerid) {
	new index;
	if(958 <= (index = GetPlayerAnimationIndex(playerid)) <= 980 || index == 1134) return 1;
	return 0;
}
//------------------------------------------------------------------------------
stock isPlayerFalling(&playerid) return ((1128 <= GetPlayerAnimationIndex(playerid) <= 1134) ? 1 : 0);
//------------------------------------------------------------------------------
Float:getPlayerPLossFromData(&playerid) {
    static net_string[256], index;
    GetPlayerNetworkStats(playerid, net_string, sizeof(net_string));
    if((index = strfind(net_string, "Packetloss:")) != -1) {
        strdel(net_string, 0, index);
		if((index = strfind(net_string, "%")) != -1) {
			net_string[index] = EOS;
			return floatstr(net_string[12]);
		}
    }
    return 0.0;
}