/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerRWeaponsSettingMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new string[270];
			if(listitem == -1) {
				getSettingsBodyMessage(string, SBM_MENU_ROUND_WEAPONS, 0);				
				format(string, sizeof(string), string, getSettingName(SETTING_NAME_WEAPON_MODE, (getWeaponSelectType() == PERMADED_WEAPON_SETS ? 1 : 0)), getFreeChoiceMaxSlots(), getGunMenuTime());
				ShowPlayerDialog(playerid, DIALOG_ROUND_WEAPON_MENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
			} else {
				switch(listitem) {
					case 0: {
						showPlayerRFreeWeaponsMenu(playerid);
						return 1;
					}
					case 1: {
						showPlayerRPremadedWeaponsMenu(playerid);
						return 1;
					} 
					case 2: {
						showPlayerRConstWeaponsMenu(playerid);
						return 1;
					} 
					case 3: {
						setWeaponSelectType((getWeaponSelectType() == PERMADED_WEAPON_SETS ? FREE_WEAPON_FREECHOOSE : PERMADED_WEAPON_SETS));
						getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 4);	
						format(string, sizeof(string), string, getPlayerName(playerid), getSettingName(SETTING_NAME_WEAPON_MODE, 2), getSettingName(SETTING_NAME_WEAPON_MODE, (getWeaponSelectType() == PERMADED_WEAPON_SETS ? 1 : 0)));							
					}
					case 4: {
						showPlayerValueDialogBack(playerid, DIALOG_VALUE_FREE_CHOICE_SLOTS);
						return 1;
					}
					case 5: {
						showPlayerValueDialogBack(playerid, DIALOG_VALUE_GUN_CMD_TIME);
						return 1;					
					}
					default: return showPlayerRWeaponsSettingMenu(playerid);
				}
				SendClientMessageToAll(COLOR_INFO_1, string);
				c_print(string);	
				showPlayerRWeaponsSettingMenu(playerid);
			}		
		}
		return 1;
	}
	return 0;
}
//==============================================================================
showPlayerRConstWeaponsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new string[256];
			switch(listitem) {
				case 0..MAX_STATIC_WEAPONS: {
					SetPVarInt(playerid, PV_HELP_VAR_4, listitem);
					showPlayerRConstWeaponsSubmenu(playerid);
				}
				default: {
					getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_CONST_WEAPONS, 3);
					for(new i, w_name[32], weaponid; i < MAX_STATIC_WEAPONS; i ++) {
						if((weaponid = g_Round_Weapon_StaticWeapons[i][0]) == -1) format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"Slot %d", string, i + 1);
						else {
							GetWeaponName(weaponid, w_name, sizeof(w_name));
							format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s\t%d", string, w_name, g_Round_Weapon_StaticWeapons[i][1]);
						}
					}
					ShowPlayerDialog(playerid, DIALOG_ROUND_CONST_WEAPONS_MENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}
		}	
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRConstWeaponsSubmenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new slotid = GetPVarInt(playerid, PV_HELP_VAR_4);
			switch(listitem) {
				case 0: showPlayerRConstWeaponsList(playerid);
				case 1: showPlayerValueDialogBack(playerid, DIALOG_VALUE_CONST_WEAPONS_AMMO);
				case 2: {
					g_Round_Weapon_StaticWeapons[slotid][0] = INVALID_WEAPON_ID;
					g_Round_Weapon_StaticWeapons[slotid][1] = 0;
					showPlayerRConstWeaponsMenu(playerid);				
				}
				default: {
					new w_name[32] = "NoN", string[128];
					if(g_Round_Weapon_StaticWeapons[slotid][0] != INVALID_WEAPON_ID) {
						GetWeaponName(g_Round_Weapon_StaticWeapons[slotid][0], w_name, sizeof(w_name));						
					} else g_Round_Weapon_StaticWeapons[slotid][1] = 0;
					getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_CONST_WEAPONS, 0);
					format(string, sizeof(string), string, w_name, g_Round_Weapon_StaticWeapons[slotid][1]);		
					ShowPlayerDialog(playerid, DIALOG_ROUND_CONST_WEAPONS_SUBMENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRConstWeaponsList(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new i;
			switch(listitem) {
				case 0..17: {
					new weaponid, slotid;
					switch(listitem) {
						case 0..6: 		weaponid = listitem + 1;
						case 7..14: 	weaponid = listitem + 2;
						case 15..16:	weaponid = listitem + 26;
						default: 		weaponid = listitem + 29;
					}
					
					for(i = 0, slotid = (weaponid == 46 ? 11 : getWeaponSlot(weaponid)); i < MAX_STATIC_WEAPONS; i ++) {
						if(weaponid == g_Round_Weapon_StaticWeapons[i][0]) {
							SetPVarInt(playerid, PV_HELP_VAR_4, i);
							showPlayerRConstWeaponsSubmenu(playerid);
							return 1;
						} else if(slotid == (g_Round_Weapon_StaticWeapons[i][0] == 46 ? 11 : getWeaponSlot(g_Round_Weapon_StaticWeapons[i][0]))) {
							setStaticWeaponWeapon(i, weaponid);
							SetPVarInt(playerid, PV_HELP_VAR_4, i);
							showPlayerRConstWeaponsSubmenu(playerid);							
						}
					}
					
					setStaticWeaponWeapon(GetPVarInt(playerid, PV_HELP_VAR_4), weaponid);
					showPlayerRConstWeaponsSubmenu(playerid);
				}
				default: {
					new string[320], w_name[32];
					for(i = 1; i < 17; i ++) {
						if(isValidWeapon(i)) {
							GetWeaponName(i, w_name, sizeof(w_name));
							format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s", string, w_name);
						}
					}
					for(i = 41; i < 43; i ++) {
						GetWeaponName(i, w_name, sizeof(w_name));
						format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s", string, w_name);				
					}
					GetWeaponName(46, w_name, sizeof(w_name));
					format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s", string, w_name);
					ShowPlayerDialog(playerid, DIALOG_ROUND_CONST_WEAPONS_LIST, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}		
		}
		return 1;
	}
	return 0;
}
//==============================================================================
showPlayerRFreeWeaponsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new string[700];
			if(listitem < 0) {
				getDialogBodyMessage(string, DIALOG_BODY_FREECHOOSE_MENU, 2);
				for(new i = 22, w_name[32], color[10]; i <= 38; i ++) {
					if(isValidWeapon(i)) {
						GetWeaponName(i, w_name, sizeof(w_name));
						format(color, sizeof(color), ((g_Round_Weapon_FreeChoose[i][WEAPON_FC_ENABLE] && g_Round_Weapon_FreeChoose[i][WEAPON_FC_AMMO] > 0 && g_Round_Weapon_FreeChoose[i][WEAPON_FC_MAX_PLAYERS] > 0) ? (C_LIGHTGREEN) : (C_KICK))); 
						format(string, sizeof(string), "%s\n%s%s\t%s%d\t%s%d", string, color, w_name, color, g_Round_Weapon_FreeChoose[i][WEAPON_FC_AMMO], color, g_Round_Weapon_FreeChoose[i][WEAPON_FC_MAX_PLAYERS]);
					}
				}
				ShowPlayerDialog(playerid, DIALOG_ROUND_FREE_WEAPONS_MENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
			} else {
				SetPVarInt(playerid, PV_HELP_VAR_4, (listitem == 14 ? 38 : (22 + listitem)));
				showPlayerRFreeWeaponsSubmenu(playerid);
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRFreeWeaponsSubmenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[40], weaponid;
		GetWeaponName((weaponid = GetPVarInt(playerid, PV_HELP_VAR_4)), caption, 32);
		strins(caption, COLOR_DIALOG_HEAD, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new string[128];
			switch(listitem) {
				case 0: g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE] = !g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE];
				case 1: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_FWEAPONS_AMMO);
					return 1;
				}
				case 2: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_FWEAPONS_PLAYERS);
					return 1;
				}				
			}			
			getSettingsBodyMessage(string, SBM_MENU_ROUND_FREE_WEAPONS, 0);
			format(string, sizeof(string), string, 
				g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE] ? (C_LIGHTGREEN) : (C_KICK), g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE] ? (oftenUsedPhrases(LANG_OUP_ENABLE)) : (oftenUsedPhrases(LANG_OUP_DISABLE)),
				g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_AMMO] == 0 ? (C_KICK) : (C_WHITE), g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_AMMO], 
				g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS] == 0 ? (C_KICK) : (C_WHITE), g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS]);
			ShowPlayerDialog(playerid, DIALOG_ROUND_FREE_WEAPONS_SUBMENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));			
		}
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerRPremadedWeaponsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new string[1536];
			switch(listitem) {
				case 0..MAX_WEAPONS_SET: {
					SetPVarInt(playerid, PV_HELP_VAR_4, listitem);
					
					if(g_Round_Weapon_Set[listitem][WEAPON_SETS_WEAPON_1] == INVALID_WEAPON_ID || g_Round_Weapon_Set[listitem][WEAPON_SETS_WEAPON_1] == INVALID_WEAPON_ID) {
						SetPVarInt(playerid, PV_PREMADE_WEAPON_1, -1);
						SetPVarInt(playerid, PV_PREMADE_WEAPON_2, -1);				
						SetPVarInt(playerid, PV_PREMADE_AMMO_1, 0);
						SetPVarInt(playerid, PV_PREMADE_AMMO_2, 0);
						SetPVarInt(playerid, PV_PREMADE_PLAYERS, 0);					
						SetPVarInt(playerid, PV_PREMADE_CREATE_MODE, 1);
					} else {
						SetPVarInt(playerid, PV_PREMADE_CREATE_MODE, 0);
					}
					
					showPlayerRPremadedWeapsSubmenu(playerid);
				}
				default: {
					getDialogBodyMessage(string, DIALOG_BODY_WEAPON_SETS_MENU, 0);
					for(new i, w_name_1[32], w_name_2[32], color[10]; i < MAX_WEAPONS_SET; i ++) {
						if(g_Round_Weapon_Set_Loaded <= i) format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"Slot %d", string, i + 1);
						else {						
							format(color, sizeof(color), (i % 2 == 0 ? (COLOR_DIALOG_COUNT) : (COLOR_DIALOG_BODY)));
							GetWeaponName(g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_1], w_name_1, sizeof(w_name_1));								
							GetWeaponName(g_Round_Weapon_Set[i][WEAPON_SETS_WEAPON_2], w_name_2, sizeof(w_name_2));
							format(string, sizeof(string), "%s\n%s%s ("C_WHITE"%d%s)\t%s%s ("C_WHITE"%d%s)\t%s%d", string, color, w_name_1, g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_1], color, color, w_name_2, g_Round_Weapon_Set[i][WEAPON_SETS_AMMO_2], color, color, g_Round_Weapon_Set[i][WEAPON_SETS_MAX_PLAYERS]);
						}
					}		
					ShowPlayerDialog(playerid, DIALOG_ROUND_PREMADED_WEAPONS_MENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}
		}	
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRPremadedWeapsSubmenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new slotid = GetPVarInt(playerid, PV_HELP_VAR_4);
			if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 0 && g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] == INVALID_WEAPON_ID) {
				showPlayerRPremadedWeaponsMenu(playerid);
				return 1;
			}			
			switch(listitem) {
				case 0: {
					SetPVarInt(playerid, PV_HELP_VAR_5, 0);
					showPlayerRPermadedWeaponsList(playerid);
				}
				case 1: {
					SetPVarInt(playerid, PV_HELP_VAR_5, 0);
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_PERMADED_WEAPONS_AMMO);
				}
				case 2: {
					SetPVarInt(playerid, PV_HELP_VAR_5, 1);
					showPlayerRPermadedWeaponsList(playerid);
				}
				case 3: {
					SetPVarInt(playerid, PV_HELP_VAR_5, 1);
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_PERMADED_WEAPONS_AMMO);
				}	
				case 4: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_PERMADED_WEAPONS_PLAYERS);
				}					
				case 5: {
					if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 0) {
						if(slotid + 1 != g_Round_Weapon_Set_Loaded) {
							g_Round_Weapon_Set_Loaded --;
							g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_1];
							g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_1];
							g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_2];
							g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_2] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_2];
							g_Round_Weapon_Set[slotid][WEAPON_SETS_MAX_PLAYERS] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_MAX_PLAYERS];
							g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_1] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_2] = INVALID_WEAPON_ID;
							g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_1] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_2] = g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_MAX_PLAYERS] = 0;
						} else {
							g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] = INVALID_WEAPON_ID;
							g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1] = 0;
							g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2] = INVALID_WEAPON_ID;
							g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_2] = 0;
							g_Round_Weapon_Set[slotid][WEAPON_SETS_MAX_PLAYERS] = 0;						
							g_Round_Weapon_Set_Loaded --;
						}
						showPlayerRPremadedWeaponsMenu(playerid);	
					} else {
						new weapon_1, weapon_2, ammo_1, ammo_2, players;
						if((weapon_1 = GetPVarInt(playerid, PV_PREMADE_WEAPON_1)) != INVALID_WEAPON_ID && (weapon_2 = GetPVarInt(playerid, PV_PREMADE_WEAPON_2)) != INVALID_WEAPON_ID && (ammo_1 = GetPVarInt(playerid, PV_PREMADE_AMMO_1)) > 0 && (ammo_2 = GetPVarInt(playerid, PV_PREMADE_AMMO_2)) > 0 && (players = GetPVarInt(playerid, PV_PREMADE_PLAYERS)) > 0) {
							if(g_Round_Weapon_Set_Loaded + 1 <= MAX_WEAPONS_SET) {
								g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_1] = weapon_1;
								g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_1] = ammo_1;
								g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_WEAPON_2] = weapon_2;
								g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_AMMO_2] = ammo_2;
								g_Round_Weapon_Set[g_Round_Weapon_Set_Loaded][WEAPON_SETS_MAX_PLAYERS] = players;									
								g_Round_Weapon_Set_Loaded ++;
							} else {							
								g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1] = weapon_1;
								g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1] = ammo_1;
								g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2] = weapon_2;
								g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_2] = ammo_2;
								g_Round_Weapon_Set[slotid][WEAPON_SETS_MAX_PLAYERS] = players;									
							}							
						}	
						return showPlayerRPremadedWeaponsMenu(playerid);
					}								
				}
				default: {
					new w_name_1[32] = "NoN", w_name_2[32] = "NoN", ammo_1, ammo_2, players, string[220];				
					
					if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 1) {			
						if(GetPVarInt(playerid, PV_PREMADE_WEAPON_1) != INVALID_WEAPON_ID) GetWeaponName(GetPVarInt(playerid, PV_PREMADE_WEAPON_1), w_name_1, sizeof(w_name_1));	
						if(GetPVarInt(playerid, PV_PREMADE_WEAPON_2) != INVALID_WEAPON_ID) GetWeaponName(GetPVarInt(playerid, PV_PREMADE_WEAPON_2), w_name_2, sizeof(w_name_2));					
						ammo_1 = GetPVarInt(playerid, PV_PREMADE_AMMO_1);
						ammo_2 = GetPVarInt(playerid, PV_PREMADE_AMMO_2);
						players = GetPVarInt(playerid, PV_PREMADE_PLAYERS);		
						getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_PREMADED_WEAPONS, 3);
					} else {			
						GetWeaponName(g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_1], w_name_1, sizeof(w_name_1));	
						GetWeaponName(g_Round_Weapon_Set[slotid][WEAPON_SETS_WEAPON_2], w_name_2, sizeof(w_name_2));
						ammo_1 = g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_1];
						ammo_2 = g_Round_Weapon_Set[slotid][WEAPON_SETS_AMMO_2];
						players = g_Round_Weapon_Set[slotid][WEAPON_SETS_MAX_PLAYERS];
						getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_PREMADED_WEAPONS, 0);
					}					
					
					format(string, sizeof(string), string, w_name_1, ammo_1, w_name_2, ammo_2, players);					
					ShowPlayerDialog(playerid, DIALOG_ROUND_PREMADED_WEAPONS_SUBMENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRPermadedWeaponsList(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new caption[64];
		getSettingsCaptionMessage(caption, SCM_ROUND_WEAPONS, 0);
		if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
		else {
			new i, slot = GetPVarInt(playerid, PV_HELP_VAR_4), type = GetPVarInt(playerid, PV_HELP_VAR_5), weapon_slot;

			if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 0) {	
				if(g_Round_Weapon_Set[slot][WEAPON_SETS_WEAPON_1] == INVALID_WEAPON_ID) return showPlayerRPremadedWeaponsMenu(playerid);				
				if(type == 0) weapon_slot = getWeaponSlot(g_Round_Weapon_Set[slot][WEAPON_SETS_WEAPON_2]);
				else weapon_slot = getWeaponSlot(g_Round_Weapon_Set[slot][WEAPON_SETS_WEAPON_1]);	
			} else {
				if(type == 0) weapon_slot = (GetPVarInt(playerid, PV_PREMADE_WEAPON_2) == INVALID_WEAPON_ID ? -1 : getWeaponSlot(GetPVarInt(playerid, PV_PREMADE_WEAPON_2)));
				else weapon_slot = (GetPVarInt(playerid, PV_PREMADE_WEAPON_1) == INVALID_WEAPON_ID ? -1 : getWeaponSlot(GetPVarInt(playerid, PV_PREMADE_WEAPON_1)));				
			}
			
			switch(listitem) {			
				case 0..15: {
					new weaponid;	
		
					switch(listitem) {
						case 0:			weaponid = 16;
						case 1..14: 	weaponid = listitem + 21;
						case 15:		weaponid = 38;
						default: {
							showPlayerRPermadedWeaponsList(playerid);
							return 1;
						}
					}
					
					if(weapon_slot != getWeaponSlot(weaponid)) {						
						if(GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 0) {
							if(type == 0) g_Round_Weapon_Set[slot][WEAPON_SETS_WEAPON_1] = weaponid;
							else g_Round_Weapon_Set[slot][WEAPON_SETS_WEAPON_2] = weaponid;
						} else {
							if(type == 0) SetPVarInt(playerid, PV_PREMADE_WEAPON_1, weaponid);
							else SetPVarInt(playerid, PV_PREMADE_WEAPON_2, weaponid);
						}						
					} else return showPlayerRPermadedWeaponsList(playerid);

					showPlayerRPremadedWeapsSubmenu(playerid);
				}
				
				
				default: {
					new /*string[512], */w_name[32];					
					g_String_512[0] = EOS;
					for(i = 16 ; i < 39; i ++) {
						if(isValidWeapon(i)) {
							GetWeaponName(i, w_name, sizeof(w_name));
							format(g_String_512, sizeof(g_String_512), "%s\n%s%s", g_String_512, getWeaponSlot(i) == weapon_slot ? (C_KICK) : (COLOR_DIALOG_BODY), w_name);
						}
					}

					ShowPlayerDialog(playerid, DIALOG_ROUND_PERMADED_WEAPONS_LIST, DIALOG_STYLE_LIST, caption, g_String_512, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
				}
			}		
		}
		return 1;
	}
	return 0;
}