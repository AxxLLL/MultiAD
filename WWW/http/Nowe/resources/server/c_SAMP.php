<?php
//=============================================================
define("SAMP_TYPE_VERSION", 		1);
define("SAMP_TYPE_UPDATE", 			2);
define("SAMP_TYPE_MATCH_RESULT", 	3);
//=============================================================
require_once(dirname(__FILE__)."/../init.php");
//=============================================================
class c_SAMP {
	//=============================================================
	private $g_Server = array();
	private $g_Settings = array();
	//=============================================================
	public function __construct() {
		if(file_exists("settings.ini")) {
			$this -> g_Settings = parse_ini_file("settings.ini");
		} 
		if(!array_key_exists("auto_block_time_minutes", $this -> g_Settings) || $this -> g_Settings['auto_block_time_minutes'] <= 0 || $this -> g_Settings['auto_block_time_minutes'] > 1440) $this -> g_Settings['auto_block_time_minutes'] = 10;
		
		if(!array_key_exists("update_connections_limit", $this -> g_Settings) || $this -> g_Settings['update_connections_limit'] <= 0 || $this -> g_Settings['update_connections_limit'] > 99) $this -> g_Settings['update_connections_limit'] = 10;
		if(!array_key_exists("update_connections_time", $this -> g_Settings) || $this -> g_Settings['update_connections_time'] <= 0 || $this -> g_Settings['update_connections_time'] > 93600) $this -> g_Settings['update_connections_time'] = 60;
		
		if(!array_key_exists("only_linux_connections", $this -> g_Settings) || !is_bool($this -> g_Settings['only_linux_connections'])) $this -> g_Settings['only_linux_connections'] = false;
		if(!array_key_exists("block_http_modules", $this -> g_Settings) || !is_bool($this -> g_Settings['block_http_modules'])) $this -> g_Settings['block_http_modules'] = false;
		if(!array_key_exists("new_db_servers", $this -> g_Settings) || !is_bool($this -> g_Settings['new_db_servers'])) $this -> g_Settings['new_db_servers'] = true;
		
		if(!array_key_exists("match_results_limit", $this -> g_Settings) || $this -> g_Settings['match_results_limit'] <= 0 || $this -> g_Settings['match_results_limit'] > 99) $this -> g_Settings['match_results_limit'] = 5;
		if(!array_key_exists("match_results_time", $this -> g_Settings) || $this -> g_Settings['match_results_time'] <= 0 || $this -> g_Settings['match_results_time'] > 93600) $this -> g_Settings['match_results_time'] = 60;
	}	
	//=============================================================
	public function getServerSetting($key) {
		if(isset($key) && array_key_exists($key, $this -> g_Settings)) {
			return $this -> g_Settings[$key];
		}
		return null;
	}
	//-------------------------------------------------------------
	public function getServerData($key) {
		if(isset($key) && array_key_exists($key, $this -> g_Server)) {
			return $this -> g_Server[$key];
		}
		return null;
	}
	//-------------------------------------------------------------
	public function prepareServerData($version, $data) {
		if(is_numeric($version) && is_string($data)) {
			global $MultiAD;
			//-----------------------
			if($version >= 20003) {
				$this -> g_Server['version'] = strval($version);
				if(preg_match("/^\[[1-3]{1}\|[0-9\.]{1,15}\|[0-9]{4}\|[0-1]{1}\|[0-1]{1}\]$/D", $data)) {
					list($this -> g_Server['type'], $this -> g_Server['bind'], $this -> g_Server['port'], $this -> g_Server['system'], $this -> g_Server['list']) = explode("|", str_replace(array("[", "]"), "", $data));
					if(!filter_var($this -> g_Server['bind'], FILTER_VALIDATE_IP)) {
						if($this -> g_Server['bind'] == "0") {
							$this -> g_Server['bind'] = $_SERVER['REMOTE_ADDR'];
						} else {
							$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "prepareServerData", "Invalid IP (".($this -> g_Server['bind']).") in data ".$data." (Version: ".$version.")");
							return false;
						}
					}					
					return true;
				} else {
					$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "prepareServerData", "Invalid RegEx in data ".$data." (Version: ".$version.")");
				}
			}
			//-----------------------
		}
		return false;
	}
	//=============================================================
	public function getGamemodeVersion($raw_type = false) {
		global $MultiAD;
		$version = "0";
		if(($result = $MultiAD -> Database -> query("SELECT `".MV_MAJOR."`, `".MV_MINOR."`, `".MV_RELEASE."` FROM `".MAD_VERSION."` WHERE `".MV_AVAILABLE."`='1' ORDER BY `".MV_MAJOR."` DESC, `".MV_MINOR."` DESC, `".MV_RELEASE."`DESC LIMIT 1")) && $result -> num_rows == 1) {
			$row = $result -> fetch_assoc();
			$version = sprintf(($raw_type ? ("%d%02d%02d") : ("%d.%d.%d")), $row[MV_MAJOR], $row[MV_MINOR], $row[MV_RELEASE]);
			$result -> close();
		}
		return $version;
	}
	//-------------------------------------------------------------
	public function updateServerData($data) {
		global $MultiAD;
		$data = str_replace(array("[", "]"), "", $data);
		if(is_numeric($data) && (strval($data) == 0 || strval($data) == 1)) { 
			if(($statement = $MultiAD -> Database -> prepare("UPDATE `".MAD_SERVERS."` SET `".MS_USING_VERSION."`=?, `".MS_SYSTEM."`=?, `".MS_LIST."`=?, `".MS_ONLINE."`=? WHERE `".MS_ID."`=?")) != false) {
				$statement -> bind_param("iiiii", $this -> g_Server['version'], $this -> g_Server['system'], $this -> g_Server['list'], $data, $this -> g_Server[MS_ID]);
				$statement -> execute();
				$statement -> close();				
				
				if(strval($data) == 1) {
					//-----------------------------
					$ip = $this -> g_Server['bind'];
					$port = $this -> g_Server['port'];
					//-----------------------------
					$aIPAddr = explode('.', $ip);		 
					$sPacket = "SAMP";              
					$sPacket .= chr($aIPAddr[0]);                                        
					$sPacket .= chr($aIPAddr[1]);             
					$sPacket .= chr($aIPAddr[2]);                              
					$sPacket .= chr($aIPAddr[3]);                               
					$sPacket .= chr($port & 0xFF);                                  
					$sPacket .= chr($port >> 8 & 0xFF);                            
					$sPacket .= "i";   
					if(($rSocket = fsockopen('udp://'.$ip, $port, $iError, $sError, 2)) != false) {   
						stream_set_timeout($rSocket, 2);
						fwrite($rSocket, $sPacket);                                  		 
						$return_data = fread($rSocket, 2048);					 
						fclose($rSocket); 
						if(strlen($return_data) > 0 && !strncmp($return_data, "SAMP", 4)) {
							$hostname = htmlentities(substr($return_data, 20, ord($return_data[16])));
							if(($statement = $MultiAD -> Database -> prepare("UPDATE `".MAD_SERVERS."` SET `".MS_SERVER_LAST_NAME."`=? WHERE `".MS_ID."`=?")) != false) {
								$statement -> bind_param("sd", $hostname, $this -> g_Server[MS_ID]);
								if(!($statement -> execute())) $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerData", "Error in statement execute");
								$statement -> close();
							} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerData", "Invalid query - update last name data");
						}    
					}
					//-----------------------------
				}
				return true;
			} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerData", "Invalid query - update server data");
		} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerData", "Invalid param");
		return false;
	}
	//-------------------------------------------------------------
	public function updateServerLastConnectionTime() {
		global $MultiAD;
		if((($this -> getServerSetting('update_connections_time')) + ($this -> g_Server[MS_LAST_UPDATE])) > time()) {
			$this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS] ++;				
			if($this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS] >= $this -> getServerSetting('update_connections_limit')) {
				$this -> g_Server[MS_UPDATE_BLOCK_TIME] = time() + (($this -> getServerSetting('auto_block_time_minutes')) * 60);
				$this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS] = 0;
				$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "server_block", "Connection Block", "New server has been added to block list (ID: ".$this -> g_Server[MS_ID].")");
			}
		} else {
			$this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS] = 0;
			$this -> g_Server[MS_UPDATE_BLOCK_TIME] = 0;		
		}
		$this -> g_Server[MS_LAST_UPDATE] = time();
		
		if(($MultiAD -> Database -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_REMOTE_IP."`='%d', `".MS_LAST_UPDATE."`='%d', `".MS_UPDATE_CONNECTION_WARNINGS."`='%d', `".MS_UPDATE_BLOCK_TIME."`='%d' WHERE `".MS_ID."`='%d'", ip2long($_SERVER['REMOTE_ADDR']), time(), $this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS], $this -> g_Server[MS_UPDATE_BLOCK_TIME], $this -> g_Server[MS_ID]))) == false) {
			$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerLastConnectionTime", "Invalid query - update last 'server update' time");
		}
		
		return ($this -> g_Server[MS_UPDATE_BLOCK_TIME] > time()) ? false : true;
	}
	//-------------------------------------------------------------
	public function updateServerLastMatchTime() {
		global $MultiAD;
		if((($this -> getServerSetting('match_results_time')) + ($this -> g_Server[MS_LAST_MATCH_UPDATE])) > time()) {
			$this -> g_Server[MS_MATCH_RESULTS_WARNINGS] ++;				
			if($this -> g_Server[MS_MATCH_RESULTS_WARNINGS] >= $this -> getServerSetting('match_results_limit')) {
				$this -> g_Server[MS_MATCH_BLOCK_TIME] = time() + (($this -> getServerSetting('auto_block_time_minutes')) * 60);
				$this -> g_Server[MS_MATCH_RESULTS_WARNINGS] = 0;
				$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "server_block", "Match Block", "New server has been added to block list (ID: ".$this -> g_Server[MS_ID].")");
			}
		} else {
			$this -> g_Server[MS_MATCH_RESULTS_WARNINGS] = 0;
			$this -> g_Server[MS_MATCH_BLOCK_TIME] = 0;		
		}
		$this -> g_Server[MS_LAST_MATCH_UPDATE] = time();
		
		if(($MultiAD -> Database -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_REMOTE_IP."`='%d', `".MS_LAST_MATCH_UPDATE."`='%d', `".MS_MATCH_RESULTS_WARNINGS."`='%d', `".MS_MATCH_BLOCK_TIME."`='%d' WHERE `".MS_ID."`='%d'", ip2long($_SERVER['REMOTE_ADDR']), time(), $this -> g_Server[MS_MATCH_RESULTS_WARNINGS], $this -> g_Server[MS_MATCH_BLOCK_TIME], $this -> g_Server[MS_ID]))) == false) {
			$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "updateServerLastConnectionTime", "Invalid query - update last 'server update' time");
		}
		
		return ($this -> g_Server[MS_MATCH_BLOCK_TIME] > time()) ? false : true;
	}
	//-------------------------------------------------------------
	public function loadServerData() {
		global $MultiAD;
		if(($results = $MultiAD -> Database -> query(sprintf("SELECT * FROM `".MAD_SERVERS."` WHERE `".MS_IP."`='%d' AND `".MS_PORT."`='%d' LIMIT 1", ip2long($this -> g_Server['bind']), $this -> g_Server['port']))) != false && $results -> num_rows == 1) {
			$row = $results -> fetch_assoc();
				
			foreach($row as $key => $value) {
				$this -> g_Server[$key] = $value;
			}
				
			$results -> close();
			return true;
		} else {
			if($this -> getServerSetting('new_db_servers')) {
				if(($statement = $MultiAD -> Database -> prepare("INSERT INTO `".MAD_SERVERS."` (`".MS_REMOTE_IP."`, `".MS_IP."`, `".MS_PORT."`, `".MS_REGISTER."`, `".MS_USING_VERSION."`, `".MS_SYSTEM."`, `".MS_LAST_UPDATE."`, `".MS_LAST_MATCH_UPDATE."`, `".MS_LIST."`, `".MS_UPDATE_CONNECTION_WARNINGS."`, `".MS_MATCH_RESULTS_WARNINGS."`, `".MS_BLOCK."`, `".MS_MATCH_BLOCK_TIME."`, `".MS_UPDATE_BLOCK_TIME."`, `".MS_ONLINE."`, `".MS_PRIORITY."`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);")) != false) {
					$zero = 0;
					$one = 1;
					$statement -> bind_param("iiiiiiiiiiiiiiii", ip2long($_SERVER['REMOTE_ADDR']), ip2long($this -> g_Server['bind']), $this -> g_Server['port'], time(), $this -> g_Server['version'], $this -> g_Server['system'], $zero, $zero, $this -> g_Server['list'], $zero, $zero, $zero, $zero, $zero, $one, $zero);
					if($statement -> execute()) {
						$statement -> close();
						if(($statement = $MultiAD -> Database -> prepare("SELECT `".MS_ID."` FROM `".MAD_SERVERS."` WHERE `".MS_IP."`=? AND `".MS_PORT."`=?")) != false) {
							$statement -> bind_param("ii", ip2long($this -> g_Server['bind']), $this -> g_Server['port']);
							$statement -> execute();
							$statement -> store_result();
								
							$this -> g_Server[MS_REMOTE_IP] = $_SERVER['REMOTE_ADDR'];
							$this -> g_Server[MS_IP] = $this -> g_Server['bind'];
							$this -> g_Server[MS_PORT] = $this -> g_Server['port'];
							$this -> g_Server[MS_REGISTER] = 0;
							$this -> g_Server[MS_USING_VERSION] = $this -> g_Server['version'];
							$this -> g_Server[MS_SYSTEM] = $this -> g_Server['system']; 
							$this -> g_Server[MS_LAST_UPDATE] = 0;
							$this -> g_Server[MS_LAST_MATCH_UPDATE] = 0;
							$this -> g_Server[MS_LIST] = $this -> g_Server['list']; 
							$this -> g_Server[MS_UPDATE_CONNECTION_WARNINGS] = 0;
							$this -> g_Server[MS_MATCH_RESULTS_WARNINGS] = 0;
							$this -> g_Server[MS_BLOCK] = 0;
							$this -> g_Server[MS_MATCH_BLOCK_TIME] = 0;
							$this -> g_Server[MS_UPDATE_BLOCK_TIME] = 0;
							$this -> g_Server[MS_ONLINE] = 0;
							$this -> g_Server[MS_PRIORITY] = 0;
							
							if($statement -> num_rows == 1) {
								$statement -> bind_result($res_id);
								$statement -> fetch();									
								$this -> g_Server[MS_ID] = $res_id;
								$statement -> free_result();
								$statement -> close();
								return true;
							} else {
								$this -> g_Server[MS_ID] = -1;
								$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "loadServerData", "Error has occurred when trying to get server ID");
							}
						} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "loadServerData", "Invalid query - checking server ID");
					} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "loadServerData", "Error has occurred when add new server to database");
					$statement -> close();
				} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "samp_data", "loadServerData", "Invalid query - 'prepare insert' function");
				
			} else {
				$this -> g_Server[MS_ID] = -1;
				return true;
			}
		}
		return false;
	}
	//-------------------------------------------------------------
	public function updateMatchResults($data) {
		define("FROM_FUNCTION", 1);
		global $MultiAD;
		$back_value = false;
		if(array_key_exists("version", $this -> g_Server) && ($this -> g_Server['version']) >= 20003) {
			if(file_exists(dirname(__FILE__)."/versions/20003.php")) include(dirname(__FILE__)."/versions/20003.php");
		}		
		return $back_value;
	}
}