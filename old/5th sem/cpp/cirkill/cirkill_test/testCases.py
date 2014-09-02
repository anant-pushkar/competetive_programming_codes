import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("4\n-1 0\n0 0\n0 1\n1 0" , "0.25" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("5\n-1 0\n0 -1\n0 0\n0 1\n1 0" , "0.4" , "Smoke test case 2")
	defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("5\n40 60 20 9 10 " , "2870" , "Smoke test case 3")
	#defaultSuite.add(testCase)
	#testCase     = testTemplate.testInstance("3\n40 50 60" , "3400" , "Smoke test case 4")
	#defaultSuite.add(testCase)
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
	
		
		
		
		