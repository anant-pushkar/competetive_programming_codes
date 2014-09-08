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
	testcase = testTemplate.testInstance('''
	5
	0 1 0 1 0''' , "3" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance('''
	5
	1 1 0 0 1''' , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.testInstance('''
	2
	0 0''' , "0" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


