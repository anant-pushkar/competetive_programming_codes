arr=[0]*10000
for i in range(2,10000):
	if arr[i]==0:
		for j in range(2*i,10000):
			if j%i==0:
				arr[j]=1

for i in range(1000,10000):
	if arr[i]==0:
		print(i)