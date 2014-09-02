import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	
	testCase     = testTemplate.testInstance("1" , "2" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2" , "4" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3" , "5" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4" , "8" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5" , "6" , "Smoke test case")
	defaultSuite.add(testCase)

	testCase     = testTemplate.testInstance("6" , "9" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7" , "11" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8" , "16" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("9" , "10" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10" , "12" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("11" , "13" , "Smoke test case")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("12" , "17" , "Smoke test case") 
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("13" , "14" , "Smoke test case") 
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("14" , "21" , "Smoke test case") 
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("15" , "23" , "Smoke test case") 
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
	
		
		
		
		