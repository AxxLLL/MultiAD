/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getPlayerDontAskStatus(&playerid) return _:g_Round_Weapon_DontAskAgain[playerid];
setPlayerDontAskStatus(&playerid, bool:enable) {
	g_Round_Weapon_DontAskAgain[playerid] = enable;
	return 1;
}
//------------------------------------------------------------------------------
resetPlayerOldWeaponsData(&playerid) {
	g_RWeapons_Old_Premaded[playerid] = INVALID_WEAPON_ID;
	for(new i; i < MAX_WEAPON_SLOTS; i ++) g_RWeapons_Old_FreeChoose[playerid][i] = -1;
}
//------------------------------------------------------------------------------
tryGiveOldWeapons(&playerid) {
	if(givePlayerOldWeapons(playerid)) {
		showSelectedWeaponsInfo(playerid);
	    getChatMessage(g_Chat_String, CHAT_MESSAGE_OLD_WEAPONS, 0);
	} else getChatMessage(g_Chat_String, CHAT_MESSAGE_OLD_WEAPONS, 1);
	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
}
//------------------------------------------------------------------------------
givePlayerOldWeapons(&playerid) {
	if(g_Round_WeaponSelectType == FREE_WEAPON_FREECHOOSE) {	
		if(g_RWeapons_Old_FreeChoose[playerid][0] == INVALID_WEAPON_ID) {
			resetPlayerOldWeaponsData(playerid);
			showPlayerRoundWeaponSelectMenu(playerid);
			return 0;
		} else {
			new players_with_that_gun[15];
			
			for(new i, team = getPlayerTeam(playerid), weaponslot; i < MAX_PLAYERS; i ++) {
				if(IsPlayerConnected(i) && i != playerid && getPlayerTeam(i) == team && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
					for(weaponslot = 0; weaponslot < MAX_WEAPON_SLOTS; weaponslot ++) {
						if(g_Round_Weapon_FC_PlayerUsed[i][weaponslot] == INVALID_WEAPON_ID) break;
						else {
							players_with_that_gun[(g_Round_Weapon_FC_PlayerUsed[i][weaponslot] == 38 ? 14 : (g_Round_Weapon_FC_PlayerUsed[i][weaponslot] - 22))] ++;
						}
					}						
				}
			}		
					
			for(new i, max_slots = getFreeChoiceMaxSlots(), weaponid; i < max_slots; i ++) {
				if((weaponid = g_RWeapons_Old_FreeChoose[playerid][i]) == INVALID_WEAPON_ID) break;
				else {
					if(players_with_that_gun[((weaponid == 38) ? 14 : (weaponid - 22))] >= g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS] || !g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE]) {
						resetPlayerOldWeaponsData(playerid);
						showPlayerRoundWeaponSelectMenu(playerid);
						return 0;
					}
				}
			}
					
			for(new i, max_slots = getFreeChoiceMaxSlots(); i < max_slots; i ++) {
				g_Round_Weapon_FC_PlayerUsed[playerid][i] = g_RWeapons_Old_FreeChoose[playerid][i];
			}
		
			givePlayerFreeChooseWeapons(playerid);
			return 1;
		}
	} else {
		if(g_RWeapons_Old_Premaded[playerid] == INVALID_WEAPON_ID) {
			resetPlayerOldWeaponsData(playerid);
			showPlayerRoundWeaponSelectMenu(playerid);
			return 0;
		} else {
			new weapon_set = g_RWeapons_Old_Premaded[playerid], used_sets;

			for(new i, team = getPlayerTeam(playerid); i < MAX_PLAYERS; i ++) {
				if(IsPlayerConnected(i) && i != playerid && getPlayerPremadedWeaponsID(i) == weapon_set && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && team == getPlayerTeam(i)) {
					used_sets ++;
				}
			}
			
			if(used_sets >= getMaxPlayersAtWeaponSlot(weapon_set)) {
				resetPlayerOldWeaponsData(playerid);
				showPlayerRoundWeaponSelectMenu(playerid);
				return 0;
			} else {
				g_Round_Weapon_Set_PlayerUsed[playerid] = weapon_set;
				givePlayerWeaponSetWeapons(playerid);
				return 1;
			}
		}	
	}
}