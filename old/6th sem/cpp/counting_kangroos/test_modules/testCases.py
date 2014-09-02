import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample 1")
	testcase = testTemplate.testInstance("8\n2\n5\n7\n6\n9\n8\n4\n2" , "5" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample 2")
	testcase = testTemplate.testInstance("8\n9\n1\n6\n2\n6\n5\n8\n3" , "5" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom test 1")
	testcase = testTemplate.testInstance("2\n4\n5" , "2" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom test 2")
	testcase = testTemplate.testInstance("2\n2\n5" , "1" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom test 2")
	testcase = testTemplate.testInstance("4\n2\n4\n9\n20" , "2" , "")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


