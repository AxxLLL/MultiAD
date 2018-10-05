/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define getWeaponFlag(%1)				g_Round_Weapons[%1][WEAPON_FLAG]
//==============================================================================
#define W_NON							1
#define W_ALLOWED						2
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
enum E_WEAPONS_INFO {WEAPON_ID, WEAPON_SLOT, WEAPON_FLAG, /*WEAPON_NAME[8],*/ WEAPON_TABS[6]}
new const g_Round_Weapons[][E_WEAPONS_INFO] = {
	{0, 	0, 		W_ALLOWED, 			/*!"Piesc", 				*/"\t"},		{1, 	0, 		W_ALLOWED, 			/*!"Kastet", 				*/"\t\t"},			{2, 	1, 		W_ALLOWED, 			/*!"Kij golfowy", 			*/"\t\t"},
	{3, 	1, 		W_ALLOWED, 			/*!"Palka policyjna", 		*/"\t\t"},		{4, 	1, 		W_ALLOWED, 			/*!"Noz", 					*/"\t\t\t"},		{5, 	1, 		W_ALLOWED, 			/*!"Kij Baseballowy", 		*/"\t\t"},
	{6, 	1, 		W_ALLOWED, 			/*!"Szpadel", 				*/"\t\t\t"},	{7, 	1, 		W_ALLOWED,	 		/*!"Kij bilardowy", 		*/"\t\t"},			{8, 	1, 		W_NON,	 			/*!"Katana", 				*/"\t\t"},
	{9, 	1, 		W_ALLOWED,	 		/*!"Pila mechaniczna",		*/"\t\t"},		{10, 	10,		W_ALLOWED,	 		/*!"Dildo 1", 				*/"\t\t\t"},		{11, 	10, 	W_ALLOWED,	 		/*!"Dildo 2", 				*/"\t\t\t"},
	{12, 	10, 	W_ALLOWED,	 		/*!"Dildo 3", 				*/"\t\t"},		{13, 	10, 	W_ALLOWED,	 		/*!"Dildo 4", 				*/"\t\t"},			{14, 	10, 	W_ALLOWED,	 		/*!"Kwiaty", 				*/"\t\t"},
	{15, 	10, 	W_ALLOWED,	 		/*!"Laska", 				*/"\t\t\t"},	{16, 	8, 		W_ALLOWED,	 		/*!"Granat", 				*/"\t\t"},			{17, 	8, 		W_NON, 				/*!"Gaz lzawiacy", 			*/"\t"},
	{18, 	8, 		W_NON,	 			/*!"Koktail Molotova", 		*/"\t"},		{19, 	-1, 	W_NON,	 			/*!"NaN", 					*/"\t"},			{20, 	-1, 	W_NON, 				/*!"NaN", 					*/"\t"},
	{21, 	-1, 	W_NON, 				/*!"NaN", 					*/"\t"},		{22, 	2, 		W_ALLOWED, 			/*!"Pistolet 9mm", 			*/"\t\t\t"},		{23, 	2, 		W_ALLOWED, 			/*!"Pistolet 9mm (+tlumik)",*/"\t\t"},
	{24, 	2, 		W_ALLOWED, 			/*!"Desert Eagle", 			*/"\t\t"},		{25, 	3, 		W_ALLOWED, 			/*!"Shotgun", 				*/"\t\t"},			{26, 	3, 		W_ALLOWED, 			/*!"Sawnoff Shotgun", 		*/"\t"},
	{27, 	3, 		W_ALLOWED, 			/*!"Combat Shotgun", 		*/"\t"},		{28, 	4, 		W_ALLOWED, 			/*!"Micro SMG (Uzi)", 		*/"\t\t\t"},		{29, 	4, 		W_ALLOWED, 			/*!"MP5", 					*/"\t\t\t"},
	{30, 	5, 		W_ALLOWED, 			/*!"AK-47", 				*/"\t\t\t"},	{31, 	5, 		W_ALLOWED, 			/*!"M4", 					*/"\t\t\t"},		{32,	4, 		W_ALLOWED, 			/*!"Tec-9", 				*/"\t\t\t"},
	{33, 	6, 		W_ALLOWED, 			/*!"Strzelba", 				*/"\t\t\t"},	{34, 	6,		W_ALLOWED,			/*!"Karabin Snajperski", 	*/"\t\t"},			{35, 	7, 		W_ALLOWED,			/*!"RPG", 					*/"\t"},
	{36, 	7, 		W_NON,				/*!"HS Rocket", 			*/"\t\t"},		{37, 	7, 		W_NON, 				/*!"Miotacz ognia", 		*/"\t"},			{38, 	7, 		W_ALLOWED,	 		/*!"Minigun", 				*/"\t\t"},
	{39, 	8, 		W_NON,	 			/*!"Satchel", 				*/"\t\t"},		{40, 	12, 	W_NON, 				/*!"Detonator", 			*/"\t\t"},			{41, 	9, 		W_ALLOWED, 			/*!"Puszka spray'u", 		*/"\t\t"},
	{42, 	9, 		W_ALLOWED,			/*!"Gasnica", 				*/"\t"}
};
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
isValidWeapon(weaponid) return ((sizeof(g_Round_Weapons) > weaponid >= 0 && g_Round_Weapons[weaponid][WEAPON_FLAG] != W_NON) ? 1 : 0);
//------------------------------------------------------------------------------
getWeaponSlot(weaponid) return (weaponid == 46 ? 11 : g_Round_Weapons[weaponid][WEAPON_SLOT]);
//------------------------------------------------------------------------------
countRealIndex(&fakeindex, bool:without_fist) {
	if(!without_fist) {
		switch(fakeindex) {
			case 0..7: 		fakeindex = fakeindex;
			case 8..15:		fakeindex = fakeindex + 1;
			case 16..29:	fakeindex = fakeindex + 6;
			case 30:		fakeindex = fakeindex + 8;
			case 31,32:		fakeindex = fakeindex + 10;
		}
	} else {
		switch(fakeindex) {
			case 0..6: 		fakeindex = fakeindex + 1;
			case 7..14:		fakeindex = fakeindex + 2;
			case 15..28:	fakeindex = fakeindex + 7;
			case 29:		fakeindex = fakeindex + 9;
			case 30,31:		fakeindex = fakeindex + 11; 
		}	
	}
}
//------------------------------------------------------------------------------
getWeaponSlotByID(weaponid) {
	switch(weaponid) {
		case 0, 1:			return 0;
		case 2..9: 			return 1;
		case 10..15: 		return 10;
		case 16..18, 39: 	return 8;
		case 22..24: 		return 2;
		case 25..27: 		return 3;
		case 28, 29, 32: 	return 4;
		case 30, 31:	 	return 5;
		case 33, 34:	 	return 6;
		case 35..38: 		return 7;
		case 40:			return 12;
		case 41..43:	 	return 9;
		case 44, 46:	 	return 11;
	}
	return -1;
}