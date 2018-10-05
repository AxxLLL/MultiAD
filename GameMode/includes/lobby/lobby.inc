/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	getLobbyInterior()			g_LobbyInterior
//------------------------------------------------------------------------------
#define MAX_LOBBY_SPAWN 			50
//==============================================================================
new g_LobbyInterior = 1;
new g_LoadedLobbySpawns = 15;
new Float:g_LobbySpawnPos[MAX_LOBBY_SPAWN][3] = {
	{-789.2573 , 495.5433 , 1376.1953}, {-794.4801 , 497.1124 , 1376.1953}, {-794.3865 , 506.5628 , 1371.7421}, {-786.0422 , 506.4238 , 1371.7490}, {-780.7328 , 501.4897 , 1371.7490},
	{-786.5101 , 497.6416 , 1371.7421}, {-813.3947 , 502.6051 , 1359.8566}, {-817.9656 , 502.2951 , 1359.5526}, {-821.0064 , 498.8636 , 1359.2609}, {-825.1707 , 493.7364 , 1358.7687},
	{-831.9697 , 492.4239 , 1358.3234}, {-835.4655 , 497.3395 , 1358.2913}, {-833.3306 , 503.0268 , 1358.3120}, {-831.1613 , 508.6817 , 1358.2487}, {-825.7510 , 506.8079 , 1358.6447},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0},
	{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/lobby/lobby_arenadm.inc"
#include "includes/lobby/lobby_vehicles.inc"
#include "includes/lobby/lobby_menu.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
spawnPlayerInLobby(const &playerid) {
	new rand = random(g_LoadedLobbySpawns);
	ResetPlayerWeapons(playerid);
	SetPlayerHealth(playerid, 100.0);
	SetPlayerArmour(playerid, 0.0);
	SetPlayerVirtualWorld(playerid, VW_LOBBY);
	SetPlayerInterior(playerid, g_LobbyInterior);
	SetPlayerPos(playerid, g_LobbySpawnPos[rand][0], g_LobbySpawnPos[rand][1], g_LobbySpawnPos[rand][2]);
}
//------------------------------------------------------------------------------
loadLobbyPositions() {
	if(fexist(DIR_GENERAL)) {
	    new File:f_open;
	    new read[256];
	    if(!fexist(FILE_LOBBY)) {
            f_open = fopen(FILE_LOBBY, io_write);
            format(read, sizeof(read), "interior: %d", g_LobbyInterior), fwrite(f_open, read);
            for(new i; i < g_LoadedLobbySpawns; i ++) {
                format(read, sizeof(read), "\r\nposition: %.4f, %.4f, %.4f", g_LobbySpawnPos[i][0], g_LobbySpawnPos[i][1], g_LobbySpawnPos[i][2]);
				fwrite(f_open, read);
            }
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Lobby Positions", FILE_LOBBY);
	    } else {
			new readline = 1, index, length;
			new loadedInterior = -1, loadedSpawns, Float:loadedSpawnPositions[MAX_LOBBY_SPAWN][3];
			
			f_open = fopen(FILE_LOBBY, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				if(!isnull(read) && (((length = (strlen(read) - 1)) > (index = strfind(read, ":")) > 0) || (length > (index = strfind(read, "=")) > 0))) {
				    if(!strcmp(read, "interior", true, index)) {
						if(sscanf(read[index + 1], "d", loadedInterior) != 0) {
				            loadedInterior = -1;
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 0);
				            format(read, sizeof(read), read, FILE_LOBBY, readline);
							logMultiAD_Error(read);
				        }
				    } else if(!strcmp(read, "position", true, index)) {
				        if(loadedSpawns == MAX_LOBBY_SPAWN) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 2);
							format(read, sizeof(read), read, MAX_LOBBY_SPAWN, FILE_LOBBY, "position", readline);		
							logMultiAD_Error(read);
				        } else {
							if(sscanf(read[index + 1], "p<,>fff", loadedSpawnPositions[loadedSpawns][0], loadedSpawnPositions[loadedSpawns][1], loadedSpawnPositions[loadedSpawns][2]) != 0) {
								getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 1);
								format(read, sizeof(read), read, FILE_LOBBY, "position", readline);							
								logMultiAD_Error(read);
								loadedSpawnPositions[loadedSpawns][0] = loadedSpawnPositions[loadedSpawns][1] = loadedSpawnPositions[loadedSpawns][2] = -99999.0;
							} else loadedSpawns ++;	
					    }
					}
				}
				readline ++;
			}

			if(loadedInterior != -1) g_LobbyInterior = loadedInterior;
			if(loadedSpawns > 0) {
			    g_LoadedLobbySpawns = loadedSpawns;			    
			    for(new i; i < MAX_LOBBY_SPAWN; i ++) {
			        if(i < loadedSpawns) {
			        	g_LobbySpawnPos[i][0] = loadedSpawnPositions[i][0];
			        	g_LobbySpawnPos[i][1] = loadedSpawnPositions[i][1];
			        	g_LobbySpawnPos[i][2] = loadedSpawnPositions[i][2];
					} else {
			        	g_LobbySpawnPos[i][0] = g_LobbySpawnPos[i][1] = g_LobbySpawnPos[i][2] = 0.0;
					}
			    }
			}
		}
		fclose(f_open);
		return 1;
	}
	return 0;
}