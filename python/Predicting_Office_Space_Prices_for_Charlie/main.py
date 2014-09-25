'''
Project name : Predicting_Office_Space_Prices_for_Charlie
Created on : Thu Sep 25 20:01:50 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/predicting-office-space-price
'''
import sys
from sklearn import linear_model
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg

[m,n] = [int(x) for x in str(raw_input()).split(" ")]
X = []
Y = []
for N in xrange(n):
	data = [float(x) for x in str(raw_input()).split(" ")]
	X.append(data[0:m])
	Y.append([data[-1]])

rgr = linear_model.LinearRegression()
rgr.fit(X,Y)

T = int(raw_input())
for t in xrange(T):
	data = [float(x) for x in str(raw_input()).split(" ")]
	print rgr.predict(data)[0]

