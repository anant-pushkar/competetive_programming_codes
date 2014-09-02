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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="0\n")
	testcase = testTemplate.regexTester("5\n5 1 2 4 3 " , "yes" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n5 2 1 4 3 " , "yes" , "sample")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n4 1 2 5 3 " , "no" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite",footer="0\n")
	testcase = testTemplate.regexTester("5 \n4 1 5 3 2  " , "no" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 \n3 1 2 5 4" , "yes" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 \n5 3 2 1 4 " , "yes" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10 \n1 2 10 5 4 3 7 6 8 9  " , "yes" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10 \n1 2 10 5 4 3 9 8 7 6 " , "yes" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 \n3 5 2 4 1" , "no" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 \n1 2 4 3 5 " , "yes" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 \n4 2 3 1 " , "no" , "sample8")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


