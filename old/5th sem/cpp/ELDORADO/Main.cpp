/*
Project name : ELDORADO
Created on : Mon Dec 16 16:38:17 IST 2013
http://www.spoj.com/problems/ELDORADO/

*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
typedef long long int lld;
bool debug=false;
int n,k;
vector<deque<int> > list;
vector<int> array;
lld proceed(vector<lld> &lookup,vector<lld> &arr,int l){
	if(debug){
		cout<<"called at "<<l<<endl;
		cout<<"lookup : ";
		for(int i=0;i<n;++i)cout<<lookup[i]<<" ";
		cout<<endl<<endl;
	}
	if(l==k+1){
		lld sum=0;
		for(int i=0;i<n;++i)sum+=lookup[i];
		return sum;
	}
	for(int i=0;i<n;++i){
		arr[i]=0;
		for(int j=0;j<list[i].size();++j){
			arr[i]+=lookup[list[i][j]];
		}
	}
	proceed(arr,lookup,l+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	while(1){
		scanf("%d %d",&n,&k);if(n==0 && k==0)break;
		vector<lld> lookup(n,1),arr(n,0);
		list=vector<deque<int> >(n);
		array=vector<int>(n);
		for(int i=0;i<n;++i)scanf("%d",&array[i]);
		for(int i=0;i<n;++i){
			for(int j=0;j<i;++j)if(array[j]<array[i])list[i].push_back(j);
		}
		printf("%lld\n",proceed(lookup,arr,2));
	}
	return 0;
}

