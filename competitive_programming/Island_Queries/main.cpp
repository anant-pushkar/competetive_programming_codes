/*
Project name : Island_Queries
Created on : Sun Oct  5 18:06:02 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/csindia14-er2/challenges/island-queries
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
int n,q;
vector<int> p;
vector<bool> colored;
void swap(int v1,int v2){
	for(int i=0;i<n;++i){
		if(p[i]==v1){
			p[i] = v2;
		}else if(p[i]==v2){
			p[i] = v1;
		}
	}
}
int get_count(int x){
	for(int i=0;i<n;++i)if(p[i]==x){
		colored[i] = true;
	}
	int count=0 , i=0;
	while(i<n){
		if(colored[i]){
			++count;
			while(i<n && colored[i]){
				++i;
			}
		}else{
			++i;
		}
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>n>>q;
	p=vector<int>(n);
	colored = vector<bool>(n,false);
	for(int i=0;i<n;++i){
		cin>>p[i];
	}
	
	int type,v1,v2,x;
	while(q--){
		cin>>type;
		switch(type){
			case 1:
				cin>>v1>>v2;
				swap(v1,v2);
				colored = vector<bool>(n,false);
				break;
			case 2:
				cin>>x;
				cout<<get_count(x)<<endl;
				break;
		}
	}
	return 0;
}

