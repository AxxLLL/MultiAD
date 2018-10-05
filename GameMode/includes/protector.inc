/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define ABLE_NETCHECK_ALL			0
#define DISABLE_NETCHECK_PING		1
#define DISABLE_NETCHECK_FPS		2
#define DISABLE_NETCHECK_PLOSS		4
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Protector_MaxPing = 100,
	g_Protector_MinFPS = 15,
	Float:g_Protector_MaxPLoss = 5.0;
new g_Protector_Action = PROTECTOR_SEND_MESSAGE,
	g_Protector_CheckReferees = false;
//------------------------------------------------------------------------------
new g_Protector_Player_Warnings[MAX_PLAYERS][3]; 
new g_Protector_Max_Warnings[3] = {3, 3, 3};
//------------------------------------------------------------------------------
new g_Protector_Player_Check_Flags[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
addPlayerNetCheckFlag(&playerid, flag) {
	if(flag == ABLE_NETCHECK_ALL) {
		g_Protector_Player_Check_Flags[playerid] = ABLE_NETCHECK_ALL;
		return 1;
	} else {
		if((flag == DISABLE_NETCHECK_PING || flag == DISABLE_NETCHECK_FPS || flag == DISABLE_NETCHECK_PLOSS) && !(g_Protector_Player_Check_Flags[playerid] & flag)) {
			g_Protector_Player_Check_Flags[playerid] += flag;
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
subPlayerNetCheckFlag(&playerid, flag) {
	if(flag == ABLE_NETCHECK_ALL) {
		g_Protector_Player_Check_Flags[playerid] = ABLE_NETCHECK_ALL;
		return 1;
	} else {
		if((flag == DISABLE_NETCHECK_PING || flag == DISABLE_NETCHECK_FPS || flag == DISABLE_NETCHECK_PLOSS) && (g_Protector_Player_Check_Flags[playerid] & flag)) {
			g_Protector_Player_Check_Flags[playerid] -= flag;
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
checkPlayerNetCheckFlag(&playerid, flag) return (g_Protector_Player_Check_Flags[playerid] & flag);
//------------------------------------------------------------------------------
getProtectorAction() return g_Protector_Action;
//------------------------------------------------------------------------------
setProtectorAction(action) g_Protector_Action = action;
//------------------------------------------------------------------------------
protectionCheckReferees() return _:g_Protector_CheckReferees;
//------------------------------------------------------------------------------
setProtectionCheckReferees(bool:check) g_Protector_CheckReferees = check;
//------------------------------------------------------------------------------
getProtectorMaxWarnings(reason)	return g_Protector_Max_Warnings[reason];
//------------------------------------------------------------------------------
setProtectorMaxWarnings(reason, limit) {
	if(99 >= limit >= 1) g_Protector_Max_Warnings[reason] = limit;
}
//------------------------------------------------------------------------------
resetPlayerProtectorWarnings(&playerid) {
	g_Protector_Player_Warnings[playerid][PROTECTOR_CHECK_PING] = g_Protector_Player_Warnings[playerid][PROTECTOR_CHECK_FPS] = g_Protector_Player_Warnings[playerid][PROTECTOR_CHECK_PLOSS] = 0;
}
//------------------------------------------------------------------------------
addPlayerProtectorWarning(&playerid, reason) {
	if((++ g_Protector_Player_Warnings[playerid][reason]) > g_Protector_Max_Warnings[reason]) {
		g_Protector_Player_Warnings[playerid][reason] --;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
removePlayerProtectorWarning(playerid, reason) {
	if((-- g_Protector_Player_Warnings[playerid][reason]) < 0) g_Protector_Player_Warnings[playerid][reason] = 0;
}
//------------------------------------------------------------------------------
getPlayerWarnings(&playerid, reason) return g_Protector_Player_Warnings[playerid][reason];
//------------------------------------------------------------------------------
getMaxPingValue() return g_Protector_MaxPing;
setMaxPingValue(value) {
	if(9999 >= value >= 10) {
		g_Protector_MaxPing = value;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getMinFPSValue() return g_Protector_MinFPS;
setMinFPSValue(value) {
	if(89 >= value >= 1) {
		g_Protector_MinFPS = value;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
Float:getMaxPLossValue() return g_Protector_MaxPLoss;
setMaxPLossValue(Float:value) {
	if(99.0 >= value >= 1.0) {
		g_Protector_MaxPLoss = value;
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerProtectorSettingMenu(playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[405];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_PROTECTOR, 0);
			getSettingsBodyMessage(string, SBM_MENU_PROTECTOR, 0);		
			format(string, sizeof(string), string, protectionCheckReferees() ? (C_LIGHTGREEN) : (C_KICK), (getProtectorAction() == PROTECTOR_SEND_MESSAGE ? ("MSG") : ("Kick")), getMaxPingValue(), getProtectorMaxWarnings(PROTECTOR_CHECK_PING), getMinFPSValue(), getProtectorMaxWarnings(PROTECTOR_CHECK_FPS), getMaxPLossValue(), getProtectorMaxWarnings(PROTECTOR_CHECK_PLOSS));
			ShowPlayerDialog(playerid, DIALOG_PROTECTOR_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(GetPVarInt(playerid, PV_HELP_VAR_2) == 1 ? (LANG_OUP_BACK) : (LANG_OUP_EXIT)));
		} else {
			switch(listitem) {
				case 0: {
					setProtectionCheckReferees(!protectionCheckReferees());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (protectionCheckReferees() ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Restrictions: Check Referees");						
				}
				case 1: {
					setProtectorAction(!getProtectorAction());
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, 4);
					format(string, sizeof(string), string, getPlayerName(playerid), "Restrictions: Action after reached limit", (getProtectorAction() == PROTECTOR_SEND_MESSAGE ? ("MSG") : ("Kick")));						
				}			
				case 2: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_MAX_PING_VALUE);
				case 3: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_MAX_PING_WARNINGS);
				case 4: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_MIN_FPS_VALUE);
				case 5: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_MIN_FPS_WARNINGS);
				case 6: return showPlayerFloatValueDialogBack(playerid, DIALOG_F_VALUE_MAX_PLOSS_VALUE);
				case 7: return showPlayerValueDialogBack(playerid, DIALOG_VALUE_MAX_PLOSS_WARNINGS);
				default: return showPlayerProtectorSettingMenu(playerid);
			}
			SendClientMessageToAll(COLOR_INFO_1, string);
			c_print(string);					
			showPlayerProtectorSettingMenu(playerid);
		}
		return 1;
	}
	return 0;
}