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
	testcase = testTemplate.regexTester("5 7\n3 3 4 2 1" , "Yes" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 17\n3 3 4 2 1" , "Yes" , "sample1.2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 6\n3 3 4 2 1" , "No" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 8\n3 3 4 2 1" , "No" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


