'''
Project name : Stock_Prediction
Created on : Thu Sep 25 20:49:19 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/stockprediction
'''
import sys
import numpy as np
from sklearn.linear_model import LinearRegression
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
[m,k,d] = [float(x) for x in str(raw_input()).split(" ")]
stocks  = {}
for i in xrange(int(k)):
	data = str(raw_input()).split(" ")
	
	model = LinearRegression()
	X = [[x] for x in xrange(len(data)-1) ]
	model.fit(X , [[float(x)] for x in data[1::]])
	stocks[data[0]] = [int(data[1]) , float([data[-1]][0]) , model.predict([len(data)-1])[0]]

trans = []
max_name = ""
max_diff = 0
for stock in stocks:
	name = stock
	stock = stocks[stock]
	if stock[2]<=stock[1] and stock[0]!=0:
		trans.append(name+" SELL "+str(stock[0]))
		#m += stock[0]*stock[1]
		stock[0] = 0
	else:
		diff = stock[2]-stock[1]
		if diff>max_diff and stock[1]<=m:
			max_diff = diff
			max_name = name

if max_name!="" :
	trans.append(max_name+" BUY "+str(int(m/stocks[max_name][1])))

print len(trans)
for t in trans:
	print t

