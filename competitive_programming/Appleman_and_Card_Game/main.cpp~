/*
Project name : Appleman_and_Card_Game
Created on : Tue Aug 26 19:40:15 2014
Author : Anant Pushkar
http://codeforces.com/contest/462/problem/B
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int n , k;
	scanf("%d %d",&n,&k);
	string cards;
	cin>>cards;
	
	vector<int> freq(26,0);
	for(int i=0;i<n;++i){
		++freq[cards[i]-'A'];
	}
	
	if(debug){
		for(int i=0;i<n;++i)
			cout<<freq[i]<<" ";
		cout<<endl;
	}
	
	sort(freq.begin() , freq.end());
	
	if(debug){
		for(int i=0;i<n;++i)
			cout<<freq[i]<<" ";
		cout<<endl;
	}
	
	int index=25;
	lld val=0;
	while(index>-1 && freq[index]<=k){
		if(debug)cout<<"adding "<<freq[index]<<endl;
		val += static_cast<lld>(freq[index])*freq[index];
		k   -= freq[index];
		--index;
	}
	
	if(index>-1){
		val += static_cast<lld>(k)*k;
	}
	
	printf("%lld\n",val);
	
	return 0;
}

