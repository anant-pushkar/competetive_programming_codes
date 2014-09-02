import testTemplate
import random
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("1" , "0" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2" , "0" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3" , "0" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4" , "1" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("5" , "0" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("6" , "0" , "Smoke test case 6")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7" , "1" , "Smoke test case 7")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8" , "1" , "Smoke test case 8")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("9" , "0" , "Smoke test case 9")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10" , "0" , "Smoke test case 10")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("49" , "3" , "Smoke test case 11")
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
	
		
		
		
		