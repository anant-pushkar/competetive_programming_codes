/*
Project name : DevuLand,_Dinosaurs_and_Laddus
Created on : Tue Oct  7 08:28:12 2014
Author : Anant Pushkar
http://www.codechef.com/OCT14/problems/PRLADDU
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n,count;
	lld cost;
	vector<int> d(100000);
	while(t--){
		scanf("%d",&n);
		queue<int> s;
		for(int i=0;i<n;++i){
			scanf("%d",&d[i]);
			if(d[i]>0){
				s.push(i);
			}
		}
		cost=0;
		for(int i=0;i<n && !s.empty();++i)if(d[i]<0){
			while(!s.empty() && d[s.front()]<=-d[i]){
				d[i] += d[s.front()];
				cost += d[s.front()]*abs(i-s.front());
				s.pop();
			}
			if(!s.empty() && d[i]!=0 && d[s.front()]>-d[i]){
				count = -d[i];
				d[i]  = 0;
				cost += count*abs(i-s.front());
				d[s.front()] -= count;
			}
		}
		printf("%lld\n",cost);
	}
	return 0;
}

