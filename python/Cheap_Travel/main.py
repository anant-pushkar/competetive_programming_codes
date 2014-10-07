'''
Project name : Cheap_Travel
Created on : Mon Sep 29 18:47:16 2014
Author : Anant Pushkar
http://codeforces.com/contest/466/problem/A
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

[n,m,a,b] = [int(x) for x in str(raw_input()).split(" ")]
v1 = (n/m)*b + (n%m)*a
v2 = n*a
v3 = (n/m+(1 if n%m!=0 else 0))*b
print min(v1,v2,v3)
