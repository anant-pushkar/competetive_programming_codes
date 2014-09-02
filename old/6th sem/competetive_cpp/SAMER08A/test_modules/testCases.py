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
	testcase = testTemplate.regexTester("7 9\n0 6\n0 1 1\n0 2 1\n0 3 2\n0 4 3\n1 5 2\n2 6 4\n3 6 2\n4 6 4\n5 6 1" , "5" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 6\n0 2\n0 1 1\n1 2 1\n1 3 1\n3 2 1\n2 0 3\n3 0 2" , "-1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6 8\n0 1\n0 1 1\n0 2 2\n0 3 3\n2 5 3\n3 4 2\n4 1 1\n5 1 1\n3 0 1" , "6" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


