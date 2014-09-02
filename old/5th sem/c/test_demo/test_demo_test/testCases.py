import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite",1)

	testCase     = testTemplate.testInstance("2" , "3" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3" , "3" , "Smoke test case 3")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("-2" , "0" , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("0" , "0" , "Smoke test case 4")
	defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("2\n40 60 20 " , "2400" , "Smoke test case 2")
	#defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("5\n40 60 20 9 10 " , "2870" , "Smoke test case 3")
	#defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("3\n40 50 60" , "3400" , "Smoke test case 4")
	#defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("7\n60 44 33 67 9 90 34" , "6159" , "Smoke test case 5")
	#defaultSuite.add(testCase)
	
	'''
	To add test cases with open ended expected outputs ( like those whose expected value lies within a 
	range or those where you need to manually see the output as it cannot be quantified), start the ExpectedOutput with a '?'
	'''
	#testCase     = testTemplate.testInstance("2" , "?should be in range[3,4)" , "Open test case 1")
	#defaultSuite.add(testCase)
	
	'''
	To add test cases where you want the output to match a regular expression, start the ExpectedOutput with a '~'
	'''
	#testCase     = testTemplate.testInstance("2" , "~\A\w* Cycle exists. Cycle: (\d\s)*" , "Open test case 1")
	#defaultSuite.add(testCase)
	
	'''
	Following is an example of test case generated using random numbers and bruteforce function solve
	The user can write the bruteforce function in this module and use that to automatically generate 
	as many test cases as possible.
	'''
	#length=random.randint(1,5)
	#length=10
	#arr=[]
	#input=str(length)+"\n"
	#for i in range(length):
	#	temp = random.randint(1,100)
	#	arr.append(temp)
	#for num in arr:
	#	input=input+str(num)+" "
	#output=str(solve(arr)) 
	#output=str(random.randint(1,100))
	
	#temp=random.randint(1,10)
	#testCase     = testTemplate.testInstance(str(temp), str(temp+1) , "Cross checking from soln")
	#defaultSuite.add(testCase)
	
	return defaultSuite

'''
This function controls how input and output are generated from the test suite returned by getTests()
'''
def printInput():
	suite = getTests()
	'''
	comment or uncomment this part according to need
	'''
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
	
		
		
		
		