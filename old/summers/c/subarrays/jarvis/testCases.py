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
	testcase = testTemplate.regexTester("5\n2 2 1 1 4\n2" , "2 2 1 4 " , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("5 \n2 8 4 3 6 \n1" , "2 8 4 3 6 " , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("9\n\n1  2  3  1  4  5  2  3  6\n3" , "3 3 4 5 5 5 6 " , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


