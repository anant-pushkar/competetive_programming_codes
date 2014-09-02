<?php
class RoleSpace extends CI_Model {
	var $project ;
	var $graph;
	function __construct(){
        parent::__construct();
        $string = file_get_contents("project.json");
		$this->project = json_decode($string, true);
		$this->get_graph();
    }
    function get_graph(){
    	$data = ['data' => 'this', 'data2' => 'that'];
		$data = http_build_query($data);
		$context = [
		  'http' => [
			'method' => 'get',
			'header' => "Content-type: "."application/x-www-form-urlencoded"."\r\n",
			'content' => $data,
			"proxy"  => "tcp://144.16.192.245:8080",
			'request_fulluri' => true
		  ]
		];
		$context = stream_context_create($context);
		//$result = file_get_contents("http://datastore-sit.appspot.com/get?key=".$this->project["key"]."_graph", false, $context);
		$result = file_get_contents("http://datastore-sit.appspot.com/get?key=".$this->project["key"]."_graph" , false , $context);
    	//$string = file_get_contents("http://datastore-sit.appspot.com/get?key=".$this->project["name"]."_graph");
    	$this->graph = json_decode($result, true);
    	echo "<div style='color:#ff0000'>".$result."</div>";
    }
    function test(){
    	print_r($this->project);
    	print_r($this->graph);
    	return "OK";
    }
}	
