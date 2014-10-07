/*
Project name : Working_with_boxes
Created on : Sat Sep 27 18:51:15 2014
Author : Anant Pushkar
11
6 5

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
int n , t ;
vector<int> w;
int get_next_p(int n){
	if( (n&(n-1)) ==0 ){
		return n;
	}	
	int m = n;
	while((m&(m-1))!=0){
		m = m&(m-1);
	}
	return m<<1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	scanf("%d %d",&n,&t);
	w = vector<int>(n);
	
	for(int i=0;i<n;++i){
		scanf("%d",&w[i]);
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	if(n==2){
		int val = (w[0]+w[1]-t);
		cout<<(val>0 ? val : 0)<<endl;
		return 0;
	}
	sort(w.begin() , w.end());
	lld sum=0 , extra=0;
	for(int i=0;i<n;++i){
		sum += w[i];
	}
	int next_p = get_next_p(n) , m = next_p , h=0;
	while(m!=0){
		++h;
		m = m>>1;
	}
	int count = next_p - n;
	for(int i=n-1;count>0;--i){
		extra += w[i];
		--count;
	}
	
	lld wt = h*(h-1)/2 , c_wt = next_p-1 -( next_p==n ? 0 : (n-(next_p>>1)));
	lld time = sum*wt - h*extra;
	lld c = (time-t)/c_wt + ((time-t)%c_wt==0 ? 0 : 1);
	if(debug){
		cout<<"h:"<<h<<" next_p:"<<next_p<<" c_wt:"<<c_wt<<" time:"<<time<<" t:"<<t<<endl;
	}
	cout<<c<<endl;
	
	
	return 0;
}

