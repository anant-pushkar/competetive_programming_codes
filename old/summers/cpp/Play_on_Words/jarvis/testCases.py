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
	testcase = testTemplate.regexTester("2\nacm\nibm" , "The door cannot be opened." , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3\nacm\nmalform\nmouse" , "Ordering is possible." , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2\nok\nok" , "The door cannot be opened." , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("2 \nabcd \ndcba " , "Ordering is possible." , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("3 \naaa \nbbb \nccc " , "The door cannot be opened." , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 \nboko \noring \nkebo \ngoblok " , "Ordering is possible." , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("4 \nmasti \nishq \nbc \ncb " , "The door cannot be opened." , "sample7")
	suite.add(testcase)
	testcase = testTemplate.regexTester("1 \nboko" , "Ordering is possible." , "sample7")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


