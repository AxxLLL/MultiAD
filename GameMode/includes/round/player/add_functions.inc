/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Round_RandomKey[MAX_PLAYERS];
new g_Player_Round_AddTime[MAX_PLAYERS];
//==============================================================================
addPlayerToRound(&playerid, bool:force = false, bool:endcountdown = false, bool:showgunmenu = true) {
	new teamid;
	if((getRoundState() == ROUND_STATE_REMAIN || endcountdown) && getPlayerStatus(playerid) != PLAYER_STATUS_REQUEST_CLASS && TEAM_TWO >= (teamid = getPlayerTeam(playerid)) >= TEAM_ONE && (force == true || !getPlayerAFKMode(playerid)) && GetPlayerState(playerid) != PLAYER_STATE_WASTED) {	
		if(stopSpectate(playerid) == 0) {
			if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
			else if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING) TogglePlayerSpectating(playerid, false);
		}
		
		if(g_Player_Round_RandomKey[playerid] != g_Round_RandomKey) {
			g_Player_Round_RandomKey[playerid] = g_Round_RandomKey;
			resetPlayerRoundStats(playerid);
		}		
		
		if(getMatchStatus()) setPlayerMatchRandomID(playerid, getMatchRandomKey());
		
		stopDemoForPlayer(playerid, false);
		hidePlayerDialog(playerid);
		setPlayerAFKMode(playerid, false);
		SetPlayerHealth(playerid, 100.0);
		SetPlayerArmour(playerid, getRoundArmour());		
		ResetPlayerWeapons(playerid);
		SetPlayerColor(playerid, (getTeamColorInt(teamid, COLOR_STATUS_ACTIVE) & 0xFFFFFF00));				
		g_Player_Round_AddTime[playerid] = gettime();
		setPlayerInRoundPosition(playerid);
		
		if(getRoundType() == ROUND_TYPE_ARENA) {		
			if(9999.0 >= getZonePosition(0) >= -9999.0) {
				setPlayerWorldArea(playerid, getZonePosition(0), getZonePosition(2), getZonePosition(1), getZonePosition(3), getZonePosition(4), getZonePosition(5), true, 0xFF686850);
			}
		} else {
			GangZoneShowForPlayer(playerid, g_Round_GangZones[0], (getDefendingTeam() == TEAM_ONE ? 0x6868FF90 : 0xFF686850));
			SetPlayerMapIcon(playerid, ICON_ROUND_SPAWN, g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_Z], 6, 0, MAPICON_GLOBAL);
			SetPlayerMapIcon(playerid, ICON_ROUND_FLAG, CP_Position(0), CP_Position(1), CP_Position(2), 19, 0, MAPICON_GLOBAL);
			SetPlayerCheckpoint(playerid, CP_Position(0), CP_Position(1), CP_Position(2), CP_Size() * 2.0);
			if(getBoatSpawnPosition(SPAWN_X) != -99999.0) {
				SetPlayerMapIcon(playerid, ICON_ROUND_BOATS, getBoatSpawnPosition(SPAWN_X), getBoatSpawnPosition(SPAWN_Y), getBoatSpawnPosition(SPAWN_Z), 9, 0, MAPICON_GLOBAL);
			}
			if(g_Round_GangZones[1] != -1 && getDefendersBaseStatus()) {
				GangZoneShowForPlayer(playerid, g_Round_GangZones[1], (getDefendingTeam() == TEAM_ONE ? 0xFF686850 : 0x6868FF90));			
			}
		}
		setPlayerStatus(playerid, PLAYER_STATUS_IN_ROUND);		
		spawnProtectForPlayer(playerid);

		if(GetPlayerState(playerid) != PLAYER_STATE_SPECTATING && showgunmenu == true) showPlayerRoundWeaponSelectMenu(playerid);

		pauseForPlayer(playerid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
removePlayerFromFight(&playerid, bool:spawn = true) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {	
		new bool:invehicle;
		deletePlayerWorldArea(playerid);
		if(IsPlayerInAnyVehicle(playerid)) {
			RemovePlayerFromVehicle(playerid);
			invehicle = true;
			spawn = false;
		}
	
		removePlayerRoundWeapons(playerid);		
		DisablePlayerCheckpoint(playerid);
		hidePlayerDialog(playerid);
		RemovePlayerMapIcon(playerid, ICON_ROUND_FLAG);
		RemovePlayerMapIcon(playerid, ICON_ROUND_SPAWN);
		RemovePlayerMapIcon(playerid, ICON_ROUND_BOATS);
		RemovePlayerMapIcon(playerid, ICON_ROUND_HELP);
		GangZoneHideForPlayer(playerid, g_Round_GangZones[0]);
		GangZoneHideForPlayer(playerid, g_Round_GangZones[1]);		
		SetPlayerArmour(playerid, 0.0);
		SetPlayerColor(playerid, getTeamColorInt(getPlayerTeam(playerid), COLOR_STATUS_DEATH));	
		SetPlayerTeam(playerid, GLOBAL_TEAM);
		SetPlayerVirtualWorld(playerid, VW_LOBBY);
		setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
		if(spawn) SpawnPlayer(playerid);
		if(invehicle) {
			spawnPlayerInLobby(playerid);
			SpawnPlayer(playerid);
		}
		
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
backToSpawnByTeam(&playerid, reason) {
	static string[128];
	if(getPlayerTeam(playerid) != getDefendingTeam()) SetPlayerPos(playerid, circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_VX]), circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_VY]), g_Round_Data[SPAWN_TEAM_1][SPAWN_Z]);
	else SetPlayerPos(playerid, circleVariation(g_Round_Data[SPAWN_TEAM_2][SPAWN_X], g_Round_Data[SPAWN_TEAM_2][SPAWN_VX]), circleVariation(g_Round_Data[SPAWN_TEAM_2][SPAWN_Y], g_Round_Data[SPAWN_TEAM_2][SPAWN_VY]), g_Round_Data[SPAWN_TEAM_2][SPAWN_Z]);

	getChatMessage(string, CHAT_MESSAGE_ZONE_ERROR, reason);
	format(string, sizeof(string), string, getPlayerName(playerid));
	SendClientMessageToAll(COLOR_INFO_1, string);		
}
//------------------------------------------------------------------------------
setPlayerInRoundPosition(&playerid) {
	SetPlayerInterior(playerid, g_Round_Data[INTERIOR]);
	SetPlayerVirtualWorld(playerid, VW_ROUND);	
	
	if(getRoundType() == ROUND_TYPE_ARENA) SetPlayerFacingAngle(playerid, getRoundArenaFacingAngle( (getDefendingTeam() == TEAM_TWO ? getPlayerTeam(playerid) : (getPlayerTeam(playerid) == TEAM_ONE ? TEAM_TWO : TEAM_ONE)) ));
	if(getPlayerTeam(playerid) != getDefendingTeam()) SetPlayerPos(playerid, circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_X], g_Round_Data[SPAWN_TEAM_1][SPAWN_VX]), circleVariation(g_Round_Data[SPAWN_TEAM_1][SPAWN_Y], g_Round_Data[SPAWN_TEAM_1][SPAWN_VY]), g_Round_Data[SPAWN_TEAM_1][SPAWN_Z]);
	else SetPlayerPos(playerid, circleVariation(g_Round_Data[SPAWN_TEAM_2][SPAWN_X], g_Round_Data[SPAWN_TEAM_2][SPAWN_VX]), circleVariation(g_Round_Data[SPAWN_TEAM_2][SPAWN_Y], g_Round_Data[SPAWN_TEAM_2][SPAWN_VY]), g_Round_Data[SPAWN_TEAM_2][SPAWN_Z]);	
}
//------------------------------------------------------------------------------
getPlayerRoundKey(&playerid) return g_Player_Round_RandomKey[playerid];
//------------------------------------------------------------------------------
setPlayerRoundRandomKey(&playerid, value) {
	g_Player_Round_RandomKey[playerid] = value;
}
//------------------------------------------------------------------------------
getPlayerAddTime(&playerid) return g_Player_Round_AddTime[playerid];