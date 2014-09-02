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
	
	suite=testTemplate.testSuite("Sample Test Suite")
	testcase = testTemplate.regexTester("6\n100 200 100 500 100 600\n1 2\n2 3\n2 5\n4 5\n5 6" , "400" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


