'''
Project name : Pasha_Maximizes
Created on : Sun Aug 24 17:00:55 2014
Author : Anant Pushkar
http://codeforces.com/contest/435/problem/B
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
[a,k] = [x for x in str(raw_input()).split(" ")]
k = int(k)
l = len(a)
soln=[]
while k>0 and len(a)>0:
	s = max(a[0 : min(k,l-1)+1])
	i = a.index(s)
	soln.append(s)
	k -= i
	a = a[0:i] + a[i+1:]
soln.append(a)
print "".join(soln)
