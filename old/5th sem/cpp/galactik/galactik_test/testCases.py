import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite1 = testTemplate.testSuite("Default Test Suite 1")
	testCase     = testTemplate.testInstance("6 6\n1 2\n2 3\n1 3\n4 5\n5 6\n4 6\n1\n3\n5\n2\n4\n6" , "3" , "Smoke test case 1")
	defaultSuite1.add(testCase)
	return defaultSuite1
	
	#defaultSuite2 = testTemplate.testSuite("Default Test Suite 2")
	#testCase     = testTemplate.testInstance("3 1\n2 3\n1\n-1\n-1" , "-1" , "Smoke test case 2")
	#defaultSuite2.add(testCase)
	#return defaultSuite2
	
	#Suite1 = testTemplate.testSuite("Automated Test Suite 1: Boundary Conditions")
	#testCase     = testTemplate.testInstance("6 0\n1\n3\n5\n2\n4\n6" , "???" , "Case with no bridges")
	#Suite1.add(testCase)
	#return Suite1
	
	#Suite2 = testTemplate.testSuite("Automated Test Suite 2: Boundary Conditions")
	#testCase     = testTemplate.testInstance("6 5\n1 2\n3 4\n5 6\n2 3\n4 5\n1\n1\n1\n1\n1\n1" , "0" , "Case with no teleportation")
	#Suite2.add(testCase)
	#return Suite2
	
	#testCase     = testTemplate.testInstance("2\n40 60 20 " , "2400" , "Smoke test case 2")
	#defaultSuite.add(testCase)
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
	
	#return defaultSuite

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
	
		
		
		
		