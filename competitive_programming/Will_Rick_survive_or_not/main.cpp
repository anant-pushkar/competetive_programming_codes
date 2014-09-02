/*
Project name : Will_Rick_survive_or_not
Created on : Wed Aug 27 20:44:47 2014
Author : Anant Pushkar
http://www.hackerearth.com/lendingkart-hiring-challenge/algorithm/will-rick-survive-or-not-2/
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
class Solver{
	int n;
	vector<int> dist;
	int solve(){
		int extra=-1;
		for(int i=0;i<n;++i){
			dist[i] -= i;
			
			if(i%6==0){
				++extra;
			}
			dist[i] -= extra;
			
			if(dist[i]<=0){
				return i;
			}
		}
		return -1;
	}
public:
	Solver(int x):
	n(x),
	dist(vector<int>(x)){
		for(int i=0;i<n;++i){
			scanf("%d",&dist[i]);
		}
		sort(dist.begin() , dist.end());
	}
	void print_soln(){
		int kill = solve();
		if(kill<0){
			printf("Rick now go and save Carl and Judas\n");
		}else{
			printf("Goodbye Rick\n%d\n",kill);
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		s.print_soln();
	}
	
	return 0;
}

