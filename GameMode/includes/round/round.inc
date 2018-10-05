/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward OnRoundStateChange(newstate, oldstate);
forward OnRoundCounterChange(newvalue, oldvalue, roundlimit);
forward OnTDMTeamPointsChange(teamid, newpoints, oldpoints);
forward OnPlayerStartSpectatePlayer(playerid, newspecid, oldspecid);
//------------------------------------------------------------------------------
forward OnPlayerStatsChange(playerid, E_PLAYER_STATS_DATA:type, points);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define INVALID_MAP_ID 					-1
//------------------------------------------------------------------------------
#define DIR_ARENAS						DIR_GENERAL"/Arenas"
#define DIR_BASES						DIR_GENERAL"/Bases"
//------------------------------------------------------------------------------
#define BASE_CAPTURE_MAX_SIZE			108.000000
#define	MAX_CAMERA_POSITIONS			5
//------------------------------------------------------------------------------
#define getLoadedArenas()				g_Loaded_Maps[ROUND_TYPE_ARENA]
#define getLoadedBases()				g_Loaded_Maps[ROUND_TYPE_BASE]
#define getRoundTimeRest()				g_Round_Time
#define subRoundTime()					(-- g_Round_Time)
#define getZonePosition(%1)				g_Round_Data[ZONE][%1]
#define getBoatSpawnPosition(%1)		g_Round_Data[SPAWN_BOATS][%1]
#define getGangDefendersBaseZoneID()	g_Round_GangZones[1]
#define getDefBaseRestTime()			g_Round_DefBase_RestTime
#define subDefBaseRestTime()			(-- g_Round_DefBase_RestTime)
#define resetDefBaseRestTime()			g_Round_DefBase_RestTime = g_Round_DefBase_BackTime
#define getRoundInterior()				g_Round_Data[INTERIOR]
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_MapID = INVALID_MAP_ID;
new g_Round_RoundCounter = -1;
new g_Round_Type;
new bool:g_Round_ArenaTDM_Mode = false;
new g_Round_RandomKey = -1;
new g_Round_State = -1;
new g_Round_Time;
new g_Round_FlagObjectID = -1;
new g_Round_GangZones[2] = {-1, -1};
//------------------------------------------------------------------------------
new Float:g_Round_Armor = 50.0;
new g_Round_Time_Arenas = 10;
new g_Round_Time_Bases = 10;
new g_Round_ArenaTDM_Kill_Limit = 5;
new g_Round_ArenaTDM_Kill_Points[2] = {0, 0};
new g_Round_ArenaWinMode = WIN_HEALH_ADVANTAGE;
new g_Round_AutoSwapMode = AUTOSWAP_TEAM_AND_SKIN;
new bool:g_Round_DefBase_Enabled = true,
	g_Round_DefBase_BackTime = 20,
	g_Round_DefBase_RestTime;
new bool:g_Round_SyncInFall = false;
new bool:g_Round_TeamHealthInfoBars = true;
new g_Round_Gunmenu_Time = 45;
new bool:g_Round_SelfRemove = true;
new bool:g_Round_Vehicle_SelfRepair = true;
new g_Round_Vehicle_SelfRepair_Time = 20;
new bool:g_Round_OneOnOne_Markers = false;
//------------------------------------------------------------------------------
new Float:g_Round_StartingCamera[MAX_CAMERA_POSITIONS][3];
//------------------------------------------------------------------------------
enum SPAWN_DATA {Float:SPAWN_X, Float:SPAWN_Y, Float:SPAWN_Z, SPAWN_VX, SPAWN_VY}
enum ROUND_DATA {INTERIOR, SPAWN_TEAM_1[SPAWN_DATA], SPAWN_TEAM_2[SPAWN_DATA], SPAWN_BOATS[SPAWN_DATA], Float:ZONE[6], Float:CHECKPOINT[3]}
new g_Round_Data[ROUND_DATA];
//------------------------------------------------------------------------------
new Text:TD_Round_Start_Static[6],
	Text:TD_Round_Start_Map,
	Text:TD_Round_Start_Teams[2],
	Text:TD_Round_Start_Round;
new Text:TD_RoundBar_Static[11],
	Text:TD_RoundBar_Time,
	Text:TD_RoundBar_Base,
	Text:TD_RoundBar_Rounds,
	Text:TD_RoundBar_Name[2],
	Text:TD_RoundBar_Health[2],
	Text:TD_RoundBar_Players[2],
	Text:TD_RoundBar_Points[2],
	Text:TD_RoundBar_Color[2],
	Text:TD_RoundBar_Defend[2],
	Text:TD_RoundBar_Damage[2];
new Text:TD_Round_Capture_Static[2],
	Text:TD_Round_Capture_Box,
	Text:TD_Round_Capture_Info;
