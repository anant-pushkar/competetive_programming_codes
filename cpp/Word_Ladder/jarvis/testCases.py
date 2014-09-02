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
	
	suite=testTemplate.testSuite("Sample Test Suite1" , print_count = True)
	testcase = testTemplate.regexTester("a c 3 a b c" , "2" , "sample1")
	#suite.add(testcase)
	arr = ["hot","cog","dog","tot","hog","hop","pot","dot"]
	testcase = testTemplate.regexTester("hot dog "+str(len(arr))+(" ".join(arr)) , "5" , "sample2")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


