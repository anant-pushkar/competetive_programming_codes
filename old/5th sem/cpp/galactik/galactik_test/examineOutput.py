import color_console as cons
import testCases
import sys
import os
def getExpectedOutput():
	suite = testCases.getTests()
	out=[]
	f=open("expectedOutput.txt" , "r+")
	cmd=sys.stdin
	sys.stdin=f
	for i in range(suite.count):
		out.append(input())
	sys.stdin=cmd
	f.close()
	os.remove("expectedOutput.txt")
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
default_colors = cons.get_text_attr()
cons.set_text_attr(cons.FOREGROUND_GREEN | cons.BACKGROUND_GREY)
for i in range(len(expected)):
		if expected[i]!=actual[i]:
			cons.set_text_attr(cons.FOREGROUND_RED | cons.BACKGROUND_GREY)
			print(getDescription(i))
			print("Expected: ",expected[i])
			print("Got: ",actual[i])			
print("End of test.");
cons.set_text_attr(default_colors) 

