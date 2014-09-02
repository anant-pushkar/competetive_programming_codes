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
	testcase = testTemplate.regexTester("6\n5 5 7 10 14 15\n3\n2 11\n3 12\n4 4" , "9\n7\n0" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("7\n2 3 5 7 11 4 8\n2\n8 10\n2 123" , "0\n7" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


