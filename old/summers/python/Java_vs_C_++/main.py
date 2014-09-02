'''
Project name : Java_vs_C_++
Created on : Sun May 25 12:38:49 2014
Author : Anant Pushkar
http://www.spoj.com/problems/JAVAC/
'''
import sys
import re
cpp = re.compile("^[a-z]([a-z_]*[a-z])*$")
java= re.compile("^[a-z][a-zA-Z]*$")
r = re.compile("[A-Z][a-z]*")
f = re.compile("^[a-z]*")
lines = [line for line in sys.stdin.read().splitlines() if line!=""]
for line in lines:
	if cpp.match(line) : 
		line = line.split("_")
		sys.stdout.write(line[0])
		for i in range(1,len(line)):
			sys.stdout.write(line[i].capitalize())
		sys.stdout.write("\n")
	elif java.match(line): 
		namelist = r.findall(line)
		sys.stdout.write(f.findall(line)[0])
		for name in namelist:
			 sys.stdout.write("_")
			 sys.stdout.write(name[0].lower())
			 sys.stdout.write(name[1:])
		sys.stdout.write("\n")
	else : print "Error!"