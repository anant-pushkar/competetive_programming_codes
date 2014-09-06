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
	testcase = testTemplate.testInstance("1+2*3+4*5" , "105 27" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1+2*3+4+5" , "36 16" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1" , "1 1" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1+2+3+4+5" , "15 15" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1*2*3*4*5" , "120 120" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("3*2" , "6 6" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("1+2*3+4+5+3" , "45 19" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.testInstance("2*0*3+7+1*0*3" , "42 0" , "sample8")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


