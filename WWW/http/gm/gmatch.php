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
$s_round_limit = $_POST['rl'];
$s_team_1 = $_POST['t1'];
$s_team_2 = $_POST['t2'];
$s_round_info = $_POST['r'];
$s_players_info = $_POST['u'];
//==============================================================================

if(isset($s_ver, $s_ip, $s_port, $s_system, $s_list, $s_round_limit, $s_team_1, $s_team_2, $s_round_info, $s_players_info)) {
	$c_System = new c_SystemFunctions();
    
    if(!filter_var($s_ip, FILTER_VALIDATE_IP)) {
        $s_ip = $_SERVER['REMOTE_ADDR'];   
    }    
    $c_System -> checkServerInDatabase($s_ip, $s_port, $s_ver, $s_system, $s_list, $_SERVER['REMOTE_ADDR']); 
	printf("%d", $c_System -> addMatchRawData($s_ip, $s_ver, $s_port, $s_system, $s_list, $s_round_limit, $s_team_1, $s_team_2, $s_round_info, $s_players_info, $_SERVER['REMOTE_ADDR']));
	exit;
}
printf("0");
?>
