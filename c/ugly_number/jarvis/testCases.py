import testTemplate 
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def is_ugly(n):
	while n%2==0:
		n /= 2
	while n%3==0:
		n /= 3
	while n%5==0:
		n /= 5
	return n==1
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	n = 1000000
	t = 1
	for i in xrange(1,n+1):
		if is_ugly(i):
			testcase = testTemplate.regexTester(str(t) , str(i) , "sample"+str(t))
			suite.add(testcase)
			t += 1
	tests.append(suite)
	
	return tests


