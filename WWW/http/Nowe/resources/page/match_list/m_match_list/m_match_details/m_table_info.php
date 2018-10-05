<?php 
$server_name = "";
if(($server_name = $c_MatchData -> getMatchServerValue(MS_SERVER_LAST_NAME)) != false) {
	$server_name .= sprintf("<br/>(%s:%d)", long2ip($c_MatchData -> getMatchServerValue(MS_IP)), $c_MatchData -> getMatchServerValue(MS_PORT));
} else $server_name = "Undefined Server";

echo "	<tr>
			<td>Data</td>
			<td>".date("d-m-Y [H:i:s]", $c_MatchData -> getMatchValue(MNM_ADD_TIME))."</td>
		</tr>
		<tr>
			<td>Serwer</td>
			<td>".$server_name."</td>
		</tr>";