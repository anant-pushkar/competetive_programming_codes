import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	#for i in range(50,300):
	testcase = testTemplate.testInstance("50 0.04" , "" , "graph ")
	suite.add(testcase)
	testcase = testTemplate.testInstance("50 0.045" , "" , "graph ")
	suite.add(testcase)
	testcase = testTemplate.testInstance("50 0.05" , "" , "graph ")
	suite.add(testcase)
	testcase = testTemplate.testInstance("50 0.055" , "" , "graph ")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


