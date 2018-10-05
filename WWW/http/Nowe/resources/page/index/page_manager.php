<?php
//=============================================================
include("resources/init.php");
//=============================================================
if(isset($_GET['page'])) {
	switch($_GET['page']) {
		case 'svrlist': 
			include(dirname(__FILE__)."/../server_list/server_list.php");
		break;
		case 'matchlist': 
			include(dirname(__FILE__)."/../match_list/match_list.php");
		break;
		case 'madhelp': 
			include(dirname(__FILE__)."/../mad_help/mad_help.php");
		break;
	}
}