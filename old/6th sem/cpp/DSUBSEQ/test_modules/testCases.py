import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample test cases")
	testcase = testTemplate.testInstance("AAA" , "4" , "sample #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("ABCDEFG" , "128" , "sample #2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("CODECRAFT" , "496" , "sample #3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


