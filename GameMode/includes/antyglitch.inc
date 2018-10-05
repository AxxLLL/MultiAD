/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define MAX_GLITCH_TIME                     500
//------------------------------------------------------------------------------
#define AG_PUNISHMENT_HANDS_UP				0
#define AG_PUNISHMENT_FIRING_UP				1
//------------------------------------------------------------------------------
#define resetPlayerGlitchPunishment(%1)		g_Glitch_Player_Punishment[%1] = false
#define glitchSlideBugCheck()				g_AntyGlitch_SlideBug
#define glitchFastShootCheck()				g_AntyGlitch_FastShoot
#define glitchCBugCheck()					g_AntyGlitch_CrouchBug
#define getAGPunishment()					g_AntyGlitch_Punishment
//------------------------------------------------------------------------------
#define GLITCH_REASON_SLIDEBUG				0
#define GLITCH_REASON_CBUG					1
#define GLITCH_REASON_ANTIMACRO				2
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_Glitch_Player_Punishment[MAX_PLAYERS];
new g_Glitch_Player_ShootTime[MAX_PLAYERS];
new g_Glitch_Player_OldCrouchTime[MAX_PLAYERS];
new g_Glitch_Player_OldIndex[MAX_PLAYERS];
new g_Glitch_Player_Macro_Time[MAX_PLAYERS];
new g_Glitch_Player_Macro_Warn[MAX_PLAYERS];
//------------------------------------------------------------------------------
new g_AntyGlitch_SlideBug = true;
new g_AntyGlitch_FastShoot = true;
new g_AntyGlitch_CrouchBug  = true;
new g_AntyGlitch_AntiMacro = true;
//------------------------------------------------------------------------------
new g_AntiMacro_Inputs_Warning = ANTI_MACRO_MAX_AVAILABLE_INPUTS;
new g_AntiMacro_Inputs_Critical = ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS;
new g_AntiMacro_Max_Warnings = ANTI_MACRO_MAX_WARNINGS;
//------------------------------------------------------------------------------
new g_AntyGlitch_Punishment = AG_PUNISHMENT_HANDS_UP;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getAntiMacroValue(type) {
	switch(type) {
		case ANTI_MACRO_MAX_AVAILABLE_INPUTS: return g_AntiMacro_Inputs_Warning;
		case ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS: return g_AntiMacro_Inputs_Critical;
		case ANTI_MACRO_MAX_WARNINGS: return g_AntiMacro_Max_Warnings;
	}
	return 0;
}
//------------------------------------------------------------------------------
setAntiMacroValue(type, value) {
	if(value > 0) {
		switch(type) {
			case ANTI_MACRO_MAX_AVAILABLE_INPUTS: {
				if(13 >= value >= 7) {
					g_AntiMacro_Inputs_Warning = value;
					return 1;
				}
			}
			case ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS: {
				if(99 >= value >= 14) {
					g_AntiMacro_Inputs_Critical = value;
					return 1;
				}
			}
			case ANTI_MACRO_MAX_WARNINGS: {
				if(10 >= value >= 1) {
					g_AntiMacro_Max_Warnings = value;
					return 1;
				}
			}
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
setAGPunishment(type) {
	if(AG_PUNISHMENT_HANDS_UP <= type <= AG_PUNISHMENT_FIRING_UP) {
		g_AntyGlitch_Punishment = type;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getGlitchStatus(glitchtype) {
	switch(glitchtype) {
		case GLITCH_SLIDE_BUG:	return g_AntyGlitch_SlideBug;
		case GLITCH_FAST_SHOOT:	return g_AntyGlitch_FastShoot;
		case GLITCH_CROUCH_BUG:	return g_AntyGlitch_CrouchBug;
		case GLITCH_ANTI_MACRO:	return g_AntyGlitch_AntiMacro;
	}
	return 0;
}
//------------------------------------------------------------------------------
setGlitchStatus(glitchtype, bool:enable) {
	switch(glitchtype) {
		case GLITCH_SLIDE_BUG:	g_AntyGlitch_SlideBug = enable;
		case GLITCH_FAST_SHOOT:	g_AntyGlitch_FastShoot = enable;
		case GLITCH_CROUCH_BUG:	g_AntyGlitch_CrouchBug = enable;
		case GLITCH_ANTI_MACRO:	g_AntyGlitch_AntiMacro = enable;
		default: return 0;
	}	
	return 1;
}
//------------------------------------------------------------------------------
glitchPlayerConnect(&playerid) {
    g_Glitch_Player_ShootTime[playerid] = 0;
    g_Glitch_Player_OldCrouchTime[playerid] = 0;
	g_Glitch_Player_OldIndex[playerid] = 0;
	g_Glitch_Player_Punishment[playerid] = false;
	g_Glitch_Player_Macro_Time[playerid] = 0;
	g_Glitch_Player_Macro_Warn[playerid] = 0;
}
//------------------------------------------------------------------------------
glitchKeyStateChange(&playerid, &newkeys, &oldkeys) {
	if(newkeys & KEY_CROUCH && !(oldkeys & KEY_CROUCH)) {
	    g_Glitch_Player_OldCrouchTime[playerid] = NetStats_GetConnectedTime(playerid);
	} else if(g_AntyGlitch_AntiMacro && (newkeys & KEY_SPRINT && !(oldkeys & KEY_SPRINT))) {
		static system_Counter[MAX_PLAYERS];
		new curr_time = NetStats_GetConnectedTime(playerid);

		if(g_Glitch_Player_Macro_Time[playerid] == 0) {
			g_Glitch_Player_Macro_Time[playerid] = curr_time;
			system_Counter[playerid] = 0;
		} else {
			if(curr_time - g_Glitch_Player_Macro_Time[playerid] >= 1000) {
				if(curr_time - g_Glitch_Player_Macro_Time[playerid] > 2000) {
					g_Glitch_Player_Macro_Time[playerid] = 0;
					system_Counter[playerid] = 1;
				} else {
					if((-- system_Counter[playerid]) >= g_AntiMacro_Inputs_Warning) {
						if(system_Counter[playerid] >= g_AntiMacro_Inputs_Critical) {
							glitchProtect(playerid, GLITCH_REASON_ANTIMACRO, 4);
							g_Glitch_Player_Macro_Warn[playerid] = 0;
						} else {
							if((++ g_Glitch_Player_Macro_Warn[playerid]) == g_AntiMacro_Max_Warnings) {
								glitchProtect(playerid, GLITCH_REASON_ANTIMACRO, 4);
								g_Glitch_Player_Macro_Warn[playerid] = 0;
							}
						}
					} else {
						if(g_Glitch_Player_Macro_Warn[playerid] > 0) g_Glitch_Player_Macro_Warn[playerid] --;
					}
					system_Counter[playerid] = 0;
					g_Glitch_Player_Macro_Time[playerid] = 0;
				}
			} else system_Counter[playerid] ++;
		}
	}
}
//------------------------------------------------------------------------------
glitchProtect(&playerid, reason, d_reason = 0, anim_index = 0, conn_time = 0, shot_time = 0, old_index_time = 0, crouch_time = 0, weapon = 0, ammo = 0) {
	if(!g_Glitch_Player_Punishment[playerid]) {	
	
		if(DO_USUNIECIA_GLITCH_DEBUG[playerid]) {
			static string[128];
			format(string, sizeof(string), "(AntyGlitch - DEBUG) Sub: %d [%d : %d] | Anim: %d | Old: %d | Weap: %d (%d) | Cr-Time: %d | REASON: %d", 
				conn_time - shot_time, conn_time, shot_time, anim_index, old_index_time, weapon, ammo, crouch_time, d_reason		
			);	
			SendClientMessage(playerid, -1, string);
		}	
		
	
		if(g_AntyGlitch_Punishment == AG_PUNISHMENT_HANDS_UP || reason == GLITCH_REASON_ANTIMACRO) {
			SetPlayerSpecialAction(playerid, SPECIAL_ACTION_HANDSUP);
			if(reason == GLITCH_REASON_ANTIMACRO) {
				
			}
		} else {
			SetPlayerVelocity(playerid, 0.0, 0.0, 0.1);
		}
		SetPlayerArmedWeapon(playerid, 0);
		g_Glitch_Player_Punishment[playerid] = true;
		SetTimerEx("glitchPunishmentEnd", 500, 0, "dd", playerid, GetPlayerWeapon(playerid));
	}
}
//------------------------------------------------------------------------------
forward glitchPunishmentEnd(playerid, weaponid);
public glitchPunishmentEnd(playerid, weaponid){
	resetPlayerGlitchPunishment(playerid);
	SetPlayerArmedWeapon(playerid, weaponid);
	ClearAnimations(playerid);	
}
//------------------------------------------------------------------------------
glitchCheckPlayerAmmo(&playerid) {
	static weaponid, ammo, anim_index;
	static old_Players_Ammo[MAX_PLAYERS], old_Players_Weapon[MAX_PLAYERS];

	new net_connect_time = NetStats_GetConnectedTime(playerid);

	anim_index = GetPlayerAnimationIndex(playerid);
	
	//-----------------------------
	if(16 <= (weaponid = GetPlayerWeapon(playerid)) <= 34) {
		if(old_Players_Weapon[playerid] == weaponid) {
			if((ammo = GetPlayerAmmo(playerid)) < old_Players_Ammo[playerid]) {
				g_Glitch_Player_ShootTime[playerid] = net_connect_time;
			}
			old_Players_Ammo[playerid] = ammo;
		} else {
			old_Players_Weapon[playerid] = weaponid;
			old_Players_Ammo[playerid] = GetPlayerAmmo(playerid);
		}
	} else {
		old_Players_Weapon[playerid] = 0;
		old_Players_Ammo[playerid] = 0;
	}
	//-----------------------------
	
	if(!g_Glitch_Player_Punishment[playerid] && 0 <= net_connect_time - g_Glitch_Player_ShootTime[playerid] < MAX_GLITCH_TIME && (g_AntyGlitch_FastShoot && (net_connect_time - g_Glitch_Player_OldCrouchTime[playerid]) < 1000 && (anim_index == 1189 || anim_index == 1266 || anim_index == 1256 || anim_index == 1183)) || (g_AntyGlitch_CrouchBug && anim_index == 1161 && net_connect_time - g_Glitch_Player_OldIndex[playerid] < MAX_GLITCH_TIME)) {
	    glitchProtect(playerid, GLITCH_REASON_CBUG,
			((g_AntyGlitch_FastShoot && (net_connect_time - g_Glitch_Player_OldCrouchTime[playerid]) < 1000 && (anim_index == 1189 || anim_index == 1266 || anim_index == 1256 || anim_index == 1183)) ? 1 : (g_AntyGlitch_CrouchBug && anim_index == 1161 && net_connect_time - g_Glitch_Player_OldIndex[playerid] < MAX_GLITCH_TIME) ? 2 : -1),
			anim_index, net_connect_time, g_Glitch_Player_ShootTime[playerid], g_Glitch_Player_OldIndex[playerid], g_Glitch_Player_OldCrouchTime[playerid], old_Players_Weapon[playerid], old_Players_Ammo[playerid]		
		);
	}

	if(anim_index == 1274) {
		g_Glitch_Player_OldIndex[playerid] = net_connect_time;
	}
	//-----------------------------
}
//------------------------------------------------------------------------------
checkSlideBug(&playerid) {
	if(1161 <= GetPlayerAnimationIndex(playerid) <= 1163 && g_AntyGlitch_SlideBug) {
	    static Float:speed_x, Float:speed_y, Float:speed_z;
	    GetPlayerVelocity(playerid, speed_x, speed_y, speed_z);
		
        if(((floatpower(speed_x, 2) + floatpower(speed_y, 2)) * 200) > 4.0) {
			glitchProtect(playerid, GLITCH_REASON_SLIDEBUG, 3, GetPlayerAnimationIndex(playerid), NetStats_GetConnectedTime(playerid), -1, -1, -1, -1, -1);
	    } 
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================