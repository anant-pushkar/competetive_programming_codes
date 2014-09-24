'''
Project name : The_Ball_Game
Created on : Wed Sep 24 14:54:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/IEEEBGAM/
'''

import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
T = int(raw_input())
for t in xrange(T):
	n = float(raw_input())
	print "%.8f" % ((n-1)/n + 1/(n*(n+1)))
