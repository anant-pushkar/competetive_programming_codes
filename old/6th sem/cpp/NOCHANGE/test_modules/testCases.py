import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample test Suite")
	testcase = testTemplate.testInstance("13 3 9 2 1" , "NO" , "Sample #1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


