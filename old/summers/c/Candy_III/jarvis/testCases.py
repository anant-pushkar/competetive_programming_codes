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
	testcase = testTemplate.regexTester("5\n5\n2\n7\n3\n8" , "YES" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("\n5\n5\n2\n7\n3\n4" , "NO" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


