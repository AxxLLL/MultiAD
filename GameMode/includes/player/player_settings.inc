/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
savePlayerSettings(&playerid) {
	if(fexist(DIR_PLAYERS)) {
		new buffer[128], File:f_settings;
		GetPlayerName(playerid, buffer, MAX_PLAYER_NAME);
		format(buffer, sizeof(buffer), DIR_PLAYERS"/%s.ini", buffer);
		f_settings = fopen(buffer, io_write);
		format(buffer, sizeof(buffer), "\
			priv_msg=%d\r\n\
			hited_info=%d\r\n\
			hit_info=%d\r\n\
			pause_onkey=%d\r\n\
			eye_status=%d\r\n\
			eye_invalid=%d\r\n\
			spec_list=%d\
		",
			g_Player_PMLockStatus[playerid],
			getPlayerAimedInfoStatus(playerid),
			getPlayerDamageInfoStatus(playerid),
			getPlayerKeyPauseStatus(playerid),
			getPlayerEyeStatus(playerid),
			getPlayerEyeInvCMDsStatus(playerid),
			getPlayerSpecListStatus(playerid)
		);
		fwrite(f_settings, buffer);
		fclose(f_settings);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
loadPlayerSettings(&playerid) {
	if(fexist(DIR_PLAYERS)) {
		new buffer[128];
		GetPlayerName(playerid, buffer, MAX_PLAYER_NAME);
		format(buffer, sizeof(buffer), DIR_PLAYERS"/%s.ini", buffer);
		if(fexist(buffer)) {
			new File:f_settings = fopen(buffer, io_read);	
			new length, index;
			while(fread(f_settings, buffer, sizeof(buffer))) {
				DeleteNewLine(buffer);
				DeleteSpaces(buffer);
				
				if(!isnull(buffer) && (((length = (strlen(buffer) - 1)) > (index = strfind(buffer, ":")) > 0) || (length > (index = strfind(buffer, "=")) > 0))) {
					
					if(!strcmp(buffer, "priv_msg", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							g_Player_PMLockStatus[playerid] = (buffer[index + 1] == '0' ? false : true);
						}
					} else if(!strcmp(buffer, "hited_info", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerAimedInfoStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					} else if(!strcmp(buffer, "hit_info", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerDamageInfoStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					} else if(!strcmp(buffer, "pause_onkey", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerKeyPauseStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					} else if(!strcmp(buffer, "eye_status", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerEyeStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					} else if(!strcmp(buffer, "eye_invalid", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerEyeInvCMDsStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					} else if(!strcmp(buffer, "spec_list", true, index)) {
						if('0' <= buffer[index + 1] <= '1') {
							setPlayerSpecListStatus(playerid, (buffer[index + 1] == '0' ? false : true));
						}
					}					
				}
				
			}	
			fclose(f_settings);	
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerSettingsMenu(&playerid, listitem = -1) {
	if(listitem == -1) {
		new string[300];

		getDialogBodyMessage(string, DIALOG_BODY_PLAYER_SETTINGS, IsAdminOrRCON(playerid, ALVL_ADMIN) ? 2 : IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN) ? 1 : 0);		
		
		format(string, sizeof(string), string, 
			((!g_Player_PMLockStatus[playerid]) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerAFKMode(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerAimedInfoStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerDamageInfoStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerSpecListStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerKeyPauseStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerEyeStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK)),
			((getPlayerEyeInvCMDsStatus(playerid)) ? (C_LIGHTGREEN) : (C_KICK))
		);						
		
		ShowPlayerDialog(playerid, DIALOG_PLAYER_SETTINGS, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_PLAYER_SETTINGS), string, oftenUsedPhrases(LANG_OUP_CHANGE, 0), oftenUsedPhrases(LANG_OUP_EXIT, 0));
	} else {
		switch(listitem) {
			case 0: cmd_lockpm(playerid);
			case 1: cmd_afk(playerid);
			case 2: cmd_aiminfo(playerid);
			case 3: cmd_dmginfo(playerid);
			case 4: cmd_speclist(playerid);
			case 5: cmd_kpause(playerid);
			case 6: cmd_eyeinfo(playerid);
			case 7: {
				setPlayerEyeInvCMDsStatus(playerid, !getPlayerEyeInvCMDsStatus(playerid));
			}
		}
		showPlayerSettingsMenu(playerid);
	}
	return 1;
}