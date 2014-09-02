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
	
	suite=testTemplate.testSuite("Smoke Test Suite",print_count=True)
	testcase = testTemplate.regexTester("3" , "3" , "Test Case 1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("0" , "0" , "Test Case 2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-1" , "-1" , "Test Case 3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Boundary Test Suite",print_count=True)
	testcase = testTemplate.regexTester("999999999" , "999999999" , "Test Case 1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1000000000" , "1000000000" , "Test Case 2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-999999999" , "999999999" , "Test Case 3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-1000000000" , "1000000000" , "Test Case 4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


