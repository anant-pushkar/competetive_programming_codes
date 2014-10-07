'''
Project name : Facial_Keypoints_Detection
Module name  : data_io
Created on : Fri Sep 26 17:08:44 2014
Author : Anant Pushkar
Read and extract features from csv file along with basic preprocessing
'''
import numpy as np
import matplotlib.pyplot as plt
import csv
import math

features = [
		"left_eye_center_x",
		"left_eye_center_y",
		"right_eye_center_x",
		"right_eye_center_y",
		"left_eye_inner_corner_x",
		"left_eye_inner_corner_y",
		"left_eye_outer_corner_x",
		"left_eye_outer_corner_y",
		"right_eye_inner_corner_x",
		"right_eye_inner_corner_y",
		"right_eye_outer_corner_x",
		"right_eye_outer_corner_y",
		"left_eyebrow_inner_end_x",
		"left_eyebrow_inner_end_y",
		"left_eyebrow_outer_end_x",
		"left_eyebrow_outer_end_y",
		"right_eyebrow_inner_end_x",
		"right_eyebrow_inner_end_y",
		"right_eyebrow_outer_end_x",
		"right_eyebrow_outer_end_y"
	]

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
def get_image(arr):
	img = []
	for txt in arr:
		img.append( [float(x) for x in txt[0].split(" ")] )
	return img

def get_pt(arr):
	cord = []
	avg = 0
	for pt in arr:
		cord.append(float(pt[0]) if pt[0]!="" else avg/len(cord))
		avg = avg+cord[-1] 
	return cord

def get_cord(arr):
	cord = []
	avg = [0,0]
	for pt in arr:
		cord.append([float(pt[0]) if pt[0]!="" else avg[0]/len(cord) , 
						float(pt[1]) if pt[1]!="" else avg[1]/len(cord)])
		avg = [avg[0]+cord[-1][0] , avg[1]+cord[-1][1]]
	return cord

def show_img(face , size , x=0 , y=0 , txt=""):
	img = []
	for i in xrange(size):
		img.append(face[i*size:i*size+size]) 

	fig = plt.figure(figsize=(6,6))
	fig.subplots_adjust(left=0,right=1,bottom=0,top=1,hspace=0.05,wspace=0.05)

	plt.imshow(img,cmap=plt.cm.binary,interpolation="nearest")
	plt.text(x,y,txt)
	
	plt.show()
