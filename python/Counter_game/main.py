'''
Project name : Counter_game
Created on : Sat Aug  9 09:55:46 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def previous_pow(x):
	p=1
	x = x>>1
	while x>0:
		p = p<<1;
		x = x>>1;
	return p
def first_win(x):
	if x==1 or x==4:
		return False
	elif x==2 or x==3:
		return True
	
	if (x&(x-1))==0:
		return not first_win(x>>1)
	return not first_win(x - previous_pow(x))

T = int(raw_input())
for t in xrange(T):
	n = long(raw_input())
	print "Louise" if first_win(n) else "Richard"
