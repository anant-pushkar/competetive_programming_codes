/*
Project name : MSE06H
Created on : Mon Dec 16 12:43:33 IST 2013
http://www.spoj.com/problems/MSE06H/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
int n,m,k;
struct BIT{
	vector<int> tree;
	
	BIT(int n):
	tree(vector<int>(n+2,0)){}
	
	lld get(int i){
		lld s=0;
		while(i>0){
			s+=tree[i];
			i-=i&(-i);
		}
		return s;
	}
	
	void set(int i, lld v){
		while(i<n+2){
			tree[i]+=v;
			i+=i&(-i);
		}
	}
};
bool compare(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.first>p2.first?true:p1.first==p2.first?p1.second>p2.second:false;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int l,r,t;scanf("%d",&t);
	lld sum;
	for(int T=1;T<=t;++T){
		scanf("%d %d %d",&n,&m,&k);
		BIT tree(m);
		pair<int,int> roads[k];
		for(int i=0;i<k;++i){
			scanf("%d %d",&l,&r);
			roads[i]=make_pair(l,r);
		}
		sum=0;
		sort(roads,roads+k,compare);
		if(debug)cout<<roads[0].first<<" "<<roads[0].second<<endl;
		for(int i=0;i<k;++i){
			tree.set(roads[i].second,1);
			sum+=tree.get(roads[i].second-1);
		}
		printf("Test case %d: %lld\n",T,sum);
	}
	return 0;
}

