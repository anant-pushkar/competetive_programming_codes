import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Smoke Test Suite")
	testCase     = testTemplate.testInstance("1" , "0" , "Should return zero for emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 key1 val1" , "1" , "Should add an element return size(1) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 key2 val2" , "2" , "Should add an element return size(2) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 key3 val3" , "3" , "Should add an element return size(3) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 key4 val4" , "4" , "Should add an element return size(4) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 key5 val5" , "5" , "Should add an element return size(5) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3 key3" , "4" , "Should delete and element return size(4) of emptyBTree.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("4 key2" , "val2" , "Should return value of key.")
	defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("2" , "?should be in range[3,4)" , "Open test case 1")
	#defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("-1" , "~.*Exiting .*" , "Must exit on -1")
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
	
		
		
		
		