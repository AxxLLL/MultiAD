<?php
if(($xml_data = simplexml_load_file($url_address)) != false) {
	$prepare_body = "";
	$prepare_anchors = "";
	for($i = 0; $i < count($xml_data -> description); $i ++) {
		if($xml_data -> description[$i]['lang'] == 'pl') {
			for($x = 0; $x < count($xml_data -> description[$i] -> step); $x ++) {
				$prepare_anchors .= sprintf("<a href=#%s>%s</a>, ", $xml_data -> description[$i] -> step[$x]['id'], $xml_data -> description[$i] -> step[$x]['name']);
				$prepare_body .= sprintf("<br/><br/><a name='%s'><h2>%s</h2>%s", $xml_data -> description[$i] -> step[$x]['id'], $xml_data -> description[$i] -> step[$x]['name'], $xml_data -> description[$i] -> step[$x]);
			}
		}
	}
	$prepare_anchors = rtrim($prepare_anchors, " ,");
	
	echo "<p class=\"anchor\">".$prepare_anchors."</p>";
	echo $prepare_body;
}