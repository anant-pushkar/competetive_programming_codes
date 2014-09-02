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
	
	suite=testTemplate.testSuite("Sample Test Suite1")
	testcase = testTemplate.regexTester("long_and_mnemonic_identifier" , "longAndMnemonicIdentifier" , "sample1")
	suite.add(testcase)
	testcase = testTemplate.regexTester("anotherExample" , "another_example" , "sample2")
	suite.add(testcase)
	testcase = testTemplate.regexTester("i" , "i" , "sample3")
	suite.add(testcase)
	testcase = testTemplate.regexTester("bad_Style" , "Error!" , "sample4")
	suite.add(testcase)
	testcase = testTemplate.regexTester("i_" , "Error!" , "sample5")
	suite.add(testcase)
	testcase = testTemplate.regexTester("n_e_e_r_c" , "nEERC" , "sample6")
	suite.add(testcase)
	testcase = testTemplate.regexTester("nEERC" , "n_e_e_r_c" , "sample7")
	suite.add(testcase)
	testcase = testTemplate.regexTester("longAndMnemonicIdentifier" , "long_and_mnemonic_identifier" , "sample8")
	suite.add(testcase)
	testcase = testTemplate.regexTester("c_identifier" , "cIdentifier" , "sample9")
	suite.add(testcase)
	testcase = testTemplate.regexTester("javaIdentifier" , "java_identifier" , "sample10")
	suite.add(testcase)
	tests.append(suite)
	
	return tests


