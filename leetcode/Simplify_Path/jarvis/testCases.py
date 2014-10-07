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
	testcase = testTemplate.regexTester("/home/" , "/home" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("/a/./b/../../c/" , "/c" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("/../" , "/" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("/home//foo/" , "/home/foo/" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("///" , "/" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


