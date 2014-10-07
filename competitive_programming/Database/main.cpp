/*
Project name : Database
Created on : Fri Sep 26 07:35:13 2014
Author : Anant Pushkar
http://www.spoj.com/problems/RPLD/
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
const char* check(const vector<pair<int,int> > &data , int n){
	vector<set<int> > lookup(n);
	
	int size = data.size() , index;
	for(int i=0;i<size;++i){
		index = data[i].first-1;
		if(lookup[index].find(data[i].second) != lookup[index].end()){
			return "impossible";
		}
		lookup[index].insert(data[i].second);
	}
	return "possible";
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	int n , r , s , c;
	vector<pair<int,int> > data;
	for(int t=1;t<=T;++t){
		scanf("%d %d",&n,&r);
		data = vector<pair<int,int> >(r);
		for(int i=0;i<r;++i){
			scanf("%d %d",&data[i].first , &data[i].second);
		}
		printf("Scenario #%d: %s\n" , t , check(data , n));
	}
	
	return 0;
}

