import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("4 10 0 6 2 3 6 0 2 3 3 1 0 2 3 3 2 0 0 2 2 7 2 0 1 2 2 2 0 5 7 2 5 0" , "4 9" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 1 0 1 2 1 0 2 2 2 0 0 0 1 0 0 0 1 0 0" , "-1" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 5 0 1 1 1 1 0 1 1 1 1 0 1 1 1 1 1 0 9 1 9 9 0 9 1 9 1 0 9 9 9 9 9" , "3 3" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 5 0 0 0 0 0 0 0 0 0 0 5 4 5 0 6 4 6 0" , "4 0" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 7 0 5 2 3 5 0 2 3 3 1 0 2 3 3 2 0 0 2 2 7 2 0 1 2 2 2 0 5 7 2 5 0" , "6 6" , "Smoke test case 5")
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
	
		
		
		
		