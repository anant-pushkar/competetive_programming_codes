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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="0")
	
	testcase = testTemplate.testInstance('''
2
1 2 3
4 5 6''', "126" , "sample1")
	suite.add(testcase)
	
	testcase = testTemplate.testInstance('''
2
4 4 4
2 2 2''', "9" , "sample2")
	suite.add(testcase)
	
	tests.append(suite)
	
	return tests


