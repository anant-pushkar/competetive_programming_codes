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
	testcase = testTemplate.regexTester("5 3\n3" , "" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 2 1 1 3 3" , "NO" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 3 1 3 5 2" , "YES" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 2 1 2 4 3" , "YES" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


