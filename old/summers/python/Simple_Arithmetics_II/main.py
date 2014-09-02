'''
Project name : Simple_Arithmetics_II
Created on : Sun May 25 12:03:14 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ARITH2/
'''
import re
T = int(raw_input())
for t in range(T):
	cond = True
	while cond:
		line = str(raw_input())
		try:
			ops = [x for x in re.split("1|2|3|4|5|6|7|8|9|0| ",line) if x!='']
			num = [long(x) for x in re.split("\*|\+|\-|/|=| ",line) if x != '']
			cond= False if len(num)>0 else True
		except:
			cond=True
	index = 1
	n = num[0]
	for op in ops:
		if op == "=" : print n
		else:
			m = num[index]
			if op=="*": n = n*m
			elif op=="/": n = n/m
			elif op=="+" : n = n+m
			elif op=="-" : n = n-m
			index = index+1
