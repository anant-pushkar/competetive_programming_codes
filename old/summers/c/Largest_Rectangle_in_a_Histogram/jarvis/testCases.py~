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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="0")
	testcase = testTemplate.regexTester("7 2 1 4 5 1 3 3" , "8" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 1000 1000 1000 1000" , "4000" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


