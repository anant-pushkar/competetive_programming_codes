'''
Project name : Favorite_Dice
Created on : Thu Jun  5 15:46:28 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FAVDICE/
'''
import math
T = int(raw_input())
lookup = [-1]*1000
lookup[1]=1
m = 1.0
val=1.0
for t in range(T):
	n = int(raw_input())
	if n<=m :
		print lookup[n]
	else:
		while m<n:
			m += 1
			val = math.pow((1-1/m),(m-1))*(val*m/(m-1)  +  (2*m-1)/((m-1)*(m-1)))
			lookup[int(m)] = val
			print m , val
		print val
print lookup