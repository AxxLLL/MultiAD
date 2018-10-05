<?php 
//==============================================================================
//error_reporting(E_ERROR | E_WARNING | E_PARSE | E_NOTICE);
if(!defined("FROM_FUNCTION")) exit;
//==============================================================================
$img_background = @imagecreatefrompng($images_dir."/small.png");
//------------------------------------------------------------------------------
if($img_background != false) {
    if(file_exists(($arial_bold = $fonts_dir."/arial_bold.ttf")) && file_exists(($verdana_bold = $fonts_dir."/verdanab.ttf")) && file_exists(($arial = $fonts_dir."/arial.ttf")) && file_exists(($verdana = $fonts_dir."/Verdana.ttf"))) {
        $color = array('light_blue' => imagecolorallocate($img_background, 2, 113, 249), 'light_grey' => imagecolorallocate($img_background, 220, 220, 220), 'white' => imagecolorallocate($img_background, 255, 255, 255), 'grey' => imagecolorallocate($img_background, 180, 180, 180));
        //---------------------

        //--------------------- 		
        imagesavealpha($img_background, true);
        //---------------------			
		$y_pos = 103;
		//---------------------
        $dimensions = imagettfbbox(14, 0, $arial, ($string = sprintf("%d : %d", $general_data['team'][0]['points'], $general_data['team'][1]['points'])));	
        imagettftext($img_background, 14, 0, 350 - (abs($dimensions[4] - $dimensions[0]) / 2), $y_pos, $color['white'], $arial, $string);
		//---------------------
		$dimensions = imagettfbbox(16, 0, $arial, ($string = $general_data['team'][0]['name']));
		imagettftext($img_background, 16, 0, 300 - abs($dimensions[4] - $dimensions[0]), $y_pos, $color['light_blue'], $arial, $string);
		imagettftext($img_background, 16, 0, 400, $y_pos, $color['light_blue'], $arial, $general_data['team'][1]['name']);
        //---------------------
		$y_pos = 150;
		//---------------------
		if($this -> getMatchServerData(MS_IP) != false) $dimensions = imagettfbbox(8, 0, $arial, ($string = sprintf("%s  (IP: %s:%d)", $this -> getMatchServerData(MS_SERVER_LAST_NAME), long2ip($this -> getMatchServerData(MS_IP)), $this -> getMatchServerData(MS_PORT))));		
        else $dimensions = imagettfbbox(8, 0, $arial, $this -> getMatchServerData(MS_SERVER_LAST_NAME));		
		imagettftext($img_background, 8, 0, 680 - abs($dimensions[4] - $dimensions[0]), $y_pos, $color['grey'], $arial, $string); //Nazwa hosta w stopce
        //---------------------
        imagettftext($img_background, 8, 0, 20, $y_pos, $color['grey'], $arial, date("d-m-Y [H:i:s]", $this -> getMatchServerData(MNM_ADD_TIME)));			
        //---------------------	
		
        //---------------------			
        header("Content-Type: image/png");
        imagepng($img_background);
    } else die("(2) Blad kodu");
} else die("(1) Blad kodu");
//------------------------------------------------------------------------------
if($img_background != false)	imagedestroy($img_background);