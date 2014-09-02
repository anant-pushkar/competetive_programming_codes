/*
Project name : Bear_and_Prime_Numbers
Created on : Fri Jan 24 22:20:31 2014
Author : Anant Pushkar
codeforces 385 : C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
const int lim=10000001;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld n,a,max=0;
	cin>>n;
	
	vector<int> lookup(lim,0);
	for(int i=0;i<n;++i){
		cin>>a;
		++lookup[a];
		max=max>a?max:a;
	}
	
	vector<int> count(max+1,-1),sum(max+1,0);
	for(int i=2;i<=max;++i){
		if(count[i]==-1){
			count[i]=lookup[i];
			for(int j=2*i;j<=max;j+=i){
				count[i]+=lookup[j];
				count[j]=0;
			}
		}
		sum[i]=sum[i-1]+count[i];
	}
	
	lld s,e;
	cin>>a;
	for(int q=0;q<a;++q){
		cin>>s>>e;
		e=e>max?max:e;
		s=s>max?max+1:s;
		cout<<(sum[e]-sum[s-1])<<endl;
	}
	return 0;
}

