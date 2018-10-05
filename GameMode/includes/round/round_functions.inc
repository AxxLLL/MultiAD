/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Loaded_Maps[2] = {0, 0}, 
	g_Loaded_StartID[2] = {-1, -1},
	g_Loaded_EndID[2] = {-1, -1};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
preloadMapIDs() {
	new string[32];
	
	g_Loaded_Maps[ROUND_TYPE_ARENA] = g_Loaded_Maps[ROUND_TYPE_BASE] = 0;
	g_Loaded_StartID[ROUND_TYPE_ARENA] = g_Loaded_StartID[ROUND_TYPE_BASE] = -1;
	g_Loaded_EndID[ROUND_TYPE_ARENA] = g_Loaded_EndID[ROUND_TYPE_BASE] = -1;
	
	if(fexist(DIR_ARENAS)) {
		for(new i = 0, bool:error; ; i ++) {
			format(string, sizeof(string), DIR_ARENAS"/%d.ini", i);
			if(fexist(string)) {
				if(g_Loaded_StartID[ROUND_TYPE_ARENA] == -1) g_Loaded_StartID[ROUND_TYPE_ARENA] = i;
				if(i > g_Loaded_EndID[ROUND_TYPE_ARENA]) g_Loaded_EndID[ROUND_TYPE_ARENA] = i;
				g_Loaded_Maps[ROUND_TYPE_ARENA] ++;
			} else {
				if(error == true) break;
				else error = true;
			}
		}
	}
	if(fexist(DIR_BASES)) {
		for(new i = 0, bool:error; ; i ++) {
			format(string, sizeof(string), DIR_BASES"/%d.ini", i);
			if(fexist(string)) {
				if(g_Loaded_StartID[ROUND_TYPE_BASE] == -1) g_Loaded_StartID[ROUND_TYPE_BASE] = i;
				if(i > g_Loaded_EndID[ROUND_TYPE_BASE]) g_Loaded_EndID[ROUND_TYPE_BASE] = i;
				g_Loaded_Maps[ROUND_TYPE_BASE] ++;
			} else {
				if(error == true) break;
				else error = true;
			}
		}
	}		
	
	return 1;
}
//------------------------------------------------------------------------------	
getRandomMapID(type) {
	if(ROUND_TYPE_BASE >= type >= ROUND_TYPE_ARENA) {
		if(g_Loaded_Maps[type] > 0) {
			new mapid, errors, string[32];
			do {
				mapid = (g_Loaded_StartID[type] + random((1 + g_Loaded_EndID[type] - g_Loaded_StartID[type])));
				format(string, sizeof(string), "%s/%d.ini", (type == ROUND_TYPE_ARENA ? (DIR_ARENAS) : (DIR_BASES)), mapid);
				if(fexist(string)) return mapid;
				else errors ++;
			} while(errors < 10);
		}
	}
	return -1;
}