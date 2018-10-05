/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_AdminLvL[MAX_PLAYERS];
new g_Admin_Passwords[3][5];
new bool:g_Player_EyeStatus[MAX_PLAYERS];
new bool:g_Player_Eye_InvalidCMDs[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getPlayerEyeStatus(&playerid) return g_Player_EyeStatus[playerid];
setPlayerEyeStatus(&playerid, bool:enable) {
	g_Player_EyeStatus[playerid] = enable;
	return 1;
}
//------------------------------------------------------------------------------
getPlayerEyeInvCMDsStatus(&playerid) return g_Player_Eye_InvalidCMDs[playerid];
setPlayerEyeInvCMDsStatus(&playerid, bool:enable) {
	g_Player_Eye_InvalidCMDs[playerid] = enable;
	return 1;
}
//------------------------------------------------------------------------------
setPlayerAdminLevel(playerid, level) {
	if(ALVL_NON <= level <= ALVL_HEAD_ADMIN) {
		g_Player_AdminLvL[playerid] = level;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
IsAdminOrRCON(playerid, adminlvl) return ((IsPlayerAdmin(playerid) || g_Player_AdminLvL[playerid] >= adminlvl) ? 1 : 0);
//------------------------------------------------------------------------------
getPlayerAdminLevel(playerid) {
	return (IsPlayerAdmin(playerid) ? ALVL_HEAD_ADMIN : g_Player_AdminLvL[playerid]);
}
//------------------------------------------------------------------------------
getAdminNameByLevel(adminlevel, output[], size = sizeof(output)) {
	output[0] = EOS;
	switch(adminlevel) {
		case ALVL_JUNIOR_ADMIN:	strins(output, "J.Admin", 0, size);
		case ALVL_ADMIN: strins(output, "Admin", 0, size);
		case ALVL_HEAD_ADMIN: strins(output, "Head Admin", 0, size);
		default: strins(output, "NoN", 0, size);
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerScoreboardMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
		new clickedid;
		if(IsPlayerConnected((clickedid = GetPVarInt(playerid, PV_HELP_VAR_1)))) {
			new s_clicledid[8];
			valstr(s_clicledid, clickedid);
			switch(listitem) {
				case 0: cmd_spec(playerid, s_clicledid);
				case 1: cmd_aswap(playerid, s_clicledid);
				case 2: {
					if(getRoundState() == ROUND_STATE_REMAIN) {
						if(getPlayerStatus(clickedid) != PLAYER_STATUS_IN_ROUND) cmd_add(playerid, s_clicledid);
						else cmd_remove(playerid, s_clicledid);
					}
				}
				case 3: cmd_gunmenu(playerid, s_clicledid);
				case 4: cmd_restore(playerid, s_clicledid);
				case 5: {
					format(s_clicledid, sizeof(s_clicledid), "%d %s", clickedid, (!getPlayerAFKMode(playerid) ? ("on") : ("off")));
					cmd_setafk(playerid, s_clicledid);
				}
				case 6: cmd_representative(playerid, s_clicledid);
				case 7: {
					if(g_Player_MuteStatus[clickedid]) cmd_unmute(playerid, s_clicledid);
					else cmd_mute(playerid, s_clicledid);
				}
				case 8: cmd_kick(playerid, s_clicledid);
				default: {
					new string[256], caption[32];
					format(caption, sizeof(caption), COLOR_DIALOG_HEAD"%s", getPlayerName(clickedid));
					getDialogBodyMessage(string, DIALOG_BODY_SCOREBOARD_MENU, IsAdminOrRCON(playerid, ALVL_ADMIN) ? 1 : 0);
					ShowPlayerDialog(playerid, DIALOG_SCOREBOARD_MENU, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_EXIT));
				}
			}
			return 1;
		}
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerAdminPasswordMenu(&playerid, listitem = -1) {
	if(IsPlayerAdmin(playerid)) {
		switch(listitem) {
			case 0..3: {
				SetPVarInt(playerid, PV_HELP_VAR_4, listitem);
				showPlayerAdminPasswordSet(playerid);
			}
			default: {
				new string[128], passwords[3][22], caption[64];
				getSettingsCaptionMessage(caption, SCM_ADMIN_PASS, 0);			
				strunpack(passwords[0], g_Admin_Passwords[0]);
				strunpack(passwords[1], g_Admin_Passwords[1]);
				strunpack(passwords[2], g_Admin_Passwords[2]);
				
				getSettingsSettingBodyMessage(string, SBM_SETTING_ADMIN_PASSWORD_SET, 3);
				format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"J.Admin\t%s\n"COLOR_DIALOG_BODY"Admin\t%s\n"COLOR_DIALOG_BODY"Head Admin\t%s", string, passwords[0], passwords[1], passwords[2]);
				ShowPlayerDialog(playerid, DIALOG_ADMIN_PASSWORDS_MENU, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
			}
		}
	
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerAdminPasswordSet(&playerid, s_password[] = "") {
	if(IsPlayerAdmin(playerid)) {
		new string[240], info[84];
		if(!isnull(s_password)) {
			new length;
			if(3 <= (length = strlen(s_password)) <= 16) {
				for(-- length; length >= 0; length --) {
					if(!('A' <= s_password[length] <= 'Z' || 'a' <= s_password[length] <= 'z' || '0' <= s_password[length] <= '9')) {
						length = -2;
						break;
					}
				}
				if(length != -2) {
					new admin_lvl = GetPVarInt(playerid, PV_HELP_VAR_4);
					for(new i; i < 3; i ++) {
						if(g_Admin_Passwords[i][0] != EOS && strcmp(g_Admin_Passwords[i], s_password) == 0 && i != admin_lvl) {
							length = -3;
							break;
						}
					}					
					if(length != -3) {
						strpack(g_Admin_Passwords[admin_lvl], s_password);
						showPlayerAdminPasswordMenu(playerid);
						return 1;
					} else getSettingsSettingBodyMessage(info, SBM_SETTING_ADMIN_PASSWORD_SET, 2);			
				} else getSettingsSettingBodyMessage(info, SBM_SETTING_ADMIN_PASSWORD_SET, 1);
			} else getSettingsSettingBodyMessage(info, SBM_SETTING_ADMIN_PASSWORD_SET, 1);
		}
		
		getSettingsSettingBodyMessage(string, SBM_SETTING_ADMIN_PASSWORD_SET, 0);
		format(string, sizeof(string), string, info);
		getSettingsCaptionMessage(info, SCM_ADMIN_PASS, 0);	
		ShowPlayerDialog(playerid, DIALOG_ADMIN_PASSWORDS_SET, DIALOG_STYLE_INPUT, info, string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
saveAdminPassword() {
    if(fexist(DIR_GENERAL)) {
		new string[128], passwords[3][22];
		strunpack(passwords[0], g_Admin_Passwords[0]);
		strunpack(passwords[1], g_Admin_Passwords[1]);
		strunpack(passwords[2], g_Admin_Passwords[2]);		
        new File:f_open = fopen(FILE_ADMIN, io_write);
		format(string, sizeof(string), "j_admin=%s\r\n\
									admin=%s\r\n\
									h_admin=%s", 
			passwords[0],
			passwords[1],
			passwords[2]
		);
		fwrite(f_open, string);
		fclose(f_open);
	}
}
//------------------------------------------------------------------------------
loadAdminPasswords() {
	if(fexist(DIR_GENERAL)) {
	    new File:f_open;
	    new read[128];
	    if(!fexist(FILE_ADMIN)) {
			new admin_values[3];
            f_open = fopen(FILE_ADMIN, io_write);
			format(read, sizeof(read), "j_admin=%d\r\n\
										admin=%d\r\n\
										h_admin=%d", 
				(admin_values[0] = (random(9999999) + 1000)),
				(admin_values[1] = (random(9999999) + 1000)),
				(admin_values[2] = (random(9999999) + 1000))
			);
			fwrite(f_open, read);
			valstr(read, admin_values[0]), strpack(g_Admin_Passwords[0], read);
			valstr(read, admin_values[1]), strpack(g_Admin_Passwords[1], read);
			valstr(read, admin_values[2]), strpack(g_Admin_Passwords[2], read);
			
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);			
            printf(read, "Admin Passwords", FILE_ADMIN);
	    } else {
			new readline = 1, index, length;
			new error_in_password, i;
			f_open = fopen(FILE_ADMIN, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0)) && 16 >= (length = strlen(read[index + 1])) >= 3) {
					for(i = index + 1, error_in_password = false; i < length; i ++) {
						if(!('a' <= read[i] <= 'z' || 'A' <= read[i] <= 'Z' || '0' <= read[i] <= '9')) {
							error_in_password = true;
							break;
						}
					}		
					if(!error_in_password) {					
						if(!strcmp(read, "j_admin", true, index)) {
							strpack(g_Admin_Passwords[0], read[index + 1]);
						} else if(!strcmp(read, "admin", true, index)) {
							strpack(g_Admin_Passwords[1], read[index + 1]);
						} else if(!strcmp(read, "h_admin", true, index)) {
							strpack(g_Admin_Passwords[2], read[index + 1]);
						}	
					}
				}
				readline ++;
			}
			
			if(g_Admin_Passwords[0][0] == EOS) valstr(read, (random(9999999) + 1000)), strpack(g_Admin_Passwords[0], read);
			if(g_Admin_Passwords[1][0] == EOS) valstr(read, (random(9999999) + 1000)), strpack(g_Admin_Passwords[1], read);
			if(g_Admin_Passwords[2][0] == EOS) valstr(read, (random(9999999) + 1000)), strpack(g_Admin_Passwords[2], read);
			
		}
		fclose(f_open);
		return 1;
	}
	return 0;
}