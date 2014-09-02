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
	testcase = testTemplate.testInstance("\n1 + 1 * 2 =" , "4" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("\n29 / 5=" , "5" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("\n103 *103* 5 =" , "53045" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("\n50* 40 * 250 + 791 =" , "500791" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1",print_count=True)
	testcase = testTemplate.testInstance("\n1 =" , "1" , "custom1")
	suite.add(testcase)
	suite.add(testcase)
	tests.append(suite)
	
	return tests


