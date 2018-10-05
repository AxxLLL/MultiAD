<?php
if(isset($_GET['view'])) {
	include(dirname(__FILE__)."/../v_match_list/v_match_details.php");
}

$result = $MultiAD -> Database -> query("SELECT * FROM `".MAD_NEW_MATCHES."` ORDER BY `".MNM_ADD_TIME."` DESC");
if($result -> num_rows > 0) {
	$color = array("red" => "#780000", "blue" => "#000099", "white" => "#FFFFFF");
	$color_index = 0;
	while($row = $result -> fetch_assoc()) {
		
		$server_name = "Undefined Server";
		$win_team;
		$server_result = $MultiAD -> Database -> query(sprintf("SELECT `".MS_SERVER_LAST_NAME."`, `".MS_IP."`, `".MS_PORT."` FROM `".MAD_SERVERS."` WHERE `".MS_ID."`='%d' LIMIT 1", $row[MNM_MS_ID]));
		if($server_result -> num_rows == 1) {
			$server_row = $server_result -> fetch_assoc();
			$server_name = sprintf("%s", $server_row[MS_SERVER_LAST_NAME]); 
			$server_result -> close();
		}
			
		$JSON_Data = json_decode($row[MNM_JSON_DATA], true);
		$Team_Data = $JSON_Data['general']['team'];
			
		if($Team_Data[0]['points'] > $Team_Data[1]['points']) {
			$win_team = sprintf("<font color='".$color['red']."'>%s</font>", $Team_Data[0]['name']);
		} else {
			if($Team_Data[0]['points'] < $Team_Data[1]['points']) 
				$win_team = sprintf("<font color='".$color['blue']."'>%s</font>", $Team_Data[1]['name']);
			else
				$win_team = sprintf("<font color='".$color['white']."'>%s</font>", $Team_Data[1]['name']);
		}
		echo "	<tr class=\"tr_color_".($color_index % 2 == 0)."\">
					<td>".sprintf("<font color='".$color['red']."'>%s</font> Vs. <font color='".$color['blue']."'>%s</font>", $row[MNM_TEAM_1], $row[MNM_TEAM_2])."</td>
					<td>".$win_team."</td>
					<td>".sprintf("%d : %d", $Team_Data[0]['points'], $Team_Data[1]['points'])."</td>
					<td>".date("d-m-Y [H:i:s]", $row[MNM_ADD_TIME])."</td>
					<td>".$server_name."</td>		
					<td><a href=\"?page=matchlist&view=".$row[MNM_ID]."\">Info</a></td>
				</tr>";
		$color_index ++;
	}	
	$result -> close();
}