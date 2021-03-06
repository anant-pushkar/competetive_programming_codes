import re
class testInstance:
	'class to contain one test case'
	def __init__(self , inStr , outStr , str):
		self.inputStr  = inStr
		self.description = str
		self.outputStr = outStr
	
	def test(self,txt,ref):
		return ref==txt;
	
class regexTester(testInstance):
	def __init__(self , inStr , outStr , dec):
		testInstance.__init__(self , inStr , outStr , dec)
	
	def test(self,txt,ref):
		return re.match(txt,ref,re.M|re.I)
	

class testSuite:
	'test suite for adding bunch of related test cases'
	def __init__(self , str , arch=0):
		self.count       = 0
		self.description = str
		self.instances   = []
		
	def add(self , instance):
		self.instances.append(instance)
		self.count=self.count+1
