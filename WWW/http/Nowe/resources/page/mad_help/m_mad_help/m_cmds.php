<?php
if(($xml_data = simplexml_load_file($url_address)) != false) {
	$cmds = $xml_data -> $cmd_type -> cmd;
	for($i = 0; $i < count($cmds); $i ++) {
		for($x = 0; $x < count($cmds[$i] -> lang); $x ++) {
			if($cmds[$i] -> lang[$x]['value'] == 'pl') {
				echo "<tr class=\"tr_color_".($i % 2 == 0)."\">
						<td>".$cmds[$i]['name']."</td>
						<td>".$cmds[$i] -> lang[$x]['params']."</td>
						<td>".$cmds[$i] -> lang[$x] -> description."</td>
					</tr>";
			}
		}
	}	
}