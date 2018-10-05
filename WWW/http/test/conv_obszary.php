<?php
if(($f_obszary = fopen("./obszary.txt", "r")) != false) {

    $old_base_index = -1;
    $counter_success = 0;
    $counter_fail = 0;
    while(!feof($f_obszary)) {        
        list($base_id, $type, $read_x, $read_y, $read_z) = sscanf(fgets($f_obszary), "%d:%d,%f,%f,%f");
        
        if($old_base_index != $base_id) {            
            
            if($old_base_index != -1) {
                $success = false;
                printf("<br/>Baza %d", $old_base_index);
                if($new_max_z > $new_min_z && $new_min_z != 9999.0 && $new_max_z != -9999.0) {
                    if($new_max_x > $new_min_x && $new_min_x != 9999.0 && $new_max_x != -9999.0) {
                        if($new_max_y > $new_min_y && $new_min_y != 9999.0 && $new_max_y != -9999.0) {
                            printf("| zone: %.4f, %.4f, %.4f, %.4f, %.4f, %.4f", $new_min_x, $new_min_y, $new_max_x, $new_max_y, $new_min_z, $new_max_z);
                            $success = true;
                            $counter_success ++;
                        } else printf("<br/>Error: Y positions (Min: %.4f | Max: %.4f)", $new_min_y, $new_max_y); 
                    } else printf("<br/>Error: X positions (Min: %.4f | Max: %.4f)", $new_min_x, $new_max_x);  
                } else printf("<br/>Error: Z positions (Min: %.4f | Max: %.4f)", $new_min_z, $new_max_z);   
                if($success == false) {
                    print("<br/>------------------");
                    $counter_fail ++;
                }
            }
            
            $old_base_index = $base_id;
            $new_max_x = -9999.0;
            $new_min_x = 9999.0;
            $new_max_y = -9999.0;
            $new_min_y = 9999.0;
            $new_max_z = -9999.0;
            $new_min_z = 9999.0;                  
        }

        if(is_numeric($base_id) && 99 >= $base_id && $base_id >= 0 && ($type == 1 || $type == 0)) {            
            if($type == 1) {
                if($read_z > $new_max_z) $new_max_z = $read_z; 
                if($read_z < $new_min_z) $new_min_z = $read_z;
            } else {
                if($read_x > $new_max_x) $new_max_x = $read_x; 
                if($read_x < $new_min_x) $new_min_x = $read_x;
                if($read_y > $new_max_y) $new_max_y = $read_y; 
                if($read_y < $new_min_y) $new_min_y = $read_y;                
            }
        } 

    } 
    
    $success = false;
    printf("<br/>Baza %d", $old_base_index);
    if($new_max_z > $new_min_z && $new_min_z != 9999.0 && $new_max_z != -9999.0) {
        if($new_max_x > $new_min_x && $new_min_x != 9999.0 && $new_max_x != -9999.0) {
            if($new_max_y > $new_min_y && $new_min_y != 9999.0 && $new_max_y != -9999.0) {
                printf("| zone: %.4f, %.4f, %.4f, %.4f, %.4f, %.4f", $new_min_x, $new_min_y, $new_max_x, $new_max_y, $new_min_z, $new_max_z);
                $success = true;
                $counter_success ++;
            } else printf("<br/>Error: Y positions (Min: %.4f | Max: %.4f)", $new_min_y, $new_max_y); 
        } else printf("<br/>Error: X positions (Min: %.4f | Max: %.4f)", $new_min_x, $new_max_x);  
    } else printf("<br/>Error: Z positions (Min: %.4f | Max: %.4f)", $new_min_z, $new_max_z);   
    if($success == false) {
        print("<br/>------------------");
        $counter_fail ++;
    }
    
    

    fclose($f_obszary);

    printf("<br/><br/>------------</br>Converted end</br>Success: %d<br/>Fails: %d", $counter_success, $counter_fail);
} else printf("File not found");
?>