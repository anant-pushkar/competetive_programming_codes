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
	testcase = testTemplate.regexTester("8 1\n0 0\n3 1\n5 0\n4 2\n3 4\n2 5\n1 5\n0 5" , "" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("8 1\n0 5\n20 20\n23 11\n5 0\n4 2\n3 4\n2 5\n1 5" , "" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


