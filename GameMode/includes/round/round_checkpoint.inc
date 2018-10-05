/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define CP_CAPTURE_DISABLED                     0
#define CP_CAPTURE_NORMAL                       1
#define CP_CAPTURE_IN_VEHICLE                   2
#define CP_CAPTURE_DEFENDER_ABORT               4
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define CP_Position(%1)					g_Round_Data[CHECKPOINT][%1]
#define getCPCaptureProgressUnit()		g_Round_CaptureCP_Unit
#define getCaptureInfoTD()				TD_Round_Capture_Info
#define getCaptureBoxTD()				TD_Round_Capture_Box
#define setCaptureStatus(%1)			g_Round_CaptureCP_CaptureStatus = %1
#define getCaptureStatus()				g_Round_CaptureCP_CaptureStatus
#define	CP_Size()						g_Round_Checkpoint_Size
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new g_Round_CaptureCP_Mode = CP_CAPTURE_NORMAL;
new Float:g_Round_CaptureCP_Unit = 1.08;	//Poziom przy 20 sek.
new g_Round_CaptureCP_Time = -1;
new bool:g_Round_CaptureCP_CaptureStatus = false;
new Float:g_Round_Checkpoint_Size = 1.5;	//Rozmiar CP w tablicy jest podzielony na "2" wzgledem rozmiaru w ustawieniach.
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
getCheckpointCaptureTime() return g_Round_CaptureCP_Time;
//------------------------------------------------------------------------------	
getCaptureModeFlag() return g_Round_CaptureCP_Mode;
//------------------------------------------------------------------------------
setRoundCheckpointCaptureTime(time) {
	if(120 >= time >= 5) {
		g_Round_CaptureCP_Time = time;
		g_Round_CaptureCP_Unit = floatdiv(floatdiv(BASE_CAPTURE_MAX_SIZE, g_Round_CaptureCP_Time), 5);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
setCheckpointCaptureMode(mode) {
	if(7 >= mode >= 0) {
		g_Round_CaptureCP_Mode = mode;
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
addCheckpointCaptureFlag(flag) {
	if(!(g_Round_CaptureCP_Mode & flag)) g_Round_CaptureCP_Mode += flag;
}
//------------------------------------------------------------------------------
removeCheckpointCaptureFlag(flag) {
	if(g_Round_CaptureCP_Mode & flag) g_Round_CaptureCP_Mode -= flag;
}
//------------------------------------------------------------------------------
setCheckpointSize(Float:size) {
	if(10.0 >= size >= 1.0) {
		g_Round_Checkpoint_Size = floatdiv(size, 2);
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
forward Float:getCheckpointSize();
Float:getCheckpointSize() {
	return floatmul(g_Round_Checkpoint_Size, 2);
}