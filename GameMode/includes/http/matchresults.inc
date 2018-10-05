/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_SendMatchResults = false;
new g_LastMatchID = -1;
//==============================================================================
getSendMatchResultsStatus() return _:g_SendMatchResults;
setSendMatchResultsStatus(bool:enable) g_SendMatchResults = enable;
//------------------------------------------------------------------------------
prepareSiteMatchResults() {
	#if DISABLE_HTTP_MODULE != 1
	if(getMatchStatus() && g_SendMatchResults) {
		new string[2048], player_counter, round_counter;
		new DBResult:result;
		
		getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_MATCH_RESPONSE, 1);
		SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					
		g_LastMatchID = getMatchRandomKey();
		
		format(string, sizeof(string), "%s&special={\"general\":{\"rounds\":%d,\"team\":[{\"name\":\"%s\",\"points\":%d},{\"name\":\"%s\",\"points\":%d}]},\"round\":[", prepareServerData(HTTP_TYPE_MATCH_RESULTS), getMatchRoundLimit(), getTeamName(TEAM_ONE), getTeamPoints(TEAM_ONE), getTeamName(TEAM_TWO), getTeamPoints(TEAM_TWO));
		
		for(new i, round_limit = getMatchRoundLimit(); i < round_limit; i ++) {
			round_counter ++;
			format(string, sizeof(string), "%s`%d,%d,%d,%d,%d,%d,%d',", string, g_Round_Match_Data[i][MATCH_MAPID], g_Round_Match_Data[i][MATCH_TYPE], g_Round_Match_Data[i][MATCH_WINNER], g_Round_Match_Data[i][MATCH_REASON], g_Round_Match_Data[i][MATCH_DEFENDER], g_Round_Match_Data[i][MATCH_ROUND_TIME], g_Round_Match_Data[i][MATCH_TDM_MODE]);
		}				
		strdel(string, strlen(string) - 1, strlen(string));
		format(string, sizeof(string), "%s],\"players\":[", string);
		
		format(g_String_512, sizeof(g_String_512), "SELECT * FROM `"D_MATCH_PLAYERS"` WHERE `"DMP_MATCH_ID"`='%d' AND `"DMP_PLAYED_ROUNDS"` > '0'", g_LastMatchID);
		result = db_query(dbase, g_String_512);
		if((player_counter = db_num_rows(result)) > 0) {
			for(new i, p_name[24], x, length, teamid, kills, deaths, damage, played_rounds, buffer[32]; i < player_counter; i ++) {
				GetPlayerName(i, p_name, sizeof(p_name));
				for(x = 0, length = strlen(p_name); x < length; x ++) {
					if(p_name[x] == '[') p_name[x] = '`';
					else if(p_name[x] == ']') p_name[x] = '\'';
				}		

				db_get_field_assoc(result, DMP_TEAM_ID, buffer, sizeof(buffer)), teamid = strval(buffer);
				db_get_field_assoc(result, DMP_KILLS, buffer, sizeof(buffer)), kills = strval(buffer);
				db_get_field_assoc(result, DMP_DEATHS, buffer, sizeof(buffer)), deaths = strval(buffer);
				db_get_field_assoc(result, DMP_DAMAGE, buffer, sizeof(buffer)), damage = strval(buffer);
				db_get_field_assoc(result, DMP_PLAYED_ROUNDS, buffer, sizeof(buffer)), played_rounds = strval(buffer);
						
				format(string, sizeof(string), "%s`\"%s\",%d,%d,%d,%d,%d',", string, p_name, teamid, kills, deaths, damage, played_rounds);
				if(strlen(string) > 2000) break;				
				
				db_next_row(result);
			}
			db_free_result(result);			
		}
		
		strdel(string, strlen(string) - 1, strlen(string));
		format(string, sizeof(string), "%s]}", string);
		
		if(player_counter > 0 && round_counter > 0) {
			HTTP(g_LastMatchID, HTTP_POST, HTTP_SERVER_DATA, string, "http_MatchResultsResponse");
			#if DEBUG_HTTP_MODULES == 1
			printf("HTTP(%d, %d, %s, %s, %s)", g_LastMatchID, HTTP_POST, HTTP_SERVER_DATA, string, "http_MatchResultsResponse");
			#endif		
		}
		return 1;
	}
	#endif
	return 0;
}
//------------------------------------------------------------------------------
public http_MatchResultsResponse(index, response_code, data[]) {
	#if DEBUG_HTTP_MODULES == 1
	printf("http_MatchResultsResponse(%d, %d, %s)", index, response_code, data);
	#endif
	if(206 >= response_code >= 200) {
		if(index == g_LastMatchID && '9' >= data[0] >= '0' && 0 < strlen(data) <= 8) {
			if(strval(data) <= 0) {
				getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_MATCH_RESPONSE, 2);
			} else {				
				if(fexist(DIR_GENERAL)) {
					new File:f_logs = fopen(FILE_MATCH_HTTP_LINKS, io_append);
					new year, month, day, hour, minute, second;
					getdate(year, month, day);
					gettime(hour, minute, second);
					format(g_Chat_String, sizeof(g_Chat_String), "\r\n(%02d/%02d/%d  [%02d:%02d:%02d]) %s vs %s | Link: "HTTP_MATCH_RESULTS"?id=%d", day, month, year, hour, minute, second, getTeamName(TEAM_ONE), getTeamName(TEAM_TWO), strval(data));
					fwrite(f_logs, g_Chat_String);
					fclose(f_logs);
				}				
				getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_MATCH_RESPONSE, 0);
				format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, strval(data));
			}
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);			
			return 1;
		}
	}
	return 0;
}
