import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Smoke test suite")
	testcase = testTemplate.testInstance("3\n1 2 3\n2 3 1\n3 1 2" , "3" , "sample")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3\n1 2 3\n2 3 1\n1 3 2" , "3" , "anamoly")
	suite.add(testcase)
	testcase = testTemplate.testInstance("10 \n2 5 3 8 10 7 1 6 9 4\n1 2 3 4 5 6 7 8 9 10\n3 8 7 10 5 4 1 2 6 9" , "4" , "NKTEAM sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


