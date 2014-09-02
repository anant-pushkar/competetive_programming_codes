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
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.regexTester("143175=120" , "2" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite2")
	testcase = testTemplate.regexTester("5025=30" , "1" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite3")
	testcase = testTemplate.regexTester("999899=125" , "4" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite4")
	testcase = testTemplate.regexTester("1000=1000" , "0" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite5")
	testcase = testTemplate.regexTester("".join(['15' for x in xrange(333)])+"5=5000" , "333" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Sample Test Suite6")
	s=0
	i=""
	for x in xrange(33):
		n  = 8099 -random.randint(1,10)*100-random.randint(1,10)*10
		print "n : ",n
		s += n
		i  = i + str(n)
	testcase = testTemplate.regexTester(i+"="+str(s) , "32" , "sample")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


