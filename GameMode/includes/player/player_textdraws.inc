createPlayerTextDraws(&playerid) {

	PTD_TakeDamage[playerid] = CreatePlayerTextDraw(playerid, 231.000000, 366.000000, " "); //Jakis Nick Gracza AAAAAAAA~n~Desert Eagle | -99 HP  (100.0 HP | 100.0 AR)
	PlayerTextDrawAlignment(playerid, PTD_TakeDamage[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_TakeDamage[playerid], -16777200);
	PlayerTextDrawFont(playerid, PTD_TakeDamage[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_TakeDamage[playerid], 0.170000, 0.899999);
	PlayerTextDrawColor(playerid, PTD_TakeDamage[playerid], 255);
	PlayerTextDrawSetOutline(playerid, PTD_TakeDamage[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PTD_TakeDamage[playerid], 1);		

	PTD_GiveDamage[playerid] = CreatePlayerTextDraw(playerid, 409.000000, 366.000000, " "); //Jakis Nick Gracza AAAAAAAA~n~Desert Eagle | -99 HP  (100.0 HP | 100.0 AR)
	PlayerTextDrawAlignment(playerid, PTD_GiveDamage[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_GiveDamage[playerid], 16711696);
	PlayerTextDrawFont(playerid, PTD_GiveDamage[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_GiveDamage[playerid], 0.170000, 0.899999);
	PlayerTextDrawColor(playerid, PTD_GiveDamage[playerid], 255);
	PlayerTextDrawSetOutline(playerid, PTD_GiveDamage[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PTD_GiveDamage[playerid], 1);	
	
	//-------------------------------
	
	PTD_AimedPlayer_Nick[playerid] = CreatePlayerTextDraw(playerid, 597.000000, 426.000000, " ");
	PlayerTextDrawAlignment(playerid, PTD_AimedPlayer_Nick[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_AimedPlayer_Nick[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_AimedPlayer_Nick[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_AimedPlayer_Nick[playerid], 0.170000, 0.899999);
	PlayerTextDrawColor(playerid, PTD_AimedPlayer_Nick[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_AimedPlayer_Nick[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_AimedPlayer_Nick[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_AimedPlayer_Nick[playerid], 1);
	PlayerTextDrawUseBox(playerid, PTD_AimedPlayer_Nick[playerid], 1);
	PlayerTextDrawBoxColor(playerid, PTD_AimedPlayer_Nick[playerid], 48);
	PlayerTextDrawTextSize(playerid, PTD_AimedPlayer_Nick[playerid], 0.000000, 80.000000);	
	
	PTD_AimedPlayer_FPS[playerid] = CreatePlayerTextDraw(playerid, 582.000000, 438.000000, " ");
	PlayerTextDrawAlignment(playerid, PTD_AimedPlayer_FPS[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_AimedPlayer_FPS[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_AimedPlayer_FPS[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_AimedPlayer_FPS[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_AimedPlayer_FPS[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_AimedPlayer_FPS[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_AimedPlayer_FPS[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_AimedPlayer_FPS[playerid], 1);

	PTD_AimedPlayer_PLoss[playerid] = CreatePlayerTextDraw(playerid, 624.000000, 438.000000, " ");
	PlayerTextDrawAlignment(playerid, PTD_AimedPlayer_PLoss[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_AimedPlayer_PLoss[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_AimedPlayer_PLoss[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_AimedPlayer_PLoss[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_AimedPlayer_PLoss[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_AimedPlayer_PLoss[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_AimedPlayer_PLoss[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_AimedPlayer_PLoss[playerid], 1);	

	//-------------------------------
	
	PTD_PlayerHUD_Nick[playerid] = CreatePlayerTextDraw(playerid, 42.000000, 426.000000, " "); //Jakis Nick Gracza AAAAAA
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_Nick[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_Nick[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_Nick[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_Nick[playerid], 0.179998, 0.899999);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_Nick[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_Nick[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_Nick[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_Nick[playerid], 1);
	PlayerTextDrawUseBox(playerid, PTD_PlayerHUD_Nick[playerid], 1);
	PlayerTextDrawBoxColor(playerid, PTD_PlayerHUD_Nick[playerid], 48);
	PlayerTextDrawTextSize(playerid, PTD_PlayerHUD_Nick[playerid], 0.000000, 80.000000);
	
	PTD_PlayerHUD_Health[playerid] = CreatePlayerTextDraw(playerid, 576.000000, 68.000000, " ");
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_Health[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_Health[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_Health[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_Health[playerid], 0.200000, 0.699998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_Health[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_Health[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_Health[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_Health[playerid], 0);

	PTD_PlayerHUD_Armour[playerid] = CreatePlayerTextDraw(playerid, 576.000000, 46.000000, " ");
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_Armour[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_Armour[playerid], -1);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_Armour[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_Armour[playerid], 0.200000, 0.699998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_Armour[playerid], 255);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_Armour[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_Armour[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_Armour[playerid], 0);	
		
	PTD_PlayerHUD_Stats[playerid] = CreatePlayerTextDraw(playerid, 558.000000, 100.000000, "0~n~0~n~0"); //0~n~0~n~0
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_Stats[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_Stats[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_Stats[playerid], 0.219999, 0.999998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_Stats[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_Stats[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_Stats[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_Stats[playerid], 1);		
	
	PTD_PlayerHUD_FPS[playerid] = CreatePlayerTextDraw(playerid, 557.000000, 1.000000, " "); //999
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_FPS[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_FPS[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_FPS[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_FPS[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_FPS[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_FPS[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_FPS[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_FPS[playerid], 1);

	PTD_PlayerHUD_Ping[playerid] = CreatePlayerTextDraw(playerid, 589.000000, 1.000000, " "); //999
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_Ping[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_Ping[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_Ping[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_Ping[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_Ping[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_Ping[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_Ping[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_Ping[playerid], 1);

	PTD_PlayerHUD_PLoss[playerid] = CreatePlayerTextDraw(playerid, 629.000000, 1.000000, " "); //0.0%
	PlayerTextDrawAlignment(playerid, PTD_PlayerHUD_PLoss[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_PlayerHUD_PLoss[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_PlayerHUD_PLoss[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_PlayerHUD_PLoss[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_PlayerHUD_PLoss[playerid], -555819265);
	PlayerTextDrawSetOutline(playerid, PTD_PlayerHUD_PLoss[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_PlayerHUD_PLoss[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_PlayerHUD_PLoss[playerid], 1);	
		
	//-------------------------------
	
	PTD_Spectator_Nick[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 262.000000, " "); //~<~ Jakis_Nick_Gracza ~>~_____~n~~n~~n~_
	PlayerTextDrawAlignment(playerid, PTD_Spectator_Nick[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_Spectator_Nick[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_Spectator_Nick[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_Spectator_Nick[playerid], 0.209999, 1.000000);
	PlayerTextDrawColor(playerid, PTD_Spectator_Nick[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_Spectator_Nick[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_Spectator_Nick[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_Spectator_Nick[playerid], 1);
	PlayerTextDrawUseBox(playerid, PTD_Spectator_Nick[playerid], 1);
	PlayerTextDrawBoxColor(playerid, PTD_Spectator_Nick[playerid], 48);
	PlayerTextDrawTextSize(playerid, PTD_Spectator_Nick[playerid], 0.000000, 125.000000);	
	
	PTD_Spectator_HealthAndArmour[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 275.500000, " "); //~b~~h~~h~Zdrowie: ~w~100.0  ~b~~h~~h~Pancerz: ~w~100.0
	PlayerTextDrawAlignment(playerid, PTD_Spectator_HealthAndArmour[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_Spectator_HealthAndArmour[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_Spectator_HealthAndArmour[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_Spectator_HealthAndArmour[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_Spectator_HealthAndArmour[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_Spectator_HealthAndArmour[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_Spectator_HealthAndArmour[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_Spectator_HealthAndArmour[playerid], 1);	

	PTD_Spectator_NetStats[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 288.000000, " "); //~b~~h~~h~Ping: ~w~9999  ~b~~h~~h~|  FPS: ~w~999  ~b~~h~~h~|  P-Loss: ~w~10.0
	PlayerTextDrawAlignment(playerid, PTD_Spectator_NetStats[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_Spectator_NetStats[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_Spectator_NetStats[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_Spectator_NetStats[playerid], 0.170000, 0.889998);
	PlayerTextDrawColor(playerid, PTD_Spectator_NetStats[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_Spectator_NetStats[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_Spectator_NetStats[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_Spectator_NetStats[playerid], 1);	
	
	PTD_Spectator_Guns[playerid][0] = CreatePlayerTextDraw(playerid, 239.000000, 307.000000, " "); //~w~Jakas_Nazwa_Broni  ~b~~h~~h~(9999~b~~h~~h~)~n~2~n~3~n~4~n~5~n~6
	PlayerTextDrawBackgroundColor(playerid, PTD_Spectator_Guns[playerid][0], 255);
	PlayerTextDrawFont(playerid, PTD_Spectator_Guns[playerid][0], 1);
	PlayerTextDrawLetterSize(playerid, PTD_Spectator_Guns[playerid][0], 0.170000, 0.899998);
	PlayerTextDrawColor(playerid, PTD_Spectator_Guns[playerid][0], -1);
	PlayerTextDrawSetOutline(playerid, PTD_Spectator_Guns[playerid][0], 0);
	PlayerTextDrawSetProportional(playerid, PTD_Spectator_Guns[playerid][0], 1);
	PlayerTextDrawSetShadow(playerid, PTD_Spectator_Guns[playerid][0], 1);
	PlayerTextDrawUseBox(playerid, PTD_Spectator_Guns[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, PTD_Spectator_Guns[playerid][0], 48);
	PlayerTextDrawTextSize(playerid, PTD_Spectator_Guns[playerid][0], 319.000000, 0.000000);
		
	PTD_Spectator_Guns[playerid][1] = CreatePlayerTextDraw(playerid, 324.000000, 307.000000, " "); //~w~Jakas_Nazwa_Broni  ~b~~h~~h~(9999~b~~h~~h~)~n~2~n~3~n~4~n~5~n~6
	PlayerTextDrawBackgroundColor(playerid, PTD_Spectator_Guns[playerid][1], 255);
	PlayerTextDrawFont(playerid, PTD_Spectator_Guns[playerid][1], 1);
	PlayerTextDrawLetterSize(playerid, PTD_Spectator_Guns[playerid][1], 0.170000, 0.899998);
	PlayerTextDrawColor(playerid, PTD_Spectator_Guns[playerid][1], -1);
	PlayerTextDrawSetOutline(playerid, PTD_Spectator_Guns[playerid][1], 0);
	PlayerTextDrawSetProportional(playerid, PTD_Spectator_Guns[playerid][1], 1);
	PlayerTextDrawSetShadow(playerid, PTD_Spectator_Guns[playerid][1], 1);
	PlayerTextDrawUseBox(playerid, PTD_Spectator_Guns[playerid][1], 1);
	PlayerTextDrawBoxColor(playerid, PTD_Spectator_Guns[playerid][1], 48);
	PlayerTextDrawTextSize(playerid, PTD_Spectator_Guns[playerid][1], 403.000000, 0.000000);
	
	//-------------------------------
	
	PTD_KilledBy[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 103.000000, " "); //You have been killed by ~w~Jakis Nick Gracza AAAAAA
	PlayerTextDrawAlignment(playerid, PTD_KilledBy[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_KilledBy[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_KilledBy[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_KilledBy[playerid], 0.329998, 1.600000);
	PlayerTextDrawColor(playerid, PTD_KilledBy[playerid], 1502407935);
	PlayerTextDrawSetOutline(playerid, PTD_KilledBy[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_KilledBy[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_KilledBy[playerid], 1);

	PTD_KillPlayer[playerid] = CreatePlayerTextDraw(playerid, 320.000000, 90.000000, " "); //You killed ~w~Jakis Nick Gracza AAAAAA
	PlayerTextDrawAlignment(playerid, PTD_KillPlayer[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_KillPlayer[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_KillPlayer[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_KillPlayer[playerid], 0.309899, 1.399999);
	PlayerTextDrawColor(playerid, PTD_KillPlayer[playerid], 1502407935);
	PlayerTextDrawSetOutline(playerid, PTD_KillPlayer[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_KillPlayer[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_KillPlayer[playerid], 1);	
	
	//-------------------------------
	
	PTD_SpecBy_List[playerid] = CreatePlayerTextDraw(playerid, 31.000000, 150.000000, " ");//0xB6710AFF
	PlayerTextDrawBackgroundColor(playerid, PTD_SpecBy_List[playerid], 16);
	PlayerTextDrawFont(playerid, PTD_SpecBy_List[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_SpecBy_List[playerid], 0.230000, 1.100000);
	PlayerTextDrawColor(playerid, PTD_SpecBy_List[playerid], 126869632);
	PlayerTextDrawSetOutline(playerid, PTD_SpecBy_List[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_SpecBy_List[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_SpecBy_List[playerid], 1);
	PlayerTextDrawSetSelectable(playerid, PTD_SpecBy_List[playerid], 0);

	//-------------------------------
		
	PTD_VehicleHealth_Box[playerid] = CreatePlayerTextDraw(playerid, 549.500000, 38.000000, "_");
	PlayerTextDrawBackgroundColor(playerid, PTD_VehicleHealth_Box[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_VehicleHealth_Box[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_VehicleHealth_Box[playerid], 0.700000, 0.049999);
	PlayerTextDrawColor(playerid, PTD_VehicleHealth_Box[playerid], -1234105601);
	PlayerTextDrawSetOutline(playerid, PTD_VehicleHealth_Box[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_VehicleHealth_Box[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_VehicleHealth_Box[playerid], 1);
	PlayerTextDrawUseBox(playerid, PTD_VehicleHealth_Box[playerid], 1);
	PlayerTextDrawBoxColor(playerid, PTD_VehicleHealth_Box[playerid], -1234105601);
	PlayerTextDrawTextSize(playerid, PTD_VehicleHealth_Box[playerid], 603.500000, 54.000000); //603.5 - max 545.5 - min, 58 - dif
	PlayerTextDrawSetSelectable(playerid, PTD_VehicleHealth_Box[playerid], 0);

	PTD_VehicleHealth_Info[playerid] = CreatePlayerTextDraw(playerid, 576.000000, 35.000000, " "); //100
	PlayerTextDrawAlignment(playerid, PTD_VehicleHealth_Info[playerid], 2);
	PlayerTextDrawBackgroundColor(playerid, PTD_VehicleHealth_Info[playerid], 255);
	PlayerTextDrawFont(playerid, PTD_VehicleHealth_Info[playerid], 1);
	PlayerTextDrawLetterSize(playerid, PTD_VehicleHealth_Info[playerid], 0.200000, 0.699998);
	PlayerTextDrawColor(playerid, PTD_VehicleHealth_Info[playerid], -1);
	PlayerTextDrawSetOutline(playerid, PTD_VehicleHealth_Info[playerid], 0);
	PlayerTextDrawSetProportional(playerid, PTD_VehicleHealth_Info[playerid], 1);
	PlayerTextDrawSetShadow(playerid, PTD_VehicleHealth_Info[playerid], 0);
	PlayerTextDrawSetSelectable(playerid, PTD_VehicleHealth_Info[playerid], 0);
}

