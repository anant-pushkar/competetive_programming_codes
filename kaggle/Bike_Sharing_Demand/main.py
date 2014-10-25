'''
Project name : Bike_Sharing_Demand
Created on : Sat Oct 25 21:45:27 2014
Author : Anant Pushkar
http://www.kaggle.com/c/bike-sharing-demand/data
'''
import sys
from sklearn import linear_model
import csv
import numpy as np
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
class DataReader:
	def __init__(self,fname):
		data = []
		with open('data/'+fname) as csvfile:
			spamreader = csv.reader(csvfile, delimiter=',', quotechar='"')
			for row in spamreader:
				data.append(row)
		
		self.data = data[1::]
		self.index_of = {}
		index=0
		for key in data[0]:
			self.index_of[key] = index
			index += 1
	
	def get(self,keylist):
		data = []
		for d in self.data:
			arr = []
			for key in keylist:
				arr.append(d[self.index_of[key]])
			data.append(arr)
		return data

def filter_data(train_data):
	for i in xrange(len(train_data)):
		data = train_data[i]
		train_data[i] = [float(x) for x in data]
	return train_data
	
features = ["season" , "holiday" , "workingday" , "weather" , "temp" , "atemp" , "humidity" , "windspeed" ]
train = DataReader("train.csv")
train_data = filter_data(train.get(features))

target = train.get(["casual","registered"])
target = np.array(target, dtype = 'int_')
'''	
print features
for data in train_data:
	print data
'''
train_data = np.array(train_data, dtype = 'float_')
clf = linear_model.LinearRegression()
clf = clf.fit(train_data, target)

test = DataReader("test.csv")
p_id = test.get(["datetime"])
test_data = filter_data(test.get(features))
test_data = np.array(test_data, dtype = 'float_')
prediction = clf.predict(test_data)
result = open("data/submission.csv","w")

result.write("datetime,count\n")
index = 0
for data in prediction:
	val = int(data[0]+data[1])
	result.write(p_id[index][0]+","+str(val if val>0 else 0)+"\n")
	index += 1
result.close()
