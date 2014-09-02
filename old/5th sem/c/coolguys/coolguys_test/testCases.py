import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("1" , "1/1" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2" , "3/4" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3" , "5/9" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4" , "1/2" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7" , "16/49" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("13" , "37/169" , "Smoke test case 6")
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
	
		
		
		
		