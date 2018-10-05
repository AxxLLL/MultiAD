/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new Float:g_Request_BoxPos[2] = {415.0, 337.0};
new Text:TD_RequestStatic[5], Text:TD_RequestTeamName[3], Text:TD_RequestTeamInfo[3];
new Float:g_Request_PlayerPos[4] = {2332.8964, -1543.7178, 23.9898, 226.6367},
	Float:g_Request_CameraPos[3] = {2337.1923, -1547.7744, 24.0034},
	Float:g_Request_CameraLookAt[3] = {2332.8964, -1543.7178, 23.9898},
	g_Request_Interior = 0;
//==============================================================================
#define getRequestClassPlayerPos(%1)		g_Request_PlayerPos[%1]
#define getRequestClassCameraPos(%1)		g_Request_CameraPos[%1]
#define getRequestClassCameraLookAt(%1)		g_Request_CameraLookAt[%1]
#define getRequestClassInterior()			g_Request_Interior
#define getRequestClassBoxPos(%1)			g_Request_BoxPos[%1]
//==============================================================================
loadRequestPositions() {	
	if(fexist(DIR_GENERAL)) {
	    new File:f_open;
	    new read[256];
	    if(!fexist(FILE_REQUEST)) {
            f_open = fopen(FILE_REQUEST, io_write);
            format(read, sizeof(read), "interior: %d", 						g_Request_Interior),		fwrite(f_open, read);
            format(read, sizeof(read), "\r\nrequestbox: %.4f, %.4f", 			g_Request_BoxPos[0], 		g_Request_BoxPos[1]),		fwrite(f_open, read);
		    format(read, sizeof(read), "\r\nplayerpos: %.4f, %.4f, %.4f, %.4f", g_Request_PlayerPos[0], 	g_Request_PlayerPos[1], 	g_Request_PlayerPos[2], 	g_Request_PlayerPos[3]),	fwrite(f_open, read);
		    format(read, sizeof(read), "\r\ncamerapos: %.4f, %.4f, %.4f", 		g_Request_CameraPos[0], 	g_Request_CameraPos[1], 	g_Request_CameraPos[2]),	fwrite(f_open, read);
		    format(read, sizeof(read), "\r\ncameralookat: %.4f, %.4f, %.4f", 	g_Request_CameraLookAt[0], 	g_Request_CameraLookAt[1], 	g_Request_CameraLookAt[2]),	fwrite(f_open, read);
			getConsoleMessage(read, CONSOLE_MESSAGE_NEW_CONFIG_FILE);
            printf(read, "Request Positions", FILE_REQUEST);			
		} else {
			new readline = 1, index;
			new loadedInterior = -1, Float:loadedPlayerPos[4] = {-99999.0, -99999.0, ...}, Float:loadedCameraPos[3] = {-99999.0, -99999.0, ...}, Float:loadedCameraLookAt[3] = {-99999.0, -99999.0, ...}, Float:loadedRequestBox[2] = {-99999.0, -99999.0};
			
			f_open = fopen(FILE_REQUEST, io_read);
			
			while(fread(f_open, read, sizeof(read))) {
			    DeleteNewLine(read);
			    DeleteSpaces(read);
				
				if(!isnull(read) && (strlen(read) - 1) > (index = strfind(read, ":")) > 0) {
				    if(!strcmp(read, "interior", true, index)) {
				       if(sscanf(read[index + 1], "d", loadedInterior) != 0) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 0);
				            format(read, sizeof(read), read, FILE_REQUEST, readline);		
							logMultiAD_Error(read);
				            loadedInterior = -1;
            			}
					} else if(!strcmp(read, "requestbox", true, index)) {
						if(sscanf(read[index + 1], "p<,>ff", loadedRequestBox[0], loadedRequestBox[1]) || (1000.0 < loadedRequestBox[0] < 0) || (1000.0 < loadedRequestBox[1] < 0)) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 3);
				            format(read, sizeof(read), read, FILE_REQUEST, "requestbox", readline);	
							logMultiAD_Error(read);
							loadedRequestBox[0] = loadedRequestBox[1] = -99999.0;
						}
					} else if(!strcmp(read, "playerpos", true, index)) {
						if(sscanf(read[index + 1], "p<,>ffff", loadedPlayerPos[0], loadedPlayerPos[1], loadedPlayerPos[2], loadedPlayerPos[3]) != 0) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 4);
				            format(read, sizeof(read), read, FILE_REQUEST, "playerpos", readline);						
							logMultiAD_Error(read);
							loadedPlayerPos[0] = loadedPlayerPos[1] = loadedPlayerPos[2] = loadedPlayerPos[3] = -99999.0;
						}	
				    } else if(!strcmp(read, "camerapos", true, index)) {
						if(sscanf(read[index + 1], "p<,>fff", loadedCameraPos[0], loadedCameraPos[1], loadedCameraPos[2]) != 0) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 1);
							format(read, sizeof(read), read, FILE_LOBBY, "camerapos", readline);	
							logMultiAD_Error(read);
							loadedCameraPos[0] = loadedCameraPos[1] = loadedCameraPos[2] = -99999.0;
						}				 
				    } else if(!strcmp(read, "cameralookat", true, index)) {
						if(sscanf(read[index + 1], "p<,>fff", loadedCameraLookAt[0], loadedCameraLookAt[1], loadedCameraLookAt[2]) != 0) {
							getConsoleMessage(read, CONSOLE_MESSAGE_CONFIG_ERROR, 1);
							format(read, sizeof(read), read, FILE_LOBBY, "cameralookat", readline);	
							logMultiAD_Error(read);
							loadedCameraLookAt[0] = loadedCameraLookAt[1] = loadedCameraLookAt[2] = -99999.0;
						}						
				    }
				}
				readline ++;
			}
			
			if(loadedPlayerPos[0] != -99999.0) 			for(index = 0; index < sizeof(g_Request_PlayerPos); index ++) 		g_Request_PlayerPos[index] = loadedPlayerPos[index];
			if(loadedCameraPos[0] != -99999.0) 			for(index = 0; index < sizeof(g_Request_CameraPos); index ++) 		g_Request_CameraPos[index] = loadedCameraPos[index];
			if(g_Request_CameraLookAt[0] != -99999.0) 	for(index = 0; index < sizeof(g_Request_CameraLookAt); index ++) 	g_Request_CameraLookAt[index] = g_Request_CameraLookAt[index];
			if(loadedInterior != -1) 					g_Request_Interior = loadedInterior;
			if(loadedRequestBox[0] != -99999.0) {
			    g_Request_BoxPos[0] = loadedRequestBox[0];
			    g_Request_BoxPos[1] = loadedRequestBox[1];
			}
			
		}
		fclose(f_open);
		return 1;
	}
	return 0;
}