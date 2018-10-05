<p class="anchor"><a href="#public_cmd">Komendy publiczne</a>, <a href="#junior_admin_cmd">Komendy junior admina</a>, <a href="#admin_cmd">Komendy admina</a>, <a href="#head_admin_cmd">Komendy head admina</a></p>

<a name="public_cmd"/>
<p>Komendy publiczne</p>
<table class="table_style_1">
	<thead>
		<tr>
			<td width='150'>Komenda</td>
			<td width='150'>Parametry</td>
			<td width='400'>Opis</td>
		</tr>
	</thead>
	<tbody>
		<?php 
			$cmd_type = "public";
			include(dirname(__FILE__)."/../m_mad_help/m_cmds.php"); 
		?>
	</tbody>
</table>

<a name="junior_admin_cmd"/>
<p>Komendy Junior Admina</p>
<table class="table_style_1">
	<thead>
		<tr>
			<td width='150'>Komenda</td>
			<td width='150'>Parametry</td>
			<td width='400'>Opis</td>
		</tr>
	</thead>
	<tbody>
		<?php 
			$cmd_type = "j-admin";
			include(dirname(__FILE__)."/../m_mad_help/m_cmds.php"); 
		?>
	</tbody>
</table>

<a name="admin_cmd"/>
<p>Komendy Admina</p>
<table class="table_style_1">
	<thead>
		<tr>
			<td width='150'>Komenda</td>
			<td width='150'>Parametry</td>
			<td width='400'>Opis</td>
		</tr>
	</thead>
	<tbody>
		<?php 
			$cmd_type = "admin";
			include(dirname(__FILE__)."/../m_mad_help/m_cmds.php"); 
		?>
	</tbody>
</table>

<a name="head_admin_cmd"/>
<p>Komendy Head Admina</p>
<table class="table_style_1">
	<thead>
		<tr>
			<td width='150'>Komenda</td>
			<td width='150'>Parametry</td>
			<td width='400'>Opis</td>
		</tr>
	</thead>
	<tbody>
		<?php 
			$cmd_type = "h-admin";
			include(dirname(__FILE__)."/../m_mad_help/m_cmds.php"); 
		?>
	</tbody>
</table>
