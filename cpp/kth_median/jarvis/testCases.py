import testTemplate 
import random

class customTester(testTemplate.testInstance):
	
	def test(self,txt,ref):
		return float(txt) == float(ref)

def getTests():
	tests = []
	
	suite=testTemplate.testSuite("Sample Test Suite1",print_count=True)
	for x in xrange(4000):
		n1 = random.randint(1,50)
		n2 = random.randint(1,50)
		
		a1 = []
		a2 = []
		for i in xrange(n1):
			n = random.randint(1,1000000)
			a1.append(n)
		for i in xrange(n2):
			n = random.randint(1,1000000)
			a2.append(n)
		
		a1.sort()
		s1 = " ".join([str(a) for a in a1])
		a2.sort()
		s2 = " ".join([str(a) for a in a2])
		
		arr = a1+a2
		arr.sort();
		k = random.randint(1,len(arr)-1)
		m = arr[k-1] 
		
		testcase = customTester(str(n1)+" "+str(n2)+" "+str(k)+"\n"+s1+"\n"+s2 , str(m) , "sample#"+str(x))
		suite.add(testcase)
	tests.append(suite)
	
	return tests


