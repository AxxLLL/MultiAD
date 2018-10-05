<?php
//----------------------------------------
$db_login_data = array(
	"host" => "localhost",
	"base" => "virt104529_multi",
	"user" => "virt104529_usera",
	"password" => "8U1LWjp0"
);
//----------------------------------------
require_once("core/core.php");
require_once("core/c_SAMP_QUERY.php");
$MultiAD = new MAD_Core($db_login_data['host'], $db_login_data['base'], $db_login_data['user'], $db_login_data['password']);
//----------------------------------------