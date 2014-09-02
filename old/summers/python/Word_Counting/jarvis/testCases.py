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
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True,header="\n")
	testcase = testTemplate.regexTester("a aa bb cc def ghi" , "3" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("a a a a a bb bb bb bb c c" , "5" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("  \na a a a a" , "5" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


