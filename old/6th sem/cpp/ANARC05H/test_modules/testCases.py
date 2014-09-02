import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite")
	testcase = testTemplate.testInstance("635" , "1. 2" , "sample #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1117" , "2. 7" , "sample #2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("9876" , "3. 2" , "sample #3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite")
	testcase = testTemplate.testInstance("00" , "1. 2" , "test #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("000" , "2. 4" , "test #2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


