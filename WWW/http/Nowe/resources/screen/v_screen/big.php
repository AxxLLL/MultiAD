<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("FROM_FUNCTION")) exit;
//==============================================================================
$img_background = @imagecreatefrompng($images_dir."/bckg_big.png");
$img_green = @imagecreatefrompng($images_dir."/green.png");
$img_m_green = @imagecreatefrompng($images_dir."/m_green.png");
$img_red = @imagecreatefrompng($images_dir."/red.png");
$img_m_red = @imagecreatefrompng($images_dir."/m_red.png");
$img_white = @imagecreatefrompng($images_dir."/white.png");
$img_m_white = @imagecreatefrompng($images_dir."/m_white.png");
$img_blue = @imagecreatefrompng($images_dir."/blue.png");
$img_rank = @imagecreatefrompng($images_dir."/rank.png");
//------------------------------------------------------------------------------
if($img_background != false && $img_green != false && $img_red != false && $img_blue != false && $img_rank != false && $img_white != false) {
    if(file_exists(($verdana_2 = $fonts_dir."/verdana_2.ttf")) && file_exists(($verdana_bold = $fonts_dir."/verdanab.ttf")) && file_exists(($arial_bold = $fonts_dir."/arial_bold.ttf")) && file_exists(($arial = $fonts_dir."/arial.ttf")) && file_exists(($verdana = $fonts_dir."/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180), 'green' => imagecolorallocate($img_background, 0, 180, 0));
        //---------------------

        //--------------------- 		
        imagesavealpha($img_background, true);
		//---------------------	
		$dimensions = imagettfbbox(14, 0, $verdana_2, ($string = $_LANG[19]));
		imagettftext($img_background, 14, 0, 355 - ($dimensions[4] - $dimensions[0]), 120, $color['light_blue'], $verdana_2, $string);
        //---------------------	
        imagecopy($img_background, $img_blue, 250, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (srodek)
        //---------------------			
        $dimensions = imagettfbbox(14, 0, $arial, ($string = $general_data['team'][0]['name']));	//Wyrownanie do prawej nazwy pierwszej druzyny w naglowku
        imagettftext($img_background, 14, 0, (320 - abs($dimensions[4] - $dimensions[0])), 89, $color['light_grey'], $arial, $string);
        //---------------------
        imagettftext($img_background, 14, 0, 388, 89, $color['light_grey'], $arial, $general_data['team'][1]['name']);	//Nazwa drugiej druzyny w naglowku
        imagettftext($img_background, 14, 0, 378, 120, $color['light_grey'], $arial, ($general_data['team'][0]['points'] != $general_data['team'][1]['points'] ? ($general_data['team'][0]['points'] > $general_data['team'][1]['points'] ? ($general_data['team'][0]['name']) : ($general_data['team'][1]['name'])) : ($_LANG[17])));	//Wygrywa
        imagettftext($img_background, 11, 0, 326, 165, $color['light_grey'], $verdana_bold, $_LANG[0]);
		imagettftext($img_background, 11, 0, 326, 458, $color['light_blue'], $verdana_bold, $_LANG[1]); // srodek
        imagettftext($img_background, 8, 0, 170, 503, $color['white'], $arial, $this -> getMatchServerData(MS_SERVER_LAST_NAME)); //Nazwa hosta w stopce
        imagettftext($img_background, 8, 0, 170, 520, $color['grey'], $verdana, ($this -> getMatchServerData(MS_IP) == false ? ($_LANG[3]) : (sprintf("%s:%d", long2ip($this -> getMatchServerData(MS_IP)), $this -> getMatchServerData(MS_PORT))))); //IP w stopce
        imagettftext($img_background, 8, 0, 445, 503, $color['light_blue'], $verdana_bold, $_LANG[4]);

		$dimensions = imagettfbbox(14, 0, $verdana_bold, ($string = $_LANG[2]));
		imagettftext($img_background, 11, 0, 105 - ($dimensions[4] - $dimensions[0]), 458, $color['light_blue'], $verdana_bold, $string); // lewa
		imagettftext($img_background, 11, 0, 555 - ($dimensions[4] - $dimensions[0]), 458, $color['light_blue'], $verdana_bold, $string); // prawa
		//---------------------
		$img_line = imagecreatetruecolor(185, 1);
		imagefill($img_line, 0, 0, $color['light_blue']);
		
		imagecopy($img_background, $img_line, 35, 172, 0, 0, imagesx($img_line), imagesy($img_line));
		imagettftext($img_background, 8, 0, 35, 165, $color['light_grey'], $verdana_bold, $_LANG[5]);
		imagettftext($img_background, 8, 0, 158, 165, $color['light_grey'], $verdana_bold, $_LANG[6]);
		imagettftext($img_background, 8, 0, 191, 165, $color['light_grey'], $verdana_bold, $_LANG[7]);		

		imagecopy($img_background, $img_line, 485, 172, 0, 0, imagesx($img_line), imagesy($img_line));
		imagettftext($img_background, 8, 0, 485, 165, $color['light_grey'], $verdana_bold, $_LANG[5]);
		imagettftext($img_background, 8, 0, 608, 165, $color['light_grey'], $verdana_bold, $_LANG[6]);
		imagettftext($img_background, 8, 0, 641, 165, $color['light_grey'], $verdana_bold, $_LANG[7]);		
        //---------------------
        $string = sprintf("%d", $general_data['team'][0]['points'] ); //Wycentrowanie punktow z lewej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);
        imagettftext($img_background, 11, 0, 273 - (abs($dismensions[4] - $dismensions[0]) / 2), 458, $color['light_grey'], $verdana_bold, $string); //Punkty lewa
        //---------------------
        $string = sprintf("%d", $general_data['team'][1]['points']); //Wycentrowanie punktow z prawej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);				
        imagettftext($img_background, 11, 0, 426 - (abs($dismensions[4] - $dismensions[0]) / 2), 458, $color['light_grey'], $verdana_bold, $string); //Punkty Prawa			
        //---------------------
        $string = date("d-m-Y [H:i:s]", $this -> getMatchServerData(MNM_ADD_TIME)); //Wyrownanie do prawej daty rozegrania meczu
        $dismensions = imagettfbbox(8, 0, $verdana, $string);
        $dismensions_play_time = imagettfbbox(8, 0, $verdana_bold, $_LANG[4]);
        imagettftext($img_background, 8, 0, (445 + (abs($dismensions_play_time[4] - $dismensions_play_time[0]) / 2 )) - (abs($dismensions[4] - $dismensions[0]) / 2), 518, $color['grey'], $verdana, $string);			
 	
        //---------------------					
        for($i = 0; $i < $general_data['rounds']; $i ++) { //170:25	191:22						
            imagecopy($img_background, $img_rank, 246, (173 + $i * 22), 0, 0, imagesx($img_rank), imagesy($img_rank));				

            $string = sprintf("%s %d", ($rounds_data[$i][1] == 0 ? ($rounds_data[$i][6] == 0 ? ($_LANG[11]) : ($_LANG[12])) : ($_LANG[13])), $rounds_data[$i][0]);
            $dimensions = imagettfbbox(9, 0, $verdana_bold, $string);
            $center_x = 350 - (abs($dimensions[4] - $dimensions[0]) / 2);			
            imagettftext($img_background, 9, 0, $center_x, 191 + ($i * 22), $color['light_grey'], $verdana_bold, $string);				

            if($rounds_data[$i][1] == 1) {
                imagettftext($img_background, 10, 0, ($rounds_data[$i][4] == 0 ? 250 : 433), 191 + ($i * 22), $color['light_blue'], $arial_bold, "(D)");
            }			
			
			$image_width = 100;
			$start_y = 171;
			$cut = 10;
            switch($rounds_data[$i][2]) {
                case 0: 
                    imagecopy($img_background, $img_green, 250, ($start_y + $i * 22), 0, 0, $image_width, imagesy($img_blue));
                    imagecopy($img_background, $img_m_red, 350, ($start_y + $i * 22), 100 + $cut, 0, $image_width - $cut, imagesy($img_m_red));		
                break;
                case 1:
                    imagecopy($img_background, $img_red, 250, ($start_y + $i * 22), 0, 0, $image_width, imagesy($img_red));
                    imagecopy($img_background, $img_m_green, 350, ($start_y + $i * 22), 100 + $cut, 0, $image_width - $cut, imagesy($img_m_green));					
                break;
                default: 
                    imagecopy($img_background, $img_white, 250, ($start_y + $i * 22), 0, 0, $image_width, imagesy($img_white));
                    imagecopy($img_background, $img_m_white, 350, ($start_y + $i * 22), 100 + $cut, 0, $image_width - $cut, imagesy($img_m_white));			  	
                break; 
            }			
        }						
        //---------------------	
        $team_counter = array(0 => 0, 1 => 0);
		$total_stats = array(0 => array("kills" => 0, "damage" => 0, "extra_kills" => 0, "extra_damage" => 0, "lastname" => ""), 1 => array("kills" => 0, "damage" => 0, "extra_kills" => 0, "extra_damage" => 0,"lastname" => ""));
		$text_size = 7;
        for($i = 0, $teamid; $i < count($players_data); $i ++) {
            switch(($teamid = $players_data[$i][1])) {
                case 0:
                    if((++ $team_counter[$teamid]) <= 10) {
                        //imagecopy($img_background, $img_grpus, 22, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, $text_size, 0, 35, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $players_data[$i][0]);
                        $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $players_data[$i][4]));
                        imagettftext($img_background, $text_size, 0, 172 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                        $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $players_data[$i][2]));
                        imagettftext($img_background, $text_size, 0, 205 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                    } else {
						$total_stats[0]['extra_kills'] += $players_data[$i][2];
						$total_stats[0]['extra_damage'] += $players_data[$i][4];
						$total_stats[0]['lastname'] = $players_data[$i][0];						
					}					
					$total_stats[0]['kills'] += $players_data[$i][2];
					$total_stats[0]['damage'] += $players_data[$i][4];
                break;
                case 1: 
                    if((++ $team_counter[$teamid]) <= 10) {
                        //imagecopy($img_background, $img_grpus, 357, 148 + $team_counter[$teamid] * 22, 0, 0, imagesx($img_grpus), imagesy($img_grpus));
                        imagettftext($img_background, $text_size, 0, 485, 167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $players_data[$i][0]);
                        $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $players_data[$i][4]));
                        imagettftext($img_background, $text_size, 0, 622 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                        $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $players_data[$i][2]));
                        imagettftext($img_background, $text_size, 0, 655 - (abs($dismensions[4] - $dismensions[0]) / 2),  167 + $team_counter[$teamid] * 22, $color['white'], $arial_bold, $string);
                    } else {
						$total_stats[1]['extra_kills'] += $players_data[$i][2];
						$total_stats[1]['extra_damage'] += $players_data[$i][4];
						$total_stats[1]['lastname'] = $players_data[$i][0];
					}
					$total_stats[1]['kills'] += $players_data[$i][2];
					$total_stats[1]['damage'] += $players_data[$i][4];					
                break;
            }
        }
		
		if($team_counter[0] > 10) {
			if($team_counter[0] == 11) imagettftext($img_background, $text_size, 0, 35, 409, $color['white'], $arial_bold, $total_stats[0]['lastname']);
			else imagettftext($img_background, $text_size, 0, 35, 409, $color['white'], $arial_bold, sprintf($_LANG[14], $team_counter[0] - 10));			
            $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $total_stats[0]['extra_damage']));
            imagettftext($img_background, $text_size, 0, 172 - (abs($dismensions[4] - $dismensions[0]) / 2),  409, $color['white'], $arial_bold, $string);
            $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $total_stats[0]['extra_kills']));
            imagettftext($img_background, $text_size, 0, 205 - (abs($dismensions[4] - $dismensions[0]) / 2),  409, $color['white'], $arial_bold, $string);				
		}
		
		if($team_counter[1] > 10) {		
			if($team_counter[1] == 11) imagettftext($img_background, $text_size, 0, 485, 409, $color['white'], $arial_bold, $total_stats[1]['lastname']);
			else imagettftext($img_background, $text_size, 0, 485, 409, $color['white'], $arial_bold, sprintf($_LANG[14], $team_counter[1] - 10));			
		    $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $total_stats[1]['extra_damage']));
            imagettftext($img_background, $text_size, 0, 622 - (abs($dismensions[4] - $dismensions[0]) / 2),  409, $color['white'], $arial_bold, $string);
            $dismensions = imagettfbbox($text_size, 0, $arial_bold, ($string = $total_stats[1]['extra_kills']));
            imagettftext($img_background, $text_size, 0, 655 - (abs($dismensions[4] - $dismensions[0]) / 2),  409, $color['white'], $arial_bold, $string);
		}

		
		imagettftext($img_background, 11, 0, 105, 458, $color['white'], $verdana_bold, $team_counter[0]);
        imagettftext($img_background, $text_size, 0, 190, 463, $color['white'], $arial_bold, $total_stats[0]['damage']);
        imagettftext($img_background, $text_size, 0, 190, 448, $color['white'], $arial_bold, $total_stats[0]['kills']);	
			
		imagettftext($img_background, 11, 0, 555, 458, $color['white'], $verdana_bold, $team_counter[1]);
        imagettftext($img_background, $text_size, 0, 640, 463, $color['white'], $arial_bold, $total_stats[1]['damage']);
        imagettftext($img_background, $text_size, 0, 640, 448, $color['white'], $arial_bold, $total_stats[1]['kills']);		
		
		
        $dimensions_kills = imagettfbbox($text_size, 0, $arial_bold, ($s_kills = $_LANG[16]));
		$dimensions_damage = imagettfbbox($text_size, 0, $arial_bold, ($s_damage = $_LANG[15]));	
		
        imagettftext($img_background, $text_size, 0, (182 - abs($dimensions_kills[4] - $dimensions_kills[0])), 448, $color['light_blue'], $arial_bold, $s_kills);				
		imagettftext($img_background, $text_size, 0, (182 - abs($dimensions_damage[4] - $dimensions_damage[0])), 463, $color['light_blue'], $arial_bold, $s_damage);		
        imagettftext($img_background, $text_size, 0, (632 - abs($dimensions_kills[4] - $dimensions_kills[0])), 448, $color['light_blue'], $arial_bold, $s_kills);				
		imagettftext($img_background, $text_size, 0, (632 - abs($dimensions_damage[4] - $dimensions_damage[0])), 463, $color['light_blue'], $arial_bold, $s_damage);
		
        header("Content-Type: image/png");
        imagepng($img_background);
		
		imagedestroy($img_line);
    } else die("(2) Blad kodu");
} else die("(1) Blad kodu");
//------------------------------------------------------------------------------
if($img_background != false)	imagedestroy($img_background);
if($img_green != false)			imagedestroy($img_green);
if($img_m_green != false)		imagedestroy($img_m_green);
if($img_red != false)			imagedestroy($img_red);
if($img_m_red != false)			imagedestroy($img_m_red);
if($img_white != false)			imagedestroy($img_white);
if($img_m_white != false)		imagedestroy($img_m_white);
if($img_blue != false)			imagedestroy($img_blue);
if($img_rank != false)			imagedestroy($img_rank);