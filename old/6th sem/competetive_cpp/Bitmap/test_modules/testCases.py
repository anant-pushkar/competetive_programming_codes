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
	#testcase = testTemplate.regexTester("3\n4 1 7" , "2\n-2 10" , "sample")
	#suite.add(testcase)
	tests.append(suite)
	
	return tests


