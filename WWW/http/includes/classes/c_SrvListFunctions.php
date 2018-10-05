<?php
//==============================================================================
if(!defined("IN_PHP")) exit;
//==============================================================================
require_once(dirname(dirname(__FILE__))."/header.php");
//==============================================================================
class c_SrvListFunctions extends c_MultiAD {
  	public function __construct() {
  		parent::__construct();  
  	}
  	//--------------------------  
	public function getServerList($use_setting = true, $limit = 100) {
	  	if(is_bool($use_setting) && is_numeric($limit) && $limit > 0 && limit < 1000) {
		  	$where = "";
		  	if($this -> getGamemodeSettingValue('only_linux_connections') == 1) $where = "`".MS_SYSTEM."`='1' AND ";
		  	if($use_setting == true) $where .= "`".MS_LIST."`='1' AND ";
		   	
		  	if(($result = $this -> query(sprintf("SELECT `".MS_IP."`, `".MS_PORT."`, `".MS_LAST_UPDATE."` FROM `".MAD_SERVERS."` WHERE %s!(`".MS_BLOCK."`&'".BLOCK_FLAG_SERVER_LIST."') AND `".MS_LAST_UPDATE."` >= ".(time()-(86400 * 2))." LIMIT %d", $where, $limit))) && $result -> num_rows > 0) {
		  	 	return $result; 
			} 
		}
		return false;
	}
	//--------------------------  
}
?>
