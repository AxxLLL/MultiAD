<?php
//=============================================================
if(isset($_GET['view'])) {
	include("v_match_list/v_match_details.php");
} else include("v_match_list/v_match_list.php");