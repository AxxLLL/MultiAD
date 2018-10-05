/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerRoundStartTextdraws(&playerid) {
	for(new i; i < sizeof(TD_Round_Start_Static); i ++) TextDrawShowForPlayer(playerid, TD_Round_Start_Static[i]);
	TextDrawShowForPlayer(playerid, TD_Round_Start_Map);
	TextDrawShowForPlayer(playerid, TD_Round_Start_Round);
	TextDrawShowForPlayer(playerid, TD_Round_Start_Teams[0]);
	TextDrawShowForPlayer(playerid, TD_Round_Start_Teams[1]);
	return 1;
}
//------------------------------------------------------------------------------
hidePlayerRoundStartTextdraws(&playerid) {
	for(new i; i < sizeof(TD_Round_Start_Static); i ++) TextDrawHideForPlayer(playerid, TD_Round_Start_Static[i]);
	TextDrawHideForPlayer(playerid, TD_Round_Start_Map);
	TextDrawHideForPlayer(playerid, TD_Round_Start_Round);
	TextDrawHideForPlayer(playerid, TD_Round_Start_Teams[0]);
	TextDrawHideForPlayer(playerid, TD_Round_Start_Teams[1]);	
	return 1;
}
//==============================================================================
hideRoundBar(&playerid) {
	for(new i; i < sizeof(TD_RoundBar_Static); i ++) TextDrawHideForPlayer(playerid, TD_RoundBar_Static[i]);
	for(new i; i < 2; i ++) {
		TextDrawHideForPlayer(playerid, TD_RoundBar_Name[i]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Health[i]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Players[i]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Points[i]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Color[i]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Defend[i]);
	}
	TextDrawHideForPlayer(playerid, TD_RoundBar_Time);
	TextDrawHideForPlayer(playerid, TD_RoundBar_Base);
	TextDrawHideForPlayer(playerid, TD_RoundBar_Rounds);	
}
//------------------------------------------------------------------------------
showRoundBar(&playerid) {
	for(new i; i < sizeof(TD_RoundBar_Static); i ++) TextDrawShowForPlayer(playerid, TD_RoundBar_Static[i]);
	for(new i; i < 2; i ++) {
		TextDrawShowForPlayer(playerid, TD_RoundBar_Name[i]);
		TextDrawShowForPlayer(playerid, TD_RoundBar_Health[i]);
		TextDrawShowForPlayer(playerid, TD_RoundBar_Players[i]);
		TextDrawShowForPlayer(playerid, TD_RoundBar_Points[i]);
		TextDrawShowForPlayer(playerid, TD_RoundBar_Color[i]);
	}
	TextDrawShowForPlayer(playerid, TD_RoundBar_Time);
	TextDrawShowForPlayer(playerid, TD_RoundBar_Base);
	TextDrawShowForPlayer(playerid, TD_RoundBar_Rounds);
	
	if(getDefendingTeam() == TEAM_ONE) {
		TextDrawShowForPlayer(playerid, TD_RoundBar_Defend[0]);
		TextDrawHideForPlayer(playerid, TD_RoundBar_Defend[1]);
	} else {
		TextDrawHideForPlayer(playerid, TD_RoundBar_Defend[0]);
		TextDrawShowForPlayer(playerid, TD_RoundBar_Defend[1]);
	}
}
//------------------------------------------------------------------------------
#define showCaptureBar(%1) \
	TextDrawShowForPlayer(%1, TD_Round_Capture_Static[0]);\
	TextDrawShowForPlayer(%1, TD_Round_Capture_Static[1]);\
	TextDrawShowForPlayer(%1, TD_Round_Capture_Box);\
	TextDrawShowForPlayer(%1, TD_Round_Capture_Info)
//------------------------------------------------------------------------------	
#define hideCaptureBar(%1) \
	TextDrawHideForPlayer(%1, TD_Round_Capture_Static[0]);\
	TextDrawHideForPlayer(%1, TD_Round_Capture_Static[1]);\
	TextDrawHideForPlayer(%1, TD_Round_Capture_Box);\
	TextDrawHideForPlayer(%1, TD_Round_Capture_Info)
//------------------------------------------------------------------------------	
#define hideCaptureBarForAll() \
	TextDrawHideForAll(TD_Round_Capture_Static[0]);\
	TextDrawHideForAll(TD_Round_Capture_Static[1]);\
	TextDrawHideForAll(TD_Round_Capture_Box);\
	TextDrawHideForAll(TD_Round_Capture_Info)	
