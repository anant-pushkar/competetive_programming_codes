<?php
/*
Project Name : file_io
Created on   : Sat Aug  2 16:06:17 2014

*/
print_r($_GET);
if($_GET["status"]=="write"){
	echo "WRITING";
	file_put_contents('gs://anantpushkar3.appspot.com/hello.txt', $_GET["text"]);
}
echo file_get_contents('gs://anantpushkar3.appspot.com/hello.txt', true);
?>
