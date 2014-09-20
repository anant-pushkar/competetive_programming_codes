'''
Project name : Scavenger_Hunt
Created on : Sat Sep 20 15:49:04 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SCAVHUNT/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def print_soln(key , d):
	print key
	key = d[key]
	while True:
		print key
		if ct[key]==1:
			break
		key = d[key]
	print ""

T = int(raw_input())
for t in xrange(T):
	N = int(raw_input())
	fr = {}
	to = {}
	ct = {}
	for n in xrange(N-1):
		[a,b] = str(raw_input()).split(" ")
		fr[a] = b
		to[b] = a
		if a in ct:
			ct[a] += 1
		else:
			ct[a]  = 1
		if b in ct:
			ct[b] += 1
		else:
			ct[b]  = 1
	print "Scenario #" + str(t+1) + ":"
	for key in ct:
		if ct[key] == 1 and key in fr:
			print_soln(key ,fr)
			break
	
	
