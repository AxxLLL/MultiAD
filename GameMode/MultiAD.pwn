/*
	- v2.0.0 (RC-2)
        + (Bugfix) Kiedy wejdzie nowy gracz, na ID wczesniej uzywanego, nie moze uzyc komendy '/rsp'.
        + (Bugfix) Uzycie ktorejs z komend powoduje pokazanie info o mozliwosci uzycia '/hide' dla wszystkich graczy.
		+ (Bugfix) Druzyna obrony moze wejsc do pojazdu.
		+ (Buxfix) Pojazdy czasem znikaja w trakcie uzywania.
		    - Usunieto jeden z bledow, polegajacy na tym, ze niszczony w wyniku kolizji pojazd w rundzie, byl usuwany z serwera, jednak zapisane w tablicy gracza
		        ID nie bylo usuwane. Prowadzilo to do tego, ze dwoch graczy moglo miec zapisany ten sam pojazd, ktory wzajemnie byl usuwany.
		+ (Bugfix) Naprawiono blad powodujacy, ze gun menu moglo nie byc pokazywane po starcie rundy.
		+ (Bugfix) Po smierci w wyniku np. wybuchu helika, bedac w nim, gracz byl zamrozony i nie mogl sie zespawowac.
		+ (Bugfix) Naprawiono blad powodujacy niewyswietlanie informacji o komendach w menu pomocy.
		+ (Bugfix) Dodano sprawdzanie wartosci 'bind' serwera i wysylanie jej w raz z naglowkiem HTTP.
		+ (Nowosc) Mozliwosc wydluzenia lub zmniejszenia ilosci rund w meczu pod warunkiem, ze sa wieksze od juz rozegranych.
		+ (Nowosc) Podglad komend dla administratora oraz ich zapis do logow.
		+ (Nowosc) Informacje o smierci w logach meczu.
		+ (Nowosc) Dodanie do logow informacji z ID zapisanych meczow.
		+ (Nowosc) Zabezpieczenie przed zbyt bliskim spawnowaniem pojazdow.
		+ (Zmiana) Zmiany w wiadomosci powitalnej.

	- v2.0.1
		+ (Nowosc) Anti Fall Protect dla upadku bez smierci (automatyczny heal)
		+ (Nowosc) Alternatywne komendy w postaci '/hall', '/healall', '/armourall', '/aall'.
		+ (Nowosc) Po wyjsciu z serwera sa zapisywane statystyki gracza, az do ewentualnego powrotu w trakcie tego samego meczu lub rundy (max. 1h oczekiwania).
		+ (Nowosc) Zapis stanu gracza w trakcie rundy z mozliwoscia odnowienia po jego powrocie (+ pauza na koncu rundy).
		+ (Zmiana) Ujednolicenie wygladu textdrawow.
		+ (Zmiana) Poprawiono wyglad wiekszosci textdrawow.
		+ (Zmiana) Usunieto "Ping" z informacji textdrawowych trafionego gracza.
		+ (Zmiana) Zmieniono formatowanie nicku gracza oraz nicku trafionego gracza w textdrawowych informacjach.
		+ (Bugfix) Poprawiono blad z brakiem reakcji po smierci gracza.
		+ (Bugfix) Spawnowane w rundzie pojazdy maja taki kolor jaki ma druzyna ataku.
		
	- v2.0.2 RC-1
		+ (Nowosc) Dodano ustawienie regulujace czy ochrona "Anti Fall" ma obejmowac automatyczne dodanie po smierci w wyniku upadku.
		+ (Nowosc) Mozliwosc samodzielnego removowania sie z rundy do konca ochrony spawn protect lub first blood (komenda '/remove' lub '/rem') oraz ustawienie.
		+ (Nowosc) Dodano alternatywe komendy '/remove' - '/rm'.
		+ (Nowosc) Dodano alternatywe komendy '/gunmenu' w postaci '/gm'.
		+ (Nowosc) Powiadomienie o przelaniu pierwszej krwi (Powiadomienie na chacie).
		+ (Nowosc) Pauza na przycisk "Y" oraz mozliwosc wylaczenia w menu ustawien gracza '/me'.
		+ (Nowosc) Mozliwosc zmiany rozmiaru Checkpointa.
		+ (Zmiana) Dodano ustawienie czasu zmiany broni (cmd: '/gun').
		+ (Zmiana) Polaczono ustawienia "AutoSwap: Stan" i "AutoSwap: Zmiana skina" w jedno.
		+ (Zmiana) Dodano widoczniejsze powiadomienie o oczekiwaniu na decyzje admina po crashu gracza na koniec rundy.
		+ (Bugfix) Poprawiono bledny komunikat ("Wlaczony") zamiast "Wylaczony".
		+ (Bugfix) Naprawiono blad powodujacy, ze nie mozna bylo zakonczyc rundy w trakcie trwania ochrony "Crash Add".
	    + (Nowosc) Dodano automatyczne dodawanie po powrocie na serwer scrashowanego gracza, jesli nikt nie zostal wczesniej dodany (+ ustawienie regulujace ta opcje).
		+ (Nowosc) Dodano mozliwosc automatycznego wlaczenia pauzy zaraz po scrashowaniu gracza w rundzie.
		
    - v2.0.2 RC-2
        + (Nowosc) Dodano powiadomienie o wpisaniu niepoprawnej komendy.
		+ (Nowosc) Dodano 'Eye' do niepoprawnie wpisanych komend (domyslnie wylaczone, mozliwosc wlaczenia w menu gracza '/me').
		+ (Nowosc) Mozliwosc naprawy pojazdow w trakcie rundy (+ ograniczenie czasowe oraz opcje w menu ustawien rundy).
		+ (Nowosc) Mozliwosc usuwania nieuzywanych pojazdow w rundzie (CMD: '/destroyvehicle ["all", ID modelu lub nazwa pojazdu)').
		+ (Nowosc) Dodano powiadomienie w przypadku uzycia komendy '/car' na pojezdzie, ktory zostal wylaczony z uzytku.
		+ (Nowosc) Mozliwosc szybkiego dodania lub usuniecia obiektow w bazie 87 (CMD: '/labo [on/off]'.
		+ (Zmiana) Markery graczy na radarze, sa niewidoczne dla druzyny przeciwnej jedynie w trakcie udzialu w rundzie.
		+ (Zmiana) Checkpointu nie mozna przejmowac w trakcie trwania ochrony 'Spawn Protect'.
		+ (Zmiana) Nieco zawyzono rozmiary checkpointa.
		+ (Zmiana) Powiadomienie o trwajacej ochronie Spawn Protect jest umieszczone w widoczniejszym miejscu.
		+ (Bugfix) Ustawienia 'Spawn Protect' i 'Checkpoint" mozna bylo edytowac w trakcie trwania rundy.
		+ (Bugfix) Wyrownano box textdrawu powiadomienia o rundzie z box'em textdrawu czasu rundy.
		+ (Bugfix) Niektore opisy komend w menu pomocy nie byly wyswietlane lub nie mozna bylo ich wlaczyc.
		
	- v2.0.2 RC-3
	    + (Nowosc) Dodano mozliwosc uzywania komendy '/fv' dla administracji (Parametr: ID gracza lub "all" | Min. lvl. admina: Admin).
	    + (Nowosc) Dodano mozliwosc zmiany czasu Spawn Protect na arenach ('/cfg -> Ustawienia Rundy -> Spawn Protect').
	    + (Nowosc) Dodano alternatywe komendy '/alog' w postaci '/login'.
	
	- v2.0.3 RC-1
		- PRE-1
		    + (Nowosc) Mozliwosc zapisu uzywanych broni.
		    + (Nowosc) Dodatkowy tryb aren TDM.
		    + (Nowosc) Zapis ustawien graczy na serwerze.
			+ (Nowosc) Lista obserwujacych (Mozliwosc wylaczenia w menu '/me').
			+ (Nowosc) Anty Macro.
			+ (Zmiana) Przeniesiono HP pojazdu do textdrawu nad paskiem armora.
		- PRE-2
		    + (Nowosc) Dodano szczegolowe ustawienia AntyMacro.
		    + (Zmiana) Poprawiono zapis ustawien broni i pojazdow.
			+ (Zmiana) Usunieto parametr czasu z komendy '/kick', dzieki czemu gamemod dziala z wersjami od 0.3z R-1.
			+ (Zmiana) Usunieto komende '/ub', dzieki czemu gamemod dziala z wersjami od 0.3z R-1.
		    + (Zmiana) Zmieniono wyglad texdtawu meczowego (na koncu).
		- PRE-3
		    + (Zmiana) Calkowicie zmieniono sposob wysylu danych na serwer HTTP (dostosowanie pod JSON).
		    + (Nowosc) Na arenach podczas gry 1 vs 1 widac markery przeciwnikow w okreskonym odstepie czasu.
		    
        - v2.0.3 R-1
        - v2.0.3 R-2
            + (Bugfix) Poprawiono blad powodujacy, ze wyniki meczow gdzie chociaz jeden z graczy mial w nicku kwadradowy nawias ('[' lub ']') byly odrzucane przez serwer.
        - v2.0.3 R-3
            + (Nowosc) Dodano 'podpowiedzi' do komendy '/match' w sytuacji, kiedy gracz wpisywal ta komende podczas trwajacego meczu.
            + (Nowosc) Dodano opis komendy '/rounds' do menu pomocy dla head admina.
            + (Zmiana) Usunieto ograniczenie na nieparzysta ilosc rund w meczu.
        - v2.0.3 R-4
            + (Bugfix) Poprawiono niewyswietlajacy siê opis '/fixvehicle' w menu spisu komend administratora.
		    + (Bugfix) Poprawiono blad powodujacy, ze zakonczenie specowania komenda, badz przez wyjscie z serwera nie bylo odnotowywane na liscie obserwatorow, obserwowanego gracza.
		    + (Nowosc) Mozliwosc wylaczenia testu 'NetCheck' dla poszczegolnych graczy (/netcheck | Min A-LvL: Admin).
		    + (Nowosc) Mozliwosc sprawdzenia statusu testu 'NetCheck' dla poszczegolnych graczy (/mynetcheck).
        - v2.0.3 R-5
			+ (Nowosc) Dodano komende '/sethp' do ustawienia zadanej ilosci zdrowia wybranemu graczu.
			+ (Nowosc) Dodano komende '/setarmour' do ustawienia zadanej ilosci pancerza wybranemu graczu.
		    
	- v2.0.4
	    + (Nowosc) Nowy parametr w komendach umozliwiajacy wykonanie akcji na konkretnej druzynie.
	    + (Nowosc) Zmieniono makrodefinicje 'MAX_PLAYERS' w petli 'forplayers' na funkcje 'GetPlayerPoolSize'.
	    + (Nowosc) Dodano powiadomienia o mozliwych powodach bledow przy ustawianiu nazw druzyny, przez komende '/startmatch'.
	    + (Nowosc) Dodano mozliwosc zmiany kolorow druzyn (z gory zdefiniowane).
		+ (Nowosc) Mozliwosc przywrocenia niedokonczonego meczu (przerwanego np. w wyniku crasha serwera) przez komende '/restorematch'.
        + (Zmiana) Zmieniono system nazywania druzyn w komendzie '/startmatch'. W przypadku ustawiania obydwu nazw, nie jest sprawdzana wczesniej istniejaca nazwa druzyn.
		+ (Zmiana) Przywrocono komende '/unban'.
	    + (Zmiana) Przywrocono parametr czasu do komendy '/kick'.
	    + (Zmiana) Zmieniono format parametrow komend w menu pomocy w dziale komendy. Komendy zawarte w nawiasach kwadratowych, sa obowiazkowe. Komendy zawarte w nawiasach ostrych, sa opcjonalne.
		+ (BUGFIX - WA¯NE!) Usuniêto b³¹d powoduj¹cy crash serwera w przypadku, kiedy na serwer wchodzi³y osoby otrzymuj¹ce ID przekraczaj¹ce limit kompilacji.
		+ (Bugfix) Naprawiono b³¹d powoduj¹cy uciêcie ostatniej litery w nazwie dru¿yny ustawianej przy pomocy komendy '/start'.
        + (Zmiana) Zwiêkszono czu³oœæ anty slide buga.
        
        +/- (Nowosc) Zapis graj¹cych w meczu osób w celu ich póŸniejszego dodania do listy na koniec meczu, nawet gdy nie ma ich ju¿ na serwerze.
        
		- (Nowosc) Tryb "Demo" aren i baz.
		- (Nowosc) Komunikat podczas startu meczu i ostatniej rundy w przypadku braku wlaczonej opcji wysylania wynikow na serwer.
		- (Nowosc) Logi zakonczonego meczu.
		- (Bugfix) Nieznikajace ikonki smierci z radaru.
		- (Bigfix) Nieznikajace powiadomienie o byciu specowanym.
		
		UWAGA! Trzeba zmienic wyrazenie regularne w przyjeciu danych na serwerze WWW. Dodano parametr ilosci rozegranych przez gracza rund.
		
	Na nastepna wersje:


*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include <a_samp>
#include <a_http>
#include <zcmd>
#include <colors>
#include <a_func>
#include <sscanf2>
#include <a_data>
new DO_USUNIECIA_GLITCH_DEBUG[25];
//==============================================================================
//#pragma dynamic 32768
//==============================================================================
#define _TESTY                                  0
#define TEST_NEVER_ENDING_ROUND                 0
#define SHORT_ROUND                             0
#define DEBUG_HTTP_MODULES                   	0
#define DISABLE_HTTP_MODULE                   	0
//==============================================================================
#define MAX_GRACZY                				30
#define MAX_WEAPONS_SET                         12
#define DEFAULT_LANGUAGE            			LANG_PL
#define ROUND_COUNTDOWN_TIME                    5
#define CAR_SPAWN_DIS                           50.0
//------------------------------------------------------------------------------
#define _VERSION        						"2.0.4" 
#define INT_VERSION                             20004 //G.MM.SS
#define LAST_UPDATE    							"29/12/2015"
#define GM_NAME                     			"Multi A/D (v"_VERSION")"
#define GM_BREAK                    			"Lobby"
//==============================================================================
#define HTTP_ADDRESS                       	   	"mad.highskill.eu"
#define HTTP_MATCH_RESULTS                 	   	HTTP_ADDRESS"/match.php"
#define HTTP_SERVER_DATA                   	 	HTTP_ADDRESS"/server.php"
//==============================================================================
#define ALVL_NON                    			0
#define ALVL_JUNIOR_ADMIN           			1
#define ALVL_ADMIN                 				2
#define ALVL_HEAD_ADMIN            	 			3
//==============================================================================
/*
	Ponizsze wartosci nie moga byc takie same, poniewaz w kodzie sa jednoczesnie uzywane
	jako indeksy przy korzystaniu z np. instrukcji 'switch'.
*/
#define ANTI_MACRO_MAX_AVAILABLE_INPUTS    				10
#define ANTI_MACRO_MAX_AVAILABLE_CRITICAL_INPUTS      	14
#define ANTI_MACRO_MAX_WARNINGS                        	3
//==============================================================================
#define TEAM_NON								-1
#define TEAM_ONE								0
#define TEAM_TWO								1
#define TEAM_REF								2
//------------------------------------------------------------------------------
#define DEFAULT_TEAM_ONE_SKINID     			97
#define DEFAULT_TEAM_TWO_SKINID     			164
#define DEFAULT_TEAM_REF_SKINID     			187
//------------------------------------------------------------------------------
#define COLOR_STATUS_ACTIVE						0
#define COLOR_STATUS_INACTIVE					1
#define COLOR_STATUS_DEATH						2
//==============================================================================
#define ROUND_TYPE_ARENA						0
#define ROUND_TYPE_BASE							1
//==============================================================================
#define PLAYER_STATUS_NON						0
#define PLAYER_STATUS_REQUEST_CLASS				1
#define PLAYER_STATUS_LOBBY						2
#define PLAYER_STATUS_STARTING_CAMERA			3
#define PLAYER_STATUS_IN_ROUND					4
#define PLAYER_STATUS_LOBBY_TDM                 5
#define PLAYER_STATUS_SPECTATE                  6
#define PLAYER_STATUS_DEMO                      7
//==============================================================================
#define ROUND_STATE_LOBBY                       0
#define ROUND_STATE_STARTING                    1
#define ROUND_STATE_ENDING                      2
#define ROUND_STATE_REMAIN                      3
//==============================================================================
#define END_ROUND_REASON_CMD                    0
#define END_ROUND_REASON_TIME_LEFT              1
#define END_ROUND_REASON_NO_PLAYERS             2
#define END_ROUND_REASON_CHECKPOINT             3
#define END_ROUND_REASON_NO_DEFENDERS           4
#define END_ROUND_REASON_POINTS_LIMIT           5
//==============================================================================
#define WIN_REASON_DEFEND_BASE					0
#define WIN_REASON_TAKEOVER_BASE				1
#define WIN_REASON_PLAYER_ADVANTAGE				2
#define WIN_REASON_HEALTH_ADVANTAGE				3
#define WIN_REASON_ENEMY_DEFEAT					4
#define WIN_REASON_NO_DEFENDERS                 5
#define WIN_REASON_POINTS_LIMIT                 6
//==============================================================================
#define AUTOSWAP_NO                            	0
#define AUTOSWAP_ONLY_TEAM                      1
#define AUTOSWAP_TEAM_AND_SKIN                  2
//==============================================================================
#define WIN_HEALH_ADVANTAGE                     0
#define WIN_PLAYERS_ADVANTAGE                   1
//==============================================================================
#define VW_RQEUEST_CLASS            			0
#define VW_LOBBY		            			1
#define VW_ROUND                                2
#define VW_LOBBY_ARENADM	               		3
#define VW_DEMO_ARENA_START                     100000
#define VW_DEMO_ARENA_LIMIT                     900000
//==============================================================================
#define PROTECTOR_CHECK_PING					0
#define PROTECTOR_CHECK_FPS						1
#define PROTECTOR_CHECK_PLOSS					2
//------------------------------------------------------------------------------
#define PROTECTOR_SEND_MESSAGE					0
#define PROTECTOR_KICK_PLAYER					1
//==============================================================================
#define	GLITCH_SLIDE_BUG						0
#define	GLITCH_FAST_SHOOT						1
#define	GLITCH_CROUCH_BUG						2
#define GLITCH_ANTI_MACRO                       3
//==============================================================================
#define PARAM_TYPE_INVALID 						-1
#define PARAM_TYPE_PLAYER_ID    				0
#define PARAM_TYPE_ALL         					1
#define PARAM_TYPE_TEAM_ID      				2
//==============================================================================
#define DIR_GENERAL 							"MultiAD"
#define DIR_LOGS                    			DIR_GENERAL"/Logs"
#define DIR_LOGS_MATCH                 			DIR_LOGS"/Match"
#define DIR_PLAYERS                             DIR_GENERAL"/Players"
//------------------------------------------------------------------------------
#define DB_PATCH                                DIR_GENERAL"/multiad.db"
//------------------------------------------------------------------------------
#define FILE_REQUEST                			DIR_GENERAL"/request.ini"
#define FILE_LOBBY                				DIR_GENERAL"/lobby.ini"
#define FILE_ADMIN                				DIR_GENERAL"/admin.cfg"
#define FILE_LOBBY_ARENADM                      DIR_GENERAL"/lobby_arenadm.ini"
#define FILE_VEHICLES                           DIR_GENERAL"/vehicles.ini"
#define FILE_WEAPON_SET                         DIR_GENERAL"/weaponset.ini"
#define FILE_WEAPONS	                        DIR_GENERAL"/weapons.ini"
#define FILE_STATIC_WEAPONS	                    DIR_GENERAL"/sweapons.ini"
#define FILE_LOG_ERROR              			DIR_LOGS"/error.txt"
#define FILE_LOG_SETTINGS           			DIR_GENERAL"/settings.cfg"
#define FILE_LOG_ROUND_START_ERROR              DIR_LOGS"/rounderror.txt"
#define FILE_MATCH_TEMP              			DIR_LOGS"/mtemp.temp"
#define FILE_MATCH_HTTP_LINKS                   DIR_GENERAL"/matchids.txt"
//==============================================================================
#if defined forplayers
	#undef forplayers
#endif
#define forplayers(%1) 							for(new %1, pool_size = MAX_PLAYERS; %1 <= pool_size; %1 ++) if(IsPlayerConnected(%1))
//------------------------------------------------------------------------------
#define KickEx(%1)                              SetPVarInt(%1, PV_KICK, 1), SetTimerEx("Timer_KickPlayer", 100, 0, "d", %1)
#define isPlayerKicked(%1)                      GetPVarInt(%1, PV_KICK)
#define getPlayerRCONLoginStatus(%1)            GetPVarInt(%1, PV_RCON_LOGGED_STATUS)
#define setPlayerRCONLoginStatus(%1)            SetPVarInt(%1, PV_RCON_LOGGED_STATUS, 1)
#define getLastUpdateTime(%1)                   (NetStats_GetConnectedTime(%1) - g_Player_LastUpdate[%1])
//==============================================================================
#define PV_HELP_BACK_VAR           				"PV_HelpVar_Back"
#define PV_HELP_CONFIRM_VAR                     "PV_HelpVar_Confirm"
#define PV_HELP_VAR_1               			"PV_HelpVar_1"
#define PV_HELP_VAR_2               			"PV_HelpVar_2"
#define PV_HELP_VAR_3               			"PV_HelpVar_3"
#define PV_HELP_VAR_4                           "PV_HelpVar_4"
#define PV_HELP_VAR_5                           "PV_HelpVar_5"
//------------------------------------------------------------------------------
#define PV_PREMADE_CREATE_MODE                  "PV_Premade_CreateMode"
#define PV_PREMADE_WEAPON_1                     "PV_Premade_Weapon_1"
#define PV_PREMADE_WEAPON_2                     "PV_Premade_Weapon_2"
#define PV_PREMADE_AMMO_1                       "PV_Premade_Ammo_1"
#define PV_PREMADE_AMMO_2                       "PV_Premade_Ammo_2"
#define PV_PREMADE_PLAYERS              		"PV_Premade_Players"
//------------------------------------------------------------------------------
#define PV_LAST_ROUND_SHOW             			"PV_LastRoundInfo"
#define PV_LAST_MATCH_SHOW             			"PV_LastMatchInfo"
#define PV_KICK                                 "PV_Kicked"
#define PV_RCON_LOGGED_STATUS                   "PV_RCONLogged"
#define PV_CADD_ID                              "PV_cAdd_ID"
//==============================================================================
#define DIALOG_BACK                             0
#define DIALOG_CONFIRM                          1
#define DIALOG_VALUE                            2
#define DIALOG_F_VALUE                          3
//------------------------------------------------------------------------------
#define DIALOG_TEAM_PASSWORD                    5
#define DIALOG_SWITCH_TEAM_MENU            		6
#define DIALOG_ROUND_VEHICLES_TYPES             7
#define DIALOG_ROUND_VEHICLES_NAMES             8
#define DIALOG_WEAPON_SET_SELECT_MENU           9
#define DIALOG_WEAPON_FREECHOOSE_SELECT_MENU    10
#define DIALOG_MATCH_ROUNDS                     11
#define DIALOG_MATCH_ROUNDS_DELETE              12
#define DIALOG_LOBBY_VEHICLES_TYPES             13
#define DIALOG_LOBBY_VEHICLES_NAMES             14
#define DIALOG_PLAYER_SETTINGS                  15
#define DIALOG_SETTINGS                         16
#define DIALOG_SETTINGS_SUBMENU                 17
#define DIALOG_TEAM_SETTINGS_1                  18
#define DIALOG_TEAM_SETTINGS_2                  19
#define DIALOG_TEAM_SETTINGS_SKIN               20
#define DIALOG_TEAM_SETTINGS_NAME               21
#define DIALOG_TEAM_SETTINGS_PASSWORD           22
#define DIALOG_ROUND_SETTINGS_1                 23
#define DIALOG_ANTYGLITCH_SETTINGS              24
#define DIALOG_MESSAGES_SETTINGS                25
#define DIALOG_PROTECTOR_SETTINGS               26
#define DIALOG_LOBBY_SETTINGS                   27
#define DIALOG_LOBBY_VEHICLE_SETTINGS           28
#define DIALOG_LOBBY_VEHICLE_SUBMENU            29
#define DIALOG_LOBBY_WEAPONS_MENU               30
#define DIALOG_ROUND_VEHICLE_SETTINGS           31
#define DIALOG_ROUND_VEHICLE_SUBMENU            32
#define DIALOG_ROUND_WEAPON_MENU                33
#define DIALOG_ROUND_CONST_WEAPONS_MENU         34
#define DIALOG_ROUND_CONST_WEAPONS_SUBMENU      35
#define DIALOG_ROUND_CONST_WEAPONS_LIST         36
#define DIALOG_ROUND_FREE_WEAPONS_MENU   	   	37
#define DIALOG_ROUND_FREE_WEAPONS_SUBMENU       38
#define DIALOG_ROUND_PREMADED_WEAPONS_MENU      39
#define DIALOG_ROUND_PREMADED_WEAPONS_SUBMENU   40
#define DIALOG_ROUND_PERMADED_WEAPONS_LIST      41
#define DIALOG_ADMIN_PASSWORDS_MENU		      	42
#define DIALOG_ADMIN_PASSWORDS_SET		      	43
#define DIALOG_SCOREBOARD_MENU                  44
#define DIALOG_HTTP_SETTINGS                    45
#define DIALOG_HELP                             46
#define DIALOG_HELP_CMDS                        47
#define DIALOG_HELP_CMDS_LIST                   48
#define DIALOG_CRASH_ADD_LIST                   49
#define DIALOG_CRASH_ADD_PLAYER_INFO            50
#define DIALOG_ROUND_C_ADD_REASONS_SETTINGS     51
#define DIALOG_ANTYGLITCH_PUNISHMENT_SETTINGS   52
#define DIALOG_ROUND_SPAWNPROTECT_SETTINGS      53
#define DIALOG_ROUND_CHECKPOINT_SETTINGS      	54
#define DIALOG_ROUND_C_ADD_SETTINGS             55
#define DIALOG_OLD_ROUND_WEAPONS                56
#define DIALOG_ANTYGLITCH_ANTYMACRO_SETTINGS    57
#define DIALOG_MATCH_RESTORE_INFO               58
#define DIALOG_TEAM_SETTINGS_COLOR              59
#define DIALOG_TEAM_SETTINGS_COLOR_SWAP         60
//==============================================================================
#define ICON_ROUND_FLAG                         0
#define ICON_ROUND_SPAWN                        1
#define ICON_ROUND_BOATS                        2
#define ICON_ROUND_HELP                         3
#define ICON_DEATH_START                        10
//==============================================================================
#define ZONE_COLOR          					0xC2F72450
//==============================================================================
#define COLOR_DIALOG_HEAD           			"{078FE0}"
#define COLOR_DIALOG_BODY           			"{68BEFD}"
#define COLOR_DIALOG_COUNT						"{DDF4FF}"
//------------------------------------------------------------------------------
#define COLOR_INFO_1                			0xEC9E0FFF
#define COLOR_INFO_2                			0xFEDF96FF
#define TEXT_INFO_1                 			"{EC9E0F}"
#define TEXT_INFO_2                 			"{FEDF96}"
//------------------------------------------------------------------------------
#define COLOR_WEAPON_INFO_1                     0xEC9E0FFF
#define TEXT_WEAPON_INFO_1                      "{EC9E0F}"
#define COLOR_WEAPON_INFO_2                     0xFEDF96FF
#define TEXT_WEAPON_INFO_2                      "{FEDF96}"
//------------------------------------------------------------------------------
#define COLOR_SPAWN_PROTECT_INFO_1              0xEC9E0FFF
#define TEXT_SPAWN_PROTECT_INFO_1               "{EC9E0F}"
#define COLOR_SPAWN_PROTECT_INFO_2              0xFEDF96FF
#define TEXT_SPAWN_PROTECT_INFO_2               "{FEDF96}"
//------------------------------------------------------------------------------
#define COLOR_ADD_REMOVE_INFO_1             	0xEC9E0FFF
#define TEXT_ADD_REMOVE_INFO_1               	"{EC9E0F}"
#define COLOR_ADD_REMOVE_INFO_2              	0xFEDF96FF
#define TEXT_ADD_REMOVE_INFO_2               	"{FEDF96}"
//------------------------------------------------------------------------------
#define COLOR_CMD_ERROR                         0xFDEAAAFF
//------------------------------------------------------------------------------
#define COLOR_CONNECT_1                			0xEC9E0FFF
#define COLOR_CONNECT_2                			0xFEDF96FF
#define TEXT_CONNECT_1                 			"{EC9E0F}"
#define TEXT_CONNECT_2                 			"{FEDF96}"
//==============================================================================
#if defined MAX_GRACZY && MAX_GRACZY > 0 && MAX_GRACZY != MAX_PLAYERS
	#undef MAX_PLAYERS
	#define MAX_PLAYERS MAX_GRACZY
