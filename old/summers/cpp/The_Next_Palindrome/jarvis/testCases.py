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
	testcase = testTemplate.regexTester("808" , "818" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2133" , "2222" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Suite",print_count=True)
	testcase = testTemplate.regexTester("999" , "1001" , "all9_odd")
	suite.add(testcase)
	testcase = testTemplate.regexTester("909" , "919" , "notall9_odd")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9009" , "9119" , "notall9_even")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9999" , "10001" , "all9_even")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9998" , "9999" , "arbit1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9989" , "9999" , "arbit2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9898" , "9999" , "arbit3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1824" , "1881" , "reflect_even")
	suite.add(testcase)
	testcase = testTemplate.regexTester("18534" , "18581" , "reflect_odd")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1234" , "1331" , "propogate_even")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1994" , "2002" , "propogate_even_carry")
	suite.add(testcase)
	testcase = testTemplate.regexTester("12345" , "12421" , "propogate_odd")
	suite.add(testcase)
	testcase = testTemplate.regexTester("12945" , "13031" , "propogate_odd_carry1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1299945" , "1300031" , "propogate_odd_carry2")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("gfg_examples",print_count=True)
	testcase = testTemplate.regexTester("23545" , "23632" , "example1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1221" , "1331" , "example2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


