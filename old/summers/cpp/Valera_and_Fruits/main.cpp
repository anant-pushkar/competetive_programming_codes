/*
Project name : Valera_and_Fruits
Created on : Sun Jun 29 11:12:40 2014
Author : Anant Pushkar
http://codeforces.com/contest/441/problem/B
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
const int nDays = 3001;
typedef long long int lld;
typedef unsigned long long int llu;
inline void fetch(int &capacity , int &count , const int num){
	if(num<=capacity){
		count += num;
		capacity -= num;
	}else{
		count += capacity;
		capacity = 0;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,v,a,b;
	scanf("%d %d",&n,&v);
	vector<int> today(nDays,0) , yesterday(nDays,0);
	for(int i=0;i<n;++i){
		scanf("%d %d",&a,&b);
		today[a-1] += b;
	}
	int count=0 , capacity;
	for(int i=0;i<=nDays;++i){
		capacity = v;
		fetch(capacity,count,yesterday[i]);
		if(i!=nDays && today[i]>capacity){
			yesterday[i+1] += today[i] - capacity;
		}
		fetch(capacity,count,today[i]);
	}
	printf("%d\n",count);
	return 0;
}

