/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define SP_NON							0
//#define SP_ANTI_KILL					1
#define SP_ANTI_FALL					1
#define SP_FIRST_BLOOD					2
#define SP_ANTI_FALL_AUTO_ADD			4
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_SpawnProtect_Flag = SP_FIRST_BLOOD + SP_ANTI_FALL;
new g_SpawnProtect_Setting_Time = 20;
new g_SpawnProtect_A_Setting_Time = 5;
new g_SpawnProtect_Time;
new g_SpawnProtect_FBlood_Player = INVALID_PLAYER_ID;
new g_SpawnProtect_Plr_GodMode_Time[MAX_PLAYERS];
new bool:g_SpawnProtect_FallDeath[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setPlayerFallDeathStatus(playerid, bool:status) g_SpawnProtect_FallDeath[playerid] = status;
getPlayerFallDeathStatus(playerid) return _:g_SpawnProtect_FallDeath[playerid];
//------------------------------------------------------------------------------
givePlayerGodMode(&playerid) {
	g_SpawnProtect_Plr_GodMode_Time[playerid] = gettime() + 3;
	SetPlayerHealth(playerid, 99999.0);
	return 1;
}
//------------------------------------------------------------------------------
removePlayerGodMode(&playerid) {
	SetPlayerHealth(playerid, 100.0);
	g_SpawnProtect_Plr_GodMode_Time[playerid] = 0;
}
//------------------------------------------------------------------------------
getPlayerGodModeTime(&playerid) return g_SpawnProtect_Plr_GodMode_Time[playerid];
//------------------------------------------------------------------------------
checkPlayerGodModeTime(&playerid) {
	if(g_SpawnProtect_Plr_GodMode_Time[playerid] != 0 && g_SpawnProtect_Plr_GodMode_Time[playerid] <= gettime()) {
		removePlayerGodMode(playerid);
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
setSpawnProtectSettingTime(time) {
	if(120 >= time >= 0) {
		g_SpawnProtect_Setting_Time = time;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getArenaSpawnProtectSettingTime() return g_SpawnProtect_A_Setting_Time;
setArenaSpawnProtectSettingTime(time) {
	if(120 >= time >= 0) {
		g_SpawnProtect_A_Setting_Time = time;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
addSpawnProtectFlag(flag) {
	if(SP_ANTI_FALL_AUTO_ADD >= flag >= SP_ANTI_FALL && !(g_SpawnProtect_Flag & flag)) g_SpawnProtect_Flag += flag;
}
//------------------------------------------------------------------------------
removeSpawnProtectFlag(flag) {
	if(SP_ANTI_FALL_AUTO_ADD >= flag >= SP_ANTI_FALL && g_SpawnProtect_Flag & flag) g_SpawnProtect_Flag -= flag;
}
//------------------------------------------------------------------------------
getSpawnProtectSettingTime() return g_SpawnProtect_Setting_Time;
//------------------------------------------------------------------------------
getSpawnProtectTime() return g_SpawnProtect_Time;
resetSpawnProtectTime() g_SpawnProtect_Time = 0;
//------------------------------------------------------------------------------
getSpawnProtectFlags() return g_SpawnProtect_Flag;
//------------------------------------------------------------------------------
getFirstBloodPlayer() return g_SpawnProtect_FBlood_Player;
//------------------------------------------------------------------------------
resetFirstBloodPlayer() {
	g_SpawnProtect_FBlood_Player = INVALID_PLAYER_ID;
	return 1;
}
//------------------------------------------------------------------------------
setSpawnProtectFlags(flag) {
	if(7 >= flag >= 0) {
		g_SpawnProtect_Flag = flag;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
spawnProtectStart() {
	if(getRoundState() == ROUND_STATE_REMAIN) {
		new string[24];
		g_SpawnProtect_FBlood_Player = INVALID_PLAYER_ID;	
		g_SpawnProtect_Time = ((getRoundType() == ROUND_TYPE_BASE) ? getSpawnProtectSettingTime() : getArenaSpawnProtectSettingTime());
		format(string, sizeof(string), "Spawn Protect ~w~%d", g_SpawnProtect_Time);
		TextDrawSetString(TD_SpawnProtect, string);
		forplayers(i) spawnProtectForPlayer(i);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
spawnProtectForPlayer(&playerid) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		if(g_SpawnProtect_Time > 0) {
			SetPlayerTeam(playerid, GLOBAL_TEAM);
		} else {
			SetPlayerTeam(playerid, getPlayerTeam(playerid));
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
checkSpawnProtectTime() {
	if(g_SpawnProtect_Time > 0) {
		if(!getRoundPauseStatus() && (-- g_SpawnProtect_Time) == 0) {
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
					SetPlayerTeam(i, getPlayerTeam(i));
				}
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
antiFallProtect(&playerid, &weaponid) {
	if((g_SpawnProtect_Time > 0 || (g_SpawnProtect_FBlood_Player == INVALID_PLAYER_ID && g_SpawnProtect_Flag & SP_FIRST_BLOOD)) && (g_SpawnProtect_Flag & SP_ANTI_FALL) && weaponid == 54) {
		SetPlayerHealth(playerid, 100.0);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
antiFallPlayerDeath(&playerid, &reason) {
	if(g_SpawnProtect_Flag & SP_ANTI_FALL && g_SpawnProtect_Flag & SP_ANTI_FALL_AUTO_ADD && (g_SpawnProtect_Time > 0 || (g_SpawnProtect_FBlood_Player == INVALID_PLAYER_ID && g_SpawnProtect_Flag & SP_FIRST_BLOOD)) && reason == 54) {
		//addPlayerToRound(playerid);
		g_SpawnProtect_FallDeath[playerid] = true;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
checkFirstBloodPlayer(playerid, issuerid) {
	if(g_SpawnProtect_Time == 0 && (g_SpawnProtect_Flag & SP_FIRST_BLOOD) && g_SpawnProtect_FBlood_Player == INVALID_PLAYER_ID && issuerid != INVALID_PLAYER_ID && getPlayerStatus(issuerid) == PLAYER_STATUS_IN_ROUND) {
		g_SpawnProtect_FBlood_Player = playerid;
		TextDrawHideForAll(TD_Round_First_Blood);
		return 1;
	}
	return 0;
}
