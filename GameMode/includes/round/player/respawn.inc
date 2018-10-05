/*
	Optymalizacja - 3 września 2014
*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define resetPlayerRespawnTime(%1) 		g_Player_Respawn_Time[%1] = 0
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Player_Respawn_Time[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
respawnPlayer(&playerid) {
	
	if(GetPlayerState(playerid) != PLAYER_STATE_WASTED && !IsPlayerInAnyVehicle(playerid) && !isPlayerSwimming(playerid) && !isPlayerUsingParachute(playerid) && (!isPlayerFalling(playerid) || syncInFall())) {
		if((NetStats_GetConnectedTime(playerid) - g_Player_Respawn_Time[playerid]) < 1000) return -1;
		if(getRoundPauseStatus() && getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) return 0;
		
		new Float:position[4], Float:health, Float:armour, weapons[12], ammo[12], current_weapon, interior, virtual_world, index;
		GetPlayerPos(playerid, position[0], position[1], position[2]);
		
		for(new teamid = getPlayerTeam(playerid); index < MAX_PLAYERS; index ++) {
			if(IsPlayerConnected(index) && getPlayerTeam(index) != teamid) {
				if(IsPlayerInRangeOfPoint(index, 2.0, position[0], position[1], position[2])) return -2;
			}
		}
		
		GetPlayerFacingAngle(playerid, position[3]);
		GetPlayerHealth(playerid, health);
		GetPlayerArmour(playerid, armour);
		interior = GetPlayerInterior(playerid);
		virtual_world = GetPlayerVirtualWorld(playerid);
		current_weapon = GetPlayerWeapon(playerid);
		for(index = 0; index < 12; index ++) GetPlayerWeaponData(playerid, index, weapons[index], ammo[index]);		
		g_Player_Respawn_Time[playerid] = NetStats_GetConnectedTime(playerid);
		
		SetSpawnInfo(playerid, GetPlayerTeam(playerid), GetPlayerSkin(playerid), position[0], position[1], position[2], position[3], 0, 0, 0, 0, 0, 0);
		SpawnPlayer(playerid);

		SetPlayerInterior(playerid, interior);
		SetPlayerVirtualWorld(playerid, virtual_world);
		SetPlayerHealth(playerid, health);
		SetPlayerArmour(playerid, armour);
		for(index = 0; index < 12; index ++) GivePlayerWeapon(playerid, weapons[index], ammo[index]);
		SetPlayerArmedWeapon(playerid, current_weapon);
		
		if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
			for(index = 0; index < MAX_PLAYERS; index ++) {
				if(IsPlayerConnected(index) && getPlayerStatus(index) == PLAYER_STATUS_SPECTATE && getPlayerSpecID(index) == playerid) {
					SetTimerEx("startSpectate", 300, 0, "dd", index, playerid);
				}
			}		
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
checkSyncKeys(&newkeys, &oldkeys) return ((newkeys & KEY_JUMP && newkeys & KEY_HANDBRAKE) && (!(oldkeys & KEY_JUMP) || !(oldkeys & KEY_HANDBRAKE))) ? 1 : 0;
//------------------------------------------------------------------------------