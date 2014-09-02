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
	testcase = testTemplate.regexTester("3\n3 2 1" , "yes\n1 3" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("4\n2 1 3 4" , "yes\n1 2" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("4\n3 1 2 4" , "no" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.regexTester("2\n1 2" , "yes\n1 1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite5")
	testcase = testTemplate.regexTester("10\n1 2 2 2 7 6 5 4 3 8 " , "yes\n5 9" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite6")
	testcase = testTemplate.regexTester("10\n1 2 2 2 7 6 5 4 3 7 " , "yes\n5 9" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite7")
	testcase = testTemplate.regexTester("12\n1 2 2 2 7 6 5 4 3 7 7 8" , "yes\n5 9" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite8")
	testcase = testTemplate.regexTester("11\n1 2 2 2 7 6 5 4 2 2 7 " , "yes\n5 10" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite9")
	testcase = testTemplate.regexTester("11\n1 2 2 2 7 6 5 4 2 3 7 " , "no" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite10")
	testcase = testTemplate.regexTester("11\n1 2 2 7 7 6 5 4 2 2 7 " , "yes\n4 10" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


