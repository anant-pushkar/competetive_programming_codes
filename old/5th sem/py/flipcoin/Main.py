from math import log
class lookup:
	def __init__(self,n):
		self.arr=[0]*(n+2**(int(log(n,2))+1))
	
	def flip(self,l,u,index,a,b):
		#print("FLipping ",l,u)
		if index >= len(self.arr):
			return 0
		if l==u :
			#print("Changing ",index)
			self.arr[index]=self.arr[index]^1
			return (-1)**(self.arr[index]+1)
		if b<=u/2 :
			delta=self.flip(l,int((l+u)/2),2*index+1,a,b)
			self.arr[index]+=delta
			return delta
		if a>u/2 :
			delta=self.flip(int((l+u)/2)+1,u,2*index+2,a,b)
			self.arr[index]+=delta
			return delta
		delta1=self.flip(l,int((l+u)/2),2*index+1,a,int((l+u)/2))
		delta2=self.flip(int((l+u)/2)+1,u,2*index+2,int((l+u)/2)+1,b)
		self.arr[index]+=delta1+delta2
		return delta1+delta2
		
	def query(self,l,u,index,a,b):
		if index >= len(self.arr):
			return 0
		if a==l and u==b:
			return self.arr[index]
		if l==u:
			return self.arr[index]
		if b<=u/2:
			return self.query(l,int((l+u)/2),2*index+1,a,b)
		if a>u/2 :
			return self.query(int((l+u)/2)+1,u,2*index+2,a,b)
		count1=self.query(l,int((l+u)/2),2*index+1,a,int((l+u)/2))
		count2=self.query(int((l+u)/2)+1,u,2*index+2,int((l+u)/2)+1,b)
		return count1+count2
n,q=map(int,input().split())
play=lookup(n)
for x in range(q):
	op,a,b =map(int,input().split())
	if op == 0:
		play.flip(0,n-1,0,a,b)
	if op == 1:
		print( play.query(0,n-1,0,a,b) )
