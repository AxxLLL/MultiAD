/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
enum WorLD_AREA {bool:ENABLED, GANGZONE, OBJECT_ID, PROTECT_TIME, Float:X, Float:Y, Float:Z, Float:ZONE_MIN_X, Float:ZONE_MAX_X, Float:ZONE_MIN_Y, Float:ZONE_MAX_Y, Float:ZONE_MIN_Z, Float:ZONE_MAX_Z}
new Float:P_WorldArea[MAX_PLAYERS][WorLD_AREA];
//------------------------------------------------------------------------------
setPlayerWorldArea(&playerid, Float:min_x, Float:max_x, Float:min_y, Float:max_y, Float:min_z, Float:max_z, bool:gangzone = false, gangzone_color = 0x0474CE50, gangzone_flash = -1) {
	if(min_x < max_x and min_y < max_y and min_z < max_z) {
		if(P_WorldArea[playerid][ENABLED] == true) {
			if(P_WorldArea[playerid][GANGZONE] != INVALID_GANG_ZONE) {
				GangZoneDestroy(P_WorldArea[playerid][GANGZONE]);
				P_WorldArea[playerid][GANGZONE] = INVALID_GANG_ZONE;
			}
		}
		if(P_WorldArea[playerid][OBJECT_ID] != INVALID_OBJECT_ID) {
			DestroyPlayerObject(playerid, P_WorldArea[playerid][OBJECT_ID]);
			P_WorldArea[playerid][OBJECT_ID] = INVALID_OBJECT_ID;
		}
		P_WorldArea[playerid][ZONE_MIN_X] = min_x, P_WorldArea[playerid][ZONE_MAX_X] = max_x;
		P_WorldArea[playerid][ZONE_MIN_Y] = min_y, P_WorldArea[playerid][ZONE_MAX_Y] = max_y;
		P_WorldArea[playerid][ZONE_MIN_Z] = min_z, P_WorldArea[playerid][ZONE_MAX_Z] = max_z;
		if(gangzone == true) {
			if((P_WorldArea[playerid][GANGZONE] = GangZoneCreate(min_x, min_y, max_x, max_y)) != INVALID_GANG_ZONE) {
				GangZoneShowForPlayer(playerid, P_WorldArea[playerid][GANGZONE], gangzone_color);
				if(gangzone_flash != -1) {
					GangZoneFlashForPlayer(playerid, P_WorldArea[playerid][GANGZONE], gangzone_flash);
				}
			}
		}
		P_WorldArea[playerid][PROTECT_TIME] = gettime() + 2;
		P_WorldArea[playerid][ENABLED] = true;
		return 1;		
	}
	return 0;
}
//------------------------------------------------------------------------------
deletePlayerWorldArea(&playerid) {
	if(P_WorldArea[playerid][ENABLED] == true) {
		if(P_WorldArea[playerid][GANGZONE] != INVALID_GANG_ZONE) {
			GangZoneDestroy(P_WorldArea[playerid][GANGZONE]);
			P_WorldArea[playerid][GANGZONE] = INVALID_GANG_ZONE;
		}		
		if(P_WorldArea[playerid][OBJECT_ID] != INVALID_OBJECT_ID) {
			DestroyPlayerObject(playerid, P_WorldArea[playerid][OBJECT_ID]);
			P_WorldArea[playerid][OBJECT_ID] = INVALID_OBJECT_ID;
		}
		P_WorldArea[playerid][ZONE_MIN_X] = -9999.0, P_WorldArea[playerid][ZONE_MAX_X] = 9999.0;
		P_WorldArea[playerid][ZONE_MIN_Y] = -9999.0, P_WorldArea[playerid][ZONE_MAX_Y] = 9999.0;
		P_WorldArea[playerid][ZONE_MIN_Z] = -9999.0, P_WorldArea[playerid][ZONE_MAX_Z] = 9999.0;	
		P_WorldArea[playerid][PROTECT_TIME] = 0;
		P_WorldArea[playerid][ENABLED] = false;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
checkPlayerZonePosition(&playerid, &Float:x, &Float:y, &Float:z) {	
	if(P_WorldArea[playerid][OBJECT_ID] != INVALID_OBJECT_ID) {
		DestroyPlayerObject(playerid, P_WorldArea[playerid][OBJECT_ID]);
		P_WorldArea[playerid][OBJECT_ID] = INVALID_OBJECT_ID;
	}		
	
	if(getPlayerFPS(playerid) != 0) {
		if(P_WorldArea[playerid][ENABLED] == true) {
			if(gettime() > P_WorldArea[playerid][PROTECT_TIME] ) {
				if(!(P_WorldArea[playerid][ZONE_MIN_X] <= x <= P_WorldArea[playerid][ZONE_MAX_X] and P_WorldArea[playerid][ZONE_MIN_Y] <= y <= P_WorldArea[playerid][ZONE_MAX_Y] and P_WorldArea[playerid][ZONE_MIN_Z] <= z <= P_WorldArea[playerid][ZONE_MAX_Z])) {	
					if(P_WorldArea[playerid][ZONE_MIN_X] <= P_WorldArea[playerid][X] <= P_WorldArea[playerid][ZONE_MAX_X] and P_WorldArea[playerid][ZONE_MIN_Y] <= P_WorldArea[playerid][Y] <= P_WorldArea[playerid][ZONE_MAX_Y] and P_WorldArea[playerid][ZONE_MIN_Z] <= P_WorldArea[playerid][Z] <= P_WorldArea[playerid][ZONE_MAX_Z]) {
						if(z <= P_WorldArea[playerid][ZONE_MIN_Z] || P_WorldArea[playerid][Z] <= -90.0) {							
							backToSpawnByTeam(playerid, 0);
						} else {
							if(z >= 5000) {
								P_WorldArea[playerid][PROTECT_TIME] = gettime() + 2;
								backToSpawnByTeam(playerid, 0);							
							} else {
								SetPlayerPos(playerid, P_WorldArea[playerid][X], P_WorldArea[playerid][Y], P_WorldArea[playerid][Z]);				
								P_WorldArea[playerid][OBJECT_ID] = CreatePlayerObject(playerid, 18724, x, y, z - 1.2, 0, 0, 0, 5);
							}
						}
					} else {
						P_WorldArea[playerid][PROTECT_TIME] = gettime() + 2;
						backToSpawnByTeam(playerid, 1);						
					}
					return 1;
				} else {
					if(z >= 5000) {
						P_WorldArea[playerid][PROTECT_TIME] = gettime() + 2;
						backToSpawnByTeam(playerid, 0);					
						return 1;
					}
				}
				P_WorldArea[playerid][X] = x;
				P_WorldArea[playerid][Y] = y;
				P_WorldArea[playerid][Z] = z;					
			}
		}		
	} else P_WorldArea[playerid][PROTECT_TIME] = gettime() + 2;
	return 1;
}
//------------------------------------------------------------------------------
