import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	
	testCase     = testTemplate.testInstance("6 65 100 70 150 56 90 75 190 60 95 68 110" , "Solution is :  (75,190)  (70,150)  (68,110)  (65,100)  (60,95)  (56,90)" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 65 100 63 93 70 150 56 90 75 190 60 95 68 110" , "Solution is :  (75,190)  (70,150)  (68,110)  (65,100)  (60,95)  (56,90)" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("8 65 100 63 93 63 98 70 150 56 90 75 190 60 95 68 110" , "Solution is :  (75,190)  (70,150)  (68,110)  (65,100)  (63,98)  (63,93)  (60,95)  (56,90)" , "Smoke test case 2")
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
	
		
		
		
		