'''
Project name : titanic
Created on : Wed Sep 24 18:24:03 2014
Author : Anant Pushkar
practice project for kaggle
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
				1 if data[0]=="male" else 2,
				int(data[1]) if data[1].isdigit() else -1
			]
	return train_data

features = ["Sex" , "Age" ]
train = DataReader("train.csv")
train_data = filter_data(train.get(features))

target = train.get(["Survived"])
'''	
print features
for data in train_data:
	print data
'''

clf = RandomForestClassifier(n_estimators=10)
clf = clf.fit(train_data, target)

test = DataReader("test.csv")
p_id = test.get(["PassengerId"])
test_data = filter_data(test.get(features))

prediction = clf.predict(test_data)
result = open("data/submission.csv","w")

result.write("PassengerId,Survived\n")
index = 0
for data in prediction:
	result.write(p_id[index][0]+","+str(data)+"\n")
	index += 1
result.close()



