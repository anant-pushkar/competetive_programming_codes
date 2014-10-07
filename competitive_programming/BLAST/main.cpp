/*
Project name : BLAST
Created on : Fri Sep 26 07:52:27 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MBLAST/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
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
inline int get_min(int a , int b){
	return a<b ? a : b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string a , b;
	cin>>a;
	cin>>b;
	
	int k;
	cin>>k;
	
	int x = a.size() , y = b.size();
	vector<vector<int> > dist(a , vector<int>(b,0));
	for(int i=0;i<a;++i){
		dist[i][0] = get_min();
	}
	
	return 0;
}

