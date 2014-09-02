'''
Project name : Deterministic_Url_and_HashTag_Segmentation
Created on : Sun Jul 27 15:43:11 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/url-hashtag-segmentation
'''
import sys
import re
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

wordlist = [word.lower() for word in  open("words.txt").read().splitlines()]
wordlist.append("is")
wordlist.append("are")
wordlist.append("was")
wordlist.append("am")
wordlist.sort(key=len)
wordlist.reverse()
	
def is_url(txt):
	return txt[0]!="#" and len(re.findall("(www\.)?.*\..*",txt))>0

def segment_txt(txt , i=0):
	if txt.replace(" ","")=="":
		return True
		
	nums = re.findall("[0-9]*\.[0-9]+",txt)
	debug("nums test: "+str(nums))
	if len(nums)>0 and nums[0]!="" and txt.startswith(str(nums[0])):
		debug(txt+" startswith "+str(nums[0]))
		word = str(nums[0])
		rest_arr = segment_txt(txt[len(word):],i+len(word))
		if rest_arr!=False:
			return [word] + (rest_arr if not rest_arr==True else [])
		return False
		
	nums = re.findall("[0-9]*",txt)
	debug("nums test: "+str(nums))
	if len(nums)>0 and nums[0]!="" and txt.startswith(str(nums[0])):
		debug(txt+" startswith "+str(nums[0]))
		word = str(nums[0])
		rest_arr = segment_txt(txt[len(word):],i+len(word))
		if rest_arr!=False:
			return [word] + (rest_arr if not rest_arr==True else [])
		return False
		
	debug("txt :"+txt)
	debug("len : "+str(len(txt)))
	count=0
	for word in wordlist:
		count += 1
		if txt.startswith(word):
			debug("appending "+word)
			rest_arr = segment_txt(txt[len(word):],i+len(word))
			if rest_arr!=False:
				return [word] + (rest_arr if not rest_arr==True else [])
	return False
	
def segment_url(txt):
	index = txt.index(".") if txt.startswith("www") else -1
	print " ".join(segment_txt(txt[index+1:index+txt[index+1:].index(".")+1]))
	#print segment_txt(txt[index+1:index+txt[index+1:].index(".")+1]),"\n\n\n"
	
def segment_hashtag(txt):
	print " ".join(segment_txt(txt[1:]))
	#print segment_txt(txt[1:]),"\n\n\n"
	
T = int(raw_input())
for t in xrange(T):
	txt = str(raw_input())
	debug("got text : "+txt)
	if is_url(txt):
		segment_url(txt)
	else:
		segment_hashtag(txt)
