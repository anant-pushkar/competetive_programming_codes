import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("7 0 1 0 0 0 3 0" , "3 1 1 2 2 3 3 3 " , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("8 0 1 0 0 0 0 4 0" , "4 1 1 2 2 3 3 4 4 " , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("8 0 0 0 0 0 0 0 0" , "4 1 1 2 2 3 3 4 4 " , "Smoke test case 3")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("4 0 0 1 0" , "1 1 1 1 1 " , "Smoke test case 4")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("4 0 0 0 3" , "-1" , "Smoke test case 5")
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
	
		
		
		
		