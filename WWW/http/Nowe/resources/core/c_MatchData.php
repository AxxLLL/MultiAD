<?php 
class c_MatchData {
	private $match_data = false;
	private $server_data = false;
	
	public function __construct($matchid) {
		global $MultiAD;
		if(is_numeric($matchid) && $matchid > 0) {
			if(($result = $MultiAD -> Database -> query(sprintf("SELECT * FROM `".MAD_NEW_MATCHES."` WHERE `".MNM_ID."`='%d' LIMIT 1", $matchid))) != false && $result -> num_rows > 0) {
				$this -> match_data = $result -> fetch_assoc();
				$result -> close();
				if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MS_SERVER_LAST_NAME."`, `".MS_IP."`, `".MS_PORT."` FROM `".MAD_SERVERS."` WHERE `".MS_ID."`='%d' LIMIT 1", $this -> match_data[MNM_MS_ID]))) != false && $result -> num_rows > 0) {
					$this -> server_data = $result -> fetch_assoc();
					$result -> close();
				}				
			}
		}
		if($this -> match_data[MNM_ID] == false) {
			
			exit;
		}
	}
	
	public function getMatchValue($key) {
		if(isset($key) && is_string($key) && array_key_exists($key, $this -> match_data)) {
			return $this -> match_data[$key];
		}
		return false;
	}
	
	public function getMatchServerValue($key) {
		if(isset($key) && is_string($key) && array_key_exists($key, $this -> server_data)) {
			return $this -> server_data[$key];
		}
		return false;
	}
}