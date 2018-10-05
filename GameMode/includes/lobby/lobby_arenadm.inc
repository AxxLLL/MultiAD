/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define MAX_LOBBY_TDM_SPAWN 10
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_ArenaDM_Interior = 10;
new bool:g_ArenaDM_Armour = false;
new g_ArenaDM_Spawns = MAX_LOBBY_TDM_SPAWN;
new g_ArenaDM_Weapons[13] = {1, -1, 24, 25, 29, 31, 34, -1, -1, ...};
new Float:g_ArenaDM_Zone[4] = {-99999.0, -99999.0, -99999.0, -99999.0};
new Float:g_ArenaDM_SpawnPos[MAX_LOBBY_TDM_SPAWN][3] = {
	{-1113.1446 , 1027.0458 , 1343.5024},	{-1113.1411 , 1034.6298 , 1342.8479},	{-1113.1367 , 1043.8854 , 1342.6998},
	{-1113.1324 , 1053.2231 , 1342.5924},	{-1113.1282 , 1061.9482 , 1342.7778},	{-987.6328 , 1094.0135 , 1342.9873},
	{-988.0238 , 1089.5164 , 1342.9669},	{-988.3283 , 1084.3800 , 1342.8874},	{-988.8311 , 1077.5029 , 1342.9631},
	{-988.8150 , 1069.8974 , 1342.9117}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
teleportPlayerToLobbyArenaDM(&playerid) {
	new rand = random(g_ArenaDM_Spawns);
    SetPlayerVirtualWorld(playerid, VW_LOBBY_ARENADM);
    SetPlayerInterior(playerid, g_ArenaDM_Interior);
    SetPlayerPos(playerid, CircleVariation(g_ArenaDM_SpawnPos[rand][0], 2), CircleVariation(g_ArenaDM_SpawnPos[rand][1], 2), g_ArenaDM_SpawnPos[rand][2]);
    SetPlayerTeam(playerid, TEAM_NON);
    ResetPlayerWeapons(playerid);
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, g_ArenaDM_Armour == true ? 100.0 : 0.0);
    if(g_ArenaDM_Zone[3] != -99999.0 and g_ArenaDM_Interior == 0) {
        setPlayerWorldArea(playerid, g_ArenaDM_Zone[0], g_ArenaDM_Zone[2], g_ArenaDM_Zone[1], g_ArenaDM_Zone[3], -5000.0, 5000.0, true, ZONE_COLOR);
    }
    for(new i; i < sizeof(g_ArenaDM_Weapons); i ++) {
    	if(g_ArenaDM_Weapons[i] != -1) {
			GivePlayerWeapon(playerid, g_ArenaDM_Weapons[i], 9999);
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
loadLobbyArenaDMPositions() {
	if(fexist(DIR_GENERAL)) {
	    new File:f_open;
	    new read[256];
	    if(!fexist(FILE_LOBBY_ARENADM)) {
            f_open = fopen(FILE_LOBBY_ARENADM, io_write);
            format(read, sizeof(read), "interior: %d\r\narmour: %d", g_ArenaDM_Interior, _:g_ArenaDM_Armour), fwrite(f_open, read);
            for(new i; i < g_ArenaDM_Spawns; i ++) {
                format(read, sizeof(read), "\r\nposition: %.4f, %.4f, %.4f", g_ArenaDM_SpawnPos[i][0], g_ArenaDM_SpawnPos[i][1], g_ArenaDM_SpawnPos[i][2]);
				fwrite(f_open, read);
            }
		
            for(new i; i < sizeof(g_ArenaDM_Weapons); i ++) {
				if(g_ArenaDM_Weapons[i] != -1) {
					format(read, sizeof(read), "\r\nweapon: %d", g_ArenaDM_Weapons[i]);
					fwrite(f_open, read);
				}
            }			
			if(g_ArenaDM_Zone[0] != -99999.0) {
	            format(read, sizeof(read), "\r\nzone: %.4f, %.4f, %.4f, %.4f", g_ArenaDM_Zone[0], g_ArenaDM_Zone[1], g_ArenaDM_Zone[2], g_ArenaDM_Zone[3]);
				fwrite(f_open, read);		
			}			
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Lobby ArenaDM", FILE_LOBBY_ARENADM);
	    } else {
			new readline = 1, index, length, Float:loaded_zone[4] = {-99999.0, -99999.0, -99999.0, -99999.0};
			new loadedInterior = -1, loaded_armour, loadedSpawns, Float:loadedSpawnPositions[MAX_LOBBY_TDM_SPAWN][3], loaded_weapon, slotid;
			
			f_open = fopen(FILE_LOBBY_ARENADM, io_read);
			
			for(new i; i < sizeof(g_ArenaDM_Weapons); i ++) g_ArenaDM_Weapons[i] = -1;
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0))) {
				    if(!strcmp(read, "interior", true, index)) {
						if(sscanf(read[index + 1], "d", loadedInterior) != 0) {
				            loadedInterior = -1;
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 0);
				            format(read, sizeof(read), read, FILE_LOBBY_ARENADM, readline);
							logMultiAD_Error(read);
				        }
				    } else if(!strcmp(read, "position", true, index)) {
				        if(loadedSpawns == MAX_LOBBY_TDM_SPAWN) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 2);
							format(read, sizeof(read), read, MAX_LOBBY_TDM_SPAWN, FILE_LOBBY_ARENADM, "position", readline);		
							logMultiAD_Error(read);
				        } else {
							if(sscanf(read[index + 1], "p<,>fff", loadedSpawnPositions[loadedSpawns][0], loadedSpawnPositions[loadedSpawns][1], loadedSpawnPositions[loadedSpawns][2]) != 0) {
								getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 1);
								format(read, sizeof(read), read, FILE_LOBBY_ARENADM, "position", readline);							
								logMultiAD_Error(read);
								loadedSpawnPositions[loadedSpawns][0] = loadedSpawnPositions[loadedSpawns][1] = loadedSpawnPositions[loadedSpawns][2] = -99999.0;
							} else loadedSpawns ++;	
					    }
				    } else if(!strcmp(read, "weapon", true, index)) {
						if(sscanf(read[index + 1], "d", loaded_weapon) == 0 && (slotid = getWeaponSlotByID(loaded_weapon)) != -1) {
							g_ArenaDM_Weapons[slotid] = loaded_weapon;
					    }
					} else if(!strcmp(read, "armour", true, index)) {
						if(sscanf(read[index + 1], "d", loaded_armour) != 0 || !(0 <= loaded_armour <= 1)) {
				            loaded_armour = 0;
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 5);
				            format(read, sizeof(read), read, 0, 1, "armour", FILE_LOBBY_ARENADM, readline);
							logMultiAD_Error(read);
				        }	
				    } else if(!strcmp(read, "zone", true, index)) {
						//min_x, min_y, max_x, max_y
						if(sscanf(read[index + 1], "p<,>ffff", loaded_zone[0], loaded_zone[1], loaded_zone[2], loaded_zone[3]) != 0 || loaded_zone[0] >= loaded_zone[2] || loaded_zone[1] >= loaded_zone[3]) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 1);
							format(read, sizeof(read), read, FILE_LOBBY_ARENADM, "zone", readline);							
							logMultiAD_Error(read);
							loaded_zone[0] = loaded_zone[1] = loaded_zone[2] = loaded_zone[3] = -99999.0;
					    }
				    }					
				}
				readline ++;
			}

			g_ArenaDM_Armour = (loaded_armour == 1 ? true : false);
			if(-9999.0 <= loaded_zone[0] <= 9999.0 && -9999.0 <= loaded_zone[1] <= 9999.0 && -9999.0 <= loaded_zone[2] <= 9999.0 && -9999.0 <= loaded_zone[3] <= 9999.0) {
				g_ArenaDM_Zone[0] = loaded_zone[0];
				g_ArenaDM_Zone[1] = loaded_zone[1];
				g_ArenaDM_Zone[2] = loaded_zone[2];
				g_ArenaDM_Zone[3] = loaded_zone[3];
			}
			if(loadedInterior != -1) g_ArenaDM_Interior = loadedInterior;
			if(loadedSpawns > 0) {
			    g_ArenaDM_Spawns = loadedSpawns;			    
			    for(new i; i < MAX_LOBBY_TDM_SPAWN; i ++) {
			        if(i < loadedSpawns) {
			        	g_ArenaDM_SpawnPos[i][0] = loadedSpawnPositions[i][0];
			        	g_ArenaDM_SpawnPos[i][1] = loadedSpawnPositions[i][1];
			        	g_ArenaDM_SpawnPos[i][2] = loadedSpawnPositions[i][2];
					} else {
			        	g_ArenaDM_SpawnPos[i][0] = g_ArenaDM_SpawnPos[i][1] = g_ArenaDM_SpawnPos[i][2] = 0.0;
					}
			    }
			}		
		}
		fclose(f_open);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
