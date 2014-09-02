import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample 1")
	testcase = testTemplate.testInstance("4 4\n1 1\n100 55 10 2\n20   10 90 1\n60   20 22 4\n1     30 70 5" , "Y 23" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample 2")
	testcase = testTemplate.testInstance("2 2\n1 1\n1   55 \n20 10 " , "N" , "")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


