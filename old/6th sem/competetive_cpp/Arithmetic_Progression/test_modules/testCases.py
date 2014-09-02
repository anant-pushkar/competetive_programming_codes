import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.regexTester("3\n4 1 7" , "2\n-2 10" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance("1\n10" , "-1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.testInstance("4\n1 3 5 9" , "1\n7" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.testInstance("4\n4 3 4 5" , "0" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite5")
	testcase = testTemplate.testInstance("2\n2 4" , "3\n0 3 6" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1")
	testcase = testTemplate.testInstance("3\n1 3 4" , "1\n2" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite2")
	testcase = testTemplate.testInstance("2\n1 2" , "2\n0 3" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite3")
	testcase = testTemplate.testInstance("6\n1 2 4 5 6 7" , "1\n3" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite4")
	testcase = testTemplate.testInstance("6\n1 2 5 6 7 8" , "0" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


