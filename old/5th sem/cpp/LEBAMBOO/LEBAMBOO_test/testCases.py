import testTemplate
import random
import functools
def getCount(h,d,count,lim):
	if h==d :
		return count
	if count>lim:
		return -1
	n=100000
	m=0
	for i in range(len(h)):
		h[i]=h[i]-1
		for j in range(i):
			h[i]=h[i]+1
		for j in range(i+1,len(h)):
			h[i]=h[i]+1
		m=getCount(h,d,count+1,lim)
		if n!=-1 and n>m:
			n=m
		h[i]=h[i]+1
		for j in range(i):
			h[i]=h[i]-1
		for j in range(i+1,len(h)):
			h[i]=h[i]-1
	return n
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")

	testCase     = testTemplate.testInstance("1 1 2" , "-1" , "Smoke test case 1")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("2 1 2 2 1" , "1" , "Smoke test case 2")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 3 2 2 4 5 3" , "5" , "Smoke test case 3")
	defaultSuite.add(testCase)
	
	testCase     = testTemplate.testInstance("3 41 6 8 42 7 9" , "3" , "Smoke test case 4")
	defaultSuite.add(testCase)
	'''
	for q in range(10):
		n=random.randint(1,7)
		h=[0]*n
		d=[0]*n
		input_str=str(n)+" "
		h_sum=0
		d_sum=0
		for i in range(n):
			h[i]=random.randint(1,45)
			h_sum=h_sum+h[i]
			d[i]=h[i]+random.randint(1,5)
			d_sum=d_sum+d[i]
			input_str=input_str+str(h[i])+" "
		for i in range(n):
			input_str=input_str+str(d[i])+" "
		d=1
		if n-2>0 :
			d=n-2
		testCase     = testTemplate.testInstance(input_str , str(getCount(h,d,0,int((d_sum-h_sum)/d)+1)) , "Randomized test case")
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
	
		
		
		
		