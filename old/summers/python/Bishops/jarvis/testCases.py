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
	testcase = testTemplate.regexTester("2" , "2" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3" , "4" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1000000000000000000000000000000" , "1999999999999999999999999999998" , "long sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


