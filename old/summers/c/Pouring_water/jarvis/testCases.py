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
	testcase = testTemplate.regexTester("5\n2\n3" , "2" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2\n3\n4" , "-1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10\n7\n6" , "6" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10\n7\n3" , "2" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5\n3\n1" , "2" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