saveLobbyArenaDMData() {
	if(fexist(DIR_GENERAL)) {
	    new File:f_arena = fopen(FILE_LOBBY_ARENADM, io_write);
		new write[128];
        format(write, sizeof(write), "interior: %d\r\narmour: %d", g_ArenaDM_Interior, _:g_ArenaDM_Armour), fwrite(f_arena, write);
        for(new i; i < g_ArenaDM_Spawns; i ++) {
            format(write, sizeof(write), "\r\nposition: %.4f, %.4f, %.4f", g_ArenaDM_SpawnPos[i][0], g_ArenaDM_SpawnPos[i][1], g_ArenaDM_SpawnPos[i][2]);
			fwrite(f_arena, write);
        }
		
        for(new i; i < sizeof(g_ArenaDM_Weapons); i ++) {
			if(g_ArenaDM_Weapons[i] != -1) {
				format(write, sizeof(write), "\r\nweapon: %d", g_ArenaDM_Weapons[i]);
				fwrite(f_arena, write);
			}
        }			
		if(g_ArenaDM_Zone[0] != -99999.0) {
            format(write, sizeof(write), "\r\nzone: %.4f, %.4f, %.4f, %.4f", g_ArenaDM_Zone[0], g_ArenaDM_Zone[1], g_ArenaDM_Zone[2], g_ArenaDM_Zone[3]);
			fwrite(f_arena, write);		
		}				
		fclose(f_arena);
		return 1;
	}
	return 0;
}