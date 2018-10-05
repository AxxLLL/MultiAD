/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_Weapon_Set_PlayerUsed[MAX_PLAYERS] = {INVALID_WEAPON_ID, INVALID_WEAPON_ID, INVALID_WEAPON_ID, ...};
//------------------------------------------------------------------------------
new g_Round_Weapon_Set_Loaded = 10;
enum E_SETS_WEAPONS_INFO{WEAPON_SETS_WEAPON_1, WEAPON_SETS_AMMO_1, WEAPON_SETS_WEAPON_2, WEAPON_SETS_AMMO_2, WEAPON_SETS_MAX_PLAYERS}
new g_Round_Weapon_Set[MAX_WEAPONS_SET][E_SETS_WEAPONS_INFO] = {
	{31, 1000, 	29, 	500, 	20},
	{31, 500, 	25, 	200, 	20},
	{34, 100, 	25, 	150, 	1},
	{33, 300, 	25, 	200, 	20},
	{24, 200, 	29, 	750, 	20},
	{24, 200, 	30, 	500, 	20},
	{24, 100, 	25, 	100, 	20},
	{24, 200, 	33, 	300, 	20},
	{27, 100, 	33, 	200, 	1},
	{27, 100, 	23, 	400, 	1},
	{-1, -1, 	-1, 	-1, 	-1},
	{-1, -1, 	-1, 	-1, 	-1}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
/*
getPlayerPreamadedWeaponsAmmo(&playerid, &ammo_1, &ammo_2) {
	new slotid;
	ammo_1 = ammo_2 = 0;
	if((slotid = g_Round_Weapon_Set_PlayerUsed[playerid]) != INVALID_WEAPON_ID) {
		ammo_1 = g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1];
		ammo_2 = g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1];
		return 1;
	}
	return 0;
}
*/
//------------------------------------------------------------------------------
getMaxPlayersAtWeaponSlot(&weaponslot) {
	return MAX_WEAPONS_SET > weaponslot >= 0 ? g_Round_Weapon_Set[weaponslot][WEAPON_SETS_MAX_PLAYERS] : 0;
}
//------------------------------------------------------------------------------
setPlayerPremadedWeaponsID(&playerid, index) g_Round_Weapon_Set_PlayerUsed[playerid] = index;
getPlayerPremadedWeaponsID(&playerid) {
	return g_Round_Weapon_Set_PlayerUsed[playerid];
}
//------------------------------------------------------------------------------
checkPremadeEditMode(&playerid) {
	if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 0 && g_Round_Weapon_Set[GetPVarInt(playerid, PV_HELP_VAR_4)][WEAPON_SETS_WEAPON_1] == INVALID_WEAPON_ID) return 0;
	return 1;
}
//------------------------------------------------------------------------------
setPermadedWeaponAmmo(slotid, weaponslot, ammo, bool:create = false, playerid = INVALID_PLAYER_ID) {
	if(9999 >= ammo >= 1) {
		if(create == false) {
			if(g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] != INVALID_WEAPON_ID && g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2] != INVALID_WEAPON_ID) {
				if(weaponslot == 0) g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1] = ammo;
				else g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_2] = ammo;
			} 
		} else {
			if((weaponslot == 0 ? GetPVarInt(playerid, PV_PREMADE_WEAPON_1) : GetPVarInt(playerid, PV_PREMADE_WEAPON_2)) != INVALID_WEAPON_ID) {
				if(weaponslot == 0) SetPVarInt(playerid, PV_PREMADE_AMMO_1, ammo);
				else SetPVarInt(playerid, PV_PREMADE_AMMO_2, ammo);
			} 		
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setPermadedWeaponPlayers(slotid, players, bool:create = false, playerid = INVALID_PLAYER_ID) {
	if(999 >= players >= 1) {
		if(create == false) {
			if(g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] != INVALID_WEAPON_ID && g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2] != INVALID_WEAPON_ID) {
				g_Round_Weapon_Set[slotid][WEAPON_SETS_MAX_PLAYERS] = players;
			}
		} else {
			SetPVarInt(playerid, PV_PREMADE_PLAYERS, players);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
resetPlayerWeaponSet(&playerid) {
	if(g_Round_Weapon_Set_PlayerUsed[playerid] != INVALID_WEAPON_ID) {
		g_Round_Weapon_Set_PlayerUsed[playerid] = INVALID_WEAPON_ID;
		ResetPlayerWeapons(playerid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
givePlayerWeaponSetWeapons(&playerid) {
	new setid;
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && (setid = g_Round_Weapon_Set_PlayerUsed[playerid]) != INVALID_WEAPON_ID) {
		ResetPlayerWeapons(playerid);
		givePlayerStaticWeapons(playerid);
		GivePlayerWeapon(playerid, g_Round_Weapon_Set[setid][WEAPON_SETS_WEAPON_1], g_Round_Weapon_Set[setid][WEAPON_SETS_AMMO_1]);
		GivePlayerWeapon(playerid, g_Round_Weapon_Set[setid][WEAPON_SETS_WEAPON_2], g_Round_Weapon_Set[setid][WEAPON_SETS_AMMO_2]);
		g_RWeapons_Old_Premaded[playerid] = setid;
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerPermadedWeaponMenu(&playerid, listitem = -1) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {			
		new counter, teamid = getPlayerTeam(playerid);
		new string[600], w_name_1[32], w_name_2[32];

		resetPlayerWeaponSet(playerid);
		
		if(listitem == -1 || listitem == 0) {		
			new used_sets[MAX_WEAPONS_SET];
			getDialogBodyMessage(string, DIALOG_BODY_WEAPON_SETS_MENU, 0);
			
			forplayers(i) {
				if(g_Round_Weapon_Set_PlayerUsed[i] != INVALID_WEAPON_ID && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && teamid == getPlayerTeam(i)) used_sets[g_Round_Weapon_Set_PlayerUsed[i]] ++;
			}
			
			for(new i; i < g_Round_Weapon_Set_Loaded; i ++) {
				counter ++;
				GetWeaponName(g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1], w_name_1, sizeof(w_name_1));
				GetWeaponName(g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2], w_name_2, sizeof(w_name_2));
				format(string, sizeof(string), "%s\n%s%s%s%d\t%s%s%d\t\t%d", string, (i % 2 == 0 ? (COLOR_DIALOG_COUNT) : (COLOR_DIALOG_BODY)), w_name_1, g_Round_Weapons[g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1]][WEAPON_TABS], g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_1], w_name_2, g_Round_Weapons[g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2]][WEAPON_TABS], g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_2], (g_Round_Weapon_Set[i][WEAPON_SETS_MAX_PLAYERS] - used_sets[i]));
			}	
			
			if(counter > 0) ShowPlayerDialog(playerid, DIALOG_WEAPON_SET_SELECT_MENU, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), string, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_EXIT));
			else {
				getDialogBodyMessage(string, DIALOG_BODY_WEAPON_SETS_MENU, 1);
				showPlayerBackDialog(playerid, BACK_WEAPON_SET_SELECT_MENU, getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), string);
			}
		} else {
			if(g_Round_Weapon_Set_Loaded > (-- listitem) >= 0) {				
				forplayers(i) {
					if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && teamid == getPlayerTeam(i) && g_Round_Weapon_Set_PlayerUsed[i] == listitem) counter ++;
				}
				if(counter < g_Round_Weapon_Set[listitem][WEAPON_SETS_MAX_PLAYERS]) {
					g_Round_Weapon_Set_PlayerUsed[playerid] = listitem;
					givePlayerWeaponSetWeapons(playerid);
					showSelectedWeaponsInfo(playerid);
				} else showPlayerPermadedWeaponMenu(playerid);
			} else showPlayerPermadedWeaponMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
