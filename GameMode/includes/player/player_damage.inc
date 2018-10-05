/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	PLAYER_DAMAGE_TIME				3
//------------------------------------------------------------------------------
#define getPlayerTakeDamageTime(%1)		g_Player_TakeDamage_Time[%1]
#define getPlayerGiveDamageTime(%1)		g_Player_GiveDamage_Time[%1]
#define getPlayerAimedInfoTime(%1)		g_Player_AimedInfo_Time[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_Player_DamageInfo[MAX_PLAYERS] = {true, true, true, ...};	
new g_Player_GiveDamage_Time[MAX_PLAYERS],
	g_Player_TakeDamage_Time[MAX_PLAYERS],
	g_Player_Combo_PlayerID[MAX_PLAYERS] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID, ...},
	Float:g_Player_Combo_Damage[MAX_PLAYERS];
new g_Player_TakeDamage_ObjectID[MAX_PLAYERS] = {-1, -1, -1, ...};
//------------------------------------------------------------------------------
new bool:g_Player_AimedInfo[MAX_PLAYERS] = {true, true, true, ...},
	g_Player_AimedInfo_Time[MAX_PLAYERS];
//------------------------------------------------------------------------------
new bool:g_Damage_ObjectInfo = true;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setDamageObjectInfoStatus(bool:enable) g_Damage_ObjectInfo = enable;
getDamageObjectInfoStatus() return _:g_Damage_ObjectInfo;
//------------------------------------------------------------------------------
destroyPlayerDamageObject(&playerid) {
	if(g_Player_TakeDamage_ObjectID[playerid] != -1) {
		DestroyObject(g_Player_TakeDamage_ObjectID[playerid]);
		g_Player_TakeDamage_ObjectID[playerid] = -1;
		return 1;
	}
	return 0;
}	
//------------------------------------------------------------------------------
getPlayerDamageInfoStatus(&playerid) return _:g_Player_DamageInfo[playerid];
setPlayerDamageInfoStatus(&playerid, bool:enable) {
	g_Player_DamageInfo[playerid] = enable;
}
//------------------------------------------------------------------------------
updatePlayerShowDamageInfo(bool:givedamage, &showplayer, &reasonplayer, &weaponid, &Float:amount, &Float:newhealth, &Float:newarmour, &bool:takehealth) {
	static string[128];
	new time = gettime();
	
	if(reasonplayer != INVALID_PLAYER_ID) {
		new Float:combo_dmg;
		if(givedamage) {
			if(g_Player_Combo_PlayerID[showplayer] != reasonplayer) {
				g_Player_Combo_PlayerID[showplayer] = reasonplayer;
				g_Player_Combo_Damage[showplayer] = 0.0;
			}
			g_Player_Combo_Damage[showplayer] += amount;
			combo_dmg = g_Player_Combo_Damage[showplayer];
		} else {
			combo_dmg = g_Player_Combo_Damage[reasonplayer];
		}
		GetWeaponName(weaponid, string, 32);
		format(string, sizeof(string), "%s~n~%s | -%.0f (%.0f DMG | %.1f HP | %.1f AR)", getPlayerName(reasonplayer), string, amount, combo_dmg, newhealth, newarmour);	
	} else {
		format(string, sizeof(string), "Self~n~-%.0f HP (%.1f HP | %.1f AR)", amount, newhealth, newarmour);		
	}

	if(givedamage) {
		if(g_Player_DamageInfo[showplayer]) {
			PlayerTextDrawSetString(showplayer, PTD_GiveDamage[showplayer], string);
			g_Player_GiveDamage_Time[showplayer] = time + PLAYER_DAMAGE_TIME;
			PlayerTextDrawShow(showplayer, PTD_GiveDamage[showplayer]);
			PlayerPlaySound(showplayer, 17802, 0.0, 0.0, 0.0);
		}
			
		if(getPlayerStatus(showplayer) == PLAYER_STATUS_IN_ROUND) {
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_SPECTATE && getPlayerSpecID(i) == showplayer) {
					PlayerPlaySound(i, 17802, 0.0, 0.0, 0.0);
					PlayerTextDrawSetString(i, PTD_GiveDamage[i], string);
					g_Player_GiveDamage_Time[i] = time + PLAYER_DAMAGE_TIME;
					PlayerTextDrawShow(i, PTD_GiveDamage[showplayer]);					
				}
			}			
		}
	} else {		
		g_Player_TakeDamage_Time[showplayer] = time + PLAYER_DAMAGE_TIME;
		if(g_Player_DamageInfo[showplayer]) {
			PlayerTextDrawSetString(showplayer, PTD_TakeDamage[showplayer], string);
			PlayerTextDrawShow(showplayer, PTD_TakeDamage[showplayer]);
			PlayerPlaySound(showplayer, 1136, 0, 0, 0);
		}
		
		if(g_Damage_ObjectInfo && GetPlayerState(showplayer) != PLAYER_STATE_WASTED) {
			destroyPlayerDamageObject(showplayer);
			g_Player_TakeDamage_ObjectID[showplayer] = CreateObject(takehealth ? 1240 : 1242, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			AttachObjectToPlayer(g_Player_TakeDamage_ObjectID[showplayer], showplayer, 0.0, 0.0, 2.1, 0.0, 0.0, 0.0);
		}
		
		if(getPlayerStatus(showplayer) == PLAYER_STATUS_IN_ROUND) {
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_SPECTATE && getPlayerSpecID(i) == showplayer) {
					PlayerPlaySound(i, 1136, 0, 0, 0);
					PlayerTextDrawSetString(i, PTD_TakeDamage[i], string);
					g_Player_TakeDamage_Time[i] = time + PLAYER_DAMAGE_TIME;
					PlayerTextDrawShow(i, PTD_TakeDamage[i]);				
				}
			}			
		}			
	}
}
//==============================================================================
stock getPlayerAimedInfoStatus(&playerid) return _:g_Player_AimedInfo[playerid];
setPlayerAimedInfoStatus(&playerid, bool:enable) {
	g_Player_AimedInfo[playerid] = enable;
}
//------------------------------------------------------------------------------
updatePlayerAimedInfo(&playerid, &aimedid) {
	if(g_Player_AimedInfo[playerid]) {
		static string[32];
		format(string, sizeof(string), "%s~n~~n~_", getPlayerName(aimedid));		
		PlayerTextDrawSetString(playerid, PTD_AimedPlayer_Nick[playerid], string);
//		valstr(string, GetPlayerPing(aimedid)), PlayerTextDrawSetString(playerid, PTD_AimedPlayer_Ping[playerid], string);
		valstr(string, getPlayerFPS(aimedid)), PlayerTextDrawSetString(playerid, PTD_AimedPlayer_FPS[playerid], string);
		format(string, sizeof(string), "%.1f%%", NetStats_PacketLossPercent(aimedid)), PlayerTextDrawSetString(playerid, PTD_AimedPlayer_PLoss[playerid], string);
		
		for(new i; i < sizeof(TD_AimedPlayer_Static); i ++) TextDrawShowForPlayer(playerid, TD_AimedPlayer_Static[i]);
		PlayerTextDrawShow(playerid, PTD_AimedPlayer_Nick[playerid]);
//		PlayerTextDrawShow(playerid, PTD_AimedPlayer_Ping[playerid]);
		PlayerTextDrawShow(playerid, PTD_AimedPlayer_FPS[playerid]);
		PlayerTextDrawShow(playerid, PTD_AimedPlayer_PLoss[playerid]);
		
		g_Player_AimedInfo_Time[playerid] = gettime() + PLAYER_DAMAGE_TIME;
	}
}
//==============================================================================
