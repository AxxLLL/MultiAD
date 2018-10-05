<?php
//=============================================================
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
//=============================================================
require_once("resources/server/c_SAMP.php");
//=============================================================
if(!isset($_POST['ver'], $_POST['data']) || $_SERVER['REQUEST_METHOD'] != 'POST' || substr_compare("SAMP", $_SERVER['HTTP_USER_AGENT'], 0, 4) != 0) echo "-4";
else {
	
	$SAMP = new c_SAMP();		
	
	if($SAMP -> getServerSetting('block_http_modules') != true && $SAMP -> prepareServerData(strval($_POST['ver']), $_POST['data']) != false && $SAMP -> loadServerData() != false && $SAMP -> getServerData(MS_BLOCK) < time()) {
		switch($SAMP -> getServerData('type')) {
			case SAMP_TYPE_VERSION:
				echo $SAMP -> getGamemodeVersion(true);
			break;
			case SAMP_TYPE_UPDATE:
				if($SAMP -> getServerData(MS_ID) > 0 && ($SAMP -> getServerSetting('only_linux_connections') == false || $SAMP -> getServerData('system') == 1)) {
					if(!($SAMP -> updateServerLastConnectionTime())) echo "-1";
					else {
						if(isset($_POST['special'])) {
							if($SAMP -> updateServerData($_POST['special'])) echo "1";
							else echo "0";
						} else echo "-5";
					}
				}
			break;
			case SAMP_TYPE_MATCH_RESULT: 
				if($SAMP -> getServerData(MS_ID) > 0 && ($SAMP -> getServerSetting('only_linux_connections') == false || $SAMP -> getServerData('system') == 1)) {
					
					if(!($SAMP -> updateServerLastMatchTime())) echo "-1";					
					else {
						if(isset($_POST['special'])) {
							if(($id = $SAMP -> updateMatchResults($_POST['special'])) != false) echo $id;
							else echo "0";
						} else echo "-5";
					}
				}	
			break;
			default: 
				echo "-2";
			break;
		}
	
	} else echo "-3";
}