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
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	testcase = testTemplate.testInstance(
'''.87654321
2........
3........
4........
5........
6........
7........
8........
9........
''' , "1" , "sample1")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


