/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new PlayerText:PTD_TakeDamage[MAX_PLAYERS],
	PlayerText:PTD_GiveDamage[MAX_PLAYERS];
new Text:TD_AimedPlayer_Static[2],
	PlayerText:PTD_AimedPlayer_Nick[MAX_PLAYERS],
//	PlayerText:PTD_AimedPlayer_Ping[MAX_PLAYERS],
	PlayerText:PTD_AimedPlayer_FPS[MAX_PLAYERS],
	PlayerText:PTD_AimedPlayer_PLoss[MAX_PLAYERS];
new Text:TD_PlayerHUD_NickAndTeam_Static,
	Text:TD_PlayerHUD_TeamNames[3],
	Text:TD_PlayerHUD_FPSPingPLossStatic[2],
	Text:TD_PlayerHUD_Stats_Static[2],
	PlayerText:PTD_PlayerHUD_Nick[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_Health[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_Armour[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_Ping[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_FPS[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_PLoss[MAX_PLAYERS],
	PlayerText:PTD_PlayerHUD_Stats[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/player/player_functions.inc"
#include "includes/player/player_damage.inc"
#include "includes/player/player_status.inc"
#include "includes/player/player_textdraws.inc"
#include "includes/player/player_zone.inc"
#include "includes/player/player_settings.inc"
#include "includes/player/player_exit.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
