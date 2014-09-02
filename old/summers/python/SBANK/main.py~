from collections import defaultdict
T = int(input())
for t in range(T):
	n = int(input())
	arr = range(n)
	for i in range(n):
		[ctrl , bank , id1 , id2 , id3 , id4] = [long(x) for x in str(raw_input()).split(" ") if x!=""]
		arr[i] = id4 + id3*(10**4) + id2*(10**8) + id1*(10**12) + bank*(10**16) + ctrl*(10**24)
	freq = defaultdict(int)
	
	for acc in arr:
		freq[str(acc).zfill(26)] = freq[str(acc).zfill(26)] + 1
	
	for (key,val) in sorted(freq.items()):
		print key[0:2] , key[2:10] , key[10:14] , key[14:18] , key[18:22] , key[22:26] , val
	c = raw_input()
	print c

