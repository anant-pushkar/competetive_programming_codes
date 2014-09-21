'''
Project name : I_Wanna_Be_the_Guy
Created on : Sat Sep 20 18:31:04 2014
Author : Anant Pushkar
codeforces 268
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def print_soln(freq):
	for f in freq:
		if f==0:
			print "Oh, my keyboard!"
			return
	print "I become the guy."
n = int(raw_input())
freq = [0 for x in xrange(n)]
i1 = [int(x)-1 for x in str(raw_input()).split(" ")]
i2 = [int(x)-1 for x in str(raw_input()).split(" ")]
i1 = i1[1::] if i1[0]!=-1 else []
i2 = i2[1::] if i2[0]!=-1 else []
for i in i1:
	freq[i] += 1
for i in i2:
	freq[i] += 1

print_soln(freq)