#endif
//==============================================================================
#define CONSOLE_MESSAGE_NEW_CONFIG_FILE			1
#define CONSOLE_MESSAGE_CONFIG_ERROR			2
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
main() {

}
//------------------------------------------------------------------------------
forward Timer_Starting(starttimerid);
forward Timer_OneSecond();
forward Timer_TwoHundredMSeconds();
forward Timer_Round_OneSecond();
forward Timer_FiveSeconds();
forward Timer_OneHour();
//------------------------------------------------------------------------------
forward Timer_KickPlayer(playerid);
forward Timer_RCONLoginInfo();
//------------------------------------------------------------------------------
forward Float:circleVariation(Float:from, max);
forward Float:getRoundArmour();
forward Float:getMaxPLossValue();
forward Float:getServerGravity();
forward Float:getServerNameTagDistance();
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
new DB:dbase;
//------------------------------------------------------------------------------
new g_Chat_String[145];
new g_String_512[512];
//------------------------------------------------------------------------------
new bool:g_ConDis_Info = true;
new bool:g_ConDis_ShowIP = true;
new bool:g_Server_LockedForConnections = false;
new bool:g_RCON_LoginInfo = true,
	g_RCON_LoginTimerID = -1;
new bool:g_DeathInfo_Chat = false,
	bool:g_DeathInfo_Icons = true;
//------------------------------------------------------------------------------
new bool:g_Player_PMLockStatus[MAX_PLAYERS];
new bool:g_Player_MuteStatus[MAX_PLAYERS];
new g_Player_LastUpdate[MAX_PLAYERS];
new Float:g_Player_LastPLoss[MAX_PLAYERS];
new bool:g_Player_Death_Confirm[MAX_PLAYERS];
//------------------------------------------------------------------------------
new PlayerText:PTD_KilledBy[MAX_PLAYERS],
	PlayerText:PTD_KillPlayer[MAX_PLAYERS];
new g_Player_ShowDeathMessage[MAX_PLAYERS][2];
//------------------------------------------------------------------------------
new Text:TD_VehicleHealth_Static[2],
	PlayerText:PTD_VehicleHealth_Box[MAX_PLAYERS],
	PlayerText:PTD_VehicleHealth_Info[MAX_PLAYERS];
//------------------------------------------------------------------------------
new g_Player_VehicleFixCMD_Time[MAX_PLAYERS];
//------------------------------------------------------------------------------
new g_TotalPlayers;
//------------------------------------------------------------------------------
new g_Server_Port;
new g_Server_System;
new g_Server_IP_Bind[16] = "0";
//------------------------------------------------------------------------------
enum E_FREECHOOSE_WEAPONS_INFO {bool:WEAPON_FC_ENABLE, WEAPON_FC_AMMO, WEAPON_FC_MAX_PLAYERS}
//------------------------------------------------------------------------------
new g_DeathIcons[5];
//------------------------------------------------------------------------------
new g_MilitaryBaseObjects = -1;
//------------------------------------------------------------------------------
enum E_PLAYER_STATS_DATA {KILLS, DEATHS, DAMAGE}
//------------------------------------------------------------------------------
/*
new const g_NUMBERS[30] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384,
	32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432,
	67108864, 134217728, 268435456, 536870912
};
*/
//------------------------------------------------------------------------------
enum COLOR_TYPES {COLOR_TYPE_NON, COLOR_TYPE_PURPLE, COLOR_TYPE_RED, COLOR_TYPE_BLUE, COLOR_TYPE_GREEN, COLOR_TYPE_YELLOW, COLOR_TYPE_LBLUE}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#include "includes/sql_def.inc"
#include "includes/weapons.inc"
#include "includes/vehicles.inc"
#include "includes/language.inc"
#include "includes/dialogs.inc"
#include "includes/antyglitch.inc"
#include "includes/settings/settings.inc"
#include "includes/request_class.inc"
#include "includes/Lobby/lobby.inc"
#include "includes/log_functions.inc"
#include "includes/admin.inc"
#include "includes/team/team.inc"
#include "includes/round/round.inc"
#include "includes/player/player.inc"
#include "includes/textdraws.inc"
#include "includes/protector.inc"
#include "includes/help.inc"
#include "includes/http/http.inc"
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
public OnGameModeInit() {
    //------------------
    AntyDeAMX();
    //------------------
    dbase = db_open(DB_PATCH);
    
    db_query(dbase, "CREATE TABLE IF NOT EXISTS `"D_MATCH"` (`"DM_MATCH_ID"` INT, `"DM_ROUND_LIMIT"` INT, `"DM_TEAM_1"` VARCHAR(32), `"DM_TEAM_2"` VARCHAR(32), `"DM_START_TIME"` INT);");
    db_query(dbase, "CREATE TABLE IF NOT EXISTS `"D_MATCH_ROUNDS"` (`"DMR_ROUND"` INT, `"DMR_MATCH_ID"` INT, `"DMR_MAP_ID"` INT, `"DMR_MAP_TYPE"` INT, `"DMR_TDM_MODE"` INT, `"DMR_WINNER"` INT, `"DMR_REASON"` INT, `"DMR_DEFENDER"` INT, `"DMR_ROUND_TIME"` INT);");
    db_query(dbase, "CREATE TABLE IF NOT EXISTS `"D_MATCH_PLAYERS"` (`"DMP_NICK"` VARCHAR(32), `"DMP_MATCH_ID"` INT, `"DMP_TEAM_ID"` INT, `"DMP_KILLS"` INT, `"DMP_DEATHS"` INT, `"DMP_DAMAGE"` INT, `"DMP_PLAYED_ROUNDS"` INT);");
    //------------------
 	g_Server_System = getServerSystem();
    g_Server_Port = GetServerVarAsInt("port");
    GetServerVarAsString("bind", g_Server_IP_Bind, 16);
    if(isnull(g_Server_IP_Bind) || !IsValidIP(g_Server_IP_Bind)) {
        strdel(g_Server_IP_Bind, 0, 16);
        strins(g_Server_IP_Bind, "0", 0);
    }
	//------------------
    createGlobalTextDraws();
    //------------------
    changeDefaultLanguage(DEFAULT_LANGUAGE);

 	setTeamSkin(TEAM_ONE, DEFAULT_TEAM_ONE_SKINID);
	setTeamSkin(TEAM_TWO, DEFAULT_TEAM_TWO_SKINID);
	setTeamSkin(TEAM_REF, DEFAULT_TEAM_REF_SKINID);
	
	setServerNameTagDistance(40.0);
   	setServerWorldTime(16);
	setServerWeather(0);
	setServerGravity(0.008);

    loadSettingFile();
	//------------------
	new day, month, year, hour, minute, second;
//	new string[512];
	getdate(year, month, day);
	gettime(hour, minute, second);
	getConsoleMessage(g_String_512, CONSOLE_MESSAGE_STARTING);
	printf(g_String_512, day, month, year, hour, minute, second);
	//------------------
	AddPlayerClassEx(GLOBAL_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	AddPlayerClassEx(GLOBAL_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	AddPlayerClassEx(GLOBAL_TEAM, 0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);
	//------------------
	setTeamName(TEAM_ONE, "Team_One");
	setTeamName(TEAM_TWO, "Team_Two");
	
	if(getTeamColorType(TEAM_ONE) == COLOR_TYPE_NON || getTeamColorType(TEAM_TWO) == COLOR_TYPE_NON || getTeamColorType(TEAM_REF) == COLOR_TYPE_NON) {
		setTeamColorType(TEAM_ONE, COLOR_TYPE_RED);
		setTeamColorType(TEAM_TWO, COLOR_TYPE_BLUE);
		setTeamColorType(TEAM_REF, COLOR_TYPE_PURPLE);
	}
	//------------------
	loadRequestPositions();
	loadLobbyPositions();
	loadVehicleData();
	loadWeaponSetData();
	loadWeaponData();
	loadStaticWeaponData();
	loadLobbyArenaDMPositions();
	loadAdminPasswords();
	preloadMapIDs();
	//------------------
	getConsoleMessage(g_String_512, CONSOLE_MESSAGE_LOADED_MAPS_INFO);
	printf(g_String_512, getLoadedArenas(), getLoadedBases());
	print("        ---------------------------------\n");
	//------------------
	for(new i; i < 5; i++)	SendDeathMessage(201,201,0);

	AllowInteriorWeapons(1);
	DisableInteriorEnterExits();
	EnableStuntBonusForAll(0);
    UsePlayerPedAnims();

    //------------------
    setRoundState(ROUND_STATE_LOBBY);
    setRoundCounterValue(0);
    if(getCheckpointCaptureTime() == -1) setRoundCheckpointCaptureTime(20);
	//------------------
	SetTimerEx("Timer_Starting", 0, 	0, 	"d", 0);
	SetTimerEx("Timer_Starting", 250, 	0, 	"d", 1);
	SetTimerEx("Timer_Starting", 500, 	0, 	"d", 2);
	SetTimerEx("Timer_Starting", 600,   0,  "d", 3);
	SetTimerEx("Timer_Starting", 800,   0,  "d", 4);
	//------------------
	sendCheckVersion();
	sendServerInfo();
	return 1;
}
//------------------------------------------------------------------------------
public OnGameModeExit() {
    saveAllServerSettings();
    sendServerInfo(false);
    db_close(dbase);
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerConnect(playerid) {
//    new string[144];
    DO_USUNIECIA_GLITCH_DEBUG[playerid] = false;
    if(playerid >= MAX_PLAYERS) {
	    getChatMessage(g_Chat_String, CHAT_MESSAGE_COMPILE_PLAYER_LIMIT, 0);
	    SendClientMessage(playerid, COLOR_KICK, g_Chat_String);
	    KickEx(playerid);
    } else if(g_Server_LockedForConnections) {
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_SERVER_LOCK, 3);
	    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	    KickEx(playerid);
	} else {
	    resetPlayerProtectorWarnings(playerid);
	    savePlayerName(playerid);
	    resetPlayerRoundStats(playerid);
	    glitchPlayerConnect(playerid);
	    if(g_ConDis_Info) {
			if(g_ConDis_ShowIP) {
				new ip[16];
				getChatMessage(g_Chat_String, CHAT_MESSAGE_CONNECT_DISCONNECT, 1);
		        GetPlayerIp(playerid, ip, sizeof(ip));
		        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), playerid, ip);
			} else {
			    getChatMessage(g_Chat_String, CHAT_MESSAGE_CONNECT_DISCONNECT, 0);
			    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), playerid);
			}
			SendClientMessageToAll(COLOR_CONNECT_1, g_Chat_String);
	    }

        g_Player_VehicleFixCMD_Time[playerid] = 0;
        
        setPlayerPlayedRounds(playerid, 0);
        addPlayerNetCheckFlag(playerid, ABLE_NETCHECK_ALL);
        resetPlayerOldWeaponsData(playerid);
        resetPlayerFreeChooseWeapons(playerid);
        resetPlayerWeaponSet(playerid);
	    createPlayerTextDraws(playerid);
	    setPlayerDamageInfoStatus(playerid, true);
	    setPlayerAimedInfoStatus(playerid, true);
        setPlayerKeyPauseStatus(playerid, true);
        setPlayerDontAskStatus(playerid, false);
        setPlayerSpecListStatus(playerid, true);
        
	    format(g_Chat_String, sizeof(g_Chat_String), "%s~n~~n~_", getPlayerName(playerid));
	    PlayerTextDrawSetString(playerid, PTD_PlayerHUD_Nick[playerid], g_Chat_String);
	    g_Player_PMLockStatus[playerid] = g_Player_MuteStatus[playerid] = false;
	    g_Player_ShowDeathMessage[playerid][0] = g_Player_ShowDeathMessage[playerid][1] = 0;
	    g_Player_Combo_PlayerID[playerid] = INVALID_PLAYER_ID;

	    SendClientMessage(playerid, COLOR_KICK, " ");
        getChatMessage(g_Chat_String, CHAT_MESSAGE_WELCOME, 0);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
        getChatMessage(g_Chat_String, CHAT_MESSAGE_WELCOME, 1);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
        getChatMessage(g_Chat_String, CHAT_MESSAGE_WELCOME, 2);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
        getChatMessage(g_Chat_String, CHAT_MESSAGE_WELCOME, 3);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
        getChatMessage(g_Chat_String, CHAT_MESSAGE_WELCOME, 4);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	    SendClientMessage(playerid, COLOR_KICK, " ");

	    if(!restorePlayerStatsOldData(playerid, searchForPlayerOldData(playerid, true), false) && getMatchStatus()) {
	        new DBResult:result, string[128];
			format(string, sizeof(string), "SELECT * FROM `"D_MATCH_PLAYERS"` WHERE `"DMP_NICK"`='%s' AND `"DMP_MATCH_ID"`='%d' LIMIT 1", getPlayerName(playerid), getMatchRandomKey());
			if(db_num_rows((result = db_query(dbase, string))) == 1) {
				setPlayerMatchRandomID(playerid, getMatchRandomKey());

				db_get_field_assoc(result, DMP_KILLS, string, sizeof(string)), setPlayerTotalStatPoints(playerid, KILLS, strval(string));
				db_get_field_assoc(result, DMP_DEATHS, string, sizeof(string)), setPlayerTotalStatPoints(playerid, DEATHS, strval(string));
				db_get_field_assoc(result, DMP_DAMAGE, string, sizeof(string)), setPlayerTotalStatPoints(playerid, DAMAGE, strval(string));
				db_get_field_assoc(result, DMP_PLAYED_ROUNDS, string, sizeof(string)), setPlayerPlayedRounds(playerid, strval(string));
				db_free_result(result);
			}
	    }
	    
	    loadPlayerSettings(playerid);
	    
	    if(getRoundState() == ROUND_STATE_REMAIN) {
	        new index, pName[MAX_PLAYER_NAME];
	        GetPlayerName(playerid, pName, sizeof(pName));
	        if((index = searchCrashIndexByNick(pName)) != -1) {
	            SetPVarInt(playerid, PV_CADD_ID, index);
	        }
	    }

	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerDisconnect(playerid, reason) {
    if(playerid >= MAX_PLAYERS) return 0;
	if(g_ConDis_Info) {
	    new /*string[144],*/ color[12], s_reason[16];

	    switch(reason) {
	        case 0: strins(s_reason, "Timeout/Crash", 0);
	        case 1: strins(s_reason, "Quit", 0);
	        case 2: strins(s_reason, "Kick/Ban", 0);
	    }

	    getChatMessage(g_Chat_String, CHAT_MESSAGE_CONNECT_DISCONNECT, 2);
	    getTeamColorText(getPlayerTeam(playerid), COLOR_STATUS_DEATH, color, sizeof(color));
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), color, getTeamName(getPlayerTeam(playerid)), s_reason);
	    SendClientMessageToAll(COLOR_CONNECT_1, g_Chat_String);

	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	        new Float:health, Float:armour;
	        GetPlayerHealth(playerid, health);
	        GetPlayerArmour(playerid, armour);
	        getChatMessage(g_Chat_String, CHAT_MESSAGE_CONNECT_DISCONNECT, 3);
		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, health, armour);
		    SendClientMessageToAll(COLOR_CONNECT_1, g_Chat_String);
	    }
	}

	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	    if(savePlayerRoundExitData(playerid, reason) != -1 && getCrashAutoPauseStatus()) {
	        caddStopRound(playerid);
	    }

		forplayers(i) {
			if(getPlayerStatus(i) == PLAYER_STATUS_SPECTATE && getPlayerSpecID(i) == playerid) {
				findPlayerToSpectate(i);
			}
		}
	}
	
	if(getMatchStatus()) savePlayerMatchData(playerid);

    savePlayerSettings(playerid);
    setPlayerFallDeathStatus(playerid, false);
    saveExitPlayerData(playerid, reason);
    setPlayerMatchRandomID(playerid, -1);
    resetPlayerTotalStats(playerid);
    destroyPlayerDamageObject(playerid);
    stopSpectate(playerid);
    stopDemoForPlayer(playerid, false);
    setPlayerTeam(playerid, TEAM_NON, TEAM_REASON_LEFT);
    setPlayerAFKMode(playerid, false, false);
    setPlayerRepresentativeStatus(playerid, false);
    setPlayerAdminLevel(playerid, ALVL_NON);
    destroyPlayerRoundVehicle(playerid, true);
