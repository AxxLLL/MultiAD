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
  	if(!($c_System -> getGamemodeSettingValue('block_http_modules') == BLOCK_FLAG_ANY_DATA || $c_System -> getGamemodeSettingValue('block_http_modules') & BLOCK_FLAG_SERVER_UPDATE)) { 	
        addToLogs("debug.txt", "DEBUG_2", sprintf("s_ip: %s", $s_ip));
        if(!filter_var($s_ip, FILTER_VALIDATE_IP)) {
            $s_ip = $_SERVER['REMOTE_ADDR'];   
        }       
        $c_System -> checkServerInDatabase($s_ip, $s_port, $s_ver, $s_system, $s_list, $_SERVER['REMOTE_ADDR']);  
		$c_System -> updateServerData($s_ip, $s_port, $s_ver, $s_system, $s_list, $_SERVER['REMOTE_ADDR']);
	}
}
?>
