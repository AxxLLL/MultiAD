/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerHelpMenu(&playerid, listitem = -1) {
	switch(listitem) {
		case 0: {
			new string[256];
			helpMenuBody(string, HELP_BODY_START, 1);	
			showPlayerBackDialog(playerid, BACK_HELP_MENU, helpMenuCaption(HELP_CAPTION_ABOUT), string);
		}
		case 1: {
			showPlayerCMDsFirstMenu(playerid);
		}
		case 2: cmd_roundsettings(playerid, "-57");
		default: {
			new string[128];
			helpMenuBody(string, HELP_BODY_START, 0);	
			ShowPlayerDialog(playerid, DIALOG_HELP, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_START), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));		
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
showPlayerCMDsFirstMenu(playerid, listitem = -1) {
	SetPVarInt(playerid, PV_HELP_VAR_1, listitem);
	if(4 >= listitem >= 0) showPlayerCMDsList(playerid);
	else {
		new string[128];
		format(string, sizeof(string), "%s\n%s", helpMenuCaption(HELP_CAPTION_KEYOBARD_SHORTCUTS), helpMenuCaption(HELP_CAPTION_CMDS_PLAYER));
		if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
			format(string, sizeof(string), "%s\n%s", string, helpMenuCaption(HELP_CAPTION_CMDS_J_ADMIN));
			if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
				format(string, sizeof(string), "%s\n%s", string, helpMenuCaption(HELP_CAPTION_CMDS_ADMIN));
				if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
					format(string, sizeof(string), "%s\n%s", string, helpMenuCaption(HELP_CAPTION_CMDS_HEAD_ADMIN));		
				}
			}
		}
		ShowPlayerDialog(playerid, DIALOG_HELP_CMDS, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_CMDS), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));	
	}
	return 1;
}
//------------------------------------------------------------------------------
showPlayerCMDsList(playerid, listitem = -1) {
	new caption[32];
	switch(GetPVarInt(playerid, PV_HELP_VAR_1)) {
		case 0: {
			switch(listitem) {
				default: {
					helpMenuBody(g_String_512, HELP_BODY_CMDS, 4);
					ShowPlayerDialog(playerid, DIALOG_HELP_CMDS_LIST, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_KEYOBARD_SHORTCUTS), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
					return 1;					
				}
			}
			showPlayerBackDialog(playerid, BACK_HELP_MENU_CMDS_LIST, caption, g_String_512);
			return 1;
		}	
		case 1: {		
			switch(listitem) {
				case 0: {
					strins(caption, COLOR_DIALOG_HEAD"/me", 0);
				}
				case 1: {
					strins(caption, COLOR_DIALOG_HEAD"/car", 0);
				}	
				case 2: {
					strins(caption, COLOR_DIALOG_HEAD"/switch", 0);
				}	
				case 3: {
					strins(caption, COLOR_DIALOG_HEAD"/gun", 0);
				}	
				case 4: {
					strins(caption, COLOR_DIALOG_HEAD"/afk", 0);
				}	
				case 5: {
					strins(caption, COLOR_DIALOG_HEAD"/sync", 0);
				}	
				case 6: {
					strins(caption, COLOR_DIALOG_HEAD"/pm", 0);
				}	
				case 7: {
					strins(caption, COLOR_DIALOG_HEAD"/lastround", 0);
				}	
				case 8: {
					strins(caption, COLOR_DIALOG_HEAD"/lastmatch", 0);
				}	
				case 9: {
					strins(caption, COLOR_DIALOG_HEAD"/replist", 0);
				}	
				case 10: {
					strins(caption, COLOR_DIALOG_HEAD"/admins", 0);
				}	
				case 11: {
					strins(caption, COLOR_DIALOG_HEAD"/kill", 0);
				}	
				case 12: {
					strins(caption, COLOR_DIALOG_HEAD"/rounds", 0);
				}	
				case 13: {
					strins(caption, COLOR_DIALOG_HEAD"/tdm", 0);
				}	
				case 14: {
					strins(caption, COLOR_DIALOG_HEAD"/spec", 0);
				}	
				case 15: {
					strins(caption, COLOR_DIALOG_HEAD"/specoff", 0);
				}		
				case 16: {
					strins(caption, COLOR_DIALOG_HEAD"/lockpm", 0);
				}	
				case 17: {
					strins(caption, COLOR_DIALOG_HEAD"/aiminfo", 0);
				}	
				case 18: {
					strins(caption, COLOR_DIALOG_HEAD"/dmginfo", 0);
				}	
				case 19: {
					strins(caption, COLOR_DIALOG_HEAD"/roundsettings", 0);
				}	
				case 20: {
					strins(caption, COLOR_DIALOG_HEAD"/help", 0);
				}	
				case 21: {
					strins(caption, COLOR_DIALOG_HEAD"/alog", 0);
				}	
				case 22: {
					strins(caption, COLOR_DIALOG_HEAD"/hide", 0);					
				}	
				case 23: {
					strins(caption, COLOR_DIALOG_HEAD"/remove", 0);					
				}						
				case 24: {
					strins(caption, COLOR_DIALOG_HEAD"/fixvehicle", 0);					
				}		
				case 25: {
					strins(caption, COLOR_DIALOG_HEAD"/mynetcheck", 0);					
				}				
				default: {
					helpMenuBody(g_String_512, HELP_BODY_CMDS, 0);
					ShowPlayerDialog(playerid, DIALOG_HELP_CMDS_LIST, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_CMDS_PLAYER), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
					return 1;					
				}
			}
			helpMenuBody(g_String_512, HELP_CMDS_LIST_PLAYER, listitem);
			showPlayerBackDialog(playerid, BACK_HELP_MENU_CMDS_LIST, caption, g_String_512);
			return 1;
		}
		case 2: {
			if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
				switch(listitem) {
					case 0: {
						strins(caption, COLOR_DIALOG_HEAD"/aswap", 0);
					}
					case 1: {
						strins(caption, COLOR_DIALOG_HEAD"/swap", 0);
					}	
					case 2: {
						strins(caption, COLOR_DIALOG_HEAD"/sa", 0);
					}	
					case 3: {
						strins(caption, COLOR_DIALOG_HEAD"/sb", 0);
					}	
					case 4: {
						strins(caption, COLOR_DIALOG_HEAD"/end", 0);
					}	
					case 5: {
						strins(caption, COLOR_DIALOG_HEAD"/gunmenu", 0);
					}	
					case 6: {
						strins(caption, COLOR_DIALOG_HEAD"/add", 0);
					}	
					case 7: {
						strins(caption, COLOR_DIALOG_HEAD"/remove", 0);
					}	
					case 8: {
						strins(caption, COLOR_DIALOG_HEAD"/pause", 0);
					}	
					case 9: {
						strins(caption, COLOR_DIALOG_HEAD"/chat", 0);
					}	
					case 10: {
						strins(caption, COLOR_DIALOG_HEAD"/representative", 0);
					}	
					case 11: {
						strins(caption, COLOR_DIALOG_HEAD"/coin", 0);
					}	
					case 12: {
						strins(caption, COLOR_DIALOG_HEAD"/heal", 0);
					}	
					case 13: {
						strins(caption, COLOR_DIALOG_HEAD"/armour", 0);
					}	
					case 14: {
						strins(caption, COLOR_DIALOG_HEAD"/rarmour", 0);
					}	
					case 15: {
						strins(caption, COLOR_DIALOG_HEAD"/restore", 0);
					}		
					case 16: {
						strins(caption, COLOR_DIALOG_HEAD"/setafk", 0);
					}	
					case 17: {
						strins(caption, COLOR_DIALOG_HEAD"/players", 0);
					}	
					case 18: {
						strins(caption, COLOR_DIALOG_HEAD"/chckver", 0);
					}	
					case 19: {
						strins(caption, COLOR_DIALOG_HEAD"/cadd", 0);						
					}	
					case 20: {
						strins(caption, COLOR_DIALOG_HEAD"/kpause", 0);						
					}	
					case 21: {
						strins(caption, COLOR_DIALOG_HEAD"/labo", 0);						
					}		
					case 22: {
						strins(caption, COLOR_DIALOG_HEAD"/sethp", 0);						
					}			
					case 23: {
						strins(caption, COLOR_DIALOG_HEAD"/setarmour", 0);						
					}					
					default: {
						helpMenuBody(g_String_512, HELP_BODY_CMDS, 1);
						ShowPlayerDialog(playerid, DIALOG_HELP_CMDS_LIST, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_CMDS_J_ADMIN), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
						return 1;
					}
				}		
				helpMenuBody(g_String_512, HELP_CMDS_LIST_J_ADMIN, listitem);
				showPlayerBackDialog(playerid, BACK_HELP_MENU_CMDS_LIST, caption, g_String_512);				
				return 1;
			}
		}	
		case 3: {
			if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
				switch(listitem) {
					case 0: {
						strins(caption, COLOR_DIALOG_HEAD"/startmatch", 0);
					}
					case 1: {
						strins(caption, COLOR_DIALOG_HEAD"/stopmatch", 0);
					}	
					case 2: {
						strins(caption, COLOR_DIALOG_HEAD"/resetpoints", 0);
					}	
					case 3: {
						strins(caption, COLOR_DIALOG_HEAD"/kick", 0);
					}	
					case 4: {
						strins(caption, COLOR_DIALOG_HEAD"/unbanip", 0);
					}	
					case 5: {
						strins(caption, COLOR_DIALOG_HEAD"/tp", 0);
					}	
					case 6: {
						strins(caption, COLOR_DIALOG_HEAD"/tpto", 0);
					}	
					case 7: {
						strins(caption, COLOR_DIALOG_HEAD"/tphere", 0);
					}	
					case 8: {
						strins(caption, COLOR_DIALOG_HEAD"/lock", 0);
					}	
					case 9: {
						strins(caption, COLOR_DIALOG_HEAD"/open", 0);
					}	
					case 10: {
						strins(caption, COLOR_DIALOG_HEAD"/mute", 0);
					}	
					case 11: {
						strins(caption, COLOR_DIALOG_HEAD"/unmute", 0);
					}				
					case 12: {
						strins(caption, COLOR_DIALOG_HEAD"/mrounds", 0);
					}				
					case 13: {
						strins(caption, COLOR_DIALOG_HEAD"/eyeinfo", 0);
					}		
					case 14: {
						strins(caption, COLOR_DIALOG_HEAD"/destroyvehicle", 0);
					}	
					case 15: {
						strins(caption, COLOR_DIALOG_HEAD"/fixvehicle", 0);
					}
					case 16: {
						strins(caption, COLOR_DIALOG_HEAD"/netcheck", 0);					
					}	
					case 17: {
						strins(caption, COLOR_DIALOG_HEAD"/restorematch", 0);					
					}					
					default: {
						helpMenuBody(g_String_512, HELP_BODY_CMDS, 2);
						ShowPlayerDialog(playerid, DIALOG_HELP_CMDS_LIST, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_CMDS_ADMIN), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
						return 1;							
					}
				}
				helpMenuBody(g_String_512, HELP_CMDS_LIST_ADMIN, listitem);
				showPlayerBackDialog(playerid, BACK_HELP_MENU_CMDS_LIST, caption, g_String_512);						
				return 1;
			}
		}
		case 4: {
			if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
				switch(listitem) {
					case 0: {
						strins(caption, COLOR_DIALOG_HEAD"/tpwd", 0);
					}
					case 1: {
						strins(caption, COLOR_DIALOG_HEAD"/tname", 0);
					}	
					case 2: {
						strins(caption, COLOR_DIALOG_HEAD"/tskin", 0);
					}	
					case 3: {
						strins(caption, COLOR_DIALOG_HEAD"/gmx", 0);
					}	
					case 4: {
						strins(caption, COLOR_DIALOG_HEAD"/weather", 0);
					}	
					case 5: {
						strins(caption, COLOR_DIALOG_HEAD"/gravity", 0);
					}	
					case 6: {
						strins(caption, COLOR_DIALOG_HEAD"/nametagdis", 0);
					}	
					case 7: {
						strins(caption, COLOR_DIALOG_HEAD"/wtime", 0);
					}	
					case 8: {
						strins(caption, COLOR_DIALOG_HEAD"/rcfg", 0);
					}	
					case 9: {
						strins(caption, COLOR_DIALOG_HEAD"/tcfg", 0);
					}	
					case 10: {
						strins(caption, COLOR_DIALOG_HEAD"/rvehcfg", 0);
					}	
					case 11: {
						strins(caption, COLOR_DIALOG_HEAD"/rweapcfg", 0);
					}		
					case 12: {
						strins(caption, COLOR_DIALOG_HEAD"/lcfg", 0);
					}	
					case 13: {
						strins(caption, COLOR_DIALOG_HEAD"/pcfg", 0);
					}	
					case 14: {
						strins(caption, COLOR_DIALOG_HEAD"/agcfg", 0);
					}	
					case 15: {
						strins(caption, COLOR_DIALOG_HEAD"/mcfg", 0);
					}	
					case 16: {
						strins(caption, COLOR_DIALOG_HEAD"/team", 0);
					}		
					case 17: {
						strins(caption, COLOR_DIALOG_HEAD"/cfg", 0);
					}								
					default: {
						helpMenuBody(g_String_512, HELP_BODY_CMDS, 3);
						ShowPlayerDialog(playerid, DIALOG_HELP_CMDS_LIST, DIALOG_STYLE_LIST, helpMenuCaption(HELP_CAPTION_CMDS_HEAD_ADMIN), g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_BACK));
						return 1;
					}
				}	
				helpMenuBody(g_String_512, HELP_CMDS_LIST_HEAD_ADMIN, listitem);
				showPlayerBackDialog(playerid, BACK_HELP_MENU_CMDS_LIST, caption, g_String_512);					
				return 1;
			}
		}	
	}
	showPlayerCMDsFirstMenu(playerid);
	return 1;
}