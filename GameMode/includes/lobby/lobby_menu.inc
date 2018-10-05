/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerLobbySettingMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[220];
		if(listitem == -1) {
			new caption[64];
			getSettingsCaptionMessage(caption, SCM_LOBBY, 0);
			getSettingsBodyMessage(string, SBM_MENU_LOBBY, 0);		
			format(string, sizeof(string), string, (g_ArenaDM_Armour ? (C_LIGHTGREEN) : (C_KICK)), (g_Lobby_AllowLobbyVehicles ? (C_LIGHTGREEN) : (C_KICK)), (g_Lobby_AllowInteriorVehicles ? (C_LIGHTGREEN) : (C_KICK)));
			ShowPlayerDialog(playerid, DIALOG_LOBBY_SETTINGS, DIALOG_STYLE_TABLIST_HEADERS, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(GetPVarInt(playerid, PV_HELP_VAR_2) == 1 ? (LANG_OUP_BACK) : (LANG_OUP_EXIT)));
		} else {
			switch(listitem) {
				case 0: {
					showPlayerLobbyWeaponsMenu(playerid);
					return 1;
				}		
				case 1: {
					g_ArenaDM_Armour = !g_ArenaDM_Armour;
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_ArenaDM_Armour ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Training Arena: Armour");					
				}
				case 2: {
					showPlayerLobbyVehiclesMenu(playerid);
					return 1;
				}
				case 3: {
					g_Lobby_AllowLobbyVehicles = !g_Lobby_AllowLobbyVehicles;
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_Lobby_AllowLobbyVehicles ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Lobby: Vehicles");						
				}
				case 4: {
					g_Lobby_AllowInteriorVehicles = !g_Lobby_AllowInteriorVehicles;
					getChatMessage(string, CHAT_MESSAGE_ROUND_SETTING_INFO, (g_Lobby_AllowInteriorVehicles ? 1 : 0));
					format(string, sizeof(string), string, getPlayerName(playerid), "Lobby: Interior Vehicles");						
				}
				default: return showPlayerLobbySettingMenu(playerid);
			}
			SendClientMessageToAll(COLOR_INFO_1, string);
			c_print(string);					
			showPlayerLobbySettingMenu(playerid);
		}
		return 1;
	}
	return 0;
}
//==============================================================================
showPlayerLobbyVehiclesMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		if(listitem == -1) {
			new string[256], caption[64];
			getSettingsCaptionMessage(caption, SCM_LOBBY_VEHICLES);
			getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 0);
			ShowPlayerDialog(playerid, DIALOG_LOBBY_VEHICLE_SETTINGS, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));
		} else {
			SetPVarInt(playerid, PV_HELP_VAR_4, listitem);
			showPlayerLobbyVehiclesSubmenu(playerid);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerLobbyVehiclesSubmenu(&playerid, listitem = -1) {
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
					if(getVehicleFlagsByIndex(i) & VEHICLE_LOBBY_SPAWN) getVehicleFlagsByIndex(i) -= VEHICLE_LOBBY_SPAWN;
					else getVehicleFlagsByIndex(i) += VEHICLE_LOBBY_SPAWN;
					break;
				}
			}
		}
		
		for(new i, v_name[16]; i < sizeof(g_VehicleList); i ++) {
			if(getVehicleTypeByIndex(i) == type) {
				strunpack(v_name, getVehicleNameByIndex(i));
				format(string, sizeof(string), "%s\n%s%s", string, (getVehicleFlagsByIndex(i) & VEHICLE_LOBBY_SPAWN ? (C_LIGHTGREEN) : (C_KICK)), v_name);
			}
		}
		
		getSettingsCaptionMessage(caption, SCM_LOBBY_VEHICLES);
		ShowPlayerDialog(playerid, DIALOG_LOBBY_VEHICLE_SUBMENU, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));	
		return 1;
	}
	return 0;
}
//==============================================================================
showPlayerLobbyWeaponsMenu(&playerid, listitem = -1) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[560], caption[64];
	
		if(listitem != -1) {		
			new slotid;
			countRealIndex(listitem, true);
			if(g_ArenaDM_Weapons[(slotid = getWeaponSlot(listitem))] == listitem) g_ArenaDM_Weapons[slotid] = -1;
			else g_ArenaDM_Weapons[slotid] = listitem;
		}
		
		for(new i = 1, w_name[32]; i < sizeof(g_Round_Weapons); i ++) {
			if(getWeaponFlag(i) == W_ALLOWED) {
				GetWeaponName(i, w_name, sizeof(w_name));
				format(string, sizeof(string), "%s\n%s%s", string, (g_ArenaDM_Weapons[getWeaponSlot(i)] == i ? (C_LIGHTGREEN) : (C_KICK)), w_name);
			}
		}
		
		getSettingsCaptionMessage(caption, SCM_LOBBY_WEAPONS);
		ShowPlayerDialog(playerid, DIALOG_LOBBY_WEAPONS_MENU, DIALOG_STYLE_LIST, caption, string, oftenUsedPhrases(LANG_OUP_CHANGE), oftenUsedPhrases(LANG_OUP_BACK));	
		return 1;
	}
	return 0;
}