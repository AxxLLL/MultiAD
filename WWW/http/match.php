<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
define("IN_PHP", 1);
//==============================================================================
if($_SERVER['REQUEST_METHOD'] != 'GET') exit;
//==============================================================================
$id = $_GET['id'];
$result_type = $_GET['type'];
//------------------------------------------------------------------------------
$error = false;
//==============================================================================
if(!(isset($id) && is_numeric($id) && $id > 0 && $id < 9999999)) exit;
if(isset($result_type)) {
	if(!is_string($result_type) || !preg_match("/^[a-z]{3,7}$/D", $result_type) || !(/*!strcmp($result_type, "big") || !strcmp($result_type, "small") || */!strcmp($result_type, "normal") || !strcmp($result_type, "players"))) exit;
} else $result_type = 'normal';
//==============================================================================
require_once(dirname(__FILE__)."/includes/classes/c_MatchResultsFunctions.php");
//==============================================================================
$c_MatchResultsFunctions = new c_MatchResultsFunctions();
if(($results = $c_MatchResultsFunctions -> getMatchResults($id)) != false) {
    
    //==========================================	
  	$server_address = false;
  	if(($server_data = $c_MatchResultsFunctions -> getServerDataByID($results[MM_MS_ID])) != false) {
  		$server_address = sprintf("%s:%d", long2ip($server_data[MS_IP]), $server_data[MS_PORT]);
 	}
    
    $team_data = array();
    list($team_data[0]['name'], $team_data[0]['points']) = explode(":", $results[MM_TEAM_1]);
    list($team_data[1]['name'], $team_data[1]['points']) = explode(":", $results[MM_TEAM_2]);

  	$total_data = explode("|", $results[MM_ROUND_INFO]);
  	$round_data = array();  	
  	for($i = 0; $i < $results[MM_ROUND_LIMIT]; $i ++) {
  	  	list($ignore, $round_data[$i]['mapid'], $round_data[$i]['type'], $round_data[$i]['winner'], $round_data[$i]['reason'], $round_data[$i]['defender'], $round_data[$i]['time']) = sscanf($total_data[$i], "%d:%d,%d,%d,%d,%d,%d");
  	}

  	$total_data = explode("|", $results[MM_PLAYERS_INFO]);
  	$player_data = array();
  	for($i = 0, $count = count($total_data); $i < $count; $i ++) {
  	  	$total_data[$i] = str_replace(":", " ", $total_data[$i]);
  	 	list($player_data[$i]['name'], $player_data[$i]['team'], $player_data[$i]['kills'], $player_data[$i]['deaths'], $player_data[$i]['damage']) = sscanf($total_data[$i], "%s %d,%d,%d,%d");
	}
    

    $hostname = "Brak informacji";
    if($server_address != false) {
        if(file_exists(dirname(__FILE__)."/includes/classes/c_SAMPFunctions.php")) {
            require_once(dirname(__FILE__)."/includes/classes/c_SAMPFunctions.php");
            $c_SAMPFunctions = new c_SAMPFunctions();
            if(($result = $c_SAMPFunctions -> getSAMPServerData(long2ip($server_data[MS_IP]), $server_data[MS_PORT], "i")) != false) {
                $debug = 5;
                if(($hostname = $c_SAMPFunctions -> getSAMPServerSpecificData($result, SAMP_HOST_NAME)) == false) {
                    $debug = 6;
                    $hostname = "Brak informacji";
                }  		  	  
            }
        }
    }				        
	//==========================================	
    switch($result_type) {  
        case 'players':
            include(dirname(__FILE__)."/modules/match/players.php");
        break;
        /*
        case 'small': 
            include(dirname(__FILE__)."/modules/match/small.php");
        break;
        case 'big': 
            include(dirname(__FILE__)."/modules/match/big.php");
        //break;
        */
        case 'normal':         
            include(dirname(__FILE__)."/modules/match/normal.php");
        break;        
    }
} else $error = "Brak rezultatów dla wybranego ID";
//==============================================================================    
if($error != false) {
 	if(($img_error = @imagecreatefrompng(dirname(__FILE__)."/img/match_results/small.png"))) {
 	  	imagesavealpha($img_error, true);
 	  	if(file_exists(($font = dirname(__FILE__)."/includes/fonts/arial_bold.ttf"))) { 	  
 	  	  	$dimensions = imagettfbbox(13, 0, $font, $error); 	  	  	
 	  		imagettftext($img_error, 13, 0, ((imagesx($img_error) / 2) - (abs($dimensions[4] - $dimensions[0]) / 2)), 100, imagecolorallocate($img_error, 230, 230, 230), $font, $error);  
  	  	} else {
 	  		imagestring($img_error, 5, 220, 85, $error, imagecolorallocate($img_error, 230, 230, 230));
		}
  	} else {
  	  	if(($img_error = imagecreatetruecolor (310, 35)) != false) {
	    		imagestring($img_error, 5, 10, 10, $error, imagecolorallocate($img_error, 230, 230, 230));	    		
	    	} else print($error);
  	}
  	if($img_error != false) {
	  	header("Content-Type: image/png");
		imagepng($img_error); 	  	
	  	imagedestroy($img_error);
 	}
}   
?>