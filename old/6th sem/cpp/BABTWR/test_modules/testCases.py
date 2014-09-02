import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample test cases")
	testcase = testTemplate.testInstance("5\n31 41 59\n26 53 58\n97 93 23\n84 62 64\n33 83 27" , "342" , "sample #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1\n1 1 1" , "1" , "sample #2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


