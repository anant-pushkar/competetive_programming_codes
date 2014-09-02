import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	#testCase     = testTemplate.testInstance("3\n40 50 60" , "3400" , "Smoke test case 4")
	#defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("7\n60 44 33 67 9 90 34" , "6159" , "Smoke test case 5")
	#defaultSuite.add(testCase)
	return defaultSuite

def printInput():
	suite = getTests()
	#print(suite.count)
	output=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		print(suite.instances[i].inputStr)
	f=open("expectedOutput.txt" , "w+")
	f.write(output)
	f.close()
	
	return
		
		
		
		
		
		
		