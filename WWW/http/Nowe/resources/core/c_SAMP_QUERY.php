<?php 
//==============================================================================
define("SAMP_PASSWORD",			0);
define("SAMP_PLAYERS",			1);
define("SAMP_MAX_PLAYERS",		2);
define("SAMP_HOST_NAME",		3);
define("SAMP_GAMEMODE",			4);
define("SAMP_MAPNAME",			5);
//------------------------------------------------------------------------------
define("SAMP_RULE_COUNT",		"rule_count");
define("SAMP_RULE_LAGCOMP",		"lagcomp");
define("SAMP_RULE_MAPNAME",		"mapname");
define("SAMP_RULE_VERSION",		"version");
define("SAMP_RULE_WEATHER",		"weather");
define("SAMP_RULE_WEBURL",		"weburl");
define("SAMP_RULE_WORLDTIME",		"worldtime");
//==============================================================================
class c_SAMP_QUERY {
	public function getSAMPServerData($ip, $port, $data) {            
	 	if(filter_var($ip, FILTER_VALIDATE_IP) && preg_match("/^[ircdxp]{1}$/D", $data) && (is_numeric($port) && ($port >= 1000 && $port <= 9999))) {
			$aIPAddr = explode('.', $ip);		 
			$sPacket = "SAMP";              
			$sPacket .= chr($aIPAddr[0]);                                        
			$sPacket .= chr($aIPAddr[1]);             
			$sPacket .= chr($aIPAddr[2]);                              
			$sPacket .= chr($aIPAddr[3]);                               
			$sPacket .= chr($port & 0xFF);                                  
			$sPacket .= chr($port >> 8 & 0xFF);                            
			$sPacket .= $data;   
			if(($rSocket = fsockopen('udp://'.$ip, $port, $iError, $sError, 2)) != false) {   
			  	stream_set_timeout($rSocket, 2);
				fwrite($rSocket, $sPacket);                                  		 
				$return_data = fread($rSocket, 2048);					 
				fclose($rSocket); 
				if(strlen($return_data) > 0) {
					return $return_data;   
				}    
			}
		}
		return false;   	 	 
	}
	//--------------------------  
	public function readSAMPRules($result) {		
		if(strncmp($result, "SAMP", 4) == 0) {
		  	$a_Rules = array(SAMP_RULE_COUNT => ord($result[11]));
		  	for($i = 0, $index = 13; $i < $a_Rules[SAMP_RULE_COUNT]; $i ++) {
  	  			$length_rule = ord($result[$index]);
  	  			$length_value = ord($result[$index + $length_rule + 1]);  
				$rule_name = substr($result, $index + 1, $length_rule);
				if(preg_match("/^[a-z]{5,9}$/D", $rule_name)) {
  	  				$a_Rules[$rule_name] = substr($result, $index + $length_rule + 2, $length_value);  	  			
				} 				
  	  			$index += $length_rule + $length_value + 2;  	  			
  	  		}
			return $a_Rules;	
  		}
  		return false;
 	}
	//--------------------------  
	public function getSAMPServerSpecificData($result, $datatype) {
	  	$output = false;
	  	if(strncmp($result, "SAMP", 4) == 0) {
 	  		switch($datatype) {
  		 		case SAMP_PASSWORD: 
  		 			$output = ord($result[11]);
  		 		break;
				case SAMP_PLAYERS:
					$output = ord($result[12]);
				break;
				case SAMP_MAX_PLAYERS:
					$output = ord($result[14]);
				break;
				case SAMP_HOST_NAME:
					$length = ord($result[16]);
					$output = substr($result, 20, $length);
				break;
				case SAMP_GAMEMODE:
					$hostname_length = ord($result[16]);
					$length = ord($result[20 + $hostname_length]);
					$output = substr($result, 24 + $hostname_length, $length);
				break;
				case SAMP_MAPNAME:
					$hostname_length = ord($result[16]);
					$gamemode_length = ord($result[20 + $hostname_length]);
					$length = ord($result[24 + $hostname_length + $gamemode_length]);
					$output = substr($result, 33 + $hostname_length, $length);				
				break;
		  		
  		  	}
 	  	}	  
	 	return $output; 
 	} 
}