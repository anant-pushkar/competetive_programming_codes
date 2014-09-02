<?php 
ini_set('display_errors','On');
error_reporting(E_ALL);

$graph["nodelist"] = array();
array_push($graph["nodelist"] , array(	'id'=>'1'  , 
										'text'=>'President',
										'description'=>'Executive head of the domain' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'11'  , 
										'text'=>'Advisor',
										'description'=>'Advisor to the president' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'2'  , 
										'text'=>'Vice President [overseas relations]',
										'description'=>'Handles all overseas relations' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'3'  , 
										'text'=>'Vice President [Marketting]',
										'description'=>'Handles all marketing affairs' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'4'  , 
										'text'=>'Vice President [HR]',
										'description'=>'Handles Human resources for the company' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'5'  , 
										'text'=>' Project Manager [USA]',
										'description'=>'Manages all projects with USA' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'6'  , 
										'text'=>'Project Manager [Europe]',
										'description'=>'Manages all projects with Europe' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'7'  , 
										'text'=>'Project Manager[Asia]',
										'description'=>'Manages All projects with Asia' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'8'  , 
										'text'=>'Marketting Manager',
										'description'=>'Handles all marketting operations' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'9'  , 
										'text'=>'Operations Head',
										'description'=>'Overseas all oparations in the company' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'10'  , 
										'text'=>'Chief Engineer',
										'description'=>'Technical Head' , 
										'backgroundColor'=>'#AAAAAA' , 
										'leaf'=>true ));
array_push($graph["nodelist"] , array(	'id'=>'1001'  , 
										'text'=>'Operations',
										'description'=>'Department of production and value Addition' , 
										'backgroundColor'=>'#FFFFFF' , 
										'leaf'=>false ,
										'radius' => 20 , 
										'style'=>'dot'));
array_push($graph["nodelist"] , array(	'id'=>'1002'  , 
										'text'=>'Marketting',
										'description'=>'Department of Marketting and Sales' , 
										'backgroundColor'=>'#FFFFFF' , 
										'leaf'=>false ,
										'radius' => 20 , 
										'style'=>'dot'));
array_push($graph["nodelist"] , array(	'id'=>'1003'  , 
										'text'=>'HR',
										'description'=>'Human Resource department' , 
										'backgroundColor'=>'#FFFFFF' , 
										'leaf'=>false ,
										'radius' => 20 , 
										'style'=>'dot'));
array_push($graph["nodelist"] , array(	'id'=>'1005'  , 
										'text'=>'Executive Board',
										'description'=>'Chief exective board of the company' , 
										'backgroundColor'=>'#FFFFFF' , 
										'leaf'=>false ,
										'radius' => 20 , 
										'style'=>'dot'));
array_push($graph["nodelist"] , array(	'id'=>'1004'  , 
										'text'=>'ABC Internationals',
										'description'=>'' , 
										'backgroundColor'=>'#FFFFFF' , 
										'leaf'=>false ,
										'radius' => 40 , 
										'style'=>'dot'));

$graph["edgelist"] = array();
array_push($graph["edgelist"],array(	'id'=>'1', 
										'from'=>'1' , 
										'to'=>'2' , 
										'text'=>'' , 
										'description'=>'VPs report to president')
									);
array_push($graph["edgelist"],array(	'id'=>'2', 
										'from'=>'1' , 
										'to'=>'3' , 
										'text'=>'' , 
										'description'=>'VPs report to president')
									);
array_push($graph["edgelist"],array(	'id'=>'3', 
										'from'=>'1' , 
										'to'=>'4' , 
										'text'=>'' , 
										'description'=>'VPs report to president')
									);
array_push($graph["edgelist"],array(	'id'=>'4', 
										'from'=>'1' , 
										'to'=>'11' , 
										'text'=>'' , 
										'description'=>'Third party agent for legal advice')
									);
array_push($graph["edgelist"],array(	'id'=>'5', 
										'from'=>'3' , 
										'to'=>'5' , 
										'text'=>'' , 
										'description'=>'Managers report to Vice President')
									);
array_push($graph["edgelist"],array(	'id'=>'6', 
										'from'=>'3' , 
										'to'=>'6' , 
										'text'=>'' , 
										'description'=>'Managers report to Vice President')
									);
