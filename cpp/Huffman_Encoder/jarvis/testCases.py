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
	testcase = testTemplate.regexTester("5 u\na b c d e\n2 5 3 1 7" , "?\n5" , "unordered sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 u\na b c d e\n1 2 3 4 5" , "?\n5" , "unordered sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 u\na b c d e\n1 1 3 4 6" , "?\n5" , "unordered sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 u\na b c d e\n1 1 1 1 1" , "?\n5" , "unordered sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 u\na b c d\n1 1 1 1" , "?\n4" , "unordered sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 o\na b c d e" , "?\n5" , "ordered sample1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


