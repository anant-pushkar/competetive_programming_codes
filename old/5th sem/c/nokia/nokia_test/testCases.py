import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("3 8" , "0" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3 9" , "0" , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 4" , "-1" , "Smoke test case 3")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("5 25" , "5" , "Smoke test case 4")
	defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("7\n60 44 33 67 9 90 34" , "6159" , "Smoke test case 5")
	#defaultSuite.add(testCase)
	
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

def printInput():
	suite = getTests()
	print(suite.count)
	output=""
	for i in range(suite.count):
		output=output+suite.instances[i].outputStr+"\n"
		print(suite.instances[i].inputStr)
	f=open("expectedOutput.txt" , "w+")
	f.write(output)
	f.close()
	
	return
	
		
		
		
		