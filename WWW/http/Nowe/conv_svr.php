<?php
error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
require("resources/init.php");


$result = $MultiAD -> Database -> query("SELECT `".MS_ID."`, `".MS_IP."`,`".MS_PORT."` FROM `".MAD_SERVERS."`");

printf("Rows: %d<br/>", $result -> num_rows);
if($result -> num_rows > 0) {

	$index = 0;
	while($row = $result -> fetch_assoc()) {
		
		$ip = long2ip($row[MS_IP]);
		$port = $row[MS_PORT];
		
		printf("(%d) Processing %s:%d  [Server ID: %d]<br/>", $index, $ip, $port, $row[MS_ID]);
		//-----------------------------
		$aIPAddr = explode('.', $ip);		 
		$sPacket = "SAMP";              
		$sPacket .= chr($aIPAddr[0]);                                        
		$sPacket .= chr($aIPAddr[1]);             
		$sPacket .= chr($aIPAddr[2]);                              
		$sPacket .= chr($aIPAddr[3]);                               
		$sPacket .= chr($port & 0xFF);                                  
		$sPacket .= chr($port >> 8 & 0xFF);                            
		$sPacket .= "i";   
		if(($rSocket = fsockopen('udp://'.$ip, $port, $iError, $sError, 2)) != false) {   
			stream_set_timeout($rSocket, 2);
			fwrite($rSocket, $sPacket);                                  		 
			$return_data = fread($rSocket, 2048);					 
			fclose($rSocket); 
			if(strlen($return_data) > 0 && !strncmp($return_data, "SAMP", 4)) {
				$hostname = htmlentities(substr($return_data, 20, ord($return_data[16])));
				if(($statement = $MultiAD -> Database -> prepare("UPDATE `".MAD_SERVERS."` SET `".MS_SERVER_LAST_NAME."`=? WHERE `".MS_ID."`=?")) != false) {
					$statement -> bind_param("sd", $hostname, $row[MS_ID]);
					if(!($statement -> execute())) printf("Error in statement execute");
					$statement -> close();
				} else printf("Invalid query - update last name data");
			}    
		}		
		
		$index ++;
	}	

	$result -> close();
}
