<?php 
//==============================================================================
if(!defined("IN_PHP")) exit;
//==============================================================================
require_once(dirname(dirname(__FILE__))."/includes/classes/c_SAMPFunctions.php");
require_once(dirname(dirname(__FILE__))."/includes/classes/c_SrvListFunctions.php");
//==============================================================================
$c_SAMPFunctions = new c_SAMPFunctions();
$c_SrvListFunctions = new c_SrvListFunctions();
//------------------------------------------------------------------------------
$list_counter = 0;
$server_list = array();
//==============================================================================
if(($result = $c_SrvListFunctions -> getServerList()) != false) {
	$server_data = array();
	$server_rules = array();	
	//-----------------------
	while(($row_results = $result -> fetch_assoc())) {
	  	$server_list[$list_counter]['ip'] = long2ip($row_results[MS_IP]);
	  	$server_list[$list_counter]['port'] = $row_results[MS_PORT];
	  	if(($samp = $c_SAMPFunctions -> getSAMPServerData($server_list[$list_counter]['ip'], $server_list[$list_counter]['port'], "i")) != false) {
		  	$server_list[$list_counter]['password'] = 	$c_SAMPFunctions -> getSAMPServerSpecificData($samp, SAMP_PASSWORD);
		  	$server_list[$list_counter]['players'] = 	$c_SAMPFunctions -> getSAMPServerSpecificData($samp, SAMP_PLAYERS);
		  	$server_list[$list_counter]['max_players'] = 	$c_SAMPFunctions -> getSAMPServerSpecificData($samp, SAMP_MAX_PLAYERS);
		  	$server_list[$list_counter]['hostname'] = 	$c_SAMPFunctions -> getSAMPServerSpecificData($samp, SAMP_HOST_NAME);
			if(($samp = $c_SAMPFunctions -> getSAMPServerData($server_list[$list_counter]['ip'], $server_list[$list_counter]['port'], "r")) != false) {
			  	$a_Rules = $c_SAMPFunctions -> readSAMPRules($samp);			  	
			  	$server_list[$list_counter] = array_merge($server_list[$list_counter], $a_Rules);
			  	$list_counter ++;
			} 		 
 	  	}
	}  
  	//-----------------------
}
//------------------------------------------------------------------------------
if($list_counter > 0) {
    	echo "<table>
		<tr>
			<td>IP</td>
			<td>Host</td>
			<td>Haslo</td>
			<td>Graczy</td>
			<td>Wersja</td>	
			<td>Lagshoot</td>
			<td>Strona</td>	
			<td> </td>							
		</tr>
	";
	//-----------------------
  	for($i = 0; $i < $list_counter; $i ++) {
	  	echo "	<tr>
	  			<td>".$server_list[$i]['ip'].":".$server_list[$i]['port']."</td>
	  			<td>".$server_list[$i]['hostname']."</td>
	  			<td>".($server_list[$i]['password'] == 1 ? ("Tak") : ("Nie"))."</td>
	  			<td>".$server_list[$i]['players']." / ".$server_list[$i]['max_players']."</td>
	  			<td>".$server_list[$i][SAMP_RULE_VERSION]."</td>
	  			<td>".$server_list[$i][SAMP_RULE_LAGCOMP]."</td>
	  			<td>".$server_list[$i][SAMP_RULE_WEBURL]."</td>
	  			<td><a href='samp://".$server_list[$i]['ip'].":".$server_list[$i]['port']."'>Polacz</a></td>
  			</tr>
	  	";  	  
 	}  
 	//-----------------------
 	echo "</table>";
} else printf("<br/>No servers<br/>"); 
?>
