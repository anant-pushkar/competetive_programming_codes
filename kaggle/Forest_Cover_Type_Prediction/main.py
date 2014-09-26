'''
Project name : Forest_Cover_Type_Prediction
Created on : Fri Sep 26 05:22:57 2014
Author : Anant Pushkar
https://www.kaggle.com/c/forest-cover-type-prediction/data?train.csv.zip
'''
import sys
from sklearn.ensemble import RandomForestClassifier
import csv
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
		train_data[i] = [
				int(data[0]) if data[0].isdigit() else -1,
				int(data[1]) if data[1].isdigit() else -1,
				int(data[2]) if data[2].isdigit() else -1,
				int("".join(data[3:7]) , 2),
				int("".join(data[7::]) , 2)
			]
	return train_data

features = ["Elevation" , "Aspect" , "Slope" ]
for i in xrange(1,5):
	features.append("Wilderness_Area"+str(i))
for i in range(1,41):
	features.append("Soil_Type"+str(i))
train = DataReader("train.csv")
train_data = filter_data(train.get(features))

target = train.get(["Cover_Type"])
'''	
print features
for data in train_data:
	print data
'''

clf = RandomForestClassifier(n_estimators=10)
clf = clf.fit(train_data, target)

test = DataReader("test.csv")
p_id = test.get(["Id"])
test_data = filter_data(test.get(features))

prediction = clf.predict(test_data)
result = open("data/submission.csv","w")

result.write("Id,Cover_Type\n")
index = 0
for data in prediction:
	result.write(p_id[index][0]+","+str(data)+"\n")
	index += 1
result.close()
