'''
Project name : Appleman_and_Card_Game
Created on : Tue Aug 26 19:54:40 2014
Author : Anant Pushkar

'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
[n,k] = [int(x) for x in str(raw_input()).split(" ")]
cards = str(raw_input())
freq  = [0 for i in xrange(26)]
for c in cards:
	freq[ord(c)-ord('A')] += 1
freq.sort()

index = n-1
val   = 0
while index>-1 and freq[index]<=k : 
	debug("Adding "+str(freq[index]))
	val += freq[index]*freq[index];
	k   -= freq[index];
	index -= 1;

if index>-1:
	val += freq[index]*k;

print val
