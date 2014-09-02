import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	#testCase     = testTemplate.testInstance("2 50 1 2 50 2 1" , "?0.500000000" , "Smoke test case 1")
	#defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 100 1 3 47 2 1 74 3 2" , "?0.347800000" , "Smoke test case 1")
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
	
		
		
		
		