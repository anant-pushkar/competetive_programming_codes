import operator as op
import functools
def nCr(n,r):
    r=min(r,n-r)
    if r==0 :return 1
    numer = functools.reduce(op.mul,range(n,n-r,-1))
    denom = functools.reduce(op.mul,range(1,r+1))
    return numer//denom
t=int(input())
for x in range(t):
#while (1):
    strN,strK=input().split()
    n=int(strN)
    k=int(strK)
    if(n==k):
        print("1")
        continue
    print(nCr(n-1,n-k))
