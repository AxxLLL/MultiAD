/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define FWD_PLAYERS					0
#define FWD_AMMO					1
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_Weapon_FC_PlayerUsed[MAX_PLAYERS][MAX_WEAPON_SLOTS];
new bool:g_Round_Weapon_DontAskAgain[MAX_PLAYERS];
//------------------------------------------------------------------------------
new g_Round_Weapons_MaxSlots = 2;
new g_Round_Weapon_FreeChoose[][E_FREECHOOSE_WEAPONS_INFO] = {
	{/*!"Piesc", 				*/	false,	 	1,		0},					{/*!"Kastet", 				*/	false,	 	1,		0},				{/*!"Kij golfowy", 			*/		false,	 	1,		0},
	{/*!"Palka policyjna", 		*/	false,	 	1,		0},					{/*!"Noz", 					*/	false,	 	1,		0},				{/*!"Kij Baseballowy", 		*/		false,	 	1,		0},
	{/*!"Szpadel", 				*/	false,	 	1,		0},					{/*!"Kij bilardowy", 		*/	false,	 	1,		0},				{/*!"Katana", 				*/		false,	 	0,		0},
	{/*!"Pila mechaniczna",		*/	false,	 	1,		0},					{/*!"Dildo 1", 				*/	false,	 	1,		0},				{/*!"Dildo 2", 				*/		false,	 	1,		0},
	{/*!"Dildo 3", 				*/	false, 		1,		0},					{/*!"Dildo 4", 				*/	false,	 	1,		0},				{/*!"Kwiaty", 				*/		false,	 	1,		0},
	{/*!"Laska", 				*/	false, 		1,		0},					{/*!"Granat", 				*/	false,	 	0,		0},				{/*!"Gaz lzawiacy", 		*/		false,	 	0,		0},
	{/*!"Koktail Molotova", 	*/	false, 		0,		0},					{/*!"NaN", 					*/	false,	 	0,		0},				{/*!"NaN", 					*/		false,	 	0,		0},
	{/*!"NaN", 					*/	false, 		0,		0},					{/*!"Pistolet 9mm", 		*/	false,	 	0,		MAX_PLAYERS},	{/*!"Pistolet 9mm (+tlumik)",*/		true,	 	300,	MAX_PLAYERS},
	{/*!"Desert Eagle", 		*/	true, 		500,	MAX_PLAYERS},		{/*!"Shotgun", 				*/	true,	 	250,	MAX_PLAYERS},	{/*!"Sawnoff Shotgun", 		*/		false,	 	0,		0},
	{/*!"Combat Shotgun", 		*/	true, 		150,	0},					{/*!"Micro SMG (Uzi)", 		*/	false,	 	0,		0},				{/*!"MP5", 					*/		true,	 	600,	MAX_PLAYERS},
	{/*!"AK-47", 				*/	true, 		400,	MAX_PLAYERS},		{/*!"M4", 					*/	true,	 	350,	MAX_PLAYERS},	{/*!"Tec-9", 				*/		false,	 	0,		0},
	{/*!"Strzelba", 			*/	true, 		300,	MAX_PLAYERS},		{/*!"Karabin Snajperski", 	*/	true,	 	100,	MAX_PLAYERS},	{/*!"RPG", 					*/		false,	 	0,		0},
	{/*!"HS Rocket", 			*/	false, 		0,		0},					{/*!"Miotacz ognia", 		*/	false,	 	0,		0},				{/*!"Minigun", 				*/		false,	 	0,		0},
	{/*!"Satchel", 				*/	false, 		0,		0},					{/*!"Detonator", 			*/	false,	 	0,		0},				{/*!"Puszka spray'u", 		*/		false,	 	1,		0},
	{/*!"Gasnica", 				*/	false, 		1,		0}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
/*
getPlayerFreeChoiceAmmo(&playerid, ammo[]) {
	for(new i; i < MAX_WEAPON_SLOTS; i ++) {
		if(g_Round_Weapon_FC_PlayerUsed[playerid][i] != INVALID_WEAPON_ID) ammo[i] = g_Round_Weapon_FreeChoose[g_Round_Weapon_FC_PlayerUsed[playerid][i]][1];
		else ammo[i] = 0;
	}
}
*/
//------------------------------------------------------------------------------
getPlayerFreeChooseWeapons(&playerid, weapons_array[], limit = MAX_WEAPON_SLOTS) {
	if(limit <= 0 || limit > MAX_WEAPON_SLOTS) limit = MAX_WEAPON_SLOTS;
	for(new i; i < MAX_WEAPON_SLOTS; i ++) {
		if(i < limit) weapons_array[i] = g_Round_Weapon_FC_PlayerUsed[playerid][i];
		else weapons_array[i] = INVALID_WEAPON_ID;
	}
	return 1;
}
//------------------------------------------------------------------------------
getFreeChoiceMaxSlots() return g_Round_Weapons_MaxSlots;
//------------------------------------------------------------------------------
setFreeChoiceMaxSlots(slots) {
	if(5 >= slots >= 1) {
		g_Round_Weapons_MaxSlots = slots;
	}
}
//------------------------------------------------------------------------------
setFreeChoseWeaponData(&weaponid, E_FREECHOOSE_WEAPONS_INFO:type, &value) {
	g_Round_Weapon_FreeChoose[weaponid][type] = value;
}
//------------------------------------------------------------------------------
resetPlayerFreeChooseWeapons(&playerid) {
	ResetPlayerWeapons(playerid);
	for(new i; i < MAX_WEAPON_SLOTS; i ++) g_Round_Weapon_FC_PlayerUsed[playerid][i] = INVALID_WEAPON_ID;		
}
//------------------------------------------------------------------------------
setPlayerFreeChooseWeapons(&playerid, &slotid, &weaponid) {
	g_Round_Weapon_FC_PlayerUsed[playerid][slotid] = weaponid;		
}
//------------------------------------------------------------------------------
givePlayerFreeChooseWeapons(&playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		new given;
		ResetPlayerWeapons(playerid);
		givePlayerStaticWeapons(playerid);
		
		for(new i, weaponid; i < MAX_WEAPON_SLOTS; i ++) {
			if(g_Round_Weapon_FC_PlayerUsed[playerid][i] != INVALID_WEAPON_ID) {
				given ++;
				weaponid = g_Round_Weapon_FC_PlayerUsed[playerid][i];
				GivePlayerWeapon(playerid, weaponid, g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_AMMO]);
				g_RWeapons_Old_FreeChoose[playerid][i] = weaponid;
			} else g_RWeapons_Old_FreeChoose[playerid][i] = INVALID_WEAPON_ID;
		}
		if(given == 0) {
			new string[100];
	        getChatMessage(string, CHAT_MESSAGE_WEAPON_SELECT, 1);
	        SendClientMessage(playerid, COLOR_CMD_ERROR, string);	
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerFreeChooseWeaponMenu(&playerid, reset_weapons = true, listitem = -1) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		if(reset_weapons) resetPlayerFreeChooseWeapons(playerid);
		new weaponid, choosed, players_with_that_gun[15], player_gunlist[15] = {INVALID_WEAPON_ID, INVALID_WEAPON_ID, ...};
		//-------------
		for(new i; i < MAX_WEAPON_SLOTS; i ++) {
			if(g_Round_Weapon_FC_PlayerUsed[playerid][i] == INVALID_WEAPON_ID) {
				choosed = i;
				break;
			}
		}

		//-------------		
		if(listitem == 1 && choosed > 0) {			
			g_Round_Weapon_FC_PlayerUsed[playerid][(-- choosed)] = INVALID_WEAPON_ID;
			listitem = -1;
		} 

		//-------------
		for(new i, slot, teamid = getPlayerTeam(playerid); i < MAX_PLAYERS; i ++) {
			if(IsPlayerConnected(i) && getPlayerTeam(i) == teamid && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
				for(slot = 0; slot < MAX_WEAPON_SLOTS; slot ++) {
					if(g_Round_Weapon_FC_PlayerUsed[i][slot] == INVALID_WEAPON_ID) break;
					else {
						players_with_that_gun[(g_Round_Weapon_FC_PlayerUsed[i][slot] == 38 ? 14 : (g_Round_Weapon_FC_PlayerUsed[i][slot] - 22))] ++;
					}
				}
			}
		}
		
		//-------------
		for(new i = 22, weaponslot, bool:slot_used, gunlist_counter, x; i < 39; i ++) {
			if(g_Round_Weapon_FreeChoose[i][WEAPON_FC_ENABLE] && g_Round_Weapon_FreeChoose[i][WEAPON_FC_MAX_PLAYERS] > 0 && g_Round_Weapon_FreeChoose[i][WEAPON_FC_AMMO] > 0) {		
				for(x = 0, weaponslot = getWeaponSlot(i), slot_used = false; x < MAX_WEAPON_SLOTS; x ++) {
					if((weaponid = g_Round_Weapon_FC_PlayerUsed[playerid][x]) == INVALID_WEAPON_ID) break;
					else {
						if(getWeaponSlot(weaponid) == weaponslot) {
							slot_used = true;
							break;
						}
					}
				}
				if(slot_used == false) {
					player_gunlist[(gunlist_counter ++)] = i;
				}
			}
		}	

		//-------------
		if(listitem == -1 || listitem == 0) {	
			new caption[64];

			getDialogBodyMessage(g_String_512, DIALOG_BODY_FREECHOOSE_MENU, 2);
			if(choosed > 0) {
				getDialogBodyMessage(caption, DIALOG_BODY_FREECHOOSE_MENU, 0);
				format(g_String_512, sizeof(g_String_512), "%s\n%s", g_String_512, caption);
			}			

			for(new i, name[32]; i < sizeof(player_gunlist); i ++) {
				if(player_gunlist[i] == INVALID_WEAPON_ID) break;
				else {
					GetWeaponName((weaponid = player_gunlist[i]), name, sizeof(name));
					format(g_String_512, sizeof(g_String_512), "%s\n%s%s%s\t%d\t\t\t%d", g_String_512, (i % 2 == 0 ? (COLOR_DIALOG_COUNT) : (COLOR_DIALOG_BODY)), name, g_Round_Weapons[weaponid][WEAPON_TABS], g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_AMMO], (g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS] - players_with_that_gun[(weaponid == 38 ? 14 : (weaponid - 22))]));				
				}
			}			

			if(player_gunlist[0] != INVALID_WEAPON_ID) {	
				format((caption[0] = EOS, caption), sizeof(caption), getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), choosed, g_Round_Weapons_MaxSlots);
				ShowPlayerDialog(playerid, DIALOG_WEAPON_FREECHOOSE_SELECT_MENU, DIALOG_STYLE_LIST, caption, g_String_512, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_EXIT));
			} else {			
				showSelectedWeaponsInfo(playerid);							
				givePlayerFreeChooseWeapons(playerid);				
				getDialogBodyMessage(g_String_512, DIALOG_BODY_FREECHOOSE_MENU, 1);
				showPlayerBackDialog(playerid, BACK_NON, getDialogCaptionMessage(DIALOG_CAPTION_WEAPONS), g_String_512);			
			}
		} else {
			weaponid = player_gunlist[(listitem - (choosed > 0 ? 2 : 1))];	
			if(g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS] > players_with_that_gun[(weaponid == 38 ? 14 : (weaponid - 22))]) {
				g_Round_Weapon_FC_PlayerUsed[playerid][(choosed ++)] = weaponid;
				if(choosed == g_Round_Weapons_MaxSlots) {
					showSelectedWeaponsInfo(playerid);
					givePlayerFreeChooseWeapons(playerid);
					return 1;
				} 
			}		
			showPlayerFreeChooseWeaponMenu(playerid, false);
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
saveWeaponData() {
	if(fexist(DIR_GENERAL)) {
		new File:f_open = fopen(FILE_WEAPONS, io_write);
		new write[32];
		for(new i; i < sizeof(g_Round_Weapons); i ++) {
			if(isValidWeapon(i) && (38 >= i >= 22)) {
				format(write, sizeof(write), "\r\n%d:%d|%d|%d", i, g_Round_Weapon_FreeChoose[i][WEAPON_FC_AMMO], g_Round_Weapon_FreeChoose[i][WEAPON_FC_MAX_PLAYERS], g_Round_Weapon_FreeChoose[i][WEAPON_FC_ENABLE]);
				fwrite(f_open, write);
			}
		}		
		fclose(f_open);
		return 1;
	}
	return 0;
}

//------------------------------------------------------------------------------
loadWeaponData() {
	if(fexist(DIR_GENERAL)) {	    
	    new read[128];
	    if(!fexist(FILE_WEAPONS)) {
			saveWeaponData();
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Weapons Data", FILE_WEAPONS);
	    } else {
			new File:f_open;
			new index, length;
			new weaponid, ammo, players, enabled;
			
			f_open = fopen(FILE_WEAPONS, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0)) && index <= 2 && isValidWeapon((weaponid = strval(read))) && 38 >= weaponid >= 22) {
					if(sscanf(read[index + 1], "p<|>ddd", ammo, players, enabled) == 0 && 9999 >= ammo >= 0 && 999 >= players >= 1 && 1 >= enabled >= 0) {
						g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_AMMO] = ammo;
						g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_MAX_PLAYERS] = players;
						g_Round_Weapon_FreeChoose[weaponid][WEAPON_FC_ENABLE] = (enabled == 1 ? true : false);
					}
				}
			}
			fclose(f_open);
		}		
		return 1;
	}
	return 0;
}