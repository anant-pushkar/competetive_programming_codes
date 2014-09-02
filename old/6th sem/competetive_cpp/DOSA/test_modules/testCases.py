import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("6\n1 7 10 2 20 22" , "1" , "Sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance("5\n1 2 2 3 4" , "3" , "Sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Test Suite from comments")
	testcase = testTemplate.testInstance("12 \n10 11 12 10 9 15 16 22 21 19 20 21 " , "4" , "comment")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Test Suite from stackoverflow1")
	testcase = testTemplate.testInstance("6 \n1 3 3 4 5 6 " , "1" , "stackoverflow")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Test Suite from stackoverflow2")
	testcase = testTemplate.testInstance("5\n1 2 9 10 3 15" , "1" , "stackoverflow")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Test Suite from stackoverflow3")
	testcase = testTemplate.testInstance("7\n1 2 2 2 3 4 5 " , "5" , "stackoverflow")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


