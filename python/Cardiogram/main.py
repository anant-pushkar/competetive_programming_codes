'''
Project name : Cardiogram
Created on : Sun Aug 24 17:40:38 2014
Author : Anant Pushkar
http://codeforces.com/contest/435/problem/C
     /\     
  /\/  \    
 /      \   
/        \  
          \/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
n = int(raw_input())
a = [int (x) for x in str(raw_input()).split(" ")]
val = range(n+1)
val[0]=0

x=range(n)
x[0] = a[0]
for i in xrange(1,n):
	x[i] = x[i-1] + a[i]

v = 0
for i in xrange(n):
	if i%2==0:
		v += a[i]
	else:
		v -= a[i]
	val[i+1] = v
bottom = min(val)
top    = max(val)
h = top - bottom
val    = [y-bottom for y in val]

debug(val)
debug(x)
grid = []
for i in xrange(h+1):
	a = [" " for i in xrange(x[n-1]+1)]
	grid.append(a)
index=0
for i in xrange(n):
	c = "\\" if i%2==0 else "/"
	if i%2==0:
		debug(xrange(val[i] , val[i+1]))
		for j in xrange(val[i]-1 , val[i+1]):
			grid[j][index] = c
			index += 1
	else:
		debug(xrange(val[i] , val[i+1] , -1))
		for j in xrange(val[i]-1 , val[i+1] , -1):
			grid[j][index] = c
			index += 1
		
for i in xrange(h):
	print "".join(grid[i])

			
			
			
			
			
