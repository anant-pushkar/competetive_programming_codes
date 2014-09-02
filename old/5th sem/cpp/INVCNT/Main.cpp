/*
Project name : INVCNT
Created on : Sun Dec 15 14:08:50 IST 2013
http://www.spoj.com/problems/INVCNT/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
vector<int> arr;
int n;
long long int recurse(int start , int end){
	if(end-start<=1)return 0;
	int mid=(start+end)/2;
	long long int count=0;
	count+=recurse(start,mid);
	count+=recurse(mid,end);
	int i=start,j=mid;
	while(i<mid){
		while(j<end && arr[j]<arr[i])++j;
		count+=j-mid;
		++i;
	}
	vector<int> temp(end-start);
	int index=0;
	i=start;j=mid;
	while(i<mid && j<end){
		if(arr[i]<arr[j]){
			temp[index++]=arr[i++];
		}else{
			temp[index++]=arr[j++];
		}
	}
	while(i<mid)temp[index++]=arr[i++];
	while(j<end)temp[index++]=arr[j++];
	for(i=0;i<end-start;++i)arr[start+i]=temp[i];
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		arr=vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&arr[i]);
		printf("%lld\n",recurse(0,n));
	}
	return 0;
}

