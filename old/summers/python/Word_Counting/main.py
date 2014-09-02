'''
Project name : Word_Counting
Created on : Tue Jun 10 14:34:22 2014
Author : Anant Pushkar
http://www.spoj.com/problems/WORDCNT/
'''
T = int(raw_input())
t=0
while t<T:
	wordlist = str(raw_input()).strip("\n\t\r").split(' ')
	if(len(wordlist)==0 or wordlist[0]==""):
		continue
	index = 0
	count = 1
	maxCount = 0
	while index<len(wordlist)-1:
		if len(wordlist[index+1])==len(wordlist[index]):
			count +=1
		else:
			count = 1
		maxCount = count if count>maxCount else maxCount
		index += 1
	print maxCount
	t += 1