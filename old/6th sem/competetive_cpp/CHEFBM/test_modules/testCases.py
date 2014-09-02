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
	testcase = testTemplate.regexTester("4 4 6\n2 2\n3 2 \n3 2 \n4 3\n4 4\n4 3" , "3\n3\n-1\n4" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


