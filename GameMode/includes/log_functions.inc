/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
delColorSymbols(text[]) {
	static index;
	index = -1;
	while((index = strfind(text, "{", true, index + 1)) != -1) {
		if(strlen(text) - 1 >= index + 7 && text[index + 7] == '}') {
			strdel(text, index, index + 8);
		}
	}
}
//------------------------------------------------------------------------------
c_print(text[], bool:matchlogs = false) {
	delColorSymbols(text);
	print(text);
	toMatchLogs(text, matchlogs);
}
//------------------------------------------------------------------------------
logMultiAD_Error(log[]) {
	print(log);
	if(fexist(DIR_LOGS)) {
		new string[256];
		new year, month, day, hour, minute, second;
		new File:f_log = fopen(FILE_LOG_ERROR, io_append);

		getdate(year, month, day);
		gettime(hour, minute, second);

		format(string, sizeof(string), "<%02d/%02d/%d [%02d:%02d:%02d]>  %s\r\n", day, month, year, hour, minute, second, log);
		fwrite(f_log, string);
		
		fclose(f_log);
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
logRoundStart_Error(log[]) {
	print(log);
	if(fexist(DIR_LOGS)) {
		new string[256];
		new year, month, day, hour, minute, second;
		new File:f_log = fopen(FILE_LOG_ROUND_START_ERROR, io_append);

		getdate(year, month, day);
		gettime(hour, minute, second);

		format(string, sizeof(string), "<%02d/%02d/%d [%02d:%02d:%02d]>  %s\r\n", day, month, year, hour, minute, second, log);
		fwrite(f_log, string);
		
		fclose(f_log);
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------