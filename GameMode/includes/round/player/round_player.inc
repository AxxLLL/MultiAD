/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/round/player/add_functions.inc"
#include "includes/round/player/respawn.inc"
#include "includes/round/player/stats.inc"
#include "includes/round/player/afk.inc"
#include "includes/round/player/help.inc"
#include "includes/round/player/c_add.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_RoundPlayer_KeyPause = true;
//==============================================================================
getPlayerKeyPauseStatus(&playerid) return _:g_RoundPlayer_KeyPause;
setPlayerKeyPauseStatus(&playerid, bool:enable) {
	g_RoundPlayer_KeyPause = enable;
	return 1;
}