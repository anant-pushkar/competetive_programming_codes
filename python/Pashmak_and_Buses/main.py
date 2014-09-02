'''
Project name : Pashmak_and_Buses
Created on : Sat Aug 23 21:48:28 2014
Author : Anant Pushkar
http://codeforces.com/contest/459/problem/C
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
[n,k,d] = [int(x) for x in str(raw_input()).split(" ")]
if n > k**d:
	print -1
else:
	child = [range(d) for i in xrange(n)]
	arr = 0
	for i in xrange(n):	
		temp = arr
		for j in range(d):
			child[i][j] = temp%k + 1
			temp /= k
		arr += 1
	for j in xrange(d):	
		for i in range(n):
			print child[i][j] ,
		print ""
