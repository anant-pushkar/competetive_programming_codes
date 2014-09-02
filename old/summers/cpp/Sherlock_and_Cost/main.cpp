/*
Project name : Sherlock_and_Cost
Created on : Wed Jun 18 09:13:03 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101may14/challenges/sherlock-and-cost
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
#define MIN 1
#define MAX 2
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	vector<int> b , maxLookup , minLookup;
	int getMax(int index, int type){
		if(debug)cout<<"getMax : "<<index<<","<<type<<endl;
		if(index<0 || index>=n){
			if(debug)cout<<"out of bound"<<endl;
			return 0;
		}
		if(type==MIN && minLookup[index]!=-1){
			if(debug)cout<<"mem found : "<<minLookup[index]<<endl;
			return minLookup[index];
		}
		if(type==MAX && maxLookup[index]!=-1){
			if(debug)cout<<"mem found : "<<maxLookup[index]<<endl;
			return maxLookup[index];
		}
		int val = type==MAX ? b[index] : 1 ;
		int v1  = getMax(index+1,MAX) + (index+1<n ? abs(b[index+1]-val) : 0);
		int v2  = getMax(index+1,MIN) + (index+1<n ? abs(val-1) : 0);
		if(debug)cout<<"having values : "<<v1<<","<<v2<<endl;
		int v   = v1>v2 ? v1 : v2;
		if(type==MAX){
			if(debug)cout<<"Val with MAX at "<<index<<" : "<<v<<endl;
			maxLookup[index] = v;
		}else{
			if(debug)cout<<"Val with MIN at "<<index<<" : "<<v<<endl;
			minLookup[index] = v;
		}
		return v;
	}
public:
	Solver(int num):
		n(num),
		b(vector<int>(num)),
		maxLookup(vector<int>(num,-1)),
		minLookup(vector<int>(num,-1)){
			for(int i=0;i<n;++i){
				scanf("%d",&b[i]);
			}
		}
	int solve(){
		maxLookup[n-1] = 0;
		minLookup[n-1] = 0;
		int s1 = getMax(0,MAX) , s2 = getMax(0,MIN);
		int soln = s1>s2 ? s1 : s2;
		return soln;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%d\n",s.solve());
	}
	return 0;
}

