/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define SCOREBOARD_FPS				0
#define SCOREBOARD_HEALTH			1
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Setting_Weather = 10;
new Float:g_Setting_NameTagDistance = 20.0;
new Float:g_Setting_Gravity = 0.008;
new g_Setting_WorldTime = 15;
new g_Setting_Scoreboard_Type = SCOREBOARD_HEALTH;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/settings/saveload.inc"
#include "includes/settings/menu.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getServerWeather() return g_Setting_Weather;
setServerWeather(weatherid) {
	if(20 >= weatherid >= 0) {
		SetWeather((g_Setting_Weather = weatherid));
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
Float:getServerNameTagDistance() return g_Setting_NameTagDistance;
setServerNameTagDistance(Float:distance) {
	if(250.0 >= distance >= 5.0) {
		SetNameTagDrawDistance((g_Setting_NameTagDistance = distance));
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
Float:getServerGravity() return g_Setting_Gravity;
setServerGravity(Float:gravity) {
	if(50.0 >= gravity >= -50.0) {
		SetGravity((g_Setting_Gravity = gravity));
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getServerWorldTime() return g_Setting_WorldTime;
setServerWorldTime(time) {
	if(24 >= time >= 0) {
		SetWorldTime((g_Setting_WorldTime = time));
		return 1;
	}
	return 0;
}
