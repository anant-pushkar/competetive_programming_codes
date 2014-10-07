import testTemplate 
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.testInstance("12 " + " ".join([str(x) for x in [0,1,0,2,1,0,1,3,2,1,2,1]]) , "6" , "smoke test case 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3 " + " ".join([str(x) for x in [2,0,2]]) , "2" , "sample test case 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3 " + " ".join([str(x) for x in [4,2,3]]) , "1" , "sample test case 2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("4 " + " ".join([str(x) for x in [2,1,0,2]]) , "3" , "sample test case 3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


