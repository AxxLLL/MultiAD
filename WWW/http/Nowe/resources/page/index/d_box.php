<table class="table_style_2">
	<tbody>
		<?php
		if(file_exists(dirname(__FILE__)."/data/starting.xml") && ($xml = simplexml_load_file(dirname(__FILE__)."/data/starting.xml")) != false) {
			for($i = 0; $i < count($xml); $i ++) {
				switch($xml -> type[$i]['name']) {
					case 'MAD': 
						echo 	"<tr>
									<td>Aktualna wersja MAD</td>
									<td><a href='".$xml -> type[$i]['download']."'>".$xml -> type[$i]['version']."</a></td>
								</tr>";			
					break;
					case 'SA-MP': 
						echo 	"<tr>
									<td>Aktualna wersja SA-MP</td>
									<td><a href='".$xml -> type[$i]['download']."'>".$xml -> type[$i]['version']."</a></td>
								</tr>";						
					break;
				}
			}
		}		
		?>
	</tbody>
</table>