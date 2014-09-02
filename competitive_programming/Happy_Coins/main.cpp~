/*
Project name : Happy_Coins
Created on : Sun Aug 31 18:03:51 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HC/'
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
	int t , n;
	scanf("%d",&t);
	
	string coin;
	int one;
	while(t--){
		scanf("%d",&n);
		one  = 0;
		while(n--){
			cin>>coin;
			if(coin=="lxh"){
				++one;
			}
		}
		printf("%s\n" , one%2==1 ? "lxh" : "hhb");
	}
	
	return 0;
}

