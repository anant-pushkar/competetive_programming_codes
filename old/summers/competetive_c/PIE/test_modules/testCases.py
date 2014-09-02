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
	testcase = testTemplate.regexTester("3 3\n4 3 3" , "25.1327" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 24\n5" , "3.1416" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10 5\n1 4 2 3 4 5 6 5 4 2" , "50.2655" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


