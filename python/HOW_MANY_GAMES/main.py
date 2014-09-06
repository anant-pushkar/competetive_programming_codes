'''
Project name : HOW_MANY_GAMES
Created on : Sat Sep  6 22:33:11 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GAMES/
'''
import sys
import math
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

def get_gcd(a,b):
	if a<b:
		[a,b] = [b,a]
	return b if a%b==0 else get_gcd(b,a%b)
T = int(raw_input())
while T>0:
	n = str(raw_input())
	if '.' in n:
		p = len(n.split('.')[1])
		n = int(n.split('.')[0])*(10**p) + int(n.split('.')[1])
		gcd = get_gcd(n , 10**p)
		print (10**p)/gcd
	elif n.isdigit():
		print 1
	else:
		T += 1
	T -= 1
		





