/*
Project name : Googly_sum
Created on : Sat Aug 30 15:36:36 2014
Author : Anant Pushkar
'''
# Read input from stdin and provide input before running code

name = raw_input('What is your name?\n')
print 'Hi, %s.' % name
'''
from sets import Set
n = int(raw_input())
arr = [int(x) for x in str(raw_input()).split(" ")]


count=0
d_s = Set([])

for i in xrange(len(arr)):
	x = arr[i]
	for y in arr[0:i]:
		if x-y in d_s:
			count += 1
			break
	for y in arr[0:i+1]:
		d_s.add(x+y)

print count
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	set<int> d_s;
	lld count=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<i;++j){
			if(d_s.find(arr[i]-arr[j])!=d_s.end()){
				++count;
				break;
			}
		}
		for(int j=0;j<=i;++j){
			d_s.insert(arr[i]+arr[j]);
		}
	}
	
	printf("%lld\n",count);
	
	return 0;
}

