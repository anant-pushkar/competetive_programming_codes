'''
Project name : Substitutes_in_Number
Created on : Sun Sep  7 22:20:44 2014
Author : Anant Pushkar
http://codeforces.com/contest/465/problem/E
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

s = str(raw_input())
if len(s)==0:
	print 0
else:
	n = str(raw_input())
	while not n.isdigit():
		n = str(raw_input())
	n = int(n)
	while n>0:
		st = str(raw_input())
		debug("::"+st)
		while not "->" in st:
			st = str(raw_input())
			debug("::"+st)
		[sub , rep] = st.split("->")
		s = s.replace(sub , rep)
		n -= 1
	if len(s)==0:
		print 0
	else:
		x = int(s)
		print x%1000000007

