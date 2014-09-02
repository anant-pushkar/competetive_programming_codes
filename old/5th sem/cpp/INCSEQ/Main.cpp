/*
Project name : INCSEQ
Created on : Mon Dec 16 14:08:06 IST 2013
http://www.spoj.com/problems/INCSEQ/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long int lld;
bool debug=false;
const int mod=5000000;
vector<int> array;
map<int,int> indexOf;
struct BIT{
	vector<lld> tree;
	BIT(int n):
	tree(vector<lld>(n+2,0)){}
	void set(int i,lld v){
		while(i<tree.size()){
			tree[i]+=v%mod;
			i+=i&(-i);
		}
	}
	lld get(int i){
		lld s=0;
		while(i>0){
			s+=tree[i]%mod;
			i-=i&(-i);
		}
		return s;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,k;scanf("%d %d",&n,&k);
	vector<int>array(n);
	for(int i=0;i<n;++i)scanf("%d",&array[i]);
	
	vector<int> temp=array;
	sort(temp.begin(),temp.end());
	
	for(int i=0;i<n;++i)if(temp[i]!=temp[i-1])indexOf[temp[i]]=i+1;
	
	vector<BIT> lookup(k+1,BIT(n+1));
	lld sum=0;
	for(int i=0;i<n;++i){
		int index=indexOf[array[i]];
		lookup[1].set(index,1);
		for(int i=2;i<=k;++i){
			lookup[i].set(index,lookup[i-1].get(index-1)%mod);
		}
	}	
	
	printf("%lld\n",lookup[k].get(n)%mod);
	return 0;
}

