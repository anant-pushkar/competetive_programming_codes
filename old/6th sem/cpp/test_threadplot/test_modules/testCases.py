import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	testcase = testTemplate.testInstance("1" , "2" , "#1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1" , "2" , "#2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


