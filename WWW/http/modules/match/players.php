<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("IN_PHP")) exit;
//==============================================================================
$img_background = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/multigr.png");
$img_grpus = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/grpus.png");
//------------------------------------------------------------------------------
if($img_background != false && $img_grpus != false) {
    if(file_exists(($verdana_bold = dirname(dirname(dirname(__FILE__)))."/includes/fonts/verdanab.ttf")) && file_exists(($arial_bold = dirname(dirname(dirname(__FILE__)))."/includes/fonts/arial_bold.ttf")) && file_exists(($arial = dirname(dirname(dirname(__FILE__)))."/includes/fonts/arial.ttf")) && file_exists(($verdana = dirname(dirname(dirname(__FILE__)))."/includes/fonts/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180));			
        //--------------------- 		
        imagesavealpha($img_background, true);
        //---------------------	
        $dimensions = imagettfbbox(14, 0, $arial, sprintf("[%d]   %s", $team_data[0]['points'], $team_data[0]['name']));	//Wyrownanie do prawej nazwy pierwszej druzyny w naglowku
        imagettftext($img_background, 14, 0, (320 - abs($dimensions[4] - $dimensions[0])), 89, $color['light_grey'], $arial, sprintf("[%d]   %s", $team_data[0]['points'], $team_data[0]['name']));
        //---------------------
        imagettftext($img_background, 14, 0, 388, 89, $color['light_grey'], $arial, sprintf("%s   [%d]", $team_data[1]['name'], $team_data[1]['points']));	//Nazwa drugiej druzyny w naglowku
        imagettftext($img_background, 14, 0, 378, 120, $color['light_grey'], $arial, ($team_data[0]['points'] != $team_data[1]['points'] ? ($team_data[0]['points'] > $team_data[1]['points'] ? ($team_data[0]['name']) : ($team_data[1]['name'])) : ("Remis")));	//Wygrywa
        imagettftext($img_background, 8, 0, 170, 456, $color['white'], $arial, $hostname); //Nazwa hosta w stopce
        imagettftext($img_background, 8, 0, 170, 473, $color['grey'], $verdana, ($server_address == false ? ("Brak IP") : ($server_address))); //IP w stopce
        imagettftext($img_background, 8, 0, 445, 456, $color['light_blue'], $verdana_bold, "ROZEGRANO");
        //---------------------
        $string = date("Y-m-d [H:i:s]", $results[MM_ADD_TIME]); //Wyrownanie do prawej daty rozegrania meczu
        $dismensions = imagettfbbox(8, 0, $verdana, $string);
        $dismensions_play_time = imagettfbbox(8, 0, $verdana_bold, "ROZEGRANO");
        imagettftext($img_background, 8, 0, (445 + (abs($dismensions_play_time[4] - $dismensions_play_time[0]) / 2 )) - (abs($dismensions[4] - $dismensions[0]) / 2), 473, $color['grey'], $verdana, date("Y-m-d [H:i:s]", $results[MM_ADD_TIME]));			
        //---------------------	
        //$player_data[$i]['name'], $player_data[$i]['team'], $player_data[$i]['kills'], $player_data[$i]['deaths'], $player_data[$i]['damage']
        $team_counter[2];
        for($i = 0, $teamid; $i < count($player_data); $i ++) {
            switch(($teamid = $player_data[$i]['team'])) {
                case 0:
                    if((++ $team_counter[$teamid]) <= 10) {
                        imagecopy($img_background, $img_grpus, 22, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, 10, 0, 35, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['name']);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, $player_data[$i]['damage']);
                        imagettftext($img_background, 10, 0, 222 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['damage']);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, $player_data[$i]['kills']);
                        imagettftext($img_background, 10, 0, 305 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['kills']);
                         
                    }               
                break;
                case 1: 
                    if((++ $team_counter[$teamid]) <= 10) {
                        imagecopy($img_background, $img_grpus, 357, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, 10, 0, 370, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['name']);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, $player_data[$i]['damage']);
                        imagettftext($img_background, 10, 0, 557 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['damage']);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, $player_data[$i]['kills']);
                        imagettftext($img_background, 10, 0, 640 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $player_data[$i]['kills']);

                    }
                break;
                case 2:
                break;
            }
        }        

        //---------------------			
        header("Content-Type: image/png");
        imagepng($img_background);
    } else $error = "(2) Blad kodu";
} else $error = "(1) Blad kodu";
//------------------------------------------------------------------------------
if($img_background != false) imagedestroy($img_background);
if($img_grpus != false) imagedestroy($img_grpus);
?>