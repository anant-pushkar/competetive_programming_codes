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
	testcase = testTemplate.testInstance("barfoothefoobarman\n2\nfoo bar" , "0 9 " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance(
'''abababab
3
a b a
''' , "0 2 4 " , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


