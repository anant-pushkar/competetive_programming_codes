import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	testCase     = testTemplate.testInstance("asdf afsdddsaf" , "4" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("algorithm globalism" , "4" , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("asdf qwer" , "0" , "Boundary test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("asdf asdf" , "4" , "Boundary test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("aaaa aaaa" , "4" , "Boundary test case 3")
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
	
		
		
		
		