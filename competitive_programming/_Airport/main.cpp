/*
Project name : _Airport
Created on : Thu Oct 16 13:46:44 2014
Author : Anant Pushkar
http://codeforces.com/problemset/problem/218/B
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
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m , x ;
	scanf("%d %d",&n,&m);
	
	set<pair<int , int> > a , b;
	for(int i=0;i<m;++i){
		scanf("%d",&x);
		a.insert(make_pair(x , i ) );
		b.insert(make_pair(x , i ) );
	}
	
	llu min=0;
	pair<int,int> p;
	set<pair<int,int> >::iterator it;
	for(int i=0;i<n;++i){
		it = a.begin();
		min += it->first;
		
		p = *it;
		a.erase(it);
		if(p.first!=1){
			--p.first;
			a.insert(p);
		}
	}
	
	llu max=0;
	for(int i=0;i<n;++i){
		it = b.end();--it;
		max += it->first;
		
		p = *it;
		b.erase(it);
		if(p.first!=1){
			--p.first;
			b.insert(p);
		}
	}
	cout<<max<<" "<<min<<endl;
	
	return 0;
}

