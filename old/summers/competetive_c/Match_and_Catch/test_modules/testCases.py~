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
	testcase = testTemplate.regexTester("apple\npepperoni" , "2" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("lover\ndriver" , "1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("bidhan\nroy" , "-1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.regexTester("testsetses\nteeptes" , "3" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Test#11")
	testcase = testTemplate.regexTester("aaaaaaaaaaaaaaaaaaaaaaa\nbbbbbbbbbaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbb" , "-1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests

