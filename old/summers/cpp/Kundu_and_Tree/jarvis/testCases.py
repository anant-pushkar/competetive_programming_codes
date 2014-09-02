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
	testcase = testTemplate.regexTester("5\n1 2 b\n2 3 r\n3 4 r\n4 5 b" , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


