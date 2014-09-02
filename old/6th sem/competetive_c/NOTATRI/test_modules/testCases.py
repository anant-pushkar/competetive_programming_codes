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
	testcase = testTemplate.regexTester("3\n4 2 10" , "1" , "sample#1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3\n1 2 3" , "0" , "sample#2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4\n5 2 9 6" , "2" , "sample#1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Testcases from comments")
	testcase = testTemplate.regexTester("6\n1 2 3 3 3 5" , "4" , "sample#1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n8 8 2 2 3" , "6" , "sample#2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


