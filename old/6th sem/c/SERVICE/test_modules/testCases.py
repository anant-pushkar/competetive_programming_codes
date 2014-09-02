import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("5 9\n0 1 1 1 1\n1 0 2 3 2\n1 1 0 4 1\n2 1 5 0 1\n4 2 3 4 0\n4 2 4 1 5 4 3 2 1" , "5" , "Sample 1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite")
	testcase = testTemplate.testInstance("5 9\n0 1 1 1 1\n1 0 2 3 2\n1 1 0 4 1\n2 1 5 0 1\n4 2 3 4 0\n1 1 1 1 1 1 1 1 1" , "0" , "test case 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("5 9\n0 1 1 1 1\n1 0 2 3 2\n1 1 0 4 1\n2 1 5 0 1\n4 2 3 4 0\n1 1 2 3 1 2 3 1 2" , "0" , "test case 2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("5 9\n0 1 1 1 1\n1 0 2 3 2\n1 1 0 4 1\n2 1 5 0 1\n4 2 3 4 0\n1 1 1 4 1 1 1 1 1" , "2" , "test case 3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("5 9\n0 1 1 1 1\n1 0 2 1 2\n1 1 0 4 1\n2 1 5 0 1\n4 2 3 4 0\n1 1 1 4 1 1 1 1 1" , "1" , "test case 4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


