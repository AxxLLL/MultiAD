<?php

$server_list = $c_SVLIST -> getServerList();
$c_SAMP_QUERY = new c_SAMP_QUERY();

for($i = 0; $i < count($server_list); $i ++) {
	if(($query_data = $c_SAMP_QUERY -> getSAMPServerData(long2ip($server_list[$i][MS_IP]), $server_list[$i][MS_PORT], "i")) != false) {
		$rules_data = $c_SAMP_QUERY -> getSAMPServerData(long2ip($server_list[$i][MS_IP]), $server_list[$i][MS_PORT], "r");
		$rules_data = $c_SAMP_QUERY -> readSAMPRules($rules_data, SAMP_RULE_LAGCOMP);
		
		echo "<tr class=\"tr_color_".($i % 2 == 0)."\">
				<td>".$c_SAMP_QUERY -> getSAMPServerSpecificData($query_data, SAMP_HOST_NAME)."</td>
				<td>".sprintf("%s:%d", long2ip($server_list[$i][MS_IP]), $server_list[$i][MS_PORT])."</td>
				<td>".sprintf("%d/%d", $c_SAMP_QUERY -> getSAMPServerSpecificData($query_data, SAMP_PLAYERS), $c_SAMP_QUERY -> getSAMPServerSpecificData($query_data, SAMP_MAX_PLAYERS))."</td>
				<td>".sprintf("%s", $c_SAMP_QUERY -> getSAMPServerSpecificData($query_data, SAMP_PASSWORD) ? ("Tak") : ("Nie"))."</td>
				<td>".sprintf("%s", $rules_data[SAMP_RULE_LAGCOMP] == 0 ? ("Lagshoot") : ("Skinshoot"))."</td>
				<td>".sprintf("%s", htmlentities($rules_data[SAMP_RULE_VERSION]))."</td>
				<td>".sprintf("%s", htmlentities($rules_data[SAMP_RULE_WEBURL]))."</td>
			</tr>";
	}
}