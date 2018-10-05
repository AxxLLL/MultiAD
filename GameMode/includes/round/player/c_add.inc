/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	MAX_CRASH_DATA	15
//------------------------------------------------------------------------------
#define DO_NOTHING		0
#define	SET_AS_USED		1
#define RESET_DATA		2
//------------------------------------------------------------------------------
#define C_ADD_OFF		0
#define C_ADD_CRASHED	1
#define C_ADD_LEAVING	2
#define C_ADD_KICKED	4
//------------------------------------------------------------------------------
#define getCrashTeamAtIndex(%1)		g_Crash_Data[%1][CD_TEAM]
//==============================================================================
enum CRASH_DATA {
	bool:CD_USED,
	CD_PLAYER_NAME[7],
	CD_PLAYER_IP[5],
	CD_PLAYER_GPCI[16],
	CD_ROUND_ID,
	CD_MATCH_ID,
	CD_ROUND_TIME,
	CD_REASON,
	CD_TEAM,
	CD_CURR_WEAPON,
	CD_INTERIOR,
	CD_PREMADED_WEAPON,
	CD_FREE_WEAPONS[5],
	CD_VEHICLE_MODEL,
	Float:CD_POSITION[4],
	Float:CD_HEALTH,
	Float:CD_ARMOUR,
	CD_WEAPON_DATA_ID[13],
	CD_WEAPON_DATA_AMMO[13]
}
new g_Crash_Data[MAX_CRASH_DATA][CRASH_DATA];
//------------------------------------------------------------------------------
new g_Round_CrashPlayersFlag = C_ADD_CRASHED;
new bool:g_Round_CrashAdd_Active = false;
new g_Round_CrashAutoPause_Status = true;
new g_Round_CrashAutoAdd_Status = true;
//==============================================================================
getCrashAutoAddStatus() return _:g_Round_CrashAutoAdd_Status;
setCrashAutoAddStatus(bool:enable) {
	g_Round_CrashAutoAdd_Status = enable;
}
//------------------------------------------------------------------------------
getCrashAutoPauseStatus() return _:g_Round_CrashAutoPause_Status;
setCrashAutoPauseStatus(bool:enable) {
	g_Round_CrashAutoPause_Status = enable;
}
//------------------------------------------------------------------------------
getRoundCrashAddStatus() return _:g_Round_CrashAdd_Active;
setRoundCrashAddStatus(bool:active) {
	g_Round_CrashAdd_Active = active;
	return 1;
}
//------------------------------------------------------------------------------
getRoundCrashPauseStatus() return g_Round_CrashPlayersFlag;
//------------------------------------------------------------------------------
addRoundCrashPauseStatus(flag) {
	if(7 >= flag >= 0 && !(g_Round_CrashPlayersFlag & flag)) {
		if(flag == 0) g_Round_CrashPlayersFlag = 0;
		else g_Round_CrashPlayersFlag += flag;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
subRoundCrashPauseStatus(flag) {
	if(7 >= flag >= 0 && (g_Round_CrashPlayersFlag & flag)) {
		g_Round_CrashPlayersFlag -= flag;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
countUnusedCrashData() {
	new counter = 0;
	for(new i, roundid = getRoundRandomKey(); i < MAX_CRASH_DATA; i ++) {
		if(g_Crash_Data[i][CD_USED] == false && g_Crash_Data[i][CD_ROUND_ID] > 0 && g_Crash_Data[i][CD_ROUND_ID] == roundid) counter ++;
	}
	return counter;
}
//------------------------------------------------------------------------------
searchCrashIndexByNick(nick[]) {
	for(new i, roundid = getRoundRandomKey(); i < MAX_CRASH_DATA; i ++) {
		if(roundid > 0 && roundid == g_Crash_Data[i][CD_ROUND_ID] && strcmp(nick, g_Crash_Data[i][CD_PLAYER_NAME]) == 0) {
			return i;			
		} 
	}
	return -1;
}
//------------------------------------------------------------------------------
#define getNameByIndex(%1) \
	g_Crash_Data[%1][CD_PLAYER_NAME]
//------------------------------------------------------------------------------
#define getCrashSlotStatus(%1) g_Crash_Data[%1][CD_USED]
//------------------------------------------------------------------------------
savePlayerRoundExitData(&playerid, &reason) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && getRoundCrashPauseStatus() != 0) {	
		if((reason == 0 && getRoundCrashPauseStatus() & C_ADD_CRASHED) || (reason == 1 && getRoundCrashPauseStatus() & C_ADD_LEAVING) || (reason == 2 && getRoundCrashPauseStatus() & C_ADD_KICKED)) {	
		
			new slot = -1, usedid = -1;
			new string[64];
			new roundid = getRoundRandomKey(),
				matchid = getMatchRandomKey();				
				
			GetPlayerName(playerid, string, MAX_PLAYER_NAME);	
			for(new i; i < MAX_CRASH_DATA; i ++) {
				if(roundid > 0 && roundid == g_Crash_Data[i][CD_ROUND_ID] && strcmp(string, g_Crash_Data[slot][CD_PLAYER_NAME]) == 0) {
					slot = i;
					break;				
				} else if(roundid != g_Crash_Data[i][CD_ROUND_ID] || matchid != g_Crash_Data[i][CD_MATCH_ID]) {
					slot = i;
				} else if(g_Crash_Data[i][CD_USED] == true) {
					usedid = i;
				}
			}
			
			if(slot == -1) {
				slot = (usedid == -1 ? random(MAX_CRASH_DATA) : usedid);
			}
			
			g_Crash_Data[slot][CD_USED] = false;			
			strpack(g_Crash_Data[slot][CD_PLAYER_NAME], string, 6);	
			GetPlayerIp(playerid, string, 16);
			strpack(g_Crash_Data[slot][CD_PLAYER_IP], string, 4);
			gpci(playerid, string, 60);
			strpack(g_Crash_Data[slot][CD_PLAYER_GPCI], string, 15);
				
			g_Crash_Data[slot][CD_REASON] = reason;
			g_Crash_Data[slot][CD_MATCH_ID] = matchid;
			g_Crash_Data[slot][CD_ROUND_ID] = roundid;
			g_Crash_Data[slot][CD_ROUND_TIME] = getRoundTimeRest();
			g_Crash_Data[slot][CD_TEAM] = getPlayerTeam(playerid);
			GetPlayerHealth(playerid, g_Crash_Data[slot][CD_HEALTH]);
			GetPlayerArmour(playerid, g_Crash_Data[slot][CD_ARMOUR]);
			g_Crash_Data[slot][CD_CURR_WEAPON] = GetPlayerWeapon(playerid);
			g_Crash_Data[slot][CD_INTERIOR] = GetPlayerInterior(playerid);
			g_Crash_Data[slot][CD_PREMADED_WEAPON] = getPlayerPremadedWeaponsID(playerid);
			getPlayerFreeChooseWeapons(playerid, g_Crash_Data[slot][CD_FREE_WEAPONS]);		
			
			for(new i; i < 13; i ++) {
				GetPlayerWeaponData(playerid, i, g_Crash_Data[slot][CD_WEAPON_DATA_ID][i], g_Crash_Data[slot][CD_WEAPON_DATA_AMMO][i]);
			}
			
			if(IsPlayerInAnyVehicle(playerid)) {
				new vehicleid;
				g_Crash_Data[slot][CD_VEHICLE_MODEL] = GetVehicleModel((vehicleid = GetPlayerVehicleID(playerid)));
				GetVehiclePos(vehicleid, g_Crash_Data[slot][CD_POSITION][0], g_Crash_Data[slot][CD_POSITION][1], g_Crash_Data[slot][CD_POSITION][2]);
				GetVehicleZAngle(vehicleid, g_Crash_Data[slot][CD_POSITION][3]);		
			} else {	
				g_Crash_Data[slot][CD_VEHICLE_MODEL] = 0;
				GetPlayerPos(playerid, g_Crash_Data[slot][CD_POSITION][0], g_Crash_Data[slot][CD_POSITION][1], g_Crash_Data[slot][CD_POSITION][2]);
				GetPlayerFacingAngle(playerid, g_Crash_Data[slot][CD_POSITION][3]);
			}		
			
			return slot;
		}
	}
	return -1;
}
//------------------------------------------------------------------------------
addPlayerAfterCrash(&playerid, &slot, slot_action = SET_AS_USED) {
	if(getRoundState() == ROUND_STATE_REMAIN && MAX_CRASH_DATA > slot >= 0 && (IsPlayerConnected(playerid) && TEAM_ONE <= getPlayerTeam(playerid) <= TEAM_TWO && getPlayerTeam(playerid) == g_Crash_Data[slot][CD_TEAM] && getPlayerStatus(playerid) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(playerid) != PLAYER_STATUS_IN_ROUND && GetPlayerState(playerid) != PLAYER_STATE_WASTED)) {
		if(g_Crash_Data[slot][CD_ROUND_ID] > 0 && getRoundRandomKey() == g_Crash_Data[slot][CD_ROUND_ID]) {
			addPlayerToRound(playerid, true, false, false);
			SetPlayerInterior(playerid, g_Crash_Data[slot][CD_INTERIOR]);
			SetPlayerHealth(playerid, g_Crash_Data[slot][CD_HEALTH]);
			SetPlayerArmour(playerid, g_Crash_Data[slot][CD_ARMOUR]);
			SetPlayerPos(playerid, g_Crash_Data[slot][CD_POSITION][0], g_Crash_Data[slot][CD_POSITION][1], g_Crash_Data[slot][CD_POSITION][2]);
			SetPlayerFacingAngle(playerid, g_Crash_Data[slot][CD_POSITION][3]);

			resetPlayerFreeChooseWeapons(playerid);
			for(new i; i < MAX_WEAPON_SLOTS; i ++) setPlayerFreeChooseWeapons(playerid, i, g_Crash_Data[slot][CD_FREE_WEAPONS][i]);
			setPlayerPremadedWeaponsID(playerid, g_Crash_Data[slot][CD_PREMADED_WEAPON]);
			
			//----------------------------
			
			if(getWeaponSelectType() == PERMADED_WEAPON_SETS) {
				if(getPlayerPremadedWeaponsID(playerid) == INVALID_WEAPON_ID) {
					showPlayerRoundWeaponSelectMenu(playerid);
				} else {
					new weapon_set = getPlayerPremadedWeaponsID(playerid), used_sets;

					forplayers(i) {
						if(i != playerid && getPlayerPremadedWeaponsID(i) == weapon_set && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && g_Crash_Data[slot][CD_TEAM] == getPlayerTeam(i)) {
							used_sets ++;
						}
					}
					if(used_sets >= getMaxPlayersAtWeaponSlot(weapon_set)) {
						showPlayerRoundWeaponSelectMenu(playerid);
					} else {
						for(new i; i < 13; i ++) {
							GivePlayerWeapon(playerid, g_Crash_Data[slot][CD_WEAPON_DATA_ID][i], g_Crash_Data[slot][CD_WEAPON_DATA_AMMO][i]);
						}						
						//givePlayerWeaponSetWeapons(playerid);
						SetPlayerArmedWeapon(playerid, g_Crash_Data[slot][CD_CURR_WEAPON]);
					}
				}
			} else {
				if(g_Crash_Data[slot][CD_FREE_WEAPONS][getFreeChoiceMaxSlots() - 1] == INVALID_WEAPON_ID) {
					showPlayerRoundWeaponSelectMenu(playerid);
				} else {
					new players_with_that_gun[15], bool:error = false;
					for(new i, weaponslot; i < MAX_PLAYERS; i ++) {
						if(IsPlayerConnected(i) && i != playerid && getPlayerTeam(i) == g_Crash_Data[slot][CD_TEAM] && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
							for(weaponslot = 0; weaponslot < MAX_WEAPON_SLOTS; weaponslot ++) {
								if(g_Round_Weapon_FC_PlayerUsed[i][weaponslot] == INVALID_WEAPON_ID) break;
								else {
									players_with_that_gun[(g_Round_Weapon_FC_PlayerUsed[i][weaponslot] == 38 ? 14 : (g_Round_Weapon_FC_PlayerUsed[i][weaponslot] - 22))] ++;
								}
							}						
						}
					}		
					
					for(new i, max_slots = getFreeChoiceMaxSlots(), weaponid; i < max_slots; i ++) {
						weaponid = g_Crash_Data[slot][CD_FREE_WEAPONS][i];
						if(players_with_that_gun[((weaponid == 38) ? 14 : (weaponid - 22))] >= g_Round_Weapon_FreeChoose[g_Crash_Data[slot][CD_FREE_WEAPONS][i]][WEAPON_FC_MAX_PLAYERS]) {
							showPlayerRoundWeaponSelectMenu(playerid);
							error = true;
							break;
						}
					}
					
					if(error == false) {
						for(new i; i < 13; i ++) {
							GivePlayerWeapon(playerid, g_Crash_Data[slot][CD_WEAPON_DATA_ID][i], g_Crash_Data[slot][CD_WEAPON_DATA_AMMO][i]);
						}								
						//givePlayerFreeChooseWeapons(playerid);
						SetPlayerArmedWeapon(playerid, g_Crash_Data[slot][CD_CURR_WEAPON]);
					}					
				}
			}
			
			switch(slot_action) {
				case DO_NOTHING: {}
				case SET_AS_USED: {
					g_Crash_Data[slot][CD_USED] = true;
				}
				case RESET_DATA: {
					g_Crash_Data[slot][CD_USED] = false;
					strdel(g_Crash_Data[slot][CD_PLAYER_NAME], 0, 7);	
					strdel(g_Crash_Data[slot][CD_PLAYER_IP], 0, 5);
					strdel(g_Crash_Data[slot][CD_PLAYER_GPCI], 0, 16);
						
					g_Crash_Data[slot][CD_REASON] = 0;
					g_Crash_Data[slot][CD_MATCH_ID] = 0;
					g_Crash_Data[slot][CD_ROUND_ID] = 0;
					g_Crash_Data[slot][CD_ROUND_TIME] = 0;
					g_Crash_Data[slot][CD_TEAM] = 0;
					g_Crash_Data[slot][CD_HEALTH] = 0.0;
					g_Crash_Data[slot][CD_ARMOUR] = 0.0;
					g_Crash_Data[slot][CD_CURR_WEAPON] = 0;
					g_Crash_Data[slot][CD_INTERIOR] = 0;
					g_Crash_Data[slot][CD_PREMADED_WEAPON] = INVALID_WEAPON_ID;
					
					for(new i; i < 13; i ++) {
						g_Crash_Data[slot][CD_WEAPON_DATA_ID][i] = g_Crash_Data[slot][CD_WEAPON_DATA_AMMO][i] = 0;
					}				
					
					for(new i; i < MAX_WEAPON_SLOTS; i ++) g_Crash_Data[slot][CD_FREE_WEAPONS][i] = INVALID_WEAPON_ID;						
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
caddStopRound(reason) {
	new admin_counter;
	getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 2);
	forplayers(i) {
		if(IsAdminOrRCON(i, ALVL_JUNIOR_ADMIN)) {  
			admin_counter ++;
			SendClientMessage(i, COLOR_INFO_1, " ");
			SendClientMessage(i, COLOR_INFO_1, g_Chat_String);
			break;
		}				
	}
	if(admin_counter > 0) {
		setRoundPauseStatus(true);		
		setRoundCrashAddStatus(true);
		
		if(reason == INVALID_PLAYER_ID) {
			getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 1);
		} else {
			getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 4);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(reason));
		}		
		SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
		
		forplayers(i) {
			if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {  
				showCrashAddInfoForPlayer(i);
			}				
		}						
	} else {
		getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 3);
		SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	}
}	
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showCrashedPlayersList(&playerid, listitem = -1) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN) && getRoundState() == ROUND_STATE_REMAIN) {
		new counter;
		
		if(listitem == -1) {
			new added[20], notadded[20], t_one_color[12], t_two_color[12];
			g_String_512[0] = EOS;
			getDialogBodyMessage(g_Chat_String, DIALOG_BODY_CRASH_LIST, 0);
			getDialogBodyMessage(added, DIALOG_BODY_CRASH_LIST, 1);
			getDialogBodyMessage(notadded, DIALOG_BODY_CRASH_LIST, 2);
			getTeamColorText(TEAM_ONE, COLOR_STATUS_DEATH, t_one_color, 12);
			getTeamColorText(TEAM_TWO, COLOR_STATUS_DEATH, t_two_color, 12);
			
			for(new i, roundid = getRoundRandomKey(), nick[MAX_PLAYER_NAME]; i < MAX_CRASH_DATA; i ++) {
				if(g_Crash_Data[i][CD_ROUND_ID] > 0 && g_Crash_Data[i][CD_ROUND_ID] == roundid) {
					strunpack(nick, g_Crash_Data[i][CD_PLAYER_NAME], MAX_PLAYER_NAME);
					format(g_String_512, sizeof(g_String_512), "%s\n%s%s : %s", g_String_512, (g_Crash_Data[i][CD_TEAM] == TEAM_ONE ? (t_one_color) : (t_two_color)), nick, (g_Crash_Data[i][CD_USED] ? (added) : (notadded)) );
					counter ++;
				}
			}		
		} else {
			for(new i, roundid = getRoundRandomKey(); i < MAX_CRASH_DATA; i ++) {
				if(g_Crash_Data[i][CD_ROUND_ID] > 0 && g_Crash_Data[i][CD_ROUND_ID] == roundid) {
					if((counter ++) == listitem) {
						showDetailedCrasherPlayerInfo(playerid, i);
						return 1;
					}
				}
			}				
			counter = 0;
		}	
			
		if(counter > 0) {
			if(listitem == -1) ShowPlayerDialog(playerid, DIALOG_CRASH_ADD_LIST, DIALOG_STYLE_LIST, "Crash List", g_String_512, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));
		} else {
			getDialogBodyMessage(g_Chat_String, DIALOG_BODY_CRASH_LIST, 0);
			showPlayerBackDialog(playerid, BACK_NON, "Crash List", g_Chat_String);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
showDetailedCrasherPlayerInfo(&playerid, index, inputtext[] = "") {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN) && getRoundState() == ROUND_STATE_REMAIN) {
		if(g_Crash_Data[index][CD_ROUND_ID] > 0 && g_Crash_Data[index][CD_ROUND_ID] == getRoundRandomKey()) {
		
			new nick[MAX_PLAYER_NAME];
			strunpack(nick, g_Crash_Data[index][CD_PLAYER_NAME], MAX_PLAYER_NAME);
			SetPVarInt(playerid, PV_HELP_VAR_1, 999990);
			SetPVarInt(playerid, PV_HELP_VAR_2, index);
			
			if(!isnull(inputtext) && 3 >= strlen(inputtext) >= 1 && '9' >= inputtext[0] >= '0') {
				new add_id;
				if(IsPlayerConnected((add_id = strval(inputtext)))) {
					if(TEAM_TWO >= getPlayerTeam(add_id) >= TEAM_ONE && getPlayerTeam(add_id) == g_Crash_Data[index][CD_TEAM]) {
						if(getPlayerStatus(add_id) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(add_id) != PLAYER_STATUS_IN_ROUND && GetPlayerState(add_id) != PLAYER_STATE_WASTED) {
							if(addPlayerAfterCrash(add_id, index, SET_AS_USED)) {								
								getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 0);
								format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(add_id), nick, getTeamName(g_Crash_Data[index][CD_TEAM]));
								SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
								c_print(g_Chat_String);								
							} else {
								getDialogBodyMessage(g_Chat_String, DIALOG_BODY_CRASH_LIST, 5);
								showPlayerBackDialog(playerid, BACK_CRASH_ADD_PLAYER_INFO, "Crash List", g_Chat_String);
							}
							SetPVarInt(playerid, PV_HELP_VAR_1, 0);
							return 1;
						}
					}
				}
			}		
		
			new reason[16], ip[16], t_one_color[12], t_two_color[12];		
			
			strunpack(ip, g_Crash_Data[index][CD_PLAYER_IP], 16);
			getTeamColorText(TEAM_ONE, COLOR_STATUS_DEATH, t_one_color, 12);
			getTeamColorText(TEAM_TWO, COLOR_STATUS_DEATH, t_two_color, 12);
			
			switch(g_Crash_Data[index][CD_REASON]) {
				case 0: strins(reason, "Timeout/Crash", 0);
				case 1: strins(reason, "Quit", 0);
				case 2: strins(reason, "Kick/Ban", 0);
			}
	
			getDialogBodyMessage(g_String_512, DIALOG_BODY_CRASH_LIST, 4);
			format(g_String_512, sizeof(g_String_512), g_String_512,
				nick,
				(g_Crash_Data[index][CD_USED] ? (C_LIGHTGREEN) : (C_KICK)), (g_Crash_Data[index][CD_USED] ? (oftenUsedPhrases(LANG_OUP_YES)) : (oftenUsedPhrases(LANG_OUP_NO))),
				(g_Crash_Data[index][CD_TEAM] == TEAM_ONE ? (t_one_color) : (t_two_color)), getTeamName(g_Crash_Data[index][CD_TEAM]),
				floatround(floatdiv(g_Crash_Data[index][CD_ROUND_TIME], 60), floatround_floor),
				(g_Crash_Data[index][CD_ROUND_TIME] % 60),
				reason,
				ip,
				g_Crash_Data[index][CD_HEALTH],
				g_Crash_Data[index][CD_ARMOUR]
			);
			ShowPlayerDialog(playerid, DIALOG_CRASH_ADD_PLAYER_INFO, DIALOG_STYLE_INPUT, "Crash List", g_String_512, (oftenUsedPhrases(LANG_OUP_ADD)),  (oftenUsedPhrases(LANG_OUP_BACK)));
			
		} else {
			getDialogBodyMessage(g_Chat_String, DIALOG_BODY_CRASH_LIST, 3);
			showPlayerBackDialog(playerid, BACK_CRASH_ADD_LIST, "Crash List", g_Chat_String);
		}
	}
	return 0;
}