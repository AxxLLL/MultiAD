/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new bool:g_Round_ChatLock = false;
new bool:g_Round_PlayerRepresentative[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getChatLockStatus() return _:g_Round_ChatLock;
//------------------------------------------------------------------------------
setChatLockStatus(bool:disablechat) {
	g_Round_ChatLock = disablechat;
	return 1;
}
//------------------------------------------------------------------------------
isPlayerRepresentative(&playerid) return _:g_Round_PlayerRepresentative[playerid];
//------------------------------------------------------------------------------
setPlayerRepresentativeStatus(&playerid, bool:enable) {
	if(g_Round_PlayerRepresentative[playerid] != enable) {
		g_Round_PlayerRepresentative[playerid] = enable;
		return 1;
	}
	return 0;
}