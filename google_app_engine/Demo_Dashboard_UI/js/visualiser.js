/*
 * Class For summary information
 */
function Summary(arr,p){
	var children = arr;
	var parent   = p;
	this.getChildren = function(){
		return children;
	}
	this.getParent = function(){
		return parent;
	}
}
/*
 * Container class for summary information
 */
function Summariser(s){
	var list={};
	//=====================================================================
	/*
	 * Recursive function to extract parent child relationship from summary array
	 * 
	 */
	function summarise(sum,p){
		var siblings = [];
		for(key in sum){
			siblings.push(key);
			if(sum[key].constructor == Array){// if node is non-leaf
				list[key] = new Summary(sum[key],p);
				for(var i=0;i<sum[key].length;++i)list[sum[key][i]] = new Summary(undefined,key);
			}else{// if node is a leaf node
				list[key] = new Summary(summarise(sum[key],key) , p);
			}
		}
		return siblings;
	}
	summarise(s);
	//=======================================================================
	/*
	 * return summary list
	 * 
	 */
	this.getList = function(){
		return list;
	}
}
/*
 * Generic class for entity(both node and edge)
 */
function Entity(id){
	var id = id;
	var propertylist = {};
	this.getID = function(){
		return id;
	};
	//==================================================
	/*
	 * set value(val) to the property(key)
	 * 
	 */
	this.setProperty = function(key,val){
		propertylist[key] = val;
	};
	//==================================================
	this.getProperty = function(key){
		return propertylist[key];
	};
}
/*
 * Container class for list of entities
 */
function EntityList(){
	var list=[];
	this.propertylist = [];// general properties not necessarily applicable to all entities
	this.visible=[];
	//=======================================================================================
	/*
	 * get all entities in the list
	 * 
	 */
	this.getAll = function(){
		return list;
	};
	//=========================================================================================
	/*
	 * Add new Entity(entity) with visibility(visible)
	 * 
	 */
	this.add = function(entity,visible){//Add new
		for(var i=0;i<list.length;++i){
			if(list[i].getID() == entity.getID())throw("ID #"+entity.getID()+" already exists");
		}
		list.push(entity);
		this.visible.push(visible==undefined?true:visible);
		return true;
	};
	//==========================================================================================
	/*
	 * Toggle visibility of entity with given id
	 * 
	 */
	this.toggleVisibility = function(id){
		for(var i=0;i<list.length;++i){
			if(list[i].getID() == id)this.visible[i] = this.visible[i]==true? false : true ;
		}
	}
	//==========================================================================================
	/*
	 * Get visibility of entity with geiven id
	 * 
	 */
	this.getVisibility = function(id){
		for(var i=0;i<list.length;++i){
			if(list[i].getID() == id)return this.visible[i] ;
		}
	}
	//==========================================================================================
	/*
	 * Add new properties to the property list of the container class
	 * Input: array containing property names
	 * 
	 */
	this.addProperties = function(arr){
		for(var i=0;i<arr.length;++i){
			this.propertylist.push(arr[i]);
		}
	}
	//==========================================================================================
	/*
	 * Set the value for given property(key) to val in all the entities in the list
	 * 
	 */
	this.setAll = function(key,val){
		if(!propertylist.contains(key))throw("Property : "+key+" not defined");
		for(var i=0;i<list.length;++i){
			list[i].setProperty(key,val);
		}
		return true;
	}
	//==========================================================================================
	/*
	 * Set the value of property(key) to val in entity with given id
	 * 
	 */
	this.set = function(id,key,val){
		for(var i=0;i<list.length;++i){
			if(list[i].getID() == id ){
				list[i].setProperty(key,val);
				return true;
			}
		}
		throw("Key not found");
	}
	//==========================================================================================
	/*
	 * Get entity with given id
	 * 
	 */
	this.getEntity = function(id){
		for(var i=0;i<list.length;++i){
			if(list[i].getID() == id ){
				return list[i];
			}
		}
	}
	//==========================================================================================
	/*
	 * Get entity by index in the list
	 * 
	 */
	this.getEntityByIndex = function(i){
		return list[i];
	}
}
/*
 * Container class for Nodes
 * 
 */
