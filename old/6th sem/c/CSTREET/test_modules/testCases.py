import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	testcase = testTemplate.testInstance("2\n5\n7\n1 2 1\n2 3 2\n2 4 6\n5 2 1\n5 1 3\n4 5 2\n3 4 3" , "12" , "sample input")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


