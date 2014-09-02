import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("5 7\n5 2 100\n3 5 80\n2 3 70\n2 1 50\n3 4 90\n4 1 85\n3 1 70" , "61.200000 percent" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


