import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("5 7 5 2 100 3 5 80 2 3 70 2 1 50 3 4 90 4 1 85 3 1 70" , "61.200000 percent" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 8 1 2 60 2 3 30 3 7 20 2 5 50 3 6 90 1 4 50 4 5 90 5 6 90" , "7.290000 percent" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 8 1 2 40 2 3 30 3 7 20 2 5 50 3 6 60 1 4 90 4 5 80 5 6 70" , "6.048000 percent" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 8 1 2 60 2 3 10 3 7 20 2 5 50 3 6 60 1 4 60 4 5 80 5 6 90" , "5.184000 percent" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 9 1 2 40 2 3 30 3 7 20 2 5 50 3 6 60 1 4 90 4 5 80 5 6 70 1 3 90" , "18.000000 percent" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10 1 1 10 10" , "10.000000 percent" , "Boundary test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("10 2 1 5 10 5 10 10" , "1.000000 percent" , "Boundary test case 2")
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
	input=input+"0\n"
	print("0");
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		