import testTemplate 
'''
1 5 13  27  48  78  118  170  235 315
'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.regexTester("1" , "1" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2" , "5" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3" , "13" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4" , "27" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("5" , "48" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6" , "78" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("7" , "118" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.regexTester("8" , "170" , "sample8")
	suite.add(testcase)
	testcase = testTemplate.regexTester("9" , "235" , "sample9")
	suite.add(testcase)
	testcase = testTemplate.regexTester("10" , "315" , "sample10")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