//    Delete3DTextLabel(getPlayerVehicleHealthLabel(playerid));
    hidePlayerDialog(playerid);
    resetPlayerGlitchPunishment(playerid);
    g_Player_LastUpdate[playerid] = 0;
    resetPlayerRespawnTime(playerid);
    setPlayerEyeStatus(playerid, false);
    setPlayerEyeInvCMDsStatus(playerid, false);
    
    setPlayerStatus(playerid, PLAYER_STATUS_NON);
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerRequestClass(playerid, classid) {
	if(isPlayerKicked(playerid)) return 0;
	if(setPlayerStatus(playerid, PLAYER_STATUS_REQUEST_CLASS)) {
	    setPlayerTeam(playerid, TEAM_NON, TEAM_REASON_LEFT);
        setPlayerAFKMode(playerid, false, false);
        hidePlayerDialog(playerid);

  		SetPlayerVirtualWorld(playerid, VW_RQEUEST_CLASS);
  		SetPlayerInterior(playerid, getRequestClassInterior());
  		SetPlayerPos(playerid, getRequestClassPlayerPos(0), getRequestClassPlayerPos(1), getRequestClassPlayerPos(2));
  		SetPlayerFacingAngle(playerid, getRequestClassPlayerPos(3));
  		SetPlayerCameraPos(playerid, getRequestClassCameraPos(0), getRequestClassCameraPos(1), getRequestClassCameraPos(2));
  		SetPlayerCameraLookAt(playerid, getRequestClassCameraLookAt(0), getRequestClassCameraLookAt(1), getRequestClassCameraLookAt(2));

  		for(new i; i < sizeof(TD_RequestStatic); i ++) 		TextDrawShowForPlayer(playerid, TD_RequestStatic[i]);

	}

	SetSpawnInfo(playerid, GLOBAL_TEAM, getTeamSkin(classid), 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0);

	switch(classid) {
	    case 0: {
	        TextDrawShowForPlayer(playerid, TD_RequestTeamName[0]), TextDrawShowForPlayer(playerid, TD_RequestTeamInfo[0]);
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[1]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[1]);
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[2]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[2]);
	    }
	    case 1: {
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[0]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[0]);
	        TextDrawShowForPlayer(playerid, TD_RequestTeamName[1]), TextDrawShowForPlayer(playerid, TD_RequestTeamInfo[1]);
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[2]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[2]);
	    }
	    case 2: {
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[0]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[0]);
	        TextDrawHideForPlayer(playerid, TD_RequestTeamName[1]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[1]);
	        TextDrawShowForPlayer(playerid, TD_RequestTeamName[2]), TextDrawShowForPlayer(playerid, TD_RequestTeamInfo[2]);
	    }
	}
	SetPVarInt(playerid, PV_HELP_VAR_2, classid);
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerRequestSpawn(playerid) {
	new teamid;
	if(TEAM_ONE <= (teamid = GetPVarInt(playerid, PV_HELP_VAR_2)) <= TEAM_REF) {
		if(getTeamPassword(teamid) != 0 && getTeamPassword(teamid) != getPlayerTeamPassword(playerid, teamid) && !IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
			SetPVarInt(playerid, PV_HELP_VAR_3, 0);
		    showPlayerPasswordMenu(playerid);
		    return 0;
		}

		setPlayerTeam(playerid, teamid, TEAM_REASON_JOIN);

		new i;
	    for(i = 0; i < sizeof(TD_RequestStatic); i ++) 	TextDrawHideForPlayer(playerid, TD_RequestStatic[i]);
	    for(i = 0; i < 3; i ++) 						TextDrawHideForPlayer(playerid, TD_RequestTeamName[i]), TextDrawHideForPlayer(playerid, TD_RequestTeamInfo[i]);

        setPlayerFallDeathStatus(playerid, false);
	    setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
        g_Player_Death_Confirm[playerid] = false;
        
		if(getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_BASE && getGangDefendersBaseZoneID() != -1 && getDefBaseRestTime() != getDefendersBaseBackTime()) {
			showBackToBaseInfo(playerid);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
public OnPlayerSpawn(playerid) {

	if(GetPVarType(playerid, PV_CADD_ID) == PLAYER_VARTYPE_INT) {
	    new index = GetPVarInt(playerid, PV_CADD_ID);
    	if(strcmp(getPlayerName(playerid), getNameByIndex(index)) == 0 && getCrashSlotStatus(index) == false && addPlayerAfterCrash(playerid, index)) {
 			getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 5);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(getPlayerTeam(playerid)));
			SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
			c_print(g_Chat_String);
			DeletePVar(playerid, PV_CADD_ID);
    	}
	}

    destroyPlayerDamageObject(playerid);
	if(getPlayerFallDeathStatus(playerid)) {
	    setPlayerFallDeathStatus(playerid, false);
	    if(getRoundRandomKey() == getPlayerRoundKey(playerid) && addPlayerToRound(playerid, true)) {
		    getChatMessage(g_Chat_String, CHAT_MESSAGE_ANTI_FALL_PROTECT, 1);
		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
		    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
	    	return 1;
		}
	}
	
	switch(getPlayerStatus(playerid)) {
		case PLAYER_STATUS_LOBBY: spawnPlayerInLobby(playerid);
		case PLAYER_STATUS_LOBBY_TDM: teleportPlayerToLobbyArenaDM(playerid);
		case PLAYER_STATUS_DEMO: {
		
		}
	}
	
	if(g_Player_Death_Confirm[playerid]) {
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	        setPlayerInRoundPosition(playerid);
	        givePlayerGodMode(playerid);
		}
	    g_Player_Death_Confirm[playerid] = false;
	}
	
	
	return 1;
}
//------------------------------------------------------------------------------
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]) {
	if(!isnull(inputtext)) {
		for(new i; i < strlen(inputtext); i ++) {
		    if(inputtext[i] == '%') inputtext[i] = '#';
		}
	}
	
	switch(dialogid) {
	    case DIALOG_BACK: {
	        if(response)    backDialogResponse(playerid);
	        return 1;
	    }
	    case DIALOG_CONFIRM: {
	        confirmDialogResponse(playerid, response);
	        return 1;
	    }
		case DIALOG_VALUE: {
		    if(response)    showPlayerValueDialogBack(playerid, GetPVarInt(playerid, PV_VALUE_DIALOG_BACK), inputtext);
		    else            showPlayerValueDialogBack(playerid, GetPVarInt(playerid, PV_VALUE_DIALOG_BACK), "", true);
		    return 1;
		}
		case DIALOG_F_VALUE: {
		    if(response)    showPlayerFloatValueDialogBack(playerid, GetPVarInt(playerid, PV_F_VALUE_DIALOG_BACK), inputtext);
		    else            showPlayerFloatValueDialogBack(playerid, GetPVarInt(playerid, PV_F_VALUE_DIALOG_BACK), "", true);
		    return 1;
		}
	    case DIALOG_TEAM_PASSWORD: {
	        if(response)    showPlayerPasswordMenu(playerid, inputtext);
	        return 1;
	    }
	    case DIALOG_SWITCH_TEAM_MENU: {
	        if(response)    showPlayerSwitchMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_ROUND_VEHICLES_TYPES: {
	        if(response)    showPlayerRoundVehSelectMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_ROUND_VEHICLES_NAMES: {
	        if(response)    showPlayerRoundVehNames(playerid, listitem);
	        else            showPlayerRoundVehSelectMenu(playerid);
	        return 1;
	    }
	    case DIALOG_WEAPON_SET_SELECT_MENU: {
	        if(response)    showPlayerPermadedWeaponMenu(playerid, listitem);
	        else 			showSelectedWeaponsInfo(playerid);
	        return 1;
	    }
	    case DIALOG_WEAPON_FREECHOOSE_SELECT_MENU: {
	        if(response)    showPlayerFreeChooseWeaponMenu(playerid, false, listitem);
	        else            {
							showSelectedWeaponsInfo(playerid);
							givePlayerFreeChooseWeapons(playerid);
			}
	        return 1;
	    }
	    case DIALOG_MATCH_ROUNDS: {
	        if(response)    showPlayerPlayedRounds(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_MATCH_ROUNDS_DELETE: {
	        if(response)    deleteMatchRoundDataMenu(playerid, false);
	        else            showPlayerPlayedRounds(playerid);
	        return 1;
	    }
	    case DIALOG_LOBBY_VEHICLES_TYPES: {
	        if(response)    showPlayerLobbyVehSelectMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_LOBBY_VEHICLES_NAMES: {
	        if(response)    showPlayerLobbyVehNames(playerid, listitem);
	        else            showPlayerLobbyVehSelectMenu(playerid);
	        return 1;
	    }
	    case DIALOG_PLAYER_SETTINGS: {
	        if(response)    showPlayerSettingsMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_SETTINGS: {
	        if(response)    showSettingsMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_SETTINGS_SUBMENU: {
	        if(response)    sumbenuSettingsResponse(playerid, listitem);
	        else            showSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_1: {
	        if(response)    showPlayerTeamSettingsFirstMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_2: {
	        if(response)    showPlayerTeamSettingsSetMenu(playerid, listitem);
	        else            showPlayerTeamSettingsFirstMenu(playerid);
	        return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_SKIN: {
	        if(response)    setTeamNewSkin(playerid, inputtext);
	        else            showPlayerTeamSettingsSetMenu(playerid);
	        return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_NAME: {
	        if(response)    setTeamNewName(playerid, inputtext);
	        else            showPlayerTeamSettingsSetMenu(playerid);
	        return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_PASSWORD: {
	        if(response)    setTeamNewPassword(playerid, inputtext);
	        else            showPlayerTeamSettingsSetMenu(playerid);
			return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_COLOR: {
	        if(response)    setTeamNewColor(playerid, listitem);
	        else            showPlayerTeamSettingsSetMenu(playerid);
			return 1;
	    }
	    case DIALOG_TEAM_SETTINGS_COLOR_SWAP: {
	        if(response)    swapTeamColors(playerid, true);
	        else            setTeamNewColor(playerid);
			return 1;
	    }
	    case DIALOG_ROUND_SETTINGS_1: {
	        if(response)    showPlayerRoundSettingsMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_ANTYGLITCH_SETTINGS: {
	        if(response)    showPlayerAGSettingMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_MESSAGES_SETTINGS: {
	        if(response)    showPlayerMSGsSettingMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_PROTECTOR_SETTINGS: {
	        if(response)    showPlayerProtectorSettingMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_LOBBY_SETTINGS: {
	        if(response)    showPlayerLobbySettingMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_LOBBY_VEHICLE_SETTINGS: {
	        if(response)    showPlayerLobbyVehiclesMenu(playerid, listitem);
	        else            showPlayerLobbySettingMenu(playerid);
	        return 1;
	    }
	    case DIALOG_LOBBY_VEHICLE_SUBMENU: {
	        if(response)    showPlayerLobbyVehiclesSubmenu(playerid, listitem);
	        else            showPlayerLobbyVehiclesMenu(playerid);
	        return 1;
	    }
	    case DIALOG_LOBBY_WEAPONS_MENU: {
	        if(response)    showPlayerLobbyWeaponsMenu(playerid, listitem);
	        else            showPlayerLobbySettingMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_VEHICLE_SETTINGS: {
	        if(response)    showPlayerRoundVehiclesMenu(playerid, listitem);
	        else            if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showPlayerRoundSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_VEHICLE_SUBMENU: {
	        if(response)    showPlayerRoundVehiclesSubmenu(playerid, listitem);
	        else            showPlayerRoundVehiclesMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_WEAPON_MENU: {
	        if(response)    showPlayerRWeaponsSettingMenu(playerid, listitem);
	        else            if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showPlayerRoundSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_CONST_WEAPONS_MENU: {
	        if(response)    showPlayerRConstWeaponsMenu(playerid, listitem);
	        else            showPlayerRWeaponsSettingMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_CONST_WEAPONS_SUBMENU: {
	        if(response)    showPlayerRConstWeaponsSubmenu(playerid, listitem);
	        else            showPlayerRConstWeaponsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_CONST_WEAPONS_LIST: {
	        if(response)    showPlayerRConstWeaponsList(playerid, listitem);
	        else            showPlayerRConstWeaponsSubmenu(playerid);
	    }
	    case DIALOG_ROUND_FREE_WEAPONS_MENU: {
	        if(response)    showPlayerRFreeWeaponsMenu(playerid, listitem);
	        else            showPlayerRWeaponsSettingMenu(playerid);
			return 1;
	    }
	    case DIALOG_ROUND_FREE_WEAPONS_SUBMENU: {
	        if(response)    showPlayerRFreeWeaponsSubmenu(playerid, listitem);
	        else            showPlayerRFreeWeaponsMenu(playerid);
			return 1;
	    }
	    case DIALOG_ROUND_PREMADED_WEAPONS_MENU: {
	        if(response)    showPlayerRPremadedWeaponsMenu(playerid, listitem);
	        else            showPlayerRWeaponsSettingMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_PREMADED_WEAPONS_SUBMENU: {
	        if(response)    showPlayerRPremadedWeapsSubmenu(playerid, listitem);
	        else            showPlayerRPremadedWeaponsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_PERMADED_WEAPONS_LIST: {
	        if(response)    showPlayerRPermadedWeaponsList(playerid, listitem);
	        else            showPlayerRPremadedWeapsSubmenu(playerid);
	        return 1;
	    }
	    case DIALOG_ADMIN_PASSWORDS_MENU: {
	        if(response)    showPlayerAdminPasswordMenu(playerid, listitem);
	        else            showSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ADMIN_PASSWORDS_SET: {
	        if(response)    showPlayerAdminPasswordSet(playerid, inputtext);
	        else            showPlayerAdminPasswordMenu(playerid);
	        return 1;
	    }
	    case DIALOG_SCOREBOARD_MENU: {
	        if(response)    showPlayerScoreboardMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_HTTP_SETTINGS: {
	        if(response)    showPlayerHTTPSettingMenu(playerid, listitem);
	        else {
	                        if(GetPVarInt(playerid, PV_HELP_VAR_2) == 1) showSettingsMenu(playerid);
	        }
	        return 1;
	    }
	    case DIALOG_HELP: {
	        if(response)    showPlayerHelpMenu(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_HELP_CMDS: {
	        if(response)    showPlayerCMDsFirstMenu(playerid, listitem);
	        else            showPlayerHelpMenu(playerid);
	        return 1;
	    }
	    case DIALOG_HELP_CMDS_LIST: {
	        if(response)    showPlayerCMDsList(playerid, listitem);
	        else            showPlayerCMDsFirstMenu(playerid);
	        return 1;
	    }
	    case DIALOG_CRASH_ADD_LIST: {
	        if(response)    showCrashedPlayersList(playerid, listitem);
	        return 1;
	    }
	    case DIALOG_CRASH_ADD_PLAYER_INFO: {
	        if(response)    showDetailedCrasherPlayerInfo(playerid, GetPVarInt(playerid, PV_HELP_VAR_2), inputtext);
	        else {
	                        SetPVarInt(playerid, PV_HELP_VAR_1, 0);
							showCrashedPlayersList(playerid);
			}
			return 1;
	    }
	    case DIALOG_ROUND_C_ADD_REASONS_SETTINGS: {
	        if(response)    showPlayerCrashAddReasonsMenu(playerid, listitem);
	        else            showPlayerCrashAddSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ANTYGLITCH_PUNISHMENT_SETTINGS: {
	        if(response)    showPlayerAGPunishmentMenu(playerid, listitem);
	        else            showPlayerAGSettingMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_SPAWNPROTECT_SETTINGS: {
	        if(response)    showPlayerSpawnProtectMenu(playerid, listitem);
	        else            showPlayerRoundSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_CHECKPOINT_SETTINGS: {
	        if(response)    showPlayerCheckpointSettingMenu(playerid, listitem);
	        else            showPlayerRoundSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_ROUND_C_ADD_SETTINGS: {
	        if(response)    showPlayerCrashAddSettingsMenu(playerid, listitem);
	        else            showPlayerRoundSettingsMenu(playerid);
	        return 1;
	    }
	    case DIALOG_OLD_ROUND_WEAPONS: {
	        if(response)    {
	            switch(listitem) {
                 	case 0: {
                 	    resetPlayerOldWeaponsData(playerid);
                 	    showPlayerRoundWeaponSelectMenu(playerid);
                 	}
	                case 1, 2: {
	                    setPlayerDontAskStatus(playerid, listitem == 2 ? true : false);
						tryGiveOldWeapons(playerid);
	                }
	            }
	        }
	        return 1;
	    }
	    case DIALOG_ANTYGLITCH_ANTYMACRO_SETTINGS: {
	        if(response) showPlayerAntyMacroMenu(playerid, listitem);
     		else showPlayerAGSettingMenu(playerid);
     		return 1;
	    }
		case DIALOG_MATCH_RESTORE_INFO: {
		    if(response) {
		        new string[4];
		        
		        deleteRoundDataFromSQL();
		        
		        valstr(string, GetPVarInt(playerid, PV_HELP_VAR_1));
		        cmd_startmatch(playerid, string);
		    }
		    return 1;
		}
	}
	return 0;
}
//------------------------------------------------------------------------------
public OnPlayerDeath(playerid, killerid, reason) {
//	static string[64];
    PlayerTextDrawSetString(playerid, PTD_PlayerHUD_Armour[playerid], "_");
    resetPlayerGlitchPunishment(playerid);
    g_Player_Death_Confirm[playerid] = true;
    
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	    new Float:pos_x, Float:pos_y, Float:pos_z;
	    new icon_index = -1, iconid = (getPlayerTeam(playerid) == TEAM_ONE ? 59 : 58);
	    GetPlayerPos(playerid, pos_x, pos_y, pos_z);

	    if(getMatchStatus()) {
	        if(killerid != INVALID_PLAYER_ID) format(g_Chat_String, sizeof(g_Chat_String), " <Death> %s (%d) killed by %s (%d). Reason: %d", getPlayerName(playerid), playerid, getPlayerName(killerid), killerid, reason);
			else format(g_Chat_String, sizeof(g_Chat_String), " <Death> Selfkill %s (%d). Reason: %d", getPlayerName(playerid), playerid, reason);
	        toMatchLogs(g_Chat_String);
	    }

        removePlayerGodMode(playerid);
	    SendDeathMessage(killerid, playerid, reason);

		if(antiFallPlayerDeath(playerid, reason)) {
		    removePlayerFromFight(playerid, false);
		    getChatMessage(g_Chat_String, CHAT_MESSAGE_ANTI_FALL_PROTECT, 0);
		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
		    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
		} else {
			new p_team_color[12];
			addPlayerRoundStatPoints(playerid, DEATHS, 1);
			getTeamColorText(getPlayerTeam(playerid), COLOR_STATUS_ACTIVE, p_team_color);

			for(new i, time = gettime(); i < sizeof(g_DeathIcons); i ++) {
			    if(time > g_DeathIcons[i]) {
			        icon_index = i;
			        break;
			    }
			}
			if(icon_index == -1) icon_index = random(sizeof(g_DeathIcons));
            g_DeathIcons[icon_index] = gettime() + 3;

			if(killerid != INVALID_PLAYER_ID) {
			    addPlayerRoundStatPoints(killerid, KILLS, 1);
				if(g_DeathInfo_Chat) {
				    new k_team_color[12], weapon_name[32] = "NoN";
				    if(42 >= reason >= 1) GetWeaponName(reason, weapon_name, sizeof(weapon_name));
				    getTeamColorText(getPlayerTeam(killerid), COLOR_STATUS_ACTIVE, k_team_color);
                    getChatMessage(g_Chat_String, CHAT_MESSAGE_DEATH_INFO, 0);
                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, p_team_color, getPlayerName(playerid), k_team_color, getPlayerName(killerid), weapon_name);
                    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				}
			} else {
				if(g_DeathInfo_Chat) {
                    getChatMessage(g_Chat_String, CHAT_MESSAGE_DEATH_INFO, 1);
                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, p_team_color, getPlayerName(playerid));
                    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				}
			}
			
			if(getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus()) {
			    if(killerid == INVALID_PLAYER_ID) subArenaTDMPoint(getPlayerTeam(playerid));
			    else addArenaTDMPoint(getPlayerTeam(killerid));
			} else {
			    removePlayerFromFight(playerid, false);
			}

	    }
	    forplayers(i) {
	        if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && icon_index != -1) {
	            SetPlayerMapIcon(i, ICON_DEATH_START + icon_index, pos_x, pos_y, pos_z, iconid, 0, MAPICON_GLOBAL);
	        } else if(getPlayerStatus(i) == PLAYER_STATUS_SPECTATE && getPlayerSpecID(i) == playerid) {
	            startSpectate(i, INVALID_PLAYER_ID);
	        }
	    }
	}

	if(killerid != INVALID_PLAYER_ID) {
	    getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_PLAYER_KILL, 0);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(killerid));
		PlayerTextDrawSetString(playerid, PTD_KilledBy[playerid], g_Chat_String);
		PlayerTextDrawShow(playerid, PTD_KilledBy[playerid]);
		g_Player_ShowDeathMessage[playerid][0] = gettime() + 3;

	    getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_PLAYER_KILL, 1);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
		PlayerTextDrawSetString(killerid, PTD_KillPlayer[killerid], g_Chat_String);
		PlayerTextDrawShow(killerid, PTD_KillPlayer[killerid]);
		g_Player_ShowDeathMessage[killerid][1] = gettime() + 3;
	}

	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerStateChange(playerid, newstate, oldstate) {
	static oldArmedWeapon[MAX_PLAYERS];
	if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER) {
	    new vehicleid = GetPlayerVehicleID(playerid);
	    oldArmedWeapon[playerid] = GetPlayerWeapon(playerid);
	    showPlayerVehicleHealthInfo(playerid);
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && (getPlayerTeam(playerid) == getDefendingTeam() || getRoundType() == ROUND_TYPE_ARENA)) RemovePlayerFromVehicle(playerid);
	    else {
	    /*
	    	if(newstate == PLAYER_STATE_DRIVER) {
				getPlayerVehicleHealthLabel(playerid) = Create3DTextLabel(" ", 0xFFFFFFFF, 0.0, 0.0, 1000.0, 5.0, GetPlayerVirtualWorld(playerid), true);
				Attach3DTextLabelToVehicle(getPlayerVehicleHealthLabel(playerid), vehicleid, 0.0, 0.0, 1.0);
		    }
		*/
		    SetPlayerArmedWeapon(playerid, 1);
		    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		        forplayers(i) {
		            if(getPlayerSpecID(i) == playerid) {
		                PlayerSpectateVehicle(i, vehicleid);
		            }
		        }
		    }
		}
   	} else if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER) {
		SetPlayerArmedWeapon(playerid, oldArmedWeapon[playerid]);
		hidePlayerVehicleHealthInfo(playerid);
	    //if(oldstate == PLAYER_STATE_DRIVER)	Delete3DTextLabel(getPlayerVehicleHealthLabel(playerid));
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	        forplayers(i) {
	            if(getPlayerSpecID(i) == playerid) {
	                PlayerSpectatePlayer(i, playerid);
	            }
	        }
	    }
	} else if(oldstate == PLAYER_STATE_SPECTATING) {
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
			showPlayerRoundWeaponSelectMenu(playerid);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnVehicleDeath(vehicleid) {
	DestroyVehicle(vehicleid);
	forplayers(i) {
	    if(getPlayerRoundVehicleID(i) == vehicleid) {
	        destroyPlayerRoundVehicle(i, false);
	        return 1;
	    } else if(getPlayerLobbyVehicleID(i) == vehicleid) {
	        destroyPlayerLobbyVehicle(i);
	        return 1;
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, weaponid, bodypart) {
    updatePlayerAimedInfo(playerid, damagedid);
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart) {
	if(issuerid == INVALID_PLAYER_ID || (GetPlayerTeam(playerid) != GetPlayerTeam(issuerid) || GetPlayerTeam(playerid) == NO_TEAM || GetPlayerTeam(issuerid) == NO_TEAM)) {

		if(issuerid == INVALID_PLAYER_ID && getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND && antiFallProtect(playerid, weaponid)) {
		    getChatMessage(g_Chat_String, CHAT_MESSAGE_ANTI_FALL_PROTECT, 2);
		    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			return 0;
		}
		
        static Float:health, Float:armour, Float:new_health, Float:new_armour;
		new bool:take_health;

        GetPlayerHealth(playerid, health);
        GetPlayerArmour(playerid, armour);

        if(armour > 0.0 && (0 <= weaponid <= 42 || weaponid == 51)) {
            new_armour = armour - amount;
            if(new_armour < 0.0) {
                new_health = health + new_armour;
                new_armour = 0.0;
                take_health = true;
            } else {
				new_health = health;
				take_health = false;
			}
        } else {
            new_health = health - amount;
            take_health = true;
	    }
		if(new_health < 0.0 || amount >= (health + armour)) {
		    amount = health + armour;
			new_health = 0.0;
		}

	    if(issuerid != INVALID_PLAYER_ID) {
	        updatePlayerAimedInfo(issuerid, playerid);
	        updatePlayerShowDamageInfo(true, issuerid, playerid, weaponid, amount, new_health, new_armour, take_health);
	    }
	    updatePlayerShowDamageInfo(false, playerid, issuerid, weaponid, amount, new_health, new_armour, take_health);

		if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		    if(checkFirstBloodPlayer(playerid, issuerid)) {
			    getChatMessage(g_Chat_String, CHAT_MESSAGE_SPAWN_PROTECT, 0);
			    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(issuerid), getPlayerName(playerid));
			    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
		    }
            updateTeamDamageBarInfo(playerid, getPlayerTeam(playerid), amount, new_health, new_armour);

		    if(issuerid != INVALID_PLAYER_ID) {
		        addPlayerRoundStatPoints(issuerid, DAMAGE, floatround(amount));
			}
		}
	}

	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if(checkSyncKeys(newkeys, oldkeys)) {
	    if(1 >= GetPlayerWeapon(playerid) >= 0) {
			cmd_sync(playerid);
		} else {
		    if(!(7 <= GetPlayerCameraMode(playerid) <= 8)) {
//				new string[64];
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SYNC, 3);
		        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		}
	} else if(checkHelpKeys(newkeys, oldkeys)) {
	    playerCallsForHelp(playerid);
	} else if(newkeys & KEY_YES && !(oldkeys & KEY_YES) && IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN) && getPlayerKeyPauseStatus(playerid)) {
	    cmd_pause(playerid);
	}
	glitchKeyStateChange(playerid, newkeys, oldkeys);
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerUpdate(playerid) {
    g_Player_LastUpdate[playerid] = NetStats_GetConnectedTime(playerid);

	if(getPlayerStatus(playerid) == PLAYER_STATUS_SPECTATE) {
	    if(NetStats_GetConnectedTime(playerid) - getSpecButtonProtectTime(playerid) > 200) {
		    new keys, val;
		    GetPlayerKeys(playerid, val, val, keys);
		    if(keys != 0) {
		        setSpecButtonProtectTime(playerid, NetStats_GetConnectedTime(playerid));
		        g_Round_PlayerButtonProtect[playerid] = NetStats_GetConnectedTime(playerid);
				findPlayerToSpectate(playerid, keys == KEY_LEFT ? SPEC_BACKWARD : SPEC_FORWARD);
			}
		}
	} else glitchCheckPlayerAmmo(playerid);
    return 1;
}
//------------------------------------------------------------------------------
public OnPlayerText(playerid, text[]) {
//    static string[150];
    //-------------------------------
	new space_index = -1, length;
	for(new i; i < strlen(text); i ++) {
	    if(text[i] != ' ') break;
	    else space_index = i;
	}
	if(space_index != -1) {
	    strdel(text, 0, space_index + 1);
	}
	while((space_index = strfind(text, "  ")) != -1) strdel(text, space_index, space_index + 1);
	if((length = strlen(text)) > 0) {
	    if(text[length - 1] == ' ') text[length - 1] = EOS;
	}
	if(isnull(text)) return 0;
	//-------------------------------
	new sec_line[64];

	if(strlen(text) >= 70) {
	    strins(sec_line, text[69], 0);
	    text[69] = EOS;
	}
	if(strlen(text) > 1) {
		switch(text[0]) {
		    case '!': {
				new teamid;
				if((teamid = getPlayerTeam(playerid)) != TEAM_NON) {
					format(g_Chat_String, sizeof(g_Chat_String), "(Team Chat) {C0FEFE}%s{0EE2FA}: %s", getPlayerName(playerid), text[1]);
					forplayers(i) {
					    if(getPlayerTeam(i) == teamid) {
					        SendClientMessage(i, 0x0EE2FAFF, g_Chat_String);
					        if(sec_line[0] != EOS) SendClientMessage(i, 0x0EE2FAFF, sec_line);
					    }
					}
					printf("[TEAM CHAT] %s: %s", getPlayerName(playerid), text[1]);
					format(g_Chat_String, sizeof(g_Chat_String), "[TEAM CHAT] %s: %s", getPlayerName(playerid), text[1]);
					toMatchLogs(g_Chat_String);
					return 0;
				}
			}
		    case '@': {
				if(getPlayerTeam(playerid) != TEAM_REF) {
					format(g_Chat_String, sizeof(g_Chat_String), "(Ref Chat) {E9AAFD}%s [ID: %d]{B778FC}: %s", getPlayerName(playerid), playerid, text[1]);
					forplayers(i) {
					    if(getPlayerTeam(i) == TEAM_REF || i == playerid) {
					        SendClientMessage(i, 0xB778FCFF, g_Chat_String);
					        if(sec_line[0] != EOS) SendClientMessage(i, 0xB778FCFF, sec_line);
					    }
					}
					printf("[REF CHAT] %s: %s", getPlayerName(playerid), text[1]);
					format(g_Chat_String, sizeof(g_Chat_String), "[REF CHAT] %s: %s", getPlayerName(playerid), text[1]);
					toMatchLogs(g_Chat_String);
					return 0;
				}
			}
			case '#': {
				if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
					format(g_Chat_String, sizeof(g_Chat_String), "(Admin Chat) {CBFD93}%s [ID: %d]{93FE52}: %s", getPlayerName(playerid), playerid, text[1]);
					forplayers(i) {
					    if(IsAdminOrRCON(i, ALVL_JUNIOR_ADMIN)) {
					        SendClientMessage(i, 0x93FE52FF, g_Chat_String);
					        if(sec_line[0] != EOS) SendClientMessage(i, 0x93FE52FF, sec_line);
					    }
					}
					printf("[ADMIN CHAT] %s: %s", getPlayerName(playerid), text[1]);
					format(g_Chat_String, sizeof(g_Chat_String), "[ADMIN CHAT] %s: %s", getPlayerName(playerid), text[1]);
					toMatchLogs(g_Chat_String);
					return 0;
				}
			}
		}
	}

	if(g_Player_MuteStatus[playerid] || (getChatLockStatus() && (getPlayerTeam(playerid) != TEAM_REF && !IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN) && !isPlayerRepresentative(playerid)))) {
	    getChatMessage(g_Chat_String, CHAT_MESSAGE_CHATLOCK, 0);
	    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	    return 0;
	}

    new color[12];
    format(color, sizeof(color), "{%x}", GetPlayerColor(playerid));
	strdel(color, 7, 9);
	format(g_Chat_String, sizeof(g_Chat_String), "("C_WHITE"ID: %d%s) %s: "C_WHITE"%s", playerid, color, getPlayerName(playerid), text);
	SendClientMessageToAll(GetPlayerColor(playerid), g_Chat_String);
	if(sec_line[0] != EOS) SendClientMessageToAll(COLOR_WHITE, sec_line);
//	printf("[CHAT] %s: %s", getPlayerName(playerid), text);
	format(g_Chat_String, sizeof(g_Chat_String), "[CHAT] %s: %s", getPlayerName(playerid), text);
	toMatchLogs(g_Chat_String);
	return 0;
}
//------------------------------------------------------------------------------
public OnRconLoginAttempt(ip[], password[], success) {
	if(success && g_RCON_LoginInfo) {
	    if(g_RCON_LoginTimerID != -1) KillTimer(g_RCON_LoginTimerID);
	    g_RCON_LoginTimerID = SetTimer("Timer_RCONLoginInfo", 100, 0);
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerClickPlayer(playerid, clickedplayerid, source) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
	    switch(GetPVarInt(playerid, PV_HELP_VAR_1)) {
	        case 999990: {
			    new string[4];
			    valstr(string, clickedplayerid);
	            showDetailedCrasherPlayerInfo(playerid, GetPVarInt(playerid, PV_HELP_VAR_2), string);
	            SetPVarInt(playerid, PV_HELP_VAR_1, 0);
	        }
	        default: {
			    SetPVarInt(playerid, PV_HELP_VAR_1, clickedplayerid);
			    showPlayerScoreboardMenu(playerid);
	        }
	    }

	} else {
	    new string[4];
	    valstr(string, clickedplayerid);
		cmd_spec(playerid, string);
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnPlayerCommandPerformed(playerid, cmdtext[], success) {
	if(success) {
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_EYE, 0);
		format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), cmdtext);
	    forplayers(i) {
	        if(i != playerid && IsAdminOrRCON(i, ALVL_ADMIN) && getPlayerEyeStatus(i)) {
	            SendClientMessage(i, COLOR_INFO_1, g_Chat_String);
	        }
	    }
	    c_print(g_Chat_String);
	} else {
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_INVALID_COMMAND, 0);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, cmdtext);
	    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_EYE, 2);
		format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), cmdtext);
	    forplayers(i) {
	        if(i != playerid && IsAdminOrRCON(i, ALVL_ADMIN) && getPlayerEyeStatus(i) && getPlayerEyeInvCMDsStatus(i)) {
	            SendClientMessage(i, COLOR_INFO_1, g_Chat_String);
	        }
	    }
	    c_print(g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnVehicleDamageStatusUpdate(vehicleid, playerid) {
	if(playerid != INVALID_PLAYER_ID) {
	    updateRoundVehicleTime(vehicleid, playerid);
	}
	return 1;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
public OnPlayerStatusChange(playerid, newstatus, oldstatus) {

	switch(oldstatus) {
	    case PLAYER_STATUS_STARTING_CAMERA: {
	        if(newstatus != PLAYER_STATUS_LOBBY) {
	            TogglePlayerSpectating(playerid, false);
	            hidePlayerRoundStartTextdraws(playerid);
	        } else if(newstatus != PLAYER_STATUS_REQUEST_CLASS) {
	            showPlayerHud(playerid);
	            showRoundBar(playerid);
	            if(getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus()) {
	                showPlayerArenaTDMTextDraw(playerid);
	            }
	        }
	    }
	    case PLAYER_STATUS_IN_ROUND: {

	        hideZPosCheckpointInfo(playerid);

            PlayerTextDrawHide(playerid, PTD_TakeDamage[playerid]),	getPlayerTakeDamageTime(playerid) = 0;
            PlayerTextDrawHide(playerid, PTD_GiveDamage[playerid]),	getPlayerGiveDamageTime(playerid) = 0, g_Player_Combo_PlayerID[playerid] = INVALID_PLAYER_ID;

	        hideBackToBasePlayerInfo(playerid);
	        hideBackToBaseInfo(playerid);

			if(GetPlayerState(playerid) != PLAYER_STATE_WASTED) {
				TogglePlayerControllable(playerid, true);
			}

			TextDrawHideForPlayer(playerid, TD_Round_Pause);
            TextDrawHideForPlayer(playerid, TD_Round_Team_PlayersHealth[TEAM_ONE]);
            TextDrawHideForPlayer(playerid, TD_Round_Team_PlayersHealth[TEAM_TWO]);
            TextDrawHideForPlayer(playerid, TD_Round_First_Blood);
            TextDrawHideForPlayer(playerid, TD_SpawnProtect);
            
            PlayerTextDrawHide(playerid, PTD_SpecBy_List[playerid]);
            
            for(new i; i < sizeof(g_DeathIcons); i ++) RemovePlayerMapIcon(playerid, ICON_DEATH_START + i);
            
            removePlayerGodMode(playerid);
	    }
	    case PLAYER_STATUS_LOBBY: {
	        destroyPlayerLobbyVehicle(playerid);
	    }
	    case PLAYER_STATUS_LOBBY_TDM: {

	    }
	    case PLAYER_STATUS_REQUEST_CLASS: {
	        showRoundBar(playerid);
	        if(getRoundCrashAddStatus()) {
	            showCrashAddInfoForPlayer(playerid);
	        }
	    }
	    case PLAYER_STATUS_SPECTATE: {
			hidePlayerSpectatorTextDraws(playerid);
            PlayerTextDrawHide(playerid, PTD_TakeDamage[playerid]),	getPlayerTakeDamageTime(playerid) = 0;
            PlayerTextDrawHide(playerid, PTD_GiveDamage[playerid]),	getPlayerGiveDamageTime(playerid) = 0, g_Player_Combo_PlayerID[playerid] = INVALID_PLAYER_ID;
	        hideBackToBasePlayerInfo(playerid);
	        hideBackToBaseInfo(playerid);

            TextDrawHideForPlayer(playerid, TD_Spectator_Team_PlayersHealth[TEAM_ONE]);
            TextDrawHideForPlayer(playerid, TD_Spectator_Team_PlayersHealth[TEAM_TWO]);
            TextDrawHideForPlayer(playerid, TD_Round_Team_PlayersHealth[TEAM_ONE]);
            TextDrawHideForPlayer(playerid, TD_Round_Team_PlayersHealth[TEAM_TWO]);
            TextDrawHideForPlayer(playerid, TD_Round_First_Blood);
            TextDrawHideForPlayer(playerid, TD_SpawnProtect);

	    }
	}

	switch(newstatus) {
	    case PLAYER_STATUS_LOBBY: {
	        showPlayerHud(playerid);
	    }
	    case PLAYER_STATUS_STARTING_CAMERA, PLAYER_STATUS_REQUEST_CLASS: {
	        stopDemoForPlayer(playerid, false);
	    
            hideCrashAddInfoForPlayer(playerid);
	        hideRoundBar(playerid);
	        hidePlayerHud(playerid);
	        hidePlayerArenaTDMTextDraw(playerid);

            PlayerTextDrawHide(playerid, PTD_TakeDamage[playerid]),	getPlayerTakeDamageTime(playerid) = 0;
	        PlayerTextDrawHide(playerid, PTD_GiveDamage[playerid]),	getPlayerGiveDamageTime(playerid) = 0, g_Player_Combo_PlayerID[playerid] = INVALID_PLAYER_ID;

	 		if(gettime() > getPlayerAimedInfoTime(playerid) > 0) {
	            hidePlayerAimedInfo(playerid);
	            getPlayerAimedInfoTime(playerid) = 0;
			}

			if(getMatchTimerID() != -1) hidePlayerEndMatchInfo(playerid);
            if(getRoundTimerID() != -1) hidePlayerEndRoundInfo(playerid);
	    }

	    case PLAYER_STATUS_SPECTATE: {
	        showPlayerSpectatorTextDraws(playerid);
	        hidePlayerHud(playerid, true);

	        if(getPlayerTeam(playerid) == TEAM_REF && getTeamHealthInfoBarsStatus()) {
	            TextDrawShowForPlayer(playerid, TD_Spectator_Team_PlayersHealth[TEAM_ONE]);
	            TextDrawShowForPlayer(playerid, TD_Spectator_Team_PlayersHealth[TEAM_TWO]);
			} else TextDrawShowForPlayer(playerid, TD_Round_Team_PlayersHealth[getPlayerTeam(playerid)]);
			
		 	if(getFirstBloodPlayer() == INVALID_PLAYER_ID && g_SpawnProtect_Flag & SP_FIRST_BLOOD) {
		 		TextDrawShowForPlayer(playerid, TD_Round_First_Blood);
		 	}
		 	
		 	if(getSpawnProtectTime() > 0) {
		 	    TextDrawShowForPlayer(playerid, TD_SpawnProtect);
		 	}
	    }
	    case PLAYER_STATUS_IN_ROUND: {
	        stopDemoForPlayer(playerid, false);
	        g_Player_VehicleFixCMD_Time[playerid] = 0;
	        
	        if(getTeamHealthInfoBarsStatus()) {
        	    TextDrawShowForPlayer(playerid, TD_Round_Team_PlayersHealth[getPlayerTeam(playerid)]);
		 	}
		 	
		 	if(getFirstBloodPlayer() == INVALID_PLAYER_ID && g_SpawnProtect_Flag & SP_FIRST_BLOOD) {
		 		TextDrawShowForPlayer(playerid, TD_Round_First_Blood);
		 	}
		 	
		 	if(getSpawnProtectTime() > 0) {
		 	    TextDrawShowForPlayer(playerid, TD_SpawnProtect);
		 	}
		 	
           	if(getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus()) {
 				showPlayerArenaTDMTextDraw(playerid);
           	}
	    }
	}

}
//------------------------------------------------------------------------------
public OnRoundStateChange(newstate, oldstate) {
	switch(newstate) {
	    case ROUND_STATE_LOBBY: {
	        //---------------

	        for(new i; i < 2; i ++) {
				getShowDamageBarTime(i) = 0,	TextDrawHideForAll(TD_RoundBar_Damage[i]);
				getHelpIconTime(i) = 0;
	            TextDrawHideForAll(TD_Round_Team_PlayersHealth[i]);
	            TextDrawHideForAll(TD_Spectator_Team_PlayersHealth[i]);
	            TextDrawSetString(TD_RoundBar_Health[i], "0");
			}
            hideHelpIconForAll();	//Zawiera petle na wszystkich graczy!
	        hideCaptureBarForAll();
	        hideBackToBasePlayerInfoForAll();
	        hideBackToBaseInfoForAll();
			TextDrawSetString(TD_RoundBar_Base, "~w~--");
			TextDrawSetString(TD_RoundBar_Time, "--:--");

	        //---------------

	        if(getMatchStatus()) {
//	            new string[64];
	            format(g_Chat_String, sizeof(g_Chat_String), "mapname %s %d:%d %s (R: %d/%d)", getTeamName(TEAM_ONE), getTeamPoints(TEAM_ONE), getTeamPoints(TEAM_TWO), getTeamName(TEAM_TWO), getRoundCounterValue() + 1, getMatchRoundLimit());
	            SendRconCommand(g_Chat_String);
	        } else SendRconCommand("mapname "GM_NAME);
            SetGameModeText(GM_BREAK);

			//---------------

	    }
	    case ROUND_STATE_STARTING: {
//			new string[16];

			if(getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus()) {
			    format(g_Chat_String, sizeof(g_Chat_String), "A-TDM  ~w~%d", getRoundMapID());
			    TextDrawSetString(TD_RoundBar_Base, g_Chat_String);
			    
	    		format(g_Chat_String, sizeof(g_Chat_String), "~r~%s  ~w~0 : 0  ~b~%s", getTeamName(TEAM_ONE), getTeamName(TEAM_TWO));
	    		TextDrawSetString(TD_ArenaTDM_Info, g_Chat_String);
			    
			    getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_POINTS_LIMIT, 0);
			    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getArenaTDMKillLimit());
			} else {
				format(g_Chat_String, sizeof(g_Chat_String), "%s ~w~%d", oftenUsedPhrases((getRoundType() == ROUND_TYPE_ARENA ? (!getArenaTDMModeStatus() ? LANG_OUP_ARENA : LANG_OUP_ARENA_TDM) : LANG_OUP_BASE), 3), getRoundMapID());
				TextDrawSetString(TD_RoundBar_Base, g_Chat_String);
				
				format(g_Chat_String, sizeof(g_Chat_String), "%02d:%02d", floatround(floatdiv(getRoundTimeRest(), 60), floatround_floor), getRoundTimeRest() % 60);
			}
			TextDrawSetString(TD_RoundBar_Time, g_Chat_String);

			killRoundEndTimerID();
			killMatchTimerID();

			for(new i; i < 2; i ++) {
				TextDrawSetString(TD_Round_Team_PlayersHealth[i], "_");
				TextDrawSetString(TD_Spectator_Team_PlayersHealth[i], "_");
			}
		}
	    case ROUND_STATE_ENDING: {}
	    case ROUND_STATE_REMAIN: {
            spawnProtectStart();

 		 	if(getSpawnProtectTime() > 0) {
	            forplayers(i) {
	                if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
	                    TextDrawShowForPlayer(i, TD_SpawnProtect);
	                }
	            }
			}
		}
	}
}
//------------------------------------------------------------------------------
public OnPlayerTeamChange(playerid, newteam, oldteam, reason) {
	if(newteam != TEAM_NON) {
	    for(new i; i <= TEAM_REF; i ++) TextDrawHideForPlayer(playerid, TD_PlayerHUD_TeamNames[i]);
		TextDrawShowForPlayer(playerid, TD_PlayerHUD_TeamNames[newteam]);

		if(reason != TEAM_REASON_SWAP) {
		    new /*string[128],*/ color_text_active[12], color_text_inactive[12];

		    getTeamColorText(newteam, COLOR_STATUS_ACTIVE, color_text_active);
		    getTeamColorText(newteam, COLOR_STATUS_INACTIVE, color_text_inactive);

			switch(reason) {
			    case TEAM_REASON_JOIN: getChatMessage(g_Chat_String, CHAT_MESSAGE_TEAM_JOIN);
				case TEAM_REASON_SWITCH: getChatMessage(g_Chat_String, CHAT_MESSAGE_TEAM_SWITCH, 0);
				case TEAM_REASON_ADMIN_SWAP: getChatMessage(g_Chat_String, CHAT_MESSAGE_TEAM_SWITCH, 1);
			}
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, color_text_inactive, getPlayerName(playerid), color_text_active, color_text_inactive, getTeamName(newteam));
			SendClientMessageToAll(getTeamColorInt(newteam, COLOR_STATUS_ACTIVE), g_Chat_String);
			c_print(g_Chat_String);
		}


		if(getRoundState() == ROUND_STATE_REMAIN && getTeamHealthInfoBarsStatus()) {
		    if(oldteam != TEAM_NON && oldteam != TEAM_REF) {
				TextDrawHideForPlayer(playerid, TD_Round_Team_PlayersHealth[oldteam]);
       	    	TextDrawShowForPlayer(playerid, TD_Round_Team_PlayersHealth[newteam]);
			}
		}

	}
	return 1;
}
//------------------------------------------------------------------------------
public OnTeamSkinChange(teamid, newskin, oldskin) {
//	new string[32];
	format(g_Chat_String, sizeof(g_Chat_String),"%d~n~%s", newskin, (getTeamPassword(teamid) == 0 ? (oftenUsedPhrases(LANG_OUP_NO)) : (oftenUsedPhrases(LANG_OUP_YES))));
	TextDrawSetString(TD_RequestTeamInfo[teamid], g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
public OnTeamPasswordChange(teamid, newpassword, oldpassword) {
//	new string[32];
	format(g_Chat_String, sizeof(g_Chat_String),"%d~n~%s", getTeamSkin(teamid), (newpassword == 0 ? (oftenUsedPhrases(LANG_OUP_NO)) : (oftenUsedPhrases(LANG_OUP_YES))));
	TextDrawSetString(TD_RequestTeamInfo[teamid], g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
public OnDefaultLanguageChange(newlanguage, oldlanguage) {
	switch(newlanguage) {
	    case LANG_PL: {
	        setTeamName(TEAM_REF, "Arbiter");
	        TextDrawSetString(TD_RequestStatic[2], "Wybierz druzyne");
	        TextDrawSetString(TD_RequestStatic[3], "Skin ID:_~n~Haslo:");
	        TextDrawSetString(TD_Round_BTB_Player_Info, "Poza baza");
	        TextDrawSetString(TD_Round_Pause, "~n~Runda zostala zatrzymana~n~_");
	        TextDrawSetString(TD_Round_End_Static[2], "Top graczy w rundzie~n~~n~~n~~n~~n~~n~_");
	        TextDrawSetString(TD_Round_End_Static[3], "Nick_________________Druzyna_____DMG_(Zabojstw)");
	        TextDrawSetString(TD_Round_Match_End_Static[5], "Wynik~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~~n~Punktow");
	        TextDrawSetString(TD_Round_Match_End_Static[6], "_Nick__________________________Damage____(Z)");
	        TextDrawSetString(TD_Round_Match_End_Static[7], "_Nick__________________________Damage____(Z)");
            TextDrawSetString(TD_PlayerHUD_Stats_Static[1], "Zabojstw:~n~Smierci:~n~Obrazenia:~n~_");
	        TextDrawSetString(TD_Round_Help_Static[1], "~n~Wola o pomoc!");
	        TextDrawSetString(TD_Round_CrashAdd_Static[2], "Trwa oczekiwanie na decyzje administratora");
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
public OnRoundCounterChange(newvalue, oldvalue, roundlimit) {
//	new string[32];
	getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_ROUND, (roundlimit == 0 ? 0 : 1));
   	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, newvalue + 1, roundlimit);
    TextDrawSetString(TD_RoundBar_Rounds, g_Chat_String);
}
//------------------------------------------------------------------------------
public OnDefendingTeamSwap(defteam) {
    TextDrawHideForAll(TD_RoundBar_Defend[(defteam == TEAM_ONE ? TEAM_TWO : TEAM_ONE)]);
	forplayers(i) {
	    if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) TextDrawShowForPlayer(i, TD_RoundBar_Defend[defteam]);
	}
}
//------------------------------------------------------------------------------
public OnTeamPointsChange(teamid, newpoints, oldpoints) {
	new string[8];
	valstr(string, newpoints);
	TextDrawSetString(TD_RoundBar_Points[teamid], string);
}
//------------------------------------------------------------------------------
public OnTeamNameChange(teamid, newname[], oldname[]) {
	if(TEAM_ONE <= teamid <= TEAM_TWO) {
	    TextDrawSetString(TD_RoundBar_Name[teamid], newname);
	}
	TextDrawSetString(TD_PlayerHUD_TeamNames[teamid], newname);
    TextDrawSetString(TD_RequestTeamName[teamid], newname);
	return 1;
}
//------------------------------------------------------------------------------
public OnTeamColorChange(teamid, COLOR_TYPES:newcolor, COLOR_TYPES:oldcolor) {

    TextDrawColor(TD_RequestTeamName[teamid], getTeamColorInt(teamid, COLOR_STATUS_ACTIVE));
    TextDrawColor(TD_PlayerHUD_TeamNames[teamid], getTeamColorInt(teamid, COLOR_STATUS_ACTIVE));
	
    if(TEAM_TWO >= teamid) {
	    TextDrawColor(TD_RoundBar_Name[teamid], getTeamColorInt(teamid, COLOR_STATUS_ACTIVE));
	}
	
	forplayers(i) {
	    if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(i) != PLAYER_STATUS_STARTING_CAMERA) {
	        TextDrawShowForPlayer(i, TD_RoundBar_Name[teamid]);
	        if(getPlayerTeam(i) == teamid) {
            	TextDrawShowForPlayer(i, TD_PlayerHUD_TeamNames[teamid]);
			}
	    }
	}
}
//------------------------------------------------------------------------------
public OnPlayerStatsChange(playerid, E_PLAYER_STATS_DATA:type, points) {
	static string[32];
	format(string, sizeof(string), "%d~n~%d~n~%d", getPlayerTotalStats(playerid, KILLS), getPlayerTotalStats(playerid, DEATHS), getPlayerTotalStats(playerid, DAMAGE));
	PlayerTextDrawSetString(playerid, PTD_PlayerHUD_Stats[playerid], string);
}
//------------------------------------------------------------------------------
public OnTDMTeamPointsChange(teamid, newpoints, oldpoints) {
	new string[64];
	format(string, sizeof(string), "~r~%s  ~w~%d : %d  ~b~%s", getTeamName(TEAM_ONE), getArenaTDMPoints(TEAM_ONE),  getArenaTDMPoints(TEAM_TWO), getTeamName(TEAM_TWO));
	TextDrawSetString(TD_ArenaTDM_Info, string);
	
	if(getRoundState() == ROUND_STATE_REMAIN && getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus() && getArenaTDMKillLimit() <= getArenaTDMPoints(teamid)) {
    	endRound(END_ROUND_REASON_POINTS_LIMIT);
	}
}
//------------------------------------------------------------------------------
public OnPlayerStartSpectatePlayer(playerid, newspecid, oldspecid) {
	if(newspecid != oldspecid) { //INFO: Taka sytuacja jest mozliwa np. po automatycznym oswiezeniu speca po '/rsp'.
		new counter, pName[MAX_PLAYER_NAME], lastid;
		
		if(oldspecid != INVALID_PLAYER_ID && getPlayerSpecListStatus(oldspecid)) {
            getTextDrawShortMessage(g_String_512, TD_SHORT_MESSAGE_SPECTATOR, 1);
			for(new i; i < MAX_PLAYERS; i ++) {
			    if(IsPlayerConnected(i) && getPlayerSpecID(i) == oldspecid && getPlayerTeam(i) != TEAM_REF) {
			        if((++ counter) <= 10) {
			        	GetPlayerName(i, pName, sizeof(pName));
			        	format(g_String_512, 512, "%s~n~%s", g_String_512, pName);
					} else lastid = i;
			    }
			}
			
			if(counter > 10) {
			    if(counter == 11) {
		        	GetPlayerName(lastid, pName, sizeof(pName));
		        	format(g_String_512, 512, "%s~n~%s", g_String_512, pName);
			    } else {
			        getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_SPECTATOR, 2);
			        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, counter);
			        strins(g_String_512, g_Chat_String, strlen(g_String_512));
			    }
			}
			
			if(counter > 0) {
				PlayerTextDrawSetString(oldspecid, PTD_SpecBy_List[oldspecid], g_String_512);
				PlayerTextDrawShow(oldspecid, PTD_SpecBy_List[oldspecid]);
			} else {
			    PlayerTextDrawHide(oldspecid, PTD_SpecBy_List[oldspecid]);
			}
		}

		if(newspecid != INVALID_PLAYER_ID && getPlayerSpecListStatus(newspecid)) {
			counter = 0;
            getTextDrawShortMessage(g_String_512, TD_SHORT_MESSAGE_SPECTATOR, 1);
			for(new i; i < MAX_PLAYERS; i ++) {
			    if(IsPlayerConnected(i) && getPlayerSpecID(i) == newspecid && getPlayerTeam(i) != TEAM_REF) {
			        if((++ counter) <= 10) {
			        	GetPlayerName(i, pName, sizeof(pName));
			        	format(g_String_512, 512, "%s~n~%s", g_String_512, pName);
					} else lastid = i;
			    }
			}

			if(counter > 10) {
			    if(counter == 11) {
		        	GetPlayerName(lastid, pName, sizeof(pName));
		        	format(g_String_512, 512, "%s~n~%s", g_String_512, pName);
			    } else {
			        getTextDrawShortMessage(g_Chat_String, TD_SHORT_MESSAGE_SPECTATOR, 2);
			        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, counter);
			        strins(g_String_512, g_Chat_String, strlen(g_String_512));
			    }
			}

			if(counter > 0) {
				PlayerTextDrawSetString(newspecid, PTD_SpecBy_List[newspecid], g_String_512);
				PlayerTextDrawShow(newspecid, PTD_SpecBy_List[newspecid]);
			} else {
			    PlayerTextDrawHide(newspecid, PTD_SpecBy_List[newspecid]);
			}
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
public Timer_Starting(starttimerid) {
	switch(starttimerid) {
	    case 0: SetTimer("Timer_OneSecond", 1000, 1);
		case 1: SetTimer("Timer_TwoHundredMSeconds", 200, 1);
		case 2: SetTimer("Timer_Round_OneSecond", 1000, 1);
		case 3: SetTimer("Timer_FiveSeconds", 5000, 1);
		case 4: SetTimer("Timer_OneHour", 3600000, 1);
	}
}
//------------------------------------------------------------------------------
public Timer_OneSecond() {
	static old_drunk_level[MAX_PLAYERS];
	static p_team, time, Float:float_value_1, Float:float_value_2, int_value;
//	static string[100];
	static string[8];
	static bool:any_admin;
	new total_PlayersInTeam[2], admin_counter, total_players;
    time = gettime();

    forplayers(i) {

        //---------------------
        total_players ++;

		if(IsAdminOrRCON(i, ALVL_ADMIN)) {  //J.Admin nie ma znaczenia, bo nie ma praw do edycji ustawien
			admin_counter ++;
        }
        
        //---------------------
        
		if((int_value = GetPlayerVehicleID(i)) != 0) {
		    GetVehicleHealth(int_value, float_value_1);
		    float_value_2 = ((float_value_1 - 250.0) / 750.0);
		    if(float_value_2 < 0.0) float_value_2 = 0.0;
			if(float_value_2 > 1.0) float_value_2 = 100.0;
		    
		    format(string, sizeof(string), "%.0f", float_value_2 * 100.0);
		    PlayerTextDrawSetString(i, PTD_VehicleHealth_Info[i], string);
            PlayerTextDrawTextSize(i, PTD_VehicleHealth_Box[i], (545.5 + (58 * float_value_2)), 54.000000);
            PlayerTextDrawShow(i, PTD_VehicleHealth_Box[i]);
		}

        //---------------------

        if(TEAM_ONE <= (p_team = getPlayerTeam(i)) <= TEAM_TWO) total_PlayersInTeam[p_team] ++;
        
        if(getPlayerStatus(i) != PLAYER_STATUS_IN_ROUND) {
			for(int_value = 0; int_value < MAX_PLAYERS; int_value ++) {
			    if(IsPlayerConnected(int_value)) {
					if(getPlayerStatus(int_value) != PLAYER_STATUS_IN_ROUND) {
	   					SetPlayerMarkerForPlayer(int_value, i, (GetPlayerColor(i) | 0x00000050));
					} else SetPlayerMarkerForPlayer(int_value, i, (GetPlayerColor(i) & 0xFFFFFF00));
	/*
	   				SetPlayerMarkerForPlayer(int_value, i,
					   		getPlayerStatus(int_value) == PLAYER_STATUS_IN_ROUND ?
							   	(getPlayerTeam(int_value) == p_team ? (GetPlayerColor(i) | 0x00000050) : (GetPlayerColor(i) & 0xFFFFFF00))
					   		: (GetPlayerColor(i) | 0x00000050));
	*/
				} 
			}
		}
        //---------------------

		if(time > getPlayerTakeDamageTime(i) > 0) {
            PlayerTextDrawHide(i, PTD_TakeDamage[i]);
            destroyPlayerDamageObject(i);
            getPlayerTakeDamageTime(i) = 0;
		}

 		if(time > getPlayerGiveDamageTime(i) > 0) {
 		    g_Player_Combo_PlayerID[i] = INVALID_PLAYER_ID;
            PlayerTextDrawHide(i, PTD_GiveDamage[i]);
            getPlayerGiveDamageTime(i) = 0;
		}

 		if(time > getPlayerAimedInfoTime(i) > 0) {
            hidePlayerAimedInfo(i);
            getPlayerAimedInfoTime(i) = 0;
		}

 		if(time > g_Player_ShowDeathMessage[i][0] > 0) {
 		    PlayerTextDrawHide(i, PTD_KilledBy[i]);
            g_Player_ShowDeathMessage[i][0] = 0;
		}

 		if(time > g_Player_ShowDeathMessage[i][1] > 0) {
 		    PlayerTextDrawHide(i, PTD_KillPlayer[i]);
            g_Player_ShowDeathMessage[i][1] = 0;
		}
		
		//---------------------

		setPlayerFPS(i, old_drunk_level[i] - (int_value = GetPlayerDrunkLevel(i)));
		if(int_value < 250) SetPlayerDrunkLevel(i, (old_drunk_level[i] = 1999));
		else old_drunk_level[i] = int_value;

		if(g_Setting_Scoreboard_Type == SCOREBOARD_FPS) SetPlayerScore(i, getPlayerFPS(i));

        //---------------------
/*
        if(GetPlayerState(i) == PLAYER_STATE_DRIVER) {
	        GetVehicleHealth(GetPlayerVehicleID(i), float_value_1);
	        int_value = float_value_1 > 1000.0 ? 100 : floatround((float_value_1 - 250) * 0.13);
            switch(int_value) {
	            case 1..30: 	format(g_Chat_String, sizeof(g_Chat_String), "{F40000}¤¤¤¤¤¤¤¤¤¤  ");
	            case 31..60:	format(g_Chat_String, sizeof(g_Chat_String), "{F2F900}¤¤¤¤¤¤¤¤¤¤  ");
	            case 61..100:   format(g_Chat_String, sizeof(g_Chat_String), "{2FB81B}¤¤¤¤¤¤¤¤¤¤  ");
	            default: 		format(g_Chat_String, sizeof(g_Chat_String), "{000000}¤¤¤¤¤¤¤¤¤¤  ");
	        }
			strins(g_Chat_String, "{000000}", int_value < 1 ? 0 : (floatround(floatdiv(int_value, 10)) + 9));
			Update3DTextLabelText(getPlayerVehicleHealthLabel(i), 0x000000FF, g_Chat_String);
	    }
*/
	    //---------------------

		valstr(string, GetPlayerPing(i)),   PlayerTextDrawSetString(i, PTD_PlayerHUD_Ping[i], string);
		valstr(string, getPlayerFPS(i)),    PlayerTextDrawSetString(i, PTD_PlayerHUD_FPS[i], string);
		format(string, 8, "%.1f%%", (g_Player_LastPLoss[i] = getPlayerPLossFromData(i))), PlayerTextDrawSetString(i, PTD_PlayerHUD_PLoss[i], string);

	    //---------------------

	    GetPlayerHealth(i, float_value_1);
	    GetPlayerArmour(i, float_value_2);

	    if(GetPlayerState(i) != PLAYER_STATE_WASTED) {
	        checkSlideBug(i);
			format(string, sizeof(string), "%.0f", float_value_1),	PlayerTextDrawSetString(i, PTD_PlayerHUD_Health[i], string);
			if(float_value_2 > 0.0) {
				format(string, sizeof(string), "%.0f", float_value_2);
				PlayerTextDrawSetString(i, PTD_PlayerHUD_Armour[i], string);
			} else PlayerTextDrawSetString(i, PTD_PlayerHUD_Armour[i], "_");
		} else {
			PlayerTextDrawSetString(i, PTD_PlayerHUD_Health[i], "Wasted");
		    PlayerTextDrawSetString(i, PTD_PlayerHUD_Armour[i], "_");
		}

        //---------------------
    }

    if(total_PlayersInTeam[TEAM_ONE] == 0 && total_PlayersInTeam[TEAM_TWO] == 0) {
		#if TEST_NEVER_ENDING_ROUND != 1
        if(getMatchStatus()) endMatch(STOP_MATCH_REASON_CMD, true);
        if(getRoundState() == ROUND_STATE_REMAIN) endRound(END_ROUND_REASON_NO_PLAYERS);
        #endif
    }

	if(admin_counter > 0) any_admin = true;
	else {
	    if(total_players == 0) {    //Dla wygody gry, zapis ustawien odbedzie sie dopiero kiedy wyjda wszyscy gracze.
		    if(any_admin == true) {
		        sendCheckVersion();
		        saveAllServerSettings();
		        any_admin = false;
		    }
		}
	}

	if(g_Server_LockedForConnections && admin_counter == 0) {
	    g_Server_LockedForConnections = false;
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_SERVER_LOCK, 2);
	    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
	}


	if(getRoundState() != ROUND_STATE_REMAIN) {
		valstr(string, total_PlayersInTeam[TEAM_ONE]), TextDrawSetString(TD_RoundBar_Players[TEAM_ONE], string);
		valstr(string, total_PlayersInTeam[TEAM_TWO]), TextDrawSetString(TD_RoundBar_Players[TEAM_TWO], string);
	}
	g_TotalPlayers = total_players;
}
//------------------------------------------------------------------------------
public Timer_TwoHundredMSeconds() {
	static Float:posX, Float:posY, Float:posZ;
	static Float:cp_capture_progress;
	static def_team, bool:defender_in_cp, capture_player_id;
	static string[32];
	static capture_msg[32];
	//---------------------

	def_team = getDefendingTeam();
	defender_in_cp = false;

	//---------------------

	if(!getRoundPauseStatus()) capture_player_id = INVALID_PLAYER_ID;
    if(getRoundState() == ROUND_STATE_LOBBY && capture_msg[0] != EOS) capture_msg[0] = EOS;
    else if(getRoundState() == ROUND_STATE_STARTING && capture_msg[0] == EOS) getTextDrawShortMessage(capture_msg, TD_SHORT_MESSAGE_BASE_CAPTURE);

	//---------------------
    setCaptureStatus(false);

	if(getRoundState() == ROUND_STATE_REMAIN) {
		forplayers(i) {
		    if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
		        GetPlayerPos(i, posX, posY, posZ);
		        checkPlayerZonePosition(i, posX, posY, posZ);
		        if(getRoundType() == ROUND_TYPE_BASE) {
					//------------
					if(getLastUpdateTime(i) < 2500 && getPlayerFPS(i) > 0 && !getRoundPauseStatus() && getSpawnProtectTime() <= 0) {
		                if(getPlayerTeam(i) == def_team) {
							if((getCaptureModeFlag() & CP_CAPTURE_DEFENDER_ABORT) && IsPlayerInRangeOfPoint(i, CP_Size() + 0.25, CP_Position(0), CP_Position(1), CP_Position(2))) {
							    capture_player_id = INVALID_PLAYER_ID;
							    cp_capture_progress = 0.0;
							    defender_in_cp = true;
							}
		                } else {
		                    if(defender_in_cp == false && capture_player_id == INVALID_PLAYER_ID && IsPlayerInRangeOfPoint(i, CP_Size() + 0.25, CP_Position(0), CP_Position(1), CP_Position(2))) {
								if(!IsPlayerInAnyVehicle(i) || (getCaptureModeFlag() & CP_CAPTURE_IN_VEHICLE)) {
						            capture_player_id = i;
						            setCaptureStatus(true);
			                        if((cp_capture_progress += getCPCaptureProgressUnit()) >= BASE_CAPTURE_MAX_SIZE) {
			                            cp_capture_progress = 0.0;
			                            return endRound(END_ROUND_REASON_CHECKPOINT);
			                        } else {
				                        format(string, sizeof(string), capture_msg, floatmul(floatdiv(cp_capture_progress, BASE_CAPTURE_MAX_SIZE), 100));
				                        TextDrawSetString(getCaptureInfoTD(), string);
				                        TextDrawTextSize(getCaptureBoxTD(), cp_capture_progress, 16.000000);
			                        }
								}
			                }
			            }
					}
		            //------------
		        }
		    }
		    if(capture_player_id != INVALID_PLAYER_ID && cp_capture_progress > 0 && getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {
				showCaptureBar(i);  //Makrodefinicja - koniecznie ujac w klamry
			}
		}
	}
    //------------
	if(capture_player_id == INVALID_PLAYER_ID) {
		cp_capture_progress = 0.0;
		hideCaptureBarForAll();
	} else {
        for(new i; i < capture_player_id; i ++) {
            if(IsPlayerConnected(i)) {
            	showCaptureBar(i);
			}
	    }
	}
	//------------
	return 1;
}
//------------------------------------------------------------------------------
public Timer_Round_OneSecond() {
	static round_Caption[16], team_HAInfo_Caption[16];
    static bool:round_BackToBase_ShowTextDraw;
    static bool:showTeamMarkers_Status, showTeamMarkers_Time;
    
	if(getRoundState() == ROUND_STATE_REMAIN) {
	    static bool:player_Use_Jetpack[MAX_PLAYERS];
	    new team_PlayersInRound[2], Float:team_HealthAndArmour[2], bool:team_HideHelpIcon[2], p_team, team_DefendersInBase, team_AttackersInBase, Float:team_HealthInfo_Other[2], Float:team_ArmourInfo_Other[2], team_LastPlayer[2] = {INVALID_PLAYER_ID, INVALID_PLAYER_ID};
	    new spec_WeaponCounter[2];
	    static Float:p_healthandarmour;
	    static spec_WeaponID, spec_Ammo, spec_WeaponName[32];
	    static string[2][325], team_HealthInfo[2][290];
	    static int_value_1, int_value_2, x;
	    static Float:float_val_1, Float:float_val_2, Float:float_val_3;
		static bool:round_BackToBasePlayer[MAX_PLAYERS];
		//---------------

        if(round_Caption[0] == EOS) strins(round_Caption, oftenUsedPhrases((getRoundType() == ROUND_TYPE_ARENA ? (!getArenaTDMModeStatus() ? LANG_OUP_ARENA : LANG_OUP_ARENA_TDM) : LANG_OUP_BASE), 3), 0);
        if(team_HAInfo_Caption[0] == EOS) getTextDrawShortMessage(team_HAInfo_Caption, TD_SHORT_MESSAGE_OTHER, 0);

		//---------------

		for(int_value_2 = 0, int_value_1 = gettime(); int_value_2 < 2; int_value_2 ++) {
			if(0 < getShowDamageBarTime(int_value_2) < int_value_1) {
			    resetRoundDamageInfo(TEAM_ONE);
			    resetRoundDamageInfo(TEAM_TWO);
			    TextDrawHideForAll(TD_RoundBar_Damage[int_value_2]);
		        getShowDamageBarTime(int_value_2) = 0;
			}
			if(0 < getHelpIconTime(int_value_2) < int_value_1) {
			    getHelpIconTime(int_value_2) = 0;
			    team_HideHelpIcon[int_value_2] = true;
			}
		}

		//---------------

		team_HealthInfo[0][0] = team_HealthInfo[1][0] = EOS;

		//---------------

		int_value_2 = gettime();

		//---------------

	    forplayers(i) {
	        //---------------
	        for(int_value_1 = 0; int_value_1 < sizeof(g_DeathIcons); int_value_1 ++) {
	            if(g_DeathIcons[int_value_1] != 0 && int_value_2 > g_DeathIcons[int_value_1]) {
	                RemovePlayerMapIcon(i, ICON_DEATH_START + int_value_1);
	            }
	        }
	        //---------------
	        if(getPlayerStatus(i) != PLAYER_STATUS_REQUEST_CLASS) {
	        	if(getRoundTimeRest() < 120) TextDrawShowForPlayer(i, TD_RoundBar_Time);
	        	if(round_BackToBase_ShowTextDraw) showBackToBaseInfo(i);
	        	if(getCaptureStatus()) PlayerPlaySound(i, 5201, 0.0, 0.0, 0.0);
	        	else if(getDefBaseRestTime() < getDefendersBaseBackTime()) PlayerPlaySound(i, 5201, 0.0, 0.0, 0.0);
	        }
	        //---------------

			switch(getPlayerStatus(i)) {
			    case PLAYER_STATUS_IN_ROUND: {
			        if(GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK) {
			            if(player_Use_Jetpack[i] == false) {
				            player_Use_Jetpack[i] = true;
				            getChatMessage(g_Chat_String, CHAT_MESSAGE_USE_JETPACK, 0);
				            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i));
				            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						}
					} else player_Use_Jetpack[i] = false;

                    if(checkPlayerGodModeTime(i) && getRoundType() == ROUND_TYPE_ARENA && getArenaTDMModeStatus()) {
                        givePlayerOldWeapons(i);
                    }

			        GetPlayerHealth(i, float_val_1);
			        GetPlayerArmour(i, float_val_2);

					if(float_val_1 >= 100.0 && getPlayerGodModeTime(i) > int_value_2) {
					    float_val_1 = 100.0;
					}
					
			        team_PlayersInRound[(p_team = getPlayerTeam(i))] ++;
					team_LastPlayer[p_team] = i;

			        if(getTeamHealthInfoBarsStatus()) {
				        if(team_PlayersInRound[p_team] > 5) {
				            team_HealthInfo_Other[p_team] += float_val_1;
				            team_ArmourInfo_Other[p_team] += float_val_2;
				            
				        } else {
			                format(team_HealthInfo[p_team], 290, "%s~n~~n~%s%s  ~w~%.1f (%.1f)", team_HealthInfo[p_team], (p_team == TEAM_ONE ? ("~r~") : ("~b~")), getPlayerName(i), float_val_1, float_val_2);
				        }
			        }

			        team_HealthAndArmour[p_team] += ((p_healthandarmour = float_val_1 + float_val_2));
			        if(team_HideHelpIcon[p_team]) hideHelpIcon(i, p_team);

			        if(getRoundType() == ROUND_TYPE_BASE) {
			            GetPlayerPos(i, float_val_1, float_val_2, float_val_3);
			            if(CP_Position(2) - 0.25 <= float_val_3 <= CP_Position(2) + 0.25) {
			                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[0]);
			                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[1]);
			                TextDrawShowForPlayer(i, TD_Round_CP_Map_ZPos[2]);
			            } else {
			                if(float_val_3 >= CP_Position(2)) {
				                TextDrawShowForPlayer(i, TD_Round_CP_Map_ZPos[0]);
				                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[1]);
				                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[2]);
			                } else {
				                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[0]);
				                TextDrawShowForPlayer(i, TD_Round_CP_Map_ZPos[1]);
				                TextDrawHideForPlayer(i, TD_Round_CP_Map_ZPos[2]);
			                }
			            }
				        if(getGangDefendersBaseZoneID() != -1) {
							if(p_team == getDefendingTeam()) {
						        if(getLastUpdateTime(i) < 2500/*getPlayerFPS(i) > 0*/ && getZonePosition(0) <= float_val_1 <= getZonePosition(2) && getZonePosition(1) <= float_val_2 <= getZonePosition(3) && getZonePosition(4) <= float_val_3 <= getZonePosition(5)) {
						            team_DefendersInBase ++;
						            hideBackToBasePlayerInfo(i);
						            round_BackToBasePlayer[i] = false;
						        } else {
						            showBackToBasePlayerInfo(i);
						            round_BackToBasePlayer[i] = true;
						        }
							} else {
						        if(getLastUpdateTime(i) < 2500/*getPlayerFPS(i) > 0*/ && getZonePosition(0) <= float_val_1 <= getZonePosition(2) && getZonePosition(1) <= float_val_2 <= getZonePosition(3) && getZonePosition(4) <= float_val_3 <= getZonePosition(5)) {
						            team_AttackersInBase ++;
								}
							}
				        } else round_BackToBasePlayer[i] = false;
					} else round_BackToBasePlayer[i] = false;
					
					for(x = 0; x < MAX_PLAYERS; x ++) {
					    if(IsPlayerConnected(x)) {
							if(getPlayerStatus(x) == PLAYER_STATUS_IN_ROUND) {
						        if(getPlayerTeam(x) == p_team || (showTeamMarkers_Status && showTeamMarkers_Time >= 0)) {
						            SetPlayerMarkerForPlayer(x, i, (GetPlayerColor(i) | 0x00000050));
						        } else {
						            SetPlayerMarkerForPlayer(x, i, (GetPlayerColor(i) & 0xFFFFFF00));
						        }
							} else {
								SetPlayerMarkerForPlayer(x, i, (GetPlayerColor(i) & 0xFFFFFF00));
							}
					    }
					}
			    }
			    case PLAYER_STATUS_SPECTATE: {
			        round_BackToBasePlayer[i] = false;

				    GetPlayerHealth(getPlayerSpecID(i), float_val_1);
				    GetPlayerArmour(getPlayerSpecID(i), float_val_2);

				    getTextDrawShortMessage(string[0], TD_SHORT_MESSAGE_SPECTATOR, 0);
				    format(string[0], 325, string[0], float_val_1, float_val_2);
				    PlayerTextDrawSetString(i, PTD_Spectator_HealthAndArmour[i], string[0]);

				    format(string[0], 128, "~b~~h~~h~Ping: ~w~%d  ~b~~h~~h~|  FPS: ~w~%d  ~b~~h~~h~|  P-Loss: ~w~%.1f", GetPlayerPing(getPlayerSpecID(i)), getPlayerFPS(getPlayerSpecID(i)), g_Player_LastPLoss[getPlayerSpecID(i)]);
				    PlayerTextDrawSetString(i, PTD_Spectator_NetStats[i], string[0]);

					string[0][0] = string[1][0] = EOS;
					spec_WeaponCounter[0] = spec_WeaponCounter[1] = 0;

				    for(int_value_1 = 0, int_value_2 = 0; int_value_2 < 13; int_value_2 ++) {
	           			GetPlayerWeaponData(getPlayerSpecID(i), int_value_2, spec_WeaponID, spec_Ammo);
	           			if(46 >= spec_WeaponID > 0) {
	           			    GetWeaponName(spec_WeaponID, spec_WeaponName, sizeof(spec_WeaponName));
           			        spec_WeaponCounter[int_value_1] ++;
           			        format(string[int_value_1], 325, "%s~n~~w~%s  ~b~~h~~h~(~w~%d~b~~h~~h~)", string[int_value_1], spec_WeaponName, spec_Ammo);
	           			    int_value_1 = !int_value_1;
	           			}
				    }

				    if(string[0][0] != EOS) {
						strdel(string[0], 0, 3);
						if(string[1][0] != EOS) strdel(string[1], 0, 3);
					}

					for(int_value_1 = min(spec_WeaponCounter[0], spec_WeaponCounter[1]); int_value_1 < 6; int_value_1 ++) {
					    if(int_value_1 >= spec_WeaponCounter[0]) format(string[0], 325, "%s~n~_", string[0]);
					    if(int_value_1 >= spec_WeaponCounter[1]) format(string[1], 325, "%s~n~_", string[1]);
					}

		            PlayerTextDrawSetString(i, PTD_Spectator_Guns[i][0], string[0]);
	                PlayerTextDrawSetString(i, PTD_Spectator_Guns[i][1], string[1]);

	                if(round_BackToBasePlayer[getPlayerSpecID(i)]) showBackToBasePlayerInfo(i);
	                else hideBackToBasePlayerInfo(i);
			    }
			    default: round_BackToBasePlayer[i] = false;
			}

			if(g_Setting_Scoreboard_Type == SCOREBOARD_HEALTH) {
			    SetPlayerScore(i, ((getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) ? floatround(p_healthandarmour) : 0));
			}

			//---------------
	    }

        //---------------
        #define TEAM_MARKERS_HIDE_INTERVAL   5
        #define TEAM_MARKERS_SHOW_INTERVAL   2
        
		if(getOneOnOneMarkersStatus() && (team_PlayersInRound[TEAM_ONE] == 1 && team_PlayersInRound[TEAM_TWO] == 1) && getRoundType() == ROUND_TYPE_ARENA) {
		    if(showTeamMarkers_Status) {
				if((-- showTeamMarkers_Time) <= -TEAM_MARKERS_HIDE_INTERVAL) {
				    showTeamMarkers_Time = TEAM_MARKERS_SHOW_INTERVAL;
				}
		    } else {
		        showTeamMarkers_Time = TEAM_MARKERS_SHOW_INTERVAL;
		        showTeamMarkers_Status = true;
		    }
		} else {
		    showTeamMarkers_Status = false;
		    showTeamMarkers_Time = 0;
		}
        //---------------
        for(int_value_1 = 0, int_value_2 = gettime(); int_value_1 < sizeof(g_DeathIcons); int_value_1 ++) {
       		if(g_DeathIcons[int_value_1] != 0 && int_value_2 > g_DeathIcons[int_value_1]) {
	            g_DeathIcons[int_value_1] = 0;
	        }
        }
        //---------------
        if(getTeamHealthInfoBarsStatus()) {
            for(int_value_1 = 0; int_value_1 < 2; int_value_1 ++) {
	            if(team_PlayersInRound[int_value_1] > 5) {
	                if(team_PlayersInRound[int_value_1] == 6) {
	                    format(team_HealthInfo[int_value_1], 290, "%s~n~~n~%s%s  ~w~%.1f (%.1f)~n~_", team_HealthInfo[int_value_1], (int_value_1 == TEAM_ONE ? ("~r~") : ("~b~")), getPlayerName(team_LastPlayer[int_value_1]), team_HealthInfo_Other[int_value_1], team_ArmourInfo_Other[int_value_1]);
	                } else {
	                    format(team_HealthInfo[int_value_1], 290, "%s~n~~n~%s [%d]  %.1f (%.1f)~n~_", team_HealthInfo[int_value_1], team_HAInfo_Caption, (team_PlayersInRound[int_value_1] - 5), team_HealthInfo_Other[int_value_1], team_ArmourInfo_Other[int_value_1]);
	                }
	            } else strins(team_HealthInfo[int_value_1], "~n~_", strlen(team_HealthInfo[int_value_1]));
	            TextDrawSetString(TD_Round_Team_PlayersHealth[int_value_1], team_HealthInfo[int_value_1]);
	            TextDrawSetString(TD_Spectator_Team_PlayersHealth[int_value_1], team_HealthInfo[int_value_1]);
			}
        }
  		//---------------
		valstr(string[0], team_PlayersInRound[TEAM_ONE]), TextDrawSetString(TD_RoundBar_Players[TEAM_ONE], string[0]);
		valstr(string[0], team_PlayersInRound[TEAM_TWO]), TextDrawSetString(TD_RoundBar_Players[TEAM_TWO], string[0]);

		format(string[0], 16, "%.0f", team_HealthAndArmour[TEAM_ONE]), TextDrawSetString(TD_RoundBar_Health[TEAM_ONE], string[0]);
		format(string[0], 16, "%.0f", team_HealthAndArmour[TEAM_TWO]), TextDrawSetString(TD_RoundBar_Health[TEAM_TWO], string[0]);
        //---------------
		format(string[0], 64, "mapname %s %d:%d %s", getTeamName(TEAM_ONE), team_PlayersInRound[TEAM_ONE], team_PlayersInRound[TEAM_TWO], getTeamName(TEAM_TWO));
		SendRconCommand(string[0]);
        //---------------
		int_value_1 = floatround(floatdiv((getRoundTimeRest() - 1), 60), floatround_floor);    	//Czas minuty
		int_value_2 = ((getRoundTimeRest() - 1) % 60);	                                        //Czas sekundy
		//---------------
		/*
		    Zmiany oznaczen:
		        spec_WeaponID - Uzywany w przypadku pauzy do efektu migania czasu.
		*/
		spec_WeaponID = 0;
        //---------------
	    if(checkSpawnProtectTime()) {
			if(getSpawnProtectTime() > 0) {
				format(string[0], 32, "Spawn Protect ~w~%d", getSpawnProtectTime());
				TextDrawSetString(TD_SpawnProtect, string[0]);
			} else TextDrawHideForAll(TD_SpawnProtect);
		}
		
		if(getRoundType() != ROUND_TYPE_ARENA || !getArenaTDMModeStatus()) {
		    format(string[0], 16, "%02d:%02d", int_value_1, int_value_2);
			TextDrawSetString(TD_RoundBar_Time, string[0]);

			//---------------
			if(getRoundTimeRest() < 120) TextDrawBoxColor(TD_RoundBar_Time, ((getRoundTimeRest() % 2 == 0) ? 48 : 0xFF000030));
        	//---------------
		}
		
		if(!getRoundPauseStatus()) {
		    if(!getArenaTDMModeStatus() && subRoundTime() == 0) return endRound(END_ROUND_REASON_TIME_LEFT);
		    else {
		        #if _TESTY != 1
		        if(team_PlayersInRound[TEAM_ONE] == 0 || team_PlayersInRound[TEAM_TWO] == 0) return endRound(END_ROUND_REASON_NO_PLAYERS);
				else {
				#endif
				    if(getRoundType() != ROUND_TYPE_ARENA || !getArenaTDMModeStatus()) {
			        	format(string[0], 32, "%s %d (%02d:%02d)", round_Caption, getRoundMapID(), int_value_1, int_value_2);
					} else {
					    format(string[0], 32, "A-TDM %d (%d : %d [Limit: %d])", getRoundMapID(), getArenaTDMPoints(TEAM_ONE), getArenaTDMPoints(TEAM_TWO), getArenaTDMKillLimit());
					}
					SetGameModeText(string[0]);
					
					#if _TESTY != 1
					if(getGangDefendersBaseZoneID() != -1) {
						if(team_DefendersInBase == 0 && team_AttackersInBase > 0) {
						    if(subDefBaseRestTime() == 0) endRound(END_ROUND_REASON_NO_DEFENDERS);
						    else {
						        getTextDrawShortMessage(string[0], TD_SHORT_MESSAGE_DEF_BASE, 0);
						        format(string[0], 64, string[0], getDefBaseRestTime());
						        TextDrawSetString(TD_Round_BTB_Info, string[0]);
								round_BackToBase_ShowTextDraw = true;
							}
						} else {
						    resetDefBaseRestTime();
						    if(round_BackToBase_ShowTextDraw == true) {
						        round_BackToBase_ShowTextDraw = false;
                                hideBackToBaseInfoForAll();
						    }
						}
					}
					#endif
                #if _TESTY != 1
				}
				#endif
		    }
		} else {
		    if(getRoundType() != ROUND_TYPE_ARENA || !getArenaTDMModeStatus()) {
			    if(spec_WeaponID == 0) {
			        format(string[0], 32, "%s %d (%02d:%02d)", round_Caption, getRoundMapID(), int_value_1, int_value_2);
			        spec_WeaponID = 1;
				} else {
			        format(string[0], 32, "%s %d (PAUZA)", round_Caption, getRoundMapID());
			        spec_WeaponID = 0;
				}
				
			} else {
			    if(spec_WeaponID == 0) {
			        format(string[0], 32, "A-TDM %d (%d : %d [Limit: %d])", getRoundMapID(), getArenaTDMPoints(TEAM_ONE), getArenaTDMPoints(TEAM_TWO), getArenaTDMKillLimit());
			        spec_WeaponID = 1;
				} else {
			        format(string[0], 32, "A-TDM %d (PAUZA)", getRoundMapID());
			        spec_WeaponID = 0;
				}
			}
			SetGameModeText(string[0]);
		}
		return 1;
	} else {
	    showTeamMarkers_Status = false;
		showTeamMarkers_Time = 0;
		
		round_Caption[0] = team_HAInfo_Caption[0] = EOS;
		round_BackToBase_ShowTextDraw = false;

		if(g_Setting_Scoreboard_Type == SCOREBOARD_HEALTH) {
			forplayers(i) SetPlayerScore(i, 0);
		}

        for(new i; i < sizeof(g_DeathIcons); i ++) {
	        g_DeathIcons[i] = 0;
        }
		return 0;
	}
}
//------------------------------------------------------------------------------
public Timer_FiveSeconds() {

//	static string[144];

	forplayers(i) {
		if(protectionCheckReferees() || TEAM_NON <= getPlayerTeam(i) <= TEAM_TWO) {
		    if(GetPlayerPing(i) > getMaxPingValue() && !checkPlayerNetCheckFlag(i, DISABLE_NETCHECK_PING)) {
				if(addPlayerProtectorWarning(i, PROTECTOR_CHECK_PING) == 1) {   // 1 - Osiagnieto limit ostrzezen, 0 - Ponizej limitu.
					if(getProtectorAction() == PROTECTOR_SEND_MESSAGE) {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 4);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), "Ping", getMaxPingValue(), GetPlayerPing(i));
						SendClientMessageToAll(COLOR_KICK, g_Chat_String);
					} else {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 2);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), "Ping", getMaxPingValue(), GetPlayerPing(i));
						SendClientMessage(i, COLOR_KICK, g_Chat_String);
						KickEx(i);
						continue;
					}
				} else {
                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 0);
                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, "Ping", getMaxPingValue(), GetPlayerPing(i), getPlayerWarnings(i, PROTECTOR_CHECK_PING), getProtectorMaxWarnings(PROTECTOR_CHECK_PING));
					SendClientMessage(i, COLOR_KICK, g_Chat_String);
				}
		    } else removePlayerProtectorWarning(i, PROTECTOR_CHECK_PING);

		    if(0 < getPlayerFPS(i) < getMinFPSValue() && !checkPlayerNetCheckFlag(i, DISABLE_NETCHECK_FPS)) {
				if(addPlayerProtectorWarning(i, PROTECTOR_CHECK_FPS) == 1) {   // 1 - Osiagnieto limit ostrzezen, 0 - Ponizej limitu.
					if(getProtectorAction() == PROTECTOR_SEND_MESSAGE) {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 4);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), "FPS", getMinFPSValue(), getPlayerFPS(i));
						SendClientMessageToAll(COLOR_KICK, g_Chat_String);
					} else {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 2);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), "FPS", getMinFPSValue(), getPlayerFPS(i));
						SendClientMessage(i, COLOR_KICK, g_Chat_String);
						continue;
					}
				} else {
                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 0);
                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, "FPS", getMinFPSValue(), getPlayerFPS(i), getPlayerWarnings(i, PROTECTOR_CHECK_FPS), getProtectorMaxWarnings(PROTECTOR_CHECK_FPS));
                    SendClientMessage(i, COLOR_KICK, g_Chat_String);
				}
		    } else removePlayerProtectorWarning(i, PROTECTOR_CHECK_FPS);
		    if(g_Player_LastPLoss[i] > getMaxPLossValue() && !checkPlayerNetCheckFlag(i, DISABLE_NETCHECK_PLOSS)) {
				if(addPlayerProtectorWarning(i, PROTECTOR_CHECK_PLOSS) == 1) {   // 1 - Osiagnieto limit ostrzezen, 0 - Ponizej limitu.
					if(getProtectorAction() == PROTECTOR_SEND_MESSAGE) {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 5);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), getMaxPLossValue(), g_Player_LastPLoss[i]);
						SendClientMessageToAll(COLOR_KICK, g_Chat_String);
					} else {
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 3);
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i), getMaxPLossValue(), g_Player_LastPLoss[i]);
						SendClientMessage(i, COLOR_KICK, g_Chat_String);
						KickEx(i);
						continue;
					}
				} else {
                   	getChatMessage(g_Chat_String, CHAT_MESSAGE_PROTECTOR, 1);
                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getMaxPLossValue(), g_Player_LastPLoss[i], getPlayerWarnings(i, PROTECTOR_CHECK_PLOSS), getProtectorMaxWarnings(PROTECTOR_CHECK_PLOSS));
                    SendClientMessage(i, COLOR_KICK, g_Chat_String);
				}
		    } else removePlayerProtectorWarning(i, PROTECTOR_CHECK_PLOSS);
		}
	}
}
//------------------------------------------------------------------------------
public Timer_OneHour() {
    sendServerInfo();
	if(g_TotalPlayers == 0) {
	    sendCheckVersion();
	}
}
//==============================================================================
public Timer_KickPlayer(playerid) Kick(playerid);
//------------------------------------------------------------------------------
public Timer_RCONLoginInfo() {
//    new string[128];
    new s_version[10], s_split[3], index;
    valstr(s_version, g_ActualVersion), strins(s_version, ".", 3), strins(s_version, ".", 1);
    s_split[0] = strval(s_version);
    s_split[1] = strval(s_version[(index = strfind(s_version, ".")) + 1]);
    s_split[2] = strval(s_version[strfind(s_version, ".", true, index + 1) + 1]);
    format(s_version, sizeof(s_version), "%d.%d.%d", s_split[0], s_split[1], s_split[2]);
    
    
    g_RCON_LoginTimerID = -1;
    forplayers(i) {
        if(IsPlayerAdmin(i) && !getPlayerRCONLoginStatus(i)) {
            setPlayerRCONLoginStatus(i);
            getChatMessage(g_Chat_String, CHAT_MESSAGE_RCON_LOGIN, 0);
          	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(i));
           	SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			c_print(g_Chat_String);
			if(isAvailableNewerVersion()) {
				
				getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_NEW_VERSION, 0);
				format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, s_version);
				SendClientMessage(i, COLOR_INFO_1, g_Chat_String);
			}
			if(GetMaxPlayers() > MAX_PLAYERS) {
	            getChatMessage(g_Chat_String, CHAT_MESSAGE_RCON_LOGIN, 1);
	          	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, GetMaxPlayers(), MAX_PLAYERS);
			    SendClientMessage(i, COLOR_KICK, g_Chat_String);
			}
        }
    }
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
Float:circleVariation(Float:from, max) return ((max > 0) ? (from + floatdiv(random((max * 1000)), ((random(2) == 0 ? (-1) : (1)) * 1000))) : from);
//------------------------------------------------------------------------------
AntyDeAMX() {
        new amx[][] ={"Unarmed (Fist)","Brass K"};
        new d;
        #emit load.pri d
        #emit stor.pri d
        #pragma unused amx
}
//------------------------------------------------------------------------------
getParamType(param[], &return_id = INVALID_PLAYER_ID) {
    return_id = INVALID_PLAYER_ID;
	if(!isnull(param)) {
		if('9' >= param[0] >= '0' && strlen(param) <= 3) {
		    if(MAX_PLAYERS >= (return_id = strval(param)) >= 0) return PARAM_TYPE_PLAYER_ID;
		    else return PARAM_TYPE_INVALID;
		} else if(strcmp(param, "all", true) == 0) {
			return PARAM_TYPE_ALL;
		} else if(strcmp(param, "t:", true, 2) == 0) {
		    if(strlen(param) == 3 && '2' >= param[2] >= '1') {
		        return_id = (strval(param[2]) - 1);
		        return PARAM_TYPE_TEAM_ID;
		    } else {
		        if(strcmp(param[2], getTeamName(TEAM_ONE)) == 0) {
		            return_id = TEAM_ONE;
		            return PARAM_TYPE_TEAM_ID;
		        } else if(strcmp(param[2], getTeamName(TEAM_TWO)) == 0) {
		            return_id = TEAM_TWO;
		            return PARAM_TYPE_TEAM_ID;
		        } else {
		            return_id = TEAM_NON;
		            return PARAM_TYPE_TEAM_ID;
		        }
		    }
		}
	}
	return PARAM_TYPE_INVALID;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
CMD:rcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerRoundSettingsMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:tcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerTeamSettingsFirstMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:rvehcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerRoundVehiclesMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:rweapcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerRWeaponsSettingMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:lcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerLobbySettingMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:pcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerProtectorSettingMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:agcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerAGSettingMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:mcfg(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerMSGsSettingMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:team(playerid) {
	SetPVarInt(playerid, PV_HELP_VAR_2, 0);
    showPlayerTeamSettingsFirstMenu(playerid);
    return 1;
}
//------------------------------------------------------------------------------
CMD:tpwd(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
	    new teamid, password;
//	    new string[128];
	    if(sscanf(cmdtext, "p< >dd", teamid, password) != 0 || !setTeamPassword((-- teamid), password)) {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_PASSWORD, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_PASSWORD, (password != 0 ? 1 : 2));
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(teamid));
		    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
            c_print(g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:tname(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
//	    new string[145];
	    if(getRoundState() == ROUND_STATE_LOBBY) {
	        if(!getMatchStatus()) {
		        new teamid, name[10];
			    if(sscanf(cmdtext, "p< >ds[9]", teamid, name) != 0 || !(TEAM_ONE <= (-- teamid) <= TEAM_TWO)) {
		            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_NAME, 0);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				} else {
				    new oldname[16];
				    strins(oldname, getTeamName(teamid), 0);
				    if(setTeamName(teamid, name)) {
			            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_NAME, 1);
						format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), oldname, name);
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
			            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_NAME, 0);
						SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
			} else {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 2);
				SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:tskin(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
//	    new string[128];
		if(getRoundState() == ROUND_STATE_LOBBY) {
		    new teamid, skinid;
		    if(sscanf(cmdtext, "p< >dd", teamid, skinid) != 0 || !setTeamSkin((-- teamid), skinid)) {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_SKIN, 0);
				SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			} else {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_SKIN, 1);
		        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(teamid), skinid);
			    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			    c_print(g_Chat_String);
			}
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:switch(playerid, cmdtext[]) {
//	new string[128];
	if(getRoundState() == ROUND_STATE_LOBBY) {
		if(getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY) {
			if(!isnull(cmdtext) && '1' <= cmdtext[0] <= '3' && strlen(cmdtext) == 1) {
			    new teamid;
			    SetPVarInt(playerid, PV_HELP_VAR_3, 1);
			    if(getTeamPassword((teamid = strval(cmdtext) - 1)) == 0 || getPlayerTeamPassword(playerid, teamid) == getTeamPassword(teamid)) {
			    	setPlayerTeam(playerid, teamid, TEAM_REASON_SWITCH, true);
				} else {
				    SetPVarInt(playerid, PV_HELP_VAR_2, teamid);
				    showPlayerPasswordMenu(playerid);
				}
			} else {
				SetPVarInt(playerid, PV_HELP_VAR_1, playerid);
	            showPlayerSwitchMenu(playerid);
			}
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SWITCH);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	} else {
        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:aswap(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//	    new string[128];
	    if(isnull(cmdtext)){
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_ASWAP, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
	        new teamid, s_playerid;
	        if(sscanf(cmdtext, "p< >dd", s_playerid, teamid) != 0) {
			    SetPVarInt(playerid, PV_HELP_VAR_1, s_playerid);
			    if(!showPlayerSwitchMenu(playerid)) {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_ASWAP, 1);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
	        } else {
	            if(IsPlayerConnected(s_playerid) && getPlayerStatus(s_playerid) == PLAYER_STATUS_LOBBY) {
	                if(TEAM_ONE <= (-- teamid) <= TEAM_REF) {
	                    setPlayerTeam(s_playerid, teamid, TEAM_REASON_ADMIN_SWAP, true);
	                } else {
				        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_ASWAP, 2);
						SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	                }
	            } else {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_ASWAP, 1);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	            }
	        }
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:swap(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//	    new string[128];
		if(getRoundState() == ROUND_STATE_LOBBY) {
		    if(!isnull(cmdtext)) {
		        if(strcmp(cmdtext, "yes") == 0) swapDefendingTeam(true);
		        else if(strcmp(cmdtext, "no") == 0) swapDefendingTeam(false);
		        else {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_SWAP, 0);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					return 1;
		        }
		    } else {
		        swapDefendingTeam(false);
		    }
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_TEAM_SWAP, 1);
	        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			c_print(g_Chat_String);
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:starttdmarena(playerid, cmdtext[]) return cmd_sta(playerid, cmdtext);
CMD:sta(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
 //     new string[128];
		if(getRoundState() == ROUND_STATE_LOBBY || getRoundState() == ROUND_STATE_STARTING) {
		    if(getRoundState() == ROUND_STATE_STARTING) {
                killRoundStartTimer();
                forplayers(i) stopPlayerStartingCamera(i);
				endRound(END_ROUND_REASON_CMD);
		    }
		    new mapid = -1, random_start;
		    if(isnull(cmdtext)) {
		        mapid = getRandomMapID(ROUND_TYPE_ARENA);
		        random_start = true;
		    } else {
		        if(!('9' >= cmdtext[0] >= '0' && strlen(cmdtext) < 8 && 9999999 >= (mapid = strval(cmdtext)) >= 0)) mapid = -1;
		    }
		    if(mapid != -1) {
		        new team_one, team_two;
		        #if _TESTY != 1
		        forplayers(i) {
		            if(!getPlayerAFKMode(i)) {
		            	if(getPlayerTeam(i) == TEAM_ONE) team_one ++;
		                else if(getPlayerTeam(i) == TEAM_TWO) team_two ++;
		                if(team_one > 0 && team_two > 0) break;
					}
		        }
		        #else
		        team_one = team_two = 1;
		        #endif
		        if(team_one > 0 && team_two > 0) {
			        new ret;
			        if((ret = startNewRound(ROUND_TYPE_ARENA, mapid, true)) == 1) {
			            new start_type[8];
			            strins(start_type, oftenUsedPhrases(LANG_OUP_ARENA_TDM, 0), 0);
			            start_type[0] = toupper(start_type[0]);
	                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (random_start ? 1 : 0));
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, start_type, mapid);
	                    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	                    c_print(g_Chat_String);
			        } else {
			            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (ret == -1 ? 3 : 2));
			            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA_TDM, 2), mapid);
			            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
		        } else {
		            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 5);
		            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA_TDM, 2), mapid);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    } else {
	            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 4);
	            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA_TDM, 2), mapid);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    }
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:startarena(playerid, cmdtext[]) return cmd_sa(playerid, cmdtext);
CMD:sa(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
 //     new string[128];
		if(getRoundState() == ROUND_STATE_LOBBY || getRoundState() == ROUND_STATE_STARTING) {
		    if(getRoundState() == ROUND_STATE_STARTING) {
                killRoundStartTimer();
                forplayers(i) stopPlayerStartingCamera(i);
				endRound(END_ROUND_REASON_CMD);
		    }
		    new mapid = -1, random_start;
		    if(isnull(cmdtext)) {
		        mapid = getRandomMapID(ROUND_TYPE_ARENA);
		        random_start = true;
		    } else {
		        if(!('9' >= cmdtext[0] >= '0' && strlen(cmdtext) < 8 && 9999999 >= (mapid = strval(cmdtext)) >= 0)) mapid = -1;
		    }
		    if(mapid != -1) {
		        new team_one, team_two;
		        #if _TESTY != 1
		        forplayers(i) {
		            if(!getPlayerAFKMode(i)) {
		            	if(getPlayerTeam(i) == TEAM_ONE) team_one ++;
		                else if(getPlayerTeam(i) == TEAM_TWO) team_two ++;
		                if(team_one > 0 && team_two > 0) break;
					}
		        }
		        #else
		        team_one = team_two = 1;
		        #endif
		        if(team_one > 0 && team_two > 0) {
			        new ret;
			        if((ret = startNewRound(ROUND_TYPE_ARENA, mapid)) == 1) {
			            new start_type[8];
			            strins(start_type, oftenUsedPhrases(LANG_OUP_ARENA, 0), 0);
			            start_type[0] = toupper(start_type[0]);
	                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (random_start ? 1 : 0));
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, start_type, mapid);
	                    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	                    c_print(g_Chat_String);
			        } else {
			            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (ret == -1 ? 3 : 2));
			            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA, 2), mapid);
			            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
		        } else {
		            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 5);
		            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA, 2), mapid);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    } else {
	            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 4);
	            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_ARENA, 2), mapid);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    }
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:startbase(playerid, cmdtext[]) return cmd_sa(playerid, cmdtext);
CMD:sb(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
// 	    new string[128];
		if(getRoundState() == ROUND_STATE_LOBBY || getRoundState() == ROUND_STATE_STARTING) {
		    if(getRoundState() == ROUND_STATE_STARTING) {
                killRoundStartTimer();
                forplayers(i) stopPlayerStartingCamera(i);
				endRound(END_ROUND_REASON_CMD);
		    }
		    new mapid = -1, bool:random_start;
		    if(isnull(cmdtext)) {
		        mapid = getRandomMapID(ROUND_TYPE_BASE);
		        random_start = true;
		    } else {
		        if(!('9' >= cmdtext[0] >= '0' && strlen(cmdtext) < 8 && 9999999 >= (mapid = strval(cmdtext)) >= 0)) mapid = -1;
		    }
		    if(mapid != -1) {
		        new team_one, team_two;
		        #if _TESTY != 1
		        forplayers(i) {
		            if(!getPlayerAFKMode(i)) {
		            	if(getPlayerTeam(i) == TEAM_ONE) team_one ++;
		                else if(getPlayerTeam(i) == TEAM_TWO) team_two ++;
		                if(team_one > 0 && team_two > 0) break;
					}
		        }
		        #else
		        team_one = team_two = 1;
		        #endif

		        if(team_one > 0 && team_two > 0) {
			        new ret;
			        if((ret = startNewRound(ROUND_TYPE_BASE, mapid)) == 1) {
			            new start_type[8];
			            strins(start_type, oftenUsedPhrases(LANG_OUP_BASE, 0), 0);
			            start_type[0] = toupper(start_type[0]);
	                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (random_start ? 1 : 0));
	                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, start_type, mapid);
	                    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	                    c_print(g_Chat_String);
			        } else {
			            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, (ret == -1 ? 3 : 2));
			            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_BASE, 2), mapid);
			            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			        }
				} else {
		            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 5);
		            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_BASE, 2), mapid);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
		    } else {
	            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_START_ROUND, 4);
	            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(LANG_OUP_BASE, 2), mapid);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    }
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:end(playerid) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
 	    new /*string[128],*/ mapid;
		if((mapid = getRoundMapID()) != INVALID_MAP_ID) {
		    new roundTime = (getRoundTime(getRoundType(), true) - getRoundTimeRest());
			new start_type[12];
			
		    switch(getRoundState()) {
		        case ROUND_STATE_STARTING: {
                    killRoundStartTimer();
                    forplayers(i) stopPlayerStartingCamera(i);
                    endRound(END_ROUND_REASON_CMD);
				}
		        case ROUND_STATE_REMAIN: {
		            endRound(END_ROUND_REASON_CMD);
		        }
		        default: {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
					SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					return 1;
		        }
		    }
		    
            format(start_type, sizeof(start_type), "%s %d", oftenUsedPhrases((getRoundType() == ROUND_TYPE_ARENA ? (!getArenaTDMModeStatus() ? LANG_OUP_ARENA : LANG_OUP_ARENA_TDM) : LANG_OUP_BASE), 0), mapid);
            start_type[0] = toupper(start_type[0]);
            
            if(getRoundType() == ROUND_TYPE_BASE || !getArenaTDMModeStatus()) {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_END_ROUND, 0);
		        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, start_type, floatround(floatdiv(roundTime, 60), floatround_floor), roundTime % 60);
            } else {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_END_ROUND, 2);
		        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, start_type, getTeamName(TEAM_ONE), getArenaTDMPoints(TEAM_ONE), getArenaTDMPoints(TEAM_TWO), getTeamName(TEAM_TWO), getArenaTDMKillLimit());
            }
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			c_print(g_Chat_String);
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:v(playerid, cmdtext[]) return cmd_car(playerid, cmdtext);
CMD:veh(playerid, cmdtext[]) return cmd_car(playerid, cmdtext);
CMD:vehicle(playerid, cmdtext[]) return cmd_car(playerid, cmdtext);
CMD:c(playerid, cmdtext[]) return cmd_car(playerid, cmdtext);
CMD:car(playerid, cmdtext[]) {
//    new string[128];
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	    if(getRoundType() == ROUND_TYPE_BASE && getPlayerTeam(playerid) != getDefendingTeam()) {
	        if(isnull(cmdtext)) {
				if(showPlayerRoundVehSelectMenu(playerid) == -1) {
	                getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 2);
	                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
	        } else {
	            new modelid;
	            if(('0' <= cmdtext[0] <= '9' && 611 >= (modelid = strval(cmdtext)) >= 400) || ((modelid = findVehicleModelByNamePart(cmdtext)) != 0)) {
	                switch(givePlayerRoundVehicle(playerid, modelid)) {
	                    case -1: {
			                getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 2);
			                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	                    }
	                    case -2: {
			                getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 4);
			                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	                    }
	                }
	            } else {
	                getChatMessage(g_Chat_String, CHAT_MESSAGE_VEHICLE_SPAWN, 1);
	                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	            }
	        }
	    }
	} else {
	    if(getLobbyVehiclesStatus()) {
		    if(getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY && (getLobbyInterior() == 0 || getInteriorLobbyVehiclesStatus())) {
		        if(isnull(cmdtext)) {
					if(showPlayerLobbyVehSelectMenu(playerid) == -1) {
		                getChatMessage(g_Chat_String, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, 2);
		                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
		        } else {
		            new modelid;
		            if(('0' <= cmdtext[0] <= '9' && 611 >= (modelid = strval(cmdtext)) >= 400) || ((modelid = findVehicleModelByNamePart(cmdtext)) != 0)) {
		                if(givePlayerLobbyVehicle(playerid, modelid) == -1) {
			                getChatMessage(g_Chat_String, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, 5);
			                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		                }
		            } else {
		                getChatMessage(g_Chat_String, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, 1);
		                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		            }
		        }
		    } else {
		    	getChatMessage(g_Chat_String, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, (getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY ? 3 : 2));
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    }
		} else {
        	getChatMessage(g_Chat_String, CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN, 4);
        	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:gun(playerid) {
    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
        if(((((getRoundTime(getRoundType(), true) - getRoundTimeRest()) <= getGunMenuTime()) || gettime() - getPlayerAddTime(playerid) <= 5)   && (!(getSpawnProtectFlags() & SP_FIRST_BLOOD) || getFirstBloodPlayer() == INVALID_PLAYER_ID)) || getSpawnProtectTime() > 0) {
            resetPlayerOldWeaponsData(playerid);
   		    showPlayerRoundWeaponSelectMenu(playerid);
		} else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GUN, 0);
        	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getGunMenuTime());
	        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:gm(playerid, cmdtext[]) return cmd_gunmenu(playerid, cmdtext);
CMD:gunmenu(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//        new string[128];
        if(getRoundState() == ROUND_STATE_REMAIN) {
            new give_id;
            if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || !(MAX_PLAYERS >(give_id = strval(cmdtext)) >= 0)) {
	        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GUN, 4);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            } else {
                if(IsPlayerConnected(give_id)) {
                    resetPlayerOldWeaponsData(give_id);
                    if(showPlayerRoundWeaponSelectMenu(give_id)) {
 			        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GUN, 1);
 			        	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(give_id));
        				SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
        				c_print(g_Chat_String);
                    } else {
                        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GUN, 2);
                        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
                    }
                } else {
	                getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GUN, 3);
                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
                }
            }
        } else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        }
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:addall(playerid) return cmd_add(playerid, "all");
CMD:add(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//        new string[144];
        if(getRoundState() == ROUND_STATE_REMAIN) {
        
		    new return_id;
		    switch(getParamType(cmdtext, return_id)) {
		        case PARAM_TYPE_PLAYER_ID: {
					if(IsPlayerConnected(return_id) && (getPlayerStatus(return_id) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(return_id) != PLAYER_STATUS_IN_ROUND)) {
						if(addPlayerToRound(return_id, true)) {
						    setPlayerAFKMode(return_id, false, false);
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 4);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id), getTeamName(getPlayerTeam(return_id)));
						    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						} else {
				        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 3);
				            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
		            } else {
			        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 2);
			            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		            }
				}
		        case PARAM_TYPE_ALL: {
	                forplayers(i) {
						addPlayerToRound(i, true);
						setPlayerAFKMode(i, false, false);
					}
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 7);
				    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);
				}
		        case PARAM_TYPE_TEAM_ID: {
		            if(return_id != TEAM_NON) {
		                forplayers(i) {
		                    if(getPlayerTeam(i) == return_id) {
								addPlayerToRound(i, true);
								setPlayerAFKMode(i, false, false);
							}
						}
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 12);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id));
					    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
						getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 13);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        default: {
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 0);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
			}

		} else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
    }
    return 1;
}
//------------------------------------------------------------------------------
CMD:rm(playerid, cmdtext[]) return cmd_rem(playerid, cmdtext);
CMD:remove(playerid, cmdtext[]) return cmd_rem(playerid, cmdtext);
CMD:rem(playerid, cmdtext[]) {
    if(getRoundState() == ROUND_STATE_REMAIN) {
   		if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
		    new return_id;
		    switch(getParamType(cmdtext, return_id)) {
		        case PARAM_TYPE_PLAYER_ID: {
		            if(IsPlayerConnected(return_id) && removePlayerFromFight(return_id)) {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 6);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id), getTeamName(getPlayerTeam(return_id)));
					    SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
		            } else {
			        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 5);
			            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		            }
				}
		        default: {
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 1);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
			}
		} else {
		    if(getSelfRemoveStatus()) {
	            if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	                if( (getSpawnProtectFlags() & SP_FIRST_BLOOD && getFirstBloodPlayer() == INVALID_PLAYER_ID) || getSpawnProtectTime() > 0) {
		                removePlayerFromFight(playerid);
		 		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 9);
		 		       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(getPlayerTeam(playerid)));
			   		 	SendClientMessage(playerid, COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
			   		 	c_print(g_Chat_String);
					} else {
				       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 10);
			   		 	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
	            } else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 8);
		   		 	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	            }
			} else {
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER, 11);
			 	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
        }
	} else {
       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
	    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:kpause(playerid) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
        setPlayerKeyPauseStatus(playerid, !getPlayerKeyPauseStatus(playerid));
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_PAUSE, 2);
		format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(getPlayerKeyPauseStatus(playerid) ? LANG_OUP_ENABLE : LANG_OUP_DISABLE));
		SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
    } else {
 		getChatMessage(g_Chat_String, CHAT_MESSAGE_ADMIN, 0);
		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:p(playerid) return cmd_pause(playerid);
CMD:pause(playerid) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//        new string[128];
        if(getRoundState() == ROUND_STATE_REMAIN) {
            if(getRoundPauseStatus() && getRoundPauseTimerID() == -1) {
                setRoundPauseStatus(false, 3);
 			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_PAUSE, 1);
 			    
 			    if(getRoundCrashAddStatus()) {
 			        new team_PlayersInRound[2];
 			        hideCrashAddInfoForAll();
 			        setRoundCrashAddStatus(false);

				    forplayers(i) {
						if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
					        team_PlayersInRound[getPlayerTeam(i)] ++;
						}
					}

					if(team_PlayersInRound[0] == 0 || team_PlayersInRound[1] == 0) {
					    endRound(END_ROUND_REASON_NO_PLAYERS, true);
	                    getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 6);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
					    SendClientMessageToAll(COLOR_SPAWN_PROTECT_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					}
					return 1;
				}

 			    
            } else {
                setRoundPauseStatus(true, 0);
                getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_PAUSE, 0);
            }
		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
		    SendClientMessageToAll(COLOR_SPAWN_PROTECT_INFO_1, g_Chat_String);
		    c_print(g_Chat_String);
        } else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:rsp(playerid) return cmd_sync(playerid);
