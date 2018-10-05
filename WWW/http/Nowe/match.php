<?php
//=============================================================
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
//=============================================================
require_once("resources/screen/screen.php");
//=============================================================
$screen_type = DEFAULT_TYPE;
$screen_language = DEFAULT_LANGUAGE;
$screen_index = -1;
//-------------------------------------------------------------
if(isset($_GET['id']) && is_numeric($_GET['id']) && $_GET['id'] > 0 && $_GET['id'] <= 999999999) $screen_index = $_GET['id'];
if(isset($_GET['type'])) {
	if(is_numeric($_GET['type']) && $_GET['type'] >= 0 && $_GET['type'] <= 3) $screen_type = $_GET['type'];
	else {
		switch($_GET['type']) {
			case 'big': 
				$screen_type = 0;
			break;		
			case 'normal': 
				$screen_type = 1;
			break;
			case 'players': 
				$screen_type = 2;
			break;
			case 'small': 
				$screen_type = 3;
			break;		
		}
	}
}
if(isset($_GET['lang']) && is_numeric($_GET['lang']) && $_GET['lang'] >= 0 && $_GET['lang'] <= 1) $screen_language = $_GET['lang'];
//-------------------------------------------------------------
if($screen_index == -1) die("Wrong screen ID");
//=============================================================
$SCREEN = new c_Screen();
if($SCREEN -> loadMatchData($screen_index)) {
	if($SCREEN -> prepareScreenShot($screen_type, $screen_language) == false) {
		die("Something went wrong... Please report this issue to administrator.");
	}
} else die("Wrong screen ID");