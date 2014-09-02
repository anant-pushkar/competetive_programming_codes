import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Default Test Suite1")
	testcase = testTemplate.testInstance("XXXOO.XXX" , "invalid" , "Sample 1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XOXOXOXOX" , "valid" , "Sample 2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("OXOXOXOXO" , "invalid" , "Sample 3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XXOOOXXOX" , "valid" , "Sample 4")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XO.OX...X" , "valid" , "Sample 5")
	suite.add(testcase)
	testcase = testTemplate.testInstance(".XXX.XOOO" , "invalid" , "Sample 6")
	suite.add(testcase)
	testcase = testTemplate.testInstance("OOXXXOOXO" , "invalid" , "Sample 7")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XXOOOXXOX" , "valid" , "comment1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XX.OOO..X" , "valid" , "comment2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("X.OOX...X" , "valid" , "comment3")
	suite.add(testcase)
	testcase = testTemplate.testInstance("XXO.XOX.O" , "invalid" , "comment 4")
	suite.add(testcase)
	tests.append(suite)
	
	return tests

