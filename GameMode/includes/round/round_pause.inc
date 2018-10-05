/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward timer_UnPause(rest_time);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define getRoundPauseTimerID()		g_Round_Pause_Timer
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_Round_Paused;
new g_Round_Pause_Timer = -1;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getRoundPauseStatus() return _:g_Round_Paused;
//------------------------------------------------------------------------------
pauseForPlayer(&playerid) {
	if(g_Round_Paused && getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		TextDrawShowForPlayer(playerid, TD_Round_Pause);
		SetPlayerTeam(playerid, GLOBAL_TEAM);
		TogglePlayerControllable(playerid, false);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setRoundPauseStatus(bool:enable, intime = 0) {
	if((enable != g_Round_Paused || (g_Round_Pause_Timer != -1 && enable == true)) && getRoundState() == ROUND_STATE_REMAIN && 10 >= intime >= 0) {		
		if(g_Round_Pause_Timer != -1) {
			KillTimer(g_Round_Pause_Timer);
			g_Round_Pause_Timer = -1;
		}	
	
		if(enable == true) {
			new string[32];
			g_Round_Paused = true;
			getTextDrawShortMessage(string, TD_SHORT_MESSAGE_PAUSE, 0); 
			TextDrawColor(TD_Round_Pause, 0xFF0000AA);
			TextDrawSetString(TD_Round_Pause, string);		
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
					SetPlayerTeam(i, GLOBAL_TEAM);
					TogglePlayerControllable(i, false);
					TextDrawShowForPlayer(i, TD_Round_Pause);
				}
			}
		} else {		
			TextDrawColor(TD_Round_Pause, 0x078FE0FF);
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) TextDrawShowForPlayer(i, TD_Round_Pause);
			}			
			timer_UnPause(intime * 1000);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
public timer_UnPause(rest_time) {
	if(getRoundState() == ROUND_STATE_REMAIN) {
		if((rest_time -= 100) <= 0) {
			g_Round_Pause_Timer = -1;
			unpausePlayers();
		} else {
			new string[50];
			getTextDrawShortMessage(string, TD_SHORT_MESSAGE_PAUSE, 1);
			format(string, sizeof(string), string, floatround(floatdiv(rest_time, 1000), floatround_floor), ((rest_time % 1000) / 100));
			TextDrawSetString(TD_Round_Pause, string);
			g_Round_Pause_Timer = SetTimerEx("timer_UnPause", 100, 0, "d", rest_time);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
unpausePlayers() {
	if(g_Round_Pause_Timer != -1) KillTimer(g_Round_Pause_Timer);
	TextDrawHideForAll(TD_Round_Pause);
	g_Round_Paused = false;
	forplayers(i) {
		if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
			if(getSpawnProtectTime() == 0) SetPlayerTeam(i, getPlayerTeam(i));
			TogglePlayerControllable(i, true);
		}
	}	
}