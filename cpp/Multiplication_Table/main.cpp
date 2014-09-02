/*
Project name : Multiplication_Table
Created on : Fri Jul 18 10:07:59 2014
Author : Anant Pushkar
http://codeforces.com/contest/448/problem/D
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class frequency_queue{
	priority_queue<lld> pq;
	map<lld,lld> lookup;
	int count;
public:
	frequency_queue():
	count(0){
		
	}
	lld size(){
		return count;
	}
	void push(lld val){
		if(lookup.find(val)==lookup.end() || lookup[val]==0){
			lookup[val] = 1;
			pq.push(val);
		}else{
			++lookup[val];
		}
		++count;
	}
	lld top(){
		return pq.top();
	}
	void pop(){
		lld top = pq.top();
		--lookup[top];
		if(lookup[top]==0){
			pq.pop();
		}
		--count;
	}
};
class Solver{
	int n , m ;
	lld k;
	frequency_queue pq;
	bool process(lld i , lld j){
		if(pq.size()<k){
			pq.push(i*j);
		}else{
			if(i*j>pq.top()){
				return false;
			}else{
				pq.pop();
				pq.push(i*j);
			}
		}
		return true;
	}
public:
	Solver(){
		scanf("%d %d %lld",&n,&m,&k);
	}
	lld solve(){
		for(lld i=1;i<=n;++i){
			for(lld j=1;j<=m;++j){
				if(!process(i,j)){
					break;
				}
			}
		}
		return pq.top();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	Solver s;
	printf("%lld\n",s.solve());
	return 0;
}

