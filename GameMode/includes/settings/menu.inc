/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define SETTINGS_MENU_SERVER					0
#define	SETTINGS_MENU_TEAM						1
#define SETTINGS_ROUND							2
#define SETTINGS_LOBBY							3
#define SETTINGS_PROTECTOR						4
#define SETTINGS_MENU_ANTYGLITCH				5
#define	SETTINGS_MENU_MESSAGES					6
#define SETTINGS_MENU_HTTP						7
#define SETTINGS_MENU_ADMIN_PASSWORDS			8
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showSettingsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[350];
		if(listitem == -1) {		
			new caption[32];
			getSettingsCaptionMessage(caption, SCM_START, 0);
			getSettingsBodyMessage(string, SBM_START, (IsPlayerAdmin(playerid) ? 2 : IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN) ? 1 : 0));
			ShowPlayerDialog(playerid, DIALOG_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));
		} else {
			SetPVarInt(playerid, PV_HELP_VAR_1, listitem);			
			sumbenuSettingsResponse(playerid);			
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
sumbenuSettingsResponse(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new submenuid = GetPVarInt(playerid, PV_HELP_VAR_1);
		new /*string[512], */caption[64];
		if(listitem == -1) {
			new yes[16], no[16];
			format(yes, sizeof(yes), "{00FF00}%s", oftenUsedPhrases(LANG_OUP_YES));	
			format(no, sizeof(no), "{FF0000}%s", oftenUsedPhrases(LANG_OUP_NO));
			
			switch(submenuid) {
				case SETTINGS_MENU_SERVER: {
					getSettingsCaptionMessage(caption, SCM_SERVER, 0);
					getSettingsBodyMessage(g_String_512, SBM_MENU_SERVER, 0);
					format(g_String_512, sizeof(g_String_512), g_String_512, getServerWeather(), getServerNameTagDistance(), getServerGravity(), getServerWorldTime(), (g_Server_LockedForConnections ? (yes) : (no)));
					ShowPlayerDialog(playerid, DIALOG_SETTINGS_SUBMENU, DIALOG_STYLE_TABLIST_HEADERS, caption, g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
					return 1;
				}
				case SETTINGS_MENU_TEAM: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerTeamSettingsFirstMenu(playerid);	
					return 1;
				}
				case SETTINGS_ROUND: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerRoundSettingsMenu(playerid);	
					return 1;				
				}
				case SETTINGS_LOBBY: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerLobbySettingMenu(playerid);
					return 1;
				}
				case SETTINGS_PROTECTOR: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerProtectorSettingMenu(playerid);
					return 1;
				}
				case SETTINGS_MENU_ANTYGLITCH: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerAGSettingMenu(playerid);
					return 1;
				}
				case SETTINGS_MENU_MESSAGES: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerMSGsSettingMenu(playerid);
					return 1;
				}		
				case SETTINGS_MENU_HTTP: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerHTTPSettingMenu(playerid);
					return 1;
				}							
				case SETTINGS_MENU_ADMIN_PASSWORDS: {
					SetPVarInt(playerid, PV_HELP_VAR_2, 1);
					showPlayerAdminPasswordMenu(playerid);	
					return 1;
				}
				default: return showSettingsMenu(playerid);
			}
		} else {
			switch(submenuid) {
				case SETTINGS_MENU_SERVER: {
					switch(listitem) {
						case 0: showPlayerValueDialogBack(playerid, DIALOG_VALUE_WEATHER);
						case 1: showPlayerFloatValueDialogBack(playerid, DIALOG_F_VALUE_NAMETAG_DIS);
						case 2: {
							if(getRoundState() == ROUND_STATE_LOBBY) showPlayerFloatValueDialogBack(playerid, DIALOG_F_VALUE_GRAVITY);
							else {
								getSettingsCaptionMessage(caption, SCM_SERVER, 0);
								showPlayerBackDialog(playerid, BACK_TO_SUBMENU_SETTINGS, caption, getSettingsErrorMessage(SETTINGS_ERROR_INROUND));
							}
						}
						case 3: showPlayerValueDialogBack(playerid, DIALOG_VALUE_WORLD_TIME);
						case 4: {
							if(g_Server_LockedForConnections) cmd_open(playerid);
							else cmd_lock(playerid);
							sumbenuSettingsResponse(playerid);
						}
						default: sumbenuSettingsResponse(playerid, submenuid);
					}
				}				
				default: sumbenuSettingsResponse(playerid);
			}
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerAGSettingMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[150];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_ANTYGLITCH, 0);
			getSettingsBodyMessage(string, SBM_MENU_ANTYGLITCH, 0);		
			format(string, sizeof(string), string, (getAGPunishment() == AG_PUNISHMENT_HANDS_UP ? ("Hands Up") : ("Fired Up")), getGlitchStatus(GLITCH_SLIDE_BUG) ? (C_LIGHTGREEN) : (C_KICK), getGlitchStatus(GLITCH_FAST_SHOOT) ? (C_LIGHTGREEN) : (C_KICK), getGlitchStatus(GLITCH_CROUCH_BUG) ? (C_LIGHTGREEN) : (C_KICK)/*, getGlitchStatus(GLITCH_ANTI_MACRO) ? (C_LIGHTGREEN) : (C_KICK)*/);
			ShowPlayerDialog(playerid, DIALOG_ANTYGLITCH_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(GetPVarInt(playerid, PV_HELP_VAR_2) == 1 ? (LANG_OUP_BACK) : (LANG_OUP_EXIT)));
		} else {
			switch(listitem) {
				case 0: {
					showPlayerAntyMacroMenu(playerid);
					return 1;
				}
				case 1: {
					showPlayerAGPunishmentMenu(playerid);
					return 1;
				}
				case 2: {
					setGlitchStatus(GLITCH_SLIDE_BUG, !getGlitchStatus(GLITCH_SLIDE_BUG));
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getGlitchStatus(GLITCH_SLIDE_BUG) ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "AG: Slide Bug");
				}
				case 3: {
					setGlitchStatus(GLITCH_FAST_SHOOT, !getGlitchStatus(GLITCH_FAST_SHOOT));
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getGlitchStatus(GLITCH_FAST_SHOOT) ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "AG: Fast Shoot");
				}
				case 4: {
					setGlitchStatus(GLITCH_CROUCH_BUG, !getGlitchStatus(GLITCH_CROUCH_BUG));
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getGlitchStatus(GLITCH_CROUCH_BUG) ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "AG: C-Bug");
				}
				default: return showPlayerAGSettingMenu(playerid);
			}
			SendClientMessageToAll(COLOR_INFO_1, string);
			c_print(string);			
			showPlayerAGSettingMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerAGPunishmentMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		switch(listitem) {
			case 0..1: {
				setAGPunishment(listitem);
				showPlayerAGSettingMenu(playerid);
			}
			default: {
				new caption[64];
				getSettingsCaptionMessage(caption, SCM_ANTYGLITCH, 0);
				getSettingsBodyMessage(g_Chat_String, SBM_MENU_ANTYGLITCH, 1);						
				ShowPlayerDialog(playerid, DIALOG_ANTYGLITCH_PUNISHMENT_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, g_Chat_String, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));	
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerAntyMacroMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		switch(listitem) {
			case 0: { 
				setGlitchStatus(GLITCH_ANTI_MACRO, !getGlitchStatus(GLITCH_ANTI_MACRO));
				getChatMessage(g_Chat_String, CHAT_MESSAGE_ROUND_SETTING_INFO, (getGlitchStatus(GLITCH_ANTI_MACRO) ? 1 : 0));
				format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), "AG: Anti Macro - Status");
				SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				c_print(g_Chat_String);			
				showPlayerAntyMacroMenu(playerid);				
			}			
			case 1: showPlayerValueDialogBack(playerid, DIALOG_VALUE_AMACRO_MAX_CLICKS);
			case 2: showPlayerValueDialogBack(playerid, DIALOG_VALUE_AMACRO_MAX_CRITICAL_CLICKS);
			case 3: showPlayerValueDialogBack(playerid, DIALOG_VALUE_AMACRO_MAX_WARNINGS);
			default: {
				new caption[64];
				new string[200];
				getSettingsCaptionMessage(caption, SCM_ANTYMACRO, 0);
				getSettingsBodyMessage(string, SBM_MENU_ANTYGLITCH, 2);	
				format(string, sizeof(string), string, 
					getGlitchStatus(GLITCH_ANTI_MACRO) ? (C_LIGHTGREEN) : (C_KICK),
					getAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_INPUTS),
					getAntiMacroValue(ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS), 
					getAntiMacroValue(ANTI_MACRO_MAX_WARNINGS)
				);
				ShowPlayerDialog(playerid, DIALOG_ANTYGLITCH_ANTYMACRO_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));	
			}
		}
		return 1;
	}
	return 0;	
}
//------------------------------------------------------------------------------
showPlayerMSGsSettingMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[350];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_INFO_MSGS, 0);
			getSettingsBodyMessage(string, SBM_MENU_MSGS, 0);		
			format(string, sizeof(string), string, g_ConDis_Info ? (C_LIGHTGREEN) : (C_KICK), g_ConDis_ShowIP ? (C_LIGHTGREEN) : (C_KICK), getTeamDamageBarInfoStatus() ? (C_LIGHTGREEN) : (C_KICK), getTeamHealthInfoBarsStatus() ? (C_LIGHTGREEN) : (C_KICK), getDamageObjectInfoStatus() ? (C_LIGHTGREEN) : (C_KICK), g_DeathInfo_Chat ? (C_LIGHTGREEN) : (C_KICK), g_DeathInfo_Icons ? (C_LIGHTGREEN) : (C_KICK), (g_Setting_Scoreboard_Type == SCOREBOARD_HEALTH ? ("Health") : ("FPS")));
			ShowPlayerDialog(playerid, DIALOG_MESSAGES_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(GetPVarInt(playerid, PV_HELP_VAR_2) == 1 ? (LANG_OUP_BACK) : (LANG_OUP_EXIT)));	
		} else {
			switch(listitem) {
				case 0: {
					g_ConDis_Info = !g_ConDis_Info;
					setGlitchStatus(GLITCH_CROUCH_BUG, !getGlitchStatus(GLITCH_CROUCH_BUG));
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_ConDis_Info ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Wiadomosci o polaczeniach");
				}
				case 1: {
					g_ConDis_ShowIP = !g_ConDis_ShowIP;
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_ConDis_ShowIP ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Wiadomosci o polaczeniach (IP)");
				}
				case 2: {
					setTeamDamageBarStatus(!getTeamDamageBarInfoStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getTeamDamageBarInfoStatus() ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Info. o obrazeniach druzyny");
				}
				case 3: {
					setTeamHealthInfoBarsStatus(!getTeamHealthInfoBarsStatus());
					if(getRoundState() == ROUND_STATE_REMAIN) {
						if(!getTeamHealthInfoBarsStatus()) hideTeamHealthInfoForAll();			
						else showTeamHealthInfoForAll();			
					}
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getTeamHealthInfoBarsStatus() ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Info. o zdrowiu druzyny");					
				}
				case 4: {
					setDamageObjectInfoStatus(!getDamageObjectInfoStatus());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (getDamageObjectInfoStatus() ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Object Damage Info");					
				}
				case 5: {
					g_DeathInfo_Chat = (!g_DeathInfo_Chat);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_DeathInfo_Chat ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Death Chat Info");					
				}
				case 6: {
					g_DeathInfo_Icons = (!g_DeathInfo_Icons);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_DeathInfo_Icons ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Death Icons");					
				}	
				case 7: {
					g_Setting_Scoreboard_Type = (g_Setting_Scoreboard_Type == SCOREBOARD_FPS ? SCOREBOARD_HEALTH : SCOREBOARD_FPS);
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 4);
					format(string, sizeof(string), string, getPlayerName(playerid), "Scoreboard Data", g_Setting_Scoreboard_Type == SCOREBOARD_HEALTH ? ("Health") : ("FPS"));						
				}				
				default: return showPlayerMSGsSettingMenu(playerid);
			}
			SendClientMessageToAll(COLOR_INFO_1, string);
			c_print(string);			
			showPlayerMSGsSettingMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerHTTPSettingMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[270];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_MENU_HTTP, 0);
			getSettingsBodyMessage(string, SBM_MENU_HTTP, 0);		
			format(string, sizeof(string), string, getAutomaticCheckingVersion() ? (C_LIGHTGREEN) : (C_KICK), getSendMatchResultsStatus() ? (C_LIGHTGREEN) : (C_KICK), getAddToServerListStatus() ? (C_LIGHTGREEN) : (C_KICK));
			ShowPlayerDialog(playerid, DIALOG_HTTP_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(GetPVarInt(playerid, PV_HELP_VAR_2) == 1 ? (LANG_OUP_BACK) : (LANG_OUP_EXIT)));
		} else {
			switch(listitem) {
				case 0: {
					setAutomaticCheckingVersion(!getAutomaticCheckingVersion());
					sendCheckVersion(INVALID_PLAYER_ID);
				}
				case 1: setSendMatchResultsStatus(!getSendMatchResultsStatus());
				case 2: {
					setAddToServerListStatus(!getAddToServerListStatus());		
					sendServerInfo();
				}
				default: return showPlayerHTTPSettingMenu(playerid);
			}		
			showPlayerHTTPSettingMenu(playerid);
		}
		return 1;
	}
	return 0;
}