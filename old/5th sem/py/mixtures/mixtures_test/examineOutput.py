import testCases
import sys
def getExpectedOutput():
	suite = testCases.getTests()
	out=[]
	f=open("expectedOutput.txt" , "r+")
	cmd=sys.stdin
	sys.stdin=f
	for i in range(suite.count):
		out.append(input())
	sys.stdin=cmd
	return out

def getDescription(index):
	suite = testCases.getTests()
	str=suite.description+" failed at "
	str=str+suite.instances[index].description
	return str
	
expected = getExpectedOutput()
actual=[]
for i in range(len(expected)):
    str=input()
    if not str:
        break
    actual.append(str)
for i in range(len(expected)):
    if expected[i]!=actual[i]:
        print(getDescription(i))
        print("Expected: ",expected[i])
        print("Got: ",actual[i])
print("End of test.");
    

