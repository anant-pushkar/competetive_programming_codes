import testTemplate
from random import randint
import functools
def count (n,k):
	count=0
	for i in range(n):
		for j in range(i+1,n):
			if (i+j+2)%k==0 :
				count=count+1
	return count
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("10 4" , "10" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("7 3" , "7" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("6 3" , "5" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("12 12" , "5" , "Smoke test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("11 11" , "5" , "Smoke test case 5")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1 1" , "0" , "Boundary test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2 2" , "0" , "Boundary test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 3" , "1" , "Boundary test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1000000000 1000000000" , "499999999" , "Boundary test case 4")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("1000000000 5" , "99999999900000000" , "Boundary test case 5")
	defaultSuite.add(testCase)
	'''
	for i in range(10):
		k=randint(1,1000)
		n=randint(k,1000000)
		testCase     = testTemplate.testInstance( str(n)+" "+str(k), str(count (n,k)) , "Random test case #"+str(i))
		defaultSuite.add(testCase)
	'''
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
	
		
		
		
		