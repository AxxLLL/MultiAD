/*

*/
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
forward OnDefaultLanguageChange(newlanguage, oldlanguage);
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define LANG_PL									0
//==============================================================================
new g_DefaultLanguage = -1;
//==============================================================================
changeDefaultLanguage(language) {
	if(language >= LANG_PL) {
		if(language != g_DefaultLanguage) {
			new oldlanguage = g_DefaultLanguage;
			CallLocalFunction("OnDefaultLanguageChange", "dd", (g_DefaultLanguage = language), oldlanguage);
		}
		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
getDefaultLanguage() return g_DefaultLanguage;
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	CONSOLE_MESSAGE_STARTING				0
#define CONSOLE_MESSAGE_NEW_CONFIG_FILE			1
#define CONSOLE_MESSAGE_CONFIG_ERROR			2
#define CONSOLE_MESSAGE_LOADED_MAPS_INFO		3
#define CONSOLE_MESSAGE_ROUND_START_ERROR		4
//==============================================================================
getConsoleMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case CONSOLE_MESSAGE_STARTING: {
			switch(language) {
				case LANG_PL: strins(output, "\n-------------------------------\
												\n Multi A/D (2009 - 2015)\
												\n-------------------------------\
												\n Wersja: "_VERSION"\
												\n Autor: Rafal (AxL) Zoltanski\
												\n Ost. aktualizacja: "LAST_UPDATE"\
												\n Limit graczy: "#MAX_PLAYERS"\
												\n-------------------------------\
												\n\
												\n ---------------------------------\
												\n (MultiAD) Data startu: %02d/%02d/%d [%02d:%02d:%02d]", 0, size);
			}
		}
		case CONSOLE_MESSAGE_NEW_CONFIG_FILE: {
			switch(language) {
				case LANG_PL: strins(output, " (MultiAD : Config) Utworzono plik konfiguracyjny '%s' o sciezce '%s'.", 0, size);
			}
		}
		case CONSOLE_MESSAGE_CONFIG_ERROR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawny interior w pliku konfiguracyjnym. Wartosc interioru musi byc w przedziale od 0 do 18. <'%s' | 'interior' | Line: %d>", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawna pozycja. Pozycja musi byc w formacie 'PosX, PosY, PosZ'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Osiagnieto limit danych: '%d'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawna pozycja. Pozycja musi byc w przedziale od '0.0' do '1000.0'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}				
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawna pozycja. Pozycja musi byc w formacie 'PosX, PosY, PosZ, F_Angle'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawna wartosc. Wartosc musi byc w przedziale od '%d' do '%d'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, "(MultiAD : Config) Niepoprawna wartosc. Wartosc musi byc w przedziale od '%.4f' do '%.4f'. <'%s' | '%s' | Line: %d>", 0, size);
					}
				}				
			}
		}
		case CONSOLE_MESSAGE_LOADED_MAPS_INFO: {
			switch(language) {
				case LANG_PL: strins(output, "(MultiAD : Maps) Odnaleziono %d plikow aren i %d plikow baz", 0, size);
			}
		}
		case CONSOLE_MESSAGE_ROUND_START_ERROR: {
			switch(msg_subindex) {
				case -1: {
					switch(language) {
						case LANG_PL: strins(output, "Nieodnaleziono pliku '%s' (Mapid: %d | Typ: %s)", 0, size);
					}				
				}
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Blad przy odczycie danych mapy (Mapid: %d | Typ: %s). Blad w wartosci 'interior' (Oczekiwana wartosc miedzy 0 i 18)", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Blad przy odczycie pozycji spawnu '%s' (Mapid: %d | Typ: %s). Pozycja musi byc miedzy '-9999.0' and '9999.0' (Aktualna: %.4f | %.4f | %.4f | %.0f | %.0f)", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "Blad przy odczycie pozycji '%s' (Mapid: %d | Typ: %s). Pozycja musi byc miedzy '-9999.0' and '9999.0' (Aktualna: %.4f | %.4f | %.4f | %.4f | %.4f | %.4f)", 0, size);
					}				
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, "Blad przy odczycie pozycji '%s' (Mapid: %d | Typ: %s). Pozycja musi byc miedzy '-9999.0' and '9999.0' (Aktualna: %.4f | %.4f | %.4f)", 0, size);
					}
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, "Bledna pozycja zostala zamieniona przez system na domyslna (%.4f | %.4f | %.4f | %.0f | %.0f)", 0, size);
					}
				}			
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, "Opcja zostala dezaktywowana", 0, size);
					}			
				}
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, "Blad w '%s' (Mapid: %d | Typ: %s). Obszar musi byc w formacie 'MinX, MinY, MaxX, MaxY, MinZ, MaxZ' (Parametry 'MinZ' i 'MaxZ' sa opcjonalne)", 0, size);
					}			
				}	
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, "Pozycja 'Min' musi byc mniejsza od pozycji 'Max' (Aktualne: %.4f < %.4f [%s] | %.4f < %.4f [%s]", 0, size);
					}
				}
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, "Parametr 'MaxZ' jest mniejszy od 'MinZ' (%.2f < %.2f [%s]). System zamienil je na domyslne.", 0, size);
					}
				}
				case 9: {
					switch(language) {
						case LANG_PL: strins(output, "Blad w pozycjach 'Obszar walki' i 'Team Spawn' (Mapid: %d | Typ: %s). Pozycja 'Team Spawn' nie miesci sie w 'Obszar walki'.", 0, size);
					}
				}
				case 10: {
					switch(language) {
						case LANG_PL: strins(output, "Rezultat '%s' (z odchyleniem):  MinX: (obszar < spawn]) %.2f < %.2f [%s] | MaxX %.2f < %.2f [%s] | MinY: %.2f < %.2f [%s] | MaxY: %.2f < %.2f [%s] | Z: %.2f < %.2f < %.2f [%s]", 0, size);
					}
				}
				case 11: {
					switch(language) {
						case LANG_PL: strins(output, "Runda moze byc wystartowana, jednak moga pojawic sie bledy w rozgrywce", 0, size);
					}
				}
			}
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	CHAT_CMD_MESSAGE_TEAM_PASSWORD			0
#define	CHAT_CMD_MESSAGE_TEAM_NAME				1
#define	CHAT_CMD_MESSAGE_TEAM_SKIN				2
#define	CHAT_CMD_MESSAGE_SWITCH					3
#define	CHAT_CMD_MESSAGE_TEAM_ASWAP				4
#define	CHAT_CMD_MESSAGE_TEAM_SWAP				5
#define CHAT_CMD_MESSAGE_ROUND_ERROR			6
#define	CHAT_CMD_MESSAGE_SET_ERROR				7
#define	CHAT_CMD_MESSAGE_START_ROUND			8
#define	CHAT_CMD_MESSAGE_END_ROUND				9
#define CHAT_CMD_MESSAGE_GUN					10
#define CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER	11
#define	CHAT_CMD_MESSAGE_ROUND_PAUSE			12
#define	CHAT_CMD_MESSAGE_SYNC					13
#define CHAT_CMD_MESSAGE_AFK_FUNC				14
#define	CHAT_CMD_MESSAGE_CHATLOCK				15
#define	CHAT_CMD_MESSAGE_REPRESENTATIVE			16
#define	CHAT_CMD_MESSAGE_ADMINLIST				17
#define	CHAT_CMD_MESSAGE_MATCH					18
#define	CHAT_CMD_MESSAGE_COIN					19
#define	CHAT_CMD_MESSAGE_RESET_POINTS			20
#define	CHAT_CMD_MESSAGE_DEL_ROUNDS				21
#define CHAT_CMD_MESSAGE_ARENA_DM				22
#define CHAT_CMD_MESSAGE_SPECTATOR				23
#define	CHAT_CMD_MESSAGE_PRIV_MESSAGE			24
#define	CHAT_CMD_MESSAGE_HEALTH					25
#define	CHAT_CMD_MESSAGE_ARMOUR					26
#define	CHAT_CMD_MESSAGE_ROUND_ARMOUR			27
#define	CHAT_CMD_MESSAGE_RESTORE				28
#define	CHAT_CMD_TELEPORT						29
#define	CHAT_CMD_AFKSET							30
#define	CHAT_CMD_SERVER_LOCK					31
#define	CHAT_CMD_MUTE							32
#define	CHAT_CMD_KICK							33
#define	CHAT_CMD_BAN							34
#define	CHAT_CMD_UNBAN							35
#define	CHAT_CMD_GMX							36
#define CHAT_CMD_ADMIN							37
#define	CHAT_CMD_MESSAGE_AIM_INFO				38
#define	CHAT_CMD_MESSAGE_DMG_INFO				39
#define	CHAT_CMD_MESSAGE_WEATHER				40
#define	CHAT_CMD_MESSAGE_WORLD_TIME				41
#define	CHAT_CMD_MESSAGE_GRAVITY				42
#define	CHAT_CMD_MESSAGE_NAMETAGDIS				43
#define CHAT_CMD_MESSAGE_MATCH_ROUNDS			44
#define CHAT_CMD_MESSAGE_EYE					45
#define CHAT_CMD_MESSAGE_C_ADD					46
#define CHAT_CMD_INVALID_COMMAND				47
#define	CHAT_CMD_LABO							48
#define CHAT_CMD_FIX_VEHICLE					49
#define	CHAT_CMD_DESTROY_VEHICLE				50
#define	CHAT_CMD_MESSAGE_SPEC_LIST				51
#define CHAT_CMD_MESSAGE_NETCHECK				52
#define CHAT_CMD_MESSAGE_SET_HP					53
#define CHAT_CMD_MESSAGE_SET_ARMOUR				54
#define	CHAT_CMD_MESSAGE_RESTORE_MATCH			55
#define	CHAT_CMD_MESSAGE_TEAM_COLOR				56
//==============================================================================
getChatCMDMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case CHAT_CMD_MESSAGE_TEAM_PASSWORD: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tpwd [Team ID (1, 2 lub 3)] [Haslo (Uzyj 0 zeby zresetowac lub 1000 do 9999 zeby ustawic)]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil haslo druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zresetowal haslo druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}
				}				
			}
		}
		case CHAT_CMD_MESSAGE_TEAM_NAME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tname [Team ID (1 lub 2)] [Unikalna nazwa o dlugosci od '1' do '8' znakow (litery, cyfry, symbole: _()[].$@=)]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil nazwe druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"' na '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}
				}			
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozna zmienic nazwy druzyny w trakcie trwania meczu.", 0, size);
					}				
				}
			}
		}
		case CHAT_CMD_MESSAGE_TEAM_SKIN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tskin [Team ID (1, 2 lub 3)] [Indywidualny skin (0 - 299)]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil skin druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"' na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}			
			}
		}
		case CHAT_CMD_MESSAGE_SWITCH: {
			switch(language) {
				case LANG_PL: strins(output, " (CMD) Musisz byc w obszarze 'Lobby' zeby moc uzyc komendy.", 0, size);
			}
		}	
		case CHAT_CMD_MESSAGE_TEAM_ASWAP: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/aswap [ID Gracza] [Team ID (1, 2 lub 3)]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub gracz nie jest w 'Lobby'", 0, size);
					}
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID druzyny. ID musi byc w przedziale od 1 do 2.", 0, size);
					}
				}					
			}
		}		
		case CHAT_CMD_MESSAGE_TEAM_SWAP: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/swap [Zmiana skinu ('yes' lub 'no')]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s"TEXT_INFO_1" zmienil strony walki druzyn.", 0, size);
					}				
				}
			}
		}
		case CHAT_CMD_MESSAGE_ROUND_ERROR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda niedostepna w czasie trwania rundy.", 0, size);
					}		
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda dostepna jedynie czasie trwania rundy.", 0, size);
					}						
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda niedostepna w trakcie trwania meczu.", 0, size);
					}						
				}				
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda dostepna jedynie w trakcie trwania meczu.", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_MESSAGE_SET_ERROR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/set [Nazwa ustawienia] [Wartosc]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nazwy ustawien: arena_time, base_time.", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna wartosc ustawienia '%s'. Poprawna wartosc powinna byc w przedziale od '%d' do '%d'.", 0, size);
					}				
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Zmieniono wartosc ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}				
				}				
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Zmiana ustawienia niemozliwa w trakcie trwania rundy.", 0, size);
					}					
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna wartosc ustawienia '%s'.", 0, size);
					}
				}
			}
		}		
		case CHAT_CMD_MESSAGE_START_ROUND: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Administrator wystartowal runde: "TEXT_INFO_2"%s %d", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Administrator wystartowal losowa runde: "TEXT_INFO_2"%s %d", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nieodnaleziono pliku %s o ID '%d'.", 0, size);
					}					
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Napotkano na blad wewnatrz pliku %s o ID '%d'.", 0, size);
					}					
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID %s.", 0, size);
					}				
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) W druzynach bioracych udzial w walce musi byc co najmniej jeden aktywny gracz (Bez aktywnego statusu 'AFK').", 0, size);
					}				
				}				
			}
		}
		case CHAT_CMD_MESSAGE_END_ROUND: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, " (Info) Administrator przerwal runde. ("TEXT_INFO_2"%s"TEXT_INFO_1" | Czas trwania: "TEXT_INFO_2"%02d:%02d"TEXT_INFO_1")", 0, size);
					}
				} 
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) W ostatnim czasie nie rozegrano do konca zadnej rundy.", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Administrator przerwal runde. ("TEXT_INFO_2"%s"TEXT_INFO_1" | %s "TEXT_INFO_2"%d:%d"TEXT_INFO_1" %s | Limit: "TEXT_INFO_2"%d"TEXT_INFO_1")", 0, size);
					}
				}
			}
		}		
		case CHAT_CMD_MESSAGE_GUN: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda dostepna przez pierwszych %d sekund rundy, do uplywu ochrony poczatkowej lub przelania \"pierwszej krwi\".", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s pozwolil graczu "TEXT_INFO_2"%s"TEXT_INFO_1" na zmiane broni.", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrany gracz nie bierze udzialu w rundzie.", 0, size);
					}				
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID lub wybrane ID nie jest uzywane.", 0, size);
					}				
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/gunmenu [ID Gracza]' zeby pozwolic wybranemu graczu na zmiane broni", 0, size);
					}				
				}					
			}
		}
		case CHAT_CMD_MESSAGE_ADD_AND_REMOVE_PLAYER: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '/add [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')]' zeby dodac gracza do rundy.", 0, size);
					}				
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '(/rem)ove [ID Gracza]' zeby usunac gracza do rundy.", 0, size);
					}				
				}				
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub gracz jest poza obszarem poczekalni.", 0, size);
					}							
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Gracz musi byc w druzynie bioracej udzial w walce aby moc uzyc na nim komendy.", 0, size);
					}							
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dodal gracza "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1" do walki (Druzyna: "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1")", 0, size);
					}					
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID lub gracz nie bierze udzialu w walce.", 0, size);
					}							
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s usunal gracza "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1" z walki (Druzyna: "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1")", 0, size);
					}						
				}		
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dodal wszystkich graczy do walki.", 0, size);
					}					
				}				
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz brac udzial w rundzie, zeby moc uzyc komendy.", 0, size);
					}					
				}
				case 9: {
					switch(language) {
						case LANG_PL: strins(output, " (Auto Remove) "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1"usunal sie z rundy (Druzyna: "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1")", 0, size);
					}					
				}	
				case 10: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda dziala do zakonczenia \"Spawn Protect\" lub momentu przelania pierwszej krwi.", 0, size);
					}					
				}			
				case 11: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Ustawienia serwera, niepozwalaja na usuniecie sie z rundy.", 0, size);
					}					
				}		
				case 12: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dodal wszystkich graczy z druzyny "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1" do walki.", 0, size);
					}					
				}
				case 13: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_MESSAGE_ROUND_PAUSE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_SPAWN_PROTECT_INFO_2"%s"TEXT_SPAWN_PROTECT_INFO_1" zatrzymal gre.", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_SPAWN_PROTECT_INFO_2"%s"TEXT_SPAWN_PROTECT_INFO_1" wznowil gre.", 0, size);
					}					
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status pauzy na przycisk (\"Y\") na: "C_WHITE"%s", 0, size);
					}					
				}				
			}
		}
		case CHAT_CMD_MESSAGE_SYNC: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Zrespawnowales swoja postac", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz stac na ziemii zeby moc uzyc komendy.", 0, size);
					}					
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz odczekac chwile, zeby moc ponownie uzyc komendy.", 0, size);
					}						
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozesz miec broni w reku, zeby moc uzyc funkcji.", 0, size);
					}					
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozna uzyc komendy w poblizu gracza z innej druzyny.", 0, size);
					}				
				}
			}			
		}
		case CHAT_CMD_MESSAGE_AFK_FUNC: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Zmieniles status 'AFK' na '"TEXT_INFO_2"aktywny"TEXT_INFO_1"'. Oznacza to, ze nie bedziesz dodawany do rundy po starcie.", 0, size);
					}				
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Zmieniles status 'AFK' na '"TEXT_INFO_2"nieaktywny"TEXT_INFO_1"'.", 0, size);
					}				
				}						
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz byc w druzynie bioracej udzial w walce, zeby moc zmienic status 'AFK'.", 0, size);
					}				
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozesz zmienic statusu 'AFK' bedac w rundzie.", 0, size);
					}				
				}							
			}
		}
		case CHAT_CMD_MESSAGE_CHATLOCK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s ustawil status chatu globalnego na "TEXT_INFO_2"nieaktywny"TEXT_INFO_1".", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s ustawil status chatu globalnego na "TEXT_INFO_2"aktywny"TEXT_INFO_1".", 0, size);
					}				
				}				
			}
		} 
		case CHAT_CMD_MESSAGE_REPRESENTATIVE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s ustawil status 'reprezentanta' gracza "TEXT_INFO_2"%s"TEXT_INFO_1" na "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}				
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Podane ID gracza jest niepoprawne lub aktualnie nieuzywane.", 0, size);
					}				
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '(/rep)resentative [ID Gracza]' zeby pozwolic lub zakazac graczu pisac na chacie podczas blokady.", 0, size);
					}						
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " ----- Lista graczy ze statusem reprezentanta -----", 0, size);
					}					
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " Brak graczy ze statusem reprezentanta.", 0, size);
					}					
				}
			}				
		}
		case CHAT_CMD_MESSAGE_ADMINLIST: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " ----- Lista graczy ze statusem administratora -----", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " Brak graczy ze statusem administratora.", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_MESSAGE_MATCH: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s wlaczyl ustawienia meczowe (Rund: "TEXT_INFO_2"%d"TEXT_INFO_1" | "TEXT_INFO_2"%s "TEXT_INFO_1"vs"TEXT_INFO_2" %s"TEXT_INFO_1")", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozesz wlaczyc ustawien meczowych w trakcie trwania rundy.", 0, size);
					}					
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Ustawienia meczowe sa juz wlaczone. Wylacz je komenda '(/stop)match' i wlacz nowe.", 0, size);
					}					
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Napotkano niepoprawna nazwe druzyny (ID druzyny: %d)", 0, size);
					}					
				}			
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '(/start)match [Ilosc rund (1 - 11)] <Nazwa druzyny 1> <Nazwa druzyny 2>' zeby wlaczyc ustawienia meczowe.", 0, size);
					}					
				}		
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna ilosc rund. Ilosc rund musi zawierac sie w przedziale od 1 do 11.", 0, size);
					}					
				}
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Aktualnie nie sa wlaczone ustawienia meczowe. Mozesz je wlaczyc komenda '(/start)match'.", 0, size);
					}					
				}
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozna wylaczyc ustawien meczowych w trakcie trwania rundy.", 0, size);
					}					
				}	
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s wylaczyl ustawienia meczowe (Rund: "TEXT_INFO_2"%d/%d"TEXT_INFO_1" | "TEXT_INFO_2"%s [%d] "TEXT_INFO_1"vs "TEXT_INFO_2"%s [%d]"TEXT_INFO_1")", 0, size);
					}					
				}		
				case 9: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) W ostatnim czasie nie rozegrano zadnego meczu.", 0, size);
					}					
				}
				case 10: {
					switch(language) {
						case LANG_PL: strins(output, " (Porada) Jesli chcesz zmienic ilosc rund w meczu bez jego wylaczania, uzyj komendy '/mrounds'.", 0, size);
					}					
				}
				case 11: {
					switch(language) {
						case LANG_PL: strins(output, " (Porada) Jesli chcesz usunac ktoras z rund z ogolnego wyniku, uzyj komendy '/rounds'.", 0, size);
					}					
				}	
				case 12: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nazwa druzyny %d zawiera niedozwolone symbole. Nazwa moze skladac sie z liter, cyfr oraz symboli: ()[]._$@=", 0, size);
					}						
				}
				case 13: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nazwy druzyn nie moga byc identyczne.", 0, size);
					}						
				}
				case 14: {
					switch(language) {
						case LANG_PL: strins(output, " (Podpowiedz) Nazwa druzyny nie moze byc identyczna z juz istniejaca i musi skladac sie z liter, cyfr lub znakow: ()[]._$@=", 0, size);
					}						
				}
				case 15: {
					switch(language) {
						case LANG_PL: strins(output, " (Podpowiedz) Wielokrotne symbole twardej spacji \"_\" sa zamieniane w jeden, oraz sa usuwane z poczatku oraz konca nazwy!", 0, size);
					}						
				}
			}
		}
		case CHAT_CMD_MESSAGE_COIN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1" rzucil moneta. Rezultat: "TEXT_INFO_2"Orzel", 0, size);
					}				
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1" rzucil moneta. Rezultat: "TEXT_INFO_2"Reszka", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_MESSAGE_RESET_POINTS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1"zresetowal punkty druzyn.", 0, size);
					}			
				}		
			}
		}
		case CHAT_CMD_MESSAGE_DEL_ROUNDS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Runda %d: "COLOR_DIALOG_COUNT"%s %d\n"COLOR_DIALOG_BODY"Druzyna broniaca: "COLOR_DIALOG_COUNT"%s\n"COLOR_DIALOG_BODY"Zwyciezca: "COLOR_DIALOG_COUNT"%s\n"COLOR_DIALOG_BODY"Powod: "COLOR_DIALOG_COUNT"%s\n"COLOR_DIALOG_BODY"Czas rundy: "COLOR_DIALOG_COUNT"%d min. %d. sek.", 0, size);
					}					
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Czy na pewno chcesz usunac wpis o rundzie?", 0, size);
					}					
				}				
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s usunal wpis rundy "TEXT_INFO_2"%d "TEXT_INFO_1"z danych meczu ("TEXT_INFO_2"%s %d "TEXT_INFO_1"| Wygrana: "TEXT_INFO_2"%s"TEXT_INFO_1")", 0, size);
					}
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Nie mozna usunac wpisu w trakcie trwania rundy.", 0, size);
					}
				}		
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Aktualnie nie trwa zaden mecz.", 0, size);
					}				
				}
			}		
		}
		case CHAT_CMD_MESSAGE_ARENA_DM: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Na arene treningowa mozesz przeniesc sie przebywajac wylacznie w poczekalni.", 0, size);
					}					
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Brak pozycji spawnu na arenie treningowej.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Zeby wyjsc z areny treningowej, ponownie uzyj komendy '"TEXT_INFO_2"/tdm"TEXT_INFO_1"'.", 0, size);
					}					
				}					
			}				
		}
		case CHAT_CMD_MESSAGE_SPECTATOR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie znaleziono gracza mozliwego do obserwacji, lub Twoj stan gry nie pozwala na obserwacje.", 0, size);
					}					
				}				
			}				
		}		
		case CHAT_CMD_MESSAGE_PRIV_MESSAGE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/pm [ID Odbiorcy] [Wiadomosc]' zeby wyslac prywatna wiadomosc do gracza.", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozesz wyslac prywatnej wiadomosci do samego siebie.", 0, size);
					}					
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrane ID jest nieuzywane.", 0, size);
					}					
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"Wylaczyles "TEXT_INFO_1"odbior prywatnych wiadomosci.", 0, size);
					}					
				}					
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"Wlaczyles "TEXT_INFO_1"odbior prywatnych wiadomosci.", 0, size);
					}					
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wylaczyles mozliwosc pisania i odbierania prywatnych wiadomosci.", 0, size);
					}					
				}		
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrany gracz ma wylaczona mozliwosc odbierania prywatnych wiadomosci.", 0, size);
					}					
				}					
			}				
		}
		case CHAT_CMD_MESSAGE_HEALTH: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/heal [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')]' zeby uzdrowic gracza(y).", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil wszystkich graczy.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil gracza "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil wszystkich graczy w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}					
				}					
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie jest w rundzie.", 0, size);
					}					
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}					
			}
		}
		case CHAT_CMD_MESSAGE_ARMOUR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/armour [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')]' zeby dac graczu(om) pancerz.", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dal pancerz wszystkim graczom.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dal pancerz graczu "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}					
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s dal pancerz wszystkim graczom w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}					
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie jest w rundzie.", 0, size);
					}					
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}				
			}
		}	
		case CHAT_CMD_MESSAGE_ROUND_ARMOUR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/rarmour [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')]' zeby przywrocic graczu(om) pancerz.", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s przywrocil pancerz wszystkim graczom.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s przywrocil pancerz graczu "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s przywrocil pancerz wszystkim graczom w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}					
				}				
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie jest w rundzie.", 0, size);
					}					
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}				
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Stan pancerza w rundzie wynosi '0' - nie mozna uzyc komendy.", 0, size);
					}					
				}					
			}
		}
		case CHAT_CMD_MESSAGE_RESTORE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/restore [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')]' zeby uzdrowic gracza(y) i przywrocic pancerz rundy.", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil i przywrocil pancerz wszystkim graczom.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil i przywrocil pancerz graczu "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s uzdrowil i przywrocil pancerz wszystkim graczom w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}					
				}				
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie jest w rundzie.", 0, size);
					}					
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}					
			}
		}		
		case CHAT_CMD_TELEPORT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tp [ID Gracza teleportowanego, 'all' lub indeks druzyny (np. 't:1' lub 't:2')] [ID Gracza celu]'.", 0, size);
					}					
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tpto [ID Gracza]' zeby teleportowac sie do gracza.", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/tphere [ID Gracza]' zeby teleportowac gracza do siebie.", 0, size);
					}					
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub stan gry gracza \"Celu\" nie pozwala na teleportowanie.", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s teleportowal "TEXT_INFO_2"%s"TEXT_INFO_1" do "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}
				}		
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s teleportowal wszystkich do "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s teleportowal wszystkich graczy druzyny "TEXT_INFO_2"%s"TEXT_INFO_1" do "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}
				}					
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub stan gry graczy rozni sie od siebie. Nie mozna uzyc teleportacji.", 0, size);
					}
				}
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}
				}												
			}
		}
		case CHAT_CMD_AFKSET: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/setafk [ID Gracza] [On/Off]' zeby ustawic status 'AFK' gracza.", 0, size);
					}					
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s ustawil status 'AFK' gracza "TEXT_INFO_2"%s"TEXT_INFO_1" na "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub okreslenie statusu do ustawienia.", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_SERVER_LOCK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s "TEXT_INFO_2"zablokowal"TEXT_INFO_1" serwer na nowe polaczenia graczy.", 0, size);
					}					
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s "TEXT_INFO_2"odblokowal"TEXT_INFO_1" serwer na nowe polaczenia graczy.", 0, size);
					}					
				}					
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Serwer zostal automatycznie odblokowany na polaczenia z powodu braku administratora.", 0, size);
					}					
				}				
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Serwer zostal zablokowany na nowe polaczenia.", 0, size);
					}					
				}					
			}
		}
		case CHAT_CMD_MUTE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/mute [ID gracza]' zeby uciszyc gracza na chacie globalnym.", 0, size);
					}					
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/unmute [ID gracza]' zeby pozwolic graczu pisac na chacie globalnym.", 0, size);
					}					
				}					
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz juz jest uciszony.", 0, size);
					}								
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie jest uciszony.", 0, size);
					}								
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s wlaczyl uciszenie dla gracza "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}								
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s wylaczyl uciszenie dla gracza "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}								
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozna uciszyc administratora.", 0, size);
					}								
				}					
			}
		}
		case CHAT_CMD_KICK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						//case LANG_PL: strins(output, " (CMD) Uzyj: '(/k)ick [ID Gracza] <Powod>' zeby wyrzucic gracza z serwera.", 0, size);
						case LANG_PL: strins(output, " (CMD) Uzyj: '(/k)ick [ID Gracza] <Czas w minutach (0-60)> <Powod>' zeby wyrzucic gracza z serwera.", 0, size);
					}					
				}				
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Kick) %s wyrzucil gracza "C_WHITE"%s"C_KICK" z serwera (Czas: %d min.). Powod: "C_WHITE"%s", 0, size);
						//case LANG_PL: strins(output, " (Kick) %s wyrzucil gracza "C_WHITE"%s"C_KICK" z serwera. Powod: "C_WHITE"%s", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub gracz jest administatorem z ranga co najmniej rowna Twojej.", 0, size);
					}					
				}
				/*
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Czas musi zawierac sie w przedziale od 0 do 60 minut.", 0, size);
					}					
				}	
				*/
			}
		}
		case CHAT_CMD_BAN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '(/b)an [ID Gracza] <Czas w godzinach (1-24)> <Powod>' zeby wyrzucic gracza z serwera.", 0, size);
					}					
				}				
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Ban) %s wyrzucil gracza "C_WHITE"%s"C_KICK" z serwera (Czas: %d h.). Powod: "C_WHITE"%s", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub gracz jest administatorem z ranga co najmniej rowna Twojej.", 0, size);
					}					
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Czas musi zawierac sie w przedziale od 1 do 60 godzin.", 0, size);
					}					
				}				
			}
		}		
		case CHAT_CMD_UNBAN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '(/u)n(b)an [Adres IP]' zeby usunac adres z listy banow.", 0, size);
					}					
				}				
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Odbanowales adres "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}				
			}		
		}
		case CHAT_CMD_GMX: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1"zrestartowal gamemoda.", 0, size);
					}
				}
			}			
		}		
		case CHAT_CMD_ADMIN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1"zalogowal sie na konto administratora ("TEXT_INFO_2"%s"TEXT_INFO_1")", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne haslo dostepu do konta administratora.", 0, size);
					}
				}				
			}			
		}
		case CHAT_CMD_MESSAGE_AIM_INFO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status powiadomien o trafionym graczu na: "TEXT_INFO_2"wylaczony"TEXT_INFO_1".", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status powiadomien o trafionym graczu na: "TEXT_INFO_2"wlaczony"TEXT_INFO_1".", 0, size);
					}
				}				
			}			
		}
		case CHAT_CMD_MESSAGE_DMG_INFO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status powiadomien o obrazeniach na: "TEXT_INFO_2"wylaczony"TEXT_INFO_1".", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status powiadomien o obrazeniach na: "TEXT_INFO_2"wlaczony"TEXT_INFO_1".", 0, size);
					}
				}				
			}			
		}		
		case CHAT_CMD_MESSAGE_WEATHER: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/weather [ID Pogody (0-20)]' zeby zmienic pogode na serwerze.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil pogode na serwerze na "TEXT_INFO_2"%d"TEXT_INFO_1".", 0, size);
					}
				}				
			}
		}
		case CHAT_CMD_MESSAGE_WORLD_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/wtime [ID Pogody (0-24)]' zeby zmienic czas na serwerze.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil czas na serwerze na godzine "TEXT_INFO_2"%d"TEXT_INFO_1".", 0, size);
					}
				}				
			}
		}		
		case CHAT_CMD_MESSAGE_GRAVITY: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/gravity [Wartosc (-50 / +50 <Domyslna: 0.008>)]' zeby zmienic grawitacje na serwerze.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil grawitacje na serwerze na "TEXT_INFO_2"%.4f"TEXT_INFO_1".", 0, size);
					}
				}				
			}
		}	
		case CHAT_CMD_MESSAGE_NAMETAGDIS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/nametagdis [Odleglosc (5.0 - 250.0)]' zeby zmienic odleglosc rysowania nickow graczy.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil odleglosc rysowania nickow na "TEXT_INFO_2"%.2f"TEXT_INFO_1".", 0, size);
					}
				}				
			}
		}	
		case CHAT_CMD_MESSAGE_MATCH_ROUNDS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s"TEXT_INFO_1" zmienil ilosc rund meczu na "TEXT_INFO_2"%d"TEXT_INFO_1".", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nowa ilosc rund, jest identyczna z poprzednia.", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nowa ilosc rund musi zawierac sie w przedziale od 1 do 11, oraz musi byc wieksza od sumy dotychczas rozegranych rund.", 0, size);
					}				
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: /mrounds [Ilosc rund (1 - 11)].", 0, size);
					}					
				}
			}
		}
		case CHAT_CMD_MESSAGE_EYE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Eye) "TEXT_INFO_2"%s"TEXT_INFO_1" wpisal komende: "TEXT_INFO_2"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Zmieniles status podgladu komend na: "TEXT_INFO_2"%s", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Eye) "TEXT_INFO_2"%s"TEXT_INFO_1" wpisal niepoprawna komende: "TEXT_INFO_2"%s", 0, size);
					}
				}				
			}
		}
		case CHAT_CMD_MESSAGE_C_ADD: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Uzyj: '/cadd [ID Gracza (Dodanie go po wczesniejszym scrashowaniu) lub brak parametru]'.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Druzyna gracza nie jest taka sama jak po opuszczeniu serwera.", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Stan gry wybranego gracza niepozwala na dodanie go do rundy.", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Wybrane ID gracza jest nieuzywane.", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Komenda dziala wylacznie w trakcie trwania rundy.", 0, size);
					}
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Wybrany gracz nie zostal scrashowany w trakcie tej rundy.", 0, size);
					}
				}			
			}		
		}
		case CHAT_CMD_INVALID_COMMAND: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wpisana komenda jest niepoprawna: "C_WHITE"%s", 0, size);
					}
				}								
			}			
		}
		case CHAT_CMD_LABO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/labo [on/off]' zeby wlaczyc, badz wylaczyc obiekty w bazie wojskowej.", 0, size);
					}
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) %s ustawil status obiektow w bazie wojskowej na: "C_LIGHTGREEN"Wlaczone", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) %s ustawil status obiektow w bazie wojskowej na: "C_KICK"Wylaczone", 0, size);
					}				
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Obiekty w bazie wojskowej nie sa wlaczone.", 0, size);
					}				
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Obiekty w bazie wojskowej sa juz wlaczone.", 0, size);
					}				
				}					
			}			
		}		
		case CHAT_CMD_FIX_VEHICLE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie jestes w pojezdzie lub nie jestes kierowca.", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Ustawienia gamemoda nie pozwalaja na naprawe pojazdow w trakcie rundy.", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Veh-Fix) Naprawiles swoj pojazd.", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Veh-Fix) "TEXT_INFO_2"%s"TEXT_INFO_1" naprawil swoj pojazd.", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz jeszcze zaczekac %d sekund zeby moc ponownie uzyc komendy.", 0, size);
					}
				}					
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (Veh-Fix) "TEXT_INFO_2"%s"TEXT_INFO_1" naprawil wszystkie uzywane pojazdy bedace w rundzie.", 0, size);
					}					
				}
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (Veh-Fix) "TEXT_INFO_2"%s"TEXT_INFO_1" naprawil pojazd gracza "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}					
				}		
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrany gracz nie jest w pojezdzie, lub nie jest jego kierowca.", 0, size);
					}					
				}	
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza, lub gracz nie bierze udzialu w rundzie.", 0, size);
					}					
				}	
				case 9: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/fv [\"all\" lub ID gracza]' zeby naprawic pojazd wybranej osoby.", 0, size);
					}					
				}		
				case 10: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Komenda dostepna tylko w trakcie trwania trybu \"Bazy\".", 0, size);
					}					
				}					
			}
		}
		case CHAT_CMD_DESTROY_VEHICLE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID modelu pojazdu lub jego nazwa.", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/dv [\"all\", ID modelu lub nazwa pojazdu]' zeby usunac nieuzywane pojazdy rundy.", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Des-Veh) "TEXT_INFO_2"%s"TEXT_INFO_1" usunal wszystkie nieuzywane pojazdy. Usunieto: %d pojazdow", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Des-Veh) "TEXT_INFO_2"%s"TEXT_INFO_1" usunal wszystkie pojazdy o nazwie "TEXT_INFO_2"%s"TEXT_INFO_1" (Model: %d). Usunieto: %d pojazdy(ow).", 0, size);
					}
				}					
			}
		}
		case CHAT_CMD_MESSAGE_SPEC_LIST: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status listy obserwujacych na: "TEXT_INFO_2"wylaczony"TEXT_INFO_1".", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ustawiles status listy obserwujacych na: "TEXT_INFO_2"wlaczony"TEXT_INFO_1".", 0, size);
					}
				}				
			}			
		}	
		case CHAT_CMD_MESSAGE_NETCHECK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj: '/netcheck [ID Gracza do sprawdzenia, badz zmiany statusu] [(FPS/Ping/PLoss) lub brak parametru]'.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawne ID gracza lub gracz jest offline.", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (NetCheck) %s ustawil status testu '"TEXT_INFO_2"%s"TEXT_INFO_1"' dla gracza "TEXT_INFO_2"%s"TEXT_INFO_1" na: %s%s", 0, size);
					}					
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Podpowiedz) Uzyj '"TEXT_INFO_2"/mynetcheck (ID gracza lub brak parametru)"TEXT_INFO_1"' zeby sprawdzic aktualny stan swoich testow.", 0, size);
					}					
				}				
			}
		}
		case CHAT_CMD_MESSAGE_SET_HP: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) Uzyj: '/sethp [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')] [Wartosc HP (1-100)]'.", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) %s zmienil stan zdrowia wszystkich graczy na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) %s zmienil stan zdrowia gracza "TEXT_INFO_2"%s"TEXT_INFO_1" na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) %s zmienil stan zdrowia wszystkich graczy w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"' na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) Niepoprawne ID gracza lub gracz jest Off-Line.", 0, size);
					}
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (Set HP) Wartosc zdrowia musi byc w przedziale od '1' do '100'.", 0, size);
					}
				}								
			}
		}
		case CHAT_CMD_MESSAGE_SET_ARMOUR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) Uzyj: '/setarmour [ID Gracza, 'all' lub indeks druzyny (np. 't:1' lub 't:2')] [Wartosc pancerza (0-100)]'.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) %s zmienil stan pancerza wszystkich graczy na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) %s zmienil stan pancerza gracza "TEXT_INFO_2"%s"TEXT_INFO_1" na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) %s zmienil stan pancerza wszystkich graczy w druzynie '"TEXT_INFO_2"%s"TEXT_INFO_1"' na '"TEXT_INFO_2"%d"TEXT_INFO_1"'.", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) Niepoprawne ID gracza lub gracz jest Off-Line.", 0, size);
					}
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub indeks druzyny.", 0, size);
					}					
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (Set Armour) Wartosc pancerza musi byc w przedziale od '0' do '100'.", 0, size);
					}
				}					
			}
		}
		case CHAT_CMD_MESSAGE_RESTORE_MATCH: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Match Restore) %s przywrocil rezultaty niedokonczonego meczu.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Match Restore) W pamieci nie znajduje sie zaden niedokonczony mecz.", 0, size);
					}
				}
			}
		}
		case CHAT_CMD_MESSAGE_TEAM_COLOR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
					//	case LANG_PL: strins(output, " (CMD) Uzyj: '/tpwd [Team ID (1, 2 lub 3)] [Haslo (Uzyj 0 zeby zresetowac lub 1000 do 9999 zeby ustawic)]'", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil kolor druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"' na %sPROBKA", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil kolorami druzyny '"TEXT_INFO_2"%s"TEXT_INFO_1"' i '"TEXT_INFO_2"%s"TEXT_INFO_1"'.", 0, size);
					}
				}				
			}
		}
	}
}

