import testTemplate 
import random
class customTester():
	def __init__(self , inStr , str):
		self.inputStr  = inStr
		self.description = str
		self.outputStr = inStr
	
	def getInput(self):
		return self.inputStr
	
	def test(self,txt,ref):
		return int(txt) == int(ref)+1

class randomTester(testTemplate.testInstance):
	def __init__(self , dec):
		n = random.randint(1,100)
		testTemplate.testInstance.__init__(self , str(n) , str(n+1) , dec)

class passTester():
	def __init__(self , inStr , str):
		self.inputStr  = inStr
		self.description = str
		self.outputStr = "?\n2"
	
	def getInput(self):
		return self.inputStr
	
	def test(self,txt,ref):
		return int(txt) == int(ref)+1
	
def getTests():
    tests = []
	
    suite=testTemplate.testSuite("Smoke Test Suite",print_count=True)
    testcase = customTester("3" , "Test Case 1")
    suite.add(testcase)
    testcase = customTester("0" , "Test Case 2")
    suite.add(testcase)
    testcase = customTester("-1" , "Test Case 3")
    suite.add(testcase)
    tests.append(suite)
    
    suite=testTemplate.testSuite("Random Test Suite",print_count=True)
    testcase = randomTester("Test Case 1")
    suite.add(testcase)
    tests.append(suite)
    
    suite=testTemplate.testSuite("Manual Test Suite",print_count=True)
    testcase = passTester("3\n4" , "Test Case 1")
    suite.add(testcase)
    testcase = passTester("0\n1" , "Test Case 2")
    suite.add(testcase)
    testcase = passTester("-1\n3" , "Test Case 3")
    suite.add(testcase)
    testcase = testTemplate.testInstance("" , "" , "Dummy Test Case")
    suite.add(testcase)
    testcase = testTemplate.testInstance("" , "" , "Dummy Test Case")
    suite.add(testcase)
    testcase = testTemplate.testInstance("" , "" , "Test Case 3")
    suite.add(testcase)
    tests.append(suite)

    suite=testTemplate.testSuite("Boundary Test Suite",print_count=True)
    testcase = customTester("999999999" , "Test Case 1")
    suite.add(testcase)
    testcase = customTester("1000000000" , "Test Case 2")
    suite.add(testcase)
    testcase = customTester("-999999999" , "Test Case 3")
    suite.add(testcase)
    testcase = customTester("-1000000000" , "Test Case 4")
    suite.add(testcase)
    tests.append(suite)

    return tests
