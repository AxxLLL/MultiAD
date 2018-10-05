<?php
//=============================================================
require_once(dirname(__FILE__)."/../../../init.php");
//=============================================================
class c_SVLIST {

	public function getServerList() {
		global $MultiAD;
		if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MS_ID."`, `".MS_IP."`, `".MS_PORT."`, `".MS_SERVER_LAST_NAME."`, `".MS_USING_VERSION."` FROM `".MAD_SERVERS."` WHERE `".MS_ONLINE."` = '1' AND `".MS_LAST_UPDATE."` >= '%d' AND `".MS_LIST."` = '1' ORDER BY `".MS_PRIORITY."` DESC", time() - 7200)))) {
	//	if(($result = $MultiAD -> Database -> query(sprintf("SELECT `".MS_ID."`, `".MS_IP."`, `".MS_PORT."`, `".MS_SERVER_LAST_NAME."`, `".MS_USING_VERSION."` FROM `".MAD_SERVERS."` WHERE `".MS_LAST_UPDATE."` >= '%d' ORDER BY `".MS_PRIORITY."` DESC", time() - 86400)))) {
			if($result -> num_rows > 0) {
				$index = 0;
				$server_list = array();
				
				while(($row = $result -> fetch_assoc())) {
					$server_list[$index][MS_ID] = $row[MS_ID];
					$server_list[$index][MS_IP] = $row[MS_IP];
					$server_list[$index][MS_PORT] = $row[MS_PORT];
					$server_list[$index][MS_SERVER_LAST_NAME] = $row[MS_SERVER_LAST_NAME];
					$server_list[$index][MS_USING_VERSION] = $row[MS_USING_VERSION];
					$index ++;
				}				
				
				$result -> close();
				return $server_list;
			}
		}
		return false;
	}
}