//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	CHAT_MESSAGE_TEAM_JOIN					0
#define	CHAT_MESSAGE_TEAM_SWITCH				1
#define CHAT_MESSAGE_AUTOSWAP					2
#define	CHAT_MESSAGE_ENDROUND					3
#define	CHAT_MESSAGE_ENDROUND_REASON			4
#define CHAT_MESSAGE_ZONE_ERROR					5
#define	CHAT_MESSAGE_VEHICLE_SPAWN				6
#define	CHAT_MESSAGE_WEAPON_SELECT				7
#define	CHAT_MESSAGE_SPAWN_PROTECT				8
#define CHAT_MESSAGE_CHATLOCK					9
#define CHAT_MESSAGE_CONNECT_DISCONNECT			10
#define	CHAT_MESSAGE_SELFKILL					11
#define	CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN		12
#define	CHAT_MESSAGE_COMPILE_PLAYER_LIMIT		13
#define	CHAT_MESSAGE_PROTECTOR					14
#define CHAT_MESSAGE_RCON_LOGIN					15
#define	CHAT_MESSAGE_ROUND_SETTING_INFO			16
#define CHAT_MESSAGE_HTTP_NEW_VERSION			17
#define	CHAT_MESSAGE_HTTP_MATCH_RESPONSE		18
#define	CHAT_MESSAGE_DEATH_INFO					19
#define	CHAT_MESSAGE_USE_JETPACK				20
#define	CHAT_MESSAGE_WELCOME					21
#define CHAT_MESSAGE_MATCH_END					22
#define	CHAT_MESSAGE_CRASH_ADD					23
#define CHAT_MESSAGE_ANTI_FALL_PROTECT			24
#define CHAT_MESSAGE_ADMIN						25
#define	CHAT_MESSAGE_OLD_WEAPONS				26	
//==============================================================================
getChatMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case CHAT_MESSAGE_TEAM_JOIN: {
			switch(language) {
				case LANG_PL: strins(output, " (Join) Gracz %s%s%s dolaczyl do druzyny %s%s", 0, size);
			}
		}
		case CHAT_MESSAGE_TEAM_SWITCH: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Switch) Gracz %s%s%s zmienil druzyne na %s%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Switch) Administrator zmienil druzyne gracza %s%s%s na %s%s", 0, size);
					}				
				}
			}
		}		
		case CHAT_MESSAGE_AUTOSWAP: {
			switch(language) {
				case LANG_PL: strins(output, " (Auto-Swap) Druzyny zostaly automatycznie zamienione (Zmiana skina: "TEXT_INFO_2"%s"TEXT_INFO_1")", 0, size);
			}
		}
		case CHAT_MESSAGE_ENDROUND: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Runda) Runda dobiegla konca ("TEXT_INFO_2"%s "TEXT_INFO_1"| Runda: "TEXT_INFO_2"%d "TEXT_INFO_1")", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Runda) Runda dobiegla konca ("TEXT_INFO_2"%s "TEXT_INFO_1"| Runda: "TEXT_INFO_2"%d / %d "TEXT_INFO_1")", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Runda) Wygrywa druzyna '"TEXT_INFO_2"%s"TEXT_INFO_1"' ("TEXT_INFO_2"%s"TEXT_INFO_1")", 0, size);
					}							
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Runda) Runda zakonczyla sie remisem.", 0, size);
					}							
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Uzyj '"TEXT_INFO_2"(/hi)de"TEXT_INFO_1"' zeby ukryc tabele wynikow.", 0, size);
					}							
				}		
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Uzyj '"TEXT_INFO_2"/lastround"TEXT_INFO_1"' zeby ponownie wyswietlic tabele wynikow.", 0, size);
					}							
				}				
			}
		}
		case CHAT_MESSAGE_ENDROUND_REASON: {
			switch(msg_subindex) {
				case WIN_REASON_DEFEND_BASE: {
					switch(language) {
						case LANG_PL: strins(output, "Obrona bazy", 0, size);
					}
				}
				case WIN_REASON_TAKEOVER_BASE: {
					switch(language) {
						case LANG_PL: strins(output, "Przejecie bazy", 0, size);
					}
				}
				case WIN_REASON_PLAYER_ADVANTAGE: {
					switch(language) {
						case LANG_PL: strins(output, "Przewaga graczy", 0, size);
					}
				}
				case WIN_REASON_HEALTH_ADVANTAGE: {
					switch(language) {
						case LANG_PL: strins(output, "Przewaga HP (+Armor)", 0, size);
					}
				}	
				case WIN_REASON_ENEMY_DEFEAT: {
					switch(language) {
						case LANG_PL: strins(output, "Pokonanie przeciwnika", 0, size);
					}
				}			
				case WIN_REASON_NO_DEFENDERS: {
					switch(language) {
						case LANG_PL: strins(output, "Obroncy poza baza", 0, size);
					}				
				}
				case WIN_REASON_POINTS_LIMIT: {
					switch(language) {
						case LANG_PL: strins(output, "Limit punktow", 0, size);
					}				
				}
			}
		}	
		case CHAT_MESSAGE_ZONE_ERROR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Obszar) Gracz '"TEXT_INFO_2"%s"TEXT_INFO_1"' zostal zrespawnowany z powodu wyjscia poza tekstury mapy.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Obszar) Gracz '"TEXT_INFO_2"%s"TEXT_INFO_1"' zostal zrespawnowany z powodu braku poprawnej pozycji.", 0, size);
					}				
				}
			}
		}
		case CHAT_MESSAGE_VEHICLE_SPAWN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Pojazd) Zespawnowales '"TEXT_INFO_2"%s"TEXT_INFO_1"' (Model: "TEXT_INFO_2"%d"TEXT_INFO_1")", 0, size);
					}
				} case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Pojazd) Niepoprawna nazwa lub ID modelu pojazdu.", 0, size);
					}				
				} case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Pojazd) Musisz wrocic na obszar spawnu druzyny atakujacej zeby zespawnowac pojazd.", 0, size);
					}				
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz nieco sie odsunac od innych graczy, zeby uniknac zakleszczenia pojazdow.", 0, size);
					}
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrany pojazd jest wylaczony z uzytku w trakcie rund.", 0, size);
					}				
				}
			}
		}			
		case CHAT_MESSAGE_WEAPON_SELECT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Bron) "TEXT_WEAPON_INFO_2"%s"TEXT_WEAPON_INFO_1" wybral zestaw '"TEXT_WEAPON_INFO_2"%s  (%d)"TEXT_WEAPON_INFO_1"' i '"TEXT_WEAPON_INFO_2"%s  (%d)"TEXT_WEAPON_INFO_1"'.", 0, size);
					}
				}		
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Bron) Niewybrales zadnego zestawu broni. Mozesz do niego wrocic komenda '/gun'.", 0, size);
					}						
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Bron) "TEXT_WEAPON_INFO_2"%s"TEXT_WEAPON_INFO_1" wybral zestaw '"TEXT_WEAPON_INFO_2"%s"TEXT_WEAPON_INFO_1"'.", 0, size);
					}					
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Bron) "TEXT_WEAPON_INFO_2"%s"TEXT_WEAPON_INFO_1" nie wybral zadnego zestawu broni.", 0, size);
					}						
				}
			}		
		}
		case CHAT_MESSAGE_SPAWN_PROTECT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (First Blood) "TEXT_SPAWN_PROTECT_INFO_2"%s"TEXT_SPAWN_PROTECT_INFO_1" przelal pierwsza krew gracza "TEXT_SPAWN_PROTECT_INFO_2"%s"TEXT_SPAWN_PROTECT_INFO_1".", 0, size);
					}
				}
			}		
		}		
		case CHAT_MESSAGE_CHATLOCK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Chat) Chat zostal wylaczony. Uzyj symboli '!tekst' zeby pisac na teamchacie lub '@tekst' zeby wyslac wiadomosc do arbitrow.", 0, size);
					}
				}
			}		
		}		
		case CHAT_MESSAGE_CONNECT_DISCONNECT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Connect) Gracz "TEXT_CONNECT_2"%s"TEXT_CONNECT_1" dolaczyl do gry (ID: "TEXT_CONNECT_2"%d"TEXT_CONNECT_1")", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Connect) Gracz "TEXT_CONNECT_2"%s"TEXT_CONNECT_1" dolaczyl do gry (ID: "TEXT_CONNECT_2"%d"TEXT_CONNECT_1" | IP: "TEXT_CONNECT_2"%s"TEXT_CONNECT_1")", 0, size);
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Disconnect) Gracz "TEXT_CONNECT_2"%s"TEXT_CONNECT_1" opuscil serwer (Druzyna: %s%s"TEXT_CONNECT_1" | "TEXT_CONNECT_2"%s"TEXT_CONNECT_1")", 0, size);
					}				
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Disconnect) Gracz opuscil serwer w trakcie gry (Zdrowie: "TEXT_CONNECT_2"%.1f "TEXT_CONNECT_1"("TEXT_CONNECT_2"%.1f"TEXT_CONNECT_1"))", 0, size);
					}				
				}						
			}
		}
		case CHAT_MESSAGE_SELFKILL: {
			switch(language) {
				case LANG_PL: strins(output, " (Info) Gracz "TEXT_INFO_2"%s"TEXT_INFO_1" popelnil samobojstwo.", 0, size);
			}					
		}
		case CHAT_MESSAGE_LOBBY_VEHICLE_SPAWN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Pojazd) Zespawnowales '"TEXT_INFO_2"%s"TEXT_INFO_1"' (Model: "TEXT_INFO_2"%d"TEXT_INFO_1")", 0, size);
					}
				} case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Niepoprawna nazwa lub ID modelu pojazdu.", 0, size);
					}				
				} case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Musisz byc w obszarze lobby, zeby moc uzyc komendy.", 0, size);
					}				
				} case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Nie mozna spawnowac pojazdow wewnatrz budynkow.", 0, size);
					}				
				} case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Ustawienia zabraniaja spawnowania pojazdow w poczekalni.", 0, size);
					}				
				} case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Wybrany pojazd jest wylaczony z uzytku w obszarze lobby.", 0, size);
					}						
				}
				
			}
		}	
		case CHAT_MESSAGE_COMPILE_PLAYER_LIMIT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Wersja gamemoda uzywana na serwerze, nie obsluguje tak wysokich ID graczy.", 0, size);
					}
				}
			}
		}
		case CHAT_MESSAGE_PROTECTOR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) Otrzymales ostrzezenie za przekroczenie limitu '"C_WHITE"%s"C_KICK"' (Limit: %d | Twoj rezultat: %d). Ostrzezenie "C_WHITE"%d/%d", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) Otrzymales ostrzezenie za przekroczenie limitu '"C_WHITE"P-Loss"C_KICK"' (Limit: %.1f | Twoj rezultat: %.1f). Ostr. "C_WHITE"%d/%d", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) "C_WHITE"%s "C_KICK"zostal wyrzucony za przekroczenie limitu '"C_WHITE"%s"C_KICK"' (Limit: %d | Rezultat: %d)", 0, size);
					}
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) "C_WHITE"%s "C_KICK"zostal wyrzucony za przekroczenie limitu '"C_WHITE"P-Loss"C_KICK"' (Limit: %.1f | Rezultat: %.1f)", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) "C_WHITE"%s "C_KICK"otrzymal ostrzezenie za przekroczenie limitu '"C_WHITE"%s"C_KICK"' (Limit: %d | Rezultat: %d)", 0, size);
					}
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (Ostrzezenie) "C_WHITE"%s "C_KICK"otrzymal ostrzezenie za przekroczenie limitu '"C_WHITE"P-Loss"C_KICK"' (Limit: %.1f | Rezultat: %.1f)", 0, size);
					}
				}	
				
			}
		}
		case CHAT_MESSAGE_RCON_LOGIN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s "TEXT_INFO_1"zalogowal(a) sie na konto RCON.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Ilosc slotow serwera przekracza mozliwosci gamemoda (Server: "C_WHITE"%d"C_KICK" | Gamemod: "C_WHITE"%d"C_KICK"). Zaktualizuj wersje!", 0, size);
					}				
				}
			}
		}
		case CHAT_MESSAGE_ROUND_SETTING_INFO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil stan ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na: "C_KICK"Wylaczone", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil stan ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na: "C_LIGHTGREEN"Wlaczone", 0, size);
					}					
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil wartosc ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na: "C_WHITE"%d", 0, size);
					}					
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil wartosc ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na: "C_WHITE"%.1f", 0, size);
					}					
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) %s zmienil stan ustawienia '"TEXT_INFO_2"%s"TEXT_INFO_1"' na: "C_WHITE"%s", 0, size);
					}
				}				
			}		
		}
		case CHAT_MESSAGE_HTTP_NEW_VERSION: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Jest dostepna nowa wersja ("TEXT_INFO_2"%s"TEXT_INFO_1") do sciagniecia na stronie"TEXT_INFO_2" "HTTP_ADDRESS, 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Nie ma nowszej wersji do sciagniecia.", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Wyslano pytanie o wersje. Trwa oczekiwanie na odpowiedz z serwera.", 0, size);
					}
				}				
			}
		}
		case CHAT_MESSAGE_HTTP_MATCH_RESPONSE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Wyniki meczu mozesz zobaczyc na stronie '"TEXT_INFO_2""HTTP_MATCH_RESULTS"?id=%d"TEXT_INFO_1"'.", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Trwa przygotowanie i wysylanie wynikow na serwer (to moze zajac chwilke).", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Serwer WWW odrzucil polaczenie. Moze to oznaczac problemy z serwerem, lub przekroczenie limitu danych.", 0, size);
					}
				}						
			}
		}
		case CHAT_MESSAGE_DEATH_INFO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Death) %s%s"TEXT_INFO_1" zostal zabity przez %s%s"TEXT_INFO_1" ("TEXT_INFO_2"%s"TEXT_INFO_1")", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Death) %s%s"TEXT_INFO_1" popelnil samobojstwo.", 0, size);
					}
				}				
			}		
		}
		case CHAT_MESSAGE_USE_JETPACK: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) "TEXT_INFO_2"%s"TEXT_INFO_1" uzywa jetpack'a.", 0, size);
					}
				}			
			}				
		}
		case CHAT_MESSAGE_WELCOME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " * Multi A/D ("TEXT_INFO_2""_VERSION""TEXT_INFO_1") by AxL ", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '"TEXT_INFO_2"/help"TEXT_INFO_1"' zeby otrzymac pomoc.", 0, size);
					}
				}			
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (CMD) Uzyj '"TEXT_INFO_2"/me"TEXT_INFO_1"' zeby skonfigurowac ustawienia prywatne.", 0, size);
					}
				}					
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Jesli masz jakies sugestie lub jakiekolwiek problemy z gamemodem, zapraszamy", 0, size);
					}
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, "    na oficjalne forum znajdujace sie pod adresem "TEXT_INFO_2"www.HighSkill.eu", 0, size);
					}
				}					
			}				
		}
		case CHAT_MESSAGE_MATCH_END: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Info) Uzyj '"TEXT_INFO_2"/lastmatch"TEXT_INFO_1"' zeby ponownie wyswietlic tabele wynikow.", 0, size);
					}
				}	
			}
		}
		case CHAT_MESSAGE_CRASH_ADD: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) %s dodal do walki gracza "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1"na miejsce "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1"(Druzyna: "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1")", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Do rundy nie dodano wszystkich graczy, ktorzy opuscili ja w trakcie trwania. Oczekiwanie na decyzje administratora...", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Wpisz '"TEXT_INFO_2"/cadd"TEXT_INFO_1"' zeby zobaczyc liste niedodanych graczy lub '"TEXT_INFO_2"/pause"TEXT_INFO_1"' zeby zakonczyc runde.", 0, size);
					}
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Na serwerze nie ma administratora. Przerwano dzialanie...", 0, size);
					}
				}
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) Runda zostala automatycznie zatrzymana z powodu opuszczenia serwera przez "TEXT_INFO_2"%s"TEXT_INFO_1".", 0, size);
					}
				}		
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1" zostal automatycznie dodany do rundy po crashu (Druzyna: "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1")", 0, size);
					}
				}					
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, " (C-Add) "TEXT_ADD_REMOVE_INFO_2"%s"TEXT_ADD_REMOVE_INFO_1" zadecydowal, zeby zakonczyc runde.", 0, size);
					}
				}									
			}		
		}
		case CHAT_MESSAGE_ANTI_FALL_PROTECT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Anti Fall) "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1"zginal w wyniku upadku podczas trwania ochrony. Gracz zostanie automatycznie dodany po spawnie.", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Anti Fall) "TEXT_ADD_REMOVE_INFO_2"%s "TEXT_ADD_REMOVE_INFO_1"zostal automatycznie dodany do rundy po smierci.", 0, size);
					}
				}						
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, " (Anti Fall) Zostales automatycznie uzdrowiony po upadku w trakcie trwania ochrony.", 0, size);
					}
				}			
			}			
		}
		case CHAT_MESSAGE_ADMIN: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Admin) Nie posiadasz odpowiedniego poziomu praw administratora do uzycia tej funkcji.", 0, size);
					}
				}		
			}			
		}
		case CHAT_MESSAGE_OLD_WEAPONS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, " (Old-Weapons) Przywrociles bronie uzywane w poprzedniej rundzie.", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, " (Old-Weapons) Nie mozna przywrocic broni uzywanych w poprzedniej rundzie. Wybierz nowe!", 0, size);
					}
				}					
			}	
		}		
	}
}

