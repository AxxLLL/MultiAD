<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("FROM_FUNCTION")) exit;
//==============================================================================
$img_background = @imagecreatefrompng($images_dir."/multigr.png");
$img_grpus = @imagecreatefrompng($images_dir."/grpus.png");
//------------------------------------------------------------------------------
if($img_background != false && $img_grpus != false) {
    if(file_exists(($verdana_2 = $fonts_dir."/verdana_2.ttf")) && file_exists(($verdana_bold = $fonts_dir."/verdanab.ttf")) && file_exists(($arial_bold = $fonts_dir."/arial_bold.ttf")) && file_exists(($arial = $fonts_dir."/arial.ttf")) && file_exists(($verdana = $fonts_dir."/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180));			
        //--------------------- 		
        imagesavealpha($img_background, true);
        //---------------------	
		$dimensions = imagettfbbox(14, 0, $verdana_2, ($string = $_LANG[19]));
		imagettftext($img_background, 14, 0, 355 - ($dimensions[4] - $dimensions[0]), 120, $color['light_blue'], $verdana_2, $string);
		//---------------------	
        $dimensions = imagettfbbox(14, 0, $arial, ($string = sprintf("[%d]   %s", $general_data['team'][0]['points'], $general_data['team'][0]['name'])));	//Wyrownanie do prawej nazwy pierwszej druzyny w naglowku
        imagettftext($img_background, 14, 0, (320 - abs($dimensions[4] - $dimensions[0])), 89, $color['light_grey'], $arial, $string);
        //---------------------
        imagettftext($img_background, 14, 0, 388, 89, $color['light_grey'], $arial, sprintf("%s   [%d]", $general_data['team'][1]['name'], $general_data['team'][1]['points']));	//Nazwa drugiej druzyny w naglowku
        imagettftext($img_background, 14, 0, 378, 120, $color['light_grey'], $arial, ($general_data['team'][0]['points'] != $general_data['team'][1]['points'] ? ($general_data['team'][0]['points'] > $general_data['team'][1]['points'] ? ($general_data['team'][0]['name']) : ($general_data['team'][1]['name'])) : ($_LANG[17])));	//Wygrywa
        imagettftext($img_background, 8, 0, 170, 456, $color['white'], $arial, $this -> getMatchServerData(MS_SERVER_LAST_NAME)); //Nazwa hosta w stopce
        imagettftext($img_background, 8, 0, 170, 473, $color['grey'], $verdana, ($this -> getMatchServerData(MS_IP) == false ? ($_LANG[3]) : (sprintf("%s:%d", long2ip($this -> getMatchServerData(MS_IP)), $this -> getMatchServerData(MS_PORT))))); //IP w stopce
        imagettftext($img_background, 8, 0, 445, 456, $color['light_blue'], $verdana_bold, $_LANG[4]);
        //---------------------
        $string = date("d-m-Y [H:i:s]", $this -> getMatchServerData(MNM_ADD_TIME)); //Wyrownanie do prawej daty rozegrania meczu
        $dismensions = imagettfbbox(8, 0, $verdana, $string);
        $dismensions_play_time = imagettfbbox(8, 0, $verdana_bold, $_LANG[4]);
        imagettftext($img_background, 8, 0, (445 + (abs($dismensions_play_time[4] - $dismensions_play_time[0]) / 2 )) - (abs($dismensions[4] - $dismensions[0]) / 2), 473, $color['grey'], $verdana, $string);			
        //---------------------	
        $team_counter = array(0 => 0, 1 => 0);
        for($i = 0, $teamid; $i < count($players_data); $i ++) {
            switch(($teamid = $players_data[$i][1])) {
                case 0:
                    if((++ $team_counter[$teamid]) <= 10) {
                        imagecopy($img_background, $img_grpus, 22, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, 10, 0, 35, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $players_data[$i][0]);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, ($string = $players_data[$i][4]));
                        imagettftext($img_background, 10, 0, 222 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, ($string = $players_data[$i][2]));
                        imagettftext($img_background, 10, 0, 305 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                         
                    }               
                break;
                case 1: 
                    if((++ $team_counter[$teamid]) <= 10) {
                        imagecopy($img_background, $img_grpus, 357, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, 10, 0, 370, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $players_data[$i][0]);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, ($string = $players_data[$i][4]));
                        imagettftext($img_background, 10, 0, 557 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                        $dismensions = imagettfbbox(10, 0, $arial_bold, ($string = $players_data[$i][2]));
                        imagettftext($img_background, 10, 0, 640 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);

                    }
                break;
            }
        }        

        //---------------------			
        header("Content-Type: image/png");
        imagepng($img_background);
    } die("(2) Blad kodu");
} die("(1) Blad kodu");
//------------------------------------------------------------------------------
if($img_background != false) imagedestroy($img_background);
if($img_grpus != false) imagedestroy($img_grpus);