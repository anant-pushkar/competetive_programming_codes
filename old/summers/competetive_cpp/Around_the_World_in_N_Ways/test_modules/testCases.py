import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	for i in range(9000,10000):
		a=1
		b=2
		c=4
		for j in range(i-3):
			d=(a+b+c)%1000000007
			a=b
			b=c
			c=d
		testcase = testTemplate.regexTester(str(i) , str(c) , "sample#"+str(i))
		suite.add(testcase)
	tests.append(suite)
	
	return tests


