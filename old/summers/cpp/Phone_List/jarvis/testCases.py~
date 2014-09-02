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
	testcase = testTemplate.regexTester("3\n911\n97625999\n91125426" , "NO" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n113\n12340\n123440\n12345\n98346" , "YES" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


