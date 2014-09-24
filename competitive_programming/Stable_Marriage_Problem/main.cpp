/*
Project name : Stable_Marriage_Problem
Created on : Wed Sep 24 16:32:57 2014
Author : Anant Pushkar
http://www.spoj.com/problems/STABLEMP/
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
	vector<int> match;
	vector<queue<int> > proposals;
	vector<queue<int> > pref_m ;
	vector<vector<int> > pref_w;
	void run_proposals(){
		for(int i=0;i<n;++i){
			proposals[pref_m[i].front()].push(i);
		}
	}
	bool is_perfect(){
		for(int i=0;i<n;++i){
			if(proposals[i].size()!=1){
				return false;
			}
		}
		return true;
	}
	void judge_match(){
		queue<int> q;
		
		int best;
		for(int i=0;i<n;++i){
			best = INT_MAX;
			while(!proposals[i].empty()){
				best = best>pref_w[i][proposals[i].front()] ? pref_w[i][proposals[i].front()] : best;
				q.push(proposals[i].front());
				proposals[i].pop();
			}
			while(!q.empty()){
				if(best != pref_w[i][q.front()]){
					pref_m[q.front()].pop();
				}
				q.pop();
			}
		}	
	}
	void get_match(){
		while(true){
			run_proposals();
			if(is_perfect()){
				break;
			}
			judge_match();
		}
		for(int i=0;i<n;++i){
			match[proposals[i].front()] = i+1;
		}
	}
public:
	Solver(int x):
	n(x),
	match(vector<int>(n)),
	proposals(vector<queue<int> >(n)),
	pref_m(vector<queue<int> >(x)),
	pref_w(vector<vector<int> >(x , vector<int>(x))){
		int k , index;
		for(int i=0;i<n;++i){
			scanf("%d",&k);
			--k;
			for(int j=0;j<n;++j){
				scanf("%d",&index);
				--index;
				pref_w[k][index] = j;
			}
		}
		for(int i=0;i<n;++i){
			scanf("%d",&k);
			--k;
			for(int j=0;j<n;++j){
				scanf("%d",&index);
				--index;
				pref_m[k].push(index);
			}
		}
	}
	void print_soln(){
		get_match();
		for(int i=0;i<n;++i){
			cout<<i+1<<" "<<match[i]<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		s.print_soln();
	}
	
	return 0;
}


