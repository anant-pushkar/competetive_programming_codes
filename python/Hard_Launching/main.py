'''
Project name : Hard_Launching
Created on : Thu Sep  4 23:27:18 2014
Author : Anant Pushkar
http://www.spoj.com/problems/RPLH/
'''
import sys
import math
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
g = 9.806
T = int(raw_input())
for t in xrange(1,T+1):
	[s,u] = [float(x) for x in str(raw_input()).split(" ")]
	if s * g/(u *u) <= 1:
		theta = 0.5 * (math.asin(s * g/(u *u)))
		print "Scenario #%d: %0.2f" % (t,theta*180/math.pi)
	else:
		print "Scenario #%d: %d" % (t,-1)
	
