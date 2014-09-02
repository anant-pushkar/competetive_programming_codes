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
	testcase = testTemplate.regexTester("2" , "3" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3" , "8" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4" , "6" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5" , "20" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6" , "24" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


