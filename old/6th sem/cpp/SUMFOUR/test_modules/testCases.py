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
	testcase = testTemplate.regexTester("6" , "" , "size of list")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-45 22 42 -16" , "" , "list#1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-41 -27 56 30" , "" , "list#2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-36 53 -37 77" , "" , "list#3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-36 30 -75 -46" , "" , "list#4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("26 -38 -10 62" , "" , "list#5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("-32 -54 -6 45" , "5" , "list#6")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


