/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
saveAllServerSettings() {
    saveVehicleData();
    saveSettingFile();
    saveWeaponSetData();
    saveWeaponData();
    saveStaticWeaponData();
    saveLobbyArenaDMData();
    saveAdminPassword();
}
//------------------------------------------------------------------------------
loadSettingFile() {
	if(fexist(DIR_GENERAL)) {
		new read[256];
		if(!fexist(FILE_LOG_SETTINGS)) {
			if(saveSettingFile()) {
				getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
				printf(read, "Settings", FILE_LOG_SETTINGS);			
			}
		} else {
			new File:f_settings = fopen(FILE_LOG_SETTINGS, io_read);
			new readline, load_data_int, Float:load_data_float, length, index;
			
			while(fread(f_settings, read, sizeof(read))) {
				DeleteNewLine(read);
				DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0))) {
					if(!strcmp(read, "t1_skin", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 299)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 299, FILE_LOG_SETTINGS, "w_time", readline);			
							logMultiAD_Error(read);							
						} else {
							setTeamSkin(TEAM_ONE, load_data_int);
						}						
					} else if(!strcmp(read, "t2_skin", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 299)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 299, FILE_LOG_SETTINGS, "t2_skin", readline);			
							logMultiAD_Error(read);							
						} else {
							setTeamSkin(TEAM_TWO, load_data_int);
						}						
					} else if(!strcmp(read, "t3_skin", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 299)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 299, FILE_LOG_SETTINGS, "t3_skin", readline);			
							logMultiAD_Error(read);							
						} else {
							setTeamSkin(TEAM_REF, load_data_int);
						}						
					} else if(!strcmp(read, "weather", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 20)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 20, FILE_LOG_SETTINGS, "weather", readline);			
							logMultiAD_Error(read);	
						} else {
							setServerWeather(load_data_int);							
						}						
					} else if(!strcmp(read, "w_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 24)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 24, FILE_LOG_SETTINGS, "w_time", readline);			
							logMultiAD_Error(read);							
						} else {
							setServerWorldTime(load_data_int);
						}						
					} else if(!strcmp(read, "ntag_draw_dis", true, index)) {
						if(sscanf(read[index + 1], "f", load_data_float) != 0 || !(5.0 <= load_data_float <= 250.0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 6);
							format(read, sizeof(read), read, 5.0, 250.0, FILE_LOG_SETTINGS, "ntag_draw_dis", readline);			
							logMultiAD_Error(read);							
						} else {
							setServerNameTagDistance(load_data_float);
						}						
					} else if(!strcmp(read, "gravity", true, index)) {
						if(sscanf(read[index + 1], "f", load_data_float) != 0 || !(-50.0 <= load_data_float <= 50.0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 6);
							format(read, sizeof(read), read, -50.0, 50.0, FILE_LOG_SETTINGS, "gravity", readline);			
							logMultiAD_Error(read);						
						} else {
							setServerGravity(load_data_float);
						}
					} else if(!strcmp(read, "language", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !changeDefaultLanguage(load_data_int)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 0, FILE_LOG_SETTINGS, "language", readline);			
							logMultiAD_Error(read);						
						} 
					} else if(!strcmp(read, "time_arenas", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(5 <= load_data_int <= 60)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 5, 60, FILE_LOG_SETTINGS, "time_arenas", readline);			
							logMultiAD_Error(read);						
						} else {
							setRoundTime(ROUND_TYPE_ARENA, load_data_int);
						}
					} else if(!strcmp(read, "time_bases", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(5 <= load_data_int <= 60)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 5, 60, FILE_LOG_SETTINGS, "time_bases", readline);			
							logMultiAD_Error(read);						
						} else {
							setRoundTime(ROUND_TYPE_BASE, load_data_int);
						}
					} else if(!strcmp(read, "cp_capture", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 7)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 7, FILE_LOG_SETTINGS, "cp_capture", readline);			
							logMultiAD_Error(read);						
						} else {
							setCheckpointCaptureMode(load_data_int);
						}
					} else if(!strcmp(read, "cp_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(5 <= load_data_int <= 120)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 5, 120, FILE_LOG_SETTINGS, "cp_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setRoundCheckpointCaptureTime(load_data_int);
						}
					} else if(!strcmp(read, "weapon_select", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "weapon_select", readline);			
							logMultiAD_Error(read);						
						} else {
							setWeaponSelectType(load_data_int);
						}
					} else if(!strcmp(read, "sp_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 120)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 120, FILE_LOG_SETTINGS, "sp_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setSpawnProtectSettingTime(load_data_int);
						}
					} else if(!strcmp(read, "sp_type", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 7)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 3, FILE_LOG_SETTINGS, "sp_type", readline);			
							logMultiAD_Error(read);						
						} else {
							setSpawnProtectFlags(load_data_int);
						}
					} else if(!strcmp(read, "r_armour", true, index)) {
						if(sscanf(read[index + 1], "f", load_data_float) != 0 || !(0.0 <= load_data_float <= 100.0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 6);
							format(read, sizeof(read), read, 0.0, 100.0, FILE_LOG_SETTINGS, "r_armour", readline);			
							logMultiAD_Error(read);						
						} else {
							setRoundArmour(load_data_float);
						}
					} else if(!strcmp(read, "awin_mode", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(WIN_HEALH_ADVANTAGE <= load_data_int <= WIN_PLAYERS_ADVANTAGE)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, WIN_HEALH_ADVANTAGE, WIN_PLAYERS_ADVANTAGE, FILE_LOG_SETTINGS, "awin_mode", readline);			
							logMultiAD_Error(read);						
						} else {
							setArenaRoundWinMode(load_data_int);
						}
					} else if(!strcmp(read, "swap_mode", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(AUTOSWAP_NO <= load_data_int <= AUTOSWAP_TEAM_AND_SKIN)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, AUTOSWAP_NO, AUTOSWAP_TEAM_AND_SKIN, FILE_LOG_SETTINGS, "swap_mode", readline);			
							logMultiAD_Error(read);						
						} else {
							setAutoSwapMode(load_data_int);
						}
					} else if(!strcmp(read, "defbase_mode", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "defbase_mode", readline);			
							logMultiAD_Error(read);						
						} else {
							setDefendersBaseStatus((load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "defbase_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(10 <= load_data_int <= 60)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 10, 60, FILE_LOG_SETTINGS, "defbase_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setDefendersBaseBackTime(load_data_int);
						}
					} else if(!strcmp(read, "fall_sync", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "fall_sync", readline);			
							logMultiAD_Error(read);						
						} else {
							setSyncInFallStatus((load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "team_damage_bar", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "team_damage_bar", readline);			
							logMultiAD_Error(read);						
						} else {
							setTeamDamageBarStatus((load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "l_int_veh", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "l_int_veh", readline);			
							logMultiAD_Error(read);						
						} else {
							setInteriorLobbyVehiclesStatus((load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "l_veh", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "l_veh", readline);			
							logMultiAD_Error(read);						
						} else {
							setLobbyVehiclesStatus((load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "glitch_slidebug", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "glitch_slidebug", readline);			
							logMultiAD_Error(read);						
						} else {
							setGlitchStatus(GLITCH_SLIDE_BUG, (load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "glitch_fastshoot", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "glitch_fastshoot", readline);			
							logMultiAD_Error(read);						
						} else {
							setGlitchStatus(GLITCH_FAST_SHOOT, (load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "glitch_crouchbug", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "glitch_crouchbug", readline);			
							logMultiAD_Error(read);						
						} else {
							setGlitchStatus(GLITCH_CROUCH_BUG, (load_data_int == 1 ? true : false));
						}
					} else if(!strcmp(read, "team_info_bars", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "team_info_bars", readline);			
							logMultiAD_Error(read);						
						} else {
							setTeamHealthInfoBarsStatus(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "max_ping", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(10 <= load_data_int <= 9999)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 10, 9999, FILE_LOG_SETTINGS, "max_ping", readline);			
							logMultiAD_Error(read);						
						} else {
							setMaxPingValue(load_data_int);
						}
					} else if(!strcmp(read, "min_fps", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 89)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 89, FILE_LOG_SETTINGS, "min_fps", readline);			
							logMultiAD_Error(read);						
						} else {
							setMinFPSValue(load_data_int);
						}		
					} else if(!strcmp(read, "max_ploss", true, index)) {
						if(sscanf(read[index + 1], "f", load_data_float) != 0 || !(1.0 <= load_data_float <= 99.0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 6);
							format(read, sizeof(read), read, 1.0, 99.0, FILE_LOG_SETTINGS, "max_ploss", readline);			
							logMultiAD_Error(read);						
						} else {
							setMaxPLossValue(load_data_float);
						}
					} else if(!strcmp(read, "rcon_login_info", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "rcon_login_info", readline);			
							logMultiAD_Error(read);						
						} else {
							g_RCON_LoginInfo = (load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "max_w_ping", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 99)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 99, FILE_LOG_SETTINGS, "max_w_ping", readline);			
							logMultiAD_Error(read);						
						} else {
							setProtectorMaxWarnings(PROTECTOR_CHECK_PING, load_data_int);
						}
					} else if(!strcmp(read, "max_w_fps", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 99)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 99, FILE_LOG_SETTINGS, "max_w_fps", readline);			
							logMultiAD_Error(read);						
						} else {
							setProtectorMaxWarnings(PROTECTOR_CHECK_FPS, load_data_int);
						}
					} else if(!strcmp(read, "max_w_ploss", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 99)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 99, FILE_LOG_SETTINGS, "max_w_ploss", readline);			
							logMultiAD_Error(read);						
						} else {
							setProtectorMaxWarnings(PROTECTOR_CHECK_PLOSS, load_data_int);
						}
					} else if(!strcmp(read, "protector_action", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(PROTECTOR_SEND_MESSAGE <= load_data_int <= PROTECTOR_KICK_PLAYER)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, PROTECTOR_SEND_MESSAGE, PROTECTOR_KICK_PLAYER, FILE_LOG_SETTINGS, "protector_action", readline);			
							logMultiAD_Error(read);						
						} else {
							setProtectorAction(load_data_int);
						}
					} else if(!strcmp(read, "protector_ref", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "protector_ref", readline);			
							logMultiAD_Error(read);						
						} else {
							setProtectionCheckReferees(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "fc_slot", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 5)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 5, FILE_LOG_SETTINGS, "fc_slot", readline);			
							logMultiAD_Error(read);						
						} else {
							setFreeChoiceMaxSlots(load_data_int);
						}
					} else if(!strcmp(read, "obj_info", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "obj_info", readline);			
							logMultiAD_Error(read);						
						} else {
							setDamageObjectInfoStatus(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "veh_tflag", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 3)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 3, FILE_LOG_SETTINGS, "veh_tflag", readline);			
							logMultiAD_Error(read);						
						} else {
							setVehicleTuningFlags(load_data_int);
						}
					} else if(!strcmp(read, "score_data", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(SCOREBOARD_FPS <= load_data_int <= SCOREBOARD_HEALTH)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, SCOREBOARD_FPS, SCOREBOARD_HEALTH, FILE_LOG_SETTINGS, "score_data", readline);			
							logMultiAD_Error(read);						
						} else {
							g_Setting_Scoreboard_Type = load_data_int;
						}
					} else if(!strcmp(read, "http_new_ver", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "http_new_ver", readline);			
							logMultiAD_Error(read);						
						} else {
							setAutomaticCheckingVersion(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "http_match_results", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "http_match_results", readline);			
							logMultiAD_Error(read);						
						} else {
							setSendMatchResultsStatus(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "http_sv_list", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "http_sv_list", readline);			
							logMultiAD_Error(read);						
						} else {
							setAddToServerListStatus(load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "death_info", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "death_info", readline);			
							logMultiAD_Error(read);						
						} else {
							g_DeathInfo_Chat = (load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "death_icon", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "death_icon", readline);			
							logMultiAD_Error(read);						
						} else {
							g_DeathInfo_Icons = (load_data_int == 1 ? true : false);
						}
					} else if(!strcmp(read, "c_add", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 7)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 7, FILE_LOG_SETTINGS, "c_add", readline);			
							logMultiAD_Error(read);						
						} else {
							addRoundCrashPauseStatus(0);
							addRoundCrashPauseStatus(load_data_int);
						}
					} else if(!strcmp(read, "ag_punish", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(AG_PUNISHMENT_HANDS_UP <= load_data_int <= AG_PUNISHMENT_FIRING_UP)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, AG_PUNISHMENT_HANDS_UP, AG_PUNISHMENT_FIRING_UP, FILE_LOG_SETTINGS, "ag_punish", readline);			
							logMultiAD_Error(read);						
						} else {
							setAGPunishment(load_data_int);
						}
					} else if(!strcmp(read, "gm_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(10 <= load_data_int <= 9999)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 10, 9999, FILE_LOG_SETTINGS, "gm_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setGunMenuTime(load_data_int);
						}
					} else if(!strcmp(read, "cp_size", true, index)) {
						if(sscanf(read[index + 1], "f", load_data_float) != 0 || !(1.0 <= load_data_float <= 10.0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 6);
							format(read, sizeof(read), read, 1.0, 10.0, FILE_LOG_SETTINGS, "cp_size", readline);			
							logMultiAD_Error(read);					
						} else {
							setCheckpointSize(load_data_float);
						}
					} else if(!strcmp(read, "sl_remove", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "sl_remove", readline);			
							logMultiAD_Error(read);						
						} else {
							setSelfRemoveStatus(load_data_int ? true : false);
						}							
					} else if(!strcmp(read, "cadd_exit_pause", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "cadd_exit_pause", readline);			
							logMultiAD_Error(read);						
						} else {
							setCrashAutoPauseStatus(load_data_int ? true : false);
						}							
					} else if(!strcmp(read, "cadd_auto_add", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "cadd_auto_add", readline);			
							logMultiAD_Error(read);						
						} else {
							setCrashAutoAddStatus(load_data_int ? true : false);
						}							
					} else if(!strcmp(read, "veh_fix", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "veh_fix", readline);			
							logMultiAD_Error(read);						
						} else {
							setSelfVehRepairStatus(load_data_int ? true : false);
						}							
					} else if(!strcmp(read, "veh_fix_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 600)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 600, FILE_LOG_SETTINGS, "veh_fix_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setSelfVehRepairMinTime(load_data_int);
						}							
					} else if(!strcmp(read, "arena_sp_time", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 120)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 120, FILE_LOG_SETTINGS, "arena_sp_time", readline);			
							logMultiAD_Error(read);						
						} else {
							setArenaSpawnProtectSettingTime(load_data_int);
						}							
					} else if(!strcmp(read, "arena_tdm_limit", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 999)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 999, FILE_LOG_SETTINGS, "arena_tdm_limit", readline);			
							logMultiAD_Error(read);						
						} else {
							setArenaTDMKillLimit(load_data_int);
						}
					} else if(!strcmp(read, "anti_macro", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "anti_macro", readline);			
							logMultiAD_Error(read);						
						} else {
							setGlitchStatus(GLITCH_ANTI_MACRO, (load_data_int ? true : false));
						}							
					} else if(!strcmp(read, "am_input_normal", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(7 <= load_data_int <= 13)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 7, 13, FILE_LOG_SETTINGS, "am_input_normal", readline);			
							logMultiAD_Error(read);						
						} else {
							setAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_INPUTS, load_data_int);
						}							
					} else if(!strcmp(read, "am_input_critical", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(14 <= load_data_int <= 99)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 14, 99, FILE_LOG_SETTINGS, "am_input_normal", readline);			
							logMultiAD_Error(read);						
						} else {
							setAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS, load_data_int);
						}							
					} else if(!strcmp(read, "am_warnings", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(1 <= load_data_int <= 10)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, 10, FILE_LOG_SETTINGS, "am_warnings", readline);			
							logMultiAD_Error(read);						
						} else {
							setAntiMacroValue(ANTI_MACRO_MAX_WARNINGS, load_data_int);
						}							
					} else if(!strcmp(read, "1on1_markers", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= 1)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 0, 1, FILE_LOG_SETTINGS, "1on1_markers", readline);			
							logMultiAD_Error(read);						
						} else {
							setOneOnOneMarkersStatus((load_data_int ? true : false));
						}							
					} else if(!strcmp(read, "t_1_col", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= _:COLOR_TYPES) || COLOR_TYPES:load_data_int == COLOR_TYPE_NON) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, _:COLOR_TYPES, FILE_LOG_SETTINGS, "t_1_col", readline);			
							logMultiAD_Error(read);						
						} else {
							setTeamColorType(TEAM_ONE, COLOR_TYPES:load_data_int);
						}							
					} else if(!strcmp(read, "t_2_col", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= _:COLOR_TYPES) || COLOR_TYPES:load_data_int == COLOR_TYPE_NON) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, _:COLOR_TYPES, FILE_LOG_SETTINGS, "t_2_col", readline);			
							logMultiAD_Error(read);						
						} else {
							setTeamColorType(TEAM_TWO, COLOR_TYPES:load_data_int);
						}							
					} else if(!strcmp(read, "t_3_col", true, index)) {
						if(sscanf(read[index + 1], "d", load_data_int) != 0 || !(0 <= load_data_int <= _:COLOR_TYPES) || COLOR_TYPES:load_data_int == COLOR_TYPE_NON) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
							format(read, sizeof(read), read, 1, _:COLOR_TYPES, FILE_LOG_SETTINGS, "t_3_col", readline);			
							logMultiAD_Error(read);						
						} else {
							setTeamColorType(TEAM_REF, COLOR_TYPES:load_data_int);
						}							
					}							
				}			
				
				readline ++;
			}		
			fclose(f_settings);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
