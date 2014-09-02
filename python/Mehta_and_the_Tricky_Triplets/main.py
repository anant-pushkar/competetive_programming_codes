'''
Project name : Mehta_and_the_Tricky_Triplets
Created on : Tue Aug 26 23:19:11 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
class Solver:
	def __init__(self , n):
		self.create_masks()
		for i in xrange(n):
			a = int(raw_input())
			mask = 0
			while a>0:
				mask = mask | (1<<(a%10))
				a /= 10
			for i in xrange(len(self.mask)):
				self.count[i] += 1 if ( mask & self.mask[i] )==self.mask[i] else 0
	
	def create_masks(self):
		self.mask=[]
		self.mask.append(1<<2)
		self.mask.append(1<<3)
		self.mask.append(1<<5)
		self.mask.append(1<<7)
		self.mask.append((1<<2) | (1<<3))
		self.mask.append((1<<2) | (1<<5))
		self.mask.append((1<<2) | (1<<7))
		self.mask.append((1<<3) | (1<<5))
		self.mask.append((1<<3) | (1<<7))
		self.mask.append((1<<5) | (1<<7))
		self.mask.append((1<<2) | (1<<3) | (1<<5))
		self.mask.append((1<<7) | (1<<3) | (1<<5))
		self.mask.append((1<<2) | (1<<7) | (1<<5))
		self.mask.append((1<<2) | (1<<3) | (1<<7))
		self.mask.append((1<<2) | (1<<3) | (1<<5) | (1<<7))
		self.count = [0 for i in xrange(len(self.mask))]
	
	def nC3(self,n):
		return n*(n-1)*(n-2)/6
	
	def solve(self):
		soln  = self.nC3(self.count[0]) + self.nC3(self.count[1]) + self.nC3(self.count[2]) + self.nC3(self.count[3])
		soln -= self.nC3(self.count[4]) + self.nC3(self.count[5]) + self.nC3(self.count[6]) + self.nC3(self.count[7]) + self.nC3(self.count[8]) + self.nC3(self.count[9])
		soln += self.nC3(self.count[10]) + self.nC3(self.count[11]) + self.nC3(self.count[12]) + self.nC3(self.count[13])
		soln -= self.nC3(self.count[14])
		return soln
		
n = int(raw_input())
s = Solver(n)
print s.solve()
