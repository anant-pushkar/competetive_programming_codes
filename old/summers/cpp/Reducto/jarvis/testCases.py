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
	testcase = testTemplate.regexTester("2 acmmcacamapapc mca pa" , "6" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 ccdedefcde cde" , "1" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 aabaab aa bb" , "0" , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