//------------------------------------------------------------------------------
showBackToBasePlayerInfo(&playerid) {
    TextDrawShowForPlayer(playerid, TD_Round_BTB_Player_Static);
    TextDrawShowForPlayer(playerid, TD_Round_BTB_Player_Info);
}
//------------------------------------------------------------------------------
hideBackToBasePlayerInfo(&playerid) {
    TextDrawHideForPlayer(playerid, TD_Round_BTB_Player_Static);
    TextDrawHideForPlayer(playerid, TD_Round_BTB_Player_Info);
}	
//------------------------------------------------------------------------------
hideBackToBasePlayerInfoForAll() {
    TextDrawHideForAll(TD_Round_BTB_Player_Static);
    TextDrawHideForAll(TD_Round_BTB_Player_Info);
}
//------------------------------------------------------------------------------
showBackToBaseInfo(&playerid) {
    TextDrawShowForPlayer(playerid, TD_Round_BTB_Static);
    TextDrawShowForPlayer(playerid, TD_Round_BTB_Info);
}
//------------------------------------------------------------------------------
hideBackToBaseInfo(&playerid) {
    TextDrawHideForPlayer(playerid, TD_Round_BTB_Static);
    TextDrawHideForPlayer(playerid, TD_Round_BTB_Info);
}
//------------------------------------------------------------------------------
hideBackToBaseInfoForAll() {
    TextDrawHideForAll(TD_Round_BTB_Static);
    TextDrawHideForAll(TD_Round_BTB_Info);
}
//------------------------------------------------------------------------------
showPlayerEndRoundInfo(&playerid) {
	for(new x = 0; x < sizeof(TD_Round_End_Static); x ++) TextDrawShowForPlayer(playerid, TD_Round_End_Static[x]);
	TextDrawShowForPlayer(playerid, TD_Round_End_MapInfo);
	TextDrawShowForPlayer(playerid, TD_Round_End_WinInfo);
	TextDrawShowForPlayer(playerid, TD_Round_End_Reason);
	TextDrawShowForPlayer(playerid, TD_Round_End_Top_Nicks);
	TextDrawShowForPlayer(playerid, TD_Round_End_Top_Teams);
	TextDrawShowForPlayer(playerid, TD_Round_End_Top_Points);
}
//------------------------------------------------------------------------------
hidePlayerEndRoundInfo(&playerid) {
	for(new x = 0; x < sizeof(TD_Round_End_Static); x ++) TextDrawHideForPlayer(playerid, TD_Round_End_Static[x]);
	TextDrawHideForPlayer(playerid, TD_Round_End_MapInfo);
	TextDrawHideForPlayer(playerid, TD_Round_End_WinInfo);
	TextDrawHideForPlayer(playerid, TD_Round_End_Reason);
	TextDrawHideForPlayer(playerid, TD_Round_End_Top_Nicks);
	TextDrawHideForPlayer(playerid, TD_Round_End_Top_Teams);
	TextDrawHideForPlayer(playerid, TD_Round_End_Top_Points);
}
//------------------------------------------------------------------------------
showPlayerEndMatchInfo(&playerid) {
	new x;
	for(x = 0; x < sizeof(TD_Round_Match_End_Static); x ++) TextDrawShowForPlayer(playerid, TD_Round_Match_End_Static[x]);
	for(x = 0; x < 2; x ++) {
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TNames[x]);
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TPoints[x]);
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TRounds[x]);
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TPlayers[x]);
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TDamage[x]);
		TextDrawShowForPlayer(playerid, TD_Round_Match_End_TKills[x]);
	}
	TextDrawShowForPlayer(playerid, TD_Round_Match_Result_WWW);
	TextDrawShowForPlayer(playerid, TD_Round_Match_End_Winner);
	TextDrawShowForPlayer(playerid, TD_Round_Match_End_Rounds);
}
//------------------------------------------------------------------------------
hidePlayerEndMatchInfo(&playerid) {
	new x;
	for(x = 0; x < sizeof(TD_Round_Match_End_Static); x ++) TextDrawHideForPlayer(playerid, TD_Round_Match_End_Static[x]);
	for(x = 0; x < 2; x ++) {
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TNames[x]);
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TPoints[x]);
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TRounds[x]);
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TPlayers[x]);
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TDamage[x]);
		TextDrawHideForPlayer(playerid, TD_Round_Match_End_TKills[x]);
	}
	TextDrawHideForPlayer(playerid, TD_Round_Match_Result_WWW);
	TextDrawHideForPlayer(playerid, TD_Round_Match_End_Winner);
	TextDrawHideForPlayer(playerid, TD_Round_Match_End_Rounds);
}
//------------------------------------------------------------------------------
showPlayerHud(playerid) {
	if(TEAM_ONE <= getPlayerTeam(playerid) <= TEAM_REF) {
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_NickAndTeam_Static);
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_TeamNames[getPlayerTeam(playerid)]);
		
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_FPSPingPLossStatic[0]);
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_FPSPingPLossStatic[1]);
		
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_Stats_Static[0]);
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_Stats_Static[1]);
		
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_Nick[playerid]);
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_Health[playerid]);
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_Armour[playerid]);
		
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_Ping[playerid]);
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_FPS[playerid]);
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_PLoss[playerid]);	
		PlayerTextDrawShow(playerid, PTD_PlayerHUD_Stats[playerid]);		
		
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
hidePlayerHud(playerid, bool:spec_mode = false) {	

	TextDrawHideForPlayer(playerid, TD_PlayerHUD_Stats_Static[0]);
	TextDrawHideForPlayer(playerid, TD_PlayerHUD_Stats_Static[1]);		
	
	PlayerTextDrawHide(playerid, PTD_PlayerHUD_Health[playerid]);
	PlayerTextDrawHide(playerid, PTD_PlayerHUD_Armour[playerid]);	
	PlayerTextDrawHide(playerid, PTD_PlayerHUD_Stats[playerid]);	
	
	if(!spec_mode) {
		TextDrawHideForPlayer(playerid, TD_PlayerHUD_TeamNames[getPlayerTeam(playerid)]);
		TextDrawHideForPlayer(playerid, TD_PlayerHUD_NickAndTeam_Static);
		TextDrawHideForPlayer(playerid, TD_PlayerHUD_FPSPingPLossStatic[0]);
		TextDrawHideForPlayer(playerid, TD_PlayerHUD_FPSPingPLossStatic[1]);	
	
		PlayerTextDrawHide(playerid, PTD_PlayerHUD_Nick[playerid]);
		PlayerTextDrawHide(playerid, PTD_PlayerHUD_Ping[playerid]);
		PlayerTextDrawHide(playerid, PTD_PlayerHUD_FPS[playerid]);
		PlayerTextDrawHide(playerid, PTD_PlayerHUD_PLoss[playerid]);				
	}	
}
//------------------------------------------------------------------------------
hidePlayerAimedInfo(&playerid) {
	PlayerTextDrawHide(playerid, PTD_AimedPlayer_Nick[playerid]);
//	PlayerTextDrawHide(playerid, PTD_AimedPlayer_Ping[playerid]);
	PlayerTextDrawHide(playerid, PTD_AimedPlayer_FPS[playerid]);
	PlayerTextDrawHide(playerid, PTD_AimedPlayer_PLoss[playerid]);
	TextDrawHideForPlayer(playerid, TD_AimedPlayer_Static[0]);
	TextDrawHideForPlayer(playerid, TD_AimedPlayer_Static[1]);
}
//------------------------------------------------------------------------------
showPlayerSpectatorTextDraws(&playerid) {
	TextDrawShowForPlayer(playerid, TD_Spectator_Static[0]);
	TextDrawShowForPlayer(playerid, TD_Spectator_Static[1]);
	
	PlayerTextDrawShow(playerid, PTD_Spectator_Nick[playerid]);
	PlayerTextDrawShow(playerid, PTD_Spectator_HealthAndArmour[playerid]);
	PlayerTextDrawShow(playerid, PTD_Spectator_NetStats[playerid]);
	PlayerTextDrawShow(playerid, PTD_Spectator_Guns[playerid][0]);
	PlayerTextDrawShow(playerid, PTD_Spectator_Guns[playerid][1]);
}
//------------------------------------------------------------------------------
hidePlayerSpectatorTextDraws(&playerid) {
	TextDrawHideForPlayer(playerid, TD_Spectator_Static[0]);
	TextDrawHideForPlayer(playerid, TD_Spectator_Static[1]);
	
	PlayerTextDrawHide(playerid, PTD_Spectator_Nick[playerid]);
	PlayerTextDrawHide(playerid, PTD_Spectator_HealthAndArmour[playerid]);
	PlayerTextDrawHide(playerid, PTD_Spectator_NetStats[playerid]);
	PlayerTextDrawHide(playerid, PTD_Spectator_Guns[playerid][0]);	
	PlayerTextDrawHide(playerid, PTD_Spectator_Guns[playerid][1]);
}
//------------------------------------------------------------------------------
hideHelpIcon(&playerid, &teamid) {
	TextDrawHideForPlayer(playerid, TD_Round_Help_Static[0]);
	TextDrawHideForPlayer(playerid, TD_Round_Help_Static[1]);
	TextDrawHideForPlayer(playerid, TD_Round_Help_Nick[teamid]);
	RemovePlayerMapIcon(playerid, ICON_ROUND_HELP);
}
//------------------------------------------------------------------------------
hideHelpIconForAll() {
	TextDrawHideForAll(TD_Round_Help_Static[0]);
	TextDrawHideForAll(TD_Round_Help_Static[1]);
	TextDrawHideForAll(TD_Round_Help_Nick[TEAM_ONE]);
	TextDrawHideForAll(TD_Round_Help_Nick[TEAM_TWO]);
	forplayers(i) RemovePlayerMapIcon(i, ICON_ROUND_HELP);
}
//------------------------------------------------------------------------------
hideTeamHealthInfoForAll() {
	for(new i; i < 2; i ++) {
		TextDrawHideForAll(TD_Round_Team_PlayersHealth[i]);
		TextDrawHideForAll(TD_Spectator_Team_PlayersHealth[i]);
	}		
}
//------------------------------------------------------------------------------
showTeamHealthInfoForAll() {
	new x;
	forplayers(i) {
		if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {
			if(getPlayerStatus(i) == PLAYER_STATUS_SPECTATE || getPlayerTeam(i) == TEAM_REF) {
				for(x = 0; x < 2; x ++) TextDrawShowForPlayer(i, TD_Spectator_Team_PlayersHealth[x]);
			} else {
				TextDrawShowForPlayer(i, TD_Round_Team_PlayersHealth[getPlayerTeam(i)]);
			}
		}
	}
}				
//------------------------------------------------------------------------------
hideZPosCheckpointInfo(&playerid) {
    TextDrawHideForPlayer(playerid, TD_Round_CP_Map_ZPos[0]);
    TextDrawHideForPlayer(playerid, TD_Round_CP_Map_ZPos[1]);
    TextDrawHideForPlayer(playerid, TD_Round_CP_Map_ZPos[2]);
}
//------------------------------------------------------------------------------
showCrashAddInfoForPlayer(&playerid) {
	for(new i; i < sizeof(TD_Round_CrashAdd_Static); i ++) {
		TextDrawShowForPlayer(playerid, TD_Round_CrashAdd_Static[i]);
	}
}
//------------------------------------------------------------------------------
hideCrashAddInfoForPlayer(&playerid) {
	for(new i; i < sizeof(TD_Round_CrashAdd_Static); i ++) {
		TextDrawHideForPlayer(playerid, TD_Round_CrashAdd_Static[i]);
	}
}
//------------------------------------------------------------------------------
hideCrashAddInfoForAll() {
	for(new i; i < sizeof(TD_Round_CrashAdd_Static); i ++) {
		TextDrawHideForAll(TD_Round_CrashAdd_Static[i]);
	}
}
//------------------------------------------------------------------------------
showPlayerArenaTDMTextDraw(&playerid) {
	TextDrawShowForPlayer(playerid, TD_ArenaTDM_Static);
	TextDrawShowForPlayer(playerid, TD_ArenaTDM_Info);
}
//------------------------------------------------------------------------------
hidePlayerArenaTDMTextDraw(&playerid) {
	TextDrawHideForPlayer(playerid, TD_ArenaTDM_Static);
	TextDrawHideForPlayer(playerid, TD_ArenaTDM_Info);
}
//------------------------------------------------------------------------------
hideArenaTDMTextDraw() {
	TextDrawHideForAll(TD_ArenaTDM_Static);
	TextDrawHideForAll(TD_ArenaTDM_Info);
}
//------------------------------------------------------------------------------
showPlayerVehicleHealthInfo(&playerid) {
	TextDrawShowForPlayer(playerid, TD_VehicleHealth_Static[0]);
	TextDrawShowForPlayer(playerid, TD_VehicleHealth_Static[1]);
	PlayerTextDrawShow(playerid, PTD_VehicleHealth_Box[playerid]);
	PlayerTextDrawShow(playerid, PTD_VehicleHealth_Info[0]);
}
//------------------------------------------------------------------------------
hidePlayerVehicleHealthInfo(&playerid) {
	TextDrawHideForPlayer(playerid, TD_VehicleHealth_Static[0]);
	TextDrawHideForPlayer(playerid, TD_VehicleHealth_Static[1]);
	PlayerTextDrawHide(playerid, PTD_VehicleHealth_Box[playerid]);
	PlayerTextDrawHide(playerid, PTD_VehicleHealth_Info[0]);
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
createGlobalTextDraws() {
	new string[32];
    //415.000000, 337.000000
	TD_RequestStatic[0] = TextDrawCreate(getRequestClassBoxPos(0), getRequestClassBoxPos(1), "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_RequestStatic[0], 255);
	TextDrawFont(TD_RequestStatic[0], 4);
	TextDrawLetterSize(TD_RequestStatic[0], 0.500000, 1.000000);
	TextDrawColor(TD_RequestStatic[0], 80);
	TextDrawSetOutline(TD_RequestStatic[0], 0);
	TextDrawSetProportional(TD_RequestStatic[0], 1);
	TextDrawSetShadow(TD_RequestStatic[0], 1);
	TextDrawUseBox(TD_RequestStatic[0], 1);
	TextDrawBoxColor(TD_RequestStatic[0], 255);
	TextDrawTextSize(TD_RequestStatic[0], 130.000000, 50.000000);
	//416.000000, 338.000000
	TD_RequestStatic[1] = TextDrawCreate(getRequestClassBoxPos(0) + 1.0, getRequestClassBoxPos(1) + 1.0, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_RequestStatic[1], 255);
	TextDrawFont(TD_RequestStatic[1], 4);
	TextDrawLetterSize(TD_RequestStatic[1], 0.500000, 1.000000);
	TextDrawColor(TD_RequestStatic[1], 80);
	TextDrawSetOutline(TD_RequestStatic[1], 0);
	TextDrawSetProportional(TD_RequestStatic[1], 1);
	TextDrawSetShadow(TD_RequestStatic[1], 1);
	TextDrawUseBox(TD_RequestStatic[1], 1);
	TextDrawBoxColor(TD_RequestStatic[1], 255);
	TextDrawTextSize(TD_RequestStatic[1], 128.000000, 48.000000);
	//480.000000, 340.000000
	TD_RequestStatic[2] = TextDrawCreate(getRequestClassBoxPos(0) + 65.0, getRequestClassBoxPos(1) + 3.0, "Wybierz druzyne");
	TextDrawAlignment(TD_RequestStatic[2], 2);
	TextDrawBackgroundColor(TD_RequestStatic[2], 255);
	TextDrawFont(TD_RequestStatic[2], 1);
	TextDrawLetterSize(TD_RequestStatic[2], 0.250000, 1.200000);
	TextDrawColor(TD_RequestStatic[2], 74764031);
	TextDrawSetOutline(TD_RequestStatic[2], 0);
	TextDrawSetProportional(TD_RequestStatic[2], 1);
	TextDrawSetShadow(TD_RequestStatic[2], 1);
	//484.000000, 368.000000
	TD_RequestStatic[3] = TextDrawCreate(getRequestClassBoxPos(0) + 69.0, getRequestClassBoxPos(1) + 31.0, "Skin ID:_~n~Haslo:");
	TextDrawAlignment(TD_RequestStatic[3], 3);
	TextDrawBackgroundColor(TD_RequestStatic[3], 255);
	TextDrawFont(TD_RequestStatic[3], 1);
	TextDrawLetterSize(TD_RequestStatic[3], 0.150000, 0.799998);
	TextDrawColor(TD_RequestStatic[3], 74764031);
	TextDrawSetOutline(TD_RequestStatic[3], 0);
	TextDrawSetProportional(TD_RequestStatic[3], 1);
	TextDrawSetShadow(TD_RequestStatic[3], 1);
	//473.000000, 355.000000
	TD_RequestStatic[4] = TextDrawCreate(getRequestClassBoxPos(0) + 58.0, getRequestClassBoxPos(1) + 18.0, "~<~__________~>~");
	TextDrawAlignment(TD_RequestStatic[4], 2);
	TextDrawBackgroundColor(TD_RequestStatic[4], 255);
	TextDrawFont(TD_RequestStatic[4], 1);
	TextDrawLetterSize(TD_RequestStatic[4], 0.500000, 1.000000);
	TextDrawColor(TD_RequestStatic[4], -1);
	TextDrawSetOutline(TD_RequestStatic[4], 0);
	TextDrawSetProportional(TD_RequestStatic[4], 1);
	TextDrawSetShadow(TD_RequestStatic[4], 1);
	//480.000000, 354.000000
	TD_RequestTeamName[0] = TextDrawCreate(getRequestClassBoxPos(0) + 65.0, getRequestClassBoxPos(1) + 17.0, " "); //getTeamName(TEAM_ONE)
	TextDrawAlignment(TD_RequestTeamName[0], 2);
	TextDrawBackgroundColor(TD_RequestTeamName[0], 255);
	TextDrawFont(TD_RequestTeamName[0], 1);
	TextDrawLetterSize(TD_RequestTeamName[0], 0.250000, 1.200000);
	TextDrawColor(TD_RequestTeamName[0], getTeamColorInt(TEAM_ONE, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_RequestTeamName[0], 0);
	TextDrawSetProportional(TD_RequestTeamName[0], 1);
	TextDrawSetShadow(TD_RequestTeamName[0], 1);
	//480.000000, 354.000000
	TD_RequestTeamName[1] = TextDrawCreate(getRequestClassBoxPos(0) + 65.0, getRequestClassBoxPos(1) + 17.0, " "); //getTeamName(TEAM_TWO)
	TextDrawAlignment(TD_RequestTeamName[1], 2);
	TextDrawBackgroundColor(TD_RequestTeamName[1], 255);
	TextDrawFont(TD_RequestTeamName[1], 1);
	TextDrawLetterSize(TD_RequestTeamName[1], 0.250000, 1.200000);
	TextDrawColor(TD_RequestTeamName[1], getTeamColorInt(TEAM_TWO, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_RequestTeamName[1], 0);
	TextDrawSetProportional(TD_RequestTeamName[1], 1);
	TextDrawSetShadow(TD_RequestTeamName[1], 1);
	//480.000000, 354.000000
	TD_RequestTeamName[2] = TextDrawCreate(getRequestClassBoxPos(0) + 65.0, getRequestClassBoxPos(1) + 17.0, " "); //getTeamName(TEAM_REF)
	TextDrawAlignment(TD_RequestTeamName[2], 2);
	TextDrawBackgroundColor(TD_RequestTeamName[2], 255);
	TextDrawFont(TD_RequestTeamName[2], 1);
	TextDrawLetterSize(TD_RequestTeamName[2], 0.250000, 1.200000);
	TextDrawColor(TD_RequestTeamName[2], getTeamColorInt(TEAM_REF, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_RequestTeamName[2], 0);
	TextDrawSetProportional(TD_RequestTeamName[2], 1);
	TextDrawSetShadow(TD_RequestTeamName[2], 1);
	//486.000000, 368.000000
	format(string, sizeof(string),"%d~n~Nie", getTeamSkin(TEAM_ONE));
	TD_RequestTeamInfo[0] = TextDrawCreate(getRequestClassBoxPos(0) + 71.0, getRequestClassBoxPos(1) + 31.0, string);
	TextDrawBackgroundColor(TD_RequestTeamInfo[0], 255);
	TextDrawFont(TD_RequestTeamInfo[0], 1);
	TextDrawLetterSize(TD_RequestTeamInfo[0], 0.150000, 0.799998);
	TextDrawColor(TD_RequestTeamInfo[0], -35);
	TextDrawSetOutline(TD_RequestTeamInfo[0], 0);
	TextDrawSetProportional(TD_RequestTeamInfo[0], 1);
	TextDrawSetShadow(TD_RequestTeamInfo[0], 1);
	//486.000000, 368.000000
    format(string, sizeof(string),"%d~n~Nie", getTeamSkin(TEAM_TWO));
	TD_RequestTeamInfo[1] = TextDrawCreate(getRequestClassBoxPos(0) + 71.0, getRequestClassBoxPos(1) + 31.0, string);
	TextDrawBackgroundColor(TD_RequestTeamInfo[1], 255);
	TextDrawFont(TD_RequestTeamInfo[1], 1);
	TextDrawLetterSize(TD_RequestTeamInfo[1], 0.150000, 0.799998);
	TextDrawColor(TD_RequestTeamInfo[1], -35);
	TextDrawSetOutline(TD_RequestTeamInfo[1], 0);
	TextDrawSetProportional(TD_RequestTeamInfo[1], 1);
	TextDrawSetShadow(TD_RequestTeamInfo[1], 1);
	//486.000000, 368.000000
	format(string, sizeof(string),"%d~n~Nie", getTeamSkin(TEAM_REF));
	TD_RequestTeamInfo[2] = TextDrawCreate(getRequestClassBoxPos(0) + 71.0, getRequestClassBoxPos(1) + 31.0, string);
	TextDrawBackgroundColor(TD_RequestTeamInfo[2], 255);
	TextDrawFont(TD_RequestTeamInfo[2], 1);
	TextDrawLetterSize(TD_RequestTeamInfo[2], 0.150000, 0.799998);
	TextDrawColor(TD_RequestTeamInfo[2], -35);
	TextDrawSetOutline(TD_RequestTeamInfo[2], 0);
	TextDrawSetProportional(TD_RequestTeamInfo[2], 1);
	TextDrawSetShadow(TD_RequestTeamInfo[2], 1);
	//--------------------------------------------------------------------------
	TD_Round_Start_Static[0] = TextDrawCreate(320.000000, 0.000000, "_");
	TextDrawAlignment(TD_Round_Start_Static[0], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[0], 255);
	TextDrawFont(TD_Round_Start_Static[0], 1);
	TextDrawLetterSize(TD_Round_Start_Static[0], 0.500000, 6.000000);
	TextDrawColor(TD_Round_Start_Static[0], -1);
	TextDrawSetOutline(TD_Round_Start_Static[0], 0);
	TextDrawSetProportional(TD_Round_Start_Static[0], 1);
	TextDrawSetShadow(TD_Round_Start_Static[0], 1);
	TextDrawUseBox(TD_Round_Start_Static[0], 1);
	TextDrawBoxColor(TD_Round_Start_Static[0], 255);
	TextDrawTextSize(TD_Round_Start_Static[0], 0.000000, 640.000000);

	TD_Round_Start_Static[1] = TextDrawCreate(320.000000, 393.000000, "_");
	TextDrawAlignment(TD_Round_Start_Static[1], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[1], 255);
	TextDrawFont(TD_Round_Start_Static[1], 1);
	TextDrawLetterSize(TD_Round_Start_Static[1], 0.500000, 6.000000);
	TextDrawColor(TD_Round_Start_Static[1], -1);
	TextDrawSetOutline(TD_Round_Start_Static[1], 0);
	TextDrawSetProportional(TD_Round_Start_Static[1], 1);
	TextDrawSetShadow(TD_Round_Start_Static[1], 1);
	TextDrawUseBox(TD_Round_Start_Static[1], 1);
	TextDrawBoxColor(TD_Round_Start_Static[1], 255);
	TextDrawTextSize(TD_Round_Start_Static[1], 0.000000, 640.000000);

	TD_Round_Start_Static[2] = TextDrawCreate(-10.000000, 55.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_Round_Start_Static[2], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[2], 255);
	TextDrawFont(TD_Round_Start_Static[2], 4);
	TextDrawLetterSize(TD_Round_Start_Static[2], 0.490000, 2.000000);
	TextDrawColor(TD_Round_Start_Static[2], 126869759);
	TextDrawSetOutline(TD_Round_Start_Static[2], 0);
	TextDrawSetProportional(TD_Round_Start_Static[2], 1);
	TextDrawSetShadow(TD_Round_Start_Static[2], 1);
	TextDrawUseBox(TD_Round_Start_Static[2], 1);
	TextDrawBoxColor(TD_Round_Start_Static[2], -16776961);
	TextDrawTextSize(TD_Round_Start_Static[2], 660.000000, 1.000000);

	TD_Round_Start_Static[3] = TextDrawCreate(-10.000000, 391.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_Round_Start_Static[3], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[3], 255);
	TextDrawFont(TD_Round_Start_Static[3], 4);
	TextDrawLetterSize(TD_Round_Start_Static[3], 0.490000, 2.000000);
	TextDrawColor(TD_Round_Start_Static[3], 126869759);
	TextDrawSetOutline(TD_Round_Start_Static[3], 0);
	TextDrawSetProportional(TD_Round_Start_Static[3], 1);
	TextDrawSetShadow(TD_Round_Start_Static[3], 1);
	TextDrawUseBox(TD_Round_Start_Static[3], 1);
	TextDrawBoxColor(TD_Round_Start_Static[3], -16776961);
	TextDrawTextSize(TD_Round_Start_Static[3], 660.000000, 1.000000);
	
	TD_Round_Start_Static[4] = TextDrawCreate(273.000000, 34.000000, "LD_POOL:ball");
	TextDrawAlignment(TD_Round_Start_Static[4], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[4], 255);
	TextDrawFont(TD_Round_Start_Static[4], 4);
	TextDrawLetterSize(TD_Round_Start_Static[4], 0.500000, 1.000000);
	TextDrawColor(TD_Round_Start_Static[4], 126869691);
	TextDrawSetOutline(TD_Round_Start_Static[4], 0);
	TextDrawSetProportional(TD_Round_Start_Static[4], 1);
	TextDrawSetShadow(TD_Round_Start_Static[4], 1);
	TextDrawUseBox(TD_Round_Start_Static[4], 1);
	TextDrawBoxColor(TD_Round_Start_Static[4], -16776961);
	TextDrawTextSize(TD_Round_Start_Static[4], 94.000000, 1.000000);

	TD_Round_Start_Static[5] = TextDrawCreate(320.000000, 399.000000, "Vs");
	TextDrawAlignment(TD_Round_Start_Static[5], 2);
	TextDrawBackgroundColor(TD_Round_Start_Static[5], 255);
	TextDrawFont(TD_Round_Start_Static[5], 1);
	TextDrawLetterSize(TD_Round_Start_Static[5], 0.500000, 2.299999);
	TextDrawColor(TD_Round_Start_Static[5], 126869759);
	TextDrawSetOutline(TD_Round_Start_Static[5], 0);
	TextDrawSetProportional(TD_Round_Start_Static[5], 1);
	TextDrawSetShadow(TD_Round_Start_Static[5], 1);
		
	TD_Round_Start_Map = TextDrawCreate(320.000000, 14.000000, " ");
	TextDrawAlignment(TD_Round_Start_Map, 2);
	TextDrawBackgroundColor(TD_Round_Start_Map, 255);
	TextDrawFont(TD_Round_Start_Map, 1);
	TextDrawLetterSize(TD_Round_Start_Map, 0.500000, 2.299999);
	TextDrawColor(TD_Round_Start_Map, 126869759);
	TextDrawSetOutline(TD_Round_Start_Map, 0);
	TextDrawSetProportional(TD_Round_Start_Map, 1);
	TextDrawSetShadow(TD_Round_Start_Map, 1);	

	TD_Round_Start_Teams[0] = TextDrawCreate(303.000000, 403.000000, " ");
	TextDrawAlignment(TD_Round_Start_Teams[0], 3);
	TextDrawBackgroundColor(TD_Round_Start_Teams[0], 255);
	TextDrawFont(TD_Round_Start_Teams[0], 1);
	TextDrawLetterSize(TD_Round_Start_Teams[0], 0.350000, 1.699999);
	TextDrawColor(TD_Round_Start_Teams[0], -858993409);
	TextDrawSetOutline(TD_Round_Start_Teams[0], 0);
	TextDrawSetProportional(TD_Round_Start_Teams[0], 1);
	TextDrawSetShadow(TD_Round_Start_Teams[0], 1);

	TD_Round_Start_Teams[1] = TextDrawCreate(338.000000, 403.000000, " ");
	TextDrawBackgroundColor(TD_Round_Start_Teams[1], 255);
	TextDrawFont(TD_Round_Start_Teams[1], 1);
	TextDrawLetterSize(TD_Round_Start_Teams[1], 0.350000, 1.699999);
	TextDrawColor(TD_Round_Start_Teams[1], -858993409);
	TextDrawSetOutline(TD_Round_Start_Teams[1], 0);
	TextDrawSetProportional(TD_Round_Start_Teams[1], 1);
	TextDrawSetShadow(TD_Round_Start_Teams[1], 1);

	TD_Round_Start_Round = TextDrawCreate(320.000000, 425.000000, " ");
	TextDrawAlignment(TD_Round_Start_Round, 2);
	TextDrawBackgroundColor(TD_Round_Start_Round, 255);
	TextDrawFont(TD_Round_Start_Round, 1);
	TextDrawLetterSize(TD_Round_Start_Round, 0.260000, 1.399999);
	TextDrawColor(TD_Round_Start_Round, 126869759);
	TextDrawSetOutline(TD_Round_Start_Round, 0);
	TextDrawSetProportional(TD_Round_Start_Round, 1);
	TextDrawSetShadow(TD_Round_Start_Round, 1);	

	//--------------------------------------------------------------------------
	TD_RoundBar_Static[0] = TextDrawCreate(265.000000, 420.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_RoundBar_Static[0], 255);
	TextDrawFont(TD_RoundBar_Static[0], 4);
	TextDrawLetterSize(TD_RoundBar_Static[0], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[0], 48);
	TextDrawSetOutline(TD_RoundBar_Static[0], 0);
	TextDrawSetProportional(TD_RoundBar_Static[0], 1);
	TextDrawSetShadow(TD_RoundBar_Static[0], 1);
	TextDrawUseBox(TD_RoundBar_Static[0], 1);
	TextDrawBoxColor(TD_RoundBar_Static[0], 80);
	TextDrawTextSize(TD_RoundBar_Static[0], 110.000000, 38.000000);


	TD_RoundBar_Static[1] = TextDrawCreate(94.500000, 435.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_RoundBar_Static[1], 255);
	TextDrawFont(TD_RoundBar_Static[1], 4);
	TextDrawLetterSize(TD_RoundBar_Static[1], 0.509998, 1.000000);
	TextDrawColor(TD_RoundBar_Static[1], 48);
	TextDrawSetOutline(TD_RoundBar_Static[1], 0);
	TextDrawSetProportional(TD_RoundBar_Static[1], 1);
	TextDrawSetShadow(TD_RoundBar_Static[1], 1);
	TextDrawUseBox(TD_RoundBar_Static[1], 1);
	TextDrawBoxColor(TD_RoundBar_Static[1], 80);
	TextDrawTextSize(TD_RoundBar_Static[1], 160.000000, 20.000000);

	TD_RoundBar_Static[2] = TextDrawCreate(174.500000, 438.000000, "_");
	TextDrawAlignment(TD_RoundBar_Static[2], 2);
	TextDrawBackgroundColor(TD_RoundBar_Static[2], 255);
	TextDrawFont(TD_RoundBar_Static[2], 1);
	TextDrawLetterSize(TD_RoundBar_Static[2], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Static[2], -1);
	TextDrawSetOutline(TD_RoundBar_Static[2], 0);
	TextDrawSetProportional(TD_RoundBar_Static[2], 1);
	TextDrawSetShadow(TD_RoundBar_Static[2], 1);
	TextDrawUseBox(TD_RoundBar_Static[2], 1);
	TextDrawBoxColor(TD_RoundBar_Static[2], 48);
	TextDrawTextSize(TD_RoundBar_Static[2], 0.000000, 155.000000);

	TD_RoundBar_Static[3] = TextDrawCreate(385.500000, 435.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_RoundBar_Static[3], 255);
	TextDrawFont(TD_RoundBar_Static[3], 4);
	TextDrawLetterSize(TD_RoundBar_Static[3], 0.509998, 1.000000);
	TextDrawColor(TD_RoundBar_Static[3], 48);
	TextDrawSetOutline(TD_RoundBar_Static[3], 0);
	TextDrawSetProportional(TD_RoundBar_Static[3], 1);
	TextDrawSetShadow(TD_RoundBar_Static[3], 1);
	TextDrawUseBox(TD_RoundBar_Static[3], 1);
	TextDrawBoxColor(TD_RoundBar_Static[3], 80);
	TextDrawTextSize(TD_RoundBar_Static[3], 160.000000, 20.000000);

	TD_RoundBar_Static[4] = TextDrawCreate(465.500000, 438.000000, "_");
	TextDrawAlignment(TD_RoundBar_Static[4], 2);
	TextDrawBackgroundColor(TD_RoundBar_Static[4], 255);
	TextDrawFont(TD_RoundBar_Static[4], 1);
	TextDrawLetterSize(TD_RoundBar_Static[4], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Static[4], -1);
	TextDrawSetOutline(TD_RoundBar_Static[4], 0);
	TextDrawSetProportional(TD_RoundBar_Static[4], 1);
	TextDrawSetShadow(TD_RoundBar_Static[4], 1);
	TextDrawUseBox(TD_RoundBar_Static[4], 1);
	TextDrawBoxColor(TD_RoundBar_Static[4], 48);
	TextDrawTextSize(TD_RoundBar_Static[4], 0.000000, 155.000000);

	TD_RoundBar_Static[5] = TextDrawCreate(194.000000, 442.000000, "hud:radar_girlfriend");
	TextDrawBackgroundColor(TD_RoundBar_Static[5], 255);
	TextDrawFont(TD_RoundBar_Static[5], 4);
	TextDrawLetterSize(TD_RoundBar_Static[5], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[5], -1);
	TextDrawSetOutline(TD_RoundBar_Static[5], 0);
	TextDrawSetProportional(TD_RoundBar_Static[5], 1);
	TextDrawSetShadow(TD_RoundBar_Static[5], 1);
	TextDrawUseBox(TD_RoundBar_Static[5], 1);
	TextDrawBoxColor(TD_RoundBar_Static[5], 255);
	TextDrawTextSize(TD_RoundBar_Static[5], 5.000000, 5.000000);

	TD_RoundBar_Static[6] = TextDrawCreate(441.000000, 442.000000, "hud:radar_girlfriend");
	TextDrawBackgroundColor(TD_RoundBar_Static[6], 255);
	TextDrawFont(TD_RoundBar_Static[6], 4);
	TextDrawLetterSize(TD_RoundBar_Static[6], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[6], -1);
	TextDrawSetOutline(TD_RoundBar_Static[6], 0);
	TextDrawSetProportional(TD_RoundBar_Static[6], 1);
	TextDrawSetShadow(TD_RoundBar_Static[6], 1);
	TextDrawUseBox(TD_RoundBar_Static[6], 1);
	TextDrawBoxColor(TD_RoundBar_Static[6], 255);
	TextDrawTextSize(TD_RoundBar_Static[6], 5.000000, 5.000000);

	TD_RoundBar_Static[7] = TextDrawCreate(212.500000, 442.000000, "hud:radar_gangB");
	TextDrawBackgroundColor(TD_RoundBar_Static[7], 255);
	TextDrawFont(TD_RoundBar_Static[7], 4);
	TextDrawLetterSize(TD_RoundBar_Static[7], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[7], -1);
	TextDrawSetOutline(TD_RoundBar_Static[7], 0);
	TextDrawSetProportional(TD_RoundBar_Static[7], 1);
	TextDrawSetShadow(TD_RoundBar_Static[7], 1);
	TextDrawUseBox(TD_RoundBar_Static[7], 1);
	TextDrawBoxColor(TD_RoundBar_Static[7], 255);
	TextDrawTextSize(TD_RoundBar_Static[7], 5.000000, 5.000000);

	TD_RoundBar_Static[8] = TextDrawCreate(421.000000, 442.000000, "hud:radar_gangB");
	TextDrawBackgroundColor(TD_RoundBar_Static[8], 255);
	TextDrawFont(TD_RoundBar_Static[8], 4);
	TextDrawLetterSize(TD_RoundBar_Static[8], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[8], -1);
	TextDrawSetOutline(TD_RoundBar_Static[8], 0);
	TextDrawSetProportional(TD_RoundBar_Static[8], 1);
	TextDrawSetShadow(TD_RoundBar_Static[8], 1);
	TextDrawUseBox(TD_RoundBar_Static[8], 1);
	TextDrawBoxColor(TD_RoundBar_Static[8], 255);
	TextDrawTextSize(TD_RoundBar_Static[8], 5.000000, 5.000000);

	TD_RoundBar_Static[9] = TextDrawCreate(231.000000, 442.000000, "hud:radar_race");
	TextDrawBackgroundColor(TD_RoundBar_Static[9], 255);
	TextDrawFont(TD_RoundBar_Static[9], 4);
	TextDrawLetterSize(TD_RoundBar_Static[9], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[9], -202826241);
	TextDrawSetOutline(TD_RoundBar_Static[9], 0);
	TextDrawSetProportional(TD_RoundBar_Static[9], 1);
	TextDrawSetShadow(TD_RoundBar_Static[9], 1);
	TextDrawUseBox(TD_RoundBar_Static[9], 1);
	TextDrawBoxColor(TD_RoundBar_Static[9], 255);
	TextDrawTextSize(TD_RoundBar_Static[9], 5.000000, 5.000000);

	TD_RoundBar_Static[10] = TextDrawCreate(402.000000, 443.000000, "hud:radar_race");
	TextDrawBackgroundColor(TD_RoundBar_Static[10], 255);
	TextDrawFont(TD_RoundBar_Static[10], 4);
	TextDrawLetterSize(TD_RoundBar_Static[10], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Static[10], -202826241);
	TextDrawSetOutline(TD_RoundBar_Static[10], 0);
	TextDrawSetProportional(TD_RoundBar_Static[10], 1);
	TextDrawSetShadow(TD_RoundBar_Static[10], 1);
	TextDrawUseBox(TD_RoundBar_Static[10], 1);
	TextDrawBoxColor(TD_RoundBar_Static[10], 255);
	TextDrawTextSize(TD_RoundBar_Static[10], 5.000000, 5.000000);
		
	TD_RoundBar_Time = TextDrawCreate(320.000000, 423.000000, "--:--"); //99:99
	TextDrawAlignment(TD_RoundBar_Time, 2);
	TextDrawBackgroundColor(TD_RoundBar_Time, 255);
	TextDrawFont(TD_RoundBar_Time, 1);
	TextDrawLetterSize(TD_RoundBar_Time, 0.209998, 1.000000);
	TextDrawColor(TD_RoundBar_Time, -1);
	TextDrawSetOutline(TD_RoundBar_Time, 0);
	TextDrawSetProportional(TD_RoundBar_Time, 1);
	TextDrawSetShadow(TD_RoundBar_Time, 1);
	TextDrawUseBox(TD_RoundBar_Time, 1);
	TextDrawBoxColor(TD_RoundBar_Time, 48);
	TextDrawTextSize(TD_RoundBar_Time, 0.000000, 105.000000);	
	 
	TD_RoundBar_Base = TextDrawCreate(288.000000, 437.000000, "--"); //Base  ~w~88
	TextDrawAlignment(TD_RoundBar_Base, 2);
	TextDrawBackgroundColor(TD_RoundBar_Base, 255);
	TextDrawFont(TD_RoundBar_Base, 1);
	TextDrawLetterSize(TD_RoundBar_Base, 0.209998, 1.000000);
	TextDrawColor(TD_RoundBar_Base, 126869759);
	TextDrawSetOutline(TD_RoundBar_Base, 0);
	TextDrawSetProportional(TD_RoundBar_Base, 1);
	TextDrawSetShadow(TD_RoundBar_Base, 1);
	TextDrawUseBox(TD_RoundBar_Base, 1);
	TextDrawBoxColor(TD_RoundBar_Base, 48);
	TextDrawTextSize(TD_RoundBar_Base, 0.000000, 40.000000);

	TD_RoundBar_Rounds = TextDrawCreate(342.500000, 437.000000, "--"); //Round  ~w~99 / 99
	TextDrawAlignment(TD_RoundBar_Rounds, 2);
	TextDrawBackgroundColor(TD_RoundBar_Rounds, 255);
	TextDrawFont(TD_RoundBar_Rounds, 1);
	TextDrawLetterSize(TD_RoundBar_Rounds, 0.209998, 1.000000);
	TextDrawColor(TD_RoundBar_Rounds, 126869759);	//126869759
	TextDrawSetOutline(TD_RoundBar_Rounds, 0);
	TextDrawSetProportional(TD_RoundBar_Rounds, 1);
	TextDrawSetShadow(TD_RoundBar_Rounds, 1);
	TextDrawUseBox(TD_RoundBar_Rounds, 1);
	TextDrawBoxColor(TD_RoundBar_Rounds, 48);
	TextDrawTextSize(TD_RoundBar_Rounds, 0.000000, 60.000000);

	TD_RoundBar_Name[0] = TextDrawCreate(133.000000, 438.000000, getTeamName(TEAM_ONE));
	TextDrawAlignment(TD_RoundBar_Name[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Name[0], 255);
	TextDrawFont(TD_RoundBar_Name[0], 1);
	TextDrawLetterSize(TD_RoundBar_Name[0], 0.189998, 0.899999);
	TextDrawColor(TD_RoundBar_Name[0], getTeamColorInt(TEAM_ONE, COLOR_STATUS_ACTIVE)); //126869759
	TextDrawSetOutline(TD_RoundBar_Name[0], 0);
	TextDrawSetProportional(TD_RoundBar_Name[0], 1);
	TextDrawSetShadow(TD_RoundBar_Name[0], 1);

	TD_RoundBar_Health[0] = TextDrawCreate(184.000000, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Health[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Health[0], 255);
	TextDrawFont(TD_RoundBar_Health[0], 1);
	TextDrawLetterSize(TD_RoundBar_Health[0], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Health[0], -1);
	TextDrawSetOutline(TD_RoundBar_Health[0], 0);
	TextDrawSetProportional(TD_RoundBar_Health[0], 1);
	TextDrawSetShadow(TD_RoundBar_Health[0], 1);

	TD_RoundBar_Players[0] = TextDrawCreate(207.000000, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Players[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Players[0], 255);
	TextDrawFont(TD_RoundBar_Players[0], 1);
	TextDrawLetterSize(TD_RoundBar_Players[0], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Players[0], -1);
	TextDrawSetOutline(TD_RoundBar_Players[0], 0);
	TextDrawSetProportional(TD_RoundBar_Players[0], 1);
	TextDrawSetShadow(TD_RoundBar_Players[0], 1);

	TD_RoundBar_Points[0] = TextDrawCreate(225.300003, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Points[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Points[0], 255);
	TextDrawFont(TD_RoundBar_Points[0], 1);
	TextDrawLetterSize(TD_RoundBar_Points[0], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Points[0], -1);
	TextDrawSetOutline(TD_RoundBar_Points[0], 0);
	TextDrawSetProportional(TD_RoundBar_Points[0], 1);
	TextDrawSetShadow(TD_RoundBar_Points[0], 1);

	TD_RoundBar_Color[0] = TextDrawCreate(98.000000, 435.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_RoundBar_Color[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Color[0], 255);
	TextDrawFont(TD_RoundBar_Color[0], 4);
	TextDrawLetterSize(TD_RoundBar_Color[0], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Color[0], -16777072);
	TextDrawSetOutline(TD_RoundBar_Color[0], 0);
	TextDrawSetProportional(TD_RoundBar_Color[0], 1);
	TextDrawSetShadow(TD_RoundBar_Color[0], 1);
	TextDrawUseBox(TD_RoundBar_Color[0], 1);
	TextDrawBoxColor(TD_RoundBar_Color[0], 255);
	TextDrawTextSize(TD_RoundBar_Color[0], 153.000000, 0.500000);

	TD_RoundBar_Name[1] = TextDrawCreate(507.000000, 438.000000, getTeamName(TEAM_TWO));
	TextDrawAlignment(TD_RoundBar_Name[1], 2);
	TextDrawBackgroundColor(TD_RoundBar_Name[1], 255);
	TextDrawFont(TD_RoundBar_Name[1], 1);
	TextDrawLetterSize(TD_RoundBar_Name[1], 0.189998, 0.899999);
	TextDrawColor(TD_RoundBar_Name[1], getTeamColorInt(TEAM_TWO, COLOR_STATUS_ACTIVE)); //126869759
	TextDrawSetOutline(TD_RoundBar_Name[1], 0);
	TextDrawSetProportional(TD_RoundBar_Name[1], 1);
	TextDrawSetShadow(TD_RoundBar_Name[1], 1);

	TD_RoundBar_Health[1] = TextDrawCreate(455.000000, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Health[1], 2);
	TextDrawBackgroundColor(TD_RoundBar_Health[1], 255);
	TextDrawFont(TD_RoundBar_Health[1], 1);
	TextDrawLetterSize(TD_RoundBar_Health[1], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Health[1], -1);
	TextDrawSetOutline(TD_RoundBar_Health[1], 0);
	TextDrawSetProportional(TD_RoundBar_Health[1], 1);
	TextDrawSetShadow(TD_RoundBar_Health[1], 1);

	TD_RoundBar_Players[1] = TextDrawCreate(431.000000, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Players[1], 2);
	TextDrawBackgroundColor(TD_RoundBar_Players[1], 255);
	TextDrawFont(TD_RoundBar_Players[1], 1);
	TextDrawLetterSize(TD_RoundBar_Players[1], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Players[1], -1);
	TextDrawSetOutline(TD_RoundBar_Players[1], 0);
	TextDrawSetProportional(TD_RoundBar_Players[1], 1);
	TextDrawSetShadow(TD_RoundBar_Players[1], 1);

	TD_RoundBar_Points[1] = TextDrawCreate(411.500000, 438.000000, "0");
	TextDrawAlignment(TD_RoundBar_Points[1], 2);
	TextDrawBackgroundColor(TD_RoundBar_Points[1], 255);
	TextDrawFont(TD_RoundBar_Points[1], 1);
	TextDrawLetterSize(TD_RoundBar_Points[1], 0.189998, 0.889998);
	TextDrawColor(TD_RoundBar_Points[1], -1);
	TextDrawSetOutline(TD_RoundBar_Points[1], 0);
	TextDrawSetProportional(TD_RoundBar_Points[1], 1);
	TextDrawSetShadow(TD_RoundBar_Points[1], 1);

	TD_RoundBar_Color[1] = TextDrawCreate(388.500000, 435.000000, "LD_OTB2:butnAo");
	TextDrawBackgroundColor(TD_RoundBar_Color[1], 255);
	TextDrawFont(TD_RoundBar_Color[1], 4);
	TextDrawLetterSize(TD_RoundBar_Color[1], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Color[1], 65424);
	TextDrawSetOutline(TD_RoundBar_Color[1], 0);
	TextDrawSetProportional(TD_RoundBar_Color[1], 1);
	TextDrawSetShadow(TD_RoundBar_Color[1], 1);
	TextDrawUseBox(TD_RoundBar_Color[1], 1);
	TextDrawBoxColor(TD_RoundBar_Color[1], 255);
	TextDrawTextSize(TD_RoundBar_Color[1], 153.000000, 0.500000);

	TD_RoundBar_Defend[0] = TextDrawCreate(242.000000, 439.000000, "hud:radar_EnemyAttack");
	TextDrawBackgroundColor(TD_RoundBar_Defend[0], 255);
	TextDrawFont(TD_RoundBar_Defend[0], 4);
	TextDrawLetterSize(TD_RoundBar_Defend[0], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Defend[0], -1);
	TextDrawSetOutline(TD_RoundBar_Defend[0], 0);
	TextDrawSetProportional(TD_RoundBar_Defend[0], 1);
	TextDrawSetShadow(TD_RoundBar_Defend[0], 1);
	TextDrawUseBox(TD_RoundBar_Defend[0], 1);
	TextDrawBoxColor(TD_RoundBar_Defend[0], 255);
	TextDrawTextSize(TD_RoundBar_Defend[0], 7.000000, 7.000000);

	TD_RoundBar_Defend[1] = TextDrawCreate(392.000000, 439.000000, "hud:radar_EnemyAttack");
	TextDrawBackgroundColor(TD_RoundBar_Defend[1], 255);
	TextDrawFont(TD_RoundBar_Defend[1], 4);
	TextDrawLetterSize(TD_RoundBar_Defend[1], 0.500000, 1.000000);
	TextDrawColor(TD_RoundBar_Defend[1], -1);
	TextDrawSetOutline(TD_RoundBar_Defend[1], 0);
	TextDrawSetProportional(TD_RoundBar_Defend[1], 1);
	TextDrawSetShadow(TD_RoundBar_Defend[1], 1);
	TextDrawUseBox(TD_RoundBar_Defend[1], 1);
	TextDrawBoxColor(TD_RoundBar_Defend[1], 255);
	TextDrawTextSize(TD_RoundBar_Defend[1], 7.000000, 7.000000);
		
	TD_Round_Capture_Static[0] = TextDrawCreate(266.000000, 405.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_Round_Capture_Static[0], 2);
	TextDrawBackgroundColor(TD_Round_Capture_Static[0], 255);
	TextDrawFont(TD_Round_Capture_Static[0], 4);
	TextDrawLetterSize(TD_Round_Capture_Static[0], 0.159999, 0.799998);
	TextDrawColor(TD_Round_Capture_Static[0], 48);
	TextDrawSetOutline(TD_Round_Capture_Static[0], 0);
	TextDrawSetProportional(TD_Round_Capture_Static[0], 1);
	TextDrawSetShadow(TD_Round_Capture_Static[0], 1);
	TextDrawUseBox(TD_Round_Capture_Static[0], 1);
	TextDrawBoxColor(TD_Round_Capture_Static[0], 453748784);
	TextDrawTextSize(TD_Round_Capture_Static[0], 108.000000, 16.000000);

	TD_Round_Capture_Static[1] = TextDrawCreate(266.000000, 405.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_Round_Capture_Static[1], 2);
	TextDrawBackgroundColor(TD_Round_Capture_Static[1], 255);
	TextDrawFont(TD_Round_Capture_Static[1], 4);
	TextDrawLetterSize(TD_Round_Capture_Static[1], 0.159999, 0.799998);
	TextDrawColor(TD_Round_Capture_Static[1], 0x2727F830);
	TextDrawSetOutline(TD_Round_Capture_Static[1], 0);
	TextDrawSetProportional(TD_Round_Capture_Static[1], 1);
	TextDrawSetShadow(TD_Round_Capture_Static[1], 1);
	TextDrawUseBox(TD_Round_Capture_Static[1], 1);
	TextDrawBoxColor(TD_Round_Capture_Static[1], 453748784);
	TextDrawTextSize(TD_Round_Capture_Static[1], 108.000000, 16.000000);

	TD_Round_Capture_Box = TextDrawCreate(266.000000, 405.000000, "LD_OTB2:butnAo");
	TextDrawAlignment(TD_Round_Capture_Box, 2);
	TextDrawBackgroundColor(TD_Round_Capture_Box, 255);
	TextDrawFont(TD_Round_Capture_Box, 4);
	TextDrawLetterSize(TD_Round_Capture_Box, 0.159999, 0.799998);
	TextDrawColor(TD_Round_Capture_Box, 65376);
	TextDrawSetOutline(TD_Round_Capture_Box, 0);
	TextDrawSetProportional(TD_Round_Capture_Box, 1);
	TextDrawSetShadow(TD_Round_Capture_Box, 1);
	TextDrawUseBox(TD_Round_Capture_Box, 1);
	TextDrawBoxColor(TD_Round_Capture_Box, 453748784);
	TextDrawTextSize(TD_Round_Capture_Box, 108.000000, 16.000000);

	TD_Round_Capture_Info = TextDrawCreate(320.000000, 406.500000, " "); //Base capturing  100%
	TextDrawAlignment(TD_Round_Capture_Info, 2);
	TextDrawBackgroundColor(TD_Round_Capture_Info, 255);
	TextDrawFont(TD_Round_Capture_Info, 1);
	TextDrawLetterSize(TD_Round_Capture_Info, 0.170000, 0.899999);
	TextDrawColor(TD_Round_Capture_Info, -1);
	TextDrawSetOutline(TD_Round_Capture_Info, 0);
	TextDrawSetProportional(TD_Round_Capture_Info, 1);
	TextDrawSetShadow(TD_Round_Capture_Info, 1);	
	
	TD_RoundBar_Damage[0] = TextDrawCreate(174.500000, 425.000000, "Jakis Nick Gracza  ~w~-99 HP  (100.0 HP | 100.0 AR)"); //Jakis Nick Gracza  ~w~-99 HP  (100.0 HP | 100.0 AR)
	TextDrawAlignment(TD_RoundBar_Damage[0], 2);
	TextDrawBackgroundColor(TD_RoundBar_Damage[0], 170);
	TextDrawFont(TD_RoundBar_Damage[0], 1);
	TextDrawLetterSize(TD_RoundBar_Damage[0], 0.170000, 0.899999);
	TextDrawColor(TD_RoundBar_Damage[0], 126869759);
	TextDrawSetOutline(TD_RoundBar_Damage[0], 0);
	TextDrawSetProportional(TD_RoundBar_Damage[0], 1);
	TextDrawSetShadow(TD_RoundBar_Damage[0], 1);
	TextDrawUseBox(TD_RoundBar_Damage[0], 1);
	TextDrawBoxColor(TD_RoundBar_Damage[0], 48);
	TextDrawTextSize(TD_RoundBar_Damage[0], 0.000000, 150.000000);

	TD_RoundBar_Damage[1] = TextDrawCreate(465.000000, 425.000000, "Jakis Nick Gracza  ~w~-99 HP  (100.0 HP | 100.0 AR)"); //Jakis Nick Gracza  ~w~-99 HP  (100.0 HP | 100.0 AR)
	TextDrawAlignment(TD_RoundBar_Damage[1], 2);
	TextDrawBackgroundColor(TD_RoundBar_Damage[1], 170);
	TextDrawFont(TD_RoundBar_Damage[1], 1);
	TextDrawLetterSize(TD_RoundBar_Damage[1], 0.170000, 0.899999);
	TextDrawColor(TD_RoundBar_Damage[1], 126869759);
	TextDrawSetOutline(TD_RoundBar_Damage[1], 0);
	TextDrawSetProportional(TD_RoundBar_Damage[1], 1);
	TextDrawSetShadow(TD_RoundBar_Damage[1], 1);
	TextDrawUseBox(TD_RoundBar_Damage[1], 1);
	TextDrawBoxColor(TD_RoundBar_Damage[1], 48);
	TextDrawTextSize(TD_RoundBar_Damage[1], 0.000000, 150.000000);	
		
	//--------------------------------------------------------------------------
		
	TD_Round_Help_Static[0] = TextDrawCreate(30.000000, 293.000000, "LD_POKE:cd9s");
	TextDrawAlignment(TD_Round_Help_Static[0], 2);
	TextDrawBackgroundColor(TD_Round_Help_Static[0], 255);
	TextDrawFont(TD_Round_Help_Static[0], 4);
	TextDrawLetterSize(TD_Round_Help_Static[0], 0.200000, 1.000000);
	TextDrawColor(TD_Round_Help_Static[0], 48);
	TextDrawSetOutline(TD_Round_Help_Static[0], 0);
	TextDrawSetProportional(TD_Round_Help_Static[0], 1);
	TextDrawSetShadow(TD_Round_Help_Static[0], 1);
	TextDrawUseBox(TD_Round_Help_Static[0], 1);
	TextDrawBoxColor(TD_Round_Help_Static[0], 80);
	TextDrawTextSize(TD_Round_Help_Static[0], 116.000000, 24.000000);

	TD_Round_Help_Static[1] = TextDrawCreate(88.000000, 296.000000, " "); //~n~Calls for help!
	TextDrawAlignment(TD_Round_Help_Static[1], 2);
	TextDrawBackgroundColor(TD_Round_Help_Static[1], 255);
	TextDrawFont(TD_Round_Help_Static[1], 1);
	TextDrawLetterSize(TD_Round_Help_Static[1], 0.209999, 1.000000);
	TextDrawColor(TD_Round_Help_Static[1], 126869759);
	TextDrawSetOutline(TD_Round_Help_Static[1], 0);
	TextDrawSetProportional(TD_Round_Help_Static[1], 1);
	TextDrawSetShadow(TD_Round_Help_Static[1], 1);
	TextDrawUseBox(TD_Round_Help_Static[1], 1);
	TextDrawBoxColor(TD_Round_Help_Static[1], 80);
	TextDrawTextSize(TD_Round_Help_Static[1], 0.000000, 110.000000);

	TD_Round_Help_Nick[0] = TextDrawCreate(88.000000, 295.000000, " "); //Jakis Nick Gracza AAAAAA
	TextDrawAlignment(TD_Round_Help_Nick[0], 2);
	TextDrawBackgroundColor(TD_Round_Help_Nick[0], 255);
	TextDrawFont(TD_Round_Help_Nick[0], 1);
	TextDrawLetterSize(TD_Round_Help_Nick[0], 0.209999, 1.000000);
	TextDrawColor(TD_Round_Help_Nick[0], -1);
	TextDrawSetOutline(TD_Round_Help_Nick[0], 0);
	TextDrawSetProportional(TD_Round_Help_Nick[0], 1);
	TextDrawSetShadow(TD_Round_Help_Nick[0], 1);		
			
	TD_Round_Help_Nick[1] = TextDrawCreate(88.000000, 295.000000, " "); //Jakis Nick Gracza AAAAAA
	TextDrawAlignment(TD_Round_Help_Nick[1], 2);
	TextDrawBackgroundColor(TD_Round_Help_Nick[1], 255);
	TextDrawFont(TD_Round_Help_Nick[1], 1);
	TextDrawLetterSize(TD_Round_Help_Nick[1], 0.209999, 1.000000);
	TextDrawColor(TD_Round_Help_Nick[1], -1);
	TextDrawSetOutline(TD_Round_Help_Nick[1], 0);
	TextDrawSetProportional(TD_Round_Help_Nick[1], 1);
	TextDrawSetShadow(TD_Round_Help_Nick[1], 1);		

	//--------------------------------------------------------------------------
	
	TD_Round_BTB_Player_Static = TextDrawCreate(30.000000, 323.000000, "LD_POKE:cd9s");
	TextDrawAlignment(TD_Round_BTB_Player_Static, 2);
	TextDrawBackgroundColor(TD_Round_BTB_Player_Static, 255);
	TextDrawFont(TD_Round_BTB_Player_Static, 4);
	TextDrawLetterSize(TD_Round_BTB_Player_Static, 0.200000, 1.000000);
	TextDrawColor(TD_Round_BTB_Player_Static, 48);
	TextDrawSetOutline(TD_Round_BTB_Player_Static, 0);
	TextDrawSetProportional(TD_Round_BTB_Player_Static, 1);
	TextDrawSetShadow(TD_Round_BTB_Player_Static, 1);
	TextDrawUseBox(TD_Round_BTB_Player_Static, 1);
	TextDrawBoxColor(TD_Round_BTB_Player_Static, 80);
	TextDrawTextSize(TD_Round_BTB_Player_Static, 116.000000, 15.000000);

	TD_Round_BTB_Player_Info = TextDrawCreate(88.000000, 326.000000, " "); //Outside the base
	TextDrawAlignment(TD_Round_BTB_Player_Info, 2);
	TextDrawBackgroundColor(TD_Round_BTB_Player_Info, 255);
	TextDrawFont(TD_Round_BTB_Player_Info, 1);
	TextDrawLetterSize(TD_Round_BTB_Player_Info, 0.210000, 1.000000);
	TextDrawColor(TD_Round_BTB_Player_Info, 126869759);
	TextDrawSetOutline(TD_Round_BTB_Player_Info, 0);
	TextDrawSetProportional(TD_Round_BTB_Player_Info, 1);
	TextDrawSetShadow(TD_Round_BTB_Player_Info, 1);
	TextDrawUseBox(TD_Round_BTB_Player_Info, 1);
	TextDrawBoxColor(TD_Round_BTB_Player_Info, 80);
	TextDrawTextSize(TD_Round_BTB_Player_Info, 0.000000, 110.000000);	
	
	//--------------------------------------------------------------------------
	
	TD_Round_BTB_Static = TextDrawCreate(266.000000, 389.000000, "LD_POKE:cd9s");
	TextDrawAlignment(TD_Round_BTB_Static, 2);
	TextDrawBackgroundColor(TD_Round_BTB_Static, 255);
	TextDrawFont(TD_Round_BTB_Static, 4);
	TextDrawLetterSize(TD_Round_BTB_Static, 0.200000, 1.000000);
	TextDrawColor(TD_Round_BTB_Static, 48);
	TextDrawSetOutline(TD_Round_BTB_Static, 0);
	TextDrawSetProportional(TD_Round_BTB_Static, 1);
	TextDrawSetShadow(TD_Round_BTB_Static, 1);
	TextDrawUseBox(TD_Round_BTB_Static, 1);
	TextDrawBoxColor(TD_Round_BTB_Static, 80);
	TextDrawTextSize(TD_Round_BTB_Static, 108.000000, 14.000000);

	TD_Round_BTB_Info = TextDrawCreate(320.000000, 392.000000, " "); //Czas na powrot do bazy  ~w~99
	TextDrawAlignment(TD_Round_BTB_Info, 2);
	TextDrawBackgroundColor(TD_Round_BTB_Info, 255);
	TextDrawFont(TD_Round_BTB_Info, 1);
	TextDrawLetterSize(TD_Round_BTB_Info, 0.169999, 0.899999);
	TextDrawColor(TD_Round_BTB_Info, 126869759);
	TextDrawSetOutline(TD_Round_BTB_Info, 0);
	TextDrawSetProportional(TD_Round_BTB_Info, 1);
	TextDrawSetShadow(TD_Round_BTB_Info, 1);
	TextDrawUseBox(TD_Round_BTB_Info, 1);
	TextDrawBoxColor(TD_Round_BTB_Info, 80);
	TextDrawTextSize(TD_Round_BTB_Info, 0.000000, 103.000000);

	//--------------------------------------------------------------------------
	
	TD_Round_Pause = TextDrawCreate(320.000000, 200.000000, " "); //~n~Runda zostala zatrzymana~n~_
	TextDrawAlignment(TD_Round_Pause, 2);
	TextDrawBackgroundColor(TD_Round_Pause, 255);
	TextDrawFont(TD_Round_Pause, 1);
	TextDrawLetterSize(TD_Round_Pause, 0.359999, 1.599998);
	TextDrawColor(TD_Round_Pause, -16777046);
	TextDrawSetOutline(TD_Round_Pause, 0);
	TextDrawSetProportional(TD_Round_Pause, 1);
	TextDrawSetShadow(TD_Round_Pause, 1);
	TextDrawUseBox(TD_Round_Pause, 1);
	TextDrawBoxColor(TD_Round_Pause, 80);
	TextDrawTextSize(TD_Round_Pause, 0.000000, 650.000000);
	
	//--------------------------------------------------------------------------

	TD_Round_CP_Map_ZPos[2] = TextDrawCreate(6.000000, 377.000000, "CP ~<~");
	TextDrawBackgroundColor(TD_Round_CP_Map_ZPos[2], 255);
	TextDrawFont(TD_Round_CP_Map_ZPos[2], 1);
	TextDrawLetterSize(TD_Round_CP_Map_ZPos[2], 0.280000, 1.199999);
	TextDrawColor(TD_Round_CP_Map_ZPos[2], 126869759);
	TextDrawSetOutline(TD_Round_CP_Map_ZPos[2], 0);
	TextDrawSetProportional(TD_Round_CP_Map_ZPos[2], 1);
	TextDrawSetShadow(TD_Round_CP_Map_ZPos[2], 1);
	TextDrawUseBox(TD_Round_CP_Map_ZPos[2], 1);
	TextDrawBoxColor(TD_Round_CP_Map_ZPos[2], 80);
	TextDrawTextSize(TD_Round_CP_Map_ZPos[2], 30.000000, 25.000000);
		
	TD_Round_CP_Map_ZPos[0] = TextDrawCreate(6.000000, 377.000000, "CP ~d~");
	TextDrawBackgroundColor(TD_Round_CP_Map_ZPos[0], 255);
	TextDrawFont(TD_Round_CP_Map_ZPos[0], 1);
	TextDrawLetterSize(TD_Round_CP_Map_ZPos[0], 0.280000, 1.199999);
	TextDrawColor(TD_Round_CP_Map_ZPos[0], 126869759);
	TextDrawSetOutline(TD_Round_CP_Map_ZPos[0], 0);
	TextDrawSetProportional(TD_Round_CP_Map_ZPos[0], 1);
	TextDrawSetShadow(TD_Round_CP_Map_ZPos[0], 1);
	TextDrawUseBox(TD_Round_CP_Map_ZPos[0], 1);
	TextDrawBoxColor(TD_Round_CP_Map_ZPos[0], 80);
	TextDrawTextSize(TD_Round_CP_Map_ZPos[0], 30.000000, 25.000000);

	TD_Round_CP_Map_ZPos[1] = TextDrawCreate(6.000000, 377.000000, "CP ~u~");
	TextDrawBackgroundColor(TD_Round_CP_Map_ZPos[1], 255);
	TextDrawFont(TD_Round_CP_Map_ZPos[1], 1);
	TextDrawLetterSize(TD_Round_CP_Map_ZPos[1], 0.280000, 1.199999);
	TextDrawColor(TD_Round_CP_Map_ZPos[1], 126869759);
	TextDrawSetOutline(TD_Round_CP_Map_ZPos[1], 0);
	TextDrawSetProportional(TD_Round_CP_Map_ZPos[1], 1);
	TextDrawSetShadow(TD_Round_CP_Map_ZPos[1], 1);
	TextDrawUseBox(TD_Round_CP_Map_ZPos[1], 1);
	TextDrawBoxColor(TD_Round_CP_Map_ZPos[1], 80);
	TextDrawTextSize(TD_Round_CP_Map_ZPos[1], 30.000000, 25.000000);
	
	//--------------------------------------------------------------------------

	TD_Round_End_Static[0] = TextDrawCreate(319.000000, 161.500000, "_");
	TextDrawAlignment(TD_Round_End_Static[0], 2);
	TextDrawBackgroundColor(TD_Round_End_Static[0], 255);
	TextDrawFont(TD_Round_End_Static[0], 1);
	TextDrawLetterSize(TD_Round_End_Static[0], 0.500000, 14.000001);
	TextDrawColor(TD_Round_End_Static[0], 48);
	TextDrawSetOutline(TD_Round_End_Static[0], 0);
	TextDrawSetProportional(TD_Round_End_Static[0], 1);
	TextDrawSetShadow(TD_Round_End_Static[0], 1);
	TextDrawUseBox(TD_Round_End_Static[0], 1);
	TextDrawBoxColor(TD_Round_End_Static[0], 48);
	TextDrawTextSize(TD_Round_End_Static[0], 140.000000, 168.000000);	
		
	TD_Round_End_Static[1] = TextDrawCreate(256.000000, 195.000000, "LD_POOL:ball");
	TextDrawBackgroundColor(TD_Round_End_Static[1], 255);
	TextDrawFont(TD_Round_End_Static[1], 4);
	TextDrawLetterSize(TD_Round_End_Static[1], 0.500000, 1.000000);
	TextDrawColor(TD_Round_End_Static[1], 126869584);
	TextDrawSetOutline(TD_Round_End_Static[1], 0);
	TextDrawSetProportional(TD_Round_End_Static[1], 1);
	TextDrawSetShadow(TD_Round_End_Static[1], 1);
	TextDrawUseBox(TD_Round_End_Static[1], 1);
	TextDrawBoxColor(TD_Round_End_Static[1], 255);
	TextDrawTextSize(TD_Round_End_Static[1], 126.000000, 1.000000);

	TD_Round_End_Static[2] = TextDrawCreate(319.000000, 216.000000, " "); //Top graczy w rundzie~n~~n~~n~~n~~n~~n~_
	TextDrawAlignment(TD_Round_End_Static[2], 2);
	TextDrawBackgroundColor(TD_Round_End_Static[2], 255);
	TextDrawFont(TD_Round_End_Static[2], 1);
	TextDrawLetterSize(TD_Round_End_Static[2], 0.209999, 1.099999);
	TextDrawColor(TD_Round_End_Static[2], 126869759);
	TextDrawSetOutline(TD_Round_End_Static[2], 0);
	TextDrawSetProportional(TD_Round_End_Static[2], 1);
	TextDrawSetShadow(TD_Round_End_Static[2], 1);
	TextDrawUseBox(TD_Round_End_Static[2], 1);
	TextDrawBoxColor(TD_Round_End_Static[2], 48);
	TextDrawTextSize(TD_Round_End_Static[2], 0.000000, 165.000000);

	TD_Round_End_Static[3] = TextDrawCreate(268.000000, 229.000000, " "); //Nick_________________Druzyna_____DMG_(Zabojstw)
	TextDrawBackgroundColor(TD_Round_End_Static[3], 255);
	TextDrawFont(TD_Round_End_Static[3], 1);
	TextDrawLetterSize(TD_Round_End_Static[3], 0.170000, 0.899998);
	TextDrawColor(TD_Round_End_Static[3], 1757347327);
	TextDrawSetOutline(TD_Round_End_Static[3], 0);
	TextDrawSetProportional(TD_Round_End_Static[3], 1);
	TextDrawSetShadow(TD_Round_End_Static[3], 1);

	TD_Round_End_MapInfo = TextDrawCreate(319.000000, 163.000000, " "); //Arena  ~w~999
	TextDrawAlignment(TD_Round_End_MapInfo, 2);
	TextDrawBackgroundColor(TD_Round_End_MapInfo, 255);
	TextDrawFont(TD_Round_End_MapInfo, 1);
	TextDrawLetterSize(TD_Round_End_MapInfo, 0.300000, 1.399999);
	TextDrawColor(TD_Round_End_MapInfo, 126869759);
	TextDrawSetOutline(TD_Round_End_MapInfo, 0);
	TextDrawSetProportional(TD_Round_End_MapInfo, 1);
	TextDrawSetShadow(TD_Round_End_MapInfo, 1);
	TextDrawUseBox(TD_Round_End_MapInfo, 1);
	TextDrawBoxColor(TD_Round_End_MapInfo, 48);
	TextDrawTextSize(TD_Round_End_MapInfo, 0.000000, 165.000000);

	TD_Round_End_WinInfo = TextDrawCreate(319.000000, 181.000000, " "); //Wygrywa druzyna ~w~Jakas_Nazwa~n~~n~_
	TextDrawAlignment(TD_Round_End_WinInfo, 2);
	TextDrawBackgroundColor(TD_Round_End_WinInfo, 255);
	TextDrawFont(TD_Round_End_WinInfo, 1);
	TextDrawLetterSize(TD_Round_End_WinInfo, 0.209999, 1.100000);
	TextDrawColor(TD_Round_End_WinInfo, 126869759);
	TextDrawSetOutline(TD_Round_End_WinInfo, 0);
	TextDrawSetProportional(TD_Round_End_WinInfo, 1);
	TextDrawSetShadow(TD_Round_End_WinInfo, 1);
	TextDrawUseBox(TD_Round_End_WinInfo, 1);
	TextDrawBoxColor(TD_Round_End_WinInfo, 48);
	TextDrawTextSize(TD_Round_End_WinInfo, 0.000000, 165.000000);

	TD_Round_End_Reason = TextDrawCreate(319.000000, 198.000000, " "); //Brak obroncow w bazie
	TextDrawAlignment(TD_Round_End_Reason, 2);
	TextDrawBackgroundColor(TD_Round_End_Reason, 255);
	TextDrawFont(TD_Round_End_Reason, 1);
	TextDrawLetterSize(TD_Round_End_Reason, 0.209999, 1.100000);
	TextDrawColor(TD_Round_End_Reason, -1);
	TextDrawSetOutline(TD_Round_End_Reason, 0);
	TextDrawSetProportional(TD_Round_End_Reason, 1);
	TextDrawSetShadow(TD_Round_End_Reason, 1);

	TD_Round_End_Top_Nicks = TextDrawCreate(274.000000, 240.000000, " "); //Jakis_Dlugi_Nick_Gracza~n~Nick2~n~Nick3~n~Nick4~n~Nick5
	TextDrawAlignment(TD_Round_End_Top_Nicks, 2);
	TextDrawBackgroundColor(TD_Round_End_Top_Nicks, 255);
	TextDrawFont(TD_Round_End_Top_Nicks, 1);
	TextDrawLetterSize(TD_Round_End_Top_Nicks, 0.170000, 0.899998);
	TextDrawColor(TD_Round_End_Top_Nicks, -1);
	TextDrawSetOutline(TD_Round_End_Top_Nicks, 0);
	TextDrawSetProportional(TD_Round_End_Top_Nicks, 1);
	TextDrawSetShadow(TD_Round_End_Top_Nicks, 1);

	TD_Round_End_Top_Teams = TextDrawCreate(333.500000, 240.000000, " "); //Jakas_Nazwa~n~nazwa2~n~nazwa3~n~nazwa4~n~nazwa5
	TextDrawAlignment(TD_Round_End_Top_Teams, 2);
	TextDrawBackgroundColor(TD_Round_End_Top_Teams, 255);
	TextDrawFont(TD_Round_End_Top_Teams, 1);
	TextDrawLetterSize(TD_Round_End_Top_Teams, 0.170000, 0.899998);
	TextDrawColor(TD_Round_End_Top_Teams, -1);
	TextDrawSetOutline(TD_Round_End_Top_Teams, 0);
	TextDrawSetProportional(TD_Round_End_Top_Teams, 1);
	TextDrawSetShadow(TD_Round_End_Top_Teams, 1);

	TD_Round_End_Top_Points = TextDrawCreate(379.000000, 240.000000, " "); //9999  (99)~n~9999  (99)~n~9999  (99)~n~9999  (99)~n~9999  (99)
	TextDrawAlignment(TD_Round_End_Top_Points, 2);
	TextDrawBackgroundColor(TD_Round_End_Top_Points, 255);
	TextDrawFont(TD_Round_End_Top_Points, 1);
	TextDrawLetterSize(TD_Round_End_Top_Points, 0.170000, 0.899998);
	TextDrawColor(TD_Round_End_Top_Points, -1);
	TextDrawSetOutline(TD_Round_End_Top_Points, 0);
	TextDrawSetProportional(TD_Round_End_Top_Points, 1);
	TextDrawSetShadow(TD_Round_End_Top_Points, 1);

	//--------------------------------------------------------------------------

	TD_Round_Match_End_Static[0] = TextDrawCreate(320.000000, 105.500000, "_");
	TextDrawAlignment(TD_Round_Match_End_Static[0], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Static[0], 255);
	TextDrawFont(TD_Round_Match_End_Static[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[0], 0.400000, 21.000000);
	TextDrawColor(TD_Round_Match_End_Static[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_Static[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[0], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[0], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[0], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[0], 0.000000, 177.000000);

	TD_Round_Match_End_Static[1] = TextDrawCreate(320.000000, 107.000000, "Vs~n~_");
	TextDrawAlignment(TD_Round_Match_End_Static[1], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Static[1], 255);
	TextDrawFont(TD_Round_Match_End_Static[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[1], 0.419999, 2.000000);
	TextDrawColor(TD_Round_Match_End_Static[1], 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Static[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[1], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[1], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[1], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[1], 0.000000, 174.000000);	
		
	TD_Round_Match_End_Static[2] = TextDrawCreate(235.000000, 266.500000, "LD_OTB2:butnAo");
	TextDrawBackgroundColor(TD_Round_Match_End_Static[2], 255);
	TextDrawFont(TD_Round_Match_End_Static[2], 4);
	TextDrawLetterSize(TD_Round_Match_End_Static[2], 0.500000, 1.000000);
	TextDrawColor(TD_Round_Match_End_Static[2], 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Static[2], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[2], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[2], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[2], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[2], 255);
	TextDrawTextSize(TD_Round_Match_End_Static[2], 170.000000, 1.000000);

	TD_Round_Match_End_Static[3] = TextDrawCreate(150.000000, 166.000000, "_");
	TextDrawAlignment(TD_Round_Match_End_Static[3], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Static[3], 255);
	TextDrawFont(TD_Round_Match_End_Static[3], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[3], 0.800000, 11.099996);
	TextDrawColor(TD_Round_Match_End_Static[3], -1);
	TextDrawSetOutline(TD_Round_Match_End_Static[3], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[3], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[3], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[3], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[3], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[3], -10.000000, 126.000000);

	TD_Round_Match_End_Static[4] = TextDrawCreate(490.000000, 166.000000, "_");
	TextDrawAlignment(TD_Round_Match_End_Static[4], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Static[4], 255);
	TextDrawFont(TD_Round_Match_End_Static[4], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[4], 0.800000, 11.099996);
	TextDrawColor(TD_Round_Match_End_Static[4], -1);
	TextDrawSetOutline(TD_Round_Match_End_Static[4], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[4], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[4], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[4], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[4], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[4], -10.000000, 126.000000);

	TD_Round_Match_End_Static[5] = TextDrawCreate(320.000000, 149.000000, " "); //Wynik~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~Punktow
	TextDrawAlignment(TD_Round_Match_End_Static[5], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Static[5], 255);
	TextDrawFont(TD_Round_Match_End_Static[5], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[5], 0.259999, 1.199998);
	TextDrawColor(TD_Round_Match_End_Static[5], 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Static[5], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[5], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[5], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[5], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[5], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[5], 0.000000, 174.000000);	
		
	TD_Round_Match_End_Static[6] = TextDrawCreate(87.500000, 168.000000, " "); //_Nick__________________________Damage____(Z)
	TextDrawBackgroundColor(TD_Round_Match_End_Static[6], 255);
	TextDrawFont(TD_Round_Match_End_Static[6], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[6], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Match_End_Static[6], 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Static[6], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[6], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[6], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[6], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[6], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[6], 213.000000, 103.000000);	
		
	TD_Round_Match_End_Static[7] = TextDrawCreate(427.000000, 168.000000, " "); //_Nick__________________________Damage____(Z)
	TextDrawBackgroundColor(TD_Round_Match_End_Static[7], 255);
	TextDrawFont(TD_Round_Match_End_Static[7], 1);
	TextDrawLetterSize(TD_Round_Match_End_Static[7], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Match_End_Static[7], 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Static[7], 0);
	TextDrawSetProportional(TD_Round_Match_End_Static[7], 1);
	TextDrawSetShadow(TD_Round_Match_End_Static[7], 1);
	TextDrawUseBox(TD_Round_Match_End_Static[7], 1);
	TextDrawBoxColor(TD_Round_Match_End_Static[7], 48);
	TextDrawTextSize(TD_Round_Match_End_Static[7], 553.000000, 103.000000);	

	TD_Round_Match_End_TNames[0] = TextDrawCreate(300.000000, 112.000000, " "); //Jakas_Nazwa
	TextDrawAlignment(TD_Round_Match_End_TNames[0], 3);
	TextDrawBackgroundColor(TD_Round_Match_End_TNames[0], 255);
	TextDrawFont(TD_Round_Match_End_TNames[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TNames[0], 0.279998, 1.299998);
	TextDrawColor(TD_Round_Match_End_TNames[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TNames[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TNames[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TNames[0], 1);

	TD_Round_Match_End_TNames[1] = TextDrawCreate(339.000000, 112.000000, " "); //Jakas_Nazwa
	TextDrawBackgroundColor(TD_Round_Match_End_TNames[1], 255);
	TextDrawFont(TD_Round_Match_End_TNames[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TNames[1], 0.280000, 1.299998);
	TextDrawColor(TD_Round_Match_End_TNames[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TNames[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TNames[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TNames[1], 1);	

	TD_Round_Match_End_Winner = TextDrawCreate(320.000000, 128.000000, " "); //Wygrywa  ~w~Jakas_Nazwa
	TextDrawAlignment(TD_Round_Match_End_Winner, 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Winner, 255);
	TextDrawFont(TD_Round_Match_End_Winner, 1);
	TextDrawLetterSize(TD_Round_Match_End_Winner, 0.279998, 1.299998);
	TextDrawColor(TD_Round_Match_End_Winner, 126869759);
	TextDrawSetOutline(TD_Round_Match_End_Winner, 0);
	TextDrawSetProportional(TD_Round_Match_End_Winner, 1);
	TextDrawSetShadow(TD_Round_Match_End_Winner, 1);

	TD_Round_Match_End_TPoints[0] = TextDrawCreate(265.000000, 269.000000, " "); //99
	TextDrawAlignment(TD_Round_Match_End_TPoints[0], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TPoints[0], 255);
	TextDrawFont(TD_Round_Match_End_TPoints[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TPoints[0], 0.219999, 0.999999);
	TextDrawColor(TD_Round_Match_End_TPoints[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TPoints[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TPoints[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TPoints[0], 1);

	TD_Round_Match_End_TPoints[1] = TextDrawCreate(375.000000, 269.000000, " "); //99
	TextDrawAlignment(TD_Round_Match_End_TPoints[1], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TPoints[1], 255);
	TextDrawFont(TD_Round_Match_End_TPoints[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TPoints[1], 0.219999, 0.999999);
	TextDrawColor(TD_Round_Match_End_TPoints[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TPoints[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TPoints[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TPoints[1], 1);

	TD_Round_Match_End_Rounds = TextDrawCreate(320.000000, 164.000000, " "); //Arena 9999~n~Baza 9999~n~3~n~4~n~5~n~6~n~7~n~8~n~9~n~10~n~11
	TextDrawAlignment(TD_Round_Match_End_Rounds, 2);
	TextDrawBackgroundColor(TD_Round_Match_End_Rounds, 255);
	TextDrawFont(TD_Round_Match_End_Rounds, 1);
	TextDrawLetterSize(TD_Round_Match_End_Rounds, 0.219999, 0.999999);
	TextDrawColor(TD_Round_Match_End_Rounds, -1);
	TextDrawSetOutline(TD_Round_Match_End_Rounds, 0);
	TextDrawSetProportional(TD_Round_Match_End_Rounds, 1);
	TextDrawSetShadow(TD_Round_Match_End_Rounds, 1);

	TD_Round_Match_End_TRounds[0] = TextDrawCreate(265.000000, 164.000000, " "); //~g~Att~n~~r~Def~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att
	TextDrawAlignment(TD_Round_Match_End_TRounds[0], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TRounds[0], 255);
	TextDrawFont(TD_Round_Match_End_TRounds[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TRounds[0], 0.219999, 0.999999);
	TextDrawColor(TD_Round_Match_End_TRounds[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TRounds[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TRounds[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TRounds[0], 1);

	TD_Round_Match_End_TRounds[1] = TextDrawCreate(375.000000, 164.000000, " "); //~g~Att~n~~r~Def~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att~n~Att
	TextDrawAlignment(TD_Round_Match_End_TRounds[1], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TRounds[1], 255);
	TextDrawFont(TD_Round_Match_End_TRounds[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TRounds[1], 0.219999, 0.999999);
	TextDrawColor(TD_Round_Match_End_TRounds[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TRounds[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TRounds[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TRounds[1], 1);

	TD_Round_Match_End_TPlayers[0] = TextDrawCreate(87.500000, 182.000000, " "); //ZZZZZZZZZZZZZZZZZZZ~n~2~n~2~n~2~n~2~n~2~n~2~n~2~n~2~n~2
	TextDrawBackgroundColor(TD_Round_Match_End_TPlayers[0], 255);
	TextDrawFont(TD_Round_Match_End_TPlayers[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TPlayers[0], 0.170000, 0.899998);
	TextDrawColor(TD_Round_Match_End_TPlayers[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TPlayers[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TPlayers[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TPlayers[0], 1);
	TextDrawUseBox(TD_Round_Match_End_TPlayers[0], 1);
	TextDrawBoxColor(TD_Round_Match_End_TPlayers[0], 48);
	TextDrawTextSize(TD_Round_Match_End_TPlayers[0], 159.000000, 93.000000);

	TD_Round_Match_End_TDamage[0] = TextDrawCreate(177.500000, 182.000000, " "); //99999~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9
	TextDrawAlignment(TD_Round_Match_End_TDamage[0], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TDamage[0], 255);
	TextDrawFont(TD_Round_Match_End_TDamage[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TDamage[0], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Match_End_TDamage[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TDamage[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TDamage[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TDamage[0], 1);
	TextDrawUseBox(TD_Round_Match_End_TDamage[0], 1);
	TextDrawBoxColor(TD_Round_Match_End_TDamage[0], 48);
	TextDrawTextSize(TD_Round_Match_End_TDamage[0], 316.000000, 26.000000);

	TD_Round_Match_End_TKills[0] = TextDrawCreate(204.500000, 182.000000, " "); //999~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9
	TextDrawAlignment(TD_Round_Match_End_TKills[0], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TKills[0], 255);
	TextDrawFont(TD_Round_Match_End_TKills[0], 1);
	TextDrawLetterSize(TD_Round_Match_End_TKills[0], 0.170000, 0.899900);
	TextDrawColor(TD_Round_Match_End_TKills[0], -1);
	TextDrawSetOutline(TD_Round_Match_End_TKills[0], 0);
	TextDrawSetProportional(TD_Round_Match_End_TKills[0], 1);
	TextDrawSetShadow(TD_Round_Match_End_TKills[0], 1);
	TextDrawUseBox(TD_Round_Match_End_TKills[0], 1);
	TextDrawBoxColor(TD_Round_Match_End_TKills[0], 48);
	TextDrawTextSize(TD_Round_Match_End_TKills[0], 316.000000, 17.000000);

	TD_Round_Match_End_TPlayers[1] = TextDrawCreate(427.000000, 182.000000, " "); //ZZZZZZZZZZZZZZZZZZZ~n~2~n~2~n~2~n~2~n~2~n~2~n~2~n~2~n~2
	TextDrawBackgroundColor(TD_Round_Match_End_TPlayers[1], 255);
	TextDrawFont(TD_Round_Match_End_TPlayers[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TPlayers[1], 0.170000, 0.899998);
	TextDrawColor(TD_Round_Match_End_TPlayers[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TPlayers[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TPlayers[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TPlayers[1], 1);
	TextDrawUseBox(TD_Round_Match_End_TPlayers[1], 1);
	TextDrawBoxColor(TD_Round_Match_End_TPlayers[1], 48);
	TextDrawTextSize(TD_Round_Match_End_TPlayers[1], 498.500000, 93.000000);

	TD_Round_Match_End_TDamage[1] = TextDrawCreate(517.000000, 182.000000, " "); //99999~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9
	TextDrawAlignment(TD_Round_Match_End_TDamage[1], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TDamage[1], 255);
	TextDrawFont(TD_Round_Match_End_TDamage[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TDamage[1], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Match_End_TDamage[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TDamage[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TDamage[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TDamage[1], 1);
	TextDrawUseBox(TD_Round_Match_End_TDamage[1], 1);
	TextDrawBoxColor(TD_Round_Match_End_TDamage[1], 48);
	TextDrawTextSize(TD_Round_Match_End_TDamage[1], 316.000000, 26.000000);

	TD_Round_Match_End_TKills[1] = TextDrawCreate(544.000000, 182.000000, " "); //999~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9~n~9
	TextDrawAlignment(TD_Round_Match_End_TKills[1], 2);
	TextDrawBackgroundColor(TD_Round_Match_End_TKills[1], 255);
	TextDrawFont(TD_Round_Match_End_TKills[1], 1);
	TextDrawLetterSize(TD_Round_Match_End_TKills[1], 0.170000, 0.899900);
	TextDrawColor(TD_Round_Match_End_TKills[1], -1);
	TextDrawSetOutline(TD_Round_Match_End_TKills[1], 0);
	TextDrawSetProportional(TD_Round_Match_End_TKills[1], 1);
	TextDrawSetShadow(TD_Round_Match_End_TKills[1], 1);
	TextDrawUseBox(TD_Round_Match_End_TKills[1], 1);
	TextDrawBoxColor(TD_Round_Match_End_TKills[1], 48);
	TextDrawTextSize(TD_Round_Match_End_TKills[1], 316.000000, 17.000000);
	
	TD_Round_Match_Result_WWW = TextDrawCreate(320.000000, 285.000000, " "); //Brak wyniku na stronie WWW
	TextDrawAlignment(TD_Round_Match_Result_WWW, 2);
	TextDrawBackgroundColor(TD_Round_Match_Result_WWW, 255);
	TextDrawFont(TD_Round_Match_Result_WWW, 1);
	TextDrawLetterSize(TD_Round_Match_Result_WWW, 0.170000, 0.889999);
	TextDrawColor(TD_Round_Match_Result_WWW, -1);
	TextDrawSetOutline(TD_Round_Match_Result_WWW, 0);
	TextDrawSetProportional(TD_Round_Match_Result_WWW, 1);
	TextDrawSetShadow(TD_Round_Match_Result_WWW, 1);
	TextDrawUseBox(TD_Round_Match_Result_WWW, 1);
	TextDrawBoxColor(TD_Round_Match_Result_WWW, 48);
	TextDrawTextSize(TD_Round_Match_Result_WWW, 540.000000, 174.000000);	
	
	//--------------------------------------------------------------------------
	
	TD_AimedPlayer_Static[0] = TextDrawCreate(554.500000, 423.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_AimedPlayer_Static[0], 255);
	TextDrawFont(TD_AimedPlayer_Static[0], 4);
	TextDrawLetterSize(TD_AimedPlayer_Static[0], 0.500000, 1.000000);
	TextDrawColor(TD_AimedPlayer_Static[0], 48);
	TextDrawSetOutline(TD_AimedPlayer_Static[0], 0);
	TextDrawSetProportional(TD_AimedPlayer_Static[0], 1);
	TextDrawSetShadow(TD_AimedPlayer_Static[0], 1);
	TextDrawUseBox(TD_AimedPlayer_Static[0], 1);
	TextDrawBoxColor(TD_AimedPlayer_Static[0], 48);
	TextDrawTextSize(TD_AimedPlayer_Static[0], 86.000000, 26.000000);	

	TD_AimedPlayer_Static[1] = TextDrawCreate(589.000000, 438.000000, "FPS_________P-Loss");
	TextDrawAlignment(TD_AimedPlayer_Static[1], 2);
	TextDrawBackgroundColor(TD_AimedPlayer_Static[1], 255);
	TextDrawFont(TD_AimedPlayer_Static[1], 1);
	TextDrawLetterSize(TD_AimedPlayer_Static[1], 0.170000, 0.889998);
	TextDrawColor(TD_AimedPlayer_Static[1], 126869759);
	TextDrawSetOutline(TD_AimedPlayer_Static[1], 0);
	TextDrawSetProportional(TD_AimedPlayer_Static[1], 1);
	TextDrawSetShadow(TD_AimedPlayer_Static[1], 1);
		
	//--------------------------------------------------------------------------
	
	TD_PlayerHUD_NickAndTeam_Static = TextDrawCreate(-0.500000, 423.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_PlayerHUD_NickAndTeam_Static, 255);
	TextDrawFont(TD_PlayerHUD_NickAndTeam_Static, 4);
	TextDrawLetterSize(TD_PlayerHUD_NickAndTeam_Static, 0.500000, 1.200000);
	TextDrawColor(TD_PlayerHUD_NickAndTeam_Static, 48);
	TextDrawSetOutline(TD_PlayerHUD_NickAndTeam_Static, 0);
	TextDrawSetProportional(TD_PlayerHUD_NickAndTeam_Static, 1);
	TextDrawSetShadow(TD_PlayerHUD_NickAndTeam_Static, 1);
	TextDrawUseBox(TD_PlayerHUD_NickAndTeam_Static, 1);
	TextDrawBoxColor(TD_PlayerHUD_NickAndTeam_Static, 48);
	TextDrawTextSize(TD_PlayerHUD_NickAndTeam_Static, 85.000000, 27.000000);	
	
	TD_PlayerHUD_TeamNames[0] = TextDrawCreate(42.000000, 438.000000, " "); 
	TextDrawAlignment(TD_PlayerHUD_TeamNames[0], 2);
	TextDrawBackgroundColor(TD_PlayerHUD_TeamNames[0], 255);
	TextDrawFont(TD_PlayerHUD_TeamNames[0], 1);
	TextDrawLetterSize(TD_PlayerHUD_TeamNames[0], 0.170000, 0.889998);
	TextDrawColor(TD_PlayerHUD_TeamNames[0], getTeamColorInt(TEAM_ONE, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_PlayerHUD_TeamNames[0], 0);
	TextDrawSetProportional(TD_PlayerHUD_TeamNames[0], 1);
	TextDrawSetShadow(TD_PlayerHUD_TeamNames[0], 1);

	TD_PlayerHUD_TeamNames[1] = TextDrawCreate(42.000000, 438.000000, " "); 
	TextDrawAlignment(TD_PlayerHUD_TeamNames[1], 2);
	TextDrawBackgroundColor(TD_PlayerHUD_TeamNames[1], 255);
	TextDrawFont(TD_PlayerHUD_TeamNames[1], 1);
	TextDrawLetterSize(TD_PlayerHUD_TeamNames[1], 0.170000, 0.889998);
	TextDrawColor(TD_PlayerHUD_TeamNames[1], getTeamColorInt(TEAM_TWO, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_PlayerHUD_TeamNames[1], 0);
	TextDrawSetProportional(TD_PlayerHUD_TeamNames[1], 1);
	TextDrawSetShadow(TD_PlayerHUD_TeamNames[1], 1);	
	
	TD_PlayerHUD_TeamNames[2] = TextDrawCreate(42.000000, 438.000000, " "); 
	TextDrawAlignment(TD_PlayerHUD_TeamNames[2], 2);
	TextDrawBackgroundColor(TD_PlayerHUD_TeamNames[2], 255);
	TextDrawFont(TD_PlayerHUD_TeamNames[2], 1);
	TextDrawLetterSize(TD_PlayerHUD_TeamNames[2], 0.170000, 0.889998);
	TextDrawColor(TD_PlayerHUD_TeamNames[2], getTeamColorInt(TEAM_REF, COLOR_STATUS_ACTIVE));
	TextDrawSetOutline(TD_PlayerHUD_TeamNames[2], 0);
	TextDrawSetProportional(TD_PlayerHUD_TeamNames[2], 1);
	TextDrawSetShadow(TD_PlayerHUD_TeamNames[2], 1);

	TD_PlayerHUD_FPSPingPLossStatic[0] = TextDrawCreate(535.500000, -15.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_PlayerHUD_FPSPingPLossStatic[0], 255);
	TextDrawFont(TD_PlayerHUD_FPSPingPLossStatic[0], 4);
	TextDrawLetterSize(TD_PlayerHUD_FPSPingPLossStatic[0], 0.500000, 1.000000);
	TextDrawColor(TD_PlayerHUD_FPSPingPLossStatic[0], 48);
	TextDrawSetOutline(TD_PlayerHUD_FPSPingPLossStatic[0], 0);
	TextDrawSetProportional(TD_PlayerHUD_FPSPingPLossStatic[0], 1);
	TextDrawSetShadow(TD_PlayerHUD_FPSPingPLossStatic[0], 1);
	TextDrawUseBox(TD_PlayerHUD_FPSPingPLossStatic[0], 1);
	TextDrawBoxColor(TD_PlayerHUD_FPSPingPLossStatic[0], 48);
	TextDrawTextSize(TD_PlayerHUD_FPSPingPLossStatic[0], 107.000000, 27.000000);
		
	TD_PlayerHUD_FPSPingPLossStatic[1] = TextDrawCreate(538.000000, 1.000000, "FPS________Ping________P-Loss");
	TextDrawBackgroundColor(TD_PlayerHUD_FPSPingPLossStatic[1], 255);
	TextDrawFont(TD_PlayerHUD_FPSPingPLossStatic[1], 1);
	TextDrawLetterSize(TD_PlayerHUD_FPSPingPLossStatic[1], 0.170000, 0.899998);
	TextDrawColor(TD_PlayerHUD_FPSPingPLossStatic[1], 126869759);
	TextDrawSetOutline(TD_PlayerHUD_FPSPingPLossStatic[1], 0);
	TextDrawSetProportional(TD_PlayerHUD_FPSPingPLossStatic[1], 1);
	TextDrawSetShadow(TD_PlayerHUD_FPSPingPLossStatic[1], 1);
	TextDrawUseBox(TD_PlayerHUD_FPSPingPLossStatic[1], 1);
	TextDrawBoxColor(TD_PlayerHUD_FPSPingPLossStatic[1], 48);
	TextDrawTextSize(TD_PlayerHUD_FPSPingPLossStatic[1], 637.000000, 72.000000);	
	
	TD_PlayerHUD_Stats_Static[0] = TextDrawCreate(516.000000, 99.000000, "LD_POKE:cd9s");
	TextDrawAlignment(TD_PlayerHUD_Stats_Static[0], 3);
	TextDrawBackgroundColor(TD_PlayerHUD_Stats_Static[0], 255);
	TextDrawFont(TD_PlayerHUD_Stats_Static[0], 4);
	TextDrawLetterSize(TD_PlayerHUD_Stats_Static[0], 0.219999, 0.699998);
	TextDrawColor(TD_PlayerHUD_Stats_Static[0], 48);
	TextDrawSetOutline(TD_PlayerHUD_Stats_Static[0], 0);
	TextDrawSetProportional(TD_PlayerHUD_Stats_Static[0], 1);
	TextDrawSetShadow(TD_PlayerHUD_Stats_Static[0], 1);
	TextDrawUseBox(TD_PlayerHUD_Stats_Static[0], 1);
	TextDrawBoxColor(TD_PlayerHUD_Stats_Static[0], 255);
	TextDrawTextSize(TD_PlayerHUD_Stats_Static[0], 75.000000, 31.000000);

	TD_PlayerHUD_Stats_Static[1] = TextDrawCreate(553.000000, 100.000000, " "); //Kills:~n~Deaths:~n~Damage:~n~
	TextDrawAlignment(TD_PlayerHUD_Stats_Static[1], 3);
	TextDrawBackgroundColor(TD_PlayerHUD_Stats_Static[1], 187);
	TextDrawFont(TD_PlayerHUD_Stats_Static[1], 1);
	TextDrawLetterSize(TD_PlayerHUD_Stats_Static[1], 0.219999, 0.999998);
	TextDrawColor(TD_PlayerHUD_Stats_Static[1], 126869759);
	TextDrawSetOutline(TD_PlayerHUD_Stats_Static[1], 0);
	TextDrawSetProportional(TD_PlayerHUD_Stats_Static[1], 1);
	TextDrawSetShadow(TD_PlayerHUD_Stats_Static[1], 1);	
	
	//--------------------------------------------------------------------------
				
	TD_Spectator_Static[0] = TextDrawCreate(254.000000, 258.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_Spectator_Static[0], 255);
	TextDrawFont(TD_Spectator_Static[0], 4);
	TextDrawLetterSize(TD_Spectator_Static[0], 0.500000, 1.000000);
	TextDrawColor(TD_Spectator_Static[0], 48);
	TextDrawSetOutline(TD_Spectator_Static[0], 0);
	TextDrawSetProportional(TD_Spectator_Static[0], 1);
	TextDrawSetShadow(TD_Spectator_Static[0], 1);
	TextDrawUseBox(TD_Spectator_Static[0], 1);
	TextDrawBoxColor(TD_Spectator_Static[0], 255);
	TextDrawTextSize(TD_Spectator_Static[0], 132.000000, 44.000000);
		
	TD_Spectator_Static[1] = TextDrawCreate(235.500000, 303.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_Spectator_Static[1], 255);
	TextDrawFont(TD_Spectator_Static[1], 4);
	TextDrawLetterSize(TD_Spectator_Static[1], 0.500000, 2.000000);
	TextDrawColor(TD_Spectator_Static[1], 48);
	TextDrawSetOutline(TD_Spectator_Static[1], 0);
	TextDrawSetProportional(TD_Spectator_Static[1], 1);
	TextDrawSetShadow(TD_Spectator_Static[1], 1);
	TextDrawUseBox(TD_Spectator_Static[1], 1);
	TextDrawBoxColor(TD_Spectator_Static[1], 255);
	TextDrawTextSize(TD_Spectator_Static[1], 171.000000, 57.000000);
	
	TD_Spectator_Team_PlayersHealth[0] = TextDrawCreate(6.000000, 295.000000, " "); //~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd
	TextDrawBackgroundColor(TD_Spectator_Team_PlayersHealth[0], 0x00000070);
	TextDrawFont(TD_Spectator_Team_PlayersHealth[0], 1);
	TextDrawLetterSize(TD_Spectator_Team_PlayersHealth[0], 0.170000, 0.889999);
	TextDrawColor(TD_Spectator_Team_PlayersHealth[0], -1);
	TextDrawSetOutline(TD_Spectator_Team_PlayersHealth[0], 1);
	TextDrawSetProportional(TD_Spectator_Team_PlayersHealth[0], 1);

	TD_Spectator_Team_PlayersHealth[1] = TextDrawCreate(630.000000, 295.000000, " "); //~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd
	TextDrawAlignment(TD_Spectator_Team_PlayersHealth[1], 3);
	TextDrawBackgroundColor(TD_Spectator_Team_PlayersHealth[1], 0x00000070);
	TextDrawFont(TD_Spectator_Team_PlayersHealth[1], 1);
	TextDrawLetterSize(TD_Spectator_Team_PlayersHealth[1], 0.170000, 0.899999);
	TextDrawColor(TD_Spectator_Team_PlayersHealth[1], -1);
	TextDrawSetOutline(TD_Spectator_Team_PlayersHealth[1], 1);
	TextDrawSetProportional(TD_Spectator_Team_PlayersHealth[1], 1);

	//--------------------------------------------------------------------------
	
	TD_Round_Team_PlayersHealth[0] = TextDrawCreate(630.000000, 295.000000, " "); //~n~~n~~r~asd  ~w~100.0 (100.0)~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd
	TextDrawAlignment(TD_Round_Team_PlayersHealth[0], 3);
	TextDrawBackgroundColor(TD_Round_Team_PlayersHealth[0], 0x00000070);
	TextDrawFont(TD_Round_Team_PlayersHealth[0], 1);
	TextDrawLetterSize(TD_Round_Team_PlayersHealth[0], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Team_PlayersHealth[0], -1);
	TextDrawSetOutline(TD_Round_Team_PlayersHealth[0], 1);
	TextDrawSetProportional(TD_Round_Team_PlayersHealth[0], 1);
		
	TD_Round_Team_PlayersHealth[1] = TextDrawCreate(630.000000, 295.000000, " "); //~n~~n~~b~asd  ~w~100.0 (100.0)~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd~n~~n~asd
	TextDrawAlignment(TD_Round_Team_PlayersHealth[1], 3);
	TextDrawBackgroundColor(TD_Round_Team_PlayersHealth[1], 0x00000070);
	TextDrawFont(TD_Round_Team_PlayersHealth[1], 1);
	TextDrawLetterSize(TD_Round_Team_PlayersHealth[1], 0.170000, 0.899999);
	TextDrawColor(TD_Round_Team_PlayersHealth[1], -1);
	TextDrawSetOutline(TD_Round_Team_PlayersHealth[1], 1);
	TextDrawSetProportional(TD_Round_Team_PlayersHealth[1], 1);	

	//--------------------------------------------------------------------------
	
	TD_Round_First_Blood = TextDrawCreate(553.500000, 136.000000, "First Blood");
	TextDrawAlignment(TD_Round_First_Blood, 2);
	TextDrawBackgroundColor(TD_Round_First_Blood, 255);
	TextDrawFont(TD_Round_First_Blood, 1);
	TextDrawLetterSize(TD_Round_First_Blood, 0.280000, 1.200000);
	TextDrawColor(TD_Round_First_Blood, 126869759);
	TextDrawSetOutline(TD_Round_First_Blood, 0);
	TextDrawSetProportional(TD_Round_First_Blood, 1);
	TextDrawSetShadow(TD_Round_First_Blood, 1);
	TextDrawUseBox(TD_Round_First_Blood, 1);
	TextDrawBoxColor(TD_Round_First_Blood, 48);
	TextDrawTextSize(TD_Round_First_Blood, 0.000000, 71.000000);	
	
	TD_SpawnProtect = TextDrawCreate(553.500000, 155.000000, " "); //Spawn Protect ~w~120
	TextDrawAlignment(TD_SpawnProtect, 2);
	TextDrawBackgroundColor(TD_SpawnProtect, 255);
	TextDrawFont(TD_SpawnProtect, 1);
	TextDrawLetterSize(TD_SpawnProtect, 0.219999, 0.999998);
	TextDrawColor(TD_SpawnProtect, 126869759);
	TextDrawSetOutline(TD_SpawnProtect, 0);
	TextDrawSetProportional(TD_SpawnProtect, 1);
	TextDrawSetShadow(TD_SpawnProtect, 1);
	TextDrawUseBox(TD_SpawnProtect, 1);
	TextDrawBoxColor(TD_SpawnProtect, 48);
	TextDrawTextSize(TD_SpawnProtect, 0.000000, 71.000000);		
	
	//--------------------------------------------------------------------------
	
	TD_Round_CrashAdd_Static[0] = TextDrawCreate(240.000000, 10.000000, "LD_POKE:cd9s");
	TextDrawBackgroundColor(TD_Round_CrashAdd_Static[0], 255);
	TextDrawFont(TD_Round_CrashAdd_Static[0], 4);
	TextDrawLetterSize(TD_Round_CrashAdd_Static[0], 0.500000, 1.000000);
	TextDrawColor(TD_Round_CrashAdd_Static[0], 80);
	TextDrawSetOutline(TD_Round_CrashAdd_Static[0], 0);
	TextDrawSetProportional(TD_Round_CrashAdd_Static[0], 1);
	TextDrawSetShadow(TD_Round_CrashAdd_Static[0], 1);
	TextDrawUseBox(TD_Round_CrashAdd_Static[0], 1);
	TextDrawBoxColor(TD_Round_CrashAdd_Static[0], 255);
	TextDrawTextSize(TD_Round_CrashAdd_Static[0], 160.000000, 54.000000);

	TD_Round_CrashAdd_Static[1] = TextDrawCreate(320.000000, 15.000000, "Crash Add");
	TextDrawAlignment(TD_Round_CrashAdd_Static[1], 2);
	TextDrawBackgroundColor(TD_Round_CrashAdd_Static[1], 255);
	TextDrawFont(TD_Round_CrashAdd_Static[1], 1);
	TextDrawLetterSize(TD_Round_CrashAdd_Static[1], 0.390000, 1.800000);
	TextDrawColor(TD_Round_CrashAdd_Static[1], 126869759);
	TextDrawSetOutline(TD_Round_CrashAdd_Static[1], 0);
	TextDrawSetProportional(TD_Round_CrashAdd_Static[1], 1);
	TextDrawSetShadow(TD_Round_CrashAdd_Static[1], 1);

	TD_Round_CrashAdd_Static[2] = TextDrawCreate(320.000000, 33.000000, " "); //Trwa oczekiwanie na decyzje administratora
	TextDrawAlignment(TD_Round_CrashAdd_Static[2], 2);
	TextDrawBackgroundColor(TD_Round_CrashAdd_Static[2], 255);
	TextDrawFont(TD_Round_CrashAdd_Static[2], 1);
	TextDrawLetterSize(TD_Round_CrashAdd_Static[2], 0.210000, 1.200000);
	TextDrawColor(TD_Round_CrashAdd_Static[2], -1);
	TextDrawSetOutline(TD_Round_CrashAdd_Static[2], 0);
	TextDrawSetProportional(TD_Round_CrashAdd_Static[2], 1);
	TextDrawSetShadow(TD_Round_CrashAdd_Static[2], 1);

	TD_Round_CrashAdd_Static[3] = TextDrawCreate(320.000000, 48.000000, "/cadd  |  /pause");
	TextDrawAlignment(TD_Round_CrashAdd_Static[3], 2);
	TextDrawBackgroundColor(TD_Round_CrashAdd_Static[3], 255);
	TextDrawFont(TD_Round_CrashAdd_Static[3], 1);
	TextDrawLetterSize(TD_Round_CrashAdd_Static[3], 0.210000, 1.200000);
	TextDrawColor(TD_Round_CrashAdd_Static[3], -176);
	TextDrawSetOutline(TD_Round_CrashAdd_Static[3], 0);
	TextDrawSetProportional(TD_Round_CrashAdd_Static[3], 1);
	TextDrawSetShadow(TD_Round_CrashAdd_Static[3], 0);	
	
	//--------------------------------------------------------------------------
		
	TD_ArenaTDM_Static = TextDrawCreate(246.500000, 401.000000, "LD_POKE:cd9s");
	TextDrawAlignment(TD_ArenaTDM_Static, 2);
	TextDrawBackgroundColor(TD_ArenaTDM_Static, 255);
	TextDrawFont(TD_ArenaTDM_Static, 4);
	TextDrawLetterSize(TD_ArenaTDM_Static, 0.210000, 1.000000);
	TextDrawColor(TD_ArenaTDM_Static, 48);
	TextDrawSetOutline(TD_ArenaTDM_Static, 0);
	TextDrawSetProportional(TD_ArenaTDM_Static, 1);
	TextDrawSetShadow(TD_ArenaTDM_Static, 1);
	TextDrawUseBox(TD_ArenaTDM_Static, 1);
	TextDrawBoxColor(TD_ArenaTDM_Static, 255);
	TextDrawTextSize(TD_ArenaTDM_Static, 147.000000, 17.000000);
	TextDrawSetSelectable(TD_ArenaTDM_Static, 0);

	TD_ArenaTDM_Info = TextDrawCreate(320.000000, 405.000000, " "); //~r~Team One   ~w~999 : 999  ~b~Team Two
	TextDrawAlignment(TD_ArenaTDM_Info, 2);
	TextDrawBackgroundColor(TD_ArenaTDM_Info, 170);
	TextDrawFont(TD_ArenaTDM_Info, 1);
	TextDrawLetterSize(TD_ArenaTDM_Info, 0.210000, 1.000000);
	TextDrawColor(TD_ArenaTDM_Info, 0xFFFFFFFF);
	TextDrawSetOutline(TD_ArenaTDM_Info, 0);
	TextDrawSetProportional(TD_ArenaTDM_Info, 1);
	TextDrawSetShadow(TD_ArenaTDM_Info, 1);
	TextDrawUseBox(TD_ArenaTDM_Info, 1);
	TextDrawBoxColor(TD_ArenaTDM_Info, 48);
	TextDrawTextSize(TD_ArenaTDM_Info, 1.000000, 140.000000);
	TextDrawSetSelectable(TD_ArenaTDM_Info, 0);	
	
	TD_VehicleHealth_Static[0] = TextDrawCreate(576.500000, 36.000000, "_");
	TextDrawAlignment(TD_VehicleHealth_Static[0], 2);
	TextDrawBackgroundColor(TD_VehicleHealth_Static[0], 255);
	TextDrawFont(TD_VehicleHealth_Static[0], 1);
	TextDrawLetterSize(TD_VehicleHealth_Static[0], 0.500000, 0.449999);
	TextDrawColor(TD_VehicleHealth_Static[0], 255);
	TextDrawSetOutline(TD_VehicleHealth_Static[0], 0);
	TextDrawSetProportional(TD_VehicleHealth_Static[0], 1);
	TextDrawSetShadow(TD_VehicleHealth_Static[0], 1);
	TextDrawUseBox(TD_VehicleHealth_Static[0], 1);
	TextDrawBoxColor(TD_VehicleHealth_Static[0], 255);
	TextDrawTextSize(TD_VehicleHealth_Static[0], 62.000000, 58.000000);
	TextDrawSetSelectable(TD_VehicleHealth_Static[0], 0);

	TD_VehicleHealth_Static[1] = TextDrawCreate(576.500000, 38.000000, "_");
	TextDrawAlignment(TD_VehicleHealth_Static[1], 2);
	TextDrawBackgroundColor(TD_VehicleHealth_Static[1], 255);
	TextDrawFont(TD_VehicleHealth_Static[1], 1);
	TextDrawLetterSize(TD_VehicleHealth_Static[1], 0.500000, 0.050000);
	TextDrawColor(TD_VehicleHealth_Static[1], -1234105601);
	TextDrawSetOutline(TD_VehicleHealth_Static[1], 0);
	TextDrawSetProportional(TD_VehicleHealth_Static[1], 1);
	TextDrawSetShadow(TD_VehicleHealth_Static[1], 1);
	TextDrawUseBox(TD_VehicleHealth_Static[1], 1);
	TextDrawBoxColor(TD_VehicleHealth_Static[1], 2102722815);
	TextDrawTextSize(TD_VehicleHealth_Static[1], 62.000000, 54.000000);
	TextDrawSetSelectable(TD_VehicleHealth_Static[1], 0);
}
