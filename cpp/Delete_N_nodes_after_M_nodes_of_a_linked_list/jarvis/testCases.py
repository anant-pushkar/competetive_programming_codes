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
	testcase = testTemplate.testInstance(
'''
8
1 2 3 4 5 6 7 8
2 2
''' , "1 2 5 6 " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''
10
1 2 3 4 5 6 7 8 9 10
3 2
''' , "1 2 3 6 7 8 " , "sample2")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''
10
1 2 3 4 5 6 7 8 9 10
1 1
''' , "1 3 5 7 9 " , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


