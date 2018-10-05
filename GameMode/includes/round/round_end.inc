/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward timer_EndRoundInfo();
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define killRoundEndTimerID()	timer_EndRoundInfo()
#define	getRoundTimerID()		g_Round_End_StatsTimerID
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_End_StatsTimerID = -1;
//------------------------------------------------------------------------------
new g_Round_AnyRoundEndSuccess = false;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getSuccesRoundEndStatus() return _:g_Round_AnyRoundEndSuccess;
//------------------------------------------------------------------------------
endRound(reason, bool:crash_add_force = false) {
	if(g_Round_State == ROUND_STATE_REMAIN || g_Round_State == ROUND_STATE_STARTING) {
		if(g_Round_State == ROUND_STATE_REMAIN) {

			if(reason == END_ROUND_REASON_NO_PLAYERS && getRoundCrashPauseStatus() && crash_add_force == false) {
				if(countUnusedCrashData() > 0) {
					caddStopRound(INVALID_PLAYER_ID);
					return 1;
				}
			}
		
			new string[144];
			new alive_players[2], Float:alive_health[2], Float:health, Float:armour;
			new teamid, winreason;			
			
			setRoundPauseStatus(false, 0);
			hideCrashAddInfoForAll();
			setRoundCrashAddStatus(false);
			TextDrawColor(TD_RoundBar_Time, -1);
			TextDrawBoxColor(TD_RoundBar_Time, 48);
			
			forplayers(i) {
				if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) TextDrawShowForPlayer(i, TD_RoundBar_Time);
				GetPlayerHealth(i, health);
				GetPlayerHealth(i, armour);
				destroyPlayerRoundVehicle(i);
				if(!stopSpectate(i, false) && removePlayerFromFight(i)) {
					alive_players[(teamid = getPlayerTeam(i))] ++;
					alive_health[teamid] += health + armour;
				}
			}
			
			if(reason != END_ROUND_REASON_CMD) {
				new s_end[32], s_type[16];
				
				if(g_Round_Type == ROUND_TYPE_ARENA) {
					if(reason == END_ROUND_REASON_POINTS_LIMIT) {
						winreason = WIN_REASON_POINTS_LIMIT;						
						if(g_Round_ArenaTDM_Kill_Points[TEAM_ONE] >= g_Round_ArenaTDM_Kill_Limit && g_Round_ArenaTDM_Kill_Points[TEAM_TWO] >= g_Round_ArenaTDM_Kill_Limit) teamid = TEAM_REF;	
						else if(g_Round_ArenaTDM_Kill_Points[TEAM_ONE] >= g_Round_ArenaTDM_Kill_Limit) teamid = TEAM_ONE;	
						else teamid = TEAM_TWO;	
					} else if(alive_players[TEAM_ONE] == 0 || alive_players[TEAM_TWO] == 0) {
						winreason = WIN_REASON_ENEMY_DEFEAT;
						if(alive_players[TEAM_ONE] == 0 && alive_players[TEAM_TWO] == 0) teamid = TEAM_REF;	
						else if(alive_players[TEAM_ONE] == 0) teamid = TEAM_TWO;	
						else teamid = TEAM_ONE;					
					} else {
						if(getArenaRoundWinMode() == WIN_HEALH_ADVANTAGE) {
							winreason = WIN_REASON_HEALTH_ADVANTAGE;
							if(alive_health[TEAM_ONE] > alive_health[TEAM_TWO]) teamid = TEAM_ONE;
							else if(alive_health[TEAM_ONE] < alive_health[TEAM_TWO]) teamid = TEAM_TWO;
							else teamid = TEAM_REF;							
						} else {
							winreason = WIN_REASON_PLAYER_ADVANTAGE;
							if(alive_players[TEAM_ONE] > alive_players[TEAM_TWO]) teamid = TEAM_ONE;
							else if(alive_players[TEAM_ONE] < alive_players[TEAM_TWO]) teamid = TEAM_TWO;
							else teamid = TEAM_REF;								
						}
					}
				} else {
					if(g_Round_Time == 0) {
						if(alive_players[getDefendingTeam()] > 0) {
							winreason = WIN_REASON_DEFEND_BASE;
							teamid = getDefendingTeam();
						} else {
							winreason = WIN_REASON_ENEMY_DEFEAT;
							teamid = (getDefendingTeam() == TEAM_ONE ? TEAM_TWO : TEAM_ONE);
						}
					} else {
						if(alive_players[TEAM_ONE] == 0 || alive_players[TEAM_TWO] == 0) {
							winreason = WIN_REASON_ENEMY_DEFEAT;
							if(alive_players[TEAM_ONE] == 0 && alive_players[TEAM_TWO] == 0) teamid = TEAM_REF;	
							else if(alive_players[TEAM_ONE] == 0) teamid = TEAM_TWO;	
							else teamid = TEAM_ONE;
						} else {
							winreason = ((reason == END_ROUND_REASON_NO_DEFENDERS) ? WIN_REASON_NO_DEFENDERS : WIN_REASON_TAKEOVER_BASE);								
							teamid = (getDefendingTeam() == TEAM_ONE ? TEAM_TWO : TEAM_ONE); 
						}
					}
				}
						
						
				SendClientMessageToAll(-1, " ");
				getChatMessage(s_end, CHAT_MESSAGE_ENDROUND_REASON, winreason);
				format(s_type, sizeof(s_type), "%s %d", oftenUsedPhrases((g_Round_Type == ROUND_TYPE_ARENA ? (!g_Round_ArenaTDM_Mode ? LANG_OUP_ARENA : LANG_OUP_ARENA_TDM) : LANG_OUP_BASE), 0), g_Round_MapID);
				s_type[0] = toupper(s_type[0]);				
				getChatMessage(string, CHAT_MESSAGE_ENDROUND, 0);
				format(string, sizeof(string), string, s_type, g_Round_RoundCounter + 1);
				SendClientMessageToAll(COLOR_INFO_1, string);
				c_print(string);
				
				if(teamid != TEAM_REF) {
					setTeamPoints(teamid, getTeamPoints(teamid) + 1);
					getChatMessage(string, CHAT_MESSAGE_ENDROUND, 2);
					format(string, sizeof(string), string, getTeamName(teamid), s_end);
					SendClientMessageToAll(COLOR_INFO_1, string);		
					c_print(string);
				} else {	
					getChatMessage(string, CHAT_MESSAGE_ENDROUND, 3);
					SendClientMessageToAll(COLOR_INFO_1, string);	
					c_print(string);					
				}
				SendClientMessageToAll(-1, " ");					
				
				if(!addMatchRoundInfo(g_Round_RoundCounter, g_Round_MapID, g_Round_Type, g_Round_ArenaTDM_Mode, teamid, winreason, getDefendingTeam(), getRoundTime(g_Round_Type, true) - getRoundTimeRest())) {
					setRoundCounterValue(g_Round_RoundCounter + 1);
				}	
				updateEndRoundScreen(winreason, teamid, (getMatchTimerID() == -1 ? true : false));
				
				getChatMessage(string, CHAT_MESSAGE_ENDROUND, 4);
				SendClientMessageToAll(COLOR_INFO_1, string);					
				
				if(getAutoSwapMode() != AUTOSWAP_NO) {							
					swapDefendingTeam((getAutoSwapMode() == AUTOSWAP_ONLY_TEAM ? false : true));
					getChatMessage(string, CHAT_MESSAGE_AUTOSWAP, 0);
					format(string, sizeof(string), string, (getAutoSwapMode() == AUTOSWAP_ONLY_TEAM ? (oftenUsedPhrases(LANG_OUP_NO)) : (oftenUsedPhrases(LANG_OUP_YES))));
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);
				}				
				g_Round_AnyRoundEndSuccess = true;
			}
		}
		
		if(g_Round_GangZones[0] != -1) GangZoneDestroy(g_Round_GangZones[0]), g_Round_GangZones[0] = -1;
		if(g_Round_GangZones[1] != -1) GangZoneDestroy(g_Round_GangZones[1]), g_Round_GangZones[1] = -1;
		
		if(g_Round_FlagObjectID != -1) {
			DestroyObject(g_Round_FlagObjectID);
			g_Round_FlagObjectID = -1;
		}		
		
		hideArenaTDMTextDraw();
		resetRoundDamageInfo(TEAM_ONE);
		resetRoundDamageInfo(TEAM_TWO);
		deleteRoundObjects();
		g_Round_MapID = INVALID_MAP_ID;
		setRoundState(ROUND_STATE_LOBBY);
		resetDefBaseRestTime();
		resetSpawnProtectTime();
		
		return 1;
	}
	return 0;
}	
//------------------------------------------------------------------------------
updateEndRoundScreen(&winreason, &teamid, bool:show = false) {
	new string[150];
	//----------------------
	format(string, sizeof(string), "%s %d", oftenUsedPhrases((g_Round_Type == ROUND_TYPE_ARENA ? (!g_Round_ArenaTDM_Mode ? LANG_OUP_ARENA : LANG_OUP_ARENA_TDM) : LANG_OUP_BASE), 0), g_Round_MapID);
	string[0] = toupper(string[0]);
	TextDrawSetString(TD_Round_End_MapInfo, string);
	//----------------------
	getTextDrawShortMessage(string, TD_SHORT_MESSAGE_END_ROUND, (teamid != TEAM_REF ? 0 : 1));
	format(string, sizeof(string), string, getTeamName(teamid));
	TextDrawSetString(TD_Round_End_WinInfo, string);	
	//----------------------
	getChatMessage(string, CHAT_MESSAGE_ENDROUND_REASON, winreason);
	TextDrawSetString(TD_Round_End_Reason, string);	
	//----------------------
	new result, top_ids[5];
	if((result = getTop5PlayersInTeam(top_ids, TEAM_REF, DAMAGE)) > 0) {
		if(result > sizeof(top_ids)) result = sizeof(top_ids);
		
		string[0] = EOS;
		for(new i; i < result; i ++) {
			format(string, sizeof(string), "%s~n~%s", string, getPlayerName(top_ids[i]));
		}
		strdel(string, 0, 3);
		TextDrawSetString(TD_Round_End_Top_Nicks, string);	
		
		string[0] = EOS;
		for(new i, p_team; i < result; i ++) {
			p_team = getPlayerTeam(top_ids[i]);
			format(string, sizeof(string), "%s~n~%s%s", string, (p_team == TEAM_ONE ? ("~r~") : ("~b~")), getTeamName(p_team));
		}
		strdel(string, 0, 3);
		TextDrawSetString(TD_Round_End_Top_Teams, string);		
		
		string[0] = EOS;
		for(new i; i < result; i ++) {
			format(string, sizeof(string), "%s~n~%d  (%d)", string, getPlayerRoundStats(top_ids[i], DAMAGE), getPlayerRoundStats(top_ids[i], KILLS));
		}
		strdel(string, 0, 3);
		TextDrawSetString(TD_Round_End_Top_Points, string);		
	}	
	
	if(show) {
		new x;
		forplayers(i) {
			if(getPlayerStatus(i) == PLAYER_STATUS_LOBBY) {
				for(x = 0; x < sizeof(TD_Round_End_Static); x ++) TextDrawShowForPlayer(i, TD_Round_End_Static[x]);
				TextDrawShowForPlayer(i, TD_Round_End_MapInfo);
				TextDrawShowForPlayer(i, TD_Round_End_WinInfo);
				TextDrawShowForPlayer(i, TD_Round_End_Reason);
				TextDrawShowForPlayer(i, TD_Round_End_Top_Nicks);
				TextDrawShowForPlayer(i, TD_Round_End_Top_Teams);
				TextDrawShowForPlayer(i, TD_Round_End_Top_Points);		
			}
		}
		
		if(g_Round_End_StatsTimerID != -1) KillTimer(g_Round_End_StatsTimerID);
		g_Round_End_StatsTimerID = SetTimer("timer_EndRoundInfo", 5000, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
public timer_EndRoundInfo() {
	if(g_Round_End_StatsTimerID != -1) {
		for(new x; x < sizeof(TD_Round_End_Static); x ++) TextDrawHideForAll(TD_Round_End_Static[x]);
		TextDrawHideForAll(TD_Round_End_MapInfo);
		TextDrawHideForAll(TD_Round_End_WinInfo);
		TextDrawHideForAll(TD_Round_End_Reason);
		TextDrawHideForAll(TD_Round_End_Top_Nicks);
		TextDrawHideForAll(TD_Round_End_Top_Teams);
		TextDrawHideForAll(TD_Round_End_Top_Points);	

		KillTimer(g_Round_End_StatsTimerID);
		g_Round_End_StatsTimerID = -1;	
		
		getChatMessage(g_Chat_String, CHAT_MESSAGE_ENDROUND, 5);
		SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	}
}