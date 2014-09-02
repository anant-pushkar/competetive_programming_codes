import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Custom test Suite")
	testcase = testTemplate.testInstance("1" , "1" , "#1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2" , "1" , "#2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3" , "2" , "#3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("4" , "1" , "#4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("8" , "1" , "#5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("7" , "3" , "#6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("15" , "4" , "#7")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


