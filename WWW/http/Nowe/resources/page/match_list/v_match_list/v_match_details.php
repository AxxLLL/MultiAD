<?php 
$match_details_url = dirname(__FILE__)."/../m_match_list/m_match_details";
include($match_details_url."/m_match_details.php"); 
?>

<table>
	<tbody>
		<?php include($match_details_url."/m_table_info.php"); ?> 
	</tbody>
</table>

<p><a href="?page=matchlist">Wroc do listy rezultatow</a></p>