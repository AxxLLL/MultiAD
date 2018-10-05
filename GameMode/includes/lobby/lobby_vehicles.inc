/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define getPlayerLobbyVehicleID(%1)		g_Player_Lobby_VehicleID[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Lobby_VehicleID[MAX_PLAYERS] = {-1, -1, -1, ...};
//------------------------------------------------------------------------------
new bool:g_Lobby_AllowLobbyVehicles = true;
new bool:g_Lobby_AllowInteriorVehicles = false;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getInteriorLobbyVehiclesStatus() return _:g_Lobby_AllowInteriorVehicles;
//------------------------------------------------------------------------------
setInteriorLobbyVehiclesStatus(bool:enable) g_Lobby_AllowInteriorVehicles = enable;
//------------------------------------------------------------------------------
getLobbyVehiclesStatus() return _:g_Lobby_AllowLobbyVehicles;
//------------------------------------------------------------------------------
setLobbyVehiclesStatus(bool:enable) g_Lobby_AllowLobbyVehicles = enable;
//------------------------------------------------------------------------------
givePlayerLobbyVehicle(&playerid, modelid) {
	if(getLobbyVehiclesStatus() && getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY && (getLobbyInterior() == 0 || g_Lobby_AllowInteriorVehicles) && 611 >= modelid >= 400) {
		if(getVehicleFlagsByModel(modelid) & VEHICLE_LOBBY_SPAWN) {			
			new Float:x, Float:y, Float:z, Float:a, name[20], string[128], interior;
			if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
			DestroyVehicle(g_Player_Lobby_VehicleID[playerid]);	
			GetPlayerPos(playerid, x, y, z);
			GetPlayerFacingAngle(playerid, a);
			interior = GetPlayerInterior(playerid);
			g_Player_Lobby_VehicleID[playerid] = CreateVehicle(modelid, x, y, z, a, 3, 1, -1);
			SetVehicleVirtualWorld(g_Player_Lobby_VehicleID[playerid], VW_LOBBY);
			LinkVehicleToInterior(g_Player_Lobby_VehicleID[playerid], interior);
			PutPlayerInVehicle(playerid, g_Player_Lobby_VehicleID[playerid], 0);
			getVehicleNameByModel(modelid, name);		
			getChatMessage(string, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, 0);
			format(string, sizeof(string), string, name, modelid);
			strins(name, "~w~", 0);
			GameTextForPlayer(playerid, name, 5000, 1);
			SendClientMessage(playerid, COLOR_INFO_1, string);
			return 1;
		} else return -1;
	}
	return 0;
}
//------------------------------------------------------------------------------
destroyPlayerLobbyVehicle(&playerid) {
	if(g_Player_Lobby_VehicleID[playerid] != -1) {
		if(IsPlayerInVehicle(playerid, g_Player_Lobby_VehicleID[playerid])) RemovePlayerFromVehicle(playerid);
		DestroyVehicle(g_Player_Lobby_VehicleID[playerid]);
		g_Player_Lobby_VehicleID[playerid] = -1;
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerLobbyVehSelectMenu(playerid, listitem = -1) {
	if(getLobbyVehiclesStatus() && getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY && (getLobbyInterior() == 0 || g_Lobby_AllowInteriorVehicles)) {	
		if(listitem == -1) {
			new string[400];
			getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 0);
			ShowPlayerDialog(playerid, DIALOG_LOBBY_VEHICLES_TYPES, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));
		} else {
			SetPVarInt(playerid, PV_HELP_VAR_1, listitem);
			showPlayerLobbyVehNames(playerid);
		}
		return 1;	
	}
	return 0;
}
//------------------------------------------------------------------------------
showPlayerLobbyVehNames(playerid, listitem = -1) {
	if(getLobbyVehiclesStatus() && getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY && (getLobbyInterior() == 0 || g_Lobby_AllowInteriorVehicles)) {	

		new string[700], name[16];
		new counter, VEHICLE_TYPES: type;
		switch(GetPVarInt(playerid, PV_HELP_VAR_1)) {
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

		if(listitem == -1) {
			for(new i; i < sizeof(g_VehicleList); i ++) {
				if(getVehicleTypeByIndex(i) == type && getVehicleFlagsByIndex(i) & VEHICLE_LOBBY_SPAWN) {
					strunpack(name, getVehicleNameByIndex(i));
					format(string, sizeof(string), "%s\n"COLOR_DIALOG_BODY"%s", string, name);
					counter ++;
				}
			}

			if(counter > 0) {
				ShowPlayerDialog(playerid, DIALOG_LOBBY_VEHICLES_NAMES, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_BACK));
			} else {
				getDialogBodyMessage(string, DIALOG_BODY_VEHICLE_TYPES, 1);
				showPlayerBackDialog(playerid, BACK_VEHICLE_NAMES, getDialogCaptionMessage(DIALOG_CAPTION_VEHICLES), string);
			}
		} else {
			for(new i; i < sizeof(g_VehicleList); i ++) {
				if(getVehicleTypeByIndex(i) == type && getVehicleFlagsByIndex(i) & VEHICLE_LOBBY_SPAWN) {
					if(counter == listitem) {
						givePlayerLobbyVehicle(playerid, getVehicleModelByIndex(i));
						return 1;
					} else counter ++;
				}
			}			
		}
		
		return 1;
	}
	return 0;
}