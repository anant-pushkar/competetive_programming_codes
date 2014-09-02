import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Cases")
	testcase = testTemplate.testInstance("3\n1 1 1\n1 1 1\n1 1 1" , "6" , "Sample #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("11\n1 0 0 1 0 0 0 0 0 1 1 \n1 1 1 1 1 0 1 0 1 0 0 \n1 0 0 1 0 0 1 1 0 1 0 \n1 0 1 1 1 0 1 1 0 1 1 \n0 1 1 1 0 1 0 0 1 1 1 \n1 1 1 0 0 1 0 0 0 0 0 \n0 0 0 0 1 0 1 0 0 0 1 \n1 0 1 1 0 0 0 0 0 0 1 \n0 0 1 0 1 1 0 0 0 1 1 \n1 1 1 0 0 0 1 0 1 0 1 \n1 0 0 0 1 1 1 1 0 0 0" , "7588" , "Sample #2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("11\n0 1 1 1 0 1 0 0 0 1 0 \n0 0 1 1 1 1 1 1 1 1 1 \n1 1 0 1 0 0 0 0 0 1 0 \n0 1 0 1 0 1 0 1 0 1 1 \n1 0 0 1 0 0 0 0 1 0 1 \n0 0 1 0 1 1 0 0 0 0 1 \n1 0 1 0 1 1 1 0 1 1 0 \n1 0 1 1 0 1 1 0 0 1 0 \n0 0 1 1 0 1 1 1 1 1 1 \n0 1 0 0 0 0 0 0 0 1 1 \n0 1 1 0 0 0 0 0 1 0 1 " , "7426" , "Sample #3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


