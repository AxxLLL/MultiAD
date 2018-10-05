/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerPlayedRounds(&playerid, listitem = -1) {
	if(getMatchStatus()) {
		new string[800];
		if(listitem == -1) {
			new counter, s_arena[8], s_base[8];
			new win_team[3][10];
			
			strins(win_team[0], getTeamName(TEAM_ONE), 0);
			strins(win_team[1], getTeamName(TEAM_TWO), 0);
			strins(win_team[2], oftenUsedPhrases(LANG_OUP_ROUND_DRAW, 0), 0);
			
			strins(s_arena, oftenUsedPhrases(LANG_OUP_ARENA, 3), 0);
			strins(s_base, oftenUsedPhrases(LANG_OUP_BASE, 3), 0);
			
			for(new i; i < g_Round_Match_Data[i][MATCH_MAPID]; i ++) {
				if(g_Round_Match_Data[i][MATCH_MAPID] == INVALID_MAP_ID) break;
				else {
					counter ++;
					format(string, sizeof(string),"%s\n"COLOR_DIALOG_COUNT"%d) "COLOR_DIALOG_BODY"%s %d\t\tWygrywa: "COLOR_DIALOG_COUNT"%s", string, i + 1, (g_Round_Match_Data[i][MATCH_TYPE] == ROUND_TYPE_ARENA ? s_arena : s_base), g_Round_Match_Data[i][MATCH_MAPID], win_team[g_Round_Match_Data[i][MATCH_WINNER]]);
				}
			}
			
			if(counter > 0) {
				ShowPlayerDialog(playerid, DIALOG_MATCH_ROUNDS, DIALOG_STYLE_LIST, COLOR_DIALOG_HEAD"Match Rounds", string, oftenUsedPhrases(LANG_OUP_NEXT), oftenUsedPhrases(LANG_OUP_EXIT));
			} else {
				getDialogBodyMessage(string, DIALOG_BODY_MATCH_ROUNDS, 0);
				showPlayerBackDialog(playerid, BACK_NON, COLOR_DIALOG_HEAD"Match Rounds", string);
			}
		} else {
			if(listitem >= sizeof(g_Round_Match_Data) || g_Round_Match_Data[listitem][MATCH_MAPID] == INVALID_MAP_ID) showPlayerPlayedRounds(playerid);
			else {
				new s_win_reason[64];
				getChatCMDMessage(string, CHAT_CMD_MESSAGE_DEL_ROUNDS, g_Round_Match_Data[listitem][MATCH_WINNER]);
				getChatCMDMessage(s_win_reason, CHAT_MESSAGE_ENDROUND_REASON, g_Round_Match_Data[listitem][MATCH_REASON]);
				format(string, sizeof(string), string, 
					listitem + 1, 
					oftenUsedPhrases((g_Round_Match_Data[listitem][MATCH_TYPE] == ROUND_TYPE_ARENA ? LANG_OUP_ARENA : LANG_OUP_BASE), 3), 
					g_Round_Match_Data[listitem][MATCH_MAPID],
					getTeamName(g_Round_Match_Data[listitem][MATCH_DEFENDER]),
					(g_Round_Match_Data[listitem][MATCH_WINNER] == TEAM_REF ? oftenUsedPhrases(LANG_OUP_ROUND_DRAW, 0) : getTeamName(g_Round_Match_Data[listitem][MATCH_WINNER]) ),				
					s_win_reason,
					floatround(floatdiv(g_Round_Match_Data[listitem][MATCH_ROUND_TIME], 60), floatround_floor), g_Round_Match_Data[listitem][MATCH_ROUND_TIME] % 60					
				);

				if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
					SetPVarInt(playerid, PV_HELP_VAR_1, listitem);
					ShowPlayerDialog(playerid, DIALOG_MATCH_ROUNDS_DELETE, DIALOG_STYLE_MSGBOX, COLOR_DIALOG_HEAD"Match Rounds", string, oftenUsedPhrases(LANG_OUP_ROUND_DELETE), oftenUsedPhrases(LANG_OUP_BACK));
				} else {
					showPlayerBackDialog(playerid, BACK_MATCH_ROUNDS, COLOR_DIALOG_HEAD"Match Rounds", string);
				}
			}
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
deleteMatchRoundDataMenu(&playerid, confirm = false) {
	new roundid; 
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN) && getMatchStatus()) {
		if(sizeof(g_Round_Match_Data) > (roundid = GetPVarInt(playerid, PV_HELP_VAR_1)) >= 0 && g_Round_Match_Data[roundid][MATCH_MAPID] != INVALID_MAP_ID) {
			new string[144];
			if(getRoundState() == ROUND_STATE_LOBBY) {				
				if(confirm) {
					getChatCMDMessage(string, CHAT_CMD_MESSAGE_DEL_ROUNDS, 2);
					format(string, sizeof(string), string, getPlayerName(playerid), roundid + 1, oftenUsedPhrases((g_Round_Match_Data[roundid][MATCH_TYPE] == ROUND_TYPE_ARENA ? LANG_OUP_ARENA : LANG_OUP_BASE), 3), g_Round_Match_Data[roundid][MATCH_MAPID], (g_Round_Match_Data[roundid][MATCH_WINNER] == TEAM_REF ? oftenUsedPhrases(LANG_OUP_ROUND_DRAW, 0) : getTeamName(g_Round_Match_Data[roundid][MATCH_WINNER]) ));
					SendClientMessageToAll(COLOR_INFO_1, string);
					c_print(string);
					
					if(g_Round_Match_Data[roundid][MATCH_WINNER] != TEAM_REF) {
						setTeamPoints(g_Round_Match_Data[roundid][MATCH_WINNER], getTeamPoints(g_Round_Match_Data[roundid][MATCH_WINNER]) - 1);
					}
					setRoundCounterValue(getRoundCounterValue() - 1);
					
					deleteMatchRoundData(roundid);
					showPlayerPlayedRounds(playerid);
				} else {
					getChatCMDMessage(string, CHAT_CMD_MESSAGE_DEL_ROUNDS, 1);
					showPlayerConfirmDialog(playerid, CONFIRM_DELETE_ROUND, COLOR_DIALOG_HEAD"Match Rounds", string);
				}
				return 1;
			} else {
				getChatCMDMessage(string, CHAT_CMD_MESSAGE_DEL_ROUNDS, 3);
				showPlayerBackDialog(playerid, BACK_MATCH_ROUNDS, COLOR_DIALOG_HEAD"Match Rounds", string);
			}	
		} else showPlayerPlayedRounds(playerid);
	}
	return 0;
}
