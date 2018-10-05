/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
hidePlayerDialog(&playerid) ShowPlayerDialog(playerid, -1, DIALOG_STYLE_MSGBOX, " ", " ", " ", "");
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define BACK_NON								0
#define	BACK_VEHICLE_NAMES						1
#define	BACK_WEAPON_SET_SELECT_MENU				2
#define	BACK_WEAPON_FREECHOSE_WEAPONS_MENU		3
#define	BACK_MATCH_ROUNDS						4
#define	BACK_TO_SUBMENU_SETTINGS				5
#define	BACK_TEAM_SETTINGS						6
#define BACK_ROUND_SETTINGS						7
#define BACK_HELP_MENU							8
#define BACK_HELP_MENU_CMDS_LIST				9
#define BACK_CRASH_ADD_LIST						10
#define BACK_CRASH_ADD_PLAYER_INFO				11
//==============================================================================
showPlayerBackDialog(&playerid, backid, caption[], body[]) {
	SetPVarInt(playerid, PV_HELP_BACK_VAR, backid);
	ShowPlayerDialog(playerid, DIALOG_BACK, DIALOG_STYLE_MSGBOX, caption, body, oftenUsedPhrases(LANG_OUP_BACK), "");
	return 1;
}
//------------------------------------------------------------------------------
backDialogResponse(&playerid) {
	switch(GetPVarInt(playerid, PV_HELP_BACK_VAR)) {
		case BACK_NON:								{}
		case BACK_VEHICLE_NAMES: 					showPlayerRoundVehSelectMenu(playerid);
		case BACK_WEAPON_SET_SELECT_MENU: 			{}
		case BACK_WEAPON_FREECHOSE_WEAPONS_MENU: 	{}
		case BACK_MATCH_ROUNDS:						showPlayerPlayedRounds(playerid);
		case BACK_TO_SUBMENU_SETTINGS: 				sumbenuSettingsResponse(playerid);
		case BACK_TEAM_SETTINGS:					showPlayerTeamSettingsSetMenu(playerid);
		case BACK_ROUND_SETTINGS:					showPlayerRoundSettingsMenu(playerid);
		case BACK_HELP_MENU:						showPlayerHelpMenu(playerid);
		case BACK_HELP_MENU_CMDS_LIST:				showPlayerCMDsList(playerid);
		case BACK_CRASH_ADD_LIST:					showCrashedPlayersList(playerid);
		case BACK_CRASH_ADD_PLAYER_INFO:			showDetailedCrasherPlayerInfo(playerid, GetPVarInt(playerid, PV_HELP_VAR_2));
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	CONFIRM_DELETE_ROUND					0
//==============================================================================
showPlayerConfirmDialog(&playerid, confirmid, caption[], body[]) {
	SetPVarInt(playerid, PV_HELP_CONFIRM_VAR, confirmid);
	ShowPlayerDialog(playerid, DIALOG_CONFIRM, DIALOG_STYLE_MSGBOX, caption, body, oftenUsedPhrases(LANG_OUP_YES), oftenUsedPhrases(LANG_OUP_NO));	
}
//------------------------------------------------------------------------------
confirmDialogResponse(&playerid, confirm) {
	switch(GetPVarInt(playerid, PV_HELP_CONFIRM_VAR)) {
		case CONFIRM_DELETE_ROUND: {
			if(confirm) deleteMatchRoundDataMenu(playerid, true);
			else showPlayerPlayedRounds(playerid, GetPVarInt(playerid, PV_HELP_VAR_1));
		}		
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define PV_VALUE_DIALOG_BACK					"PVValueDialogBack"
//------------------------------------------------------------------------------
#define	DIALOG_VALUE_WEATHER					0
#define	DIALOG_VALUE_WORLD_TIME					1
#define DIALOG_VALUE_BASE_TIME					2
#define DIALOG_VALUE_ARENA_TIME					3
#define	DIALOG_VALUE_CP_CAPTURE_TIME			4
#define	DIALOG_VALUE_SPAWNPROTECT_TIME			5
#define	DIALOG_VALUE_DEFBASE_TIME				6
#define DIALOG_VALUE_MAX_PING_VALUE				7
#define DIALOG_VALUE_MAX_PING_WARNINGS			8
#define DIALOG_VALUE_MIN_FPS_VALUE				9
#define DIALOG_VALUE_MIN_FPS_WARNINGS			10
#define DIALOG_VALUE_MAX_PLOSS_WARNINGS			11
#define DIALOG_VALUE_FWEAPONS_AMMO				12
#define DIALOG_VALUE_FWEAPONS_PLAYERS			13
#define	DIALOG_VALUE_FREE_CHOICE_SLOTS			14
#define	DIALOG_VALUE_CONST_WEAPONS_AMMO			15
#define	DIALOG_VALUE_PERMADED_WEAPONS_AMMO		16
#define	DIALOG_VALUE_PERMADED_WEAPONS_PLAYERS	17
#define	DIALOG_VALUE_GUN_CMD_TIME				18
#define	DIALOG_VALUE_VEHICLE_FIX_TIME			19
#define	DIALOG_VALUE_SPAWNPROTECT_ARENA_TIME	20
#define	DIALOG_VALUE_ARENA_TDM_LIMIT			21
#define	DIALOG_VALUE_AMACRO_MAX_CLICKS			22
#define DIALOG_VALUE_AMACRO_MAX_CRITICAL_CLICKS	23
#define	DIALOG_VALUE_AMACRO_MAX_WARNINGS		24
//==============================================================================
showPlayerValueDialogBack(&playerid, backid, s_value[] = "", bool:response_false = false) {
	new head[64], string[512], info[128];
	new value, bool:set_value;
	if(11 > strlen(s_value) > 0 && ('9' >= s_value[0] >= '0' || (strlen(s_value) > 1 && s_value[0] == '-' && '9' >= s_value[1] >= '0'))) {
		value = strval(s_value);
		set_value = true;
	}
	SetPVarInt(playerid, PV_VALUE_DIALOG_BACK, backid);
	switch(backid) {
		case DIALOG_VALUE_WEATHER: {
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return sumbenuSettingsResponse(playerid);
			else if(set_value == true) {
				if(20 >= value >= 0) {					
					cmd_weather(playerid, s_value);
					sumbenuSettingsResponse(playerid);
					return 1;
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_WEATHER, 1);
			}				
			getSettingsCaptionMessage(head, SCM_SERVER, 0);
			getSettingsSettingBodyMessage(string, SBM_SETTING_WEATHER, 0);				
			format(string, sizeof(string), string, info);
		}
		case DIALOG_VALUE_WORLD_TIME: {
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return sumbenuSettingsResponse(playerid);
			else if(set_value == true) {
				if(24 >= value >= 0) {
					cmd_wtime(playerid, s_value);
					sumbenuSettingsResponse(playerid);
					return 1;
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_WORLD_TIME, 1);
			}				
			getSettingsCaptionMessage(head, SCM_SERVER, 0);
			getSettingsSettingBodyMessage(string, SBM_SETTING_WORLD_TIME, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_BASE_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(60 >= value >= 3) {					
					setRoundTime(ROUND_TYPE_BASE, value);					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Base Time", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					
					return showPlayerRoundSettingsMenu(playerid);
					
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_BASE_TIME, 1);
			}				
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_BASE_TIME, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_ARENA_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(60 >= value >= 3) {
					setRoundTime(ROUND_TYPE_ARENA, value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Arena Time", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerRoundSettingsMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_ARENA_TIME, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_ARENA_TIME, 0);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_CP_CAPTURE_TIME: {
			getSettingsCaptionMessage(head, SCM_MENU_CHECKPOINT, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerCheckpointSettingMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(120 >= value >= 5) {
					setRoundCheckpointCaptureTime(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Checkpoint: Capture Time", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerCheckpointSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_CHECKPOINT_TIME, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_CHECKPOINT_TIME, 0);				
			format(string, sizeof(string), string, info);
		}						
		case DIALOG_VALUE_SPAWNPROTECT_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND_SPAWN_PROTECT, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerSpawnProtectMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(120 >= value >= 0) {
					setSpawnProtectSettingTime(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Spawn Protect: Duration", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerSpawnProtectMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_SPAWNPROTECT_TIME, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_SPAWNPROTECT_TIME, 0);				
			format(string, sizeof(string), string, info);
		}							
		case DIALOG_VALUE_DEFBASE_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(60 >= value >= 10) {
					setDefendersBaseBackTime(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Defenders: Time to return", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerRoundSettingsMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_DEFBASE_TIME, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_DEFBASE_TIME, 0);				
			format(string, sizeof(string), string, info);
		}				
		case DIALOG_VALUE_MAX_PING_VALUE: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(9999 >= value >= 10) {
					setMaxPingValue(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Max Ping: Value", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_MAX_PING_VALUE, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_MAX_PING_VALUE, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_MAX_PING_WARNINGS: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(99 >= value >= 1) {
					setProtectorMaxWarnings(PROTECTOR_CHECK_PING, value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Max Ping: Warnings", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_WARNINGS, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_WARNINGS, 0);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_MIN_FPS_VALUE: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(89 >= value >= 1) {
					setMinFPSValue(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Min FPS: Value", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_MIN_FPS_VALUE, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_MIN_FPS_VALUE, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_MIN_FPS_WARNINGS: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(99 >= value >= 1) {
					setProtectorMaxWarnings(PROTECTOR_CHECK_FPS, value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Min FPS: Warnings", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_WARNINGS, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_WARNINGS, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_MAX_PLOSS_WARNINGS: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(99 >= value >= 1) {
					setProtectorMaxWarnings(PROTECTOR_CHECK_PLOSS, value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Max PLoss: Warnings", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_WARNINGS, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_WARNINGS, 0);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_FWEAPONS_AMMO: {
			new weaponid;
			GetWeaponName((weaponid = GetPVarInt(playerid, PV_HELP_VAR_4)), head, sizeof(head));
			strins(head, COLOR_DIALOG_HEAD, 0);

			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRFreeWeaponsSubmenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(9999 >= value >= 0) {					
					setFreeChoseWeaponData(weaponid, WEAPON_FC_AMMO, value);				
					return showPlayerRFreeWeaponsSubmenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_FWEAPONS_INFO, 1);
			}						
			getDialogBodyMessage(string, DIALOG_BODY_FWEAPONS_INFO, 0);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_FWEAPONS_PLAYERS: {
			new weaponid;
			GetWeaponName((weaponid = GetPVarInt(playerid, PV_HELP_VAR_4)), head, sizeof(head));
			strins(head, COLOR_DIALOG_HEAD, 0);

			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRFreeWeaponsSubmenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(999 >= value >= 0) {		
					setFreeChoseWeaponData(weaponid, WEAPON_FC_MAX_PLAYERS, value);			
					return showPlayerRFreeWeaponsSubmenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_FWEAPONS_INFO, 3);
			}						
			getDialogBodyMessage(string, DIALOG_BODY_FWEAPONS_INFO, 2);				
			format(string, sizeof(string), string, info);
		}			
		case DIALOG_VALUE_FREE_CHOICE_SLOTS: {
			getSettingsCaptionMessage(head, SCM_ROUND_WEAPONS, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRWeaponsSettingMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(5 >= value >= 1) {		
					setFreeChoiceMaxSlots(value);			
					return showPlayerRWeaponsSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_FWEAPONS_INFO, 5);
			}						
			getDialogBodyMessage(string, DIALOG_BODY_FWEAPONS_INFO, 4);				
			format(string, sizeof(string), string, info);		
		}
		case DIALOG_VALUE_CONST_WEAPONS_AMMO: {
			getSettingsCaptionMessage(head, SCM_ROUND_WEAPONS, 0);

			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRConstWeaponsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(setStaticWeaponAmmo(GetPVarInt(playerid, PV_HELP_VAR_4), value)) {
					return showPlayerRConstWeaponsMenu(playerid);
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_ROUND_CONST_WEAPONS, 2);
			}						
			getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_CONST_WEAPONS, 1);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_PERMADED_WEAPONS_AMMO: {
			getSettingsCaptionMessage(head, SCM_ROUND_WEAPONS, 0);
			
			if(!checkPremadeEditMode(playerid)){
				showPlayerRPremadedWeaponsMenu(playerid);
				return 1;
			}						
			
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRPremadedWeapsSubmenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(setPermadedWeaponAmmo(GetPVarInt(playerid, PV_HELP_VAR_4), GetPVarInt(playerid, PV_HELP_VAR_5), value, (GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 1 ? true : false), playerid)) {
					return showPlayerRPremadedWeapsSubmenu(playerid);
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_ROUND_PREMADED_WEAPONS, 2);
				
			}						
			getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_PREMADED_WEAPONS, 1);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_PERMADED_WEAPONS_PLAYERS: {
			getSettingsCaptionMessage(head, SCM_ROUND_WEAPONS, 0);

			if(!checkPremadeEditMode(playerid)){
				showPlayerRPremadedWeaponsMenu(playerid);
				return 1;
			}							
			
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRPremadedWeapsSubmenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(setPermadedWeaponPlayers(GetPVarInt(playerid, PV_HELP_VAR_4), value, (GetPVarInt(playerid, PV_PREMADE_CREATE_MODE) == 1 ? true : false), playerid)) {
					return showPlayerRPremadedWeapsSubmenu(playerid);
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_ROUND_PREMADED_WEAPONS, 5);				
			}						
			getSettingsSettingBodyMessage(string, SBM_SETTING_ROUND_PREMADED_WEAPONS, 4);				
			format(string, sizeof(string), string, info);
		}		
		case DIALOG_VALUE_GUN_CMD_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND_WEAPONS, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRWeaponsSettingMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(9999 >= value >= 10) {		
					setGunMenuTime(value);			
					return showPlayerRWeaponsSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_CMD_GUN_TIME, 1);
			}						
			getDialogBodyMessage(string, DIALOG_BODY_CMD_GUN_TIME, 0);				
			format(string, sizeof(string), string, info);		
		}		
		case DIALOG_VALUE_VEHICLE_FIX_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND_FIX_VEHICLES, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(set_value == true) {
				if(600 >= value >= 0) {		
					setSelfVehRepairMinTime(value);			
					return showPlayerRoundSettingsMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_FIX_VEHICLE_MENU, 1);
			}						
			getDialogBodyMessage(string, DIALOG_BODY_FIX_VEHICLE_MENU, 0);				
			format(string, sizeof(string), string, info);		
		}
		case DIALOG_VALUE_SPAWNPROTECT_ARENA_TIME: {
			getSettingsCaptionMessage(head, SCM_ROUND_SPAWN_PROTECT, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerSpawnProtectMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(120 >= value >= 0) {
					setArenaSpawnProtectSettingTime(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Spawn Protect (Arena): Duration", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerSpawnProtectMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_SPAWNPROTECT_TIME, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_SPAWNPROTECT_TIME, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_VALUE_ARENA_TDM_LIMIT: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(999 >= value >= 1) {					
					setArenaTDMKillLimit(value);					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "Arena TDM Points Limit", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					
					return showPlayerRoundSettingsMenu(playerid);
					
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_ARENA_TDM_POINTS_LIMIT, 1);
			}				
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_ARENA_TDM_POINTS_LIMIT, 0);				
			format(string, sizeof(string), string, info);
		}			
		case DIALOG_VALUE_AMACRO_MAX_CLICKS: {
			getSettingsCaptionMessage(head, SCM_ANTYMACRO, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerAntyMacroMenu(playerid);
			else if(set_value == true) {
				if(13 >= value >= 7) {					
					setAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_INPUTS, value);				
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "AntyMacro - Av.Inputs", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					
					return showPlayerAntyMacroMenu(playerid);
					
				} else getDialogBodyMessage(info, DIALOG_BODY_ANTYMACRO_SETTINGS, 0);
			}				
			getDialogBodyMessage(string, DIALOG_BODY_ANTYMACRO_SETTINGS, 1);				
			format(string, sizeof(string), string, info);		
		}
		case DIALOG_VALUE_AMACRO_MAX_CRITICAL_CLICKS: {
			getSettingsCaptionMessage(head, SCM_ANTYMACRO, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerAntyMacroMenu(playerid);
			else if(set_value == true) {
				if(99 >= value >= 14) {					
					setAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS, value);				
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "AntyMacro - Cr.Inputs", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					
					return showPlayerAntyMacroMenu(playerid);
					
				} else getDialogBodyMessage(info, DIALOG_BODY_ANTYMACRO_SETTINGS, 0);
			}				
			getDialogBodyMessage(string, DIALOG_BODY_ANTYMACRO_SETTINGS, 2);				
			format(string, sizeof(string), string, info);		
		}
		case DIALOG_VALUE_AMACRO_MAX_WARNINGS: {
			getSettingsCaptionMessage(head, SCM_ANTYMACRO, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerAntyMacroMenu(playerid);
			else if(set_value == true) {
				if(10 >= value >= 1) {					
					setAntiMacroValue(ANTI_MACRO_MAX_WARNINGS, value);				
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), "AntyMacro - Max Warnings", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					
					return showPlayerAntyMacroMenu(playerid);
					
				} else getDialogBodyMessage(info, DIALOG_BODY_ANTYMACRO_SETTINGS, 0);
			}				
			getDialogBodyMessage(string, DIALOG_BODY_ANTYMACRO_SETTINGS, 3);				
			format(string, sizeof(string), string, info);		
		}
	}	
	ShowPlayerDialog(playerid, DIALOG_VALUE, DIALOG_STYLE_INPUT, head, string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
	return 1;
}


//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define PV_F_VALUE_DIALOG_BACK					"PVFValueDialogBack"
//------------------------------------------------------------------------------
#define	DIALOG_F_VALUE_NAMETAG_DIS				0
#define	DIALOG_F_VALUE_GRAVITY					1
#define DIALOG_F_VALUE_ROUND_ARMOUR				2
#define	DIALOG_F_VALUE_MAX_PLOSS_VALUE			3
#define DIALOG_F_VALUE_CHECKPOINT_SIZE			4
//==============================================================================
showPlayerFloatValueDialogBack(&playerid, backid, s_value[] = "", bool:response_false = false) {
	new head[64], string[256], info[128];
	new Float:value, bool:set_value;
	if(11 > strlen(s_value) > 0 && ('9' >= s_value[0] >= '0' || (strlen(s_value) > 1 && s_value[0] == '-' && '9' >= s_value[1] >= '0'))) {
		value = floatstr(s_value);
		set_value = true;
	}
	SetPVarInt(playerid, PV_F_VALUE_DIALOG_BACK, backid);
	switch(backid) {
		case DIALOG_F_VALUE_NAMETAG_DIS: {
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return sumbenuSettingsResponse(playerid);
			else if(set_value == true) {
				if(250.0 >= value >= 5.0) {
					cmd_nametagdis(playerid, s_value);
					sumbenuSettingsResponse(playerid);
					return 1;
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_NAMETAG_DIS, 1);
			}				
			getSettingsCaptionMessage(head, SCM_SERVER, 0);
			getSettingsSettingBodyMessage(string, SBM_SETTING_NAMETAG_DIS, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_F_VALUE_GRAVITY: {
			getSettingsCaptionMessage(head, SCM_SERVER, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_TO_SUBMENU_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(response_false == true) return sumbenuSettingsResponse(playerid);
			else if(set_value == true) {
				if(50.0 >= value >= -50.0) {
					cmd_gravity(playerid, s_value);
					sumbenuSettingsResponse(playerid);
					return 1;
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_GRAVITY, 1);
			}				
			getSettingsSettingBodyMessage(string, SBM_SETTING_GRAVITY, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_F_VALUE_ROUND_ARMOUR: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerRoundSettingsMenu(playerid);
			else if(getRoundState() != ROUND_STATE_LOBBY) return showPlayerBackDialog(playerid, BACK_ROUND_SETTINGS, head, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
			else if(set_value == true) {
				if(100.0 >= value >= 0.0) {
					setRoundArmour(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 3);
					format(string, sizeof(string), string, getPlayerName(playerid), "Armour", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerRoundSettingsMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_ROUND_ARMOUR, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_ROUND_ARMOUR, 0);				
			format(string, sizeof(string), string, info);
		}	
		case DIALOG_F_VALUE_MAX_PLOSS_VALUE: {
			getSettingsCaptionMessage(head, SCM_ROUND, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerProtectorSettingMenu(playerid);
			else if(set_value == true) {
				if(99.0 >= value >= 1.0) {
					setMaxPLossValue(value);					
					
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 3);
					format(string, sizeof(string), string, getPlayerName(playerid), "Max PLoss: Value", value);
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);					
					return showPlayerProtectorSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_PROTECTOR_MAX_PLOSS_VALUE, 1);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_PROTECTOR_MAX_PLOSS_VALUE, 0);				
			format(string, sizeof(string), string, info);
		}			
		case DIALOG_F_VALUE_CHECKPOINT_SIZE: {
			getSettingsCaptionMessage(head, SCM_MENU_CHECKPOINT, 0);
			if(!IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) return 0;
			else if(response_false == true) return showPlayerCheckpointSettingMenu(playerid);
			else if(set_value == true) {
				if(10.0 >= value >= 1.0) {
					setCheckpointSize(value);									
					return showPlayerCheckpointSettingMenu(playerid);
				} else getDialogBodyMessage(info, DIALOG_BODY_CHECKPOINT_MENU, 2);
			}				
			
			getDialogBodyMessage(string, DIALOG_BODY_CHECKPOINT_MENU, 1);				
			format(string, sizeof(string), string, info);		
		}	
	}
	ShowPlayerDialog(playerid, DIALOG_F_VALUE, DIALOG_STYLE_INPUT, head, string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
	return 1;
}