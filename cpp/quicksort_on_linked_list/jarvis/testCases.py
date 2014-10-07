import testTemplate 
import random
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
	for i in xrange(10):
		n = random.randint(2,10000)
		arr = []
		for j in xrange(n):
			arr.append(random.randint(1,1000000))
		istr = str(n) + " " + " ".join([str(x) for x in arr])
		arr.sort()
		ostr = " ".join([str(x) for x in arr]) + " " 
		testcase = testTemplate.testInstance(istr , ostr , "sample"+str(i))
		suite.add(testcase)
	tests.append(suite)
	
	return tests


