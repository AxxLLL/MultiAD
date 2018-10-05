/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
checkRoundDataInSQL() {
	new DBResult:result;
	result = db_query(dbase, "SELECT `"DM_MATCH_ID"`, `"DM_ROUND_LIMIT"` FROM `"D_MATCH"`");
	if(db_num_rows(result) == 1) {
		new match_id, round_limit, string[64];
		db_get_field_assoc(result, DM_MATCH_ID, string, 32), match_id = strval(string);
		db_get_field_assoc(result, DM_ROUND_LIMIT, string, 32), round_limit = strval(string);
		db_free_result(result);
		if(match_id > 0 && 11 >= round_limit >= 1) {
			format(string, sizeof(string), "SELECT `"DMR_ROUND"` FROM `"D_MATCH_ROUNDS"` WHERE `"DMR_MATCH_ID"`='%d'", match_id);
			if(round_limit > db_num_rows((result = db_query(dbase, string))) > 0) {
				db_free_result(result);
				return match_id;
			} else deleteRoundDataFromSQL();			
		} else deleteRoundDataFromSQL();
	} else if(db_num_rows(result) > 1) {
		db_free_result(result);
		deleteRoundDataFromSQL();
	}
	return 0;
}
//------------------------------------------------------------------------------
deleteRoundDataFromSQL() {
	db_query(dbase, "DELETE FROM `"D_MATCH"`");
	db_query(dbase, "DELETE FROM `"D_MATCH_PLAYERS"`");
	db_query(dbase, "DELETE FROM `"D_MATCH_ROUNDS"`");
}
//------------------------------------------------------------------------------
loadRoundDataFromSQL() {
	new match_id;
	if((match_id = checkRoundDataInSQL()) != 0) {
		new DBResult:result, string[128];
		//--------------------
		new team_1_name[16], team_2_name[16], round_limit;
		result = db_query(dbase, "SELECT * FROM `"D_MATCH"`");		
		db_get_field_assoc(result, DM_TEAM_1, team_1_name, sizeof(team_1_name));
		db_get_field_assoc(result, DM_TEAM_2, team_2_name, sizeof(team_2_name));
		db_get_field_assoc(result, DM_ROUND_LIMIT, string, sizeof(string)), round_limit = strval(string);
		db_free_result(result);
		
	    setTeamName(TEAM_ONE, team_1_name, true);
	    setTeamName(TEAM_TWO, team_2_name, true);		
		startMatch(round_limit);
		forceMatchRandomKey(match_id);
		
		format(string, sizeof(string), "UPDATE `"D_MATCH"` SET `"DM_START_TIME"`='%d'", gettime());
		//--------------------
		format(string, sizeof(string), "SELECT * FROM `"D_MATCH_ROUNDS"` WHERE `"DMR_MATCH_ID"`='%d'", match_id);
		result = db_query(dbase, string);
		for(new i, num_rows = db_num_rows(result), mapid, type, bool:tdm_mode, win_teamid, win_reason, defender, time; i < num_rows; i ++) {
			db_get_field_assoc(result, DMR_MAP_ID, string, sizeof(string)), mapid = strval(string);
			db_get_field_assoc(result, DMR_MAP_TYPE, string, sizeof(string)), type = strval(string);
			db_get_field_assoc(result, DMR_TDM_MODE, string, sizeof(string)), tdm_mode = (strval(string) > 0 ? true : false);
			db_get_field_assoc(result, DMR_WINNER, string, sizeof(string)), win_teamid = strval(string);
			db_get_field_assoc(result, DMR_REASON, string, sizeof(string)), win_reason = strval(string);
			db_get_field_assoc(result, DMR_DEFENDER, string, sizeof(string)), defender = strval(string);
			db_get_field_assoc(result, DMR_ROUND_TIME, string, sizeof(string)), time = strval(string);
			
			addMatchRoundInfo(i, mapid, type, tdm_mode, win_teamid, win_reason, defender, time, false);
			db_next_row(result);
		}
		db_free_result(result);
		//--------------------
		new pName[MAX_PLAYER_NAME];
		forplayers(i) {
			GetPlayerName(i, pName, sizeof(pName));
			format(string, sizeof(string), "SELECT * FROM `"D_MATCH_PLAYERS"` WHERE `"DMP_NICK"`='%s' AND `"DMP_MATCH_ID"`='%d' LIMIT 1", pName, match_id);
			if(db_num_rows((result = db_query(dbase, string))) == 1) {
				setPlayerMatchRandomID(i, match_id);
				
				db_get_field_assoc(result, DMP_KILLS, string, sizeof(string)), setPlayerTotalStatPoints(i, KILLS, strval(string));
				db_get_field_assoc(result, DMP_DEATHS, string, sizeof(string)), setPlayerTotalStatPoints(i, DEATHS, strval(string));
				db_get_field_assoc(result, DMP_DAMAGE, string, sizeof(string)), setPlayerTotalStatPoints(i, DAMAGE, strval(string));
				db_get_field_assoc(result, DMP_PLAYED_ROUNDS, string, sizeof(string)), setPlayerPlayedRounds(i, strval(string));
				db_free_result(result);		
			}
		}				
		return 1;
	}
	return 0;
}