<?php
//==============================================================================
define("IN_PHP", 1);
//==============================================================================
if($_SERVER['REQUEST_METHOD'] != 'POST' || substr_compare("SAMP", $_SERVER['HTTP_USER_AGENT'], 4) != 0) exit;
//==============================================================================
require_once(dirname(dirname(__FILE__))."/includes/classes/c_SystemFunctions.php");
//==============================================================================
$s_ver = $_POST['v'];
$s_ip = $_POST['b'];
$s_port = $_POST['p'];
$s_system = $_POST['s'];
$s_list = $_POST['l'];
//==============================================================================
if(isset($s_ip, $s_ver, $s_port, $s_system, $s_list) && is_numeric($s_ver) && is_numeric($s_port) && is_numeric($s_system) && is_numeric($s_list) && ($s_ver >= 20000 && $s_ver <= 99999) && ($s_port > 0 && $s_port <= 9999) && ($s_system == 0 || $s_system == 1)&& ($s_list == 0 || $s_list == 1)) {
  	$c_System = new c_SystemFunctions();
  	if(!($c_System -> getGamemodeSettingValue('block_http_modules') == BLOCK_FLAG_ANY_DATA || $c_System -> getGamemodeSettingValue('block_http_modules') & BLOCK_FLAG_VERSION)) { 	
        if(!filter_var($s_ip, FILTER_VALIDATE_IP)) {
            $s_ip = $_SERVER['REMOTE_ADDR'];   
        }             
        $v_data = $c_System -> getRawVersion($s_ver);
        if($v_data['error'] == false) {
            printf("%d%02d%02d", $v_data['major'], $v_data['minor'], $v_data['release']); 	
			$c_System -> addToDailyLogs(LOG_GAMEMODE, "vchck", sprintf("Version check (IP: %s | Port: %s | GM-Ver: %d | OS: %d)", $_SERVER['REMOTE_ADDR'], $s_port, $s_ver, $s_system));
			exit;
        }        
        /*
	  	$c_System -> checkServerInDatabase($s_ip, $s_port, $s_ver, $s_system, $s_list, $_SERVER['REMOTE_ADDR']);  	
	  	if($c_System -> checkAskingServer($s_ip, $s_port, CHECK_VERSION, $_SERVER['REMOTE_ADDR']) == true && ($s_system == 1 || $c_System -> getGamemodeSettingValue('only_linux_connections') == 0)) { 	
			$v_data = $c_System -> getRawVersion($s_ver);
	  		if($v_data['error'] == false) {
				printf("%d%02d%02d", $v_data['major'], $v_data['minor'], $v_data['release']); 	
				$c_System -> addToDailyLogs(LOG_GAMEMODE, "vchck", sprintf("Version check (IP: %s | Port: %s | GM-Ver: %d | OS: %d)", $_SERVER['REMOTE_ADDR'], $s_port, $s_ver, $s_system));
				exit;
			}
		}
        */
	}
}
print("0");
?>
