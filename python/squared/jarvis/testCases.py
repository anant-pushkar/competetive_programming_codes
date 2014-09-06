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
	def get_sum(n):
		return sum(int(x) for x in str(int("".join(["1"]*n))**2))
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	val = [get_sum(x) for x in xrange(1,101)]
	for i in range(100):
		testcase = testTemplate.regexTester(str(i+1) , str(val[i]) , "sample"+str(i+1))
		suite.add(testcase)
	tests.append(suite)
	
	
	
	
	
	return tests


