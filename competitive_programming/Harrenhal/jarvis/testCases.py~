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
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count=True)
	testcase = testTemplate.testInstance("abbabaab" , "2" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1" , print_count=True)
	testcase = testTemplate.testInstance("aaaaaa" , "1" , "custom1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("baaabababaab" , "2" , "custom2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