CMD:s(playerid) return cmd_sync(playerid);
CMD:sync(playerid) {
//    new string[64];
	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
	    switch(respawnPlayer(playerid)) {
	        case 1: {
	       		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SYNC, 0);
	        	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	        }
	        case 0: {
	      		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SYNC, 1);
	        	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        }
	        case -1: {
	      		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SYNC, 2);
	        	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        }
	        case -2: {
	      		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SYNC, 4);
	        	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        }
 	   	}
	} else {
       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:lastround(playerid) {
	if(getPlayerStatus(playerid) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(playerid) != PLAYER_STATUS_STARTING_CAMERA) {
	    if(getSuccesRoundEndStatus()) {
	        if(GetPVarInt(playerid, PV_LAST_MATCH_SHOW) == 1) {
			    hidePlayerEndMatchInfo(playerid);
				DeletePVar(playerid, PV_LAST_MATCH_SHOW);
	        }
		    if(GetPVarInt(playerid, PV_LAST_ROUND_SHOW) == 0) {
			    showPlayerEndRoundInfo(playerid);
				SetPVarInt(playerid, PV_LAST_ROUND_SHOW, 1);

				getChatMessage(g_Chat_String, CHAT_MESSAGE_ENDROUND, 4);
    			SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			} else {
			    hidePlayerEndRoundInfo(playerid);
				DeletePVar(playerid, PV_LAST_ROUND_SHOW);
			}
		} else {
//		    new string[64];
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_END_ROUND, 1);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:lastmatch(playerid) {
	if(getPlayerStatus(playerid) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(playerid) != PLAYER_STATUS_STARTING_CAMERA) {
	    if(getSuccesMatchEndStatus()) {
	        if(GetPVarInt(playerid, PV_LAST_ROUND_SHOW) == 1) {
			    hidePlayerEndRoundInfo(playerid);
				DeletePVar(playerid, PV_LAST_ROUND_SHOW);
	        }

		    if(GetPVarInt(playerid, PV_LAST_MATCH_SHOW) == 0) {
			    showPlayerEndMatchInfo(playerid);
				SetPVarInt(playerid, PV_LAST_MATCH_SHOW, 1);

				getChatMessage(g_Chat_String, CHAT_MESSAGE_ENDROUND, 4);
				SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			} else {
			    hidePlayerEndMatchInfo(playerid);
				DeletePVar(playerid, PV_LAST_MATCH_SHOW);
			}
		} else {
//		    new string[64];
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 9);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:afk(playerid) {
//	new string[128];
	if(TEAM_ONE <= getPlayerTeam(playerid) <= TEAM_TWO) {
	    if(setPlayerAFKMode(playerid, (getPlayerAFKMode(playerid) ? false : true), true)) {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_AFK_FUNC, (getPlayerAFKMode(playerid) ? 0 : 1));
	        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	    } else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_AFK_FUNC, 3);
	        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	    }
	} else {
        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_AFK_FUNC, 2);
        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:chat(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//	    new string[128];

	    if(getChatLockStatus()) {
	        setChatLockStatus(false);
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_CHATLOCK, 1);
	    } else {
	        setChatLockStatus(true);
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_CHATLOCK, 0);
	    }

        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:rep(playerid, cmdtext[]) return cmd_representative(playerid, cmdtext);
CMD:representative(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
	    new rep_id;
//	    new string[144];
	    if(isnull(cmdtext) || !('9' >= cmdtext[0] >= 0 && MAX_PLAYERS > (rep_id = strval(cmdtext)) >= 0)) {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_REPRESENTATIVE, 2);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        return 1;
	    } else {
	        if(IsPlayerConnected(rep_id)) {
	            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_REPRESENTATIVE, 0);
	            if(isPlayerRepresentative(rep_id)) {
	                setPlayerRepresentativeStatus(rep_id, false);
			        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(rep_id), "nieaktywny");
	            } else {
	                setPlayerRepresentativeStatus(rep_id, true);
	                format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(rep_id), "aktywny");
	            }
	            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	            c_print(g_Chat_String);
	        } else {
	            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_REPRESENTATIVE, 1);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        }
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:replist(playerid) {
	new counter/*, string[64]*/, color[12];
    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_REPRESENTATIVE, 3);
    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
    forplayers(i) {
        if(isPlayerRepresentative(i)) {
            getTeamColorText(getPlayerTeam(i), COLOR_STATUS_DEATH, color, 12);
            format(g_Chat_String, sizeof(g_Chat_String), "%d)  %s  [ID: %d]   |   %s%s", (++ counter), getPlayerName(i), i, color, getTeamName(getPlayerTeam(i)));
            SendClientMessage(playerid, COLOR_INFO_2, g_Chat_String);
        }
    }
    if(!counter) {
        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_REPRESENTATIVE, 4);
        SendClientMessage(playerid, COLOR_INFO_2, g_Chat_String);
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:admins(playerid) {
	new counter/*, string[64]*/, a_name[12], alvl;
    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADMINLIST, 0);
    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
    forplayers(i) {
        if((alvl = getPlayerAdminLevel(i)) > 0) {
            a_name[0] = EOS;
            if(IsPlayerAdmin(i)) strins(a_name, "RCON", 0);
            else getAdminNameByLevel(alvl, a_name, 12);
            format(g_Chat_String, sizeof(g_Chat_String), "%d)  %s  [ID: %d]   |   "C_WHITE"%s", (++ counter), getPlayerName(i), i, a_name);
            SendClientMessage(playerid, COLOR_INFO_2, g_Chat_String);
        }
    }
    if(!counter) {
        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ADMINLIST, 1);
        SendClientMessage(playerid, COLOR_INFO_2, g_Chat_String);
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:kill(playerid) {
	if(getPlayerStatus(playerid) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(playerid) != PLAYER_STATUS_STARTING_CAMERA) {
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
//	        new string[128];
	        getChatMessage(g_Chat_String, CHAT_MESSAGE_SELFKILL);
	        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
	        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    }
	    SetPlayerArmour(playerid, 0.0);
	    SetPlayerHealth(playerid, 0.0);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:start(playerid, cmdtext[]) return cmd_startmatch(playerid, cmdtext);
CMD:startmatch(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//	    new string[144];
	    if(getRoundState() == ROUND_STATE_LOBBY) {
		    if(!getMatchStatus()) {
		        if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0')) {
                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 4);
                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        } else {
		            new round_limit, team1_name[16], team2_name[16];
		            sscanf(cmdtext, "p< >ds[9]s[9]", round_limit, team1_name, team2_name);
		            if(11 >= round_limit >= 1) {
		                if(!isnull(team1_name) && !isnull(team2_name)) {
		                    if(isValidTeamName(team1_name, TEAM_ONE, true) && isValidTeamName(team2_name, TEAM_TWO, true)) {
								if(strcmp(team1_name, team2_name) != 0) {
								    setTeamName(TEAM_ONE, team1_name, true);
								    setTeamName(TEAM_TWO, team2_name, true);
								} else {
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 13);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
								    return 1;
								}
							} else {
			                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 12);
			                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, isValidTeamName(team1_name, TEAM_ONE, true) ? 2 : 1);
			                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 15);
			                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
							    return 1;
							}
		                } else {
			                if(!isnull(team1_name)) {
								if(!setTeamName(TEAM_ONE, team1_name)) {
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 3);
				                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, 1);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 14);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 15);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
								    return 1;
								}
							}
			                if(!isnull(team2_name)) {
								if(!setTeamName(TEAM_TWO, team2_name)) {
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 3);
				                    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, 2);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 14);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 15);
				                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
								    return 1;
								}
							}
						}

						if(checkRoundDataInSQL() != 0) {
							new DBResult:result, buffer[8];
							new start_time, t_1_name[16], t_2_name[16], total_rounds, played_rounds;
							new year, month, day, hour, minute;
					
					        SetPVarInt(playerid, PV_HELP_VAR_1, round_limit);
					        
							result = db_query(dbase, "SELECT * FROM `"D_MATCH"`");
							db_get_field_assoc(result, DM_TEAM_1, t_1_name, sizeof(t_1_name));
							db_get_field_assoc(result, DM_TEAM_2, t_2_name, sizeof(t_2_name));
                            db_get_field_assoc(result, DM_START_TIME, buffer, sizeof(buffer)), start_time = strval(buffer);
                            db_get_field_assoc(result, DM_ROUND_LIMIT, buffer, sizeof(buffer)), total_rounds = strval(buffer);
							db_free_result(result);
							
							result = db_query(dbase, "SELECT `"DMR_WINNER"` FROM `"DMR_ROUND"`");
							played_rounds = db_num_rows(result);
							db_free_result(result);
							
							dtimestamp(start_time, year, month, day, hour, minute);
							
							getDialogBodyMessage(g_String_512, DIALOG_BODY_MATCH_RESTORE, 0);
							format(g_String_512, sizeof(g_String_512), g_String_512, t_1_name, t_2_name, strData(year, month, day, "/", false, true), hour, minute, played_rounds, total_rounds, oftenUsedPhrases(LANG_OUP_NO));
							
       					    ShowPlayerDialog(playerid, DIALOG_MATCH_RESTORE_INFO, DIALOG_STYLE_MSGBOX, getDialogCaptionMessage(DIALOG_CAPTION_MATCH_RESTORE), g_String_512, oftenUsedPhrases(LANG_OUP_YES), oftenUsedPhrases(LANG_OUP_NO));
						} else {
							if(startMatch(round_limit)) {
					        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 0);
					        	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), round_limit, getTeamName(TEAM_ONE), getTeamName(TEAM_TWO));
					            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					            c_print(g_Chat_String);
							}
						}
						
		            } else {
	                    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 5);
	                    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		            }
		        }
		    } else {
	        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 2);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 10);
	            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	            if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 11);
		            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
      		}
		} else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 1);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:stop(playerid) return cmd_stopmatch(playerid);
