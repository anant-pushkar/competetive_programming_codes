/*
Project name : Mice_V2
Created on : Sat Sep 27 19:54:43 2014
Author : Anant Pushkar

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
class Solver{
	int n , m;
	vector<int> mouse , hole;
public:
	Solver(int a , int b):
	n(a),
	m(b),
	mouse(vector<int>(a)),
	hole(vector<int>(b)){
		for(int i=0;i<n;++i){
			scanf("%d",&mouse[i]);
		}
		sort(mouse.begin() , mouse.end());
		for(int i=0;i<m;++i){
			scanf("%d",&hole[i]);
		}
		sort(hole.begin() , hole.end());
	}
	int solve(){
		int diff , m , min=INT_MAX;
		for(int j=0;j<=m-n;++j){
			m = 0;
			for(int i=0;i<n;++i){
				diff = abs(mouse[i]-hole[i+j]);
				m = m<diff ? diff : m;
			}
			min = min>m ? m : min;
		}
		return min;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n , m;
	while(t--){
		scanf("%d %d",&n,&m);
		Solver s(n,m);
		cout<<s.solve()<<endl;
	}
	return 0;
}

