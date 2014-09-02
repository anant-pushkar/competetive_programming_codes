import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.regexTester("11" , "13" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite1.1")
	testcase = testTemplate.regexTester("111" , "136" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite1.2")
	testcase = testTemplate.regexTester("112" , "139" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("16" , "23" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("123" , "164" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