CMD:stopmatch(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//	    new string[144];
	    if(getRoundState() == ROUND_STATE_LOBBY) {
	        new rounds[2], points[2];
	        rounds[0] = getRoundCounterValue();
	        rounds[1] = getMatchRoundLimit();
	        points[TEAM_ONE] = getTeamPoints(TEAM_ONE);
	        points[TEAM_TWO] = getTeamPoints(TEAM_TWO);
		    if(endMatch(STOP_MATCH_REASON_CMD)) {
       	  		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 8);
       	  		format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), rounds[0], rounds[1], getTeamName(TEAM_ONE), points[TEAM_ONE], getTeamName(TEAM_TWO), points[TEAM_TWO]);
      	      	SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
      	      	c_print(g_Chat_String, true);
		    } else {
      	  		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 6);
      	      	SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    }
		} else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH, 7);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:rmatch(playerid) return cmd_restorematch(playerid);
CMD:restorematch(playerid) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
        if(!getMatchStatus()) {
			if(getRoundState() == ROUND_STATE_LOBBY) {
			    if(loadRoundDataFromSQL()) {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE_MATCH, 0);
			        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
			        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			        c_print(g_Chat_String, true);
			    } else {
			        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE_MATCH, 1);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
			} else {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
        } else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 2);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        }
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:coin(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//	    new string[128];
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_COIN, random(2));
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
	    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:reset(playerid) return cmd_resetpoints(playerid);
