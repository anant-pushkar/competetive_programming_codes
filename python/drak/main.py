'''
Project name : drak
Created on : Sat Nov  8 22:21:19 2014
Author : Anant Pushkar
NLP term project
'''
import sys
from  resolver import *
from DrakSuggestionsFetcher import *
from inex import *
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
		
def extract_text(path):
	logs = open("./logs/" + path,"rb").readlines()
	resolver = DrakeImmediateResolver(logs,["." , "jarvis" , "scripts" , "test"])
	
	result = {}
	result["immediate"] = resolver.get_suggestion()#["suggestion"]
	result["web"]  = resolver.get_keywords()
	return result
T = int(raw_input())
for t in xrange(T):
	filename = str(raw_input())
	text_extract = extract_text(filename)	
	print "==========Text Extraction Results ==================="
	print "Immediate Solutions : "
	for soln in text_extract["immediate"]["suggestion"]:
		print soln
		print "-------------------------------"
	print "Keywords extracted from Immediate analysis : "
	for soln in text_extract["immediate"]["keyword"]:
		print soln
		print "-------------------------------"
	print "Key words for web search : "
	print text_extract["web"]
	app = DrakSuggestionFetcher()
	web_result = []
	for keyword in text_extract["web"] + text_extract["immediate"]["keyword"]:
		web_result += app.get_suggestions(keyword, 10)
	
	print "==========Web Based Analysis Results ==================="
	print "Results from Web based analysis (not neccesarily in sorted order based on confidence value)"
	print "###########################################################"
	for result in web_result:
		print "Confidence Value : ",result.confidence
		print "----------------------------"
		print result.text
		print "###########################################################"
	
	ob = Inex()
	print "==========Information Extraction Results ==================="
	print "Final suggestion after Information Extraction : "
	print ob.processInput(web_result , False)
	print "============================"
