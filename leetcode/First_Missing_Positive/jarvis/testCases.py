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
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count=True)
	testcase = testTemplate.testInstance("3 1 2 0" , "3" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("4 3 4 -1 1" , "2" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("0 " , "1" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1 0 " , "1" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2 1 2 " , "3" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1 1 " , "2" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1 2 " , "1" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.testInstance("4 0 -1 3 1 " , "2" , "sample8")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


