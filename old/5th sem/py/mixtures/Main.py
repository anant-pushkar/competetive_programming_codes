import functools
from sys import stdin
def val(a,token):
	return ((token+100-a)%100)*a
while True:
	line=stdin.readline()
	if len(line)==0 : break;
	list   = [int(i) for i in input().split()]
	total=0
	while len(list)>1:
		token   = sum([i%100 for i in list])
		element = functools.reduce(lambda a,b: a if val(a,token) < val(b,token) else b , list[1:] , list[0])
		list.remove(element)
		total  += val(element,token)
	print(total)