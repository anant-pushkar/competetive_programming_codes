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
	testcase = testTemplate.testInstance("0011" , "EQUAL" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.testInstance("0111" , "ROTATE" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.testInstance("000111" , "SHOOT" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