new Text:TD_Round_BTB_Player_Static,
	Text:TD_Round_BTB_Player_Info;
new Text:TD_Round_BTB_Static,
	Text:TD_Round_BTB_Info;	
new Text:TD_Round_Pause;
new Text:TD_Round_End_Static[4],
	Text:TD_Round_End_MapInfo,	
	Text:TD_Round_End_WinInfo,
	Text:TD_Round_End_Reason,
	Text:TD_Round_End_Top_Nicks,
	Text:TD_Round_End_Top_Teams,
	Text:TD_Round_End_Top_Points;
new Text:TD_Round_Match_End_Static[8],	
	Text:TD_Round_Match_End_Winner,
	Text:TD_Round_Match_End_Rounds,
	Text:TD_Round_Match_End_TNames[2],
	Text:TD_Round_Match_End_TPoints[2],	
	Text:TD_Round_Match_End_TRounds[2],
	Text:TD_Round_Match_End_TPlayers[2],
	Text:TD_Round_Match_End_TDamage[2],
	Text:TD_Round_Match_End_TKills[2],
	Text:TD_Round_Match_Result_WWW;
new Text:TD_Round_Help_Static[2],
	Text:TD_Round_Help_Nick[2];
new Text:TD_Spectator_Static[2],
	PlayerText:PTD_Spectator_Nick[MAX_PLAYERS],
	PlayerText:PTD_Spectator_HealthAndArmour[MAX_PLAYERS],
	PlayerText:PTD_Spectator_NetStats[MAX_PLAYERS],
	PlayerText:PTD_Spectator_Guns[MAX_PLAYERS][2];
new Text:TD_Spectator_Team_PlayersHealth[2];
new Text:TD_Round_Team_PlayersHealth[2];
new Text:TD_Round_CP_Map_ZPos[3];
new Text:TD_Round_First_Blood;
new Text:TD_Round_CrashAdd_Static[4];
new Text:TD_SpawnProtect;
new Text:TD_ArenaTDM_Static,
	Text:TD_ArenaTDM_Info;
