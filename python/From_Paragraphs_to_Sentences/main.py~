'''
Project name : From_Paragraphs_to_Sentences
Created on : Sun Jul 27 15:00:30 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/from-paragraphs-to-sentences
'''
import sys
import re
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
text = str(raw_input())
sentence_list = re.split("\?|!" , text)
for sentence in sentence_list:
	debug(sentence+"\n--------------\n")
	if "." in sentence:
		start = 0
		end   = sentence.index(".")
		while end<len(sentence):
			debug("Start:"+str(start)+" end:"+str(end)+"\n\n")
			debug("segment : \n"+sentence[start:end])
			debug("end-1 : "+sentence[end-1]+"\nend-2:"+sentence[end-2]+"\n\n")
			if sentence[end-1]!=sentence[end-1].upper() and sentence[end-2]!=sentence[end-2].upper():
				while (sentence[start]==" "  or sentence[start]=="\t"):
					start += 1
				print sentence[start:end+1]
				start = end+1
				while start>=len(sentence) and (sentence[start]==" "  or sentence[start]=="\t"):
					start += 1
			if not "." in sentence[end+1:]:
				break
			end += sentence[end+1:].index(".")+1
