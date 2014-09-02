import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("50 10 12 3 15 8 16 9 16 6 10 2 21 9 18 4 12 4 17 8 18 9 \n" , "49 26" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("50 10 13 8 19 10 16 8 12 9 10 2 12 8 13 5 15 5 11 7 16 2 \n" , "48 32" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 2  6 1  5 1 \n" , "5 1" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	return defaultSuite
def printInput():
	suite = getTests()
	#print(suite.count)
	output=""
	input=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		input = input+suite.instances[i].inputStr +"\n"
		print(suite.instances[i].inputStr)
	input = input+"0 0\n"
	print("0 0\n");
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		