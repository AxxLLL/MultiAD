/*
	!!! Sprawdzic numerowanie objektow gracza wzgledem obiektow globalnych !!!
	!!! Sprawdzic numerowanie stref gangow !!!
*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
enum G_PLAYER_DEMO {PD_MAP_ID, PD_MAP_TYPE, PD_START_OBJECT_ID, PD_END_OBJECT_ID, PD_GANG_ZONE_ID, PD_VIRTUAL_WORLD, PD_INTERIOR, Float:PD_TEAM_ONE_SPAWN[5], Float:PD_TEAM_TWO_SPAWN[5], Float:PD_ARENA_ZONE[6], Float:PD_CHECKPOINT_POS[3], Float:PD_BOAT_SPAWN[5]}
new g_Player_Demo[MAX_PLAYERS][G_PLAYER_DEMO];
//==============================================================================
stock startDemoForPlayer(&playerid, mapid, roundtype, invite_playerid = INVALID_PLAYER_ID) { //virtualworld: jezeli -1 wtedy ustawiane jest losowe ID virtualnego swiata
	if(getPlayerStatus(playerid) == PLAYER_STATUS_DEMO || getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY) {
		//------------------
		stopDemoForPlayer(playerid, false);
		destroyPlayerLobbyVehicle(playerid);
		hidePlayerDialog(playerid);
		
		if(!IsPlayerConnected(invite_playerid) || getPlayerStatus(invite_playerid) != PLAYER_STATUS_DEMO) invite_playerid = INVALID_PLAYER_ID;
		//------------------
		if(loadDemoArenaData(playerid, mapid, roundtype, invite_playerid)) {		
			if(invite_playerid != INVALID_PLAYER_ID) {
				g_Player_Demo[playerid][PD_VIRTUAL_WORLD] = ((invite_playerid != INVALID_PLAYER_ID) ? g_Player_Demo[invite_playerid][PD_VIRTUAL_WORLD] : (VW_DEMO_ARENA_START + random(VW_DEMO_ARENA_LIMIT)));
			}
			
			if(roundtype == ROUND_TYPE_ARENA) {
				if(9999.0 >= g_Player_Demo[playerid][PD_ARENA_ZONE][0] >= -9999.0) {
					setPlayerWorldArea(playerid, g_Player_Demo[playerid][PD_ARENA_ZONE][0], g_Player_Demo[playerid][PD_ARENA_ZONE][2], g_Player_Demo[playerid][PD_ARENA_ZONE][1], g_Player_Demo[playerid][PD_ARENA_ZONE][3], g_Player_Demo[playerid][PD_ARENA_ZONE][4], g_Player_Demo[playerid][PD_ARENA_ZONE][5], true, 0xFF686850);
				}	
			} else {
				SetPlayerCheckpoint(playerid, g_Player_Demo[playerid][PD_CHECKPOINT_POS][0], g_Player_Demo[playerid][PD_CHECKPOINT_POS][1], g_Player_Demo[playerid][PD_CHECKPOINT_POS][2], CP_Size() * 2.0);
				GangZoneShowForPlayer(playerid, g_Player_Demo[playerid][PD_GANG_ZONE_ID], 0x6868FF90);
				SetPlayerMapIcon(playerid, ICON_ROUND_SPAWN, g_Player_Demo[playerid][PD_TEAM_ONE_SPAWN][0], g_Player_Demo[playerid][PD_TEAM_ONE_SPAWN][1], g_Player_Demo[playerid][PD_TEAM_ONE_SPAWN][2], 6, 0, MAPICON_GLOBAL);
				SetPlayerMapIcon(playerid, ICON_ROUND_SPAWN, g_Player_Demo[playerid][PD_CHECKPOINT_POS][0], g_Player_Demo[playerid][PD_CHECKPOINT_POS][1], g_Player_Demo[playerid][PD_CHECKPOINT_POS][2], 19, 0, MAPICON_GLOBAL);

				if(g_Player_Demo[playerid][PD_BOAT_SPAWN][0] != -99999.0) {
					SetPlayerMapIcon(playerid, ICON_ROUND_BOATS, g_Player_Demo[playerid][PD_BOAT_SPAWN][0], g_Player_Demo[playerid][PD_BOAT_SPAWN][1], g_Player_Demo[playerid][PD_BOAT_SPAWN][2], 9, 0, MAPICON_GLOBAL);
				}
			}
			
			SetPlayerTeam(playerid, NO_TEAM);
			SetPlayerHealth(playerid, 100.0);
			SetPlayerArmour(playerid, 0.0);
			ResetPlayerWeapons(playerid);
		
		} else {
			//Mozna dodac wysylanie powiadomienia o niepowodzeniu
			if(getPlayerStatus(playerid) != PLAYER_STATUS_LOBBY) {
				setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
				SpawnPlayer(playerid);			
			}
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
stock stopDemoForPlayer(&playerid, bool:changestate = true) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_DEMO) {
		new bool:use;
		
		for(new i = g_Player_Demo[playerid][PD_START_OBJECT_ID]; i < g_Player_Demo[playerid][PD_END_OBJECT_ID]; i ++) {
			DestroyPlayerObject(playerid, i);
		}
		
		forplayers(i) {
			if(i != playerid && getPlayerStatus(i) == PLAYER_STATUS_DEMO && GetPlayerVirtualWorld(i) == g_Player_Demo[playerid][PD_VIRTUAL_WORLD]) {
				use = true;
				break;
			}
		}
		if(!use) {
			GangZoneDestroy(g_Player_Demo[playerid][PD_GANG_ZONE_ID]);
		} else {
			GangZoneHideForPlayer(playerid, g_Player_Demo[playerid][PD_GANG_ZONE_ID]);					
		}
		
		DisablePlayerCheckpoint(playerid);
		destroyPlayerLobbyVehicle(playerid);
		RemovePlayerMapIcon(playerid, ICON_ROUND_FLAG);
		RemovePlayerMapIcon(playerid, ICON_ROUND_SPAWN);
		RemovePlayerMapIcon(playerid, ICON_ROUND_BOATS);
		RemovePlayerMapIcon(playerid, ICON_ROUND_HELP);
		hidePlayerDialog(playerid);
		deletePlayerWorldArea(playerid);
		SetPlayerTeam(playerid, GLOBAL_TEAM);
		
		g_Player_Demo[playerid][PD_MAP_ID] = 0;
		g_Player_Demo[playerid][PD_START_OBJECT_ID] = 0;
		g_Player_Demo[playerid][PD_END_OBJECT_ID] = 0;
		g_Player_Demo[playerid][PD_VIRTUAL_WORLD] = 0;
		g_Player_Demo[playerid][PD_INTERIOR] = 0;
		g_Player_Demo[playerid][PD_GANG_ZONE_ID] = INVALID_GANG_ZONE;
		
		for(new i; i < 6; i ++) {
			if(i < 3) g_Player_Demo[playerid][PD_CHECKPOINT_POS][i] = 0.0;
			if(i < 5) {
				g_Player_Demo[playerid][PD_TEAM_ONE_SPAWN][i] = 0.0;
				g_Player_Demo[playerid][PD_TEAM_TWO_SPAWN][i] = 0.0;
				g_Player_Demo[playerid][PD_BOAT_SPAWN][i] = 0.0;
			}
			g_Player_Demo[playerid][PD_ARENA_ZONE][i] = 0.0;
		}
		
		if(changestate) {
			setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
			SpawnPlayer(playerid);
		}
		return 1;
	}
	return 0;
}
//==============================================================================
stock loadDemoArenaData(&playerid, &mapid, &roundtype, &invite_playerid) {
	new string[256];
	format(string, sizeof(string), "%s/%d.ini", roundtype == ROUND_TYPE_ARENA ? (DIR_ARENAS) : (DIR_BASES), mapid);
	if(fexist(string)) {
		if(invite_playerid != INVALID_PLAYER_ID) {
			g_Player_Demo[playerid][PD_INTERIOR] = g_Player_Demo[invite_playerid][PD_INTERIOR];
			g_Player_Demo[playerid][PD_GANG_ZONE_ID] = g_Player_Demo[invite_playerid][PD_GANG_ZONE_ID];
			for(new i; i < 6; i ++) {
				if(i < 3) g_Player_Demo[playerid][PD_CHECKPOINT_POS][i] = g_Player_Demo[invite_playerid][PD_CHECKPOINT_POS][i];
				if(i < 5) {
					g_Player_Demo[playerid][PD_TEAM_ONE_SPAWN][i] = g_Player_Demo[invite_playerid][PD_TEAM_ONE_SPAWN][i];
					g_Player_Demo[playerid][PD_TEAM_TWO_SPAWN][i] = g_Player_Demo[invite_playerid][PD_TEAM_TWO_SPAWN][i];
					g_Player_Demo[playerid][PD_BOAT_SPAWN][i] = g_Player_Demo[invite_playerid][PD_BOAT_SPAWN][i];
				}
				g_Player_Demo[playerid][PD_ARENA_ZONE][i] = g_Player_Demo[invite_playerid][PD_ARENA_ZONE][i];
			}
			
			
		} else {
			
		}
		return 1;
	}
	return 0;
}