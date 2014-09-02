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
	testcase = testTemplate.regexTester("<<>>" , "4" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("><" , "0" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("<>>>" , "2" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


