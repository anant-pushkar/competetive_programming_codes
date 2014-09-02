import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite",1)
	testCase     = testTemplate.testInstance("10 15 0 1 0 2 0 3 1 3 1 4 2 5 2 9 3 6 4 7 4 8 5 8 5 9 6 7 6 9 7 8" , "~\A\w* Cycle exists. Cycle: (\d\s)*" , "Graph1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("10 15 0 1 0 2 0 3 1 3 0 3 2 5 5 6 3 6 4 7 4 8 5 8 5 9 6 7 6 9 8 8" , "~\A\w* Cycle exists. Cycle: (\d\s)*" , "Graph1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("10 15 0 1 1 2 1 3 0 3 0 4 2 5 2 9 3 6 4 7 4 8 5 8 5 9 6 7 6 9 7 8" , "~\A\w* Cycle exists. Cycle: (\d\s)*" , "Graph1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("10 15 4 1 7 9 6 2 7 3 5 0 0 2 0 8 1 6 3 9 6 3 2 8 1 5 9 8 4 5 4 7" , "~\A\w* Cycle exists. Cycle: (\d\s)*" , "Graph1")
	defaultSuite.add(testCase)
	return defaultSuite

def printInput():
	suite = getTests()
	print(suite.count)
	output=""
	input=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		input = input+suite.instances[i].inputStr+"\n" 
		print(suite.instances[i].inputStr)
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		