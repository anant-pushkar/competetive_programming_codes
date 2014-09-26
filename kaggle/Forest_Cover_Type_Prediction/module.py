'''
Project name : Forest_Cover_Type_Prediction
Module name  : {module}
Created on : Fri Sep 26 05:22:57 2014
Author : Anant Pushkar
1 - Spruce/Fir
2 - Lodgepole Pine
3 - Ponderosa Pine
4 - Cottonwood/Willow
5 - Aspen
6 - Douglas-fir
7 - Krummholz
https://www.kaggle.com/c/forest-cover-type-prediction/data?train.csv.zip
'''
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import csv
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
				arr.append(float(d[self.index_of[key]]))
			data.append(arr)
		return data




types = ["Spruce/Fir" , "Lodgepole Pine" , "Ponderosa Pine" , "Cottonwood/Willow" , "Aspen" , "Douglas-fir" , "Krummholz"]
formatter = plt.FuncFormatter(lambda i , *args : types[int(i)])
data = DataReader("train.csv")
x_feature = "Aspect"
y_feature = "Elevation"

plt.scatter(data.get([x_feature]) , 
			data.get([y_feature]) , 
			c=data.get(["Cover_Type"]), alpha=0.5)
plt.colorbar(ticks=range(6) , format = formatter)
plt.xlabel(x_feature)
plt.ylabel(y_feature)
'''
ax = plt.axes(projection="3d")
ax.scatter(data.get(["Aspect"]) , data.get(["Elevation"]) , data.get(["Slope"]) , c=data.get(["Cover_Type"]), alpha=0.5)
'''
plt.show()

