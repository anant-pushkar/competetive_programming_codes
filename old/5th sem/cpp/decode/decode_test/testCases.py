import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	
	testCase     = testTemplate.testInstance("1123" , "?aabc kbc alc aaw kw" , "Should contain all these strings")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("101523" , "?jaebc jobc jaew jow" , "Should contain all these strings")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1020" , "?jt" , "Should contain all these strings")
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
	
		
		
		
		