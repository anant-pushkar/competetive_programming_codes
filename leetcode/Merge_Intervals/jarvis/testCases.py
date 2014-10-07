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
	testcase = testTemplate.testInstance("4\n1 3\n2 6\n8 10\n15 18" , "3\n1 6\n8 10\n15 18\n" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2\n1 4\n0 4" , "1\n0 4" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


