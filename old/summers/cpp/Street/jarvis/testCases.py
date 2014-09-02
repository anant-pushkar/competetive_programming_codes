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
	testcase = testTemplate.regexTester("10 2 4\n7\n3\n12\n11\n13\n4\n8\n6\n6\n20" , "57" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


