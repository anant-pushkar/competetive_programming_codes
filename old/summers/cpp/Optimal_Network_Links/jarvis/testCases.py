import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.regexTester("5\nD B\nD C\nD A\nB A\nC A" , "Case 1: 1 D,A " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6\nD B\nD C\nD A\nC B\nB A\nC A" , "Case 2: 3 C,A D,A D,B " , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1\nA B" , "Case 3: 0 " , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("string Test Suite1",print_count=True)
	testcase = testTemplate.regexTester("5\nDa Ba\nDa Ca\nDa Aa\nBa Aa\nCa Aa" , "Case 1: 1 Da,Aa " , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6\nD1 B1\nD1 C1\nD1 A1\nC1 B1\nB1 A1\nC1 A1" , "Case 2: 3 C1,A1 D1,A1 D1,B1 " , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1\nA# B#" , "Case 3: 0 " , "sample3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("custom Test Suite1",print_count=True)
	testcase = testTemplate.regexTester("6\nA B\nA C\nA D\nB C\nB D\nC D" , "Case 1: 3 A,C A,D B,D " , "custom1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("6\nA B\nA C\nA D\nB C\nB D\nD C" , "Case 2: 3 A,C A,D B,C " , "custom2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


