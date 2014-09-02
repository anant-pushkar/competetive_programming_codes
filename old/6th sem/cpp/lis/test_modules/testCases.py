import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	d=10000
	for i in range(1,10):
		d=d+100000
		testcase = testTemplate.testInstance(str(d) , "success" , "Test acse #"+str(i))
		suite.add(testcase)
	tests.append(suite)
	
	return tests


