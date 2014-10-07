'''
Project name : Text_Justification
Created on : Thu Oct  2 11:49:58 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/text-justification/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
class Solution:
	# @param words, a list of strings
	# @param L, an integer
	# @return a list of strings
	def fullJustify(self, words, L):
		lines = []
		l=0
		line  = []
		length= []
		for word in words:
			if l + len(word) <= L-len(line):
				line.append(word)
				l += len(word)
			else:
				lines.append(line)
				length.append(l)
				line = [word]
				l = len(word)
		lines.append(line)
		length.append(l)
		
		for i in xrange(len(lines)):
			if i!=len(lines)-1 and len(lines[i])!=1:
				line = lines[i]
				l    = length[i]
				n_space = L-l
				for j in xrange(1 , n_space%(len(line)-1)+1):
					line[j] = " " + line[j]
				lines[i] = (" "*(n_space/(len(line)-1))).join(line)
			else:
				lines[i] = " ".join(lines[i])
				lines[i] = lines[i] + " "*(L-len(lines[i]))
		return lines

s = Solution()
print s.fullJustify(["This", "is", "an", "example", "of", "text", "justification."] , 16)
