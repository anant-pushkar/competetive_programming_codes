import testTemplate 
'''number of test suites'''
nSuites=1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample1")
	testcase = testTemplate.testInstance("1\n.135\n1247\n3468\n5789" , "YES" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample2")
	testcase = testTemplate.testInstance("5\n..1.\n1111\n..1.\n..1." , "YES" , "")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample3")
	testcase = testTemplate.testInstance("1\n....\n12.1\n.2..\n.2.." , "NO" , "")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


