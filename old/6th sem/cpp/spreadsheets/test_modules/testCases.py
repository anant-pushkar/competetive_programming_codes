import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	testcase = testTemplate.testInstance("R23C55" , "BC23" , "1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("BC23" , "R23C55" , "2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("A1" , "R1C1" , "3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("BZ78" , "R78C78" , "4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("ZZ676" , "R676C702" , "5")
	suite.add(testcase)
	testcase = testTemplate.testInstance("ZZZ17576" , "R17576C17576" , "6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("BZZ2028" , "R2028C2028" , "6")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


