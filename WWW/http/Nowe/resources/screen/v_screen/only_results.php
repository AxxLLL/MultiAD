<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("FROM_FUNCTION")) exit;
//==============================================================================
$img_background = @imagecreatefrompng($images_dir."/tlo.png");
$img_green = @imagecreatefrompng($images_dir."/green.png");
$img_red = @imagecreatefrompng($images_dir."/red.png");
$img_white = @imagecreatefrompng($images_dir."/white.png");
$img_blue = @imagecreatefrompng($images_dir."/blue.png");
$img_rank = @imagecreatefrompng($images_dir."/rank.png");
//------------------------------------------------------------------------------
if($img_background != false && $img_green != false && $img_red != false && $img_blue != false && $img_rank != false && $img_white != false) {
    if(file_exists(($verdana_2 = $fonts_dir."/verdana_2.ttf")) && file_exists(($verdana_bold = $fonts_dir."/verdanab.ttf")) && file_exists(($arial_bold = $fonts_dir."/arial_bold.ttf")) && file_exists(($arial = $fonts_dir."/arial.ttf")) && file_exists(($verdana = $fonts_dir."/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180));
        //--------------------- 		
        imagesavealpha($img_background, true);
		//--------------------- 
		$dimensions = imagettfbbox(14, 0, $verdana_2, ($string = $_LANG[19]));
		imagettftext($img_background, 14, 0, 355 - ($dimensions[4] - $dimensions[0]), 120, $color['light_blue'], $verdana_2, $string);
        //---------------------
        imagecopy($img_background, $img_blue, 20, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (lewa)
        imagecopy($img_background, $img_blue, 250, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (srodek)
        imagecopy($img_background, $img_blue, 480, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (prawa)
        //---------------------			
        $dimensions = imagettfbbox(14, 0, $arial, ($string = $general_data['team'][0]['name']));	//Wyrownanie do prawej nazwy pierwszej druzyny w naglowku
        imagettftext($img_background, 14, 0, (320 - abs($dimensions[4] - $dimensions[0])), 89, $color['light_grey'], $arial, $string);
        //---------------------
        imagettftext($img_background, 14, 0, 388, 89, $color['light_grey'], $arial, $general_data['team'][1]['name']);	//Nazwa drugiej druzyny w naglowku
        imagettftext($img_background, 14, 0, 378, 120, $color['light_grey'], $arial, ($general_data['team'][0]['points'] != $general_data['team'][1]['points'] ? ($general_data['team'][0]['points'] > $general_data['team'][1]['points'] ? ($general_data['team'][0]['name']) : ($general_data['team'][1]['name'])) : ($_LANG[17])));	//Wygrywa
        imagettftext($img_background, 11, 0, 326, 165, $color['light_grey'], $verdana_bold, $_LANG[0]);
        imagettftext($img_background, 8, 0, 170, 456, $color['white'], $arial, $this -> getMatchServerData(MS_SERVER_LAST_NAME)); //Nazwa hosta w stopce
        imagettftext($img_background, 8, 0, 170, 473, $color['grey'], $verdana, ($this -> getMatchServerData(MS_IP) == false ? ($_LANG[3]) : (sprintf("%s:%d", long2ip($this -> getMatchServerData(MS_IP)), $this -> getMatchServerData(MS_PORT))))); //IP w stopce
        imagettftext($img_background, 8, 0, 445, 456, $color['light_blue'], $verdana_bold, $_LANG[4]);
        //---------------------
        $string = sprintf($_LANG[18], $general_data['team'][0]['points'] ); //Wycentrowanie punktow z lewej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);
        imagettftext($img_background, 11, 0, 123 - (abs($dismensions[4] - $dismensions[0]) / 2), 165, $color['light_grey'], $verdana_bold, $string); //Punkty lewa
        //---------------------
        $string = sprintf($_LANG[18], $general_data['team'][1]['points']); //Wycentrowanie punktow z prawej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);				
        imagettftext($img_background, 11, 0, 582 - (abs($dismensions[4] - $dismensions[0]) / 2), 165, $color['light_grey'], $verdana_bold, $string); //Punkty Prawa			
        //---------------------
        $string = date("d-m-Y [H:i:s]", $this -> getMatchServerData(MNM_ADD_TIME)); //Wyrownanie do prawej daty rozegrania meczu
        $dismensions = imagettfbbox(8, 0, $verdana, $string);
        $dismensions_play_time = imagettfbbox(8, 0, $verdana_bold, $_LANG[4]);
        imagettftext($img_background, 8, 0, (445 + (abs($dismensions_play_time[4] - $dismensions_play_time[0]) / 2 )) - (abs($dismensions[4] - $dismensions[0]) / 2), 473, $color['grey'], $verdana, $string);			
        //---------------------	
        /*
            Przygotowanie (wycentrowanie) pozycji 'X' dla napisow rezultatu rundy druzyn oraz podswietlenia info. o rundzie
        */
        $dimensions = imagettfbbox(9, 0, $verdana_bold, $_LANG[8]);
        $win_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);
        $win_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);

        $dimensions = imagettfbbox(9, 0, $verdana_bold, $_LANG[9]);
        $loss_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);
        $loss_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);

        $dimensions = imagettfbbox(9, 0, $verdana_bold, $_LANG[10]);
        $draw_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);				
        $draw_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);		

        $center_round_box = 350 - (imagesx($img_rank) / 2);			
        //---------------------					
        for($i = 0; $i < $general_data['rounds']; $i ++) { //170:25	191:22						
            imagecopy($img_background, $img_rank, 246, (173 + $i * 22), 0, 0, imagesx($img_rank), imagesy($img_rank));				

            $string = sprintf("%s %d", ($rounds_data[$i][1] == 0 ? ($rounds_data[$i][6] == 0 ? ($_LANG[11]) : ($_LANG[12])) : ($_LANG[13])), $rounds_data[$i][0]);
            $dimensions = imagettfbbox(9, 0, $verdana_bold, $string);
            $center_x = 350 - (abs($dimensions[4] - $dimensions[0]) / 2);			
            imagettftext($img_background, 9, 0, $center_x, 191 + ($i * 22), $color['light_grey'], $verdana_bold, $string);				

            if($rounds_data[$i][1] == 1) {
                imagettftext($img_background, 10, 0, ($rounds_data[$i][4] == 0 ? 260 : 423), 191 + ($i * 22), $color['light_blue'], $arial_bold, "(D)");
            }

            switch($rounds_data[$i][2]) {
                case 0: 
                    imagecopy($img_background, $img_green, 16, (172 + $i * 22), 0, 0, imagesx($img_blue), imagesy($img_blue));
                    imagecopy($img_background, $img_red, 470, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));				 	  	
                    imagettftext($img_background, 9, 0, $win_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[8]);	
                    imagettftext($img_background, 9, 0, $loss_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[9]);	
                break;
                case 1:
                    imagecopy($img_background, $img_red, 16, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagecopy($img_background, $img_green, 470, (172 + $i * 22), 0, 0, imagesx($img_green), imagesy($img_green));
                    imagettftext($img_background, 9, 0, $win_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[8]);	
                    imagettftext($img_background, 9, 0, $loss_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[9]);						
                break;
                default: 
                    imagecopy($img_background, $img_white, 16, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagecopy($img_background, $img_white, 470, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagettftext($img_background, 9, 0, $draw_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[10]);	
                    imagettftext($img_background, 9, 0, $draw_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, $_LANG[10]);				  	
                break; 
            }													
        }						
        //---------------------			
        header("Content-Type: image/png");
        imagepng($img_background);
    } else die("(2) Blad kodu");
} else die("(1) Blad kodu");
//------------------------------------------------------------------------------
if($img_background != false)	imagedestroy($img_background);
if($img_green != false)			imagedestroy($img_green);
if($img_red != false)			imagedestroy($img_red);
if($img_white != false)			imagedestroy($img_white);
if($img_blue != false)			imagedestroy($img_blue);
if($img_rank != false)			imagedestroy($img_rank);