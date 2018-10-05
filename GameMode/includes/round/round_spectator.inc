/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward startSpectate(playerid, specid);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SPEC_FORWARD							0
#define SPEC_BACKWARD							1
//------------------------------------------------------------------------------
#define getSpecButtonProtectTime(%1)			g_Round_PlayerButtonProtect[%1]
#define setSpecButtonProtectTime(%1,%2)			g_Round_PlayerButtonProtect[%1] = %2
//------------------------------------------------------------------------------
#define getPlayerSpecID(%1)						g_Round_PlayerSpecID[%1]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_PlayerSpecID[MAX_PLAYERS] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID, INVALID_PLAYER_ID, ...};
new g_Round_PlayerButtonProtect[MAX_PLAYERS];
new bool:g_Round_Player_SpecList[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getPlayerSpecListStatus(&playerid) return _:g_Round_Player_SpecList[playerid];
setPlayerSpecListStatus(&playerid, bool:enable) {
	g_Round_Player_SpecList[playerid] = enable;
	return 1;
}
//------------------------------------------------------------------------------
findPlayerToSpectate(&playerid, direction = SPEC_FORWARD) {
	new max_players;
	if(getPlayerStatus(playerid) == PLAYER_STATUS_SPECTATE && (max_players = GetMaxPlayers()) > g_Round_PlayerSpecID[playerid] >= 0) {
		new p_team = getPlayerTeam(playerid);
		if(direction == SPEC_FORWARD) {
			for(new i = g_Round_PlayerSpecID[playerid] + 1; ;) {
				if(i < max_players) {	
					if(IsPlayerConnected(i) && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && (p_team == TEAM_REF || p_team == getPlayerTeam(i))) return startSpectate(playerid, i);
					if(i == g_Round_PlayerSpecID[playerid]) {
						stopSpectate(playerid);
						return 0;
					}					
					if((++ i) == max_players) i = 0;
				} else i = 0;
			}
		} else {
			for(new i = g_Round_PlayerSpecID[playerid] - 1; ;) {
				if(i >= 0) {	
					if(IsPlayerConnected(i) && getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && (p_team == TEAM_REF || p_team == getPlayerTeam(i))) return startSpectate(playerid, i);
					if(i == g_Round_PlayerSpecID[playerid]) {
						stopSpectate(playerid);
						return -1;
					}					
					if((-- i) < 0) i = max_players - 1;
				} else i = max_players - 1;
			}		
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
public startSpectate(playerid, specid) {
	if(getRoundState() == ROUND_STATE_REMAIN && GetPlayerState(playerid) != PLAYER_STATE_WASTED && (getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY || getPlayerStatus(playerid) == PLAYER_STATUS_SPECTATE || getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY_TDM)) {
		new p_team = getPlayerTeam(playerid), string[64], oldspecid;
		if(specid == INVALID_PLAYER_ID) {
			forplayers(i) {
				if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && (p_team == TEAM_REF || p_team == getPlayerTeam(i))) {
					specid = i;
					break;
				}
			}				
			if(specid == INVALID_PLAYER_ID) {
				stopSpectate(playerid);
				return 0;			
			}
		} else {
			if(!IsPlayerConnected(specid) || getPlayerStatus(specid) != PLAYER_STATUS_IN_ROUND || (getPlayerTeam(specid) != p_team && p_team != TEAM_REF)) return 0;
		}
		
		oldspecid = g_Round_PlayerSpecID[playerid];
		SetPlayerInterior(playerid, getRoundInterior());
		SetPlayerVirtualWorld(playerid, VW_ROUND);
		format(string, sizeof(string), "~<~ %s ~>~_____~n~~n~~n~_", getPlayerName(specid));
		PlayerTextDrawSetString(playerid, PTD_Spectator_Nick[playerid], string);
		PlayerTextDrawColor(playerid, PTD_Spectator_Nick[playerid], getTeamColorInt(getPlayerTeam(specid), COLOR_STATUS_ACTIVE));
		PlayerTextDrawShow(playerid, PTD_Spectator_Nick[playerid]);
		
		TogglePlayerSpectating(playerid, true);
		if(IsPlayerInAnyVehicle(specid)) PlayerSpectateVehicle(playerid, GetPlayerVehicleID(specid));
		else PlayerSpectatePlayer(playerid, specid);
		g_Round_PlayerSpecID[playerid] = specid;
		setPlayerStatus(playerid, PLAYER_STATUS_SPECTATE);
		
		CallLocalFunction("OnPlayerStartSpectatePlayer", "ddd", playerid, specid, oldspecid);
		return 1;
	} else stopSpectate(playerid);
	return 0;
}
//------------------------------------------------------------------------------
stopSpectate(&playerid, bool:callremotefunction = true) {
	if(getPlayerStatus(playerid) == PLAYER_STATUS_SPECTATE) {	
		if(callremotefunction) CallLocalFunction("OnPlayerStartSpectatePlayer", "ddd", playerid, INVALID_PLAYER_ID, g_Round_PlayerSpecID[playerid]);
		setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
		g_Round_PlayerSpecID[playerid] = INVALID_PLAYER_ID;		
		g_Round_PlayerButtonProtect[playerid] = 0;
		TogglePlayerSpectating(playerid, false);		
		return 1;
	}	
	return 0;
}