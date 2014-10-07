/*
Project name : Wonder_Room
Created on : Mon Sep 29 18:59:53 2014
Author : Anant Pushkar
http://codeforces.com/contest/466/problem/B
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
lld get_min(lld a , lld b){
	return a<b ? a : b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld a , b;
	lld n;
	cin>>n>>a>>b;
	
	lld s = get_min(a,b);
	lld x = a+b-s;
	lld e = 6*n+1;
	lld m = (s+e)/2;
	while(e>s+1){
		m = (s+e)/2;
		if(debug)cout<<"s:"<<s<<" e:"<<e<<endl;
		if(debug)cout<<"searching : "<<m<<endl;
		if( (6*n)/m + ((6*n)%m==0 ? 0 : 1 ) <= x){
			e = m;
		}else{
			s = m;
		}
	}
	lld y = ((6*n)/s + ((6*n)%s==0 ? 0 : 1));
	y = y>x ? y : x;
	
	lld s1 = s+1 , s2 = s-1;
	s1 = s1>=get_min(a,b) ? s1 : s;
	lld y1 = ((6*n)/s1 + ((6*n)%s1==0 ? 0 : 1));
	y1 = y1>x ? y1 : x;
	
	s2 = s2>=get_min(a,b) ? s2 : s;
	lld y2 = ((6*n)/s2 + ((6*n)%s2==0 ? 0 : 1));
	y2 = y2>x ? y2 : x;
	
	if(s1*y1<s*y && s2*y2>s1*y1){
		s=s1;
		y=y1;
	}
	if(s2*y2<s*y && s1*y1>s2*y2){
		s = s2;
		y = y2;
	}
	
	cout<<s*y<<endl;
	if(s>=a && y>=b){
		cout<<s<<" "<<y<<endl;
	}else{
		cout<<y<<" "<<s<<endl;
	}
	
	return 0;
}

