<?php
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);


/*
	Tabela 'MAD_SERVERS' - informacje o serwerach posiadajacych Multi A/D
	//-------------------------------------------------
	CREATE TABLE  `virt104529_multi`.`mad_servers` (
		`ms_id` INT( 11 ) NOT NULL AUTO_INCREMENT ,
		`ms_ip` INT( 10 ) UNSIGNED NOT NULL ,
		`ms_port` SMALLINT( 5 ) UNSIGNED NOT NULL ,
		`ms_register` INT( 10 ) UNSIGNED NOT NULL ,
		`ms_using_version` SMALLINT( 5 ) UNSIGNED NOT NULL ,
		`ms_system` TINYINT( 3 ) UNSIGNED NOT NULL ,
		`ms_last_update` INT( 10 ) UNSIGNED NOT NULL DEFAULT  '0',
		`ms_last_match_update` INT( 10 ) UNSIGNED NOT NULL DEFAULT  '0',
		`ms_list` TINYINT( 3 ) UNSIGNED NOT NULL DEFAULT  '1',
		`ms_p_warnings` TINYINT( 3 ) UNSIGNED NOT NULL DEFAULT  '0',
		`ms_block` TINYINT( 3 ) UNSIGNED NOT NULL DEFAULT  '0',
		PRIMARY KEY (  `ms_id` ) ,
		KEY  `ms_using_version` (  `ms_using_version` )
	) ENGINE = INNODB DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;

*/
/*
	Tabela 'MAD_MATCHES' - informacje o meczach rozgrywanych na modzie Multi A/D
	//-------------------------------------------------
	CREATE TABLE  `virt104529_multi`.`mad_matches` (
		`mm_id` INT( 10 ) UNSIGNED NOT NULL AUTO_INCREMENT ,
	 	`mm_ms_id` INT( 10 ) UNSIGNED NOT NULL ,
	 	`mm_add_time` INT( 10 ) UNSIGNED NOT NULL ,
	 	`mm_team_1` VARCHAR( 32 ) COLLATE utf8_unicode_ci NOT NULL ,
		`mm_team_2` VARCHAR( 32 ) COLLATE utf8_unicode_ci NOT NULL ,
		`mm_round_limit` TINYINT( 3 ) UNSIGNED NOT NULL ,
		`mm_round_info` VARCHAR( 512 ) COLLATE utf8_unicode_ci NOT NULL ,
		`mm_players_info` VARCHAR( 2048 ) COLLATE utf8_unicode_ci NOT NULL ,
		PRIMARY KEY (  `mm_id` )
	) ENGINE = INNODB DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;
*/
/*
	Tabela 'MAD_VERSION' - informacje o wersjach moda Multi A/D
	//-------------------------------------------------
	CREATE TABLE  `virt104529_multi`.`mad_version` (
		`mv_id` INT( 11 ) NOT NULL AUTO_INCREMENT ,
	 	`mv_available` TINYINT( 3 ) UNSIGNED NOT NULL ,
	 	`mv_v_major` TINYINT( 3 ) UNSIGNED NOT NULL ,
	 	`mv_v_minor` TINYINT( 3 ) UNSIGNED NOT NULL ,
	 	`mv_v_release` TINYINT( 3 ) UNSIGNED NOT NULL ,
	 	`mv_v_special` VARCHAR( 64 ) COLLATE utf8_unicode_ci NOT NULL DEFAULT  'NoN',
	 	`mv_download` VARCHAR( 128 ) COLLATE utf8_unicode_ci NOT NULL ,
	 	`mv_date` INT( 11 ) UNSIGNED NOT NULL ,
	 	`mv_changelog` TEXT COLLATE utf8_unicode_ci NOT NULL ,
		PRIMARY KEY (  `mv_id` )
	) ENGINE = INNODB DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;
*/
//==============================================================================
if(!defined("IN_PHP")) exit;
//==============================================================================
require_once(dirname(dirname(__FILE__))."/header.php");
//==============================================================================
class c_SystemFunctions extends c_MultiAD {
  	public function __construct() {
  		parent::__construct();  
  	}  	
  	//--------------------------
  	public function checkServerInDatabase($ip, $port, $ver, $system, $list, $remote_addr) {
  	  	if(filter_var($ip, FILTER_VALIDATE_IP) && (is_numeric($port) && $port >= 1000 && $port <= 99999) && (is_numeric($ver) && $ver >= 20000 && $ver <= 99999) && (is_numeric($system) && ($system == 0 || $system == 1)) && (is_numeric($list) && ($list == 0 || $list == 1))) {
	  	  	if($this -> getSystemSettingValue('new_db_servers') == 1 && ($result = $this -> query(sprintf("SELECT `".MS_ID."`, `".MS_LAST_UPDATE."`, `".MS_P_WARNINGS."`, `".MS_BLOCK."` FROM `".MAD_SERVERS."` WHERE `".MS_IP."`='%d' AND `".MS_PORT."`='%d' LIMIT 1", ($real_ip = ip2long($ip)), $port)))) {
	  	  	 	if($result -> num_rows == 0) {
				    $this -> query(sprintf("INSERT INTO `".MAD_SERVERS."` (`".MS_REMOTE_IP."`, `".MS_IP."`, `".MS_PORT."`, `".MS_REGISTER."`, `".MS_USING_VERSION."`, `".MS_SYSTEM."`, `".MS_LAST_UPDATE."`, `".MS_LIST."`) VALUES ('%d', '%d', '%d', '%d', '%d', '%d', '%d', '%d');", ip2long($remote_addr), $real_ip, $port, time(), $ver, $system, time(), $list));
                    addToDailyLogs(LOG_GAMEMODE, "checkServerInDatabase", sprintf("Added new server to database (IP: %s | Port: %s | GM-Ver: %d | OS: %d | List: %d | Remote: %s)", $ip, $port, $ver, $system, $list, $remote_addr));
				   	return true;
				} 
		  	} else addToDailyLogs(LOG_GAMEMODE, "checkServerInDatabase", sprintf("Error in adding new server to database (2)"));
	  	} else addToDailyLogs(LOG_GAMEMODE, "checkServerInDatabase", sprintf("Error in adding new server to database (1)"));
	  	return false;
	}
	