saveSettingFile() {
	if(fexist(DIR_GENERAL)) {
		new File:f_settings = fopen(FILE_LOG_SETTINGS, io_write);
		new string[1024];
		format(string, sizeof(string), "\
			t1_skin=%d\r\n\
			t2_skin=%d\r\n\
			t3_skin=%d\r\n\
			weather=%d\r\n\
			w_time=%d\r\n\
			ntag_draw_dis=%.2f\r\n\
			gravity=%.4f\r\n\
			language=%d\r\n\
			time_arenas=%d\r\n\
			time_bases=%d\r\n\
			cp_capture=%d\r\n\
			cp_time=%d\r\n\
			weapon_select=%d\r\n\
			sp_time=%d\r\n\
			sp_type=%d\r\n\
			r_armour=%.1f\r\n\
			awin_mode=%d\r\n\
			swap_mode=%d\r\n\
			defbase_mode=%d\r\n\
			defbase_time=%d\r\n\
			fall_sync=%d\r\n\
			team_damage_bar=%d\r\n\
			l_veh=%d\r\n\
			l_int_veh=%d\r\n\
		",
			getTeamSkin(TEAM_ONE),
			getTeamSkin(TEAM_TWO),
			getTeamSkin(TEAM_REF),
			getServerWeather(),
			getServerWorldTime(),
			getServerNameTagDistance(),
			getServerGravity(),
			getDefaultLanguage(),
			getRoundTime(ROUND_TYPE_ARENA),
			getRoundTime(ROUND_TYPE_BASE),
			getCaptureModeFlag(),
			getCheckpointCaptureTime(),
			getWeaponSelectType(),
			getSpawnProtectSettingTime(),
			getSpawnProtectFlags(),
			getRoundArmour(),
			getArenaRoundWinMode(),
			getAutoSwapMode(),
			getDefendersBaseStatus(),
			getDefendersBaseBackTime(),
			syncInFall(),
			getTeamDamageBarInfoStatus(),
			getLobbyVehiclesStatus(),
			getInteriorLobbyVehiclesStatus()
		);
		
		format(string, sizeof(string), "%s\
			glitch_slidebug=%d\r\n\
			glitch_fastshoot=%d\r\n\
			glitch_crouchbug=%d\r\n\
			team_info_bars=%d\r\n\
			max_ping=%d\r\n\
			min_fps=%d\r\n\
			max_ploss=%.1f\r\n\
			max_w_ping=%d\r\n\
			max_w_fps=%d\r\n\
			max_w_ploss=%d\r\n\
			rcon_login_info=%d\r\n\
			protector_action=%d\r\n\
			protector_ref=%d\r\n\
			fc_slot=%d\r\n\
			obj_info=%d\r\n\
			veh_tflag=%d\r\n\
			score_data=%d\r\n\
			http_new_ver=%d\r\n\
			http_match_results=%d\r\n\
			http_sv_list=%d\r\n\
			death_info=%d\r\n\
			death_icon=%d\r\n\
			c_add=%d\r\n\
			ag_punish=%d\r\n\
		",
			string,
			getGlitchStatus(GLITCH_SLIDE_BUG),
			getGlitchStatus(GLITCH_FAST_SHOOT),
			getGlitchStatus(GLITCH_CROUCH_BUG),
			getTeamHealthInfoBarsStatus(),
			getMaxPingValue(),
			getMinFPSValue(),
			getMaxPLossValue(),
			getProtectorMaxWarnings(PROTECTOR_CHECK_PING),
			getProtectorMaxWarnings(PROTECTOR_CHECK_FPS),
			getProtectorMaxWarnings(PROTECTOR_CHECK_PLOSS),
			g_RCON_LoginInfo,
			getProtectorAction(),
			protectionCheckReferees(),
			getFreeChoiceMaxSlots(),
			getDamageObjectInfoStatus(),
			getVehicleTuningFlags(),
			g_Setting_Scoreboard_Type,
			getAutomaticCheckingVersion(),
			getSendMatchResultsStatus(),
			getAddToServerListStatus(),
			g_DeathInfo_Chat,
			g_DeathInfo_Icons,
			getRoundCrashPauseStatus(),
			getAGPunishment()			
		);
		
		format(string, sizeof(string), "%s\
			gm_time=%d\r\n\
			cp_size=%.1f\r\n\
			sl_remove=%d\r\n\
			cadd_exit_pause=%d\r\n\
			cadd_auto_add=%d\r\n\
			veh_fix=%d\r\n\
			veh_fix_time=%d\r\n\
			arena_sp_time=%d\r\n\
			arena_tdm_limit=%d\r\n\
			anti_macro=%d\r\n\
			am_input_normal=%d\r\n\
			am_input_critical=%d\r\n\
			am_warnings=%d\r\n\
			1on1_markers=%d\r\n\
			t_1_col=%d\r\n\
			t_2_col=%d\r\n\
			t_3_col=%d\
		",
			string,
			getGunMenuTime(),
			getCheckpointSize(),
			getSelfRemoveStatus(),
			getCrashAutoPauseStatus(),
			getCrashAutoAddStatus(),
			getSelfVehRepairStatus(),
			getSelfVehRepairMinTime(),
			getArenaSpawnProtectSettingTime(),
			getArenaTDMKillLimit(),
			getGlitchStatus(GLITCH_ANTI_MACRO),
			getAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_INPUTS),
			getAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS),
			getAntiMacroValue(ANTI_MACRO_MAX_WARNINGS),
			getOneOnOneMarkersStatus(),
			_:getTeamColorType(TEAM_ONE),
			_:getTeamColorType(TEAM_TWO),
			_:getTeamColorType(TEAM_REF)
		);
		
		fwrite(f_settings, string);
		fclose(f_settings);
		return 1;
	}
	return 0;
}