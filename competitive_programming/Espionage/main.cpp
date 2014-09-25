/*
Project name : Espionage
Created on : Thu Sep 25 14:44:08 2014
Author : Anant Pushkar
http://www.spoj.com/problems/RPLE/
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
const int SPY = 1;
const int CIV = 2;
int n , r;
const char* judge(vector<int> &is_spy , const vector<pair<int,int> > &rel){
	for(int i=0;i<r;++i){
		if(is_spy[rel[i].first]!=CIV){
			is_spy[rel[i].first] = SPY;
		}else{
			return "spied";
		}
		
		if(is_spy[rel[i].second]!=SPY){
			is_spy[rel[i].second] = CIV;
		}else{
			return  "spied";
		}
	}
	return "spying" ;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	for(int t=1;t<=T;++t){
		scanf("%d %d",&n,&r);
		vector<int> is_spy(n , 0);
		vector<pair<int,int> > rel(r);
		for(int i=0;i<r;++i){
			scanf("%d %d",&rel[i].first , &rel[i].second);
		}
		printf("Scenario #%d: %s\n",t,judge(is_spy , rel));
	}
	
	return 0;
}

