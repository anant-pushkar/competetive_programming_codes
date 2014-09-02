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
	testcase = testTemplate.regexTester("-4 1 2 6 0 -1 4 3" , "42" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1")
	testcase = testTemplate.regexTester("0 0 1 1 -4 -4 -1 -1" , "10" , "testcase 1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("0 0 5 5 1 1 4 4" , "25" , "testcase 2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("0 0 5 5 1 -1 8 8" , "68" , "testcase 3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("0 0 5 5 1 -1 8 8" , "68" , "testcase 4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 1 4 4 0 0 5 5" , "25" , "testcase 2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


