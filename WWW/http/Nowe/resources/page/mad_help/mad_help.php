<?php 

if(isset($_GET['type'])) {
	switch($_GET['type']) {
		case 'cmds':
			if(file_exists(($url_address = dirname(__FILE__)."/xml/commands.xml"))) { 
				include(dirname(__FILE__)."/v_mad_help/v_cmds.php");
			} else echo "<p class='missing_data'>Brak informacji. Spróbuj póŸniej...</p>";
		break;		
		case 'install': 
			if(file_exists(($url_address = dirname(__FILE__)."/xml/installation.xml"))) { 
				include(dirname(__FILE__)."/v_mad_help/v_simple_text.php");
			} else echo "<p class='missing_data'>Brak informacji. Spróbuj póŸniej...</p>";
		break;

		case 'systems': 
			if(file_exists(($url_address = dirname(__FILE__)."/xml/systems.xml"))) {
				include(dirname(__FILE__)."/v_mad_help/v_simple_text.php");
			} else echo "<p class='missing_data'>Brak informacji. Spróbuj póŸniej...</p>";		
		break;
		case 'mods': 
			if(file_exists(($url_address = dirname(__FILE__)."/xml/modifications.xml"))) { 
				include(dirname(__FILE__)."/v_mad_help/v_simple_text.php");
			} else echo "<p class='missing_data'>Brak informacji. Spróbuj póŸniej...</p>";		
		break;
		default: 
			echo "<p class='missing_data'>Brak informacji. Spróbuj póŸniej...</p>";		
		break;
	}
}