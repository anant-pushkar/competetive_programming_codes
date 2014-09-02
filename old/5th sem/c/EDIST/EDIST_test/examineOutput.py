import color_console as cons
import testCases
import sys
import os
import re
import time
from time import gmtime, strftime
from tkinter import *
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
	
def draw(cmd):
	print(cmd)
	cmd=cmd.split()
	if cmd[0]=="point":
		x=int(cmd[1])
		y=int(cmd[2])
		width=3
		color="black"
		txt=""
		if len(cmd)>3 :
			width=int(cmd[3])
			if len(cmd)>4:
				color=cmd[4]
		canvas.create_oval(int((x+width)*r), 
						int((y+width)*r),
						int((x-width)*r), 
						int((y-width)*r) , 
						fill=color)
	if cmd[0]=="txt":
		x=int(cmd[1])
		y=int(cmd[2])
		txt=cmd[3]
		if len(cmd)>4:
			fill=cmd[4]
		canvas.create_text(int(x*r), 
							int(y*r), 
							text=txt)
	if cmd[0]=="line":
		x1=int(cmd[1])
		y1=int(cmd[2])
		x2=int(cmd[3])
		y2=int(cmd[4])
		color="black"
		if len(cmd)>5:
			color=cmd[5]
		canvas.create_line(int(x1*r),
						int(y1*r),
						int(x2*r),
						int(y2*r),
						fill=color) 
	canvas.bind('<Button-1>', lambda event:
		print(event.x/r,",",event.y/r)
	)

expected  = getExpectedOutput()
inputCache= getInputCache()
actual=[]
for i in range(len(expected)):
	inputStr=sys.stdin.readline()
	if len(inputStr)==0 : 
		break
	actual.append(inputStr)
default_colors = cons.get_text_attr()
cons.set_text_attr(cons.FOREGROUND_GREEN | cons.BACKGROUND_GREY)
resultArr=["green"]*len(expected)
if len(expected)<=len(actual):
	l=len(expected)
else:
	l=len(actual)
	print("Input Received is of shorter size than expected.Did you miss some test case?")
	print("Expected ",len(expected)," responses")
	print("Got ",len(actual)," responses")
for i in range(l):
	if expected[i][0]=="$":
		print("Showing graphical test")
		root = Tk()
		root.title("Graphical Testing tool");    
		canvas = Canvas(width=500, height=500, bg='white')  
		canvas.pack(expand=YES, fill=BOTH)
		cmd=actual[i].split("|")
		max=0
		for j in range(len(cmd)):
			inst=cmd[j].split(" ")
			if int(inst[1])>max:
				max=int(inst[1])
			if int(inst[2])>max:
				max=int(inst[2])
		r=300/max
		for j in range(len(cmd)):
			draw(cmd[j])
		mainloop()
		break
	elif expected[i][0]=="?":
		expected[i]=expected[i].replace('?','')
		pre_colors = cons.get_text_attr()
		cons.set_text_attr(cons.FOREGROUND_MAGENTA | cons.BACKGROUND_GREY)
		resultArr[i]="yellow"
		print("Input: ",inputCache[i])
		print("Expected: ",expected[i])
		print("Got: ",actual[i])
		cons.set_text_attr(pre_colors)
		break
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
		break
	for j in range(len(expected[i])):
		if expected[i][j]!=actual[i][j]:
			cons.set_text_attr(cons.FOREGROUND_RED | cons.BACKGROUND_GREY)
			print(getDescription(i))
			resultArr[i]="red"
			print("Input: ",inputCache[i])
			print("Expected: ",expected[i])
			print("Got: ",actual[i])
			break
cons.set_text_attr(default_colors) 		
if testCases.getTests().archiving == 1:
	print("Generating Report.")
	reportStr="<h1>"+testCases.getTests().description+"</h1><table border='2'><tr style='background:blue'><th width='100'>Input</th><th width='100'>Expected Output</th><th width='100'>Output Received</th></tr>"
	for i in range(len(expected)):
		reportStr=reportStr+"<tr style='background:"+resultArr[i]+"'><td>"+inputCache[i]+"</td><td>"+expected[i]+"</td><td>"+actual[i]+"</td></tr>"
	reportStr=reportStr+"</table><br>Report generated at "+strftime("%Y-%m-%d %H:%M:%S", gmtime())
	print("Report Generated.\nUse view_report to view latest report.\nTo view all report go to test_archive directory.")
	f=open("test_archive/"+str(time.time())+".html" , "w+")#temporary cache file to store expected output
	f.write(reportStr)
	f.close()
print("End of test.");
cons.set_text_attr(default_colors) 