function NodeList(){
	this.list = new EntityList();
	var radii     = {};				// Radius value for specific nodes
	var defaultRadius = 10;			// Default radius for those without a specified value
	var outList = {};				// Outward Adjecency list (contains from and to values for the edges)
	var inList  = {};				// Inward Adjecency list (contains from and to values for the edges)
	//==========================================================================================
	/*
	 * Get radius of entity with the given id
	 * 
	 */
	var getRadius = function(id){
		if(radii[id]==undefined)return defaultRadius;
		else return radii[id];
	}
	//==========================================================================================
	/*
	 * add the given edge to the corresponding outList and inList for the mentioned node
	 * 
	 */
	this.addEdge = function(edge){
		if(outList.hasOwnProperty(edge.getProperty("from")))outList[edge.getProperty("from")].push(edge.getID());
		else outList[edge.getProperty("from")] = [edge.getID()];
		
		if(inList.hasOwnProperty(edge.getProperty("to")))inList[edge.getProperty("to")].push(edge.getID());
		else inList[edge.getProperty("to")] = [edge.getID()];
	}
	//==========================================================================================
	/*
	 * get outward adjecency list
	 * 
	 */
	this.getOutList = function(id){
		return outList[id];
	}
	//==========================================================================================
	/*
	 * Get inward adjecency list
	 * 
	 */
	this.getInList = function(id){
		return inList[id];
	}
	//==========================================================================================
	/*
	 * Get radius of node with given id
	 * 
	 */
	this.setRadius= function(r , id){
		if(r<=0)throw("Invalid radius");
		if(id==undefined){			// if no radius defined, return default radius
			defaultRadius = r;
		}else{						// else return the specified radius
			radii[id] = r;
		}
	}
	//==========================================================================================
	/*
	 * Get table to be passed to draw the graph
	 * 
	 */
	this.getTable = function(){
		var table = new google.visualization.DataTable() , plist , p;
		var l = new Summariser(summary).getList();
		// Create column names for nodes
		table.addColumn('number', 'id');
		table.addColumn('number', 'radius');
		for(var i=0;i<this.list.propertylist.length;++i){
			p = this.list.propertylist[i];
			table.addColumn(p!='x' && p!='y' ? 'string' : 'number', p);
		}
		var arr = this.list.getAll() , x;
		
		// Add values for every node corresponding to the column
		for(var i=0;i<arr.length;++i){
			if(arr[i].getProperty("leaf")){
				x = arr[i];
				plist = [parseInt(x.getID()) , x.getProperty("radius")];
				for(var j=0;j<this.list.propertylist.length;++j){
					p = this.list.propertylist[j];
					plist.push(x.getProperty(p));
				}
				table.addRow(plist);
			}else this.list.toggleVisibility(arr[i].getID());
		}
		return table;
	}
}
/*
 * Container class for Edges
 * 
 */
function EdgeList(){
	this.list = new EntityList();
	var width     = {};					// Width value for specific Edges
	var defaultWidth = 1;				// Default width for Edges with no width specified
	var memory = {};					// Memory for past from and to information of edges for consistent expand and contract operations on nodes
	//==========================================================================================
	/*
	 * Get width of edge with the given id
	 * Private method
	 */
	var getWidth = function(id){
		if(width[id]==undefined)return defaultWidth;
		else return width[id];
	}
	//==========================================================================================
	/*
	 * Set width of the edge with given id to value(w)
	 * 
	 */
	this.setWidth= function(w , id){
		if(w<=0)throw("Invalid radius");
		if(id==undefined){// if id is not defined, use w as default value
			defaultWidth = w;
		}else{
			width[id] = w;
		}
	}
	//==========================================================================================
	/*
	 * Remember the value(val) for the given property of the edge with given id
	 * 
	 */
	this.remember = function(id,property,val){
		if(memory[id]==undefined)memory[id]={};							// Create entry if does not exist
		if(memory[id][property]==undefined)memory[id][property] = [];		// Create property entry if does not exist
		memory[id][property].push(val);
	}
	//==========================================================================================
	/*
	 * Forget the value(val) for the given property of the edge with given id
	 * 
	 */
	this.forget = function(id,property,val){
		if(memory[id]==undefined)throw("ID:"+id+" not in memory");
		if(memory[id][property]==undefined)throw("Property:"+property+" not in memory");
		memory[id][property].splice( memory[id][property].indexOf( val ), 1 );
	}
	//==========================================================================================
	/*
	 * Recall the history of the edge with given id
	 * 
	 */
	this.recall = function(id){
		if(memory[id]==undefined)throw("ID:"+id+" not in memory");
		return memory[id];
	}
	//==========================================================================================
	/*
	 * Get the whole memory
	 * Useful only for debugging purposes
	 * 
	 */
	this.getMemory = function(){
		return memory;
	}
	//==========================================================================================
	/*
	 * Get table to be passed to draw the graph
	 * 
	 */
	this.getTable = function(){
		var table = new google.visualization.DataTable() , plist , p;
		// Create column names for edges
		table.addColumn('number', 'id');
		table.addColumn('number', 'width');
		for(var i=0;i<this.list.propertylist.length;++i){
			p = this.list.propertylist[i];
			table.addColumn('string', p);
		}
		var arr = this.list.getAll() , x;
		
		// Add Values for properties of the edges
		for(var i=0;i<arr.length;++i){
			x = arr[i];
			plist = [parseInt(x.getID()) , getWidth(x.getID())];
			for(var j=0;j<this.list.propertylist.length;++j){
				p = this.list.propertylist[j];
				plist.push(x.getProperty(p));
			}
			table.addRow(plist);
		}
		return table;
	}
}
//==========================================================================================
/*
 * Visualiser Class
 * This is the interface used in the final html to access the above classes
 * 
 */
