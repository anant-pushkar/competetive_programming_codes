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
	testcase = testTemplate.regexTester("2\n0\n900" , "IMPOSSIBLE" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("8\n1400\n1200\n1000\n800\n600\n400\n200\n0" , "POSSIBLE" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


