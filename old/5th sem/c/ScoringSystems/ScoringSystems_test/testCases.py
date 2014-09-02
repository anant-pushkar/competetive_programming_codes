import testTemplate
import random
import functools
def getTests():
	
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("2 1 2 2 3" , "Equivalent" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 1 2 2 2" , "Not Equivalent" , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3 30 50 20 49 50 1" , "Equivalent" , "Smoke test case 3")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3 250 500 1000 300 600 900" , "Not Equivalent" , "Smoke test case 4")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("10 6 6 6 6 6 8 8 8 8 8 5 5 5 5 5 7 7 7 7 7 " , "Not Equivalent" , "Smoke test case 4")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("6 200 50 500 1000 30 30 200 100 600 900 30 30" , "Not Equivalent" , "Smoke test case 5")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("6 200 50 500 1000 80 80 200 100 600 900 80 80" , "Not Equivalent" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	return defaultSuite

def printInput():
	suite = getTests()
	'''
	comment or uncomment this part according to need
	'''
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
	
		
		
		
		