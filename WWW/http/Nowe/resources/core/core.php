<?php
//=============================================================
require_once("db_definitions.php");
//=============================================================
define("LOGTYPE_DAILY",		0);
define("LOGTYPE_SPECIFIC", 	1);
//=============================================================
class MAD_Core {
	/*

	*/
	//=============================================================
	public $Database;
	private $modeValues = array();
	//=============================================================
	public function __construct($host, $dbase, $user, $password) {
		$this -> Database = new mysqli($host, $user, $password, $dbase);
		$this -> Database -> set_charset("utf8");
	}
	//-------------------------------------------------------------
	public function __destruct() {
		$this -> Database -> close();
	}
	//=============================================================
	public function getValue($key) {
		if(isset($key) && array_key_exists($key, $this -> mode_settings)) {
			return $this -> mode_settings[$key];
		}
		return null;
	}
	//-------------------------------------------------------------
	public function setValue($key, $value) {
		if(isset($key, $value)) {
			$this -> mode_settings[$key] = $value;
			return true;
		}
		return false;
	}
	//-------------------------------------------------------------
	public function toLogs($type, $filename, $caption, $message) {
		$file_name;
		$dir_name = dirname(dirname(dirname(__FILE__)))."/Logs";
		if(!file_exists($dir_name)) mkdir($dir_name, 0777);
		if(isset($filename)) {
			$header;
			switch($type) {
				case LOGTYPE_DAILY:
					if(!file_exists($dir_name."/".$filename)) mkdir(($dir_name."/".$filename), 0777);
					$file_name = ($dir_name."/".$filename."/".(date("d-M-Y").".txt"));
					$header = sprintf("[%s] <%s>", date('H:i:s'), $caption);
				break;
				case LOGTYPE_SPECIFIC:
					$file_name = ($dir_name."/".$filename.".txt");
					$header = sprintf("(%s) <%s>", date('d-M-Y  [H:i:s]'), $caption);
				break;
				default: return false;
			}
			
			if(($file_handle = fopen($file_name, 'a')) != false) {
				$message = str_replace(array("\r", "\n", "\t", "\0", "\x0B"), "", $message);
				fwrite($file_handle, $header." ".$message."\r\n");
				fclose($file_handle);
				return true;
			}
		}	
		return false;
	}
	//-------------------------------------------------------------
	public function htmlLoad($page) {
		if(isset($page)) {
			$url = dirname(__FILE__)."/../page/index";
			switch($page) {
				case 'navigation_bar': include($url."/navigation_bar.php"); break;
				case 'page_manager': include($url."/page_manager.php"); break;
				case 'd_box': include($url."/d_box.php"); break;
			}
			return true;
		}
		return false;
	}
}