CMD:resetpoints(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    if(!getMatchStatus()) {
//		    new string[128];

			setTeamPoints(TEAM_ONE, 0);
			setTeamPoints(TEAM_TWO, 0);
			setRoundCounterValue(0);

			getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESET_POINTS, 0);
			format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
			SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			c_print(g_Chat_String);
		} else {
	        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 2);
			SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:rounds(playerid) {
	if(!showPlayerPlayedRounds(playerid)) {
//	    new string[64];
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_DEL_ROUNDS, 4);
        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:tdm(playerid) {
//	new string[128];
	if(getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY || getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY_TDM) {
	    if(getPlayerStatus(playerid) == PLAYER_STATUS_LOBBY_TDM) {
	        setPlayerStatus(playerid, PLAYER_STATUS_LOBBY);
	        SpawnPlayer(playerid);
	    } else {
		    if(g_ArenaDM_Spawns > 0) {
			    setPlayerStatus(playerid, PLAYER_STATUS_LOBBY_TDM);
			    teleportPlayerToLobbyArenaDM(playerid);
			   	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARENA_DM, 2);
			    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			} else {
			   	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARENA_DM, 1);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		}
	} else {
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARENA_DM, 0);
        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:spectate(playerid, cmdtext[]) return cmd_spec(playerid, cmdtext);
CMD:spec(playerid, cmdtext[]) {
//	new string[128];
	if(getRoundState() == ROUND_STATE_REMAIN) {
		if(isnull(cmdtext)) {
			if(!startSpectate(playerid, INVALID_PLAYER_ID)) {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SPECTATOR, 0);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		} else {
		    new spec_id;
			if('0' <= cmdtext[0] <= '9' && strlen(cmdtext) <= 3 && 0 <= (spec_id = strval(cmdtext)) <= MAX_PLAYERS) {
			    if(!startSpectate(playerid, spec_id)) {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SPECTATOR, 0);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
			}
		}
	} else {
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
	    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:specoff(playerid) {
	stopSpectate(playerid);
	return 1;
}
//------------------------------------------------------------------------------
CMD:speclist(playerid) {
	if(getPlayerSpecListStatus(playerid)) {
    	setPlayerSpecListStatus(playerid, false);
		PlayerTextDrawSetString(playerid, PTD_SpecBy_List[playerid], " ");
		PlayerTextDrawHide(playerid, PTD_SpecBy_List[playerid]);
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SPEC_LIST, 0);
    } else {
     	setPlayerSpecListStatus(playerid, true);
     	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SPEC_LIST, 1);
     	if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
     	    CallLocalFunction("OnPlayerStartSpectatePlayer", "ddd", playerid, playerid, INVALID_PLAYER_ID);
     	}
    }
    SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
CMD:pw(playerid, cmdtext[]) return cmd_pm(playerid, cmdtext);
CMD:priv(playerid, cmdtext[]) return cmd_pm(playerid, cmdtext);
CMD:pm(playerid, cmdtext[]) {
	new message[128];
	if(g_Player_PMLockStatus[playerid] == true) {
	    getChatCMDMessage(message, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 5);
	    SendClientMessage(playerid, COLOR_CMD_ERROR, message);
	} else {
	    new receive_id;
		if(sscanf(cmdtext, "p< >ds[128]", receive_id, message) != 0) {
		    getChatCMDMessage(message, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, message);
		} else {
			if(IsPlayerConnected(receive_id) && receive_id != playerid) {
			    if(g_Player_PMLockStatus[receive_id] == true) {
				    getChatCMDMessage(message, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 6);
	    			SendClientMessage(playerid, COLOR_CMD_ERROR, message);
			    } else {
					new space_index = -1, length;
					for(new i; i < strlen(message); i ++) {
					    if(message[i] != ' ') break;
					    else space_index = i;
					}
					if(space_index != -1) strdel(message, 0, space_index + 1);

					while((space_index = strfind(message, "  ")) != -1) strdel(message, space_index, space_index + 1);
					if((length = strlen(message)) > 0) {
					    if(message[length - 1] == ' ') message[length - 1] = EOS;
					}
					if(isnull(message)) {
					    getChatCMDMessage(message, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 0);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, message);
					} else {
						new sec_line[64], string[200];
						if(strlen(message) >= 70) {
						    strins(sec_line, message[69], 0);
						    message[69] = EOS;
						}

		                format(string, 128, "   (PRIV)  "C_WHITE"%s [ID: %d] {F2B526}: %s", getPlayerName(playerid), playerid, message);
						SendClientMessage(receive_id, 0xF2B526FF, " ");
						SendClientMessage(receive_id, 0xF2B526FF, string);
						if(sec_line[0] != EOS) SendClientMessage(receive_id, 0xF2B526FF, sec_line);
						SendClientMessage(receive_id, 0xF2B526FF, " ");

						format(string, 128, " (SEND) "C_WHITE"%s [ID: %d] {FEDD6B}: %s", getPlayerName(receive_id), receive_id, message);
						SendClientMessage(playerid, 0xFEDD6BFF, string);
						if(sec_line[0] != EOS) SendClientMessage(playerid, 0xFEDD6BFF, sec_line);

						format(string, sizeof(string), "[PRIV] %s -> %s: %s", getPlayerName(playerid), getPlayerName(receive_id), message);
						c_print(string);
					}
				}
			} else {
			    getChatCMDMessage(message, CHAT_CMD_MESSAGE_PRIV_MESSAGE, (IsPlayerConnected(receive_id) ? 1 : 2));
			    SendClientMessage(playerid, COLOR_CMD_ERROR, message);
			}
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:pmlock(playerid) return cmd_lockpm(playerid);
CMD:lockpm(playerid) {
//	new string[80];
	if(g_Player_PMLockStatus[playerid]) {
	    g_Player_PMLockStatus[playerid] = false;
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 4);
	} else {
	    g_Player_PMLockStatus[playerid] = true;
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_PRIV_MESSAGE, 3);
	}
	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
CMD:aiminfo(playerid) {
//	new string[100];
	if(getPlayerAimedInfoStatus(playerid)) {
	    setPlayerAimedInfoStatus(playerid, false);
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_AIM_INFO, 0);
	} else {
	    setPlayerAimedInfoStatus(playerid, true);
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_AIM_INFO, 1);
	}
	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
CMD:dmginfo(playerid) {
//	new string[100];
	if(getPlayerDamageInfoStatus(playerid)) {
	    setPlayerDamageInfoStatus(playerid, false);
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_DMG_INFO, 0);
	} else {
	    setPlayerDamageInfoStatus(playerid, true);
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_DMG_INFO, 1);
	}
	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
