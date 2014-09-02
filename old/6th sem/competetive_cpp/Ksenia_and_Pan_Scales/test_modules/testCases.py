import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("AC|T\nL" , "AC|TL" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance("|ABC\nXYZ" , "XYZ|ABC" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.testInstance("W|T\nF" , "Impossible" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.testInstance("ABC|\nD" , "Impossible" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite5")
	testcase = testTemplate.testInstance("A|SD\nQWE" , "AQW|SDE" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


