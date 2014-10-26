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
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.testInstance(
'''
5 2
1 1 -1 -1 -1
1 2
2 3
4 1
4 5
''' , "2" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite1")
	testcase = testTemplate.testInstance(
'''
7 2
1 1 -1 -1 -1 2 3
1 2
2 3
4 1
4 5
5 6
5 7
''' , "5" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite2")
	testcase = testTemplate.testInstance(
'''
8 2
1 1 -1 -1 -1 2 3 10
1 2
2 3
4 1
4 5
5 6
5 7
4 8
''' , "15" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite3")
	testcase = testTemplate.testInstance(
'''
10 2
1 1 -1 -1 -1 2 3 10 -5 10
1 2
2 3
4 1
4 5
5 6
5 7
4 8
3 9
3 10
''' , "24" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite4")
	testcase = testTemplate.testInstance(
'''
10 1
1 1 -1 -1 -1 2 3 -10 -5 -10
1 2
2 3
4 1
4 5
5 6
5 7
4 8
3 9
3 10
''' , "0" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


