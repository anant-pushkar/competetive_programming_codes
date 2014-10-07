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
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count=True)
	testcase = testTemplate.testInstance("()(()" , "2" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("(((((((" , "0" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance(")" , "0" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("()" , "2" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("(()" , "2" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("()(())" , "6" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("(()()" , "4" , "sample7")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


