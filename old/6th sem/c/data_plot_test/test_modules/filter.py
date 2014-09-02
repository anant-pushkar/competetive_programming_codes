import sys
import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import json
from threading import Thread

def draw_graph(graph,is_directed, labels=None, graph_layout='shell',
               node_size=300, node_color='blue', node_alpha=0.3,
               node_text_size=12,
               edge_color='red', edge_alpha=0.3, edge_tickness=1,
               edge_text_pos=0.3,
               text_font='sans-serif'):

    # create networkx graph
    G=nx.Graph()

    # add edges
    for edge in graph:
        G.add_edge(edge[0], edge[1])

    # these are different layouts for the network you may try
    # shell seems to work best
    if graph_layout == 'spring':
        graph_pos=nx.spring_layout(G)
    elif graph_layout == 'spectral':
        graph_pos=nx.spectral_layout(G)
    elif graph_layout == 'random':
        graph_pos=nx.random_layout(G)
    else:
        graph_pos=nx.shell_layout(G)

    # draw graph
    nx.draw_networkx_nodes(G,graph_pos,node_size=node_size, 
                           alpha=node_alpha, node_color=node_color)
    nx.draw_networkx_edges(G,graph_pos,width=edge_tickness,
                           alpha=edge_alpha,edge_color=edge_color)
    nx.draw_networkx_labels(G, graph_pos,font_size=node_text_size,
                            font_family=text_font)

    if labels is None:
        labels = range(len(graph))

    edge_labels = dict(zip(graph, labels))
    nx.draw_networkx_edge_labels(G, graph_pos, edge_labels=edge_labels, 
                                 label_pos=edge_text_pos)

    # show graph
    plt.show()

def data_plot(arr,n):
	xs = np.arange(len(arr))
	series1 = np.array(arr).astype(np.double)
	s1mask = np.isfinite(series1)

	plt.plot(xs[s1mask], series1[s1mask], linestyle='-', marker='o')

	plt.show()

def filter_input(line):
	line=line.replace("^","")
	j=json.loads(line)
	graph=[]
	labels=[]
	if j["type"]=="graph" or j["type"]=="digraph":
		for i in range(len(j["obj"])):
			graph.append((j["obj"][i][0],j["obj"][i][1]))
			labels.append(str(j["obj"][i][2]))
		try:
			Thread(target=draw_graph, args=(graph, j["type"]=="digraph", labels)).start()
		except:
		   print line.replace('\n','')
	if j["type"]=="data":
		arr=[]
		for i in range(len(j["obj"])):
			arr.append(float(j["obj"][i]))
		try:
			Thread(target=data_plot, args=(arr,1)).start()
		except:
		   print line.replace('\n','')
		   
for line in sys.stdin:
	if line[0] == '^':
		filter_input(line)
	else:
		print line.replace('\n','')

	

