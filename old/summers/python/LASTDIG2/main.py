import math
T = int(raw_input())
arr = range(10)
for a in range(10) : 
	arr[a] = range(4)
	for b in range(1,5):
		arr[a][b%4] = int(math.pow(a,b) % 10)
arr[0][0] = 0
for t in range(T):
	(a,b) = (long(x) for x in str(raw_input()).split(" "))
	if a==0 : v=0
	elif b==0 : v=1
	else : v=arr[a%10][b%4]
	print v

