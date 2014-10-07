/*
Project name : Long_Road
Created on : Sun Oct  5 17:17:11 2014
Author : Anant Pushkar

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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
struct BIT{
	vector<lld> tree;
	BIT(int n):
	tree(vector<lld>(n+2,0)){}
	void set(int i,lld v){
		while(i<tree.size()){
			tree[i]+=v;
			i+=i&(-i);
		}
	}
	lld get(int i){
		lld s=0;
		while(i>0){
			s+=tree[i];
			i-=i&(-i);
		}
		return s;
	}
};
int n;
vector<int> a_arr , l_arr;
int get_max(lld index){
	--index;
	if(debug)cout<<"starting at "<<index<<endl;
	lld val=a_arr[index] , req=l_arr[index] , i=index;
	if(debug)cout<<"req:"<<req<<" val:"<<val<<endl;
	while(val>=req){
		++i;
		if(i==n){
			return n+1;
		}
		val -= req;
		val += a_arr[i];
		req  = l_arr[i];
		if(debug)cout<<"req:"<<req<<" val:"<<val<<endl;
	}
	return i+1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>n;
	
	lld v;
	a_arr = vector<int>(n);
	l_arr = vector<int>(n);
	
	for(int i=1;i<=n;++i){
		cin>>v;
		l_arr[i-1] = v;
	}
	
	for(int i=1;i<=n;++i){
		cin>>v;
		a_arr[i-1] = v;
	}
	
	lld c,d,e;
	int q,type;
	cin>>q;
	while(q--){
		cin>>type;
		switch(type){
			case 1:
				cin>>c>>d;
				a_arr[c-1] = d;
				break;
			case 2:
				cin>>e;
				cout<<get_max(e)<<endl;;
				break;
		}
	}
	return 0;
}


