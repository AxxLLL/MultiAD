<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("IN_PHP")) exit;
//==============================================================================
$img_background = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/tlo.png");
$img_green = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/green.png");
$img_red = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/red.png");
$img_white = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/white.png");
$img_blue = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/blue.png");
$img_rank = @imagecreatefrompng(dirname(dirname(dirname(__FILE__)))."/img/match_results/rank.png");
//------------------------------------------------------------------------------
if($img_background != false && $img_green != false && $img_red != false && $img_blue != false && $img_rank != false && $img_white != false) {
    if(file_exists(($verdana_bold = dirname(dirname(dirname(__FILE__)))."/includes/fonts/verdanab.ttf")) && file_exists(($arial_bold = dirname(dirname(dirname(__FILE__)))."/includes/fonts/arial_bold.ttf")) && file_exists(($arial = dirname(dirname(dirname(__FILE__)))."/includes/fonts/arial.ttf")) && file_exists(($verdana = dirname(dirname(dirname(__FILE__)))."/includes/fonts/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180));
        //---------------------

        //--------------------- 		
        imagesavealpha($img_background, true);
        //---------------------
        imagecopy($img_background, $img_blue, 20, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (lewa)
        imagecopy($img_background, $img_blue, 250, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (srodek)
        imagecopy($img_background, $img_blue, 480, 146, 0, 0, imagesx($img_blue), imagesy($img_blue));	//Podswietlenie napisu (prawa)
        //---------------------			
        $dimensions = imagettfbbox(14, 0, $arial, $team_data[0]['name']);	//Wyrownanie do prawej nazwy pierwszej druzyny w naglowku
        imagettftext($img_background, 14, 0, (320 - abs($dimensions[4] - $dimensions[0])), 89, $color['light_grey'], $arial, $team_data[0]['name']);
        //---------------------
        imagettftext($img_background, 14, 0, 388, 89, $color['light_grey'], $arial, $team_data[1]['name']);	//Nazwa drugiej druzyny w naglowku
        imagettftext($img_background, 14, 0, 378, 120, $color['light_grey'], $arial, ($team_data[0]['points'] != $team_data[1]['points'] ? ($team_data[0]['points'] > $team_data[1]['points'] ? ($team_data[0]['name']) : ($team_data[1]['name'])) : ("Remis")));	//Wygrywa
        imagettftext($img_background, 11, 0, 326, 165, $color['light_grey'], $verdana_bold, "Runda");
        imagettftext($img_background, 8, 0, 170, 456, $color['white'], $arial, $hostname); //Nazwa hosta w stopce
        imagettftext($img_background, 8, 0, 170, 473, $color['grey'], $verdana, ($server_address == false ? ("Brak IP") : ($server_address))); //IP w stopce
        imagettftext($img_background, 8, 0, 445, 456, $color['light_blue'], $verdana_bold, "ROZEGRANO");
        //---------------------
        $string = sprintf("Punktów: %d", $team_data[0]['points']); //Wycentrowanie punktow z lewej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);
        imagettftext($img_background, 11, 0, 123 - (abs($dismensions[4] - $dismensions[0]) / 2), 165, $color['light_grey'], $verdana_bold, $string); //Punkty lewa
        //---------------------
        $string = sprintf("Punktów: %d", $team_data[1]['points']); //Wycentrowanie punktow z prawej
        $dismensions = imagettfbbox(11, 0, $verdana_bold, $string);				
        imagettftext($img_background, 11, 0, 582 - (abs($dismensions[4] - $dismensions[0]) / 2), 165, $color['light_grey'], $verdana_bold, sprintf("Punktów: %d", $team_data[1]['points']));	//Punkty Prawa			
        //---------------------
        $string = date("Y-m-d [H:i:s]", $results[MM_ADD_TIME]); //Wyrownanie do prawej daty rozegrania meczu
        $dismensions = imagettfbbox(8, 0, $verdana, $string);
        $dismensions_play_time = imagettfbbox(8, 0, $verdana_bold, "ROZEGRANO");
        imagettftext($img_background, 8, 0, (445 + (abs($dismensions_play_time[4] - $dismensions_play_time[0]) / 2 )) - (abs($dismensions[4] - $dismensions[0]) / 2), 473, $color['grey'], $verdana, date("Y-m-d [H:i:s]", $results[MM_ADD_TIME]));			
        //---------------------	
        /*
            Przygotowanie (wycentrowanie) pozycji 'X' dla napisow rezultatu rundy druzyn oraz podswietlenia info. o rundzie
        */
        $dimensions = imagettfbbox(9, 0, $verdana_bold, "WYGRANA");
        $win_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);
        $win_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);

        $dimensions = imagettfbbox(9, 0, $verdana_bold, "PRZEGRANA");
        $loss_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);
        $loss_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);

        $dimensions = imagettfbbox(9, 0, $verdana_bold, "REMIS");
        $draw_center_x[0] = 123 - (abs($dimensions[4] - $dimensions[0]) / 2);				
        $draw_center_x[1] = 582 - (abs($dimensions[4] - $dimensions[0]) / 2);		

        $center_round_box = 350 - (imagesx($img_rank) / 2);			
        //---------------------					
        for($i = 0; $i < $results[MM_ROUND_LIMIT]; $i ++) { //170:25	191:22						
            imagecopy($img_background, $img_rank, 246, (173 + $i * 22), 0, 0, imagesx($img_rank), imagesy($img_rank));				

            $string = sprintf("%s %d", ($round_data[$i]['type'] == 0 ? ("ARENA") : ("BAZA")), $round_data[$i]['mapid']);
            $dimensions = imagettfbbox(9, 0, $verdana_bold, $string);
            $center_x = 350 - (abs($dimensions[4] - $dimensions[0]) / 2);			
            imagettftext($img_background, 9, 0, $center_x, 191 + ($i * 22), $color['light_grey'], $verdana_bold, $string);				

            if($round_data[$i]['type'] == 1) {
                    imagettftext($img_background, 10, 0, ($round_data[$i]['defender'] == 0 ? 260 : 423), 191 + ($i * 22), $color['light_blue'], $arial_bold, "(D)");
            }

            switch($round_data[$i]['winner']) {
                case 0: 
                    imagecopy($img_background, $img_green, 16, (172 + $i * 22), 0, 0, imagesx($img_blue), imagesy($img_blue));
                    imagecopy($img_background, $img_red, 470, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));				 	  	
                    imagettftext($img_background, 9, 0, $win_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "WYGRANA");	
                    imagettftext($img_background, 9, 0, $loss_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "PRZEGRANA");	
                break;
                case 1:
                    imagecopy($img_background, $img_red, 16, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagecopy($img_background, $img_green, 470, (172 + $i * 22), 0, 0, imagesx($img_green), imagesy($img_green));
                    imagettftext($img_background, 9, 0, $win_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "WYGRANA");	
                    imagettftext($img_background, 9, 0, $loss_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "PRZEGRANA");						
                break;
                default: 
                    imagecopy($img_background, $img_white, 16, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagecopy($img_background, $img_white, 470, (172 + $i * 22), 0, 0, imagesx($img_red), imagesy($img_red));
                    imagettftext($img_background, 9, 0, $draw_center_x[0], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "REMIS");	
                    imagettftext($img_background, 9, 0, $draw_center_x[1], 191 + ($i * 22), $color['light_grey'], $verdana_bold, "REMIS");				  	
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
if($img_green != false) imagedestroy($img_green);
if($img_red != false) imagedestroy($img_red);
if($img_blue != false) imagedestroy($img_blue);
if($img_rank != false) imagedestroy($img_rank);
?>