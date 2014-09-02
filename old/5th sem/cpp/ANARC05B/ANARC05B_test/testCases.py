import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("13 3 5 7 9 20 25 30 40 55 56 57 60 62 11 1 4 7 11 14 25 44 47 55 57 100" , "450" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 -5 100 1000 1005 3 -12 1000 1001" , "2100" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 1 2 3 4 4 5 6 7 8 " , "26" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 1 2 3 4 4 11 22 22 33" , "88" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 1 2 3 4 1 1100" , "1100" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 1 2 3 4 3 3 7 10 " , "23" , "Smoke test case 6")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("4 -30 -20 -10 10 4 -100 -80 -60 -30" , "-30" , "Smoke test case 7")
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
	print("0");
	input=input+"0\n"
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		