//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	DIALOG_CAPTION_SWITCH_MENU				0
#define	DIALOG_CAPTION_PASSWORD					1
#define DIALOG_CAPTION_VEHICLES					2
#define DIALOG_CAPTION_WEAPONS					3
#define DIALOG_CAPTION_RS						4
#define	DIALOG_CAPTION_PLAYER_SETTINGS			5
#define	DIALOG_CAPTION_TEAM_SETTINGS			6
#define	DIALOG_CAPTION_ROUND_SETTINGS			7
#define	DIALOG_CAPTION_MATCH_RESTORE			8
//==============================================================================
getDialogCaptionMessage(msg_index, language = -1) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	static output[64];
	output[0] = EOS;
	switch(msg_index) {
		case DIALOG_CAPTION_SWITCH_MENU: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Zmiana druzyny", 0);
			}
		}	
		case DIALOG_CAPTION_PASSWORD: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Haslo druzyny", 0);
			}
		}	
		case DIALOG_CAPTION_VEHICLES: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Wybor pojazdu", 0);
			}
		}	
		case DIALOG_CAPTION_WEAPONS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Wybor broni", 0);
			}
		}	
		case DIALOG_CAPTION_RS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia rozgrywki", 0);
			}
		}	
		case DIALOG_CAPTION_PLAYER_SETTINGS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia gracza", 0);
			}
		}		
		case DIALOG_CAPTION_TEAM_SETTINGS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia druzyn", 0);
			}
		}	
		case DIALOG_CAPTION_ROUND_SETTINGS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia rundy", 0);
			}
		}		
		case DIALOG_CAPTION_MATCH_RESTORE: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Niedokonczony mecz", 0);
			}			
		}
	}
	return output;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	DIALOG_BODY_PASSWORD						0