array_push($graph["edgelist"],array(	'id'=>'7', 
										'from'=>'3' , 
										'to'=>'7' , 
										'text'=>'' , 
										'description'=>'Managers report to Vice President')
									);
array_push($graph["edgelist"],array(	'id'=>'8', 
										'from'=>'4' , 
										'to'=>'8' , 
										'text'=>'' , 
										'description'=>'Managers report to Vice President')
									);
array_push($graph["edgelist"],array(	'id'=>'9', 
										'from'=>'2' , 
										'to'=>'9' , 
										'text'=>'' , 
										'description'=>'Head reports production status')
									);
array_push($graph["edgelist"],array(	'id'=>'10', 
										'from'=>'2' , 
										'to'=>'10' , 
										'text'=>'' , 
										'description'=>'Engineer reports technical details of producion')
									);
									
$graph["summary"] = array(
	'1004' => array(
		'1001' => array('2','9','10',),
		'1002' => array('4' , '8'),
		'1003' => array('3' , '5' , '6' , '7'),
		'1005' => array('1' , '11')
		)
	);
$graph["style"] = "arrow-end";

//echo $_POST["key"];
$data["graph"] = $graph;
//$data["graph"] = "";
$data["html"]  = "";
//$data["html"] = "";
//$data["timeline"] = json_decode('');

$data["timeline"] = array(
	'events'=> array(),
	'sections'=>array()
);

array_push($data["timeline"]["sections"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 2,
				"day"=> 1,
				"hour"=> 0
			),
			array(
				"year"=> 2014,
				"month"=> 2,
				"day"=> 26,
				"hour"=> 23
			)
		),
		"title"=>"Active Session#2",
		"section"=>0,
		"attrs"=>array(
			"fill"=>"#cccccc"
		)
	));
$data["html"] = $data["html"]."<button type=\"button\" class=\"btn btn-default\" onclick='timeline1.goToDate(new Date(\"01 Mar 2014\"));' class='btn btn-primary session_info'>Active Session #2</button>";

array_push($data["timeline"]["sections"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 1,
				"hour"=> 0
			),
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 16,
				"hour"=> 23
			)
		),
		"title"=>"Active Session#1",
		"section"=>1,
		"attrs"=>array(
			"fill"=>"#aaaaaa"
		)
	));
$data["html"] = $data["html"]."<button type=\"button\" class=\"btn btn-default\" onclick='timeline1.goToDate(new Date(\"01 Apr 2014\"));' class='btn btn-primary session_info'>Active Session #1</button>";
	
array_push($data["timeline"]["sections"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 27,
				"hour"=> 0
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 26,
				"hour"=> 23
			)
		),
		"title"=>"Active Session#3",
		"section"=>2,
		"attrs"=>array(
			"fill"=>"#dddddd"
		)
		
	));	
$data["html"] = $data["html"]."<button type=\"button\" class=\"btn btn-default\" onclick='timeline1.goToDate(new Date(\"27 Apr 2014\"));' class='btn btn-primary session_info'>Active Session #3</button>";
	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 2,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 3,
				"hour"=> 21
			)
		),
		"title"=>"Access of Vice President [Marketting] given to xyz.com",
		"section"=>1
	));
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 12,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 23,
				"hour"=> 21
			)
		),
		"title"=>"Access of Operations Head given to abc.com",
		"section"=>1
	));
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 22,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 22,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>1
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 2,
				"day"=> 22,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 2,
				"day"=> 22,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>0
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 22,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 22,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 12,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 12,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 26,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 23,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 3,
				"day"=> 23,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 5,
				"day"=> 23,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 23,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 24,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
array_push($data["timeline"]["events"] , array(
		"dates"=>array(
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 23,
				"hour"=> 5
			),
			array(
				"year"=> 2014,
				"month"=> 4,
				"day"=> 24,
				"hour"=> 21
			)
		),
		"title"=>"Access of Chief Engineer given to xyz.com",
		"section"=>2
	));	
//$data["timeline"] = "";

$data["html"] = "<div class='well'><div class=\"btn-group\">".$data["html"]."</div></div>";
echo json_encode($data);
?>