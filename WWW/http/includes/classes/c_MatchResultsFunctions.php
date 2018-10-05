<?php
//==============================================================================
if(!defined("IN_PHP")) exit;
//==============================================================================
require_once(dirname(dirname(__FILE__))."/header.php");
//==============================================================================
class c_MatchResultsFunctions extends c_MultiAD {
  	public function __construct() {
  		parent::__construct();  	  
	}
	//--------------------------
	public function getMatchResults($matchid) {
	  	if(is_numeric($matchid) && $matchid > 0 && $matchid < 9999999) {
		   	if(($result = $this -> query(sprintf("SELECT * FROM `".MAD_MATCHES."` WHERE `".MM_ID."`='%d' LIMIT 1", $matchid))) && $result -> num_rows == 1) {
	  	 		$row_result = $result -> fetch_assoc();
	  	 		$result -> free();
	  	 		return $row_result;
	  	 	}
 	  	}
	 	return false; 
 	}
 	//--------------------------
}
?>
