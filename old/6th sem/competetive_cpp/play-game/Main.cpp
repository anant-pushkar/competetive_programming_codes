/*
Project name : play-game
Created on : Sun May  4 16:43:30 2014
Author : Anant Pushkar
Hackerank April Challenge
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
const int size = 100001;
int n;
vector<int> brick;
vector<pair<int,int> > lookup;
pair<lld,int> getMax(int index){
	if(debug)cout<<"Called on : "<<index<<endl;
	lld sum=0;
	if(index>n-4){
		for(int i=n-1;i>=index;--i)sum += brick[i];
		return make_pair(sum,n-index);
	}
	if(lookup[index].first!=-1)return lookup[index];
	
	pair<lld,int> m1=getMax(index+1),m2=getMax(index+2),m3=getMax(index+3);
	
	lld a = brick[index] + getMax(index+m1.second+1).first;
	lld b = brick[index] + brick[index+1] + getMax(index+m2.second+2).first;
	lld c = brick[index] + brick[index+1] + brick[index+2] + getMax(index+m3.second+3).first;
	lld d = a>b ? a>c ? a : c : b>c ? b : c;
	int id= a>b ? a>c ? 1 : 3 : b>c ? 2 : 3;
	
	if(debug)cout<<"Returning "<<d<<" at index="<<index<<endl;
	return make_pair(d,id);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	brick = vector<int>(size);
	lookup= vector<pair<int,int> >(size);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&brick[i]);
		for(int i=0;i<size;++i)lookup[i].first=-1;
		printf("%lld\n" , getMax(0).first);
		if(debug)cout<<"=========================="<<endl;
	}
	return 0;
}

