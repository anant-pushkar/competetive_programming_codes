/*
Project name : fox_dividing_cheese
Created on : Tue Dec 10 02:45:58 IST 2013
http://codeforces.com/contest/371/problem/B

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<utility>
#include<climits>
using namespace std;
bool debug=false;
map<pair<int,int>,int> lookup;
int solve(int a, int b){
	if(debug)cout<<"called on "<<a<<","<<b<<endl;
	if(lookup.find(make_pair(a,b))!=lookup.end()){
		return lookup[make_pair(a,b)];
	}
	if(lookup.find(make_pair(b,a))!=lookup.end()){
		return lookup[make_pair(b,a)];
	}
	if(a==b){
		if(debug)cout<<"returning with 0"<<endl;
		return 0;
	}
	int c2,c3,c5,min,v1=a>b?a:b,v2=a+b-v1;
	c2=v1%2==0?solve(v1/2,v2):INT_MAX;
	c3=v1%3==0?solve(v1/3,v2):INT_MAX;
	c5=v1%5==0?solve(v1/5,v2):INT_MAX;
	min=c2<c3?c2:c3;
	min=min<c5?min:c5;
	if(min==INT_MAX || min==-1){
		lookup[make_pair(a,b)]=-1;
		lookup[make_pair(b,a)]=-1;
		if(debug)cout<<"returning with -1"<<endl;
		return -1;
	}
	lookup[make_pair(a,b)]=min+1;
	lookup[make_pair(b,a)]=min+1;
	return min+1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int a,b;scanf("%d %d",&a,&b);
	printf("%d\n",solve(a,b));
	return 0;
}


