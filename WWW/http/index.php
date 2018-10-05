<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if($_SERVER['HTTP_HOST'] != 'mad.highskill.eu') exit;
//==============================================================================
define("IN_PHP", 1);
//==============================================================================
require_once("./includes/header.php");
//==============================================================================
global $preg_match;
//------------------------------------------------------------------------------
$module = $_GET['id'];
$show_body = true;
//==============================================================================
if(isset($module) && preg_match($preg_match['site_module'], $module) && is_dir('modules')) {
	switch($module) {
	 	case 'srv': 
	 		if(file_exists("modules/server_list.php")) {
	 		  	include("./modules/server_list.php");
                $show_body = false;
		  	}
		break;
	}
} 
//==============================================================================
if($show_body) require_once("./body/b_index.php");
//==============================================================================
?>
