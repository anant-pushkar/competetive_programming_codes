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
	testcase = testTemplate.regexTester("349 1 4" , "348" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("395 1 7" , "392" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 -2 2" , "0" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 2 4" , "24" , "Custom1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("7 3 4" , "344" , "Custom2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 -1 1" , "0" , "Custom3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


