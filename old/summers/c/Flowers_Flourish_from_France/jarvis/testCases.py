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
	
	suite=testTemplate.testSuite("Sample Test Suite1",footer="*")
	testcase = testTemplate.testInstance("Flowers Flourish from France " , "Y" , "sample")
	suite.add(testcase)
	testcase = testTemplate.testInstance("Sam Simmonds speaks softly" , "Y" , "sample")
	suite.add(testcase)
	testcase = testTemplate.testInstance(" Peter pIckEd pePPers" , "Y" , "sample")
	suite.add(testcase)
	testcase = testTemplate.testInstance("truly tautograms triumph" , "Y" , "sample")
	suite.add(testcase)
	testcase = testTemplate.testInstance("this is NOT a tautogram" , "N" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


