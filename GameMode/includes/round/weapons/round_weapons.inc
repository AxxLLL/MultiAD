/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define INVALID_WEAPON_ID			-1
//------------------------------------------------------------------------------
#define	PERMADED_WEAPON_SETS			0
#define FREE_WEAPON_FREECHOOSE			1
#define MAX_WEAPON_SLOTS				5
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_WeaponSelectType = FREE_WEAPON_FREECHOOSE;
//------------------------------------------------------------------------------
new g_RWeapons_Old_Premaded[MAX_PLAYERS];
new g_RWeapons_Old_FreeChoose[MAX_PLAYERS][MAX_WEAPON_SLOTS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/round/weapons/permaded.inc"
#include "includes/round/weapons/freechoose.inc"
#include "includes/round/weapons/static.inc"
#include "includes/round/weapons/old_weapons.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getWeaponSelectType() return g_Round_WeaponSelectType;
//------------------------------------------------------------------------------
setWeaponSelectType(type) {
	if(FREE_WEAPON_FREECHOOSE >= type >= PERMADED_WEAPON_SETS) {
		g_Round_WeaponSelectType = type;
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRoundWeaponSelectMenu(&playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		switch(g_Round_WeaponSelectType) {
			case PERMADED_WEAPON_SETS: {
				if(g_RWeapons_Old_Premaded[playerid] == INVALID_WEAPON_ID) {
					setPlayerDontAskStatus(playerid, false);
					showPlayerPermadedWeaponMenu(playerid);
				} else {
					if(getPlayerDontAskStatus(playerid)) {
	                    tryGiveOldWeapons(playerid);						
					} else {
						setPlayerDontAskStatus(playerid, false);
						getDialogBodyMessage(g_Chat_String, DIALOG_BODY_OLD_WEAPONS, 0);
						ShowPlayerDialog(playerid, DIALOG_OLD_ROUND_WEAPONS, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), g_Chat_String, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_EXIT));
					}
				}
			}
			case FREE_WEAPON_FREECHOOSE: {
				if(g_RWeapons_Old_FreeChoose[playerid][0] == INVALID_WEAPON_ID) {
					setPlayerDontAskStatus(playerid, false);
					showPlayerFreeChooseWeaponMenu(playerid, true);
				} else {
					if(getPlayerDontAskStatus(playerid)) {
	                    tryGiveOldWeapons(playerid);					
					} else {
						setPlayerDontAskStatus(playerid, false);
						getDialogBodyMessage(g_Chat_String, DIALOG_BODY_OLD_WEAPONS, 0);
						ShowPlayerDialog(playerid, DIALOG_OLD_ROUND_WEAPONS, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), g_Chat_String, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_EXIT));
					}
				}
			}
			default: return 0;
		}	
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
removePlayerRoundWeapons(&playerid) {
	switch(g_Round_WeaponSelectType) {
		case PERMADED_WEAPON_SETS: resetPlayerWeaponSet(playerid);
		case FREE_WEAPON_FREECHOOSE: resetPlayerFreeChooseWeapons(playerid);
		default: return 0;
	}
	return 1;
}
//------------------------------------------------------------------------------
showSelectedWeaponsInfo(&playerid) {
	static weapon_names[128];	
	weapon_names[0] = EOS;
	
	if(g_Round_WeaponSelectType == PERMADED_WEAPON_SETS) {	
		new weapon_slot = g_Round_Weapon_Set_PlayerUsed[playerid];
		if((weapon_slot = g_Round_Weapon_Set_PlayerUsed[playerid]) != INVALID_WEAPON_ID) {
			getChatMessage(g_Chat_String, CHAT_MESSAGE_WEAPON_SELECT, 0);
			GetWeaponName(g_Round_Weapon_Set[weapon_slot][WEAPON_SETS_WEAPON_1], weapon_names[0], 32);
			GetWeaponName(g_Round_Weapon_Set[weapon_slot][WEAPON_SETS_WEAPON_2], weapon_names[32], 32);					
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), weapon_names[0], g_Round_Weapon_Set[weapon_slot][WEAPON_SETS_AMMO_1], weapon_names[32], g_Round_Weapon_Set[weapon_slot][WEAPON_SETS_AMMO_2]);						
		} else {
            getChatMessage(g_Chat_String, CHAT_MESSAGE_WEAPON_SELECT, 1);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);	
            getChatMessage(g_Chat_String, CHAT_MESSAGE_WEAPON_SELECT, 3);
            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));			
		}
	} else {
		new counter;
		for(new i, w_name[32], weaponid; i < MAX_WEAPON_SLOTS; i ++) {
			if((weaponid = g_Round_Weapon_FC_PlayerUsed[playerid][i]) == INVALID_WEAPON_ID) break;
			else {
				GetWeaponName(weaponid, w_name, sizeof(w_name));
				format(weapon_names, sizeof(weapon_names),"%s, %s", weapon_names, w_name);
				counter ++;
			}
		}				
		if(counter > 0) {
			strdel(weapon_names, 0, 2);
			getChatMessage(g_Chat_String, CHAT_MESSAGE_WEAPON_SELECT, 2);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), weapon_names);
		} else {		
			getChatMessage(g_Chat_String, CHAT_MESSAGE_WEAPON_SELECT, 3);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
		}					
	}
	
	for(new i, teamid = getPlayerTeam(playerid); i < MAX_PLAYERS; i ++) {
		if(IsPlayerConnected(i) && teamid == getPlayerTeam(i)) {
			SendClientMessage(i, COLOR_WEAPON_INFO_1, g_Chat_String);
		}
	}
}