import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("nested dependency test")
	testcase = testTemplate.testInstance("1" , "D1 success fully called\nD2 success fully called" , "test case 1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("direct dependency test")
	testcase = testTemplate.testInstance("2" , "D3 success fully called" , "test case 1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


