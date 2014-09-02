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
	
	$string = file_get_contents("internal_hierarchy.json");
	$json=json_decode($string,true);
	
	$string = file_get_contents("http://datastore-sit.appspot.com/get?key=cao_bucketlist" , false , $context);
	$bucketlist = json_decode($string,true);
	
	$string = file_get_contents("http://datastore-sit.appspot.com/get?key=cao_log" , false , $context);
	$log = json_decode($string,true);
?>

<!DOCTYPE HTML PUBLIC 
    "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <title>Domain Dashboard</title>
  
    <script type="text/javascript" src="jsapi"></script>
    <script type="text/javascript" src="network.js"></script>
    
    <script type="text/javascript">
      google.load("visualization", "1");
      
      // Set callback to run when API is loaded
      google.setOnLoadCallback(drawVisualization); 

      // Called when the Visualization API is loaded.
      function drawVisualization() {
        // Create a datatable for the nodes.
        var nodesTable = new google.visualization.DataTable();
        nodesTable.addColumn('string', 'id');
        nodesTable.addColumn('string', 'text');
        nodesTable.addColumn('string', 'style');  // optional
        <?php foreach ( $json["nodelist"] as $node) {?>
			nodesTable.addRow(["<?php echo $node["code"]; ?>", "<?php echo $node["name"]; ?>", undefined]);
		<?php } ?>

        // create a datatable for the links between the nodes
        var linksTable = new google.visualization.DataTable();
        linksTable.addColumn('string', 'from');
        linksTable.addColumn('string', 'to');
        linksTable.addColumn('number', 'width');  // optional
        <?php foreach ( $json["edgelist"] as $edge) {?>
			linksTable.addRow(["<?php echo $edge[0]; ?>", "<?php echo $edge[1]; ?>", undefined]);
		<?php } ?>
        // specify options
        var options = {
          width:  "400px", 
          height: "500px",
          stabilize: false, // do not stabilize before displaying
		  links:{
			  style:"arrow"
		  }
        };

        // Instantiate our network object.
        var network = new links.Network(document.getElementById('mynetwork'));

        // Draw our network with the created data and options 
        network.draw(nodesTable, linksTable, options);
      }
   </script>
   <style>
	.container{
		padding:10px;
		margin :10px;
		float:left;
	}
	.box{
		padding:10px;
		background-color: #f5f5f5;
		border: 1px solid #e3e3e3;
		border-radius: 4px;
	}
	.success{
		padding:10px;
		background-color: #80FF80;
		border: 1px solid #e3e3e3;
	}
	.failure{
		padding:10px;
		background-color: #FF9980;
		border: 1px solid #e3e3e3;
	}	
	.end{
		padding:10px;
		background-color: 	#CCCCB2;
		border: 1px solid #e3e3e3;
	}	
   </style>
  </head>

  <body>
  
	<div>
		<div class="container box">
			<h2> Internal Hierarchy </h2>
			<div id="mynetwork"></div>
		</div>
		<div class="container">
			<div class="box">
				<h2>Bucket List</h2>
				<?php
				
					foreach($bucketlist["bucket"] as $role){
						foreach ( $json["nodelist"] as $node) {
							if($node["code"] == $role){
								print($node["name"]."<br>");
							}
						}
					}
				
				?>
			</div>
			<div class="box">
				<h2> Log </h2>
				<?php foreach($log["list"] as $entry) {?>
					<div class="<?php echo $entry["status"]; ?>">
						<b><?php echo $entry["time"]; ?> : </b>
						<?php echo $entry["msg"]; ?>
					</div>
				<?php } ?>
				
				
			</div>
		</div>
	<div>
	
  
	
	
  </body>
</html>
