import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("6\n4 1 7 8 3 8\n1" , "3" , "sample test case")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1")
	testcase = testTemplate.testInstance("6\n4 1 7 8 3 8\n2" , "3" , "Custom test case")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite2")
	testcase = testTemplate.testInstance("6\n4 1 7 8 3 8\n4" , "4" , "Custom test case")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite3")
	testcase = testTemplate.testInstance("6\n4 1 9 17 25 33\n4" , "2" , "Custom test case")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