saveWeaponSetData() {
	if(fexist(DIR_GENERAL)) {
		new File:f_open = fopen(FILE_WEAPON_SET, io_write);
		new write[64];
		for(new i; i < MAX_WEAPONS_SET; i ++) {
			format(write, sizeof(write), "\r\n%d|%d|%d|%d|%d", g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1], g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_1], g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2], g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_2], g_Round_Weapon_Set[i][WEAPON_SETS_MAX_PLAYERS]);
			fwrite(f_open, write);
		}		
		fclose(f_open);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
loadWeaponSetData() {
	if(fexist(DIR_GENERAL)) {	    
	    new read[128];
	    if(!fexist(FILE_WEAPON_SET)) {
			saveWeaponSetData();
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Weapon Set", FILE_WEAPON_SET);
	    } else {
			new File:f_open;
			new loaded, i, bool:founded;
			new weaponid_1, ammo_1, weaponid_2, ammo_2, max_players;
			
			f_open = fopen(FILE_WEAPON_SET, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read)) {
					if(sscanf(read, "p<|>ddddd", weaponid_1, ammo_1, weaponid_2, ammo_2, max_players) == 0) {				
						if(isValidWeapon(weaponid_1) && 38 >= weaponid_1 >= 16 && isValidWeapon(weaponid_2) && 38 >= weaponid_2 >= 16 && weaponid_1 != weaponid_2 && 9999 >= ammo_1 >= 1 && 9999 >= ammo_2 >= 1 && 999 >= max_players >= 1 && getWeaponSlot(weaponid_1) != getWeaponSlot(weaponid_2)) {
							for(i = 0, founded = false; i < loaded; i ++) {
								if((weaponid_1 == g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1] || weaponid_1 == g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2]) && (weaponid_2 == g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1] || weaponid_2 == g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2])) {
									founded = true;
									break;
								}
							}
							if(founded == false) {
								g_Round_Weapon_Set[loaded][WEAPON_SETS_WEAPON_1] = weaponid_1;
								g_Round_Weapon_Set[loaded][WEAPON_SETS_AMMO_1] = ammo_1;
								g_Round_Weapon_Set[loaded][WEAPON_SETS_WEAPON_2] = weaponid_2;
								g_Round_Weapon_Set[loaded][WEAPON_SETS_AMMO_2] = ammo_2;
								g_Round_Weapon_Set[loaded][WEAPON_SETS_MAX_PLAYERS] = max_players;
								if(++ loaded == MAX_WEAPONS_SET) break;
							}
						}
					}
				}
			}
			g_Round_Weapon_Set_Loaded = loaded;
			fclose(f_open);
		}
		
		return 1;
	}
	return 0;
}