new PlayerText:PTD_SpecBy_List[MAX_PLAYERS];
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/round/round_checkpoint.inc"
#include "includes/round/round_spectator.inc"
#include "includes/round/round_spawnprotect.inc"
#include "includes/round/round_start.inc"
#include "includes/round/round_end.inc"
#include "includes/round/round_functions.inc"
#include "includes/round/round_vehicles.inc"
#include "includes/round/round_strtcamera.inc"
#include "includes/round/round_pause.inc"
#include "includes/round/round_chatandrepres.inc"
#include "includes/round/round_damage.inc"
#include "includes/round/weapons/round_weapons.inc"
#include "includes/round/match/round_match.inc"
#include "includes/round/player/round_player.inc"
#include "includes/round/round_settings.inc"
#include "includes/round/weapons/rweapons_settings.inc"
#include "includes/round/round_demo.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getRoundMapID() return g_Round_MapID;
//------------------------------------------------------------------------------
getRoundState() return g_Round_State;
//------------------------------------------------------------------------------
getRoundType() return g_Round_Type;
//------------------------------------------------------------------------------
getRoundCounterValue() return g_Round_RoundCounter;
setRoundCounterValue(value, bool:force = false) {
	new oldvalue;
	if((999999 >= value >= 0 && (oldvalue = g_Round_RoundCounter) != value) || force) {
		CallLocalFunction("OnRoundCounterChange", "ddd", (g_Round_RoundCounter = value), oldvalue, (getMatchStatus() ? getMatchRoundLimit() : 0));
		if(getMatchStatus() && getMatchRoundLimit() == value) {
			//endMatch();
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getRoundRandomKey() return g_Round_RandomKey;
//------------------------------------------------------------------------------	
setRoundState(newstate) {
	if(ROUND_STATE_REMAIN >= newstate >= ROUND_STATE_LOBBY) {
		new oldstate;
		if((oldstate = g_Round_State) != newstate) {
			CallLocalFunction("OnRoundStateChange", "dd", (g_Round_State = newstate), oldstate);
			return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------	
Float:getRoundArmour() return g_Round_Armor;
setRoundArmour(Float:amount) {
	if(100.0 >= amount >= 0) {
		g_Round_Armor = amount;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------	
getRoundTime(type, bool:seconds = false) {
	if(seconds == true) return ((type == ROUND_TYPE_ARENA ? g_Round_Time_Arenas : g_Round_Time_Bases) * 60);
	else return (type == ROUND_TYPE_ARENA ? g_Round_Time_Arenas : g_Round_Time_Bases);
}
//------------------------------------------------------------------------------	
setRoundTime(type, time, bool:time_in_seconds = false) {
	if(ROUND_TYPE_BASE >= type >= ROUND_TYPE_ARENA && 60 >= time >= 3) {
		if(type == ROUND_TYPE_ARENA) g_Round_Time_Arenas = (time * (time_in_seconds == true ? 60 : 1));
		else g_Round_Time_Bases = (time * (time_in_seconds == true ? 60 : 1));
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------	
getArenaRoundWinMode() return g_Round_ArenaWinMode;
setArenaRoundWinMode(mode) {
	if(WIN_PLAYERS_ADVANTAGE >= mode >= WIN_HEALH_ADVANTAGE) {
		g_Round_ArenaWinMode = mode;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------	
getAutoSwapMode() return g_Round_AutoSwapMode;
setAutoSwapMode(mode) {
	if(AUTOSWAP_TEAM_AND_SKIN >= mode >= AUTOSWAP_NO) {
		g_Round_AutoSwapMode = mode;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------	
getDefendersBaseStatus() return _:g_Round_DefBase_Enabled;
setDefendersBaseStatus(bool:enabled) {
	g_Round_DefBase_Enabled = enabled;
	return 1;
}
//------------------------------------------------------------------------------
getDefendersBaseBackTime() return g_Round_DefBase_BackTime;
setDefendersBaseBackTime(time) {
	if(60 >= time >= 10) {
		g_Round_DefBase_BackTime = time;
		resetDefBaseRestTime();
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
syncInFall() return g_Round_SyncInFall;
setSyncInFallStatus(bool:enable) {
	g_Round_SyncInFall = enable;
	return 1;
}
//------------------------------------------------------------------------------
getTeamHealthInfoBarsStatus() return _:g_Round_TeamHealthInfoBars;
setTeamHealthInfoBarsStatus(bool:enable) {
	g_Round_TeamHealthInfoBars = enable;
}
//------------------------------------------------------------------------------
getGunMenuTime() return g_Round_Gunmenu_Time;
setGunMenuTime(time) {
	if(9999 >= time >= 10) {
		g_Round_Gunmenu_Time = time;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getSelfRemoveStatus() return _:g_Round_SelfRemove;
setSelfRemoveStatus(bool:enable) {
	g_Round_SelfRemove = enable;
}
//------------------------------------------------------------------------------
getSelfVehRepairStatus() return _:g_Round_Vehicle_SelfRepair;
setSelfVehRepairStatus(bool:enable) {
	g_Round_Vehicle_SelfRepair = enable;
}
//------------------------------------------------------------------------------
getSelfVehRepairMinTime() return g_Round_Vehicle_SelfRepair_Time;
setSelfVehRepairMinTime(time) {
	if(600 >= time >= 0) {
		g_Round_Vehicle_SelfRepair_Time = time;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getArenaTDMModeStatus() return _:g_Round_ArenaTDM_Mode;
setArenaTDMModeStatus(bool:enable) g_Round_ArenaTDM_Mode = enable;
//------------------------------------------------------------------------------
getArenaTDMKillLimit() return g_Round_ArenaTDM_Kill_Limit;
setArenaTDMKillLimit(limit) {
	if(999 >= limit >= 1) {
		g_Round_ArenaTDM_Kill_Limit = limit;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getArenaTDMPoints(teamid) return TEAM_TWO >= teamid >= TEAM_ONE ? g_Round_ArenaTDM_Kill_Points[teamid] : 0;
addArenaTDMPoint(teamid) {
	if(TEAM_TWO >= teamid >= TEAM_ONE) {
		CallLocalFunction("OnTDMTeamPointsChange", "ddd", teamid, (++ g_Round_ArenaTDM_Kill_Points[teamid]), g_Round_ArenaTDM_Kill_Points[teamid] - 1);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
subArenaTDMPoint(teamid) {
	if(TEAM_TWO >= teamid >= TEAM_ONE) {
		CallLocalFunction("OnTDMTeamPointsChange", "ddd", teamid, (-- g_Round_ArenaTDM_Kill_Points[teamid]), g_Round_ArenaTDM_Kill_Points[teamid] + 1);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setArenaTDMPoints(teamid, newpoints) {
	if(TEAM_TWO >= teamid >= TEAM_ONE) {
		new oldpoints = g_Round_ArenaTDM_Kill_Points[teamid];
		g_Round_ArenaTDM_Kill_Points[teamid] = newpoints;
		CallLocalFunction("OnTDMTeamPointsChange", "ddd", teamid, newpoints, oldpoints);
		return 1;
	}	
	return 0;
}
//------------------------------------------------------------------------------
getOneOnOneMarkersStatus() return _:g_Round_OneOnOne_Markers;
setOneOnOneMarkersStatus(bool:enable) g_Round_OneOnOne_Markers = enable;