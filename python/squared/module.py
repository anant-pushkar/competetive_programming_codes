'''
Project name : 111...1_Squared
Module name  : {module}
Created on : Sat Sep  6 11:42:12 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GUANGGUN/
'''
def get_sum(n):
	return sum(int(x) for x in str(int("".join(["1"]*n))**2))

val = [get_sum(x) for x in xrange(1,101)]
for i in range(99):
	print val[i+1]-val[i]
