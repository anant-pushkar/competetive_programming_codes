'''
Project name : Jump_Game_II
Created on : Fri Oct  3 18:00:30 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/jump-game-ii/
'''
import sys
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        n = len(A)
        if n<=1:
            return 0
        max_reach = 0
        max_next = [min(i+A[i] , n-1) for i in xrange(n)]
        index = 0
        n_jumps = 0
        while index<n:
			print "At :",index
			max_reach = max(index+A[index] , max_reach)
			if max_reach>=n-1:
				return n_jumps+1
			if index==n-1:
				return n_jumps
			tmp=0
			for j in xrange(index+1 , min(max_reach+1 , n) ):
				if tmp<max_next[j]:
					tmp = max_next[j]
					index = j
				
			print "going to",index
			n_jumps += 1
        return n_jumps
s = Solution()
print s.jump([3,2,1])         
