'''
Project name : MUH_and_Sticks
Created on : Fri Sep 26 21:06:12 2014
Author : Anant Pushkar
http://codeforces.com/contest/471/problem/A
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

sticks = [int(x) for x in str(raw_input()).split(" ")]
count = {}
for s in sticks:
	if s in count:
		count[s] += 1
	else:
		count[s]  = 1

freq = []
for c in count:
	freq.append(count[c])

freq.sort()

if freq[-1]<4:
	print "Alien"
elif freq[0]==2 or freq[0]==6:
	print "Elephant"
else:
	print "Bear"
