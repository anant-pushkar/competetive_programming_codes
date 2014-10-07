import testTemplate 
import random
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count=True)
	testcase = testTemplate.testInstance("0 0" , "0" , "smoke test1")
	suite.add(testcase)
	for i in xrange(10):
		x = random.randint(10000000,100000000)
		y = random.randint(10000000,100000000)
		testcase = testTemplate.testInstance(" ".join([str(x),str(y)]) , str(x*y) , "sample"+str(i))
		suite.add(testcase)
	tests.append(suite)
	
	return tests


