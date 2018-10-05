/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward http_CheckVerResponse(index, response_code, data[]);
forward http_MatchResultsResponse(index, response_code, data[]);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SYSTEM_WIN								0
#define	SYSTEM_LINUX							1
//------------------------------------------------------------------------------
#define HTTP_TYPE_VERSION						1
#define HTTP_TYPE_UPDATE						2
#define HTTP_TYPE_MATCH_RESULTS					3
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/http/version.inc"
#include "includes/http/matchresults.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_AddServerToList = true;
//==============================================================================
setAddToServerListStatus(bool:enable) g_AddServerToList = enable;
getAddToServerListStatus() return _:g_AddServerToList;
//------------------------------------------------------------------------------
prepareServerData(type) {
	new string[64];
	format(string, sizeof(string), "ver="#INT_VERSION"&data=[%d|%s|%d|%d|%d]", type, g_Server_IP_Bind, g_Server_Port, g_Server_System, getAddToServerListStatus());
	return string;
}
//------------------------------------------------------------------------------
sendServerInfo(bool:state_online = true) {
	#if DISABLE_HTTP_MODULE != 1
	new string[128];
	format(string, sizeof(string), "%s&special=[%d]", prepareServerData(HTTP_TYPE_UPDATE), state_online);
	#if DEBUG_HTTP_MODULES == 1
	HTTP(0, HTTP_POST, HTTP_SERVER_DATA, string, "debug_sendServerInfo");
	printf("HTTP(%d, %d, %s, %s, %s)", 0, HTTP_POST, HTTP_SERVER_DATA, string, "debug_sendServerInfo");
	#else
	HTTP(0, HTTP_POST, HTTP_SERVER_DATA, string, "");
	#endif
	#endif
	return 1;
}
//------------------------------------------------------------------------------
getServerSystem() {
	new string[128], index;
	GetServerVarAsString("plugins", string, 128);	
	while((index = strfind(string, ".so", false, index)) != -1) {
		if(string[++ index + 3] == EOS || string[index + 3] == ' ') {
			return SYSTEM_LINUX;
		}
	}
	return SYSTEM_WIN;
}
//------------------------------------------------------------------------------
#if DEBUG_HTTP_MODULES == 1
forward debug_sendServerInfo(index, response_code, data[]);
public debug_sendServerInfo(index, response_code, data[]) {
	printf("debug_sendServerInfo(%d, %d, %s)", index, response_code, data);
}
#endif