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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string a , b;
	cin>>a;
	cin>>b;
	
	int k;
	cin>>k;
	
	int x = a.size() , y = b.size();
	vector<vector<int> > dist(x+1 , vector<int>(y+1,0));
	for(int i=1;i<=x;++i){
		dist[i][0] = i*k;
	}
	for(int i=1;i<=y;++i){
		dist[0][i] = i*k;
	}
	
	int v1 , v2;
	for(int i=1;i<=x;++i){
		for(int j=1;j<=y;++j){
			v1 = dist[i-1][j-1] + (a[i-1]==b[j-1] ? 0 : abs(a[i-1]-b[j-1]));
			v2 = min(dist[i-1][j] , dist[i][j-1]) + k;
			if(debug)cout<<a[i-1]<<" "<<b[j-1]<<" "<<dist[i-1][j-1]<<" v1:"<<v1<<" v2:"<<v2<<endl;
			dist[i][j] = min(v1 , v2);
		}
	}
	if(debug){
		for(int i=0;i<=x;++i){
			for(int j=0;j<=y;++j){
				cout<<dist[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	cout<<dist[x][y]<<endl;
	
	return 0;
}

