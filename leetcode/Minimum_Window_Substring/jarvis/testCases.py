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
	testcase = testTemplate.testInstance("ask_not_what_your_country_can_do_for_you_ask_what_you_can_do_for_your_country ask_country" , "sk_not_what_your_c" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("acbbaca aba" , "baca" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


