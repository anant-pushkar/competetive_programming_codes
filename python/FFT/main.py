'''
Project name : FFT
Created on : Wed Aug  6 09:20:49 2014
Author : Anant Pushkar
polytnomial multiplication using FFT
'''
import sys
import cmath
import math
import numpy as np
debug_mode = len(sys.argv)>1 and sys.argv[1]=="DEBUG"
def debug(msg):
	if debug_mode:
		print msg
def fft(poly):
	n	 = len(poly)
	print poly
	if n<2:
		return poly
	if n%2==1:
		poly.append(0)
		n += 1
		
	wn = complex(cmath.cos(2*cmath.pi/float(n)) , cmath.sin(2*cmath.pi/float(n)))
	w  = 1
	
	odd  = [poly[i] for i in xrange(1 , n , 2)]
	even = [poly[i] for i in xrange(0 , n , 2)]
	
	odd_fft = fft(odd)
	even_fft= fft(even)
	sum_fft = range(n)
	
	for i in xrange(0,n/2):
		sum_fft[i]    = even_fft[i] + w*odd_fft[i]
		sum_fft[i+n/2]= even_fft[i] - w*odd_fft[i]
		
		w = w*wn
		
	return sum_fft

print [x/4 for x in fft([1 , 4 , 9 , 16])]
