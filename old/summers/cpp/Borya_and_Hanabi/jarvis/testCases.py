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
	testcase = testTemplate.regexTester("2\nG3 G3" , "0" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("4\nG4 R4 R3 B3" , "2" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("5\nB1 Y1 W1 G1 R1" , "4" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.regexTester("5\nG4 R4 R3 B3 B4" , "3" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite5")
	testcase = testTemplate.regexTester("1\nG3" , "0" , "sample5")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite6")
	testcase = testTemplate.regexTester("7\nR2 R3 R4 G3 B3 G1 Y5" , "4" , "sample6")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


