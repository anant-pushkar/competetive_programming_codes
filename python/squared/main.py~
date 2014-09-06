'''
Project name : 111...1_Squared
Created on : Sat Sep  6 11:42:12 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GUANGGUN/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
val = [1,3,5,7,9,11,13,15,17]
s   = sum(val)
for n in [str(x).replace("\n","")  for x in sys.stdin]:
	#print "|"+n+"|",n.isdigit()
	if n.isdigit():
		n = int(n)
		q = n/9
		r = n%9
		print s*q+sum(val[0:r])
