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
	testcase = testTemplate.regexTester("01/01/2000" , "02/31/2000" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("08/08/2000" , "02/31/2040" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("02/02/2000" , "02/31/2000" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("02/31/2000" , "02/31/2040" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("02/31/2001" , "02/31/2040" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("02/31/1760" , "02/31/1840" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("02/31/2200" , "02/31/2240" , "sample7")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


