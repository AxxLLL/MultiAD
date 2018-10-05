<?php
if(!defined("FROM_FUNCTION")) exit;

if(preg_match("/^\{\"general\":\{\"rounds\":[0-9]{1,2}\,\"team\":\[\{\"name\":\"[a-zA-Z0-9\(\)\[\]\.\_\$\@\=]{1,8}\"\,\"points\":[0-9]{1,2}\},\{\"name\":\"[a-zA-Z0-9\(\)\[\]\.\_\$\@\=]{1,8}\"\,\"points\":[0-9]{1,2}\}\]\}\,\"round\":\[[0-9\,\`\']+\]\,\"players\":\[[a-zA-Z0-9\(\)\`\'\.\_\$\@\=\,\"]+\]\}$/D", $data)) {
	$data = str_replace("`", "[", $data);
	$data = str_replace("'", "]", $data);
	$JSON_Data = json_decode($data, true);
	if(json_last_error() == JSON_ERROR_NONE) {
		$error_occurred = false;
		$JSON_Encode = substr_replace(substr_replace(json_encode($JSON_Data['round']), "", 0, 1), "", -2);
		
		$explode_data = explode("]", $JSON_Encode);
		
		if(count($explode_data) == $JSON_Data['general']['rounds']) {
			for($i = 0; $i < count($explode_data); $i ++) {
				$explode_data[$i] = ltrim(ltrim($explode_data[$i], ","), "[");
				if(!preg_match("/^[\d]+\,[0-1]{1}\,[0-2]{1}\,[\d]{1,2}\,[0-1]{1}\,[0-9]{1,16}\,[0-1]{1}$/D", $explode_data[$i])) {
					$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "PREG_MATCH", sprintf("Error in rounds validation (ServerID: %d | Index: %d | Data: %s)", $this -> g_Server[MS_ID], $i, $explode_data[$i]));
					$error_occurred = true;
					break;
				} 
			}
			if(!$error_occurred) {
				$JSON_Encode = substr_replace(substr_replace(json_encode($JSON_Data['players']), "", 0, 1), "", -2);
				$explode_data = explode("],", $JSON_Encode);		
								
				for($i = 0; $i < count($explode_data); $i ++) {
					$explode_data[$i] = ltrim(ltrim($explode_data[$i], ","), "[");
					if(!preg_match("/^\"[a-zA-Z0-9\(\)\[\]\.\_\$\@\=]{3,24}\"\,[0-1]{1}\,[\d]{1,8}\,[\d]{1,8}\,[\d]{1,8}$/D", $explode_data[$i])) {
						$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "PREG_MATCH", sprintf("Error in players validation (ServerID: %d | Index: %d | Data: %s)", $this -> g_Server[MS_ID], $i, $explode_data[$i]));
						$error_occurred = true;
						break;
					}						
				}
				
				if(!$error_occurred) {
					if(($statement = $MultiAD -> Database -> prepare("INSERT INTO `".MAD_NEW_MATCHES."` (`".MNM_MS_ID."`,`".MNM_ADD_TIME."`,`".MNM_TEAM_1."`,`".MNM_TEAM_2."`,`".MNM_JSON_DATA."`) VALUES (?,?,?,?,?);")) != false) {
						$currTime = time();
						$statement -> bind_param("iisss", $this -> g_Server[MS_ID], $currTime, $JSON_Data['general']['team'][0]['name'], $JSON_Data['general']['team'][1]['name'], $data);
						if($statement -> execute()) {
							$statement -> close();
							if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MNM_ID."` FROM `".MAD_NEW_MATCHES."` WHERE `".MNM_MS_ID."`='%d' AND `".MNM_ADD_TIME."`='%d' ORDER BY `".MNM_ID."` DESC LIMIT 1", $this -> g_Server[MS_ID], $currTime))) && $result -> num_rows == 1) {	
								$row = $result -> fetch_row();
								$result -> close();
								$back_value = $row[0];
							} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "PREG_MATCH", sprintf("Error in getting match ID from database (ServerID: %d | Time: %d)", $this -> g_Server[MS_ID], $currTime));					
						} else {
							$MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "updateMatchResults", "Error in executing query (1)");
							$statement -> close();
						}
					} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "updateMatchResults", "Invalid query - 'prepare insert' function");
				}
			}
		} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "VALIDATION", sprintf("Error has occurred when checking total rounds value (ServerID: %d | Count: %d | JSon value: %d)", $this -> g_Server[MS_ID], count($explode_data), $JSON_Data['general']['rounds']));						
	} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "JSON", sprintf("Error in JSON function (1) (ServerID: %d | Code: %d | Data: %s)", $this -> g_Server[MS_ID], json_last_error(), $data));
} else $MultiAD -> toLogs(LOGTYPE_SPECIFIC, "match_error", "PREG_MATCH", sprintf("Error in first validation (ServerID: %d | Data: %s)", $this -> g_Server[MS_ID], $data));