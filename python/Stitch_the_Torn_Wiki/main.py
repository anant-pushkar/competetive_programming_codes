'''
Project name : Stitch_the_Torn_Wiki
Created on : Sun Jul 27 17:49:54 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/stitch-the-torn-wiki
'''
import sys
import nltk
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

def get_context(txt):
	#return [token[0].lower() for token in nltk.pos_tag(nltk.word_tokenize(txt)) if token[1].startswith("NN")]
	return [token.lower() for token in nltk.word_tokenize(txt) if token[0]==token[0].upper() or len(token)>2]

def match_context(txt , context):
	freq = dict([(word,0) for word in context])
	txt_context = get_context(txt)
	for word in txt_context:
		if word in context:
			freq[word] = 1
	count = 0
	for word in context:
		count += freq[word]
	return count

T = int(raw_input())
A = range(T)
context = range(T)
for t in xrange(T):
	A[t] = str(raw_input())
	context[t] = get_context(A[t])
	
s = str(raw_input())
B = range(T)
for t in xrange(T):
	B[t] = str(raw_input())
	max_val=0
	max_index=-1
	for i in xrange(T):
		val = match_context(B[t],context[i])
		if val>max_val:
			max_val = val
			max_index = i+1
	print max_index

