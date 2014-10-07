'''
Project name : Who_is_gonna_be_first
Created on : Sat Sep 27 19:28:07 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def is_valid(n):
	while n>0:
		if n%27==0:
			return False
		n /= 27
	return True
s = str(raw_input())
lookup = [0 for x in xrange(551880)]
for i in xrange(len(s)):
	lookup[ord(s[i])-ord('a')+1] += 1
	if i+1<len(s):
		lookup[(ord(s[i])-ord('a')+1)*27 + ord(s[i+1])-ord('a')+1] += 1
	if i+2<len(s):
		lookup[(ord(s[i])-ord('a')+1)*27*27 + (ord(s[i+1])-ord('a')+1)*27 + ord(s[i+2])-ord('a')+1] += 1
	if i+3<len(s):
		lookup[(ord(s[i])-ord('a')+1)*27*27*27 + (ord(s[i+1])-ord('a')+1)*27*27 + (ord(s[i+2])-ord('a')+1)*27 + ord(s[i+3])-ord('a')+1] += 1

for i in xrange(1,551880):
	if is_valid(i) and lookup[i]==0:
		soln = []
		while i>0:
			soln.append(chr(i%27 -1 + ord('a')))
			i /=27
		soln.reverse()
		print "".join(soln)
		break
