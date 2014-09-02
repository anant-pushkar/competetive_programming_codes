'''
Project name : Palindromes
Created on : Wed Aug 27 19:46:29 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PLD/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def get_hash(s):
	h = 0
	for c in s[0:k]:
		h = 10*h + ord(c)

	h_lookup = [h]
	index=0
	p = 10**(k-1)

	for c in s[k:]:
		h_lookup.append((h_lookup[-1] - ord(s[index])*p)*10 + ord(c) )
	
	return h_lookup
k = int(raw_input())
s = str(raw_input())
r = s[::-1]

h1 = get_hash(s)
h2 = get_hash(r)
h2 = h2[::-1]

count = 0
for i in range(len(h1)):
	count += 1 if h1[i] == h2[i] else 0

print count

