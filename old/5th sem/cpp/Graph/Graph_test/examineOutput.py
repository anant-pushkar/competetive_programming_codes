import color_console as cons
import testCases
import sys
import os
import time
import re
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

def getInputCache():
	suite = testCases.getTests()
	cache=[]
	f=open("inputCache.txt" , "r+")
	cmd=sys.stdin
	sys.stdin=f
	for i in range(suite.count):
		cache.append(input())
	sys.stdin=cmd
	f.close()
	os.remove("inputCache.txt")
	return cache
	
def getDescription(index):
	suite = testCases.getTests()
	str=suite.description+" failed at "
	str=str+suite.instances[index].description
	return str
	
expected  = getExpectedOutput()
inputCache= getInputCache()
actual=[]
timeArr=[]
for i in range(len(expected)):
    inputStr=input()
    if not inputStr:
        break
    actual.append(inputStr)
default_colors = cons.get_text_attr()
cons.set_text_attr(cons.FOREGROUND_GREEN | cons.BACKGROUND_GREY)
resultArr=["green"]*len(expected)
for i in range(len(expected)):
	timeArr.append(time.time())
	if expected[i][0]=="?":
		expected[i]=expected[i].replace('?','')
		pre_colors = cons.get_text_attr()
		cons.set_text_attr(cons.FOREGROUND_MAGENTA | cons.BACKGROUND_GREY)
		resultArr[i]="yellow"
		print("Input: ",inputCache[i])
		print("Expected: ",expected[i])
		print("Got: ",actual[i])
		cons.set_text_attr(pre_colors)
	elif expected[i][0]=="~":
		expected[i]=expected[i].replace("~","")
		matchObj=re.match(expected[i],actual[i],re.M|re.I)
		if matchObj:
			continue
		else:
			cons.set_text_attr(cons.FOREGROUND_RED | cons.BACKGROUND_GREY)
			print(getDescription(i))
			resultArr[i]="red"
			print("Input: ",inputCache[i])
			print("Expected: ",expected[i])
			print("Got: ",actual[i])
	elif expected[i]!=actual[i]:
		cons.set_text_attr(cons.FOREGROUND_RED | cons.BACKGROUND_GREY)
		print(getDescription(i))
		resultArr[i]="red"
		print("Input: ",inputCache[i])
		print("Expected: ",expected[i])
		print("Got: ",actual[i])
	
timeArr.append(time.time())	
cons.set_text_attr(default_colors) 		
if testCases.getTests().archiving == 1:
	print("Generating Report.")
	reportStr="<table border='2'><tr style='background:blue'><th width='100'>Input</th><th width='100'>Expected Output</th><th width='100'>Output Received</th><th width='100'>Time(in seconds)</th></tr>"
	for i in range(len(expected)):
		reportStr=reportStr+"<tr style='background:"+resultArr[i]+"'><td>"+inputCache[i]+"</td><td>"+expected[i]+"</td><td>"+actual[i]+"</td><td>"+str(timeArr[i+1]-timeArr[i])+"</td></tr>"
	reportStr=reportStr+"</table>"
	print("Report Generated.\nUse view_report to view latest report.\nTo view all report go to test_archive directory.")
	f=open("test_archive/"+str(time.time())+".html" , "w+")#temporary cache file to store expected output
	f.write(reportStr)
	f.close()
print("End of test.");
cons.set_text_attr(default_colors) 

