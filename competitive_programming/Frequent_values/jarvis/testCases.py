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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="0")
	
	testcase = testTemplate.testInstance('''
		10 3
		-1 -1 1 1 1 1 3 10 10 10
		2 3
		1 10
		5 10''' , "1\n4\n3" , "sample")
	suite.add(testcase)
	
	tests.append(suite)
	
	return tests


