/*
Project name : k_periodic_array
Created on : Tue Dec 10 04:19:12 IST 2013
http://codeforces.com/contest/371/problem/A

*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,k;cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;++i)cin>>arr[i];
	int count=0;
	for(int i=0;i<k;++i){
		int c[2];
		c[0]=0;c[1]=0;
		for(int j=i;j<n;j+=k)++c[arr[j]-1];
		int diff=c[0]>c[1]?c[1]:c[0];
		count+=diff;
	}
	printf("%d\n",count);
	return 0;
}

