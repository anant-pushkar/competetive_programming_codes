'''
Project name : Uncle_Jack
Created on : Wed Jun  4 15:23:42 2014
Author : Anant Pushkar
http://www.spoj.com/problems/UJ/
'''
import  math
T = int(raw_input())
for t in range(T):
	[k,n] = [long(x) for x in str(raw_input()).split() if x!=""]
	if n==0:
		break
	((D+1)! - 1)/n^n