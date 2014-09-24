'''
Project name : Coeficientes
Created on : Wed Sep 24 15:09:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/COEF/
'''
import sys
import math
import operator
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

lines = str(sys.stdin.read()).splitlines()
while "" in lines: lines.remove("")
T = len(lines)/2
for t in xrange(T):
	[n,k] = [int(x) for x in lines[2*t].split(" ")]
	print math.factorial(n) / reduce(operator.mul, [math.factorial(int(x)) for x in lines[2*t+1].split(" ")], 1)
