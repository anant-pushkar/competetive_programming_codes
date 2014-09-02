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
	testcase = testTemplate.regexTester("1" , "Yes" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2" , "Yes" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("7" , "No" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("14" , "No" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("49" , "Yes" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9" , "Yes" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("17" , "Yes" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.regexTester("76" , "No" , "sample8")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2888" , "Yes" , "sample9")
	suite.add(testcase)
	testcase = testTemplate.regexTester("27" , "No" , "sample10")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


