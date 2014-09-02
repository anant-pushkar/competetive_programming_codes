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
	testcase = testTemplate.regexTester("5\n999 1 1 1 0" , "1001" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n0 1 1 1 999" , "999" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


