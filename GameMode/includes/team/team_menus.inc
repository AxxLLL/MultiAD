/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerPasswordMenu(&playerid, password[] = "") {
	new teamid;
	if(TEAM_ONE <= (teamid = GetPVarInt(playerid, PV_HELP_VAR_2)) <= TEAM_TWO) {
		printf("showPlayerPasswordMenu: %s", password);
		if(getTeamPassword(teamid) == 0 || getPlayerTeamPassword(playerid, teamid) == getTeamPassword(teamid)) {
			setPlayerTeamPassword(playerid, teamid, getTeamPassword(teamid));
			if(GetPVarInt(playerid, PV_HELP_VAR_3) == 0) SpawnPlayer(playerid);
			else switchPlayerTeam(playerid, teamid);
		} else {	
			new string[128], error[32];
			if(!isnull(password)) {
				if(strlen(password) == 4 && '1' <= password[0] <= '9' && getTeamPassword(teamid) == strval(password)) {
					setPlayerTeamPassword(playerid, teamid, strval(password));
					if(GetPVarInt(playerid, PV_HELP_VAR_3) == 1) switchPlayerTeam(playerid, teamid);
					else {
						getDialogBodyMessage(string, DIALOG_BODY_PASSWORD, 2);
						SendClientMessage(playerid, COLOR_INFO_1, string);
					}
					return 1;
				} else getDialogBodyMessage(error, DIALOG_BODY_PASSWORD, 1);
			}
			getDialogBodyMessage(string, DIALOG_BODY_PASSWORD, 0);
			format(string, sizeof(string), string, error);
			ShowPlayerDialog(playerid, DIALOG_TEAM_PASSWORD, DIALOG_STYLE_INPUT, getDialogCaptionMessage(DIALOG_CAPTION_PASSWORD), string, oftenUsedPhrases(LANG_OUP_READY), oftenUsedPhrases(LANG_OUP_CANCEL));
		}
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
showPlayerSwitchMenu(playerid, listitem = -1) {
	new switch_playerid = GetPVarInt(playerid, PV_HELP_VAR_1);
	if(IsPlayerConnected(switch_playerid) && (switch_playerid == playerid || IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN))) {
		if(getPlayerStatus(switch_playerid) == PLAYER_STATUS_LOBBY) {
			switch(listitem) {
				case 0: switchPlayerTeam(playerid, TEAM_ONE);
				case 1: switchPlayerTeam(playerid, TEAM_TWO);
				case 2: switchPlayerTeam(playerid, TEAM_REF);
				default: {
					new string[128], team_color[3][12];
					
					getTeamColorText(TEAM_ONE, COLOR_STATUS_ACTIVE, team_color[0]);
					getTeamColorText(TEAM_TWO, COLOR_STATUS_ACTIVE, team_color[1]);
					getTeamColorText(TEAM_REF, COLOR_STATUS_ACTIVE, team_color[2]);
					
					format(string, sizeof(string), COLOR_DIALOG_COUNT">> %s%s\n"COLOR_DIALOG_COUNT">> %s%s\n"COLOR_DIALOG_COUNT">> %s%s", team_color[0], getTeamName(TEAM_ONE), team_color[1], getTeamName(TEAM_TWO), team_color[2], getTeamName(TEAM_REF));
					ShowPlayerDialog(playerid, DIALOG_SWITCH_TEAM_MENU, DIALOG_STYLE_LIST, getDialogCaptionMessage(DIALOG_CAPTION_SWITCH_MENU), string, oftenUsedPhrases(LANG_OUP_SELECT), oftenUsedPhrases(LANG_OUP_CANCEL));
				}
			}
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
switchPlayerTeam(playerid, teamid) {
	new switch_playerid = GetPVarInt(playerid, PV_HELP_VAR_1);
	if(IsPlayerConnected(switch_playerid) && (switch_playerid == playerid || IsAdminOrRCON(playerid, ALVL_ADMIN))) {
		if(getPlayerStatus(switch_playerid) == PLAYER_STATUS_LOBBY) {
			if(getPlayerTeam(switch_playerid) != teamid) {
				if(getTeamPassword(teamid) != 0 && getTeamPassword(teamid) != getPlayerTeamPassword(switch_playerid, teamid) && !IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
					SetPVarInt(switch_playerid, PV_HELP_VAR_2, teamid);
					SetPVarInt(switch_playerid, PV_HELP_VAR_3, 1);
					showPlayerPasswordMenu(switch_playerid);
					return 1;
				}
				setPlayerTeam(switch_playerid, teamid, (switch_playerid != playerid ? TEAM_REASON_ADMIN_SWAP : TEAM_REASON_SWITCH), true);
			}
			return 1;
		}
	}
	return 0;
}