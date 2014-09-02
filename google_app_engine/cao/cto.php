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

$string = file_get_contents("http://datastore-sit.appspot.com/get?key=cao_bucketlist" , false , $context);
$json=json_decode($string,true);

$string = file_get_contents("http://datastore-sit.appspot.com/get?key=cao_log" , false , $context);
$log=json_decode($string,true);

$last=end($log["list"]);
if($last["status"]=="end"){
	exit("Session ended");
}

$string = file_get_contents("internal_hierarchy.json");
$info=json_decode($string,true);

$entry = array();
$name = "";
foreach($info["nodelist"] as $node){
	if($node["code"] == $_GET["role"]){
		$name = $node["name"];
		break;
	}
}

function check($role , $bucket , $info){
	$graph = array();
	
	foreach( $info["nodelist"] as $node){
		$graph[$node["code"]] = array();
		$lookup[$node["code"]]= false;
	}
	foreach($info["edgelist"] as $edge){
		array_push($graph[$edge[0]] , $edge[1]);
	}
	foreach($bucket as $node){
		$q = new SplQueue();
		$lookup= array();
		foreach( $info["nodelist"] as $x){
			$lookup[$x["code"]]= false;
		}
		
		$q->push($node);
		$lookup[$node] = true;
		//echo "Starting at ".$node."<br>";
		
		while($q->count()>0){
			$v = $q->top();
			//echo "Reached ".$v."<br>";
			if($v == $role)return false;
			$q->pop();
			
			foreach($graph[$v] as $n)if($lookup[$n]==false){
				//echo "Pushing ".$n."<br>";
				$q->push($n);
				$lookup[$n] = true;
			}
		}
		//echo "<br><br>";
	}
	return true;
}

if($name == ""){
	print "Role not recognized";
	
	$entry["time"]= date('Y-m-d H:i:s');
	$entry["msg"] = "request for unidentified role <b>".$_GET["role"]."</b> ignored";
	$entry["status"]="failure";
	array_push($log["list"] , $entry);
	file_get_contents("http://datastore-sit.appspot.com/put?key=cao_log&value=".json_encode($log, JSON_FORCE_OBJECT) , false , $context);
}else if(check($_GET["role"] , $json["bucket"] , $info)==false ){
	print("Cannot grant access");
	
	$entry["time"]= date('Y-m-d H:i:s');
	$entry["msg"] = "request for <b>".$name."</b> dismissed";
	$entry["status"]="failure";
	array_push($log["list"] , $entry);
	file_get_contents("http://datastore-sit.appspot.com/put?key=cao_log&value=".json_encode($log, JSON_FORCE_OBJECT) , false , $context);
}else{
	array_push($json["bucket"] , $_GET["role"]);
	
	$entry["time"]= date('Y-m-d H:i:s');
	$entry["msg"] = "request for <b>".$name."</b> granted";
	$entry["status"]="success";
	array_push($log["list"] , $entry);
	
	print("Access granted");
	file_get_contents("http://datastore-sit.appspot.com/put?key=cao_bucketlist&value=".json_encode($json, JSON_FORCE_OBJECT) , false , $context);
	file_get_contents("http://datastore-sit.appspot.com/put?key=cao_log&value=".json_encode($log, JSON_FORCE_OBJECT) , false , $context);
	echo "http://datastore-sit.appspot.com/put?key=cao_log&value=".json_encode($log, JSON_FORCE_OBJECT) , false;
}
