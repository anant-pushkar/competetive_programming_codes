import re
t=int(input())
for i in range(t):
	line=str(input())
	lat = re.match( r'\([+-]?[1-9][0-9]*((.[0-9]+,)|[,])', line, re.M|re.I)
	long= re.match( r'[+-]?[1-9][0-9]*((.[0-9]+\))|[\)])', line, re.M|re.I)
	print(lat.group())
	print(long.group())