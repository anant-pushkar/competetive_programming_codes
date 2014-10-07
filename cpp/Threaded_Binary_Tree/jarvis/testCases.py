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
1 0
0 0
''' , "-1 " , "smoke test case1")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''
2 0
1 0
0 1
''' , "-1 1 " , "smoke test case2")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''
2 1
0 1
1 0
''' , "-1 1 " , "smoke test case3")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''
5 2
2 2
2 1
1 0
2 3
3 4
''' , "2 3 4 5 -1 " , "custom test1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


