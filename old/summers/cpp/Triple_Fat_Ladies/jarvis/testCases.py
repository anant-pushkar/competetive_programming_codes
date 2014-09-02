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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="0.00")
	testcase = testTemplate.regexTester("1.00" , "3 cards(s)" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3.71" , "61 cards(s)" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("0.04" , "1 cards(s)" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5.19" , "273 cards(s)" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


