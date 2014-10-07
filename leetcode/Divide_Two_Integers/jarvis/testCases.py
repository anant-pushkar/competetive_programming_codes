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
	testcase = testTemplate.testInstance("3 2" , "1" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("100 10" , "10" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("101 10" , "10" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("-1 -1" , "1" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


