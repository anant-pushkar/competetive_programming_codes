'''
Project name : _No_to_Palindromes
Created on : Sun Sep  7 21:53:24 2014
Author : Anant Pushkar
http://codeforces.com/contest/465/problem/C
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

def fastLongestPalindromes(seq):
    seqLen = len(seq)
    l = []
    i = 0
    palLen = 0
    while i < seqLen:
        if i > palLen and seq[i - palLen - 1] == seq[i]:
            palLen += 2
            i += 1
            continue
        l.append(palLen)
        s = len(l) - 2
        e = s - palLen
        for j in xrange(s, e, -1):
            d = j - e - 1
            if l[j] == d: 
                palLen = d
                break
            l.append(min(d, l[j]))
        else:
            palLen = 1
            i += 1
    l.append(palLen)
    lLen = len(l)
    s = lLen - 2
    e = s - (2 * seqLen + 1 - lLen)
    for i in xrange(s, e, -1):
        d = i - e - 1
        l.append(min(d, l[i]))
	debug("returning "+str(l))
    return max(l)

def get_val(s,p):
	val = 0
	for c in s:
		val = val*p + ord(c)-ord('a')
	return val

def get_str(val,p,n):
	s = []
	while val>0:
		s.append(str(unichr(val%p+ord('a'))))
		val /= p
	while len(s)<n:
		s.append('a')
	return "".join(s[::-1])

[n,p] = [int(x) for x in str(raw_input()).split() ]
s = str(raw_input())

val  = get_val(s,p)
val += 1
debug(str(val))
s    = get_str(val,p,n)
debug(s)
if len(s)>n:
	print "NO"
else:
	while fastLongestPalindromes(s)>1:
		val  = get_val(s,p)
		val += 1
		debug(str(val))
		s    = get_str(val,p,n)
		debug(s)
		if len(s)>n:
			s = "NO"
			break
	print s