#define	DIALOG_BODY_VEHICLE_TYPES					1
#define	DIALOG_BODY_WEAPON_SETS_MENU				2
#define DIALOG_BODY_FREECHOOSE_MENU					3
#define	DIALOG_BODY_MATCH_ROUNDS					4
#define DIALOG_BODY_MATCH_RS						5
#define DIALOG_BODY_PLAYER_SETTINGS					6
#define	DIALOG_BODY_TEAM_SETTINGS					7
#define	DIALOG_BODY_ROUND_SETTINGS					8
#define	DIALOG_BODY_ROUND_BASE_TIME					9
#define	DIALOG_BODY_ROUND_ARENA_TIME				10
#define	DIALOG_BODY_ROUND_CHECKPOINT_TIME			11
#define	DIALOG_BODY_ROUND_SPAWNPROTECT_TIME			12
#define	DIALOG_BODY_ROUND_DEFBASE_TIME				13
#define	DIALOG_BODY_ROUND_ARMOUR					14
#define	DIALOG_BODY_PROTECTOR_MAX_PING_VALUE		15
#define	DIALOG_BODY_PROTECTOR_MIN_FPS_VALUE			16
#define	DIALOG_BODY_PROTECTOR_MAX_PLOSS_VALUE		17
#define	DIALOG_BODY_PROTECTOR_WARNINGS				18
#define	DIALOG_BODY_FWEAPONS_INFO					19
#define DIALOG_BODY_SCOREBOARD_MENU					20
#define DIALOG_BODY_CRASH_LIST						21
#define DIALOG_BODY_CMD_GUN_TIME					22
#define	DIALOG_BODY_SPAWNPROTECT_MENU				23
#define	DIALOG_BODY_CHECKPOINT_MENU					24
#define	DIALOG_BODY_FIX_VEHICLE_MENU				25
#define DIALOG_BODY_OLD_WEAPONS						26
#define	DIALOG_BODY_ROUND_ARENA_TDM_POINTS_LIMIT	27
#define DIALOG_BODY_ANTYMACRO_SETTINGS				28
#define DIALOG_BODY_MATCH_RESTORE					29
//==============================================================================
getDialogBodyMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case DIALOG_BODY_PASSWORD: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj haslo druzyny zeby moc dolaczyc.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawne haslo druzyny.", 0, size);
					}
				}		
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "Podane haslo jest poprawne! Mozesz sie zespawnowac.", 0, size);
					}
				}						
			}
		}	
		case DIALOG_BODY_VEHICLE_TYPES: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, COLOR_DIALOG_BODY"Kabriolety\n"COLOR_DIALOG_BODY"Lowridery\n"COLOR_DIALOG_BODY"Sportowe\n"COLOR_DIALOG_BODY"Kombi\n"COLOR_DIALOG_BODY"Zwykle", 0, size);
							strins(output, COLOR_DIALOG_BODY"Motory\n"COLOR_DIALOG_BODY"Lodzie\n"COLOR_DIALOG_BODY"Smiglowce\n"COLOR_DIALOG_BODY"Samoloty\n"COLOR_DIALOG_BODY"Przemyslowe\n"COLOR_DIALOG_BODY"Offroad\n"COLOR_DIALOG_BODY"Sluzby publiczne\n", 0, size);
						}
					}	
				} 
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Brak pojazdow w tej kategorii", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Na tej bazie nie mozna spawnowac lodzi", 0, size);
					}
				}				
			}
		}
		case DIALOG_BODY_WEAPON_SETS_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Nazwa broni (Amunicja)\tNazwa broni (Amunicja)\tMax. zestawow w druzynie", 0, size);		
					}	
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Brak zestawow broni, mozliwych do wybrania.", 0, size);		
					}	
				}
			}
		}
		case DIALOG_BODY_FREECHOOSE_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_HEAD"\t\t\t<< Wroc do poprzedniego <<", 0, size);		
					}	
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Brak broni, mozliwych do wybrania.", 0, size);		
					}	
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "Nazwa broni\tAmunicja\tMax. zestawow w druzynie", 0, size);	
					}
				}
			}
		}
		case DIALOG_BODY_MATCH_ROUNDS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Do tej pory, nie rozegrano zadnej rundy.", 0, size);		
					}	
				}
			}
		}
		case DIALOG_BODY_MATCH_RS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, "\n"COLOR_DIALOG_BODY"Max ping: "C_WHITE"%d\n"COLOR_DIALOG_BODY"Min FPS: "C_WHITE"%d\n"COLOR_DIALOG_BODY"Max P-Loss: "C_WHITE"%.1f%%\n"COLOR_DIALOG_BODY"Scoreboard: "C_WHITE"%s", 0, size);
							strins(output, "\n"COLOR_DIALOG_BODY"Tryb wyboru broni: "C_WHITE"%s\n"COLOR_DIALOG_BODY"Ochrona poczatkowa: "C_WHITE"%d sek.\n"COLOR_DIALOG_BODY"Anti Fall Protect: %s\n"COLOR_DIALOG_BODY"First blood: %s\n"COLOR_DIALOG_BODY"Respawn przy spadaniu: %s\n"COLOR_DIALOG_BODY"Slidebug: %s\n"COLOR_DIALOG_BODY"Fast shoot: %s\n"COLOR_DIALOG_BODY"C-Bug: %s", 0, size);		
							strins(output, COLOR_DIALOG_BODY"Czas aren: "C_WHITE"%d min.\n"COLOR_DIALOG_BODY"Czas baz: "C_WHITE"%d min.\n"COLOR_DIALOG_BODY"Przejecie checkpointa: %s "C_WHITE"(%d sek.)\n"COLOR_DIALOG_BODY"Obronca anuluje przejecie: %s\n"COLOR_DIALOG_BODY"Przejecie w pojezdzie: %s\n"COLOR_DIALOG_BODY"Tryb aren: "C_WHITE"%s\n"COLOR_DIALOG_BODY"Obszar baz: %s "C_WHITE"(%d sek.)\n"COLOR_DIALOG_BODY"Pancerz: "C_WHITE"%.0f", 0, size);
						}
					}	
				}
			}
		}
		case DIALOG_BODY_PLAYER_SETTINGS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, "%sPrywatne wiadomosci\n%sStatus AFK\n%sInfo. o trafionym\n%sPowiadomienia trafienia\n%sLista obserwujacych", 0, size);
						}
					}	
				}
				case 1: {
					switch(language) {
						case LANG_PL: {
							strins(output, "%sPrywatne wiadomosci\n%sStatus AFK\n%sInfo. o trafionym\n%sPowiadomienia trafienia\n%sLista obserwujacych\n%sPauza na przycisk (\"Y\")", 0, size);
						}
					}	
				}					
				case 2: {
					switch(language) {
						case LANG_PL: {
							strins(output, "%sPrywatne wiadomosci\n%sStatus AFK\n%sInfo. o trafionym\n%sPowiadomienia trafienia\n%sLista obserwujacych\n%sPauza na przycisk (\"Y\")\n%sPodglad komend graczy (Eye)\n"COLOR_DIALOG_BODY"Eye: %sPodglad niepoprawnie wpisanych komend", 0, size);
						}
					}	
				}				
			}		
		}
		case DIALOG_BODY_TEAM_SETTINGS: {
			switch(msg_subindex) {
				case 0: {
				//	switch(language) {
				//		case LANG_PL: strins(output, "Ustawienia druzyn", 0, size);
				//	}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Nazwa druzyny\n%s%s\n%s%s\n%s%s", 0, size);
					}
				}	
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Nazwa\t%s\n"COLOR_DIALOG_BODY"Skin\t%d\n"COLOR_DIALOG_BODY"Haslo:\t%d\n"COLOR_DIALOG_BODY"Kolor\t%sProbka", 0, size);
					}
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ID nowego skina (Przedzial: 0 - 299)\n\n%s", 0, size);
					}
				}		
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawne ID skina lub skin jest w uzyciu", 0, size);
					}
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj nowa nazwe druzyny\n\n%s", 0, size);
					}
				}		
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna nazwa lub nazwa jest w uzyciu", 0, size);
					}
				}
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Haslo musi byc w przedziale od 1000 do 9999 lub 0 (usuniecie hasla)", 0, size);
					}
				}	
				case 8: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawne haslo", 0, size);
					}
				}			
				case 9: {
					switch(language) {
						case LANG_PL: strins(output, "%sW grze   %sLobby   %sAFK", 0, size);
					}					
				}
				case 10: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Ten kolor jest uzywany przez druzyne "C_WHITE"%s"COLOR_DIALOG_BODY".\nCzy chcesz zamienic kolory druzyn?", 0, size);
					}					
				}
			}
		}		
		case DIALOG_BODY_ROUND_SETTINGS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, COLOR_DIALOG_BODY"Arena: Tryb wygranej\t%s\n"COLOR_DIALOG_BODY"AutoSwap\t%s\n%sRespawn przy spadaniu\n%sMozliwosc samodzielnego usuniecia sie z rundy\n%sObiekty bazy wojskowej (laboratorium)\n%sSamodzielna naprawa pojazdow (/fv)\n"COLOR_DIALOG_BODY"Min. czas oczekiwania na uzycie komendy '/fv'\t%d sek.", 0, size);
							strins(output, 
								"%s1 on 1 - Znaczniki na arenach\n%sObroncy bazy\n"COLOR_DIALOG_BODY"Obroncy bazy: Czas\t%d\n"COLOR_DIALOG_BODY"Kamizelka podczas rund\t%.1f\n", 
							0, size);
							strins(output, 
								COLOR_DIALOG_BODY"Ustawienia pojazdow\n"COLOR_DIALOG_BODY"Ustawienia SpawnProtect\n"COLOR_DIALOG_BODY"Ustawienia Checkpoint'a\n"COLOR_DIALOG_BODY"Ustawienia broni\t%s\n"COLOR_DIALOG_BODY"Czas trwania baz\t%d min.\n"COLOR_DIALOG_BODY"Czas trwania aren\t%d min.\n"COLOR_DIALOG_BODY"Limit punktow (Arena TDM)\t%d\n", 
							0, size);		
							strins(output, 
								"Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Ustawienia 'Crash Add'\n", 
							0, size);								
						}
					}			
				}		
			}	
		}
		case DIALOG_BODY_ROUND_BASE_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas trwania baz w przedziale od 3 do 60 minut.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawny czas trwania baz.", 0, size);
					}			
				}
			}
		}
		case DIALOG_BODY_ROUND_ARENA_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas trwania aren w przedziale od 3 do 60 minut.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawny czas trwania aren.", 0, size);
					}			
				}
			}
		}		
		case DIALOG_BODY_ROUND_CHECKPOINT_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas przejecia checkpointa w przedziale od 5 do 120 sekund.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawny czas przejecia checkpointa.", 0, size);
					}			
				}
			}			
		}	
		case DIALOG_BODY_ROUND_SPAWNPROTECT_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas trwania ochrony \"Spawn Protect\" w przedziale od 0 do 120 sekund.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawny czas trwania ochrony.", 0, size);
					}			
				}
			}				
		}						
		case DIALOG_BODY_ROUND_DEFBASE_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas trwania, jaki obroncy beda mieli na powrot do bazy\nw przypadku kiedy nikt z nich nie pozostanie w jej obszarze\nw momencie kiedy zaatakuje przeciwna druzyna.\nCzas musi zawierac sie w przedziale od 10 do 60 sekund.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawny czas na powrot do bazy.", 0, size);
					}			
				}
			}				
		}		
		case DIALOG_BODY_ROUND_ARMOUR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj wartosc pancerza jaka maja miec gracze po\nstarcie rundy w przedziale od 0 do 100 jednostek.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc pancerza.", 0, size);
					}			
				}
			}				
		}		
		case DIALOG_BODY_PROTECTOR_MAX_PING_VALUE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj maksymalna wartosc pingu po przekroczeniu, ktorej gracz otrzyma ostrzezenie.\nWartosc pingu musi zawierac sie w przedziale od 10 do 9999 jednostek.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc maksymalnego pingu.", 0, size);
					}			
				}
			}				
		}		
		case DIALOG_BODY_PROTECTOR_MIN_FPS_VALUE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj minimalna wartosc FPS'ow po przekroczeniu, ktorej gracz otrzyma ostrzezenie.\nWartosc FPS'ow musi zawierac sie w przedziale od 1 do 89 jednostek.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc minimalnych FPS'ow.", 0, size);
					}			
				}
			}				
		}	
		case DIALOG_BODY_PROTECTOR_MAX_PLOSS_VALUE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj maksymalna wartosc traconych pakietow po przekroczeniu, ktorej gracz otrzyma ostrzezenie.\nWartosc traconych pakietow musi zawierac sie w przedziale od 1.0 do 99.0 jednostek.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc traconych pakietow.", 0, size);
					}			
				}
			}				
		}			
		case DIALOG_BODY_PROTECTOR_WARNINGS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ilosc ostrzezen jaka moze otrzymac gracz, zanim zostanie podjeta \"Akcja\".\nWartosc ostrzezen musi zawierac sie w przedziale od 1 do 99.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna ilosc ostrzezen.", 0, size);
					}			
				}
			}				
		}				
		case DIALOG_BODY_FWEAPONS_INFO: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ilosc amunicji do broni. Ilosc amunicji musi zawierac sie w przedziale 0-9999.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna ilosc amunicji.", 0, size);
					}			
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj maksymalna liczbe graczy, ktorzy moga miec ta bron.\nLiczba graczy musi zawierac sie w przedziale 0-999.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna ilosc graczy.", 0, size);
					}			
				}	
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj liczbe broni, jaka moze miec gracz w trybie wolnego wyboru.\nLiczba broni musi zawierac sie w przedziale od 1 do 5.\n"C_KICK"%s", 0, size);
					}			
				}	
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna liczba broni.", 0, size);
					}			
				}					
			}					
		}		
		case DIALOG_BODY_SCOREBOARD_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Obserwuj\n"COLOR_DIALOG_BODY"Zmien druzyne\n"COLOR_DIALOG_BODY"Dodaj/Usun do/z walki\n"COLOR_DIALOG_BODY"Daj gunmenu\n"COLOR_DIALOG_BODY"Uzdrow i daj pancerz rundy\n"COLOR_DIALOG_BODY"Zmien status AFK\n"COLOR_DIALOG_BODY"Zmien status reprezentanta", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Obserwuj\n"COLOR_DIALOG_BODY"Zmien druzyne\n"COLOR_DIALOG_BODY"Dodaj/Usun do/z walki\n"COLOR_DIALOG_BODY"Daj gunmenu\n"COLOR_DIALOG_BODY"Uzdrow i daj pancerz rundy\n"COLOR_DIALOG_BODY"Zmien status AFK\n"COLOR_DIALOG_BODY"Zmien status reprezentanta\n"COLOR_DIALOG_BODY"Ucisz/Wylacz uciszenie\n"COLOR_DIALOG_BODY"Wyrzuc z serwera", 0, size);
					}
				}				
			}
		}
		case DIALOG_BODY_CRASH_LIST: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Zaden z graczy nie zostal scrashowany podczas tej rundy", 0, size);
					}		
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, C_LIGHTGREEN"Dodano", 0, size);
					}						
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niedodano", 0, size);
					}						
				}		
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Wystapil blad przy wyszukiwaniu gracza, lub przerwano badz wystartowano nowa runde", 0, size);
					}						
				}				
				case 4: {
					switch(language) {
						case LANG_PL: strins(output, "\
								"COLOR_DIALOG_BODY"Nick: "C_WHITE"%s\n\
								"COLOR_DIALOG_BODY"Dodano kogos na jego miejsce: %s%s\n\
								"COLOR_DIALOG_BODY"Druzyna: %s%s\n\
								"COLOR_DIALOG_BODY"Czas rundy: "C_WHITE"%d min. %d sek.\n\
								"COLOR_DIALOG_BODY"Powod: "C_WHITE"%s\n\
								"COLOR_DIALOG_BODY"IP: "C_WHITE"%s\n\
								"COLOR_DIALOG_BODY"Zdrowie: "C_WHITE"%.1f\n\
								"COLOR_DIALOG_BODY"Kamizelka: "C_WHITE"%.1f\n\n\
								"COLOR_DIALOG_BODY"Podaj ID gracza lub wybierz go z \"Tab Listy\", zeby go dodac na to miejsce:\
							", 0, size);
					}						
				}
				case 5: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Wystapil blad skryptu przy dodawaniu gracza do walki", 0, size);
					}						
				}	
				case 6: {
					switch(language) {
						case LANG_PL: strins(output, "Powody uruchomienia systemu (Eventy)\n%sCrash/Timeout\n%sWyjscie z serwera\n%sKick/Ban", 0, size);
					}
				}
				case 7: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Powody uruchomienia systemu (Eventy)\n%sAutomatyczna pauza po wystapieniu Eventu\n%sAutomatyczne dodanie po powrocie na serwer", 0, size);
					}
				}				
			}
		}
		case DIALOG_BODY_CMD_GUN_TIME: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas w ktorym gracze beda mieli mozliwosc uzycia komendy zmiany broni ('/gun')\nWartosc powinna zawierac sie w przedziale od 10 do 9999 sekund.\n"C_KICK"%s", 0, size);
					}				
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc.", 0, size);
					}		
				}	
			}
		}
		case DIALOG_BODY_SPAWNPROTECT_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Czas ochrony Anty Team Kill\t%d sek.\n"COLOR_DIALOG_BODY"Czas ochrony Anty Team Kill (Areny)\t%d sek.\n%sOchrona First Blood\n%sOchrona Anti Fall Protect\n"COLOR_DIALOG_BODY"Anti Fall: Automatyczne dodawanie po smierci\t%s%s", 0, size);
					}				
				}
			}
		}	
		case DIALOG_BODY_CHECKPOINT_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Czas przejecia\t%d sek.\n"COLOR_DIALOG_BODY"Rozmiar Checkpoint'a\t%.1f\n%sPrzejecie Checkpoint'a\n%sPrzejecie w pojezdzie\n%sPrzerwanie przez obronce", 0, size);
					}				
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj nowa wielkosc Checkpoint'a w przedziale od 1.0 do 10.0 jednostek.\n"C_KICK"%s", 0, size);
					}					
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc.", 0, size);
					}					
				}				
			}
		}		
		case DIALOG_BODY_FIX_VEHICLE_MENU: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj czas jaki musza odczekac gracze, zeby moc ponownie uzyc komendy\nnaprawy pojazdu '/fv' (w rundzie).\nCzas musi zawierac sie w przedziale od 0 do 600 sekund.\n"C_KICK"%s", 0, size);
					}				
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc.", 0, size);
					}				
				}				
			}
		}
		case DIALOG_BODY_OLD_WEAPONS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_COUNT"Wybierz nowy zestaw\n"COLOR_DIALOG_COUNT"Wybierz poprzedni zestaw\n"COLOR_DIALOG_COUNT"Wybierz poprzedni zestaw i nie pytaj wiecej", 0, size);
					}				
				}
			}
		}
		case DIALOG_BODY_ROUND_ARENA_TDM_POINTS_LIMIT: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj limit punktow na arenie TDM w przedziale od 1 do 999.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc.", 0, size);
					}			
				}
			}
		}
		case DIALOG_BODY_ANTYMACRO_SETTINGS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Niepoprawna wartosc.", 0, size);
					}			
				}				
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj maksymalna ilosc uderzen klawisza sprintu, powyzej ktorej zostana naliczone ostrzezenia.\nPo przekroczeniu limitu ostrzezen, gracz zostanie zablokowany przez AntyMacro.\nLimit uderzen powinien zawierac sie w przedziale od 7 do 13.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj maksymalna ilosc uderzen klawisza sprintu powyzej ktorej,\ngracz natychmiast zostanie zablokowany przez AntyMacro.\nLimit uderzen powinien zawierac sie w przedziale od 14 do 99.\n\n"C_KICK"%s", 0, size);
					}
				}
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj limit ostrzezen, po przekroczeniu ktorych, gracz zostanie zablokowany przez AntyMacro.\nLimit ostrzezen powinien zawierac sie w przedziale od 1 do 10.\n\n"C_KICK"%s", 0, size);
					}
				}
			}			
		}
		case DIALOG_BODY_MATCH_RESTORE: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, 
								"\n\n"COLOR_DIALOG_BODY"\t\t\tCzy chcesz rozpoczac NOWY mecz?\nPodpowiedz: Jesli chcesz przywrocic niedokonczony mecz, kliknij pole \""COLOR_DIALOG_COUNT"%s"COLOR_DIALOG_BODY"\",\n\t\t     a nastepnie uzyj komendy '"COLOR_DIALOG_COUNT"/restorematch"COLOR_DIALOG_BODY"'.", 
							0, size);
							strins(output, 
								C_KICK"\t\t\t\t\tUwaga!\n"COLOR_DIALOG_BODY"    W pamieci nadal sa przechowywane rezultaty niedokonczonego meczu.\n\t   Rozpoczecie nowego spowoduje ich calkowite usuniecie.\n\n\t\t\t"C_WHITE"%s "COLOR_DIALOG_BODY"vs "C_WHITE"%s\n"COLOR_DIALOG_BODY"\t\t\tData rozegrania: "C_WHITE"%s [%02d:%02d]\n"COLOR_DIALOG_BODY"\t\t\tRozegranych rund: "C_WHITE"%d/%d", 
							0, size);
						}
					}			
				}	
			}
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define LANG_OUP_NEXT							0
#define LANG_OUP_BACK							1
#define LANG_OUP_EXIT							2
#define LANG_OUP_SET							3
#define LANG_OUP_YES							4
#define LANG_OUP_NO								5
#define	LANG_OUP_SELECT							6
#define	LANG_OUP_CANCEL							7
#define	LANG_OUP_READY							8
#define	LANG_OUP_ARENA							9
#define LANG_OUP_ARENA_TDM						10
#define	LANG_OUP_BASE							11
#define LANG_OUP_IGNORE_CHOOSE					12
#define	LANG_OUP_ROUND_DRAW						13
#define	LANG_OUP_ROUND_DELETE					14
#define	LANG_OUP_CHANGE							15
#define LANG_OUP_ENABLE							16
#define LANG_OUP_DISABLE						17
#define	LANG_OUP_ADD							18
//==============================================================================
oftenUsedPhrases(index, sub_index = 0, language = -1) {
	static string[16];
	string[0] = EOS;
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	switch(index) {
		case LANG_OUP_NEXT: {
			switch(language) {
				case LANG_PL: strins(string, "Dalej", 0);
			}
		}
		case LANG_OUP_BACK: {
			switch(language) {
				case LANG_PL: strins(string, "Wroc", 0);
			}
		}	
		case LANG_OUP_EXIT: {
			switch(language) {
				case LANG_PL: strins(string, "Wyjdz", 0);
			}
		}		
		case LANG_OUP_SET: {
			switch(language) {
				case LANG_PL: strins(string, "Ustaw", 0);
			}
		}
		case LANG_OUP_YES: {
			switch(language) {
				case LANG_PL: strins(string, "Tak", 0);
			}
		}			
		case LANG_OUP_NO: {
			switch(language) {
				case LANG_PL: strins(string, "Nie", 0);
			}
		}		
		case LANG_OUP_SELECT: {
			switch(language) {
				case LANG_PL: strins(string, "Wybierz", 0);
			}
		}	
		case LANG_OUP_CANCEL: {
			switch(language) {
				case LANG_PL: strins(string, "Anuluj", 0);
			}
		}		
		case LANG_OUP_READY: {
			switch(language) {
				case LANG_PL: strins(string, "Gotowe", 0);
			}
		}				
		case LANG_OUP_ARENA: {
			switch(sub_index) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(string, "arena", 0);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(string, "arene", 0);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(string, "areny", 0);
					}
				}			
				case 3:	{
					switch(language) {
						case LANG_PL: strins(string, "Arena", 0);
					}
				}
			}
		}
		case LANG_OUP_ARENA_TDM: {
			switch(sub_index) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(string, "arena (TDM)", 0);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(string, "arene (TDM)", 0);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(string, "areny (TDM)", 0);
					}
				}			
				case 3:	{
					switch(language) {
						case LANG_PL: strins(string, "Arena (TDM)", 0);
					}
				}
			}
		}
		case LANG_OUP_BASE: {
			switch(sub_index) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(string, "baza", 0);
					}
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(string, "baze", 0);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(string, "bazy", 0);
					}
				}		
				case 3:	{
					switch(language) {
						case LANG_PL: strins(string, "Baza", 0);
					}
				}				
			}
		}	
		case LANG_OUP_ROUND_DRAW: {
			switch(sub_index) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(string, "Remis", 0);
					}
				}		
			}
		}		
		case LANG_OUP_IGNORE_CHOOSE: {
			switch(language) {
				case LANG_PL: strins(string, "Pomin wybor", 0);
			}
		}			
		case LANG_OUP_ROUND_DELETE: {
			switch(language) {
				case LANG_PL: strins(string, "Usun", 0);
			}		
		}
		case LANG_OUP_CHANGE: {
			switch(language) {
				case LANG_PL: strins(string, "Zmien", 0);
			}
		}			
		case LANG_OUP_ENABLE: {
			switch(language) {
				case LANG_PL: strins(string, "Wlaczone", 0);
			}		
		}
		case LANG_OUP_DISABLE: {
			switch(language) {
				case LANG_PL: strins(string, "Wylaczone", 0);
			}		
		}	
		case LANG_OUP_ADD: {
			switch(language) {
				case LANG_PL: strins(string, "Dodaj", 0);
			}				
		}
	}	
	return string;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define TD_SHORT_MESSAGE_ROUND					0
