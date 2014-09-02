import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("5 0 0 2 1 1 3 2 4 5 1" , "4" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("9 6 7 5 3 2 2 0 1 1 0 2 1 2 0 3 1 4 2" , "5" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 0 0 1 0 0 1" , "2" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("6 0 0 0 1 1 1 1 2 2 1 2 4" , "3" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 1 2 2 1 2 2 2 3 2 4 3 3 4 4 1 5" , "4" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 1 2 2 1 1 2 2 3 2 4 3 3 4 4 1 5" , "4" , "Smoke test case 6")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 3 2 2 2 3 2 2 3 2 4 3 3 4 4 3 5" , "3" , "Smoke test case 7")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 2 3 2 4 2 7 2 8" , "1" , "Smoke test case 8")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 1 1 1 2 1 3 1 4 2 2 2 5 3 3 4 3" , "3" , "Smoke test case 9")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 2 3 2 4 2 7 3 8" , "2" , "Smoke test case 10")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 1 2 1 1 2 2" , "2" , "Smoke test case 11")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 1 0" , "1" , "Boundary test case 1")
	defaultSuite.add(testCase)
	
	return defaultSuite

def printInput():
	suite = getTests()
	print(suite.count)
	output=""
	input=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		input = input+suite.instances[i].inputStr +"\n"
		print(suite.instances[i].inputStr)
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		