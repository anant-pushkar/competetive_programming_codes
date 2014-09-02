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
	testcase = testTemplate.regexTester(" 4 \n1/4 \n1/2 \n1/2 \n3/4 " , "3" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite12")
	testcase = testTemplate.regexTester("9 \n3/4 \n1/2 \n1/4 \n1/4 \n1/4 \n1/4 \n1/4 \n1/4 \n1/4 " , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite13")
	testcase = testTemplate.regexTester("5\n1/2\n3/4\n1/2\n1/4\n1/4" , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite14")
	testcase = testTemplate.regexTester("3\n1/2\n3/4\n3/4" , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


