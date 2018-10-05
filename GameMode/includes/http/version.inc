/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_ActualVersion = INT_VERSION;
new bool:g_AutomaticCheckingVersion = true;
//==============================================================================
getAutomaticCheckingVersion() return _:g_AutomaticCheckingVersion;
setAutomaticCheckingVersion(bool:enable) g_AutomaticCheckingVersion = enable;
//------------------------------------------------------------------------------
sendCheckVersion(playerid = INVALID_PLAYER_ID) {
	#if DISABLE_HTTP_MODULE != 1
	if(playerid != INVALID_PLAYER_ID || g_AutomaticCheckingVersion) {
		HTTP(playerid, HTTP_POST, HTTP_SERVER_DATA, prepareServerData(HTTP_TYPE_VERSION), "http_CheckVerResponse");
		#if DEBUG_HTTP_MODULES == 1
		printf("HTTP(%d, %d, %s, %s, %s)", playerid, HTTP_POST, HTTP_SERVER_DATA, prepareServerData(HTTP_TYPE_VERSION), "http_CheckVerResponse");
		#endif		
		return 1;
	}
	#endif
	return 0;
}
//------------------------------------------------------------------------------
isAvailableNewerVersion() return g_ActualVersion > INT_VERSION ? 1 : 0;
//------------------------------------------------------------------------------
public http_CheckVerResponse(index, response_code, data[]) {
	#if DEBUG_HTTP_MODULES == 1
	printf("http_CheckVerResponse(%d, %d, %s)", index, response_code, data);
	#endif
	if(206 >= response_code >= 200) {
		if(strlen(data) == 5 && '9' >= data[0] >= '2') {
			if(g_ActualVersion < strval(data)) {
				g_ActualVersion = strval(data);
				if(index != INVALID_PLAYER_ID && IsPlayerConnected(index)) {
					new s_version[10];
					strins(s_version, data, 0), strins(s_version, ".", 3), strins(s_version, ".", 1);
					getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_NEW_VERSION, 0);
					format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, s_version);
					SendClientMessage(index, COLOR_INFO_1, g_Chat_String);
				}
			} else {
				if(index != INVALID_PLAYER_ID && IsPlayerConnected(index)) {
					getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_NEW_VERSION, 1);
					SendClientMessage(index, COLOR_INFO_1, g_Chat_String);
				}
			}
		}
		return 1;
	}
	return 0;
}