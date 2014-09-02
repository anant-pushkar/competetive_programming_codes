import testTemplate 
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	n=10
	suite=testTemplate.testSuite("Sample Test Suite1",header=str(n),footer="e")
	for i in range(n):
		testcase = testTemplate.testInstance("f "+str(i) , "Set:"+str(i)+" , Rank:1" , "Initialisation Test on "+str(i))
		suite.add(testcase)
	
	for i in range(0,n,2):
		testcase = testTemplate.testInstance("u "+str(i)+" "+str(i+1)+"\nf "+str(i) , "Set:"+str(i+1)+" , Rank:2" , "First Union Test on "+str(i)+","+str(i+1))
		suite.add(testcase)
		
		testcase = testTemplate.testInstance("f "+str(i+1) , "Set:"+str(i+1)+" , Rank:2" , " First Parent Test on "+str(i+1))
		suite.add(testcase)
	
	for i in range(0,n-4,4):
		testcase = testTemplate.testInstance("u "+str(i)+" "+str(i+3)+"\nf "+str(i) , "Set:"+str(i+3)+" , Rank:3" , "Second Union Test on "+str(i)+","+str(i+1))
		suite.add(testcase)
		
		testcase = testTemplate.testInstance("f "+str(i+2) , "Set:"+str(i+3)+" , Rank:3" , "Second Parent Test on "+str(i+1))
		suite.add(testcase)
	
	tests.append(suite)
	
	return tests