function Visualiser(div,ls){
	var linkstyle = ls==undefined ? "line" : ls;	// link style, default value line
	var network   = new links.Network(div);		// component of underlying UI component
	var nodelist  = new NodeList();				// Instance of NodeList class
	var edgelist  = new EdgeList();				// Instance of EdgeList class
	var summariser= new Summariser(summary);		// Instance of Summariser class
	var descriptionID ;								// ID of div where the description of all the entities will be displayed
	//==========================================================================================
	/*
	 * Get the underlying UI component
	 * Useful for debugging purposes
	 * 
	 */
	this.getNetwork = function(){
		return network;
	}
	//==========================================================================================
	/*
	 * Add node to the Nodelist
	 * Uncomment the try-catch clause to display errors in the UI
	 */
	this.addNode  = function(node){
		//try{
			nodelist.list.add(node);
		//}catch(err){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not add node : "+err;
		//}
	};
	//==========================================================================================
	/*
	 * Add edge to the Edge list
	 * Uncomment the try-catch clause to display errors in the UI
	 */
	this.addEdge  = function(edge){
		//try{
			edgelist.list.add(edge);
			nodelist.addEdge(edge);
		//}catch(err){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not add Edge : "+err;
		//}
	};
	//==========================================================================================
	/*
	 * Add a Node property to the underlying nodelist
	 * Uncomment the try-catch clause to display errors in the UI
	 */
	this.addNodeProperties = function(arr){
		//try{
			nodelist.list.addProperties(arr);
		//}catch(e){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not add Node Properties : "+e;
		//}
	}
	//==========================================================================================
	/*
	 * Add an Edge property to the underlying edgelist
	 * Uncomment the try-catch clause to display errors in the UI
	 */
	this.addEdgeProperties = function(arr){
		//try{
			edgelist.list.addProperties(arr);
		//}catch(e){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not add Edge Properties : "+e;
		//}
	}
	//==========================================================================================
	/*
	 * Set Node property(key) of the Node with given id to the given value 
	 * Uncomment the try-catch clause to display errors in the UI
	 * 
	 */
	this.setNodeProperty = function(key,value,id){
		//try{
			if(id==undefined)nodelist.list.setAll(key,val);
			else nodelist.list.set(id,key,val);
		//}catch(err){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not set node property : "+err;
		//}
	}
	//==========================================================================================
	/*
	 * Set radius of Node with given id to value(r)
	 * 
	 */
	this.setRadius = function(r,id){
		nodelist.setRadius(r,id);
	}
	//==========================================================================================
	/*
	 * Set property(key) of the Edge with given id to the given value
	 * Uncomment the try-catch clause to display errors in the UI
	 * 
	 */
	this.setEdgeProperty = function(key,value,id){
		//try{
			if(id==undefined)edgelist.list.setAll(key,val);
			else edgelist.list.set(id,key,val);
		//}catch(err){
		//	var container = document.getElementById(descriptionID);
		//	container.innerHTML="Could not set node property : "+err;
		//}
	}
	//==========================================================================================
	/*
	 * Set the discription ID the the given id
	 * 
	 */
	this.setDescriptionID = function(id){
		descriptionID = id;
	}
	//==========================================================================================
	/*
	 * Draw the graph
	 * 
	 */
	this.draw = function(){
		var nodesTable = nodelist.getTable();		// Extract Node Table
		var linksTable = edgelist.getTable();		// Extract Edge Table
		//Set Default options
		var options = {
			stabilize: false, 		// Set to true if you need to graph to be stabilized jsut after being rendered, effective only if close is not called at the end of draw() function
			links:{	// default link properties
					style    : linkstyle	// set link style
				}
		};
		// Draw the the graph
		network.draw(nodesTable, linksTable, options);
		
		//========================================Create Anchor Node==================================================
		nodesTable = [];
		nodesTable.push({
			'id': 0,
			'backgroundColor':'#B84DFF',
			'x':250,
			'y':150,
			'style':'dot',
			'radius':0,		// radius set to 0 to make it invisible
			'action': "create",
			'text':""
		});
		network.addNodes(nodesTable);	//Draw the Anchor Node
		var n = new Entity('0');
		n.setProperty("text","");
		nodelist.list.add(n);// Add anchor Node to nodelist
		
		//==========================================Create Edge from anchor Node to the graph================================================
		var linkID = edgelist.list.getAll().length+1;
		linksTable = [];
		linksTable.push({
			'id'  : linkID,
			'from': 0,
			'to': 1,
			'color' : '#ffffff',	// Color set to white to make it invisible
			'action': "create"
		});
		network.addLinks(linksTable);		// Draw the Edge
		var e = new Entity(linkID.toString());
		e.setProperty("from",'0');
		e.setProperty("to",'1');
		edgelist.list.add(e);// Add edge to edgelist
		
		//=====================================================================================================
		close(this);	// Comment this function call to disable the default summarisation in the beginning
		//=====================================================================================================
		google.visualization.events.addListener(network, 'select', this.onselect);// Add event listener
	}
	//==========================================================================================
	/*
	 * Summarise the node with given index
	 * 
	 */
	this.summarise = function(index){
		var id  = network.nodes[index].id;	// Extract ID of the node with given index from underlying UI component
		
		//=======================Extract summary information of the node=========================================
		var l   = summariser.getList();	
		var pSum= l[l[id].getParent()];
		if(pSum==undefined)throw("No further summarization possible");// Throw Error if no summarisation needed
		//=======================================================================================================
		
		//===========================Get children of the given node and check if all are Active=================
		var arr = pSum.getChildren();
		var check = 0;
		for(var i=0;i<arr.length;++i){
			for(var j=0;j<network.nodes.length;++j)
				if(network.nodes[j].id == arr[i])
					++check;
		}
		//=======================================================================================================
		
		//=================================All Children Active===================================================
		if(check==arr.length){
			//------------------Extract Parent Entity-------------------
			var p  = l[id].getParent();
			var n = nodelist.list.getEntity(p);
			var nodesTable = [];
			//----------------Extract Parent Properties needed to draw--------------
			var details = {
				'id': parseInt(p),
				'text' : n.getProperty("text"),
				'backgroundColor':n.getProperty("backgroundColor"),
				'style':n.getProperty("style"),
				'radius' : n.getProperty("radius"),
				'action': "create"
			}
			if(typelist!=undefined)details['y'] = n.getProperty('y');
			nodesTable.push(details);
			//-----------------Draw Parent---------------------------------------
			network.addNodes(nodesTable);
			//----------------Delete Sibling Nodes-------------------------------
			for(var i=0;i<arr.length;++i){
				deleteNode(arr[i],l[arr[i]].getParent());
			}
			//---------------Toggle visibility of parent------------------------
			nodelist.list.toggleVisibility(p);
		}else throw "Unsummarised siblings";// Throw error if some child unActive, summarisation not possible
	}
	/*
	 * Delete Node with given id and given parent
	 * 
	 */
	var deleteNode = function(id,parent){
		var nodesTable = [];
		//----------------Create delete table-------------------------------
		nodesTable.push({
			'id': parseInt(id),
			'action': "delete"
		});
		nodelist.list.toggleVisibility(id);	// Toggle visibility
		var linksTable = [];					// Update table for Edges
		var edges = edgelist.list.getAll(),from,to,tempid;
		for(var i=0;i<edges.length;++i){
			tempid = edges[i].getID();
			
			//----------Get current Edge properties-------------------------
			from = edgelist.list.getEntity(tempid).getProperty("from");
			to   = edgelist.list.getEntity(tempid).getProperty("to");
			
			if(from==id || to==id){// If Edge connected to deleted Node
				//----------remember Edge History---------------------
				edgelist.remember(tempid,"from",from);
				edgelist.remember(tempid,"to",to);
				
				//---------Update property value --------------------
				from = from == id ? parent : from;
				to   = to == id ? parent : to;
				edgelist.list.getEntity(tempid).setProperty("from",from);
				edgelist.list.getEntity(tempid).setProperty("to",to);
				
				//-----------------Add Entry to update table---------
				linksTable.push({
					'id': parseInt(tempid),
					'from': parseInt(from),
					'to'  : parseInt(to),
					'action': "update"
				});
			}
		}
		//-----------Commit changes to underlying UI component---------------
		network.addLinks(linksTable);
		network.addNodes(nodesTable);
	}
	
	/*
	 * Expand the Node with given index
	 * 
	 */
	this.expand = function(index){
		var id  = network.nodes[index].id;		// Extract ID of Node
		
		//=======================Extract summary information of the node=========================================
		var l   = summariser.getList();		
		var arr= l[id].getChildren();
		if(arr==undefined)throw("No further Expansion possible");// Throw Error if no summarisation needed
		//=======================================================================================================
		
		//=========================Insert Edges of Children ===============================================
		for(var i=arr.length-1;i>=0;--i){
			insertNodeEdges(arr[i],id,l[arr[i]].getChildren());
		}
		//=================================================================================================
		
		//=====================Update Edge Information==========================================
		var linksTable = [];// Update Table for Edges
		var edges = edgelist.list.getAll(),from,to,tempid,mem_index,mem;
		var t,f;
		for(var i=0;i<edges.length;++i){
			tempid = edges[i].getID();
			//------------------------Extract Current Properties-----------------------------
			from = edgelist.list.getEntity(tempid).getProperty("from");
			to   = edgelist.list.getEntity(tempid).getProperty("to");
			
			
			if(from==id || to==id){// If Edge connected to deleted Node
				//---------Remember Selective Edge History------------------------
				mem=edgelist.recall(tempid);
				for(var j=0;j<arr.length;++j){
					for(var k=0;k<mem["from"].length;++k){
						if(    (mem["from"][k]==arr[j] )
							|| (mem["to"][k]==arr[j] )   ){
							from = mem["from"][k]==arr[j] ? arr[j] : from;
							to   = mem["to"][k]==arr[j] ? arr[j] : to;
							break;
						}
					}
					if(from!=id && to!=id)break;
				}
				//-------Update Edge properties-----------------------------
				edgelist.list.getEntity(tempid).setProperty("from",from);
				edgelist.list.getEntity(tempid).setProperty("to",to);
				//-----------Push to update Table---------------------------
				linksTable.push({
					'id': parseInt(tempid),
					'from': parseInt(from),
					'to'  : parseInt(to),
					'action': "update"
				});
			}
		}
		network.addLinks(linksTable);// Commit Edge Updates to underlying UI Component
		
		//====================Delete Summary Node==================================
		var nodesTable = [];
		nodesTable.push({
			'id': parseInt(id),
			'action': "delete"
		});
		network.addNodes(nodesTable);
		nodelist.list.toggleVisibility(id);
	}
	/*
	 * On select Event Listner
	 * 
	 */
	this.onselect = function(){
		var sel = network.getSelection();		// Extract Selection Information from underlying UI Component
		var index , node , id;
		var l   = summariser.getList();		// Extract Summary Information
		
		//----------------Start Creating html Information-----------------------------
		var info = "<div class='panel panel-default'><div class='panel-body'>";
		var inList,outList;
		info += sel.length.toString() + 'node(s) selected<br>';
		
		/*
		 * NOTE: Information display for multiselect can be enabled by changing the for loop [change 1 to sel.length]
		 * However, the behaviour for multi select has bugs, and it is possible that not all information gets displayed
		 * 
		 */
		for (var i = 0; i < 1; i++) {// For the ith Node selected
			index = parseInt(sel[i].row);				// Extract index of Node
			id    = v.getNetwork().nodes[index].id;	// Extract id of Node
			inList  = nodelist.getInList(id) ;			// Extract inward Adjecency List
			outList = nodelist.getOutList(id);			// Extract outward Adjecency List
			
			//-------------Create Information HTML for outward Edges------------------------------------------
			if(outList!=undefined){
				info += "<div style='padding:10px;'>Subordinate relations:<br>";
				for(var i=0;i<outList.length;++i){
					info += "<div style='background-color:"+ edgelist.list.getEntity(outList[i]).getProperty("color") ;
					info += "'>" +edgelist.list.getEntity(outList[i]).getProperty("text") +" ";
					info += edgelist.list.getEntity(outList[i]).getProperty("desc") + "</div>";
				}
				info += "</div>";
			}
			
			//-------------Create Information HTML for inward Edges---------------------------------------------
			if(inList!=undefined){
				info += "<div style='padding:10px;'>Supervision relations:<br>";
				for(var i=0;i<inList.length;++i){
					info += "<div style='background-color:"+ edgelist.list.getEntity(inList[i]).getProperty("color") +"'>" ;
					info += edgelist.list.getEntity(inList[i]).getProperty("text") + " ";
					info += edgelist.list.getEntity(inList[i]).getProperty("desc") + "</div>";
				}
				info += "</div>";
			}
			
			//----------Create Information HTML for Node-------------------------------------------------------
			node  = nodelist.list.getEntity(id);
			info += "<div class='well'><b>"+ node.getProperty("text") + "</b><br>";
			info += "<div style='padding:5px;'>" + node.getProperty("desc") + "</div></div>";
			//------------Expand if No-Leaf Node------------------------------
			if(l[id].getChildren()!=undefined){
				this.expand(index);
			}
		}
		
		//-------------Close div tags in HTML text--------------------------------------------------------------
		info += "</div></div>";
		
		//----------------Display HTML text on the UI-----------------------------------------------------------
		var container = document.getElementById(descriptionID);
		container.innerHTML=info;
		container.style.visibility = "visible";
	}
	/*
	 * Insert Edges of Nodes with the given id
	 * 
	 */
	var insertNodeEdges = function(id,parent,child){
		//===============Create Node Table to create new Nodes=========================
		var nodesTable = [];
		var n = nodelist.list.getEntity(id);
		//-------Extract Node information--------------------
		var details = {
			'id': parseInt(id),
			'text':n.getProperty("text"),
			'backgroundColor':n.getProperty("backgroundColor"),
			'style':n.getProperty("style"),
			'radius' : n.getProperty("radius"),
			'action': "create"
		}
		if(typelist!=undefined)details['y'] = n.getProperty('y');
		nodesTable.push(details);
		network.addNodes(nodesTable);			// Draw Node
		nodelist.list.toggleVisibility(id);	// Toggle Node Visibility
		
		//=========Create Update Table for Nodes=========================================
		var linksTable = [];
		//---------------Get memory--------------------
		var edges = edgelist.getMemory(),old_from,old_to;
		for(var tempid in edges)for(var i=0;i<edges[tempid]["from"].length;++i){
			//--------Extract Old Information---------------------
			old_from = edges[tempid]["from"][i];	
			old_to   = edges[tempid]["to"][i];
			if(old_from==undefined || old_to==undefined){
				continue;
			}
			//---------If Old information matches the Node ID----------------------------
			if((old_from==id || old_to==id) && nodelist.list.getVisibility(old_to) && nodelist.list.getVisibility(old_from)){
				edgelist.list.getEntity(tempid).setProperty("from",old_from);
				edgelist.list.getEntity(tempid).setProperty("to",old_to);
				linksTable.push({
					'id': parseInt(tempid),
					'from': parseInt(old_from),
					'to'  : parseInt(old_to),
					'action': "update"
				});
			}
		}
		network.addLinks(linksTable);// Update Edge
	}
	
	/*
	 * Summarise all Nodes
	 * 
	 */
	var close = function(self){
		var check=true;
		while(check){// End loop if no new node summarised
			check=false;
			for(var j=0;j<network.nodes.length;++j){
				if(network.nodes[j].id!=0 && nodelist.list.getVisibility(network.nodes[j].id)){// Can the node be summarised?
					var id=network.nodes[j].id;
					try{
						self.summarise(j);	// Simmarise given node
						check=true;			// continue looping if Some node was summarised
					}catch(err){
					}
				}
			}
		}
	}
}
