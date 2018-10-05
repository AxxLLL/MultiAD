<?php 
if(!defined("IN_PHP")) exit;
define("IN_HEADER", 1);
//==============================================================================
require_once("tables.php");
require_once("definitions.php");
//==============================================================================
global $preg_match;
$preg_match = array(
	"download" => "/^[A-Za-z0-9]{1,16}\.(zip|rar)$/D",
	"site_module" => "/^[a-z]{1,16}$/D",
	"samp_rule_name" => "/^[a-z]{5,9}$/D",
	"check_srv_data_team" => "/^[a-zA-Z0-9\(\)\[\]\.\_\$\@\=]{1,8}\:[0-9]{1,2}$/D",
	"check_srv_data_round_info" => "/^[0-9]{1,2}\:[0-9]{1,4}\,[0-1]{1}\,[0-2]{1}\,[0-9]{1,2}\,[0-1]{1}\,[0-9]{1,16}\,[0-1]{1}$/D",
	"check_srv_data_player_info" => "/^[a-zA-Z0-9\(\)\[\]\.\_\$\@\=]{3,24}\:[0-2]{1}\,[0-9]{1,8}\,[0-9]{1,8}\,[0-9]{1,8}$/D"
);
//==============================================================================
function addToDailyLogs($folder, $from, $log) {
  	if(is_string($log) && is_dir(dirname(dirname(__FILE__))."/logs/".$folder)) {
  		$date = getdate();
		$f_log = fopen(sprintf(dirname(dirname(__FILE__))."/logs/".$folder."/%d-%02d-%02d.txt", $date['year'], $date['mon'], $date['mday']), 'a');
		fwrite($f_log, sprintf("\r\n[%02d:%02d:%02d (%s)] %s", $date['hours'], $date['minutes'], $date['seconds'], $from, htmlspecialchars(trim($log))));
 		fclose($f_log);
 		return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------
function addToLogs($file, $from, $log) {
  	if(is_string($log) && is_dir(dirname(dirname(dirname(__FILE__))."/logs/".$file))) {
  	  	$file = dirname(dirname(__FILE__))."/logs/".$file;
  		$date = getdate();
		$f_log = fopen($file, 'a');
		
		fwrite($f_log, sprintf("\r\n(%d-%02d-%02d [%02d:%02d:%02d]) <%s> %s", $date['year'], $date['mon'], $date['mday'], $date['hours'], $date['minutes'], $date['seconds'], $from, htmlspecialchars(trim($log))));
 		fclose($f_log);
 		return 1;
	}
	return 0;
}
//==============================================================================
class c_MultiAD extends mysqli {
  	private $multi_ad;
	private $mysql_Data = array("host" => "localhost", "user" => "virt104529_usera", "password" => "8U1LWjp0", "database" => "virt104529_multi");
  	//--------------------------
	public function __construct() {
	  	$multi_ad = parent::__construct($this -> mysql_Data['host'], $this -> mysql_Data['user'], $this -> mysql_Data['password'], $this -> mysql_Data['database']);
	  	if($multi_ad -> connect_error) {
	  	 	die("Error in connection to MySQL database"); 
 	  	}	  
 	} 
  	//--------------------------
  	public function getGamemodeSettingValue($setting) {
  	   	if(is_string($setting) && is_dir($_SERVER['DOCUMENT_ROOT']."/includes/settings") && file_exists($_SERVER['DOCUMENT_ROOT']."/includes/settings/settings.ini")) {
		     $a_settings = parse_ini_file($_SERVER['DOCUMENT_ROOT']."/includes/settings/settings.ini", true);
		     return array_key_exists($setting, $a_settings['gamemode']) ? $a_settings['gamemode'][$setting] : 0;
		} 
   		return 0;
  	}
   	//--------------------------
  	public function getSystemSettingValue($setting) {
  	   	if(is_string($setting) && is_dir($_SERVER['DOCUMENT_ROOT']."/includes/settings") && file_exists($_SERVER['DOCUMENT_ROOT']."/includes/settings/settings.ini")) {
		     $a_settings = parse_ini_file($_SERVER['DOCUMENT_ROOT']."/includes/settings/settings.ini", true);
		     return array_key_exists($setting, $a_settings['system']) ? $a_settings['system'][$setting] : 0;
		} 
   		return 0;		
  	} 	
  	//--------------------------
  	public function getServerDataByID($id) {
  	 	if(is_numeric($id) && $id > 0 && $id < 9999999) {
		     	if(($result = $this -> query(sprintf("SELECT * FROM `".MAD_SERVERS."` WHERE `".MS_ID."`='%d' LIMIT 1", $id))) && $result -> num_rows == 1) {
		       		$server_info = $result -> fetch_assoc();
		       		$result -> free();
		       		return $server_info;		
       			}
		} 
		return false;
 	}
}
//==============================================================================
?>
