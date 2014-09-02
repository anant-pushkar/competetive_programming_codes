import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite",1)
	testCase     = testTemplate.testInstance("1 10" , "1 10 20" , "Smoke test case 1")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("100 200" , "100 200 125" , "Smoke test case 2")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("201 210" , "201 210 89" , "Smoke test case 3")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("900 1000" , "900 1000 174" , "Smoke test case 4")
	defaultSuite.add(testCase)
	'''
	for n in range(1):
		a=random.randint(1,500000)
		b=random.randint(500000,1000000)
		max=-1
		for i in range(a,b+1):
			if max < ans(i):
				max= ans(i)
		testCase   = testTemplate.testInstance(str(a)+" "+str(b) , str(a)+" "+str(b)+" "+str(max+1) , "Randomized Boundary test #"+str(n))
		defaultSuite.add(testCase)
	'''
	return defaultSuite

def ans(n):
	count=0;
	while n!=1:
		if(n%2==0):
			n=n/2
		else:
			n=3*n+1
		count=count+1
	return count
	
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
	
		
		
		
		