  	//--------------------------  	
	public function checkAskingServer($ip, $port, $type, $remote_addr) {
	  	if(filter_var($ip, FILTER_VALIDATE_IP) && (is_numeric($port) && $port >= 1000 && $port <= 99999)) {
 			if(($result = $this -> query(sprintf("SELECT `".MS_ID."`, `".MS_LAST_UPDATE."`, `".MS_P_WARNINGS."`, `".MS_BLOCK."` FROM `".MAD_SERVERS."` WHERE `".MS_IP."`='%d' AND `".MS_PORT."`='%d' LIMIT 1", ip2long($ip), $port)))) {
			  	if($result -> num_rows == 1) {
	 		  	  	$row_result = $result -> fetch_assoc();
	 		  	  	$result -> free();
	 		  	  	$cfg = array("min_time" => $this -> getGamemodeSettingValue('update_connections_time'), "max_warnings" => $this -> getGamemodeSettingValue('update_connections_limit'));
	 		  	  	if(time() - $row_result[MS_LAST_UPDATE] < $cfg['min_time']) {
		  	  	  		$this -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_P_WARNINGS."`=".MS_P_WARNINGS." + 1, `".MS_LAST_UPDATE."`='%d' WHERE `".MS_ID."` = '%d'", time(), $row_result[MS_ID]));
						if($cfg['max_warnings'] <= ($row_result[MS_P_WARNINGS] + 1)) return false;
		  	  	  	} else {	  	  	  	  
					        $this -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_P_WARNINGS."`='0', `".MS_LAST_UPDATE."`='%d' WHERE `".MS_ID."` = '%d'", time(), $row_result[MS_ID]));
					}
					if($row_result[MS_BLOCK] == BLOCK_FLAG_ANY_DATA) return false;
					else {
					 	switch($type) {
						   	case CHECK_VERSION: 
						   		if($row_result[MS_BLOCK] & BLOCK_FLAG_VERSION) return false;
						   	break;
						   	case SERVER_UPDATE: 
						   	  	if($row_result[MS_BLOCK] & BLOCK_FLAG_SERVER_UPDATE) return false;
				   	  		break;
						   	default: 
							   	return false; 
				   			break;
						}				  			  		
					} 
					return true; 	  	 		  	  	
		  	  	}
		  	}
	  	}
	  	return false;
 	}  	
 	//--------------------------
 	public function updateServerData($ip, $port, $version, $system, $list, $remote_addr) {
 	  	if(filter_var($ip, FILTER_VALIDATE_IP) && (is_numeric($port) && $port >= 1000 && $port <= 99999) && (is_numeric($version) && $version >= 20000 && $version <= 99999) && (is_numeric($system) && ($system == 0 || $system == 1)) && (is_numeric($list) && ($list == 0 || $list == 1))) {
	 	  	if($this -> checkAskingServer($ip, $port, SERVER_UPDATE) == true) {
	 	  	 	$this -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_REMOTE_IP."`='%d', `".MS_USING_VERSION."`='%d', `".MS_SYSTEM."`='%d', `".MS_LAST_UPDATE."`='%d', `".MS_LIST."`='%d' WHERE `".MS_IP."`='%d' AND `".MS_PORT."`='%d'", ip2long($remote_addr), $version, $system, time(), $list, ip2long($ip), $port)); 
                return true;
	  	  	}
 	  	}
  	  	return false;
 	}
  	//--------------------------
	public function getRawVersion($gm_version) {
	  	$v_array = array("error" => true);
	  	if((is_numeric($gm_version) and $gm_version >= 20000 and $gm_version <= 99999)) {
	  		if(($result = $this -> query("SELECT `".MV_MAJOR."`, `".MV_MINOR."`, `".MV_RELEASE."` FROM `".MAD_VERSION."` WHERE `".MV_AVAILABLE."`='1' ORDER BY `".MV_MAJOR."` DESC, `".MV_MINOR."` DESC, `".MV_RELEASE."`DESC LIMIT 1")) and $result -> num_rows == 1) {
			   	$row = $result -> fetch_assoc();
				$v_array['major'] = $row[MV_MAJOR];
				$v_array['minor'] = $row[MV_MINOR];
				$v_array['release'] = $row[MV_RELEASE];
				$v_array['error'] = false;
				$result -> free();
 		  	}
 	  	} 
		return $v_array;
   	}
   	//--------------------------   	
	public function addMatchRawData($ip, $ver, $port, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr) {
	  	$log_file = "matches.txt";	  
		if(filter_var($ip, FILTER_VALIDATE_IP) && is_numeric($ver) && is_numeric($port) && is_numeric($system) && is_numeric($list) && is_numeric($round_limit) && is_string($team_1) && is_string($team_2) && is_string($round_info) && is_string($players_info)) {
			if(($ver >= 20000 && $ver <= 99999) && ($port > 0 && $port <= 99999) && ($system == 0 || $system == 1) && ($list == 0 || $list == 1) && ($round_limit >= 3 && $round_limit <= 11)) {
				if(($this -> getGamemodeSettingValue('only_linux_connections') == 0 || $system == 1) && $this -> getGamemodeSettingValue('block_http_modules') != BLOCK_FLAG_ANY_DATA && !($this -> getGamemodeSettingValue('block_http_modules') & BLOCK_FLAG_MATCH) && $this -> getSystemSettingValue('new_db_servers') == 1) {
			  		global $preg_match;
			  		if(preg_match($preg_match['check_srv_data_team'], $team_1) && preg_match($preg_match['check_srv_data_team'], $team_2) && preg_match('/^[0-9\:\,\|]{1,}$/D', $round_info) && preg_match('/^[A-Za-z0-9\[\]\(\)\.\_\$\@\=\:\,\|]{1,}$/D', $players_info)) {
			  		  	$rounds = explode("|", $round_info);
			  		  	if(count($rounds) == $round_limit) {
		 		  	  		for($i = 0; $i < $round_limit; $i ++) {
		 		  	  		 	if(!preg_match($preg_match['check_srv_data_round_info'], $rounds[$i])) {
							 		return 0;       
								} 												
			  	  		  	}
				  		  	$players = explode("|", $players_info);
				  		  	if(($p_count = count($players)) > 0 && $p_count < 1000) {
		  		  	  			for($i = 0; $i < $p_count; $i ++) {
			 		  	  		 	if(!preg_match($preg_match['check_srv_data_player_info'], $players[$i])) {
								 		return 0;      
									}   		  	  			  
			  	  			  	}
			  	  			  	//$this -> checkServerInDatabase($ip, $port, $ver, $system, $list, $remote_addr);
			  	  			  	if(($result = $this -> query(sprintf("SELECT `".MS_ID."`, `".MS_LAST_MATCH_UPDATE."`, `".MS_BLOCK."` FROM `".MAD_SERVERS."` WHERE `".MS_IP."`='%d' AND `".MS_PORT."`='%d' LIMIT 1", ip2long($ip), $port))) && $result -> num_rows == 1) {
									$row_result = $result -> fetch_assoc();
			  	  			  	  	$result -> free();
			  	  			  	  	if(((($add_time = time()) - $row_result[MS_LAST_MATCH_UPDATE]) > 600) && !($row_result[MS_BLOCK] == BLOCK_FLAG_ANY_DATA || $row_result[MS_BLOCK] & BLOCK_FLAG_MATCH)) {
										$this -> query(sprintf("UPDATE `".MAD_SERVERS."` SET `".MS_LAST_MATCH_UPDATE."`='%d', `".MS_LAST_UPDATE."`='%d', `".MS_SYSTEM."`='%d', `".MS_LIST."`='%d', `".MS_USING_VERSION."`='%d' WHERE `".MS_ID."`='%d'", $add_time, $add_time, $system, $list, $ver, $row_result[MS_ID])); 
			  	  			  	  	 	$this -> query(sprintf("INSERT INTO `".MAD_MATCHES."` (`".MM_MS_ID."`, `".MM_ADD_TIME."`, `".MM_TEAM_1."`, `".MM_TEAM_2."`, `".MM_ROUND_LIMIT."`, `".MM_ROUND_INFO."`, `".MM_PLAYERS_INFO."`) VALUES ('%d', '%d', '%s', '%s', '%d', '%s', '%s');", $row_result[MS_ID], $add_time, $this -> real_escape_string($team_1), $this -> real_escape_string($team_2), $round_limit, $this -> real_escape_string($round_info), $this -> real_escape_string($players_info))); 
										if(($result = $this -> query(sprintf("SELECT `".MM_ID."` FROM `".MAD_MATCHES."` WHERE `".MM_ADD_TIME."`='%d' AND `".MM_MS_ID."`='%d' LIMIT 1", $add_time, $row_result[MS_ID]))) && $result -> num_rows == 1) {
											$id = $result -> fetch_row();
											addToLogs($log_file, "addMatchRawData", sprintf("Added new match result (%d): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $id, $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));
											return $id[0];
								  		} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (6): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));
	  	  			  	  	  		}			  	  			  	  	
	  	  			  	  		} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (5): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));
			 		  	  	}					      	  		  	  
		 		  	  	} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (4): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));	  		  
		 		  	} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (3): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr)); 	 	  
			  	}
	  		} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (2): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));
	 	} else addToLogs($log_file, "addMatchRawData", sprintf("Error in add (1): %s, %d, %d, %d, %d, %d, %s, %s, %s, %s, %s", $ip, $port, $ver, $system, $list, $round_limit, $team_1, $team_2, $round_info, $players_info, $remote_addr));
		return 0;	  
	}
}
?>
