/*
Project name : NOCHANGE
Created on : Tue Dec 24 21:40:52 2013
Author : Anant Pushkar
http://www.spoj.com/problems/NOCHANGE/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long int lld;
bool debug=false;
int x,k,v[5];
vector<lld> mem;
lld recurse(int val , vector<int> coinCount){
	if(debug){
		cout<<"called at "<<val<<" with count vector : ";
		for(int i=0;i<k;++i)cout<<coinCount[i]<<" ";
		cout<<endl;
	}
	if(val<0){
		if(debug)cout<<"returning with val 0"<<endl;
		return 0;
	}
	if(mem[val]!=-1){
		if(debug)cout<<"returning with memoized val "<<mem[val]<<endl;
		return mem[val];
	}
	
	++coinCount[0];
	lld count=recurse(val-v[0],coinCount);
	--coinCount[0];
	
	for(int i=1;i<k;++i)if(coinCount[i-1]>coinCount[i]){
		++coinCount[i];
		count+=recurse(val-v[i],coinCount);
		--coinCount[i];
	}
	
	mem[val]=count;
	if(debug)cout<<"returning with calculated val "<<count<<endl;
	return mem[val];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d",&x);
	scanf("%d",&k);
	for(int i=0;i<k;++i)scanf("%d",&v[i]);
	mem=vector<lld>(x+1,-1);
	mem[0]=1;
	
	if(recurse(x,vector<int>(k,0))!=0)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}

