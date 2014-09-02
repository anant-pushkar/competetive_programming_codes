import testTemplate
import random
import functools
n=random.randint(3,10)
m=random.randint(2,5)
lookup=[0]*n
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	
	for j in range(m):
		a=random.randint(0,n-2)
		b=random.randint(a+1,n-1)
		for i in range(a,b+1):
			lookup[i] = (lookup[i]+1)%2
		count=0
		c=random.randint(0,n-2)
		d=random.randint(c+1,n-1)
		for i in range(c,d+1):
			count+=lookup[i]
		testCase     = testTemplate.testInstance("0 "+str(a)+" "+str(b)+" 1 "+str(c)+" "+str(d), str(count) , "#"+str(j))
		defaultSuite.add(testCase)
		
	return defaultSuite
	
def printInput():
	suite = getTests()
	#print(suite.count)
	print(n," ",2*m)
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
	
		
		
		
		