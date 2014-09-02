<?php

$data = ['data' => 'this', 'data2' => 'that'];
$data = http_build_query($data);
$context = [
  'http' => [
	'method' => 'get',
	'header' => "Content-type: "."application/x-www-form-urlencoded"."\r\n",
	'content' => $data
  ]
];
$context = stream_context_create($context);

$entry = array();
$entry["time"]= date('Y-m-d H:i:s');
$entry["msg"] = "Session Ended";
$entry["status"]="end";

$string = file_get_contents("http://datastore-sit.appspot.com/get?key=cao_log" , false , $context);
$log=json_decode($string,true);

$last=end($log["list"]);
if($last["status"]=="end"){
	exit("Session ended");
}

array_push($log["list"] , $entry);

file_get_contents("http://datastore-sit.appspot.com/put?key=cao_log&value=".json_encode($log, JSON_FORCE_OBJECT) , false , $context);
print("Session ended");
