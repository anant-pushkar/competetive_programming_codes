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
	testcase = testTemplate.regexTester("1 10\n*........X\n" , "Escape possible in 9 steps." , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 3\n*#X\n" , "The poor student is trapped!" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 20\n####################\n#XY.gBr.*.Rb.G.GG.y#\n####################\n" , "Escape possible in 45 steps." , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 2\n##\n*X\n" , "Escape possible in 1 steps." , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


