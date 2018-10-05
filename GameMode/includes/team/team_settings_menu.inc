/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerTeamSettingsFirstMenu(playerid, response_teamid = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(response_teamid == -1) {
			new string[135], colors[3][12];
			getTeamColorText(TEAM_ONE, COLOR_STATUS_ACTIVE, colors[TEAM_ONE]);
			getTeamColorText(TEAM_TWO, COLOR_STATUS_ACTIVE, colors[TEAM_TWO]);
			getTeamColorText(TEAM_REF, COLOR_STATUS_ACTIVE, colors[TEAM_REF]);
			getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 1);
			format(string, sizeof(string), string, colors[TEAM_ONE], getTeamName(TEAM_ONE), colors[TEAM_TWO], getTeamName(TEAM_TWO), colors[TEAM_REF], getTeamName(TEAM_REF));
			ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_1, DIALOG_STYLE_TABLIST_HEADERS, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases((GetPVarInt(playerid, PV_HELP_VAR_2) == 0 ? LANG_OUP_EXIT : LANG_OUP_BACK)));
		} else {
			SetPVarInt(playerid, PV_HELP_VAR_3, response_teamid);
			showPlayerTeamSettingsSetMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerTeamSettingsSetMenu(playerid, response_settingid = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		switch(response_settingid) {
			case 0: setTeamNewName(playerid);
			case 1: setTeamNewSkin(playerid);
			case 2: setTeamNewPassword(playerid);
			case 3: setTeamNewColor(playerid);
			default: {
				new string[160], color[12];
				new teamid = GetPVarInt(playerid, PV_HELP_VAR_3);
				getTeamColorText(teamid, COLOR_STATUS_ACTIVE, color);
				getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 2);
				format(string, sizeof(string), string, getTeamName(teamid), getTeamSkin(teamid), getTeamPassword(teamid), color);
				ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_2, DIALOG_STYLE_TABLIST_HEADERS, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));			
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setTeamNewSkin(playerid, response_skinid[] = "") {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {		
		if(getRoundState() != ROUND_STATE_LOBBY) showPlayerBackDialog(playerid, BACK_TEAM_SETTINGS, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), getSettingsErrorMessage(SETTINGS_ERROR_INROUND));		
		else {			
			new string[128], error[80];
			if(!isnull(response_skinid)) {
				if(0 < strlen(response_skinid) <= 3 && '0' <= response_skinid[0] <= '9') {	
					new skinid, teamid;
					if(setTeamSkin((teamid = GetPVarInt(playerid, PV_HELP_VAR_3)), (skinid = strval(response_skinid)))) {
						getChatCMDMessage(string, CHAT_CMD_MESSAGE_TEAM_SKIN, 1);
						format(string, sizeof(string), string, getPlayerName(playerid), getTeamName(teamid), skinid);
						SendClientMessageToAll(COLOR_INFO_1, string);
						c_print(string);							
						showPlayerTeamSettingsSetMenu(playerid);
						return 1;
					} 
				}  
				getDialogBodyMessage(error, DIALOG_BODY_TEAM_SETTINGS, 4);
			}		
			getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 3);
			format(string, sizeof(string), string, error);
			ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_SKIN, DIALOG_STYLE_INPUT, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setTeamNewName(playerid, response_name[] = "") {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(getRoundState() != ROUND_STATE_LOBBY) showPlayerBackDialog(playerid, BACK_TEAM_SETTINGS, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), getSettingsErrorMessage(SETTINGS_ERROR_INROUND));		
		else if(getMatchStatus()) showPlayerBackDialog(playerid, BACK_TEAM_SETTINGS, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), getSettingsErrorMessage(SETTINGS_ERROR_INMATCH));	
		else {
			new string[128], error[80];
			if(!isnull(response_name)) {	
				new teamid, old_teamname[16];
				strins(old_teamname, getTeamName((teamid = GetPVarInt(playerid, PV_HELP_VAR_3))), 0);
				if(setTeamName(teamid, response_name)) {	
		            getChatCMDMessage(string, CHAT_CMD_MESSAGE_TEAM_NAME, 1);
					format(string, sizeof(string), string, getPlayerName(playerid), old_teamname, response_name);
				    SendClientMessageToAll(COLOR_INFO_1, string);
				    c_print(string);							
					showPlayerTeamSettingsSetMenu(playerid);
					return 1;
				} else getDialogBodyMessage(error, DIALOG_BODY_TEAM_SETTINGS, 6);
			}		
			getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 5);
			format(string, sizeof(string), string, error);
			ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_NAME, DIALOG_STYLE_INPUT, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
setTeamNewPassword(playerid, response_password[] = "") {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[128], error[80];
		if(!isnull(response_password)) {	
			new teamid;
			if(1 <= strlen(response_password) <= 4 && '0' <= response_password[0] <= '9' && setTeamPassword((teamid = GetPVarInt(playerid, PV_HELP_VAR_3)), strval(response_password))) {	
				getChatCMDMessage(string, CHAT_CMD_MESSAGE_TEAM_PASSWORD, (strval(response_password) != 0 ? 1 : 2));
				format(string, sizeof(string), string, getPlayerName(playerid), getTeamName(teamid));
				SendClientMessageToAll(COLOR_INFO_1, string);
				c_print(string);						
				showPlayerTeamSettingsSetMenu(playerid);
				return 1;
			}
			getDialogBodyMessage(error, DIALOG_BODY_TEAM_SETTINGS, 8);
		}		
		getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 7);
		format(string, sizeof(string), string, error);
		ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_PASSWORD, DIALOG_STYLE_INPUT, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), string, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setTeamNewColor(playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if((_:COLOR_TYPES - 1) > listitem >= 0) {
			new teamid = GetPVarInt(playerid, PV_HELP_VAR_3), useid, color[12];
			if((useid = isTeamColorTypeInUse(COLOR_TYPES:(listitem + 1))) != TEAM_NON) {
				if(useid != teamid) {
					SetPVarInt(playerid, PV_HELP_VAR_4, useid);
					swapTeamColors(playerid);
					return 1;
				} else {
					showPlayerTeamSettingsSetMenu(playerid);
					return 1;
				}
			}
			setTeamColorType(teamid, COLOR_TYPES:(listitem + 1));
			showPlayerTeamSettingsSetMenu(playerid);
			
			getTeamColorText(teamid, COLOR_STATUS_ACTIVE, color);
			getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_COLOR, 1);		
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(teamid), color);
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
		} else {
			g_String_512[0] = EOS;
			for(new COLOR_TYPES:i, string[128], color_active[12], color_non_active[12], color_afk[12]; i < COLOR_TYPES; i ++) {
				if(i != COLOR_TYPE_NON) {
					getDialogBodyMessage(string, DIALOG_BODY_TEAM_SETTINGS, 9);
					
					getColorText(i, COLOR_STATUS_ACTIVE, color_active);
					getColorText(i, COLOR_STATUS_INACTIVE, color_non_active);
					getColorText(i, COLOR_STATUS_DEATH, color_afk);
					
					format(string, sizeof(string), string, color_active, color_non_active, color_afk);
					format(g_String_512, sizeof(g_String_512), "%s\n%s", g_String_512, string);
				}
			}
			ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_COLOR, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), g_String_512, oftenUsedPhrases(LANG_OUP_SET), oftenUsedPhrases(LANG_OUP_BACK));
		}		
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
swapTeamColors(playerid, bool:confirm = false) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(!confirm) {
			getDialogBodyMessage(g_Chat_String, DIALOG_BODY_TEAM_SETTINGS, 10);			
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getTeamName(GetPVarInt(playerid, PV_HELP_VAR_4)));
			ShowPlayerDialog(playerid, DIALOG_TEAM_SETTINGS_COLOR_SWAP, DIALOG_STYLE_MSGBOX, getDialogCaptionMessage(DIALOG_CAPTION_TEAM_SETTINGS), g_Chat_String, oftenUsedPhrases(LANG_OUP_YES), oftenUsedPhrases(LANG_OUP_NO));
		} else {
			new team_1 = GetPVarInt(playerid, PV_HELP_VAR_3),
				team_2 = GetPVarInt(playerid, PV_HELP_VAR_4),
				COLOR_TYPES:color_team_1 = getTeamColorType(team_1);
				
			setTeamColorType(team_1, getTeamColorType(team_2), true);
			setTeamColorType(team_2, color_team_1, true);
			
			showPlayerTeamSettingsSetMenu(playerid);
			
			getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_COLOR, 2);		
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(team_1), getTeamName(team_2));
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			return 1;
		}
	}
	return 0;
}