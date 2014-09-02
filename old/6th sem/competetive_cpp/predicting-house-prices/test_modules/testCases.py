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
	testcase = testTemplate.regexTester("2 7\n0.18 0.89 109.85\n1.0 0.26 155.72\n0.92 0.11 137.66\n0.07 0.37 76.17\n0.85 0.16 139.75\n0.99 0.41 162.6\n0.87 0.47 151.77\n4\n0.49 0.18\n0.57 0.83\n0.56 0.64\n0.76 0.187" , "?\n?\n?\n?" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


