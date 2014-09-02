arr=[0]*100
for i in range(2,100):
	j=1 
	while j*i<=100:
		arr[i*j-1]=1-arr[i*j-1]
		j=j+1
for i in range(100):
	if arr[i]==0:
		print(i+1)
	