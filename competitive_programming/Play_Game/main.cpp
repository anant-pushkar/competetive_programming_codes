/*
Project name : Play_Game
Created on : Fri Jul 25 14:29:59 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/play-game
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
	vector<int> brick , best_move;
	vector<lld> max_score;
	lld get_max_score(int index){
		return index>=0 && index<n ? max_score[index] : 0;
	}
	int get_best_move(int index){
		return index>=0 && index<n ? best_move[index] : 0;
	}
	inline lld get_max(lld a , lld b , lld c){
		return a>b ? a>c ? a : c : b>c ? b : c;
	}
	inline int get_move(lld a , lld b , lld c){
		return a>b ? a>c ? 1 : 3 : b>c ? 2 : 3;
	}
	void preprocess(){
		max_score[n-1] = brick[n-1];
		best_move[n-1] = 1;
		
		max_score[n-2] = max_score[n-1] + brick[n-2];
		best_move[n-2] = 2;
		
		max_score[n-3] = max_score[n-2] + brick[n-3];
		best_move[n-3] = 3;
		
		lld score[3] , extra;
		for(int i=n-4;i>=0;--i){
			extra = 0;
			for(int j=0;j<3;++j){
				extra += brick[i+j];
				score[j] = get_max_score(i+j+1+get_best_move(i+j+1)) + extra;
			}
			max_score[i] = get_max(score[0] , score[1] , score[2]);
			best_move[i] = get_move(score[0] , score[1] , score[2]);
		}
	}
public:
	Solver(int num):
	n(num),
	brick(vector<int>(num)),
	best_move(vector<int>(num)),
	max_score(vector<lld>(num)){
		for(int i=0;i<n;++i){
			scanf("%d",&brick[i]);
		}
	}
	lld solve(){
		lld soln;
		if(n<=3){
			soln  = brick[0];
			for(int i=1;i<n;++i){
				soln += brick[i];
			}
			return soln;
		}
		preprocess();
		return max_score[0];
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
		printf("%lld\n",s.solve());
	}
	
	return 0;
}

