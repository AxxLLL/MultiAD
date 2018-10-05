/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward OnTeamNameChange(teamid, newname[], oldname[]);
forward OnTeamSkinChange(teamid, newskin, oldskin);
forward OnTeamPasswordChange(teamid, newpassword, oldpassword);
forward OnTeamPointsChange(teamid, newpoints, oldpoints);
forward OnDefendingTeamSwap(defteam);
forward OnTeamColorChange(teamid, COLOR_TYPES:newcolor, COLOR_TYPES:oldcolor);
//------------------------------------------------------------------------------
forward OnPlayerTeamChange(playerid, newteam, oldteam, reason);
//==============================================================================
forward COLOR_TYPES:getTeamColorType(teamid);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	GLOBAL_TEAM				TEAM_REF
//------------------------------------------------------------------------------
#define MIN_TEAM_NAME_LENGTH	1
#define MAX_TEAM_NAME_LENGTH	8
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new const g_ColorTypes[COLOR_TYPES][5] = {
	{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1, 	1},
	{0xE407CEFF, 0xE407CEFF, 0xE407CEFF, 148, 	148},
	{0xED1818FF, 0xFFAAAAFF, 0xFF6666FF, 3, 	3},
	{0x2F33C6FF, 0x7DAEFFFF, 0x3183FDFF, 79, 	79},
	{0x2BB816FF, 0x9DFB86FF, 0x41E04DFF, 86, 	86},
	{0xDDD815FF, 0xEDECB1FF, 0xE2EB78FF, 6, 	6},
	{0x10FFFFFF, 0x10D7D7FF, 0x109B9BFF, 2, 	2}
};
//------------------------------------------------------------------------------
enum TEAM_DATA {TEAM_NAME[MAX_TEAM_NAME_LENGTH + 1], TEAM_SKIN, TEAM_PASSWORD, TEAM_POINTS, COLOR_TYPES:TEAM_COLOR_TYPE}
new g_TeamData[3][TEAM_DATA];
//------------------------------------------------------------------------------
new g_Team_Defending = TEAM_TWO;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/team/player_team.inc"
#include "includes/team/team_menus.inc"
#include "includes/team/team_settings_menu.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
setTeamName(teamid, name[], bool:force_name = false) {
	if(isValidTeamName(name, teamid, force_name) && TEAM_REF >= teamid >= TEAM_ONE) {
		new oldname[MAX_TEAM_NAME_LENGTH + 1];
		if(g_TeamData[teamid][TEAM_NAME][0] == EOS) strins(oldname, "No_Team", 0);
		else strins(oldname, g_TeamData[teamid][TEAM_NAME], 0); 
		strins((g_TeamData[teamid][TEAM_NAME][0] = EOS, g_TeamData[teamid][TEAM_NAME]), name, 0);		
		CallLocalFunction("OnTeamNameChange", "dss", teamid, name, oldname);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getTeamName(teamid) {
	new name[MAX_TEAM_NAME_LENGTH + 1] = "No_Team";
	if(TEAM_ONE <= teamid <= TEAM_REF && !isnull(g_TeamData[teamid][TEAM_NAME])) strins((name[0] = EOS, name), g_TeamData[teamid][TEAM_NAME], 0);
	return name;
}
//------------------------------------------------------------------------------
setTeamSkin(teamid, skinid, bool:force = false) {
	if(TEAM_ONE <= teamid <= TEAM_REF && 0 <= skinid <= 299 && (force == true || (g_TeamData[TEAM_ONE][TEAM_SKIN] != skinid && g_TeamData[TEAM_TWO][TEAM_SKIN] != skinid && g_TeamData[TEAM_REF][TEAM_SKIN] != skinid))) {
		new oldskinid = g_TeamData[teamid][TEAM_SKIN];
		
		forplayers(i) {
			if(g_Player_Team[i] == teamid) {
				SetSpawnInfo(i, GLOBAL_TEAM, skinid, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
				if(IsPlayerInAnyVehicle(i)) RemovePlayerFromVehicle(i);
				if(GetPlayerState(i) != PLAYER_STATE_WASTED) SpawnPlayer(i);
			}
		}
		
		CallLocalFunction("OnTeamSkinChange", "ddd", teamid, (g_TeamData[teamid][TEAM_SKIN] = skinid), oldskinid);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getTeamSkin(teamid) return ((TEAM_ONE <= teamid <= TEAM_REF) ? g_TeamData[teamid][TEAM_SKIN] : 0);
//------------------------------------------------------------------------------
setTeamPassword(teamid, password) {
	new oldpassword;
	if(TEAM_ONE <= teamid <= TEAM_REF && (1000 <= password <= 9999 || password == 0) && (oldpassword = g_TeamData[teamid][TEAM_PASSWORD]) != password) {
		if((oldpassword = g_TeamData[teamid][TEAM_PASSWORD]) != password) CallLocalFunction("OnTeamPasswordChange", "ddd", teamid, (g_TeamData[teamid][TEAM_PASSWORD] = password), oldpassword);
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
getTeamPassword(teamid) return ((TEAM_ONE <= teamid <= TEAM_REF && 1000 <= g_TeamData[teamid][TEAM_PASSWORD] <= 9999) ? g_TeamData[teamid][TEAM_PASSWORD] : 0);
//------------------------------------------------------------------------------
setTeamColorType(teamid, COLOR_TYPES:color_type, bool:force = false) {
	new COLOR_TYPES:old_color_type;
	if((force ||
		(
		(teamid == TEAM_ONE && g_TeamData[TEAM_TWO][TEAM_COLOR_TYPE] != color_type && g_TeamData[TEAM_REF][TEAM_COLOR_TYPE] != color_type) ||
		(teamid == TEAM_TWO && g_TeamData[TEAM_ONE][TEAM_COLOR_TYPE] != color_type && g_TeamData[TEAM_REF][TEAM_COLOR_TYPE] != color_type) ||
		(teamid == TEAM_REF && g_TeamData[TEAM_ONE][TEAM_COLOR_TYPE] != color_type && g_TeamData[TEAM_TWO][TEAM_COLOR_TYPE] != color_type)
		)) && (old_color_type = g_TeamData[teamid][TEAM_COLOR_TYPE]) != color_type && color_type != COLOR_TYPE_NON) {			
			
			
		g_TeamData[teamid][TEAM_COLOR_TYPE] = color_type;
		
		forplayers(i) {
			if(getPlayerTeam(i) == teamid) {
				SetPlayerColor(i, (g_ColorTypes[color_type][(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND ? COLOR_STATUS_ACTIVE : (getPlayerAFKMode(i) ? COLOR_STATUS_INACTIVE : COLOR_STATUS_DEATH))] & 0xFFFFFF00));
			}
		}
		
		if(getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_BASE) {
			new vehicleid, v_color_1, v_color_2;
			getTeamVehicleColor((g_Team_Defending == TEAM_ONE ? TEAM_TWO : TEAM_ONE), v_color_1, v_color_2);
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) != g_Team_Defending && (vehicleid = getPlayerRoundVehicleID(i)) != -1) {
					ChangeVehicleColor(vehicleid, 0, 1);
				}
			}				
		}	
		
		CallLocalFunction("OnTeamColorChange", "ddd", teamid, _:color_type, _:old_color_type);			
		return 1;
		
	}
	return 0;
}
//------------------------------------------------------------------------------
getTeamVehicleColor(teamid, &color_1, &color_2) {
	color_1 = color_2 = 1;
	if(TEAM_ONE <= teamid <= TEAM_REF) {
		color_1 = g_ColorTypes[g_TeamData[teamid][TEAM_COLOR_TYPE]][3];
		color_1 = g_ColorTypes[g_TeamData[teamid][TEAM_COLOR_TYPE]][4];
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getTeamColorInt(teamid, status) return (TEAM_ONE <= teamid <= TEAM_REF && COLOR_STATUS_ACTIVE <= status <= COLOR_STATUS_DEATH) ? g_ColorTypes[g_TeamData[teamid][TEAM_COLOR_TYPE]][status] : 0xC8C8C8FF;
//------------------------------------------------------------------------------
getTeamColorText(teamid, status, color[], size = sizeof(color)) {
	format(color, size, "{%x}", getTeamColorInt(teamid, status));
	strdel(color, 7, 9);
}
//------------------------------------------------------------------------------
getColorText(COLOR_TYPES:index, status, color[], size = sizeof(color)) {
	if(COLOR_STATUS_ACTIVE <= status <= COLOR_STATUS_DEATH && index != COLOR_TYPE_NON) {
		format(color, size, "{%x}", g_ColorTypes[index][status]);
		strdel(color, 7, 9);	
	} else {
		format(color, size, "{FFFFFF}");
	}
}
//------------------------------------------------------------------------------
COLOR_TYPES:getTeamColorType(teamid) return g_TeamData[teamid][TEAM_COLOR_TYPE];
//------------------------------------------------------------------------------
isTeamColorTypeInUse(COLOR_TYPES:type) {
	for(new i; i <= TEAM_REF; i ++) {
		if(g_TeamData[i][TEAM_COLOR_TYPE] == type) return i;
	}
	return TEAM_NON;
}
//------------------------------------------------------------------------------
swapDefendingTeam(bool:swapskins) {
	g_Team_Defending = (g_Team_Defending == TEAM_ONE ? TEAM_TWO : TEAM_ONE);
	if(swapskins) {
		new skin = g_TeamData[TEAM_ONE][TEAM_SKIN];
		setTeamSkin(TEAM_ONE, g_TeamData[TEAM_TWO][TEAM_SKIN], true);
		setTeamSkin(TEAM_TWO, skin, true);
	}
	CallLocalFunction("OnDefendingTeamSwap", "d", g_Team_Defending);
	return 1;
}
//------------------------------------------------------------------------------
getDefendingTeam() return g_Team_Defending;
//------------------------------------------------------------------------------
getTeamPoints(teamid) return ((TEAM_ONE <= teamid <= TEAM_TWO) ? g_TeamData[teamid][TEAM_POINTS] : 0);
//------------------------------------------------------------------------------
setTeamPoints(teamid, points) {
	new oldpoints;
	if(teamid <= TEAM_TWO && 999 >= points >= 0 && (oldpoints = g_TeamData[teamid][TEAM_POINTS]) != points) {
		g_TeamData[teamid][TEAM_POINTS] = points;
		CallLocalFunction("OnTeamPointsChange", "ddd", teamid, points, oldpoints);
		return 1;
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
isValidTeamName(name[], teamid, bool:ignore_team_names = false) {	
	if(!isnull(name)) {	
		new length = strlen(name), index;
		for(new i; i < length; i ++) {
			switch(name[i]) {
				case 'A'..'Z', 'a'..'z', '0'..'9', '(', ')', '[', ']', '.', '_', '$', '@', '=': continue;
				default: return 0;
			}
		}			
		
		while((index = strfind(name, "__")) != -1) strdel(name, index, index + 1);
		if(name[0] == '_') strdel(name, 0, 1);
		length = strlen(name);
		if(name[length - 1] == '_') strdel(name, length - 1, length);	
		
		if((MIN_TEAM_NAME_LENGTH <= strlen(name) <= MAX_TEAM_NAME_LENGTH) && (ignore_team_names == true || (((strcmp(g_TeamData[TEAM_ONE][TEAM_NAME], name) != 0 || teamid == TEAM_ONE) || g_TeamData[TEAM_ONE][TEAM_NAME][0] == EOS) && ((strcmp(g_TeamData[TEAM_TWO][TEAM_NAME], name) != 0 || teamid == TEAM_TWO) || g_TeamData[TEAM_TWO][TEAM_NAME][0] == EOS) && ((strcmp(g_TeamData[TEAM_REF][TEAM_NAME], name) != 0 || teamid == TEAM_REF) || g_TeamData[TEAM_REF][TEAM_NAME][0] == EOS)))) {
			return 1;
		}	
	}
	return 0;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================