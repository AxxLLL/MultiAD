/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	MAX_STATIC_WEAPONS			5
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_Weapon_StaticWeapons[MAX_STATIC_WEAPONS][2] = {
	{1,		1},		{-1, 	0},		{-1,	0}, 	{-1,	0},		{-1, 	0}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
givePlayerStaticWeapons(&playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		for(new i, weaponid; i < MAX_STATIC_WEAPONS; i ++) {
			if((isValidWeapon((weaponid = g_Round_Weapon_StaticWeapons[i][0])) || weaponid == 46) && 9999 >= g_Round_Weapon_StaticWeapons[i][0] > 0) {
				GivePlayerWeapon(playerid, weaponid, g_Round_Weapon_StaticWeapons[i][1]);
			}
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setStaticWeaponAmmo(weaponslot, ammo) {
	if(9999 >= ammo >= 0) {
		if(g_Round_Weapon_StaticWeapons[weaponslot][0] != INVALID_WEAPON_ID) g_Round_Weapon_StaticWeapons[weaponslot][1] = ammo;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setStaticWeaponWeapon(weaponslot, weaponid) {
	if((isValidWeapon(weaponid) || weaponid == INVALID_WEAPON_ID || weaponid == 46) && (16 >= weaponid >= 1 || weaponid == 46 || 42 >= weaponid >= 41)) {
		g_Round_Weapon_StaticWeapons[weaponslot][0] = weaponid;
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
saveStaticWeaponData() {
	if(fexist(DIR_GENERAL)) {
		new File:f_open = fopen(FILE_STATIC_WEAPONS, io_write);
		new write[32];
		for(new i; i < MAX_STATIC_WEAPONS; i ++) {
			if(isValidWeapon(g_Round_Weapon_StaticWeapons[i][0]) || g_Round_Weapon_StaticWeapons[i][0] == 46) {
				format(write, sizeof(write), "\r\n%d:%d", g_Round_Weapon_StaticWeapons[i][0], g_Round_Weapon_StaticWeapons[i][1]);
				fwrite(f_open, write);
			}
		}		
		fclose(f_open);
		return 1;
	}
	return 0;
}

//------------------------------------------------------------------------------
loadStaticWeaponData() {
	if(fexist(DIR_GENERAL)) {	    
	    new read[128];
	    if(!fexist(FILE_STATIC_WEAPONS)) {
			saveStaticWeaponData();
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Static Weapon Data", FILE_STATIC_WEAPONS);
	    } else {
			new File:f_open;
			new index, length;
			new weaponid, ammo, counter, bool:founded, i, slotid;
			
			f_open = fopen(FILE_STATIC_WEAPONS, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0)) && index <= 2 && ((isValidWeapon(weaponid = strval(read)) || weaponid == 46) && (16 >= weaponid >= 1 || weaponid == 46 || 42 >= weaponid >= 41)) && length - index < 6 && 9999 >= (ammo = strval(read[index + 1])) > 0) {
					for(i = 0, founded = false, slotid = getWeaponSlot(weaponid); i < MAX_STATIC_WEAPONS; i ++) {
						if(g_Round_Weapon_StaticWeapons[i][0] != -1 && (g_Round_Weapon_StaticWeapons[i][0] == weaponid || slotid == getWeaponSlot(g_Round_Weapon_StaticWeapons[i][0]))) {
							g_Round_Weapon_StaticWeapons[i][0] = weaponid;
							g_Round_Weapon_StaticWeapons[i][1] = ammo;
							founded = true;
							break;
						}
					}
					if(founded == false) {
						g_Round_Weapon_StaticWeapons[counter][0] = weaponid;
						g_Round_Weapon_StaticWeapons[counter][1] = ammo;
						
						if((++ counter) == MAX_STATIC_WEAPONS) {
							break;
						}
					}
				}
			}
			fclose(f_open);
		}		
		return 1;
	}
	return 0;
}