/*
Project name : Devu_and_his_Brother
Created on : Mon Jun 30 16:58:59 2014
Author : Anant Pushkar
http://codeforces.com/contest/439/problem/D
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
struct State{
	int index , val;
	State(int i , int v):
	index(i),
	val(v){}
}
class Solver{
	int n,m;
	vector<int> a,b;
public:
	Colver(int l1 , int l2):
	n(l1),
	m(l2),
	a(vector<int>(l1)),
	b(vector<int>(l2)){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i){
			scanf("%d",&b[i]);
		}
		sort(b.begin(),b.end());
	}
	int solve(){
		queue<State> aQ , bQ;
		queue<int> costQA , costQB;
		
		aQ.push(State(0,a[0]+1));
		costQA.push(1);
		
		bQ.push(State(b.size()-1,b[b.size()-1]-1));
		costQB.push(1);
		
		int aCost , bCost;
		while(aQ.front().val < bQ.front().val){
			aCost = aQ.front()*(aQ.index+1);
			bCost = bQ.front()*(m-bQ.index);
			
			if(aCost<bCost){
				update(aQ,costQA);
			}else{
				
			}
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m;
	scanf("%d %d",&n,&m);
	Solver s(n,m);
	return 0;
}

