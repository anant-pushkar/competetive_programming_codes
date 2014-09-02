import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("1 0 3\n0 1 2" , "0" , "Smoke test")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 0 1" , "1" , "Smoke test with negative number")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 0 0\n0 0 3" , "0" , "Smoke test with negative number")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 0 3" , "2" , "Smoke test with negative number")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 3 3" , "1" , "Smoke test with negative number")
	defaultSuite.add(testCase)
	
	return defaultSuite

def printInput():
	suite = getTests()
	print("5 7")
	output=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		print(suite.instances[i].inputStr)
	f=open("expectedOutput.txt" , "w+")
	f.write(output)
	f.close()
	
	return