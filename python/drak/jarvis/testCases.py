import testTemplate 
import os
'''

class customTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		#write test logic here

'''
def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count=True)
	for filename in os.listdir("./logs"):
		testcase = testTemplate.regexTester(filename , "?\n1" , "sample for igraph python")
		suite.add(testcase)
	tests.append(suite)
	
	return tests


