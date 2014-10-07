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
	testcase = testTemplate.testInstance("aa a" , "0" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aa aa" , "1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aaa aa" , "0" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aa *" , "1" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aa a*" , "1" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aa ?*" , "1" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("aab c*a*b" , "0" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.testInstance("b ?*?" , "0" , "sample8")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


