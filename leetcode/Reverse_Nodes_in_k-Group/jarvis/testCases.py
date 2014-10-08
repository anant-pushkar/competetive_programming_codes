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
	testcase = testTemplate.testInstance("1 1\n1" , "1 " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2 2\n1 2" , "2 1 " , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2 3\n1 2" , "1 2 " , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3 2\n1 2 3" , "2 1 3 " , "sample4")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''4 2
1 2 3 4
''' , "2 1 4 3 " , "sample5")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''4 4
1 2 3 4
''' , "4 3 2 1 " , "sample6")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


