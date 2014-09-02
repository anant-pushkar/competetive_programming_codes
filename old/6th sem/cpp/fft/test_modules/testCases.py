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
	testcase = testTemplate.regexTester("16 1 1 0 1 1 0 1 1 0 1 1 0 1 1 0 1" , "?" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.regexTester("8 1 1 0 1 1 0 1 1" , "?" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