#define	TD_SHORT_MESSAGE_BASE_CAPTURE			1
#define	TD_SHORT_MESSAGE_DEF_BASE				2
#define	TD_SHORT_MESSAGE_PAUSE					3
#define	TD_SHORT_MESSAGE_END_ROUND				4
#define TD_SHORT_MESSAGE_END_MATCH				5
#define TD_SHORT_MESSAGE_SPECTATOR				6
#define TD_SHORT_MESSAGE_OTHER					7
#define TD_SHORT_MESSAGE_PLAYER_KILL			8
#define TD_SHORT_MESSAGE_POINTS_LIMIT			9
//==============================================================================
getTextDrawShortMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case TD_SHORT_MESSAGE_ROUND: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Runda  ~w~%d", 0, size);
					}	
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "Runda  ~w~%d / %d", 0, size);
					}	
				}				
			}
		}
		case TD_SHORT_MESSAGE_BASE_CAPTURE: {
			switch(language) {
				case LANG_PL: strins(output, "Przejecie bazy  %.0f%%", 0, size);
			}
		}
		case TD_SHORT_MESSAGE_DEF_BASE: {
			switch(language) {
				case LANG_PL: strins(output, "Czas na powrot do bazy  ~w~%d", 0, size);
			}
		}	
		case TD_SHORT_MESSAGE_PAUSE: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "~n~Runda zostala zatrzymana~n~_", 0, size);
					}	
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "~n~Runda zostanie wznowiona za ~w~%d.%d sek.~n~_", 0, size);
					}	
				}				
			}
		}		
		case TD_SHORT_MESSAGE_END_ROUND: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Wygrywa druzyna ~w~%s~n~~n~_", 0, size);
					}	
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "Runda zakonczona remisem~n~~n~_", 0, size);
					}	
				}					
			}		
		}
		case TD_SHORT_MESSAGE_END_MATCH: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Wygrywa  ~w~%s", 0, size);
					}	
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "Mecz zakonczony remisem", 0, size);
					}	
				}			
				case 2: {		
					switch(language) {
						case LANG_PL: strins(output, "Punktow  ~w~%d", 0, size);
					}	
				}	
				case 3: {		
					switch(language) {
						case LANG_PL: strins(output, "Wygrana", 0, size);
					}	
				}	
				case 4: {		
					switch(language) {
						case LANG_PL: strins(output, "Przegrana", 0, size);
					}	
				}	
				case 5: {		
					switch(language) {
						case LANG_PL: strins(output, "Remis", 0, size);
					}	
				}		
				case 6: {		
					switch(language) {
						case LANG_PL: strins(output, "Arena", 0, size);
					}	
				}	
				case 7: {		
					switch(language) {
						case LANG_PL: strins(output, "Baza", 0, size);
					}	
				}		
				case 8: {		
					switch(language) {
						case LANG_PL: strins(output, "Arena (TDM)", 0, size);
					}	
				}					
			}		
		}
		case TD_SHORT_MESSAGE_SPECTATOR: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "~b~~h~~h~Zdrowie: ~w~%.1f  ~b~~h~~h~Pancerz: ~w~%.1f", 0, size);
					}	
				}
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Obserwowany przez~w~", 0, size);
					}						
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "... i %d innych", 0, size);
					}						
				}
			}
		}
		case TD_SHORT_MESSAGE_OTHER: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Pozostali", 0, size);
					}	
				}
			}		
		}
		case TD_SHORT_MESSAGE_PLAYER_KILL: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Zostales zabity przez ~w~%s", 0, size);
					}	
				}
				case 1: {		
					switch(language) {
						case LANG_PL: strins(output, "Zabiles ~w~%s", 0, size);
					}	
				}					
			}
		}		
		case TD_SHORT_MESSAGE_POINTS_LIMIT: {
			switch(msg_subindex) {
				case 0: {		
					switch(language) {
						case LANG_PL: strins(output, "Limit punktow  ~w~%d", 0, size);
					}	
				}					
			}			
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SETTINGS_ERROR_INROUND					0
#define	SETTINGS_ERROR_INMATCH					1
//==============================================================================
getSettingsErrorMessage(msg_index, language = -1) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	new output[80];
	switch(msg_index) {
		case SETTINGS_ERROR_INROUND: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_BODY"Tego ustawienia nie mozna edytowac w trakcie trwania rundy.", 0);
			}
		}		
		case SETTINGS_ERROR_INMATCH: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_BODY"Tego ustawienia nie mozna edytowac w trakcie trwania meczu.", 0);
			}
		}			
	}
	return output;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SCM_START								0
