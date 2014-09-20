'''
Project name : hack_codeforces_268
Created on : Sat Sep 20 19:54:47 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
print "50 50 0 1000"
for i in xrange(899,999,2):
	print i,i+1
	
for i in xrange(1,100,2):
	print i,i+1

