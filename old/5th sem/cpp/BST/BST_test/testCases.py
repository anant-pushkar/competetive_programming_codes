import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Smoke Test Suite")
	testCase     = testTemplate.testInstance("1" , "0" , "Should return zero for emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 3 val1" , "1" , "Should add an element return size(1) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 2 val2" , "2" , "Should add an element return size(2) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 4 val3" , "3" , "Should add an element return size(3) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 1 val4" , "4" , "Should add an element return size(4) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 5 val5" , "5" , "Should add an element return size(5) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 6 val6" , "6" , "Should add an element return size(6) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3 6" , "5" , "Should delete and element return size(5) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("4 2" , "val2" , "Should return value of key.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("5" , "val4" , "Should return value of  minimum amongst keys of nodes.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("6" , "val5" , "Should return value of maximum amongst values of nodes.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("7 4" , "val1" , "Should return value of floor of key")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("8 3" , "val3" , "Should return value of ceiling of key")
	defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("2" , "?should be in range[3,4)" , "Open test case 1")
	#defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("0" , "~.*Exiting .*" , "Must exit on -1")
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
	f=open("expectedOutput.txt" , "w+")#temporary cache file to store expected output
	f.write(output)
	f.close()
	
	f=open("inputCache.txt" , "w+")#temporary cache file to store intput
	f.write(input)
	f.close()
	
	return
	
		
		
		
		