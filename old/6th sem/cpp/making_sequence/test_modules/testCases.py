import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample 1")
	testcase = testTemplate.testInstance("9 1 1" , "9" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample 2")
	testcase = testTemplate.testInstance("77 7 7" , "7" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample 3")
	testcase = testTemplate.testInstance("114 5 14" , "6" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample 4")
	testcase = testTemplate.testInstance("1 1 2" , "0" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary test 1")
	testcase = testTemplate.testInstance("16 1111111111111111 1" , "1" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary test 2")
	testcase = testTemplate.testInstance("130 1111111111111111 4" , "2" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary test 3")
	testcase = testTemplate.testInstance("170 1111111111111111 1" , "10" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary test 4")
	testcase = testTemplate.testInstance("1 1111111111111111 1" , "0" , "")
	suite.add(testcase)
	tests.append(suite)

	suite=testTemplate.testSuite("Site test case 13")
	testcase = testTemplate.testInstance("2155990066796462 2710473050636183 563261158" , "239230" , "")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


