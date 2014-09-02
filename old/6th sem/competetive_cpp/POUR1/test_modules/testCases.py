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
	testcase = testTemplate.regexTester("5\n2\n3" , "2" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2\n3\n4" , "-1" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


