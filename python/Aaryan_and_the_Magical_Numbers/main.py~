'''
Project name : Aaryan_and_the_Magical_Numbers
Created on : Tue Aug 26 23:43:53 2014
Author : Anant Pushkar
http://www.hackerearth.com/august-clash/algorithm/aaryan-and-the-magical-numbers-2/
'''
class Solver:
	def count(self,index,n):
		if index==len(n):
			return 0
		return self.count(index+1,n) + (6**(len(n)-index-1)) * [0,1,2,2,2,3,3,4,4,5][int(n[index])]
	
	def solve(self,n):
		return int(n) - self.count(0,n) + (1 if "2" in n or "3" in n or "5" in n or "7" in n else 0 )

T = int(raw_input())
s = Solver()
for t in xrange(T):
	n = str(raw_input())
	while not n.isdigit():
		n = str(raw_input())
	print s.solve(n)
	
	
	
