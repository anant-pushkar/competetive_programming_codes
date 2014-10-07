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
	testcase = testTemplate.regexTester('''
6 5
01101
11010
01110
11110
11111
00000''' , "9" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester('''
9 8
00010111
01100101
10111101
00010000
00100010
11100111
10011001
01001100
10010000''' , "4" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


