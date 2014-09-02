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
	
	suite=testTemplate.testSuite("Sample Test Suite1",header="3\n3 2 7",print_count=True)
	testcase = testTemplate.regexTester("1 2" , "Odd" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 3" , "Even" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1",header="3\n0 2 0",print_count=True)
	testcase = testTemplate.regexTester("1 3" , "Even" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 3" , "Odd" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 3" , "Even" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 2" , "Even" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 1" , "Even" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite2",header="3\n0 1 0",print_count=True)
	testcase = testTemplate.regexTester("1 3" , "Even" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 3" , "Odd" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 3" , "Even" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 2" , "Odd" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 1" , "Even" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


