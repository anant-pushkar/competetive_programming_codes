import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample test suite")
	testcase = testTemplate.testInstance("2 3 5 \n3 12 113 25714 88888" , "ABAAB" , "Sample #1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