#define	SCM_SERVER								1
#define	SCM_ROUND								2
#define	SCM_LOBBY								3
#define	SCM_PROTECTOR							4
#define	SCM_ANTYGLITCH							5
#define	SCM_INFO_MSGS							6
#define	SCM_ADMIN_PASS							7
#define	SCM_LOBBY_VEHICLES						8
#define	SCM_LOBBY_WEAPONS						9
#define	SCM_ROUND_VEHICLES						10
#define	SCM_ROUND_WEAPONS						11
#define SCM_MENU_HTTP							12
#define	SCM_MENU_C_ADD							13
#define SCM_MENU_SPAWN_PROTECT					14
#define	SCM_MENU_CHECKPOINT						15
#define	SCM_ROUND_FIX_VEHICLES					16
#define	SCM_ROUND_SPAWN_PROTECT					17
#define	SCM_ANTYMACRO							18
//==============================================================================
getSettingsCaptionMessage(output[], msg_index, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case SCM_START: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Multi A/D - Ustawienia", 0, size);
			}
		}	
		case SCM_SERVER: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia serwera", 0, size);
			}		
		}
		case SCM_ROUND: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia rundy", 0, size);
			}				
		}
		case SCM_LOBBY: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia Lobby", 0, size);
			}			
		}
		case SCM_PROTECTOR: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ograniczenia graczy", 0, size);
			}			
		}
		case SCM_ANTYGLITCH: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia antyglitcha", 0, size);
			}			
		}
		case SCM_INFO_MSGS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia powiadomien", 0, size);
			}			
		}
		case SCM_ADMIN_PASS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Hasla administratora", 0, size);
			}			
		}
		case SCM_LOBBY_VEHICLES: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Lobby - Pojazdy", 0, size);
			}			
		}	
		case SCM_LOBBY_WEAPONS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Lobby - Bronie", 0, size);
			}			
		}	
		case SCM_ROUND_VEHICLES: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Pojazdy", 0, size);
			}			
		}	
		case SCM_ROUND_WEAPONS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Bronie", 0, size);
			}			
		}			
		case SCM_MENU_HTTP: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - HTTP", 0, size);
			}				
		}
		case SCM_MENU_C_ADD: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Crash Add", 0, size);
			}				
		}			
		case SCM_MENU_SPAWN_PROTECT: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Spawn Protect", 0, size);
			}				
		}
		case SCM_MENU_CHECKPOINT: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Checkpoint", 0, size);
			}				
		}		
		case SCM_ROUND_FIX_VEHICLES: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Naprawa pojazdow ('/fv')", 0, size);
			}				
		}
		case SCM_ROUND_SPAWN_PROTECT: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia Rundy - Spawn Protect", 0, size);
			}			
		}
		case SCM_ANTYMACRO: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Ustawienia - Ustawienia AntyMacro", 0, size);
			}			
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define SBM_START									0	
#define	SBM_MENU_SERVER								1
#define	SBM_MENU_ANTYGLITCH							2
#define	SBM_MENU_MSGS								3
#define	SBM_MENU_PROTECTOR							4
#define SBM_MENU_LOBBY								5
#define	SBM_MENU_ROUND_WEAPONS						6
#define	SBM_MENU_ROUND_FREE_WEAPONS					7
#define	SBM_MENU_HTTP								8
//==============================================================================
getSettingsBodyMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case SBM_START: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Ustawienia serwera\n"COLOR_DIALOG_BODY"Ustawienia druzyn\n"COLOR_DIALOG_BODY"Ustawienia rundy\n"COLOR_DIALOG_BODY"Ustawienia lobby\n"COLOR_DIALOG_BODY"Ograniczenia graczy\n"COLOR_DIALOG_BODY"Ustawienia Anty-Glitcha\n"COLOR_DIALOG_BODY"Ustawienia powiadomien", 0, size);
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, 
							COLOR_DIALOG_BODY"Ustawienia serwera\n"COLOR_DIALOG_BODY"Ustawienia druzyn\n"COLOR_DIALOG_BODY"Ustawienia rundy\n"COLOR_DIALOG_BODY"Ustawienia lobby\n"COLOR_DIALOG_BODY"Ograniczenia graczy\n"COLOR_DIALOG_BODY"Ustawienia Anty-Glitcha\n"COLOR_DIALOG_BODY"Ustawienia powiadomien\n"COLOR_DIALOG_BODY"Ustawienia HTTP", 
						0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, 
							COLOR_DIALOG_BODY"Ustawienia serwera\n"COLOR_DIALOG_BODY"Ustawienia druzyn\n"COLOR_DIALOG_BODY"Ustawienia rundy\n"COLOR_DIALOG_BODY"Ustawienia lobby\n"COLOR_DIALOG_BODY"Ograniczenia graczy\n"COLOR_DIALOG_BODY"Ustawienia Anty-Glitcha\n"COLOR_DIALOG_BODY"Ustawienia powiadomien\n"COLOR_DIALOG_BODY"Ustawienia HTTP\n"COLOR_DIALOG_BODY"Hasla dostepu", 
						0, size);
					}
				}				
			}
		}
		case SBM_MENU_SERVER: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, 
							"Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Pogoda\t%d\n"COLOR_DIALOG_BODY"Widocznosc nickow\t%.1f\n"COLOR_DIALOG_BODY"Grawitacja\t%.4f\n"COLOR_DIALOG_BODY"Czas\t%d\n"COLOR_DIALOG_BODY"Serwer zamkniety na polaczenia\t%s", 
						0, size);
					}
				}			
			}
		}	
		case SBM_MENU_ANTYGLITCH: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Anty Macro\n"COLOR_DIALOG_BODY"Rodzaj kary\t%s\n%sSlidebug\n%sFast Shoot\n%sCrouch Bug", 0, size);
					}
				}			
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, "Rodzaj kary\n"COLOR_DIALOG_BODY"Hands Up  (Anim. unoszenia rak)\n"COLOR_DIALOG_BODY"Fired Up  (Podniesienie skina do gory)", 0, size);
					}
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, "%sStatus AntyMacro\n"COLOR_DIALOG_BODY"Maks. klikniec (ostrzezenia)\t\t["C_WHITE"%d"COLOR_DIALOG_BODY"]\n"COLOR_DIALOG_BODY"Maks. klikniec (krytyczne)\t\t["C_WHITE"%d"COLOR_DIALOG_BODY"]\n"COLOR_DIALOG_BODY"Maks. ostrzezen\t\t\t["C_WHITE"%d"COLOR_DIALOG_BODY"]", 0, size);
					}				
				}
			}
		}		
		case SBM_MENU_MSGS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "%sWiadomosci o wejsciu/wyjsciu na/z serwer/a\n%sWyswietlanie IP po wejsciu na serwer\n%sPowiadomienia o utracie HP druzyny\n%sStan zdrowia druzyny (boczne)\n%sObiektowe info o obazeniach (nad glowa gracza)\n%sInfo. o zabojstwie na chacie\n%sIkony smierci na radarze\n"COLOR_DIALOG_BODY"Scoreboard: "C_WHITE"%s", 0, size);
					}
				}			
			}		
		}
		case SBM_MENU_PROTECTOR: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: {
							strins(output, "Ustawienie\tAktualna wartosc\n%sSprawdzaj arbitrow\t \n"COLOR_DIALOG_BODY"Czynnosc po przekroczeniu ostrzezen\t%s\n"COLOR_DIALOG_BODY"Max Ping\t%d\n"COLOR_DIALOG_BODY"Max Ping (Ostrzezenia)\t%d\n"COLOR_DIALOG_BODY"Min FPS\t%d\n"COLOR_DIALOG_BODY"Min FPS (Ostrzezenia)\t%d\n"COLOR_DIALOG_BODY"Max P-Loss\t%.2f\n"COLOR_DIALOG_BODY"Max P-Loss (Ostrzezenia)\t%d", 0, size);
						}
					}
				}			
			}		
		}		
		case SBM_MENU_LOBBY: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Arena Treningowa: Wybor broni\n"COLOR_DIALOG_BODY"Arena Treningowa\t%sPancerz\n"COLOR_DIALOG_BODY"Pojazdy: Wybor pojazdow\n"COLOR_DIALOG_BODY"Pojazdy\t%sStatus\n"COLOR_DIALOG_BODY"%sPojazdy w interiorach", 0, size);
					}
				}			
			}			
		}
		case SBM_MENU_ROUND_WEAPONS: {
			switch(msg_subindex) {
				case 0: {
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Bronie tryb: 'Wolny wybor'\n"COLOR_DIALOG_BODY"Bronie tryb: 'Stale zestawy'\n"COLOR_DIALOG_BODY"Bronie dodatkowe\n"COLOR_DIALOG_BODY"Tryb broni rund\t%s\n"COLOR_DIALOG_BODY"Limit broni w trybie 'Wolny wybor'\t%d\n"COLOR_DIALOG_BODY"Czas na zmiane broni (cmd: '/gun')\t%d sek.", 0, size);
					}
				}			
			}	
		}
		case SBM_MENU_ROUND_FREE_WEAPONS: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Status\t%s%s\n"COLOR_DIALOG_BODY"Amunicja\t%s%d\n"COLOR_DIALOG_BODY"Limit graczy\t%s%d", 0, size);				
					}
				}
			}
		}	
		case SBM_MENU_HTTP: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, "%sAutomatyczne sprawdzanie wersji\n%sWysylanie wynikow meczow\n%sDodaj do listy serwerow", 0, size);				
					}
				}
			}
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define SBM_SETTING_WEATHER							0	
#define	SBM_SETTING_NAMETAG_DIS						1
#define	SBM_SETTING_GRAVITY							2
#define	SBM_SETTING_WORLD_TIME						3
#define SBM_SETTING_ROUND_CONST_WEAPONS				4
#define	SBM_SETTING_ROUND_PREMADED_WEAPONS			5
#define	SBM_SETTING_ADMIN_PASSWORD_SET				6
//==============================================================================
getSettingsSettingBodyMessage(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case SBM_SETTING_WEATHER: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"W tym menu mozesz ustawic pogode panujaca w grze.\nID pogody musi zawierac sie w przedziale od 0 do 20.\n\n%s", 0, size);				
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna wartosc.", 0, size);	
					}
				}							
			}
		}
		case SBM_SETTING_NAMETAG_DIS: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"W tym menu mozesz ustawic odleglosc rysowania nickow graczy.\nOdleglosc rysowania musi zawierac sie w przedziale od 5.0 do 250.0 jednostek.\n\n%s", 0, size);				
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna wartosc.", 0, size);	
					}
				}						
			}
		}	
		case SBM_SETTING_GRAVITY: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"W tym menu mozesz ustawic grawitacje na serwerze.\nGrawitacja musi zawierac sie w przedziale od -50.0 do 50.0 jednostek (Domyslna: 0.008).\n\n%s", 0, size);				
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna wartosc.", 0, size);	
					}
				}							
			}
		}				
		case SBM_SETTING_WORLD_TIME: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"W tym menu mozesz ustawic czas na serwerze.\nCzas musi zawierac sie w przedziale od 0 do 24.\n\n%s", 0, size);				
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna wartosc.", 0, size);	
					}
				}							
			}
		}
		case SBM_SETTING_ROUND_CONST_WEAPONS: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Bron\t%s\n"COLOR_DIALOG_BODY"Amunicja\t%d\n"C_KICK"Usun zestaw", 0, size);				
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ilosc amunicji do broni w przedziale od 1 do 9999.", 0, size);	
					}
				}					
				case 2: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Ilosc amunicji musi byc w przedziale od 1 do 9999.", 0, size);	
					}
				}					
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, "Nazwa broni\tAmunicja", 0, size);	
					}					
				}
			}		
		}
		case SBM_SETTING_ROUND_PREMADED_WEAPONS: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Bron 1\t%s\n"COLOR_DIALOG_BODY"Amunicja 1\t%d\n"COLOR_DIALOG_BODY"Bron 2\t%s\n"COLOR_DIALOG_BODY"Amunicja 2\t%d\n"COLOR_DIALOG_BODY"Limit graczy\t%d\n"C_KICK"Usun", 0, size);				
					}
				}	
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ilosc amunicji do broni w przedziale od 1 do 9999.\n%s", 0, size);	
					}
				}					
				case 2: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Ilosc amunicji musi byc w przedziale od 1 do 9999.", 0, size);	
					}
				}	
				case 3: { 
					switch(language) {
						case LANG_PL: strins(output, "Ustawienie\tAktualna wartosc\n"COLOR_DIALOG_BODY"Bron 1\t%s\n"COLOR_DIALOG_BODY"Amunicja 1\t%d\n"COLOR_DIALOG_BODY"Bron 2\t%s\n"COLOR_DIALOG_BODY"Amunicja 2\t%d\n"COLOR_DIALOG_BODY"Limit graczy\t%d\n"C_LIGHTGREEN"Zapisz", 0, size);				
					}
				}	
				case 4: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj ilosc graczy jacy beda mogli grac tym zestawem broni.\nIlosc graczy musi byc w przedziale od 1 do 999.\n%s", 0, size);	
					}
				}					
				case 5: { 
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Ilosc gracz musi byc w przedziale od 1 do 999.", 0, size);	
					}
				}					
			}			
		}
		case SBM_SETTING_ADMIN_PASSWORD_SET: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY"Podaj nowe haslo administratora. Haslo powinno skladac sie z\nliter i cyfr, oraz powinno zawierac sie w przedziale od 3 do 16 znakow.\n%s", 0, size);				
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Niepoprawna dlugosc hasla, lub haslo zawiera niedozwolone znaki.", 0, size);				
					}				
				}
				case 2: {
					switch(language) {
						case LANG_PL: strins(output, C_KICK"Haslo administratora pokrywa sie z haslem administratora innego poziomu.", 0, size);				
					}				
				}	
				case 3: {
					switch(language) {
						case LANG_PL: strins(output, "Poziom praw\tHaslo", 0, size);				
					}					
				}
			}
		}
	}
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	SETTING_NAME_WEAPON_MODE						0
//==============================================================================
getSettingName(msg_index, msg_subindex = 0, language = -1) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	new output[32];
	output[0] = EOS;
	
	switch(msg_index) {	
		case SETTING_NAME_WEAPON_MODE: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, "Wolny wybor", 0);
					}
				}
				case 1: { 
					switch(language) {
						case LANG_PL: strins(output, "Stale zestawy", 0);
					}
				}
				case 2: { 
					switch(language) {
						case LANG_PL: strins(output, "Bronie Rundy", 0);
					}
				}										
			}
		}
	}
	return output;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	HELP_CAPTION_START						0
