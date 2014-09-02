/*
Project name : Alaska
Created on : Mon Jun 16 20:17:00 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SCPC11B/
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
const int endPos = 1422;
class Solver{
	int nStations;
	vector<int> stationPos;
public:
	Solver(int n):
		nStations(n+2),
		stationPos(vector<int>(n+2)){
			for(int i=1;i<=n;++i){
				scanf("%d",&stationPos[i]);
			}
			sort(stationPos.begin() , stationPos.begin()+n+1);
			stationPos[n+1] = 2*endPos-stationPos[n] ;
		}
	bool solve(){
		for(int i=1;i<nStations;++i){
			if(stationPos[i] > stationPos[i-1]+200){
				return false;
			}
		}
		return true;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	while(true){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		Solver s(n);
		printf("%s\n", s.solve()? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}

