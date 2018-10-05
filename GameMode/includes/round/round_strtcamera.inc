/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_StartTimerID = -1;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerStartingCamera(&playerid) {
	if(getPlayerTeam(playerid) != TEAM_NON) {
		setPlayerStatus(playerid, PLAYER_STATUS_STARTING_CAMERA);
		if(IsPlayerInAnyVehicle(playerid)) RemovePlayerFromVehicle(playerid);
		if(GetPlayerState(playerid) == PLAYER_STATE_WASTED) SpawnPlayer(playerid);
		else if(GetPlayerState(playerid) == PLAYER_STATE_SPECTATING) TogglePlayerSpectating(playerid, false);
		SetPlayerHealth(playerid, 100.0);
		SetPlayerArmour(playerid, 0.0);
		ResetPlayerWeapons(playerid);
		TogglePlayerSpectating(playerid, true);	
		SetTimerEx("StartingCameraStart", 50, 0, "d", playerid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
forward StartingCameraStart(playerid);
public StartingCameraStart(playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_STARTING_CAMERA) {	
		SetPlayerInterior(playerid, g_Round_Data[INTERIOR]);
		SetPlayerVirtualWorld(playerid, VW_ROUND);
		SetPlayerCheckpoint(playerid, g_Round_Data[CHECKPOINT][0], g_Round_Data[CHECKPOINT][1], g_Round_Data[CHECKPOINT][2], CP_Size() * 2.0);
		SetPlayerCameraPos(playerid, g_Round_StartingCamera[0][0], g_Round_StartingCamera[0][1], g_Round_StartingCamera[0][2]);
		SetPlayerCameraLookAt(playerid, g_Round_Data[CHECKPOINT][0], g_Round_Data[CHECKPOINT][1], g_Round_Data[CHECKPOINT][2]);
		showPlayerRoundStartTextdraws(playerid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
stopPlayerStartingCamera(&playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_STARTING_CAMERA) {
		setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
		TogglePlayerSpectating(playerid, false);
		hidePlayerRoundStartTextdraws(playerid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
forward StartRoundCountdown(time);
public StartRoundCountdown(time) {
	if(g_Round_MapID != INVALID_MAP_ID) {
		if((-- time) == 0) {
			g_Round_StartTimerID = -1;
			forplayers(i) {
				if(stopPlayerStartingCamera(i)) PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
				DisablePlayerCheckpoint(i);
				addPlayerToRound(i, false, true);
			}		
			setRoundState(ROUND_STATE_REMAIN);
		} else {
			new index;
			if(!(MAX_CAMERA_POSITIONS > (index = ROUND_COUNTDOWN_TIME - time) >= 0)) index = 0;
			
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_STARTING_CAMERA) {
					PlayerPlaySound(i, 1138, 0.0, 0.0, 0.0);					
					SetPlayerCameraPos(i, g_Round_StartingCamera[index][0], g_Round_StartingCamera[index][1], g_Round_StartingCamera[index][2]);
					SetPlayerCameraLookAt(i, g_Round_Data[CHECKPOINT][0], g_Round_Data[CHECKPOINT][1], g_Round_Data[CHECKPOINT][2]);
				}
			}
			g_Round_StartTimerID = SetTimerEx("StartRoundCountdown", 700, 0, "d", time);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------	
killRoundStartTimer() {
	if(g_Round_StartTimerID != -1) {
		KillTimer(g_Round_StartTimerID);
		g_Round_StartTimerID = -1;
		return 1;
	}
	return 0;
}