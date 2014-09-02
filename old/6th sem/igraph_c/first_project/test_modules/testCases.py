import testTemplate 
import networkx as nx
import numpy as np
Patches = 30   # Number of patches
P_ext = 0.05    # Probability of extinction (e)
P_col = 0.14   # Probability of colonization (c)
P_init = 0.02   # Probability that a patch will be occupied at the beginning
Distance = 3  # An arbitrary parameter to determine which patches are connected
class patch:
	def __init__(self,status=0,pos=(0,0),idx=0):
		self.status = status
		self.pos = pos
		self.index=idx
	def __str__(self):
		return(str(self.status))
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	G = nx.Graph()
	for i in xrange(Patches):
		Stat = 1 if np.random.uniform() < P_init else 0
		Pos  = (np.random.uniform()*10-5,np.random.uniform()*10-5)
		G.add_node(patch(Stat,Pos,i))
	edgelist=""
	for p1 in G.nodes():
		for p2 in G.nodes():
			Dist = np.sqrt((p1.pos[1]-p2.pos[1])**2+(p1.pos[0]-p2.pos[0])**2)
			if Dist <= Distance:
				G.add_edge(p1,p2)
				edgelist+=str(p1.index)+" "+str(p2.index)+"\n"
	
	suite=testTemplate.testSuite("Smoke Test Suite 1")
	testcase = testTemplate.regexTester(str(G.number_of_nodes())+" "+str(G.number_of_edges())+"\n"+edgelist , "" , "graph creation")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


