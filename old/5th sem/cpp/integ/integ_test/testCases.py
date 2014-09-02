import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	
	testCase     = testTemplate.testInstance("1 -1 2" , "1" , "Boundary test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 -1 1" , "1" , "Boundary test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 0 1" , "0" , "Boundary test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 3 1" , "0" , "Boundary test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2 300000000 -300000000 2" , "300000000" , "Boundary test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 -1 -2 -3 2" , "5" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 1 2 3 -5 1" , "5" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 3 -5 1" , "5" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 3 -8 1" , "8" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 9 5 4 3 1" , "0" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 3 -8 0" , "0" , "Smoke test case 6")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 3 -8 2" , "12" , "Smoke test case 7")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 3 -8 3" , "12" , "Smoke test case 8")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 1 2 -4 -3 -8 1" , "8" , "Smoke test case 9")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2 -1 -2 4" , "3" , "Sudeep test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 -3 -4 -5 -6 5" , "18" , "Sudeep test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 -3 -4 -5 -6 2" , "11" , "Sudeep test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 -3 -4 -5 -6 1" , "6" , "Sudeep test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5 0 -4 -5 -6 -7 2" , "13" , "Sudeep test case 5")
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
	
		
		
		
		