/*
Project name : Printer_Queue
Created on : Fri Aug  1 17:55:30 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PQUEUE/
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
struct compare_job{
	bool operator()(const pair<int,int> &p1 , const pair<int,int> &p2){
		return p1.first<p2.first;
	}
};
class Solver{
	int n , m;
	queue<pair<int,int> > job_q;
	vector<bool> lookup;
	priority_queue<pair<int,int> , vector<pair<int,int> > , compare_job> pq;
public:
	Solver(int a , int b):
	n(a),
	m(b),
	lookup(vector<bool>(a , false)){
		int p;
		pair<int,int> job;
		for(int i=0;i<n;++i){
			scanf("%d",&p);
			job = make_pair(p,i);
			job_q.push(job);
			pq.push(job);
		}
	}
	int solve(){
		int time = 0;
		pair<int,int> job;
		while(!job_q.empty()){
			job = job_q.front();
			job_q.pop();
			
			while(lookup[pq.top().second]){
				pq.pop();
			}
			
			if(job.first>=pq.top().first){
				++time;
				if(job.second==m){
					break;
				}
				if(debug)cout<<"Doing "<<job.first<<" "<<job.second<<endl;
				lookup[job.second] = true;
			}else{
				if(debug)cout<<"Pushing "<<job.first<<" "<<job.second<<endl;
				job_q.push(job);
			}
		}
		return time;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n , m;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d",&n,&m);
		Solver s(n,m);
		printf("%d\n",s.solve());
	}
	
	return 0;
}

