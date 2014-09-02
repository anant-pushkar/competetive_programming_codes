import testTemplate
import random
import functools
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("25114" , "6" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1111111111" , "89" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3333333333" , "1" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1201" , "1" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("17221" , "6" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("172210" , "4" , "Smoke test case 6")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1722101" , "4" , "Smoke test case 7")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("17221012" , "8" , "Smoke test case 8")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("34" , "1" , "Smoke test case 9")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("23" , "2" , "Smoke test case 10")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1017" , "2" , "Smoke test case 11")
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
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	input=input+"0\n"
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		