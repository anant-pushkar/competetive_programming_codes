'''
Project name : Restore_Cube
Created on : Sun Sep  7 22:37:20 2014
Author : Anant Pushkar
http://codeforces.com/contest/465/problem/D
'''
import sys
import itertools

debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def get_dist(p1 , p2):
	d = 0
	for i in xrange(3):
		d += (p1[i]-p2[i])*(p1[i]-p2[i])
	return d
def is_valid(pts):
	debug(str(pts))
	dist = {}
	for i in xrange(8):
		for j in xrange(i+1,8):
			d = get_dist(pts[i] , pts[j])
			if d in dist:
				dist[d] += 1
			else:
				dist[d]  = 1
		
	if 0 in dist or len(dist)!=3 or [dist[k] for k in dist]!=[3,3,3]:
		return False
	d = dist.keys().sort()
	return d[2]/d[0]==3 and d[1]/d[0]==2
pts = []
for x in xrange(8):
	pts.append([int(x) for x in str(raw_input()).split(" ")])

perm  = [list(itertools.permutations(pt)) for pt in pts]
val   = 0
soln = []
while val<6**8:
	new_pts = []
	temp = val
	i=0
	while len(new_pts)<8:
		new_pts.append(perm[i][temp%6])
		temp /= 6
		i+=1
	if is_valid(new_pts):
		soln = new_pts
		break
	debug(str(val))
	val += 1
if len(soln)==0:
	print "NO"
else :
	print "YES"
	for pt in soln:
		print " ".join([str(x) for x in pt])









