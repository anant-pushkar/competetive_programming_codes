'''
Project name : Little_Pony_and_Expected_Maximum
Created on : Fri Aug  1 21:45:21 2014
Author : Anant Pushkar

'''
import sys
import math
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
[m,n] = [float(x) for x in str(raw_input()).split(" ")]
sum = 0
for i in xrange(1,int(m)):
	sum += math.pow(float(i)/m , n)
print m - sum
