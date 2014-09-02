import testTemplate 
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Cases")
	testcase = testTemplate.testInstance("4 3 2 10 4" , "In game 1, the greedy strategy might lose by as many as 7 points." , "Sample #1")
	suite.add(testcase)
	testcase = testTemplate.testInstance("8 1 2 3 4 5 6 7 8" , "In game 2, the greedy strategy might lose by as many as 4 points." , "Sample #2")
	suite.add(testcase)
	testcase = testTemplate.testInstance("8 2 2 1 5 3 8 7 3" , "In game 3, the greedy strategy might lose by as many as 5 points." , "Sample #3")
	suite.add(testcase)
	tests.append(suite)
	
	suite=testTemplate.testSuite("Custom Test Cases With increasing sequences")
	testcase = testTemplate.testInstance("10 1 2 3 4 5 6 7 8 9 10" , "In game 1, the greedy strategy might lose by as many as 5 points." , "Incresing sequence of length 10")
	suite.add(testcase)
	testcase = testTemplate.testInstance("20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20" , "In game 2, the greedy strategy might lose by as many as 10 points." , "Incresing sequence of length 20")
	suite.add(testcase)
	testcase = testTemplate.testInstance("30 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30" , "In game 3, the greedy strategy might lose by as many as 15 points." , "Incresing sequence of length 30")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


