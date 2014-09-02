import  math
def multiplier(n , count):
	p=1;
	while count>0:
		p *= n
		n = n-1
		count = count-1
	return p
def getSoln( n , k):
	k = k-1 if k-1<n-k else n-k;
	return multiplier(n-1,k) / multiplier(k,k);

T = int(raw_input())
for t in range(T):
	(n,k) = (long(x) for x in str(raw_input()).split(" "))
	print getSoln(n,k)
