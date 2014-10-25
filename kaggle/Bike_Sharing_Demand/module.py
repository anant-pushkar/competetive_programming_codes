'''
Project name : Bike_Sharing_Demand
Module name  : {module}
Created on : Sat Oct 25 21:45:28 2014
Author : Anant Pushkar
http://www.kaggle.com/c/bike-sharing-demand/data
'''
import numpy as np
import matplotlib.pyplot as plt
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
x_feature = "Elevation"
y_feature = "Aspect"
plt.scatter(data.get([x_feature]) , 
			data.get([y_feature]) , 
			c=data.get(["Cover_Type"]), alpha=0.5)
plt.colorbar(ticks=range(6) , format = formatter)
plt.xlabel(x_feature)
plt.ylabel(y_feature)
plt.show()
