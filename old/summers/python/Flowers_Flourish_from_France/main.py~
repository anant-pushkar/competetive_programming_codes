'''
Project name : Flowers_Flourish_from_France
Created on : Thu Jun  5 16:37:19 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MFLAR10/
'''
while True:
	sentence = str(raw_input()).split()
	if len(sentence)==1 and sentence[0]=='*':
		break
	char     = sentence[0][0].lower()
	check    = False
	for s in sentence[1:]:
		if s[0].lower()!=char:
			print "N"
			check = True
			break
	if not check:
		print "Y"