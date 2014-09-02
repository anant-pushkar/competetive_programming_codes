import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Smoke test suite")
	testcase = testTemplate.testInstance("1" , "3" , "test case 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2" , "4" , "test case 2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("52" , "54" , "test case 3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary test suite")
	testcase = testTemplate.testInstance("11111111" , "11111113" , "test case 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("88888882" , "88888884" , "test case 2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("999999952" , "999999954" , "test case 3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


