<?php
if(isset($_GET['view'])) {
	include(dirname(dirname(dirname(dirname(dirname(__FILE__)))))."/core/c_MatchData.php");
	$c_MatchData = new c_MatchData($_GET['view']);
}