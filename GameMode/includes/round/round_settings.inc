/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerRoundSettingsMenu(playerid, settingid = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(settingid == -1) {
			new string[1024];
							
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_SETTINGS, 0);
			format(string, sizeof(string), string,
				getSettingName(SETTING_NAME_WEAPON_MODE, (getWeaponSelectType() == PERMADED_WEAPON_SETS ? 1 : 0)),
				getRoundTime(ROUND_TYPE_BASE),
				getRoundTime(ROUND_TYPE_ARENA),
				getArenaTDMKillLimit(),
				(getOneOnOneMarkersStatus() ? (C_LIGHTGREEN) : (C_KICK)),
				(getDefendersBaseStatus() ? (C_LIGHTGREEN) : (C_KICK)),
				getDefendersBaseBackTime(),
				getRoundArmour(),
				(getArenaRoundWinMode() == WIN_PLAYERS_ADVANTAGE ? ("Players") : ("Health")),
				((getAutoSwapMode() == AUTOSWAP_NO) ? (C_KICK"Off") : (getAutoSwapMode() == AUTOSWAP_ONLY_TEAM) ? (C_LIGHTGREEN"Only Team") : (C_LIGHTGREEN"Team + Skin")),
				((syncInFall()) ? (C_LIGHTGREEN) : (C_KICK)),
				((getSelfRemoveStatus()) ? (C_LIGHTGREEN) : (C_KICK)),
				(g_MilitaryBaseObjects == -1 ? (C_KICK) : (C_LIGHTGREEN)),
				(getSelfVehRepairStatus() ? (C_LIGHTGREEN) : (C_KICK)),
				getSelfVehRepairMinTime()
			);
			ShowPlayerDialog(playerid, DIALOG_ROUND_SETTINGS_1, DIALOG_STYLE_TABLIST_HEADERS, getDialogCaptionMessage(DIALOG_CAPTION_ROUND_SETTINGS), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases((GetPVarInt(playerid, PV_HELP_VAR_2) == 0 ? LANG_OUP_EXIT : LANG_OUP_BACK)));
		} else {
			new string[144];
			switch(settingid) {
				case 0: {
					showPlayerCrashAddSettingsMenu(playerid);
					return 1;				
				}
				case 1: {
					showPlayerRoundVehiclesMenu(playerid);
					return 1;
				}
				case 2: {
					showPlayerSpawnProtectMenu(playerid);
					return 1;
				}
				case 3: {
					showPlayerCheckpointSettingMenu(playerid);
					return 1;
				}				
				case 4: {
					showPlayerRWeaponsSettingMenu(playerid);
					return 1;
				}
				case 5: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_BASE_TIME);
				case 6: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_ARENA_TIME);
				case 7: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_ARENA_TDM_LIMIT);
				case 8: {
					setOneOnOneMarkersStatus(!getOneOnOneMarkersStatus());	
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getOneOnOneMarkersStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "1on1 Markers");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
				}				
				case 9: {
					setDefendersBaseStatus(!getDefendersBaseStatus());	
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getDefendersBaseStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "Obszar bazy dla obroncow");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
				}
				case 10: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_DEFBASE_TIME);
				case 11: return showPlayerFloatValueDialogBack(playerid, DIALOG_F_VALUE_ROUND_ARMOUR);
				case 12: {
					setArenaRoundWinMode((getArenaRoundWinMode() == WIN_HEALH_ADVANTAGE ? WIN_PLAYERS_ADVANTAGE : WIN_HEALH_ADVANTAGE));
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 4);	
					format(string, sizeof(string), string, getPlayerName(playerid), "Zwyciestwo na arenie (koniec czasu)", (getArenaRoundWinMode() == WIN_PLAYERS_ADVANTAGE ? ("Przewaga graczy") : ("Przewaga HP")));
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
				}	
				case 13: {
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 4);	
					switch(getAutoSwapMode()) {						
						case AUTOSWAP_NO: {
							setAutoSwapMode(AUTOSWAP_ONLY_TEAM);
							format(string, sizeof(string), string, getPlayerName(playerid), "Auto Swap", C_LIGHTGREEN"Only Team");
						}
						case AUTOSWAP_ONLY_TEAM: {
							setAutoSwapMode(AUTOSWAP_TEAM_AND_SKIN);
							format(string, sizeof(string), string, getPlayerName(playerid), "Auto Swap", C_LIGHTGREEN"Team + Skin");
						}
						default: {
							setAutoSwapMode(AUTOSWAP_NO);
							format(string, sizeof(string), string, getPlayerName(playerid), "Auto Swap", C_KICK"Off");
						}
					}			
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);						
				}	
				case 14: {
					setSyncInFallStatus(!syncInFall());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, syncInFall());	
					format(string, sizeof(string), string, getPlayerName(playerid), "Respawn przy spadaniu");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);	
				}				
				case 15: {
					setSelfRemoveStatus(!getSelfRemoveStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getSelfRemoveStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "Self-Remove");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);				
				}
				case 16: {
					cmd_labo(playerid, ((g_MilitaryBaseObjects == -1) ? ("On") : ("Off")));
				}
				case 17: {
					setSelfVehRepairStatus(!getSelfVehRepairStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getSelfVehRepairStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "Self-Vehicle-Fix");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
				}
				case 18: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_VEHICLE_FIX_TIME);
			}
			showPlayerRoundSettingsMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerCheckpointSettingMenu(playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) { 
		new string[220];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_MENU_CHECKPOINT);
			if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else {
				getDialogBodyMessage(string, DIALOG_BODY_CHECKPOINT_MENU, 0);
				format(string, sizeof(string), string, 					
					getCheckpointCaptureTime(),
					getCheckpointSize(),
					((getCaptureModeFlag() & CP_CAPTURE_NORMAL) ? (C_LIGHTGREEN) : (C_KICK)),
					((getCaptureModeFlag() & CP_CAPTURE_IN_VEHICLE) ? (C_LIGHTGREEN) : (C_KICK)),
					((getCaptureModeFlag() & CP_CAPTURE_DEFENDER_ABORT) ? (C_LIGHTGREEN) : (C_KICK))			
				);
				ShowPlayerDialog(playerid, DIALOG_ROUND_CHECKPOINT_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
			}
		} else {
			switch(listitem) {
				case 0: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_CP_CAPTURE_TIME);
				}
				case 1: {
					showPlayerFloatValueDialogBack(playerid, DIALOG_F_VALUE_CHECKPOINT_SIZE);
				}
				case 2: {
					if(getCaptureModeFlag() & CP_CAPTURE_NORMAL) removeCheckpointCaptureFlag(CP_CAPTURE_NORMAL);
					else addCheckpointCaptureFlag(CP_CAPTURE_NORMAL);
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getCaptureModeFlag() & CP_CAPTURE_NORMAL ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Przejecie CP");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);
					showPlayerCheckpointSettingMenu(playerid);
				}				
				case 3: {
					if(getCaptureModeFlag() & CP_CAPTURE_IN_VEHICLE) removeCheckpointCaptureFlag(CP_CAPTURE_IN_VEHICLE);
					else addCheckpointCaptureFlag(CP_CAPTURE_IN_VEHICLE);
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getCaptureModeFlag() & CP_CAPTURE_IN_VEHICLE ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Przejecie CP w pojezdzie");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);			
					showPlayerCheckpointSettingMenu(playerid);
				}
				case 4: {
					if(getCaptureModeFlag() & CP_CAPTURE_DEFENDER_ABORT) removeCheckpointCaptureFlag(CP_CAPTURE_DEFENDER_ABORT);
					else addCheckpointCaptureFlag(CP_CAPTURE_DEFENDER_ABORT);
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getCaptureModeFlag() & CP_CAPTURE_DEFENDER_ABORT ? 1 : 0));					
					format(string, sizeof(string), string, getPlayerName(playerid), "Anulowanie przejecia CP przez obronce");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);	
					showPlayerCheckpointSettingMenu(playerid);
				}
				default: {
					showPlayerCheckpointSettingMenu(playerid);			
				}	
			}
		}
	}
	return 1;
}
//==============================================================================
showPlayerSpawnProtectMenu(playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) { 
		new string[275];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_MENU_SPAWN_PROTECT);
			if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else {
				getDialogBodyMessage(string, DIALOG_BODY_SPAWNPROTECT_MENU, 0);
				format(string, sizeof(string), string, 				
					getSpawnProtectSettingTime(),
					getArenaSpawnProtectSettingTime(),
					((getSpawnProtectFlags() & SP_FIRST_BLOOD) ? (C_LIGHTGREEN) : (C_KICK)),
					((getSpawnProtectFlags() & SP_ANTI_FALL) ? (C_LIGHTGREEN) : (C_KICK)),
					((getSpawnProtectFlags() & SP_ANTI_FALL_AUTO_ADD) ? (C_LIGHTGREEN) : (C_KICK)),
					((getSpawnProtectFlags() & SP_ANTI_FALL_AUTO_ADD) ? (oftenUsedPhrases(LANG_OUP_YES)) : (oftenUsedPhrases(LANG_OUP_NO)))
				);
				ShowPlayerDialog(playerid, DIALOG_ROUND_SPAWNPROTECT_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
			}
		} else {
			switch(listitem) {
				case 0: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_SPAWNPROTECT_TIME);
				}
				case 1: {
					showPlayerValueDialogBack(playerid, DIALOG_VALUE_SPAWNPROTECT_ARENA_TIME);
				}				
				case 2: {
					if(getSpawnProtectFlags() & SP_FIRST_BLOOD) removeSpawnProtectFlag(SP_FIRST_BLOOD);
					else addSpawnProtectFlag(SP_FIRST_BLOOD);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getSpawnProtectFlags() & SP_FIRST_BLOOD ? 1 : 0));	
					format(string, sizeof(string), string, getPlayerName(playerid), "Spawn Protect: First Blood");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);
					showPlayerSpawnProtectMenu(playerid);	
				}
				case 3: {
					if(getSpawnProtectFlags() & SP_ANTI_FALL) removeSpawnProtectFlag(SP_ANTI_FALL);
					else addSpawnProtectFlag(SP_ANTI_FALL);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getSpawnProtectFlags() & SP_ANTI_FALL ? 1 : 0));	
					format(string, sizeof(string), string, getPlayerName(playerid), "Spawn Protect: Anti Fall");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);		
					showPlayerSpawnProtectMenu(playerid);	
				}
				case 4: {
					if(getSpawnProtectFlags() & SP_ANTI_FALL_AUTO_ADD) removeSpawnProtectFlag(SP_ANTI_FALL_AUTO_ADD);
					else addSpawnProtectFlag(SP_ANTI_FALL_AUTO_ADD);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getSpawnProtectFlags() & SP_ANTI_FALL_AUTO_ADD ? 1 : 0));	
					format(string, sizeof(string), string, getPlayerName(playerid), "Spawn Protect: Anti Fall Auto Add");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);				
					showPlayerSpawnProtectMenu(playerid);	
				}
				default: {
					showPlayerSpawnProtectMenu(playerid);			
				}	
			}
		}
	}
	return 1;
}
//==============================================================================
showPlayerCrashAddSettingsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[180];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_MENU_C_ADD);
			getDialogBodyMessage(string, DIALOG_BODY_CRASH_LIST, 7);
			format(string, sizeof(string), string, getCrashAutoPauseStatus() ? (C_LIGHTGREEN) : (C_KICK), getRoundCrashAddStatus() ? (C_LIGHTGREEN) : (C_KICK));
			ShowPlayerDialog(playerid, DIALOG_ROUND_C_ADD_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
		} else {
			switch(listitem) {
				case 0: {
					showPlayerCrashAddReasonsMenu(playerid);
				}
				case 1: {
					setCrashAutoPauseStatus(!getCrashAutoPauseStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getCrashAutoPauseStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "C-Add: Auto Pause");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);				
					showPlayerCrashAddSettingsMenu(playerid);					
				}
				case 2: {
					setRoundCrashAddStatus(!getRoundCrashAddStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, getRoundCrashAddStatus());	
					format(string, sizeof(string), string, getPlayerName(playerid), "C-Add: Auto Add");
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);				
					showPlayerCrashAddSettingsMenu(playerid);					
				}
				default: showPlayerCrashAddSettingsMenu(playerid);
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerCrashAddReasonsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(listitem == -1) {
			new string[128], caption[64];
			getSettingsCaptionMessage(caption, SCM_MENU_C_ADD);
			getDialogBodyMessage(string, DIALOG_BODY_CRASH_LIST, 6);
			format(string, sizeof(string), string, getRoundCrashPauseStatus() & C_ADD_CRASHED ? (C_LIGHTGREEN) : (C_KICK), getRoundCrashPauseStatus() & C_ADD_LEAVING ? (C_LIGHTGREEN) : (C_KICK), getRoundCrashPauseStatus() & C_ADD_KICKED ? (C_LIGHTGREEN) : (C_KICK));
			ShowPlayerDialog(playerid, DIALOG_ROUND_C_ADD_REASONS_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
		} else {
			switch(listitem) {
				case 0: {
					if(getRoundCrashPauseStatus() & C_ADD_CRASHED) subRoundCrashPauseStatus(C_ADD_CRASHED);
					else addRoundCrashPauseStatus(C_ADD_CRASHED);
					showPlayerCrashAddReasonsMenu(playerid);
				}
				case 1: {
					if(getRoundCrashPauseStatus() & C_ADD_LEAVING) subRoundCrashPauseStatus(C_ADD_LEAVING);
					else addRoundCrashPauseStatus(C_ADD_LEAVING);
					showPlayerCrashAddReasonsMenu(playerid);
				}
				case 2: {
					if(getRoundCrashPauseStatus() & C_ADD_KICKED) subRoundCrashPauseStatus(C_ADD_KICKED);
					else addRoundCrashPauseStatus(C_ADD_KICKED);
					showPlayerCrashAddReasonsMenu(playerid);
				}
				default: {
					showPlayerCrashAddReasonsMenu(playerid);			
				}
			}
		}
		return 1;
	}
	return 0;
}
//==============================================================================
showPlayerRoundVehiclesMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(listitem == -1) {
			new string[280], caption[64];
			getSettingsCaptionMessage(caption, SCM_ROUND_VEHICLES);
			getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 0);
			format(string, sizeof(string), "%sNitro\n%sHydraulics\n"COLOR_DIALOG_BODY"-----------------------------\n%s", getVehicleTuningFlags() & ROUND_CARS_NITRO ? (C_LIGHTGREEN) : (C_KICK), getVehicleTuningFlags() & ROUND_CARS_HYDRAULICS ? (C_LIGHTGREEN) : (C_KICK), string);
			ShowPlayerDialog(playerid, DIALOG_ROUND_VEHICLE_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
		} else {
			switch(listitem) {
				case 0: {
					if(getVehicleTuningFlags() & ROUND_CARS_NITRO) removeVehicleTuningFlag(ROUND_CARS_NITRO);
					else addVehicleTuningFlag(ROUND_CARS_NITRO);
					showPlayerRoundVehiclesMenu(playerid);
				}
				case 1: {
					if(getVehicleTuningFlags() & ROUND_CARS_HYDRAULICS) removeVehicleTuningFlag(ROUND_CARS_HYDRAULICS);
					else addVehicleTuningFlag(ROUND_CARS_HYDRAULICS);
					showPlayerRoundVehiclesMenu(playerid);
				}
				case 2: showPlayerRoundVehiclesMenu(playerid);
				default: {
					SetPVarInt(playerid, PV_HELP_VAR_4, listitem - 3);
					showPlayerRoundVehiclesSubmenu(playerid);			
				}
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerRoundVehiclesSubmenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new VEHICLE_TYPES:type, string[700], caption[64];
		switch(GetPVarInt(playerid, PV_HELP_VAR_4)) {
			case 0: type = TYPE_MOTORBIKE;
			case 1: type = TYPE_BOAT;
			case 2: type = TYPE_HELICOPTER;
			case 3: type = TYPE_PLANE;
			case 4: type = TYPE_INDUSTRIAL;
			case 5: type = TYPE_OFFROAD;
			case 6: type = TYPE_PUBLIC_SERVICES;
			case 7: type = TYPE_CABRIOLET;
			case 8: type = TYPE_LOWRIDER;
			case 9: type = TYPE_SPORT_CAR;
			case 10: type = TYPE_COMBI;
			case 11: type = TYPE_NORMAL_CAR;
		}
		
		if(listitem != -1) {
			for(new i, counter; i < sizeof(g_VehicleList); i ++) {
				if(getVehicleTypeByIndex(i) == type && (counter ++) == listitem) {
					if(getVehicleFlagsByIndex(i) & VEHICLE_ROUND_SPAWN) getVehicleFlagsByIndex(i) -= VEHICLE_ROUND_SPAWN;
					else getVehicleFlagsByIndex(i) += VEHICLE_ROUND_SPAWN;
					break;
				}
			}
		}
		
		for(new i, v_name[16]; i < sizeof(g_VehicleList); i ++) {
			if(getVehicleTypeByIndex(i) == type) {
				strunpack(v_name, getVehicleNameByIndex(i));
				format(string, sizeof(string), "%s\n%s%s", string, (getVehicleFlagsByIndex(i) & VEHICLE_ROUND_SPAWN ? (C_LIGHTGREEN) : (C_KICK)), v_name);
			}
		}
		
		getSettingsCaptionMessage(caption, SCM_ROUND_VEHICLES);
		ShowPlayerDialog(playerid, DIALOG_ROUND_VEHICLE_SUBMENU, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));	
		return 1;
	}
	return 0;
}