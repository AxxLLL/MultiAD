<?php
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
require("resources/init.php");


$result = $MultiAD -> Database -> query("SELECT * FROM `mad_matches`");
printf("Rows: %d<br/>", $result -> num_rows);
if($result -> num_rows > 0) {
	
	$real_index = array();
	$server_index = array();
	$add_time = array();
	$team_1_name = array();
	$team_1_points = array();
	$team_2_name = array();
	$team_2_points = array();
	$round_limit = array();	
	$round_data = array();
	$players_data = array();
	
	$index = 0;
	echo "<table>";
	while($row = $result -> fetch_assoc()) {
		
		$real_index[$index] = $row[MM_ID];
		$server_index[$index] = $row[MM_MS_ID];
		$add_time[$index] = $row[MM_ADD_TIME];
		$round_limit[$index] = $row[MM_ROUND_LIMIT];
		
		$buffer = explode(":", $row[MM_TEAM_1]);
		$team_1_name[$index] = $buffer[0];
		$team_1_points[$index] = $buffer[1];

		$buffer = explode(":", $row[MM_TEAM_2]);
		$team_2_name[$index] = $buffer[0];
		$team_2_points[$index] = $buffer[1];
		
		$buffer = explode("|", $row[MM_ROUND_INFO]);		
		for($i = 0; $i < count($buffer); $i ++) {
			$buffer_data = explode(":", $buffer[$i]);
			$round_data[$index][$i] = sprintf("%s,0", $buffer_data[1]);
		}
		
		$buffer = explode("|", $row[MM_PLAYERS_INFO]);
		for($i = 0; $i < count($buffer); $i ++) {
			$players_data[$index][$i] = explode(":", $buffer[$i]);
		}

		$index ++;
		/*
		echo "<tr>
			<td>".$row[MM_ID]."</td>
			<td>".$row[MM_MS_ID]."</td>
			<td>".$row[MM_ADD_TIME]."</td>
			<td>".$row[MM_TEAM_1]."</td>
			<td>".$row[MM_TEAM_2]."</td>
			<td>".$row[MM_ROUND_LIMIT]."</td>
			<td>".$row[MM_ROUND_INFO]."</td>
			<td>".$row[MM_PLAYERS_INFO]."</td>
		</tr>";
		*/
	}	
	echo "<table>";
	$result -> close();
	
	$JSON_Data = array();
	for($i = 0; $i < count($real_index); $i ++) {
		
		$JSON_Data[$i] = sprintf("{\"general\":{\"rounds\":%d,\"team\":[{\"name\":\"%s\",\"points\":%d},{\"name\":\"%s\",\"points\":%d}]},\"round\":[", $round_limit[$i], $team_1_name[$i], $team_1_points[$i], $team_2_name[$i], $team_2_points[$i]);
		for($x = 0; $x < count($round_data[$i]); $x ++) {
			$JSON_Data[$i] .= sprintf("[%s],", $round_data[$i][$x]);
		}
		$JSON_Data[$i] = rtrim($JSON_Data[$i], ",");		
		$JSON_Data[$i] .= sprintf("],\"players\":[");

		for($x = 0; $x < count($players_data[$i]); $x ++) {
			$JSON_Data[$i] .= sprintf("[\"%s\",%s],", $players_data[$i][$x][0], $players_data[$i][$x][1]);
		}	
		$JSON_Data[$i] = rtrim($JSON_Data[$i], ",");
		$JSON_Data[$i] .= sprintf("]}");
		
		$MultiAD -> Database -> query(sprintf("INSERT INTO `".MAD_NEW_MATCHES."` (`".MNM_ID."`,`".MNM_MS_ID."`,`".MNM_ADD_TIME."`,`".MNM_TEAM_1."`,`".MNM_TEAM_2."`,`".MNM_JSON_DATA."`) VALUES ('%d','%d','%d','%s','%s','%s');",
		$real_index[$i], $server_index[$i], $add_time[$i], $team_1_name[$i], $team_2_name[$i], $JSON_Data[$i]));
	}
		
	
	
	

}
