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
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.testInstance("3" , "1" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("4" , "1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("5" , "2" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("100" , "49" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


