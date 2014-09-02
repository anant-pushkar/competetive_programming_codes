'''
Project name : Help_Tohu
Created on : Sun Aug 31 18:13:07 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TOHU/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
T = int(raw_input())
for t in xrange(T):
	n = int(raw_input())
	print("%.11f" % round(0.5*(1.5-1/(float(n+1)*float(n+2))) , 11))
