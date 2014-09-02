'''
Project name : A_Basic_Spell_Checker
Created on : Tue Jul 29 14:48:45 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/basic-spell-checker
'''
import re
import sys
import nltk
from collections import defaultdict
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

class SpellChecker:
	def __init__(self,filename):
		self.corpus = defaultdict(int)
		self.lim = 0
		for token in [re.sub("\*|-|\.|\(|\)|[0-9]*|\[|\]|:|#|_|'|\"|","",token.lower()) for token in nltk.word_tokenize(open(filename).read(20000))]:
		#for token in [token.lower() for token in nltk.word_tokenize(open(filename).read())]:
			if len(token)>0:
				self.corpus[token]  += 1
				if self.lim<self.corpus[token]:
					self.lim = self.corpus[token]
		#print "corpus built"
		#print self.corpus
		
		self.cost = {}
		self.cost["delete"] = 1
		self.cost["insert"] = 2
		self.cost["replace"]= 1
		self.cost["swap"]	= 1
	
	def get_edit_dist(self , start , target):
		#print start,target
		x = len(start)+1
		y = len(target)+1
		lookup = [[ 0 for i in xrange(y)] for j in xrange(x)]
		
		for i in xrange(1,x):
			lookup[i][0] = self.cost["delete"] + lookup[i-1][0]
		
		for i in xrange(1,y):
			lookup[0][i] = self.cost["insert"] + lookup[0][i-1]
		
		for i in xrange(1,x):
			check = False
			for j in xrange(1,y):
				cost_list = range(len(self.cost.keys()))
				cost_list[0] = lookup[i-1][j] + self.cost["delete"]
				cost_list[1] = lookup[i][j-1] + self.cost["insert"]
				cost_list[2] = lookup[i-1][j-1] + (self.cost["replace"] if start[i-1]!=target[j-1] else 0)
				cost_list[3] = (lookup[i-2][j-2] + self.cost["swap"]) if i>1 and j>1 and start[i-1]==target[j-2] and start[i-2]==target[j-1] else (max([x,y])+2)
				
				lookup[i][j] = min(cost_list)
				check = check or lookup[i][j]<self.closest_val
			if not check:
				return sys.intmax
		'''
		for i in xrange(x):
			print lookup[i]
		'''
		return lookup[x-1][y-1]
	
	def get_closest(self , txt):
		self.closest_val = sys.maxint
		closest_word= []
		
		for word in self.corpus:
			dist = self.get_edit_dist(word , txt)*self.lim + self.corpus[word]
			if self.closest_val>dist:
				self.closest_val = dist
				closest_word = [word]
			elif self.closest_val==dist:
				closest_word.append(word)
		
		closest_word.sort()
		return closest_word[0]
			
#'''
checker = SpellChecker("corpus.txt")

T = int(raw_input())
for t in xrange(T):
	word = str(raw_input())
	print checker.get_closest(word)
	
'''
checker = SpellChecker("dummy.txt")
print checker.get_edit_dist("cronion" , "contan")
print checker.get_edit_dist("contain" , "contan")
'''
















