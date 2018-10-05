<?php 
	error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
	include("resources/init.php"); 
?>

<!DOCTYPE html>
<html lang="pl">
<head>
	<title>Multi A/D</title>
	<link rel="stylesheet" type="text/css" href="style/MultiAD.css" />
	<link rel="Shortcut icon" href="resources/images/small_logo.png" />
	<!-- <meta http-equiv="Content-Type" content="text/html; charset=utf-8" /> -->
</head>


<body>
	<?php $MultiAD -> htmlLoad("navigation_bar"); ?>
	<?php $MultiAD -> htmlLoad("d_box"); ?>
	<?php $MultiAD -> htmlLoad("page_manager"); ?>
</body>
</html>