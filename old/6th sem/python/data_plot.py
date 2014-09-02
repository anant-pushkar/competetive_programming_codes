import numpy as np
import matplotlib.pyplot as plt

def data_plot(xs,arr):
	series1 = np.array(arr).astype(np.double)
	s1mask = np.isfinite(series1)

	plt.plot(xs[s1mask], series1[s1mask], linestyle='-', marker='o')

	plt.show()
x=[1,2,4,5]
y=[2,3,4,5]
data_plot(x,y)
