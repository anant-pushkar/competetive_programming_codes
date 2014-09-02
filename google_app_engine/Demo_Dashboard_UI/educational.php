<?php 
ini_set('display_errors','On');
error_reporting(E_ALL);
$edgelist = [
		['1','6','','To understand fundamental interactions between orgainc molecules'],
		['5','1','','To understand Interaction between molecules'],
		['7','1','','To understand Heat Flow'],
		['10','1','','To understand Heat Flow'],
		['6','8','','To understand higher oxidation states'],
		['8','9','','To understand highest Oxidation state'],
		
	];
$obj = array();
$id = 1;
foreach ($edgelist as $edge){
	array_push($obj,array('id'=>(string)$id , 'from'=>$edge[0] , 'to'=>$edge[1] , 'text'=>$edge[2] , 'description'=>$edge[3]));
	$id = $id+1;
}
$graph = array();
$graph["edgelist"] = $obj;

$obj = array();

array_push($obj , array('id'=> '1'  , 'description'=>'General Concepts in Organic Chemistry','text'=>'GOC', 'leaf'=>true ));
array_push($obj , array('id'=> '5'  , 'description'=>'Study of General Bonds between molecules in Chemistry','text'=>'Chemical Bonding', 'leaf'=>true ));
array_push($obj , array('id'=> '6'  , 'description'=>'Compounds composed of Hydrogen and Carbon','text'=>'Hydrocarbons', 'leaf'=>true ));
array_push($obj , array('id'=> '7'  , 'description'=>'Study of flow of energy in chemical reactions','text'=>'Thermodynamics', 'leaf'=>true ));
array_push($obj , array('id'=> '10'  , 'description'=>'Mole concept','text'=>'Stocheometry', 'leaf'=>true ));
array_push($obj , array('id'=> '8'  , 'description'=>'-CO family','text'=>'Ketones', 'leaf'=>true ));
array_push($obj , array('id'=> '9'  , 'description'=>'-COOH family','text'=>'Carbolxillic Acid', 'leaf'=>true ));

array_push($obj , array('id'=> '4'  , 'description'=>'','text'=>'Organic Chemistry', 'leaf'=>false ,'radius' => 20 , 'style'=>'dot','backgroundColor'=>'#FFFFFF'));
array_push($obj , array('id'=> '2'  , 'description'=>'','text'=>'Inorganic Chemistry', 'leaf'=>false ,'radius' => 20 , 'style'=>'dot','backgroundColor'=>'#FFFFFF'));
array_push($obj , array('id'=> '3'  , 'description'=>'','text'=>'Physical Chemistry', 'leaf'=>false ,'radius' => 20 , 'style'=>'dot','backgroundColor'=>'#FFFFFF'));

$graph["nodelist"]=$obj;
$graph["summary"] = array(
		'4'=>array('1','6','8','9'),
		'2'=>array('5'),
		'3'=>array('7','10')
	);
$graph["style"] = "arrow-end";
if(isset($_POST["fname"]) && isset($_POST["lname"])){
	$graph["nodelist"] = [];
	$graph["edgelist"] = [];
	$graph["summary"]  = array();
	array_push($graph["nodelist"] , array("id"=>"1" , "text"=>$_POST["fname"] , "leaf"=>true , "description" =>"new node added"));
	array_push($graph["nodelist"] , array("id"=>"2" , "text"=>$_POST["lname"] , "leaf"=>true, "description" =>"new node added"));
	array_push($graph["edgelist"] , array("id"=>"1001" , "from" => "2" , "to"=>"1" , "color"=>"#666666"));
	$graph["summary"]['1012'] = array('2' , '1');
	$i = 1012;
	array_push($graph["nodelist"] , array('id'=>(string)$i , 'text'=>"#".(string)$i , 'description'=>'This is description for NODE#'.(string)$i ,
	'backgroundColor'=>'#FFFFFF' , 'leaf'=>false ,
	'radius' =>20 , 'style'=>'dot'));
}
/*
	$graph["nodelist"] = [];
	$graph["edgelist"] = [];
	$graph["summary"]  = array();
	array_push($graph["nodelist"] , array("id"=>"1" , "text"=>"1" , "leaf"=>true , "description" =>"property1"));
	array_push($graph["nodelist"] , array("id"=>"2" , "text"=>"2" , "leaf"=>true , "description" =>"property2"));
	array_push($graph["nodelist"] , array("id"=>"1001" , "text"=>"1001" , "leaf"=>false , "description" =>"summary node"));
	array_push($graph["edgelist"] , array("id"=>"1001" , "from" => "1" , "to"=>"2" , "color"=>"#666666"));
	$graph["summary"]['1001'] = array('2' , '1');
*/
/*
$graph["typelist"] = array(
								"type1" => array('1','2','3','4','1001','10','12','13','14','1005'),
								"type2" => array('5','6','7','8','9','1004','11','1006'),
								"type3" => array('1003','1002','1007','7','1008','15','17','18','19','1009','1010','16','20','21','22')
							);
*/
//echo $_POST["key"];
$data["graph"] = $graph;
//$data["graph"] = "";
$data["html"]  = "<div class='well'><div>POST : ".serialize($_POST)."</div><div>GET : ".serialize($_GET)."</div></div>";
//$data["html"] = "";
$data["timeline"] = json_decode('{"events":[{"dates":[{"year":2011,"month":0,"day":31}],"title":"2011 Season Opener","section":0},{"dates":[{"year":2012,"month":1,"day":29}],"title":"Spring Training Begins","section":2},{"dates":[{"year":2012,"month":3,"day":9},{"year":2012,"month":3,"day":11}],"title":"Atlanta Braves @ Houston Astros","section":1},{"dates":[{"year":2012,"month":2,"day":28},{"year":2012,"month":2,"day":29}],"title":"Seattle Mariners v. Oakland A","section":2,"description":"Played in Japan!"}],"sections":[{"dates":[{"year":2011,"month":0,"day":20},{"year":2011,"month":9,"day":28}],"title":"2011 MLB Season","section":0,"attrs":{"fill":"#d4e3fd"}},{"dates":[{"year":2012,"month":2,"day":28},{"year":2012,"month":9,"day":3}],"title":"2012 Regular MLB Season","section":1,"attrs":{"fill":"#d4e3fd"}},{"dates":[{"year":2012,"month":1,"day":29},{"year":2012,"month":3,"day":10}],"title":"Spring Training","section":2,"attrs":{"fill":"#eaf0fa"}}]}');
//$data["timeline"] = "";
echo json_encode($data);
?>