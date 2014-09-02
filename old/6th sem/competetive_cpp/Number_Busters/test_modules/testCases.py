import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	#testcase = testTemplate.testInstance("input" , "output" , "testname")
	#suite.add(testcase)
	tests.append(suite)
	
	return tests