#define	HELP_CAPTION_ABOUT						1
#define	HELP_CAPTION_KEYOBARD_SHORTCUTS			2
#define	HELP_CAPTION_CMDS						3
#define	HELP_CAPTION_CMDS_PLAYER				4
#define	HELP_CAPTION_CMDS_J_ADMIN				5
#define	HELP_CAPTION_CMDS_ADMIN					6
#define	HELP_CAPTION_CMDS_HEAD_ADMIN			7
//==============================================================================
helpMenuCaption(msg_index, language = -1) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	new output[32];
	output[0] = EOS;
	
	switch(msg_index) {	
		case HELP_CAPTION_START: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Menu pomocy", 0);					
			}
		}
		case HELP_CAPTION_ABOUT: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"O Multi A/D", 0);					
			}		
		}
		case HELP_CAPTION_KEYOBARD_SHORTCUTS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Skroty klawiszowe", 0);					
			}		
		}		
		case HELP_CAPTION_CMDS: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Pomoc - Komendy", 0);					
			}		
		}			
		case HELP_CAPTION_CMDS_PLAYER: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Komendy Gracza", 0);					
			}		
		}	
		case HELP_CAPTION_CMDS_J_ADMIN: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Komendy J.Admina", 0);					
			}		
		}	
		case HELP_CAPTION_CMDS_ADMIN: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Komendy Admina", 0);					
			}		
		}	
		case HELP_CAPTION_CMDS_HEAD_ADMIN: {
			switch(language) {
				case LANG_PL: strins(output, COLOR_DIALOG_HEAD"Komendy Head Admina", 0);					
			}		
		}			
	}
	return output;
}
//==============================================================================
//------------------------------------------------------------------------------
//==============================================================================
#define	HELP_BODY_START							0
#define	HELP_BODY_CMDS							1
#define	HELP_CMDS_LIST_PLAYER					2
#define	HELP_CMDS_LIST_J_ADMIN					3
#define	HELP_CMDS_LIST_ADMIN					4
#define	HELP_CMDS_LIST_HEAD_ADMIN				5
//==============================================================================
helpMenuBody(output[], msg_index, msg_subindex = 0, language = -1, size = sizeof(output)) {
	if(language == -1 || !(language >= LANG_PL)) language = g_DefaultLanguage;	
	output[0] = EOS;
	switch(msg_index) {
		case HELP_BODY_START: {
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: strins(output, COLOR_DIALOG_BODY">> O Multi A/D\n"COLOR_DIALOG_BODY">> Spis komend\n"COLOR_DIALOG_BODY">> Ustawienia gamemoda", 0, size);				
					}
				}	
				case 1: {
					switch(language) {
						case LANG_PL: {
							strins(output, "\n"COLOR_DIALOG_BODY"Wersja: "C_WHITE""_VERSION"\n"COLOR_DIALOG_BODY"Ost. aktualizacja: "C_WHITE""LAST_UPDATE"\n"COLOR_DIALOG_BODY"Kompilacja: "C_WHITE""#MAX_PLAYERS" graczy\n"COLOR_DIALOG_BODY"Autor: "C_WHITE"Rafal (AxL) Zoltanski\n"COLOR_DIALOG_BODY"Oficjalna strona projektu: "C_WHITE"mad.HighSkill.eu\n ", 0, size);				
						}
					}				
				}
			}
		}	
		case HELP_BODY_CMDS: {
			switch(msg_subindex) {
				case 0: { /*Komendy gracza*/
					switch(language) {
						case LANG_PL: {							
							strins(output, "/me\n/car\n/switch\n/gun\n/afk\n/sync\n/pm\n/lastround\n/lastmatch\n/replist\n/admins\n/kill\n/rounds\n/tdm\n/spec\n/specoff\n/lockpm\n/aiminfo\n/dmginfo\n/roundsettings\n/help\n/alog\n/hide\n/remove\n/fixvehicle\n/mynetcheck", 0, size);				
						}
					}
				}	
				case 1: { /*Komendy J.Admina*/
					switch(language) { 
						case LANG_PL: {
							strins(output, "/aswap\n/swap\n/sa\n/sb\n/end\n/gunmenu\n/add\n/remove\n/pause\n/chat\n/representative\n/coin\n/heal\n/armour\n/rarmour\n/restore\n/setafk\n/players\n/chckver\n/cadd\n/kpause\n/labo\n/sethp\n/setarmour", 0, size);
						}
					}
				}
				case 2: { /*Komendy Admina*/
					switch(language) {
						case LANG_PL: {
							strins(output, "/startmatch\n/stopmatch\n/resetpoints\n/kick\n/unbanip\n/tp\n/tpto\n/tphere\n/lock\n/open\n/mute\n/unmute\n/mrounds\n/eyeinfo\n/destroyvehicle\n/fixvehicle\n/netcheck\n/restorematch", 0, size);
						}
					}
				}
				case 3: { /*Komendy Head Admina*/
					switch(language) {
						case LANG_PL: {
							strins(output, "/tpwd\n/tname\n/tskin\n/gmx\n/weather\n/gravity\n/nametagdis\n/wtime\n/rcfg\n/tcfg\n/rvehcfg\n/rweapcfg\n/lcfg\n/pcfg\n/agcfg\n/mcfg\n/team\n/cfg\n/rounds", 0, size);
						}
					}
				}	
				case 4: { /*Skroty klawiszowe*/
					switch(language) {
						case LANG_PL: {
							strins(output, "Skok + Celowanie = RSP (Sync)\nPrzycisk \"Odmow\" (domyslnie 'N') = Wezwanie wsparcia", 0, size);
						}
					}				
				}
			}
		}
		case HELP_CMDS_LIST_PLAYER: {/*Komendy gracza*/
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca menu ustawien gracza.", 
							0, size);	
						}
					}
				}	
				case 1: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/c\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID modelu pojazdu, pelna lub czesc nazwy pojazdu>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do spawnowania pojazdow podczas rund i w obszarze lobby.", 
							0, size);									
						}
					}
				}
				case 2: { 
					switch(language) {
						case LANG_PL: {								
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID druzyny (1-3)>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do szybkiej zmiany druzyny w obszarze lobby.", 
							0, size);								
						}
					}
				}	
				case 3: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda przywracajaca gunmenu w trakcie rundy.", 
							0, size);					
						}
					}
				}	
				case 4: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca status AFK gracza. Przy\naktywnym statusie gracz nie jest automatycznie dodawany do rundy.", 
							0, size);				
						}
					}
				}	
				case 5: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/s, /rsp\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do zrespawnowania skina podczas rundy. Komende mozna\nwywolac rowniez przez jednoczesne wcisniecie przycisku skoku i celowania.", 
							0, size);					
						}
					}
				}	
				case 6: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/pw, /priv\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Odbiorcy] [Tresc wiadomosci]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wysylania prywatnych wiadomosci do innego gracza.", 
							0, size);					
						}
					}
				}	
				case 7: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wyswietlenia lub ukrycia informacji o ost. rundzie.", 
							0, size);		
						}
					}
				}	
				case 8: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wyswietlenia lub ukrycia informacji o ost. meczu.", 
							0, size);		
						}
					}
				}	
				case 9: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca liste osob z aktywnym statusem reprezentanta.\nStatus reprezentanta pozwala na pisanie na chacie, kiedy ten zostal wylaczony.", 
							0, size);		
						}
					}
				}	
				case 10: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietla liste zalogowanych administratorow.", 
							0, size);			
						}
					}
				}	
				case 11: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do popelnienia samobojstwa w grze!", 
							0, size);				
						}
					}
				}	
				case 12: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca informacje o rundach rozegranych w aktualnym meczu.\nAdministracja ma mozliwosc usuniecia poszczegolnych rund z ogolnego rezultatu (Head Admin)", 
							0, size);						
						}
					}
				}	
				case 13: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca wejsca i wyjsca na i z areny DM.", 
							0, size);			
						}
					}
				}	
				case 14: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID gracza>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do obserwowania gracza w rundzie.", 
							0, size);					
						}
					}
				}	
				case 15: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wylaczajaca status obserwatora.", 
							0, size);			
						}
					}
				}	
				case 16: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/pmlock\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wylaczajaca i wlaczajaca odbior i wysylanie prywatnych wiadomosci.", 
							0, size);		
						}
					}
				}	
				case 17: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca status wyswietlania informacji o trafionym graczu (prawy dolny rog).", 
							0, size);			
						}
					}
				}	
				case 18: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca status wyswietlania informacji o trafieniach.", 
							0, size);			
						}
					}
				}	
				case 19: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/roundset\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca najwazniejsze ustawienia gamemoda.", 
							0, size);			
						}
					}
				}	
				case 20: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/pomoc, /cmd, /cmds\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca menu pomocy.", 
							0, size);		
						}
					}
				}		
				case 21: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"'/login\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Haslo administratora]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do logowania sie na konto administratora.", 
							0, size);				
						}
					}
				}	
				case 22: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/hi\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do szybkiego ukrywania informacji z wynikami rundy.", 
							0, size);				
						}
					}
				}				
				case 23: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/rem, /rm\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do usuniecia sie z trwajacej rundy. Komenda dziala jedynie w\ntrakcie \"Spawn Protect\" lub do zakonczenia ochrony \"First Blood\".", 
							0, size);				
						}
					}				
				}
				case 24: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/fv\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do naprawy uzywanego pojazdu.", 
							0, size);				
						}
					}				
				}	
				case 25: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/mnc\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID gracza>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do sprawdzenia stanu testu 'NetCheck' wybranego gracza.", 
							0, size);				
						}
					}				
				}						
			}
		}		
		case HELP_CMDS_LIST_J_ADMIN: {/*Komendy junior admina*/
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza] <ID Druzyny (1-3)>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do szybkiej zmiany druzyny wybranego gracza.", 
							0, size);				
						}
					}
				}	
				case 1: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<\"yes\" lub \"no\">\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do szybkiej zmiany druzyn wszystkich graczy.\nUzycie parametru 'yes' powoduje zmiane skinow druzyn.", 
							0, size);	
						}
					}
				}	
				case 2: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/startarena\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID Areny>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wystartowania rundy w trybie aren.\nBrak parametru powoduje wystartowanie losowej mapy.", 
							0, size);				
						}
					}
				}	
				case 3: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/startbase\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID Bazy>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wystartowania rundy w trybie baz.\nBrak parametru powoduje wystartowanie losowej mapy.", 
							0, size);			
						}
					}
				}	
				case 4: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do przerwania aktualnie trwajacej rundy.", 
							0, size);				
						}
					}
				}	
				case 5: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/gm\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda dajaca graczu mozliwosc zmiany broni w trakcie rundy.", 
							0, size);				
						}
					}
				}	
				case 6: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza, indeks druzyny (np. \"t:1\") lub 'all']\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda dodajaca gracza, druzyne lub wszystkich niegrajacych graczy do trwajacej rundy.", 
							0, size);			
						}
					}
				}	
				case 7: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/rem, /rm\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda usuwajaca gracza o podanym ID z trwajacej rundy.", 
							0, size);			
						}
					}
				}	
				case 8: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/p\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wlaczajaca i wylaczajaca pauze w trakcie rundy.", 
							0, size);				
						}
					}
				}	
				case 9: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wlaczajaca i wylaczajaca mozliwosc pisania na chacie globalnym.",
							0, size);				
						}
					}
				}	
				case 10: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/rep\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wlaczajaca i wylaczajaca status reprezentanta dla gracza.\nStatus reprezentanta pozwala na pisanie na chacie globalnym, gdy ten jest wylaczony.",
							0, size);				
						}
					}
				}	
				case 11: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Prosty symulator rzutu moneta, pomocny przy rozstrzyganiu sytuacji konfliktowych.",
							0, size);			
						}
					}
				}	
				case 12: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/h\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza, indeks druzyny (np. \"t:1\") lub 'all']\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do uzdrowienia gracza, druzyny lub wszystkich graczy.",
							0, size);					
						}
					}
				}	
				case 13: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/a\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza, indeks druzyny (np. \"t:1\") lub 'all']\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda dajaca graczu, druzynie lub wszystkim graczom pelny pancerz.",
							0, size);					
						}
					}
				}	
				case 14: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/ra\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza, indeks druzyny (np. \"t:1\") lub 'all']\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda dajaca graczu, druzynie lub wszystkim graczom\npancerz o wartosci ustawionej w konfigu gamemoda.",
							0, size);				
						}
					}
				}	
				case 15: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/r\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza, indeks druzyny (np. \"t:1\") lub 'all']\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda uzdrawiajaca i dajaca graczu, druzynie lub graczom\npancerz o wartosci ustawionej w konfigu gamemoda.",
							0, size);				
						}
					}
				}	
				case 16: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca status AFK wybranego gracza.",
							0, size);					
						}
					}
				}	
				case 17: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca informacje o graczach na serwerze.",
							0, size);			
						}
					}
				}	
				case 18: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do sprawdzania istnienia nowszej wersji gamemoda.",
							0, size);				
						}
					}
				}	
				case 19: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"<ID Gracza, ktory wczesniej zostal scrashowany i powrocil na serwer>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do dodania gracza do rundy po jego wczesniejszym crashu,\nlub dodania na jego miejsce innego gracza.",
							0, size);				
						}
					}
				}					
				case 20: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do zmiany statusu ustawienia \"Pauza na przycisk\".",
							0, size);				
						}
					}
				}		
				case 21: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[\"On\" lub \"Off\"]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda dodajaca lub usuwajaca klape w silosie w bazie wojskowej na pustyni.",
							0, size);				
						}
					}
				}	
				case 22: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID gracza, indeks druzyny (np. \"t:1\") lub \"all\"] [Nowa wartosc zdrowia (1-100)]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda ustawiajaca zadana ilosc zdrowia wybranemu graczu, druzynie lub wszystkim.",
							0, size);				
						}
					}
				}
				case 23: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/seta, /setarmor\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID gracza, indeks druzyny (np. \"t:1\") lub \"all\"] [Nowa wartosc pancerza (0-100)]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda ustawiajaca zadana ilosc pancerza wybranemu graczu, druzynie lub wszystkim.",
							0, size);				
						}
					}
				}				
			}
		}
		case HELP_CMDS_LIST_ADMIN: {/*Komendy admina*/
			switch(msg_subindex) {
				case 0: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/start\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Ilosc rund (3-9)] <Nazwa druzyny '1'> <Nazwa druzyny '2'>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wlaczenia ustawien meczowych.",
							0, size);			
						}
					}
				}	
				case 1: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/stop\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wylaczenia ustawien meczowych.",
							0, size);			
						}
					}
				}	
				case 2: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/reset\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca zresetowania punktacji przy WYLACZONYCH ustawieniach meczowych.",
							0, size);				
						}
					}
				}	
				case 3: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/k\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza] <Czas trwania (0-60 minut)> <Powod>\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do wyrzucenia gracza z serwera.",
							0, size);			
						}
					}
				}	
				case 4: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/ub\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[IP do odbanowania]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do odbanowania IP zablokowanego komenda '/kick'.",
							0, size);			
						}
					}
				}	
				case 5: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza teleportowanego, indeks druzyny (np. \"t:1\") lub 'all'] [ID Gracza celu]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca przeniesienia jednego gracza do drugiego.",
							0, size);		
						}
					}
				}	
				case 6: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do przeniesienia do gracza.",
							0, size);		
						}
					}
				}	
				case 7: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do przeniesienia gracza do siebie.",
							0, size);				
						}
					}
				}	
				case 8: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda blokujaca mozliwosc wejscia na serwer dla graczy.",
							0, size);				
						}
					}
				}	
				case 9: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/unlock\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda odblokowujaca zakaz wejscia na serwer dla graczy.",
							0, size);			
						}
					}
				}	
				case 10: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda blokujaca graczu mozliwosc pisania na chacie globalnym.",
							0, size);						
						}
					}
				}	
				case 11: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wylaczajaca blokade gracza na pisanie na chacie globalnym.",
							0, size);			
						}
					}
				}	
				case 12: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Nowa ilosc rund (1 - 11)]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda umozliwiajaca zmiane ilosci rund w trakcie meczu.\nNowa ilosc rund, musi byc wieksza od sumy juz rozegranych.",
							0, size);			
						}
					}				
				}
				case 13: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmienia status podgladu komend wpisywanych przez graczy.",
							0, size);			
						}
					}				
				}		
				case 14: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/dv\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[\"All\", ID modelu pojazdu lub jego nazwa]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do usuwania nieuzywanych pojazdow w rundzie.",
							0, size);			
						}
					}				
				}	
				case 15: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/fv\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[\"All\" lub ID wybranego gracza]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do naprawy uzywanego pojazdu.", 
							0, size);				
						}
					}				
				}	
				case 16: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/nc\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID gracza] <\"Ping\", \"FPS\" lub \"PLoss\">\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda sluzaca do sprawdzenia, badz zmiany stanu testu 'NetCheck' wybranego gracza.", 
							0, size);				
						}
					}						
				}
				case 17: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/rmatch\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda przywracajaca rezultaty niedokonczonego meczu, przerwanego np. przez crash serwera.", 
							0, size);				
						}
					}						
				}				
			}
		}		
		case HELP_CMDS_LIST_HEAD_ADMIN: {/*Komendy head admina*/
			switch(msg_subindex) {
				case 0: { 
					switch(language) {					
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Druzyny (1-3)] [Haslo (przedzial 1000-9999 lub 0 do usuniecia hasla)]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zakladajaca haslo na wybrana druzyne.",
							0, size);			
						}
					}
				}	
				case 1: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Druzyny (1-3)] [Nowa nazwa]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca nazwe wybranej druzyny.",
							0, size);				
						}
					}
				}	
				case 2: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Druzyny (1-3)] [ID Skina]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca skin wybranej druzyny.",
							0, size);				
						}
					}
				}	
				case 3: { 
					switch(language) {
						case LANG_PL: {												
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wykonujaca funkcje '/rcon gmx'.",
							0, size);			
						}
					}
				}	
				case 4: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[ID Pogody]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca pogode na serwerze.",
							0, size);					
						}
					}
				}	
				case 5: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Poziom grawitacji]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca grawitacje na serwerze.",
							0, size);				
						}
					}
				}	
				case 6: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Odleglosc rysowania]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca odleglosc rysowania nickow graczy na serwerze.\nUwaga! Po wykonaniu zmian, nalezy wykonac restart gamemoda.",
							0, size);					
						}
					}
				}	
				case 7: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"[Godzina]\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda zmieniajaca godzine w grze.",
							0, size);		
						}
					}
				}	
				case 8: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien rundy.",
							0, size);			
						}
					}
				}	
				case 9: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/tcfg\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien druzyn.",
							0, size);			
						}
					}
				}	
				case 10: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien pojazdow rundy.",
							0, size);		
						}
					}
				}	
				case 11: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien broni rundy.",
							0, size);			
						}
					}
				}	
				case 12: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien lobby.",
							0, size);			
						}
					}
				}	
				case 13: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien ograniczen graczy.",
							0, size);			
						}
					}
				}	
				case 14: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien Anty-Glitch'a.",
							0, size);			
						}
					}
				}	
				case 15: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Skrot do menu ustawien powiadomien.",
							0, size);	
						}
					}
				}	
				case 16: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/tcfg\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca menu ustawien druzyn.",
							0, size);				
						}
					}
				}	
				case 17: {
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"/settings\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca menu ustawien Multi A/D.",
							0, size);				
						}
					}				
				}
				case 18: { 
					switch(language) {
						case LANG_PL: {							
							strins(output, "\
								"COLOR_DIALOG_BODY"Skrot komendy: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Parametry: "C_WHITE"Brak\n\
								"COLOR_DIALOG_BODY"Opis: "COLOR_DIALOG_COUNT"Komenda wyswietlajaca informacje o rundach rozegranych w aktualnym meczu.\nAdministracja ma mozliwosc usuniecia poszczegolnych rund z ogolnego rezultatu (Head Admin)", 
							0, size);						
						}
					}
				}					
			}
		}		
	}
}