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
	testcase = testTemplate.testInstance('''
22 10 8
10 5
5 12
12 7
7 11
4 20
20 13
21 22
17 6
9 8
19 15
10 4
20 2
13 16
16 3
7 17
17 9
9 19
5 21
10
''' , "10 5 12 7 11 4 20 13 21 22 17 6 2 16 9 8 3 19 15 " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance('''
6 3 2
1 2
2 3
3 4
1 5
5 6
1
''' , "1 2 3 4 5 6 " , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


