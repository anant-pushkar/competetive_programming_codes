'''
Project name : Facial_Keypoints_Detection
Module name  : {module}
Created on : Fri Sep 26 17:07:59 2014
Author : Anant Pushkar
http://www.kaggle.com/c/facial-keypoints-detection/data
'''
import numpy as np
import matplotlib.pyplot as plt
import csv
import data_io
import matplotlib.image as mpimg
from sklearn.decomposition import PCA

train = data_io.DataReader("training.csv")
faces = data_io.get_image(train.get(["Image"]))
feature_list = []

for f in data_io.features:
	feature_list.append(data_io.get_pt(train.get([f])))

