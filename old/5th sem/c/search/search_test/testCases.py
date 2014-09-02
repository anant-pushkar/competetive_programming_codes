import testTemplate
import random
import functools
def val(a,token):
	return ((token+100-a)%100)*a
def getTests():
	defaultSuite = testTemplate.testSuite("Default Test Suite")
	'''
	testCase     = testTemplate.testInstance("1 10 1 2 3 4 5 6 7 8 9 10" , "Array object successfully created" , "Creation of Array object.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 7" , "Key successfully found at 6" , "COrrect search")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 11" , "Key not found" , "Incorrect search with greater key")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("2 0" , "Key not found" , "incorrect searcvh with smaller key.")
	defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("3" , "Array object freed successfully." , "Array object freed successfully.")
	defaultSuite.add(testCase)
	'''
	len = random.randint(1,1000000);
	inputStr="1 "+str(len)+" "
	for i in range(len):
		inputStr=inputStr+str(i)+" "
	testCase     = testTemplate.testInstance(inputStr , "Array object successfully created" , "Creation of Array object.")
	defaultSuite.add(testCase)
	for i in range(830):
		n=random.randint(1,len);
		testCase     = testTemplate.testInstance("2 "+str(n) , "Key successfully found at "+str(n) , "COrrect search #"+str(i) )
		defaultSuite.add(testCase)
	testCase     = testTemplate.testInstance("5" , "Exiting programme." , "Exit condition.")
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
	
		
		
		
		