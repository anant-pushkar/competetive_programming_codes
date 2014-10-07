'''
Project name : Facial_Keypoints_Detection
Created on : Fri Sep 26 17:07:59 2014
Author : Anant Pushkar
http://www.kaggle.com/c/facial-keypoints-detection/data
'''
import sys
from sklearn.linear_model import LinearRegression
import csv
import data_io
train = data_io.DataReader("training.csv")
print "getting faces"
faces = data_io.get_image(train.get(["Image"]))

f = data_io.features[0]
print "getting",f
feature_val = data_io.get_pt(train.get([f]))
est = LinearRegression()
est.fit(faces , feature_val)
avg = []

for f in data_io.features:
	avg.append(sum(data_io.get_pt(train.get([f])))/len(feature_val))
	break
print "avg",avg

print "training data extracted"

test = data_io.DataReader("test.csv")
test_faces = data_io.get_image(test.get(["Image"]))

print "test faces extracted"

target = data_io.DataReader("IdLookupTable.csv")
target_list = data_io.get_image(target.get(["RowId","ImageId","FeatureName"]))
predicted   = est.predict(test_faces)

val = []
for data in predicted:
	val.append(data)
	for v in avg[1::]:
		val.append(data/avg[0]*v)

submission = open("data/submission.csv","w")
submission.write("RowId,ImageId,FeatureName,Location\n")

print "starting prediction"
for i in len(val):
	print "predicting",(",".join(target_list[i]))
	submission.write((",".join(target_list[i])) + 
					"," + 
					str(val[i]) + 
					"\n")
submission.close()

