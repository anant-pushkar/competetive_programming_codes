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
	testcase = testTemplate.regexTester("9 3\n100 200 300 400 500 600 700 800 900" , "100 200 300 400 500 / 600 700 / 800 900" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5 4\n100 100 100 100 100" , "100 / 100 / 100 / 100 100" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10 4 \n100 200 400 300 500 100 200 700 400 200 " , "100 200 400 / 300 500 100 / 200 700 / 400 200" , "from comment")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


