/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SYSTEM_WIN		0
#define	SYSTEM_LINUX	1
//==============================================================================
getServerSystem() {
	new string[128], index;
	GetServerVarAsString("plugins", string, 128);	
	while((index = strfind(string, ".so", false, index)) != -1) {
		if(string[++ index] == EOS || string[index] == ' ') {
			return SYSTEM_LINUX;
		}
	}
	return SYSTEM_WIN;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_HTTP_CheckVersionID = 45352356;
new bool:g_GTTP_CheckVersion_Available = false;
new bool:g_HTTP_ShowNewVersionInfo = true;
//==============================================================================
getShowNewVersionInfo() return _:g_HTTP_ShowNewVersionInfo;
setShowNewVersionInfo(bool:enable) g_HTTP_ShowNewVersionInfo = enable;
//------------------------------------------------------------------------------
http_CheckVersion() {
	new s_post[32];
	format(s_post, sizeof(s_post), "p=%d&v=%d&s=%d", GetServerVarAsInt("port"), INT_VERSION, getServerSystem());
	HTTP((g_HTTP_CheckVersionID = random(9999999)), HTTP_POST, HTTP_CHECK_VERSION, s_post, "OnCheckVersionDataBack");
}
//------------------------------------------------------------------------------
forward OnCheckVersionDataBack(index, response_code, data[]);
public OnCheckVersionDataBack(index, response_code, data[]) {
	if(index == g_HTTP_CheckVersionID && 0 < strlen(data) <= 8) {	
		new r_data = strval(data);
		if('2' <= data[0] <= '9' && INT_VERSION < r_data) {
			g_GTTP_CheckVersion_Available = true;
			return 1;
		} else {
			switch(r_data) {
				case -1: {} //Blokada IP
				case -2: {} //Tylko dla systemu linux
				default: {} //Nieznany powod odrzucenia
			}		
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
sendNewVersionMessage(&playerid) {
	if(g_GTTP_CheckVersion_Available && g_HTTP_ShowNewVersionInfo) {
        getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_NEW_VERSION, 1);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);	
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
http_SendEndMatchMessage(step = 0, row_id = -1) {
	if(getMatchStatus()) {
		new string[2048];
		switch(step) {
			case 0: {
				new round_limit;
				format(string, sizeof(string), "p=%d&v=%d&s=%d&ss=1&r=%d&t1=%s:%d&t2=%s:%d", GetServerVarAsInt("port"), INT_VERSION, getServerSystem(), getMatchRoundLimit(), getTeamName(TEAM_ONE), getTeamPoints(TEAM_ONE), getTeamName(TEAM_TWO), getTeamPoints(TEAM_TWO));
				for(new i, getMatchRoundLimit(); i < round_limit; i ++) {
					format(string, sizeof(string), "%s&%d:%d|%d|%d|%d|%d|%d", string, g_Round_Match_Data[i][MATCH_MAPID], g_Round_Match_Data[i][MATCH_TYPE], g_Round_Match_Data[i][MATCH_WINNER], g_Round_Match_Data[i][MATCH_REASON], g_Round_Match_Data[i][MATCH_DEFENDER], g_Round_Match_Data[i][MATCH_ROUND_TIME]);
				}
				HTTP(getMatchRandomKey(), HTTP_POST, HTTP_MATCH_SEND, s_post, "OnMatchEndDataBack");
			}
			case 1: {
				format(string, sizeof(string), "p=%d&v=%d&s=%dss=2", GetServerVarAsInt("port"), INT_VERSION, getServerSystem());
				forplayers(i) {
					if(getPlayerTeam(i) != TEAM_NON) {
						format("%s&%s:%d|%d|%d|%d", string, getPlayerName(i), getPlayerTeam(i), getPlayerTotalStats(i, KILLS), getPlayerTotalStats(i, DEATHS), getPlayerTotalStats(i, DAMAGE));
					}
				}
				HTTP(getMatchRandomKey(), HTTP_POST, HTTP_MATCH_SEND, s_post, "OnMatchEndDataBack");
			}
			case 2: {
				//Zakonczono
			}
			default: return 0;
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
public OnCheckVersionDataBack(index, response_code, data[]) {
	if(index == getMatchRandomKey() && 8 >= strlen(data) > 0) {
		new step, row_id;
		if(sscanf(data, "p<|>dd", step, row_id) == 0) {
			if(step >= 1 && row_id >= 1) {
				http_SendEndMatchMessage(step, row_id);
				return 1;
			}
		}
	}
	return 0;
}