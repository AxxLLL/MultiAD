<?php
//=============================================================
define("DEFAULT_TYPE", 0);
define("DEFAULT_LANGUAGE", 0);
//=============================================================
require_once(dirname(__FILE__)."/../init.php");
//=============================================================
class c_Screen {
	//=============================================================
	private $screen_data = array();
	private $screen_JSON = array();
	//=============================================================
	public function __construct() {
		
	}
	//=============================================================
	public function loadMatchData($match_id) {
		if(is_numeric($match_id) && $match_id > 0) {
			global $MultiAD;
			if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MNM_MS_ID."`, `".MNM_ADD_TIME."`, `".MNM_JSON_DATA."` FROM `".MAD_NEW_MATCHES."` WHERE `".MNM_ID."`='%d' LIMIT 1", $match_id))) != false) {
				if($result -> num_rows == 1) {
					$row = $result -> fetch_assoc();
					$result -> close();
					$this -> screen_data[MNM_ID] = $match_id;
					$this -> screen_data[MNM_MS_ID] = $row[MNM_MS_ID];
					$this -> screen_data[MNM_ADD_TIME] = $row[MNM_ADD_TIME];
					$this -> screen_JSON = json_decode($row[MNM_JSON_DATA], true);					
					if(json_last_error() == JSON_ERROR_NONE) {						
						if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MS_IP."`, `".MS_PORT."`, `".MS_SERVER_LAST_NAME."` FROM `".MAD_SERVERS."` WHERE `".MS_ID."`='%d' LIMIT 1", $this -> screen_data[MNM_MS_ID]))) != false) {
							if($result -> num_rows == 1) {
								$row = $result -> fetch_assoc();
								foreach($row as $key => $value) {
									$this -> screen_data[$key] = $value;
								}							
							} else {
								$this -> screen_data[MS_IP] = false;
								$this -> screen_data[MS_PORT] = false;
								$this -> screen_data[MS_SERVER_LAST_NAME] = "Undefined Server";
							}
							return true;
						} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "screen_logs", "loadMatchData", sprintf("Error in MySQL query (Index: 2 | Match ID: %d)", $match_id));
					} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "screen_logs", "loadMatchData", sprintf("Error in MySQL query (Index: 1 | Match ID: %d)", $match_id));	
				}
			} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "screen_logs", "loadMatchData", "Error in MySQL query");		
		}
		return false;
	}
	//-------------------------------------------------------------
	public function getMatchData($key) {
		if(isset($key) && array_key_exists($key, $this -> screen_JSON)) {
			return $this -> screen_JSON[$key];
		}
		return false;
	}
	//-------------------------------------------------------------
	public function getMatchServerData($key) {
		if(isset($key) && array_key_exists($key, $this -> screen_data)) {
			return $this -> screen_data[$key];
		}
		return false;		
	}
	//-------------------------------------------------------------
	public function prepareScreenShot($type, $language) {
		define("FROM_FUNCTION", 1);
		$return_value = false;
		
		$general_data = $this -> getMatchData('general');
		$rounds_data = $this -> getMatchData('round');
		$players_data = $this -> getMatchData('players');
		
		if($general_data != false && $rounds_data != false && $players_data != false) {
			$images_dir = (dirname(__FILE__)."/images");
			$fonts_dir = (dirname(__FILE__)."/fonts");
			if(!file_exists($images_dir)) die("Something went wrong with images... Please report this issue to administrator.");	
			if(!file_exists($fonts_dir)) die("Something went wrong with fonts... Please report this issue to administrator.");	
			
			switch($language) {
				case 1: 
					if(!file_exists(dirname(__FILE__)."/l_screen/en.php")) die("Something went wrong with language... Please report this issue to administrator.");	
					else include(dirname(__FILE__)."/l_screen/en.php");			
				break;			
				default: 
					if(!file_exists(dirname(__FILE__)."/l_screen/pl.php")) die("Something went wrong with language... Please report this issue to administrator.");	
					else include(dirname(__FILE__)."/l_screen/pl.php");
				break;
			}
			
			switch($type) {
				case 0: 
					if(file_exists(dirname(__FILE__)."/v_screen/big.php")) include(dirname(__FILE__)."/v_screen/big.php");
				break;
				case 1:
					if(file_exists(dirname(__FILE__)."/v_screen/only_results.php")) {
						include(dirname(__FILE__)."/v_screen/only_results.php");
						return true;
					}
				break;
				case 2:
					if(file_exists(dirname(__FILE__)."/v_screen/only_players.php")) {
						include(dirname(__FILE__)."/v_screen/only_players.php");
						return true;
					}
				break;
				case 3:
					if(file_exists(dirname(__FILE__)."/v_screen/small.php")) {
						include(dirname(__FILE__)."/v_screen/small.php");
						return true;
					}
				break;
				default: 
					echo "<br/>Invalid screenshot type<br/>";
				break;
			}
		} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "screen_logs", "prepareScreenShot", sprintf("Error in getting data (Match ID: %d | Type: %d | Language: %d)", $this -> getMatchServerData(MNM_ID), $type, $language));
		return false;
	}
}