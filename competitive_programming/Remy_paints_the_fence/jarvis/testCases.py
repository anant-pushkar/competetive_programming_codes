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
	testcase = testTemplate.testInstance("2 1\nR 1" , "1" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3 1\nA 2" , "1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("6 2\nA 2\nB 6" , "4" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


