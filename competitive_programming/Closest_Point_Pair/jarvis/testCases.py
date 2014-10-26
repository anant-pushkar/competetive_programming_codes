import testTemplate 
import random
import math
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def get_closest(pt):
	min_dist = 1000000
	for i in xrange(len(pt)):
		for j in xrange(i+1 , len(pt)):
			dist = float( (pt[i][0]-pt[j][0])*(pt[i][0]-pt[j][0]) + (pt[i][1]-pt[j][1])*(pt[i][1]-pt[j][1]) )
			dist = math.sqrt(dist)
			if min_dist>dist:
				x=i
				y=j;
				min_dist = dist
	return [x,y,min_dist]
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	n=random.randint(1,10000)
	pt = []
	for i in xrange(n):
		pt.append( [ random.randint(1,1000000) ,random.randint(1,1000000) ] );
	in_str = str(n) + "\n" + "\n".join([str(x[0]) + " " + str(x[1]) for x in pt])
	testcase = testTemplate.regexTester(in_str , " ".join([str(x) for x in get_closest(pt)]) , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


