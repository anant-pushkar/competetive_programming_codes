import testTemplate 
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance("3\n3 1 5" , "26" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance("1\n10" , "10" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1")
	testcase = testTemplate.testInstance("4\n3 1 5 1" , "30" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite2")
	testcase = testTemplate.testInstance("2\n3 1" , "8" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite3")
	testcase = testTemplate.testInstance("7\n3 1 2 4 5 6 7" , "111" , "custom")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


