import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("6 4 2 1 3 1 4 4 1 2" , "42" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 5 2 3 4 1 " , "10" , "Smoke test case 2 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 6 2 7 4 1 2 9 8 6 " , "86" , "Smoke test case 3 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 10 6 7 2 4 2 1 1 1 6 8 8 " , "106" , "Smoke test case 4 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10 9 8 8 4 6 4 8 7 7 8 4 7 4 9 6 7 5 5 " , "487" , "Smoke test case 5 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 10 1 2 8 6 3 10 10 6 2 1 9 2 1 6 1 2 " , "228" , "Smoke test case 6 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 9 9 10 7 10 10 10 5 5 4 3 3 5 5 2 1 " , "285" , "Smoke test case 7 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 9 3 10 8 1 10 7 3 5 " , "47" , "Smoke test case 8 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 7 9 1 1 1 9 1 3 9 " , "64" , "Smoke test case 9 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10 9 7 1 1 10 1 7 9 7 9 9 1 9 10 5 10 5 3 " , "406" , "Smoke test case 10 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 3 2 1 " , "3" , "Smoke test case 11 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 3 9 5 9 9 4 " , "71" , "Smoke test case 12 ")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 8 7 9 2 8 8 1 9 10 6 4 " , "161" , "Smoke test case 13 ")
	defaultSuite.add(testCase)
	
	return defaultSuite

def printInput():
	suite = getTests()
	print(suite.count,"\n")
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
	
		
		
		
		