CMD:roundset(playerid, cmdtext[]) return cmd_roundsettings(playerid, cmdtext);
CMD:roundsettings(playerid, cmdtext[]) {
	new string[800], yes[16], no[16];

	format(yes, sizeof(yes), "{00FF00}%s", oftenUsedPhrases(LANG_OUP_YES));
	format(no, sizeof(no), "{FF0000}%s", oftenUsedPhrases(LANG_OUP_NO));

	getDialogBodyMessage(string, DIALOG_BODY_MATCH_RS, 0);
	format(string, sizeof(string), string,
	    getRoundTime(ROUND_TYPE_ARENA),
	    getRoundTime(ROUND_TYPE_BASE),
	    ((getCaptureModeFlag() & CP_CAPTURE_NORMAL) ? (yes) : (no)), getCheckpointCaptureTime(),
	    ((getCaptureModeFlag() & CP_CAPTURE_DEFENDER_ABORT) ? (yes) : (no)),
	    ((getCaptureModeFlag() & CP_CAPTURE_IN_VEHICLE) ? (yes) : (no)),
	    getArenaRoundWinMode() == WIN_PLAYERS_ADVANTAGE ? ("Players") : ("Health"),
	    getDefendersBaseStatus() ? yes : no, getDefendersBaseBackTime(),
	    getRoundArmour(),
        ((getWeaponSelectType() == PERMADED_WEAPON_SETS) ? ("Stale zestawy") : ("Wolny wybor")),
        getSpawnProtectSettingTime(),
        ((getSpawnProtectFlags() & SP_ANTI_FALL) ? yes : no),
        ((getSpawnProtectFlags() & SP_FIRST_BLOOD) ? yes : no),
        ((syncInFall() == 1) ? (yes) : (no)),
        (getGlitchStatus(GLITCH_SLIDE_BUG) == 1 ? no : yes),
        (getGlitchStatus(GLITCH_FAST_SHOOT) == 1 ? no : yes),
        (getGlitchStatus(GLITCH_CROUCH_BUG) == 1 ? no : yes),
        getMaxPingValue(),
        getMinFPSValue(),
        getMaxPLossValue(),
        (g_Setting_Scoreboard_Type == SCOREBOARD_HEALTH ? ("Health") : ("FPS"))
	);
	showPlayerBackDialog(playerid, ((strlen(cmdtext) == 3 && strval(cmdtext) == -57) ? BACK_HELP_MENU : BACK_NON), getDialogCaptionMessage(DIALOG_CAPTION_RS), string);
	return 1;
}
//------------------------------------------------------------------------------
/*
*** Wersja bez parametru czasu ***
CMD:k(playerid, cmdtext[]) return cmd_kick(playerid, cmdtext);
CMD:kick(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//		new string[144];
	    new cmd_player, reason[128];
	    if(sscanf(cmdtext, "p< >ds[128]", cmd_player, reason) != 0 && sscanf(cmdtext, "p< >d", cmd_player) != 0) {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
	        if(isnull(reason)) strins(reason, "No reason", 0);
			if(IsPlayerConnected(cmd_player)) {
			    if(!IsAdminOrRCON(cmd_player, ALVL_ADMIN) || playerid == cmd_player) {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 1);
				    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(cmd_player), reason);
				    SendClientMessageToAll(COLOR_KICK, g_Chat_String);
				    c_print(g_Chat_String);
					KickEx(cmd_player);
			    } else {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 2);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
			} else {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 2);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
	    }
	}
	return 1;
}
*/
CMD:k(playerid, cmdtext[]) return cmd_kick(playerid, cmdtext);
CMD:kick(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//		new string[144];
	    new cmd_player, time, reason[128];
	    if(sscanf(cmdtext, "p< >dds[128]", cmd_player, time, reason) != 0 && sscanf(cmdtext, "p< >dd", cmd_player, time) != 0 && sscanf(cmdtext, "p< >d", cmd_player) != 0) {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
	        if(isnull(reason)) strins(reason, "No reason", 0);
			if(IsPlayerConnected(cmd_player)) {
			    if(!IsAdminOrRCON(cmd_player, ALVL_ADMIN)) {
			        if(60 >= time >= 0) {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 1);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(cmd_player), time, reason);
					    SendClientMessageToAll(COLOR_KICK, g_Chat_String);
					    c_print(g_Chat_String);

			            if(time > 0) {
				            new ip[16];
				            GetPlayerIp(cmd_player, ip, sizeof(ip));
							BlockIpAddress(ip, time * 60000);
						}

						KickEx(cmd_player);
			        } else {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 3);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			        }
			    } else {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 2);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
			} else {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_KICK, 2);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
/*
CMD:b(playerid, cmdtext[]) return cmd_ban(playerid, cmdtext);
CMD:ban(playerid, cmdtext[]) {  //Mozna uzyæ BlockIP
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
		new string[144];
	    new cmd_player, time, reason[128];
	    if(sscanf(cmdtext, "p< >dds[128]", cmd_player, time, reason) != 0 && sscanf(cmdtext, "p< >dd", cmd_player, time) != 0 && sscanf(cmdtext, "p< >d", cmd_player) != 0) {
		    getChatCMDMessage(string, CHAT_CMD_BAN, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, string);
	    } else {
	        if(isnull(reason)) strins(reason, "No reason", 0);
			if(IsPlayerConnected(cmd_player)) {
			    if(!IsAdminOrRCON(cmd_player, ALVL_ADMIN)) {
			        if(60 >= time >= 1) {
			            new ip[16];
					    getChatCMDMessage(string, CHAT_CMD_BAN, 1);
					    format(string, sizeof(string), string, getPlayerName(playerid), getPlayerName(cmd_player), time, reason);
					    SendClientMessageToAll(COLOR_KICK, string);
					    c_print(string);

                        GetPlayerIp(cmd_player, ip, sizeof(ip));
						KickEx(cmd_player);
						BlockIpAddress(ip, time * 3600000);
			        } else {
					    getChatCMDMessage(string, CHAT_CMD_BAN, 3);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, string);
			        }
			    } else {
				    getChatCMDMessage(string, CHAT_CMD_BAN, 2);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, string);
			    }
			} else {
			    getChatCMDMessage(string, CHAT_CMD_BAN, 2);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, string);
			}
	    }
	}
	return 1;
}
*/
//------------------------------------------------------------------------------
CMD:ub(playerid, cmdtext[]) return cmd_unbanip(playerid, cmdtext);
CMD:unban(playerid, cmdtext[]) return cmd_unbanip(playerid, cmdtext);
CMD:unbanip(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
  //      new string[128];
        if(isnull(cmdtext) || strlen(cmdtext) >= 16) {
  		    getChatCMDMessage(g_Chat_String, CHAT_CMD_UNBAN, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        } else {
            for(new i; i < strlen(cmdtext); i ++) {
                if(!('0' <= cmdtext[i] <= '9' || cmdtext[i] == '.')) {
		   		    getChatCMDMessage(g_Chat_String, CHAT_CMD_UNBAN, 0);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
                    return 1;
                }
            }
            UnBlockIpAddress(cmdtext);
   		    getChatCMDMessage(g_Chat_String, CHAT_CMD_UNBAN, 1);
   		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, cmdtext);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    c_print(g_Chat_String);
        }
    }
    return 1;
}
//------------------------------------------------------------------------------
CMD:healall(playerid) return cmd_heal(playerid, "all");
CMD:hall(playerid) return cmd_heal(playerid, "all");
CMD:h(playerid, cmdtext[]) return cmd_heal(playerid, cmdtext);
CMD:heal(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//		new string[128];
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new return_id;
		    switch(getParamType(cmdtext, return_id)) {
		        case PARAM_TYPE_PLAYER_ID: {
					if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
					    SetPlayerHealth(return_id, 100.0);
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 2);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 4);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        case PARAM_TYPE_ALL: {
			        forplayers(i) {
			            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) SetPlayerHealth(i, 100.0);
			        }
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 1);
				    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);
				}
		        case PARAM_TYPE_TEAM_ID: {
		            if(return_id != TEAM_NON) {
				        forplayers(i) {
				            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) SetPlayerHealth(i, 100.0);
				        }
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 3);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
						getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 5);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        default: {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_HEALTH, 0);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    }
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:aall(playerid) return cmd_armour(playerid, "all");
CMD:armourall(playerid) return cmd_armour(playerid, "all");
CMD:a(playerid, cmdtext[]) return cmd_armour(playerid, cmdtext);
CMD:armour(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//		new string[128];
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new return_id;
		    switch(getParamType(cmdtext, return_id)) {
		        case PARAM_TYPE_PLAYER_ID: {
					if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
					    SetPlayerArmour(return_id, 100.0);
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 2);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 4);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        case PARAM_TYPE_ALL: {
			        forplayers(i) {
			            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) SetPlayerArmour(i, 100.0);
			        }
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 1);
				    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);
				}
		        case PARAM_TYPE_TEAM_ID: {
		            if(return_id != TEAM_NON) {
				        forplayers(i) {
				            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) SetPlayerArmour(i, 100.0);
				        }
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 3);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
						getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 5);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        default: {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ARMOUR, 0);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    }
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:raall(playerid) return cmd_rarmour(playerid, "all");
CMD:rarmourall(playerid) return cmd_rarmour(playerid, "all");
CMD:ra(playerid, cmdtext[]) return cmd_rarmour(playerid, cmdtext);
CMD:rarmour(playerid, cmdtext[]) {  //Ustawia armour, na wartosc rowna ustawionemu limitowi na serwerze
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//		new string[128];
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new Float:armour;
		    if((armour = getRoundArmour()) > 0.0) {
			    new return_id;
			    switch(getParamType(cmdtext, return_id)) {
			        case PARAM_TYPE_PLAYER_ID: {
						if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
						    SetPlayerArmour(return_id, armour);
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 2);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id));
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						} else {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 4);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
					}
			        case PARAM_TYPE_ALL: {
				        forplayers(i) {
				            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) SetPlayerArmour(i, armour);
				        }
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 1);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					}
			        case PARAM_TYPE_TEAM_ID: {
			            if(return_id != TEAM_NON) {
					        forplayers(i) {
					            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) SetPlayerArmour(i, armour);
					        }
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 3);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id));
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						} else {
							getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 5);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
					}
			        default: {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 0);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			        }
			    }
			} else {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ARMOUR, 6);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:restoreall(playerid, cmdtext[]) return cmd_restore(playerid, "all");
