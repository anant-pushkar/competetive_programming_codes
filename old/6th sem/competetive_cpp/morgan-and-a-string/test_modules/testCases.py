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
	testcase = testTemplate.regexTester("JACK\nDANIEL" , "DAJACKNIEL" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("ABACABA\nABACABA" , "AABABACABACABA" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("BBBBBA\nBBBC" , "BBBBBABBBC" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("BBBC\nBBBBBA" , "BBBBBABBBC" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("ABCDA\nABCDB" , "AABBCCDADB" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("ABCDB\nABCDA" , "AABBCCDADB" , "sample4")
	suite.add(testcase)
	tests.append(suite)
	
	
	
	return tests