CMD:rall(playerid, cmdtext[]) return cmd_restore(playerid, "all");
CMD:r(playerid, cmdtext[]) return cmd_restore(playerid, cmdtext);
CMD:restore(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//		new string[128];
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new return_id;
		    new Float:armour = getRoundArmour();
		    switch(getParamType(cmdtext, return_id)) {
		        case PARAM_TYPE_PLAYER_ID: {
					if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
					    SetPlayerArmour(return_id, armour);
					    SetPlayerHealth(return_id, 100.0);
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 2);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 4);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        case PARAM_TYPE_ALL: {
			        forplayers(i) {
			            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
							SetPlayerArmour(i, armour);
							SetPlayerHealth(i, 100.0);
						}
			        }
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 1);
				    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);
				}
		        case PARAM_TYPE_TEAM_ID: {
		            if(return_id != TEAM_NON) {
				        forplayers(i) {
				            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) {
								SetPlayerArmour(i, armour);
								SetPlayerHealth(i, 100.0);
							}
				        }
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 3);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					} else {
						getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 5);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				}
		        default: {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_RESTORE, 0);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    }
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:sethp(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new s_select[6], i_value;
		    if(isnull(cmdtext) || sscanf(cmdtext, "p< >s[4]d", s_select, i_value)) {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 0);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    } else {
	            if(100 >= i_value >= 1) {
	            
				    new return_id;
				    switch(getParamType(s_select, return_id)) {
				        case PARAM_TYPE_PLAYER_ID: {
							if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
							    SetPlayerHealth(return_id, i_value);
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 2);
							    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id), i_value);
							    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
							    c_print(g_Chat_String);
							} else {
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 4);
							    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
							}
						}
				        case PARAM_TYPE_ALL: {
					        forplayers(i) {
					            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
									SetPlayerHealth(i, i_value);
								}
					        }
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 1);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), i_value);
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						}
				        case PARAM_TYPE_TEAM_ID: {
				            if(return_id != TEAM_NON) {
						        forplayers(i) {
						            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) {
										SetPlayerHealth(i, i_value);
									}
						        }
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 3);
							    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id), i_value);
							    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
							    c_print(g_Chat_String);
							} else {
								getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 5);
							    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
							}
						}
				        default: {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 0);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				        }
					}
      			} else {
		    		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_HP, 6);
		    		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
			}
		} else {
	   		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
	   		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:seta(playerid, cmdtext[]) return cmd_setarmor(playerid, cmdtext);
CMD:setarmour(playerid, cmdtext[]) return cmd_setarmor(playerid, cmdtext);
CMD:setarmor(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
		if(getRoundState() == ROUND_STATE_REMAIN) {
		    new s_select[6], i_value;
		    if(isnull(cmdtext) || sscanf(cmdtext, "p< >s[4]d", s_select, i_value)) {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 0);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    } else {
		    
	            if(100 >= i_value >= 1) {

				    new return_id;
				    switch(getParamType(s_select, return_id)) {
				        case PARAM_TYPE_PLAYER_ID: {
							if(IsPlayerConnected(return_id) && getPlayerStatus(return_id) == PLAYER_STATUS_IN_ROUND) {
							    SetPlayerArmour(return_id, i_value);
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 2);
							    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id), i_value);
							    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
							    c_print(g_Chat_String);
							} else {
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 4);
							    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
							}
						}
				        case PARAM_TYPE_ALL: {
					        forplayers(i) {
					            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND) {
									SetPlayerArmour(i, i_value);
								}
					        }
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 1);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), i_value);
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						}
				        case PARAM_TYPE_TEAM_ID: {
				            if(return_id != TEAM_NON) {
						        forplayers(i) {
						            if(getPlayerStatus(i) == PLAYER_STATUS_IN_ROUND && getPlayerTeam(i) == return_id) {
										SetPlayerArmour(i, i_value);
									}
						        }
							    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 3);
							    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id), i_value);
							    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
							    c_print(g_Chat_String);
							} else {
								getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 5);
							    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
							}
						}
				        default: {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 0);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				        }
					}
      			} else {
		    		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_SET_ARMOUR, 6);
		    		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
		    }
 		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:tp(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    new s_select[6], i_value;
	    if(isnull(cmdtext) || sscanf(cmdtext, "p< >s[4]d", s_select, i_value)) {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
	        new t_status;
            if(IsPlayerConnected(i_value) && ((t_status = getPlayerStatus(i_value)) != PLAYER_STATUS_REQUEST_CLASS && t_status != PLAYER_STATUS_SPECTATE && t_status != PLAYER_STATUS_STARTING_CAMERA)) {
			    new return_id;
	            new Float:x, Float:y, Float:z, interior, v_world;
	            GetPlayerPos(i_value, x, y, z);
	            interior = GetPlayerInterior(i_value);
	            v_world = GetPlayerVirtualWorld(i_value);
			    
			    switch(getParamType(s_select, return_id)) {
			        case PARAM_TYPE_PLAYER_ID: {
						if(IsPlayerConnected(return_id) && return_id != i_value && getPlayerStatus(return_id) == t_status) {
					        RemovePlayerFromVehicle(return_id);
					        SetPlayerInterior(return_id, interior);
					        SetPlayerVirtualWorld(return_id, v_world);
					        SetPlayerPos(return_id, x + 1.0, y, z);
					        
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 4);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(return_id), getPlayerName(i_value));
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						} else {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 7);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
					}
			        case PARAM_TYPE_ALL: {
				        forplayers(i) {
                            if(getPlayerStatus(i) == t_status && i != i_value) {
						        RemovePlayerFromVehicle(i);
						        SetPlayerInterior(i, interior);
						        SetPlayerVirtualWorld(i, v_world);
						        SetPlayerPos(i, x + 1.0, y, z);
                            }
				        }
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 5);
					    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(i_value));
					    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
					    c_print(g_Chat_String);
					}
			        case PARAM_TYPE_TEAM_ID: {
			            if(return_id != TEAM_NON) {
					        forplayers(i) {
	                            if(getPlayerStatus(i) == t_status && i != i_value && getPlayerTeam(i) == return_id) {
							        RemovePlayerFromVehicle(i);
							        SetPlayerInterior(i, interior);
							        SetPlayerVirtualWorld(i, v_world);
							        SetPlayerPos(i, x + 1.0, y, z);
	                            }
					        }

						    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 6);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getTeamName(return_id), getPlayerName(i_value));
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						} else {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 8);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
					}
			        default: {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 0);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			        }
				}
            } else {
			    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 3);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            }
        }
	}
	return 1;
}

//------------------------------------------------------------------------------
CMD:tpto(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//		new string[70];
		if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || strlen(cmdtext) > 3) {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		} else {
		    format(g_Chat_String, sizeof(g_Chat_String), "%d %d", playerid, strval(cmdtext));
		    cmd_tp(playerid, g_Chat_String);
		}
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:tphere(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//		new string[70];
		if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || strlen(cmdtext) > 3) {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_TELEPORT, 2);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		} else {
		    format(g_Chat_String, sizeof(g_Chat_String), "%d %d", strval(cmdtext), playerid);
		    cmd_tp(playerid, g_Chat_String);
		}
	}
    return 1;
}
//------------------------------------------------------------------------------
CMD:setafk(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
//        new string[128];
        new cmd_player, status[6];
        if(sscanf(cmdtext, "p< >ds[4]", cmd_player, status) != 0) {
 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_AFKSET, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        } else {

            if(IsPlayerConnected(cmd_player) && (strcmp(status, "on", true) == 0 || strcmp(status, "off", true) == 0)) {
                setPlayerAFKMode(cmd_player, (strcmp(status, "on", true) == 0 ? true : false));

	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_AFKSET, 1);
	 		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(cmd_player), (getPlayerAFKMode(cmd_player) ? ("on") : ("off")));
			    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			    c_print(g_Chat_String);
            } else {
	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_AFKSET, 2);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            }
        }
    }
    return 1;
}
//------------------------------------------------------------------------------
CMD:lock(playerid) {    //Zamyka serwer
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//        new string[128];
        g_Server_LockedForConnections = true;
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_SERVER_LOCK, 0);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
	    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:unlock(playerid) return cmd_open(playerid);
CMD:open(playerid) {    //Otwiera serwer
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//        new string[128];
        g_Server_LockedForConnections = false;
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_SERVER_LOCK, 1);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
	    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:mute(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//        new string[128];
        if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || strlen(cmdtext) > 3) {
 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 0);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        } else {
            new cmd_player;
            if(IsPlayerConnected((cmd_player = strval(cmdtext))) && g_Player_MuteStatus[cmd_player] == false) {
                if(!IsAdminOrRCON(cmd_player, ALVL_JUNIOR_ADMIN)) {
                    g_Player_MuteStatus[cmd_player] = true;
	 	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 4);
	 	 		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(cmd_player));
				    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);

				} else {
		 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 6);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
            } else {
	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 2);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            }
        }
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:unmute(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
//        new string[128];
        if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || strlen(cmdtext) > 3) {
 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 1);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
        } else {
            new cmd_player;
            if(IsPlayerConnected((cmd_player = strval(cmdtext))) && g_Player_MuteStatus[cmd_player] == true) {
                if(!IsAdminOrRCON(cmd_player, ALVL_JUNIOR_ADMIN)) {
                    g_Player_MuteStatus[cmd_player] = false;
	 	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 5);
	 	 		    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(cmd_player));
				    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				    c_print(g_Chat_String);
				} else {
		 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 6);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
            } else {
	 		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MUTE, 3);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            }
        }
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:gmx(playerid) {
    if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
//        new string[128];
	    getChatCMDMessage(g_Chat_String, CHAT_CMD_GMX, 0);
	    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
	    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
	    c_print(g_Chat_String);
        SendRconCommand("gmx");
    }
	return 1;
}
//------------------------------------------------------------------------------
CMD:login(playerid, cmdtext[]) return cmd_alog(playerid, cmdtext);
CMD:alog(playerid, cmdtext[]) {
	if(!isnull(cmdtext) && 16 >= strlen(cmdtext) >= 3) {
//	    new string[144];
		for(new i, a_level[16]; i < 3; i ++) {
		    if(g_Admin_Passwords[i][0] != EOS && strcmp(g_Admin_Passwords[i], cmdtext) == 0) {
		        setPlayerAdminLevel(playerid, i + 1);
		        getAdminNameByLevel(i + 1, a_level, 16);
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_ADMIN, 0);
		        format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), a_level);
		        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
		        c_print(g_Chat_String);
		        return 1;
		    }
		}
  		getChatCMDMessage(g_Chat_String, CHAT_CMD_ADMIN, 1);
	    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:me(playerid) {
    showPlayerSettingsMenu(playerid);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cfg(playerid) return cmd_settings(playerid);
CMD:settings(playerid) {
	showSettingsMenu(playerid);
	return 1;
}
//------------------------------------------------------------------------------
CMD:weather(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
	    new /*string[128],*/ weather;
	    if(isnull(cmdtext) || !setServerWeather((weather = strval(cmdtext)))) {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_WEATHER, 0);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_WEATHER, 1);
            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), weather);
            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
            c_print(g_Chat_String);
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:gravity(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
	    new /*string[128],*/ Float:gravity;
	    if(isnull(cmdtext) || !setServerGravity((gravity = floatstr(cmdtext)))) {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GRAVITY, 0);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_GRAVITY, 1);
            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), gravity);
            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
            c_print(g_Chat_String);
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:nametagdis(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
	    new /*string[128],*/ Float:nametagdis;
	    if(isnull(cmdtext) || !setServerNameTagDistance((nametagdis = floatstr(cmdtext)))) {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NAMETAGDIS, 0);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NAMETAGDIS, 1);
            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), nametagdis);
            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
            c_print(g_Chat_String);
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:wtime(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_HEAD_ADMIN)) {
	    new /*string[128],*/ w_time;
	    if(isnull(cmdtext) || !setServerWorldTime((w_time = strval(cmdtext)))) {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_WORLD_TIME, 0);
            SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
            getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_WORLD_TIME, 1);
            format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), w_time);
            SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
            c_print(g_Chat_String);
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:players(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
	    new ip[16];
	    SendClientMessage(playerid, -1, " ");
	    forplayers(i) {
	        GetPlayerIp(i, ip, sizeof(ip));
	        format(g_Chat_String, sizeof(g_Chat_String), "%s (ID: %d) | IP: %s | P-Loss: %.2f%% | FPS: %d", getPlayerName(i), i, ip, g_Player_LastPLoss[i], getPlayerFPS(i));
	        SendClientMessage(playerid, 0xEFEFEFFF, g_Chat_String);
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:hi(playerid) return cmd_hide(playerid);
CMD:hide(playerid) {
    hidePlayerEndMatchInfo(playerid), 	DeletePVar(playerid, PV_LAST_MATCH_SHOW);
    hidePlayerEndRoundInfo(playerid),	DeletePVar(playerid, PV_LAST_ROUND_SHOW);
	return 1;
}
//------------------------------------------------------------------------------
CMD:checkversion(playerid) return cmd_chckver(playerid);
CMD:checkver(playerid) return cmd_chckver(playerid);
CMD:chckver(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
	    sendCheckVersion(playerid);
		getChatMessage(g_Chat_String, CHAT_MESSAGE_HTTP_NEW_VERSION, 2);
		SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:pomoc(playerid) return cmd_help(playerid);
CMD:cmd(playerid) return cmd_help(playerid);
CMD:cmds(playerid) return cmd_help(playerid);
CMD:help(playerid) {
    showPlayerHelpMenu(playerid);
	return 1;
}
//------------------------------------------------------------------------------
CMD:mrounds(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    if(getMatchStatus()) {
		    if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '1') || strlen(cmdtext) > 2) {
		        getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH_ROUNDS, 3);
                SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		    } else {
				new new_round_limit;
				if(11 >= (new_round_limit = strval(cmdtext)) >= 1 && new_round_limit > getRoundCounterValue()) {
				    if(new_round_limit != getMatchRoundLimit()) {
				        if(getRoundState() == ROUND_STATE_LOBBY) {
						    setMatchRoundLimit(new_round_limit);
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH_ROUNDS, 0);
						    format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), new_round_limit);
						    SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						    c_print(g_Chat_String);
						    CallLocalFunction("OnRoundCounterChange", "ddd", getRoundCounterValue(), getRoundCounterValue(), new_round_limit);
				            format(g_Chat_String, sizeof(g_Chat_String), "mapname %s %d:%d %s (R: %d/%d)", getTeamName(TEAM_ONE), getTeamPoints(TEAM_ONE), getTeamPoints(TEAM_TWO), getTeamName(TEAM_TWO), getRoundCounterValue() + 1, new_round_limit);
				            SendRconCommand(g_Chat_String);
						} else {
						    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 0);
						    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
						}
					} else {
					    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH_ROUNDS, 1);
					    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
					}
				} else {
				    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_MATCH_ROUNDS, 2);
				    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
		    }
		} else {
		    getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_ROUND_ERROR, 3);
		    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:eyeinfo(playerid) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
		setPlayerEyeStatus(playerid, !getPlayerEyeStatus(playerid));
		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_EYE, 1);
		format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, oftenUsedPhrases(getPlayerEyeStatus(playerid) ? LANG_OUP_ENABLE : LANG_OUP_DISABLE));
		SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	} else {
 		getChatMessage(g_Chat_String, CHAT_MESSAGE_ADMIN, 0);
		SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:pinfo(playerid) {
	new Float:health;
	GetPlayerHealth(playerid, health);
	format(g_Chat_String, sizeof(g_Chat_String), "ID: %d | HP: %.1f | Team: %d | G-Team: %d | State: %d | G-Status: %d | Int: %d | VW: %d | Car: %d (%d)", playerid, health, GetPlayerTeam(playerid), getPlayerTeam(playerid), GetPlayerState(playerid), getPlayerStatus(playerid), GetPlayerInterior(playerid), GetPlayerVirtualWorld(playerid), GetPlayerVehicleID(playerid), GetVehicleModel(GetPlayerVehicleID(playerid)));
	SendClientMessage(playerid, -1, g_Chat_String);
	return 1;
}
//------------------------------------------------------------------------------
CMD:cadd(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
        if(getRoundState() == ROUND_STATE_REMAIN) {
            new add_id;
	        if(isnull(cmdtext) || !('9' >= cmdtext[0] >= '0') || !(MAX_PLAYERS > (add_id = strval(cmdtext)) >= 0)) {
	            if(isnull(cmdtext)) {
	                showCrashedPlayersList(playerid);
	            } else {
	                getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 0);
	                SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	            }
			} else {
				if(IsPlayerConnected(add_id)) {
				    if(getPlayerStatus(add_id) != PLAYER_STATUS_REQUEST_CLASS && getPlayerStatus(add_id) != PLAYER_STATUS_IN_ROUND && GetPlayerState(add_id) != PLAYER_STATE_WASTED && TEAM_ONE <= getPlayerTeam(add_id) <= TEAM_TWO) {
						new index, pName[MAX_PLAYER_NAME];
						GetPlayerName(add_id, pName, sizeof(pName));
						if((index = searchCrashIndexByNick(pName)) != -1) {
						    if(getCrashTeamAtIndex(index) == getPlayerTeam(add_id)) {
						        addPlayerAfterCrash(add_id, index);
								getChatMessage(g_Chat_String, CHAT_MESSAGE_CRASH_ADD, 0);
								format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), pName, pName, getTeamName(getPlayerTeam(add_id)));
								SendClientMessageToAll(COLOR_ADD_REMOVE_INFO_1, g_Chat_String);
								c_print(g_Chat_String);
						    } else {
				                getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 1);
				                SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
						    }
						} else {
					   		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 5);
					        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
						}
				    } else {
				   		getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 2);
				        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
				    }
				} else {
	                getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 3);
	                SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
				}
			}
		} else {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_C_ADD, 4);
	        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:labo(playerid, cmdtext[]) {
    if(IsAdminOrRCON(playerid, ALVL_JUNIOR_ADMIN)) {
        if(isnull(cmdtext)) {
        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 0);
	        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
        } else {
          	if(strcmp(cmdtext, "on", true) == 0) {
          	    if(g_MilitaryBaseObjects == -1) {
	                g_MilitaryBaseObjects = CreateObject(3095,268.5750,1884.1197,16.0673,0.0,0.0,0.0);
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 1);
		        	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
			        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			        c_print(g_Chat_String);
				} else {
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 4);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
    		} else if(strcmp(cmdtext, "off", true) == 0) {
				if(g_MilitaryBaseObjects != -1) {
				    DestroyObject(g_MilitaryBaseObjects);
				    g_MilitaryBaseObjects = -1;
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 2);
		        	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
			        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
			        c_print(g_Chat_String);
				} else {
		        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 4);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
            } else {
	        	getChatCMDMessage(g_Chat_String, CHAT_CMD_LABO, 0);
		        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
            }
        }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:destroyvehicle(playerid, cmdtext[]) return cmd_dv(playerid, cmdtext);
CMD:dv(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    if(isnull(cmdtext)) {
	       	getChatCMDMessage(g_Chat_String, CHAT_CMD_DESTROY_VEHICLE, 1);
	        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	    } else {
	        new modelid = -1, destroy_counter;
	        if(strcmp(cmdtext, "all", true) == 0) {
	            for(new i,x, bool:is_in_vehicle, vehicleid; i < MAX_PLAYERS; i ++) {
	                if(getPlayerRoundVehicleID(i) != -1 && 611 >= GetVehicleModel((vehicleid = getPlayerRoundVehicleID(i))) >= 400) {
	                    is_in_vehicle = false;
	                    for(x = 0; x < MAX_PLAYERS; x ++) {
	                        if(IsPlayerConnected(x) && IsPlayerInVehicle(x, vehicleid)) {
	                            is_in_vehicle = true;
	                            break;
	                        }
	                    }
	                    if(!is_in_vehicle) {
	                        destroy_counter ++;
	                        destroyPlayerRoundVehicle(i);
	                    }
	                }
	            }
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_DESTROY_VEHICLE, 2);
		       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), destroy_counter);
		        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
		        c_print(g_Chat_String);
	        } else {
				if(!('6' >= cmdtext[0] >= '4' && strlen(cmdtext) == 3 && 611 >= (modelid = strval(cmdtext)) >= 400)) modelid = -1;
				if(modelid == -1 && (modelid = findVehicleModelByNamePart(cmdtext)) == 0) modelid = -1;
				
				if(modelid != -1) {
				    new veh_name[32];
		            for(new i,x, bool:is_in_vehicle, vehicleid; i < MAX_PLAYERS; i ++) {
		                if(getPlayerRoundVehicleID(i) != -1 && GetVehicleModel((vehicleid = getPlayerRoundVehicleID(i))) == modelid) {
		                    is_in_vehicle = false;
		                    for(x = 0; x < MAX_PLAYERS; x ++) {
		                        if(IsPlayerConnected(x) && IsPlayerInVehicle(x, vehicleid)) {
		                            is_in_vehicle = true;
		                            break;
		                        }
		                    }
		                    if(!is_in_vehicle) {
		                        destroy_counter ++;
		                        destroyPlayerRoundVehicle(i);
		                    }
		                }
		            }
		            
		            strunpack(veh_name, getVehicleNameByIndex(modelid - 400), 32);
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_DESTROY_VEHICLE, 3);
			       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), veh_name, modelid, destroy_counter);
			        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
			        c_print(g_Chat_String);
				} else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_DESTROY_VEHICLE, 0);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				}
	        }
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:fixvehicle(playerid, cmdtext[]) return cmd_fv(playerid, cmdtext);
CMD:fv(playerid, cmdtext[]) {
	new vehicleid;
	if(!isnull(cmdtext) && IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    if(getRoundState() == ROUND_STATE_REMAIN) {
	        if(getRoundType() == ROUND_TYPE_BASE) {
			    new repair_ID;
			    if(3 >= strlen(cmdtext) >= 1 && (strcmp(cmdtext, "all", true) == 0 || ('9' >= cmdtext[0] >= '0' && (repair_ID = strval(cmdtext)) >= 0))) {
			        if(strcmp(cmdtext, "all", true) == 0) {
						for(new i, time = gettime(); i < MAX_PLAYERS; i ++) {
			                if(IsPlayerConnected(i) && (vehicleid = GetPlayerVehicleID(i)) != 0 && GetPlayerState(i) == PLAYER_STATE_DRIVER) {
				                g_Player_VehicleFixCMD_Time[i] = time;
						        RepairVehicle(vehicleid);
			                }
			            }
				       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 5);
				       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				        c_print(g_Chat_String);
			        } else {
				        if(IsPlayerConnected(repair_ID) && getPlayerStatus(repair_ID) == PLAYER_STATUS_IN_ROUND) {

				            if((vehicleid = GetPlayerVehicleID(repair_ID)) != 0 && GetPlayerState(repair_ID) == PLAYER_STATE_DRIVER) {
				                g_Player_VehicleFixCMD_Time[repair_ID] = gettime();
						        RepairVehicle(vehicleid);
						       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 6);
						       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), getPlayerName(repair_ID));
						        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
						        c_print(g_Chat_String);
				            } else {
						       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 7);
						        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				            }
				        } else {
					       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 8);
					        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				        }
					}
			    } else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 9);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			    }
 			} else {
			   	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 10);
			    SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
			}
		}
	} else {
		if((vehicleid = GetPlayerVehicleID(playerid)) != 0 && GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {
		    if(getPlayerStatus(playerid) == PLAYER_STATUS_IN_ROUND) {
		        if(getSelfVehRepairStatus()) {
		            if(gettime() - g_Player_VehicleFixCMD_Time[playerid] >= getSelfVehRepairMinTime()) {
		                g_Player_VehicleFixCMD_Time[playerid] = gettime();
				        RepairVehicle(vehicleid);
				       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 3);
				       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid));
				        SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
				        c_print(g_Chat_String);
		            } else {
				       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 4);
				       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getSelfVehRepairMinTime() - (gettime() - g_Player_VehicleFixCMD_Time[playerid]));
				        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		            }
		        } else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 1);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		        }
		    } else {
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 2);
		        SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
		        RepairVehicle(vehicleid);
		    }
		} else {
	       	getChatCMDMessage(g_Chat_String, CHAT_CMD_FIX_VEHICLE, 0);
	        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
		}
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:nc(playerid, cmdtext[]) return cmd_netcheck(playerid, cmdtext);
CMD:netcheck(playerid, cmdtext[]) {
	if(IsAdminOrRCON(playerid, ALVL_ADMIN)) {
	    new changeID, s_changeType[10];
	    if(sscanf(cmdtext, "p< >ds[8]", changeID, s_changeType)) {
	        if(sscanf(cmdtext, "p< >d", changeID)) {
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 0);
		        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        } else {
	            if(IsPlayerConnected(changeID)) {
	            	format(g_Chat_String, sizeof(g_Chat_String), " (NetCheck: Status) "TEXT_INFO_2"%s"TEXT_INFO_1": %sPing "TEXT_INFO_1"| %sFPS "TEXT_INFO_1"| %sPLoss", getPlayerName(changeID), !checkPlayerNetCheckFlag(changeID, DISABLE_NETCHECK_PING) ? (C_LIGHTGREEN) : (C_KICK), !checkPlayerNetCheckFlag(changeID, DISABLE_NETCHECK_FPS) ? (C_LIGHTGREEN) : (C_KICK), !checkPlayerNetCheckFlag(changeID, DISABLE_NETCHECK_PLOSS) ? (C_LIGHTGREEN) : (C_KICK));
					SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	        	} else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 1);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        	}
			}
	    } else {
	        if(IsPlayerConnected(changeID)) {
	            new changeValue = -1;
	            if(strcmp(s_changeType, "ping", true) == 0) changeValue = DISABLE_NETCHECK_PING;
	            else if(strcmp(s_changeType, "fps", true) == 0) changeValue = DISABLE_NETCHECK_FPS;
	            else if(strcmp(s_changeType, "ploss", true) == 0) changeValue = DISABLE_NETCHECK_PLOSS;
				else {
			       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 0);
			        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
				    return 1;
				}

                if(checkPlayerNetCheckFlag(changeID, changeValue)) subPlayerNetCheckFlag(changeID, changeValue);
                else addPlayerNetCheckFlag(changeID, changeValue);
                
                for(new i = strlen(s_changeType); i >= 0; i --) s_changeType[i] = toupper(s_changeType[i]);

		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 2);
		       	format(g_Chat_String, sizeof(g_Chat_String), g_Chat_String, getPlayerName(playerid), s_changeType, getPlayerName(changeID), !checkPlayerNetCheckFlag(changeID, changeValue) ? (C_LIGHTGREEN) : (C_KICK), oftenUsedPhrases((!checkPlayerNetCheckFlag(changeID, changeValue) ? LANG_OUP_ENABLE : LANG_OUP_DISABLE)));
		       	SendClientMessageToAll(COLOR_INFO_1, g_Chat_String);
		       	c_print(g_Chat_String);
		       	
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 3);
		       	SendClientMessage(changeID, COLOR_INFO_1, g_Chat_String);
	        } else {
		       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 1);
		        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        }
	    }
	}
	return 1;
}
//------------------------------------------------------------------------------
CMD:mnc(playerid, cmdtext[]) return cmd_mynetcheck(playerid, cmdtext);
CMD:mynetcheck(playerid, cmdtext[]) {
	new checkID = playerid;
	if(!isnull(cmdtext) && '9' >= cmdtext[0] >= '0' && strlen(cmdtext) <= 3) {
	    if(!IsPlayerConnected((checkID = strval(cmdtext)))) {
	       	getChatCMDMessage(g_Chat_String, CHAT_CMD_MESSAGE_NETCHECK, 1);
	        SendClientMessage(playerid, COLOR_CMD_ERROR, g_Chat_String);
	        return 1;
	    }
	}
   	format(g_Chat_String, sizeof(g_Chat_String), " (NetCheck: Status) "TEXT_INFO_2"%s"TEXT_INFO_1": %sPing "TEXT_INFO_1"| %sFPS "TEXT_INFO_1"| %sPLoss", getPlayerName(checkID), !checkPlayerNetCheckFlag(checkID, DISABLE_NETCHECK_PING) ? (C_LIGHTGREEN) : (C_KICK), !checkPlayerNetCheckFlag(checkID, DISABLE_NETCHECK_FPS) ? (C_LIGHTGREEN) : (C_KICK), !checkPlayerNetCheckFlag(checkID, DISABLE_NETCHECK_PLOSS) ? (C_LIGHTGREEN) : (C_KICK));
	SendClientMessage(playerid, COLOR_INFO_1, g_Chat_String);
	return 1;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
/*
CMD:gl(playerid) {
	if(DO_USUNIECIA_GLITCH_DEBUG[playerid]) {
	    DO_USUNIECIA_GLITCH_DEBUG[playerid] = false;
	    SendClientMessage(playerid, -1, " Debug AntyGlitcha zostal wylaczony.");
	} else {
	    DO_USUNIECIA_GLITCH_DEBUG[playerid] = true;
	    SendClientMessage(playerid, -1, " Debug AntyGlitcha zostal wlaczony.");
	}
	return 1;
}
*/
//==============================================================================
