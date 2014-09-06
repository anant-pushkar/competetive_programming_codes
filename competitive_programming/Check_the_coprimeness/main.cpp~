/*
Project name : Check_the_coprimeness
Created on : Wed Sep  3 17:07:42 2014
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
llu get_gcd(llu a , llu b){
	if(a%b==0){
		return b;
	}
	return get_gcd(b,a%b);
}
llu get_max_coprime(llu n){
	llu x=n/2;
	while(n>1){
		if(get_gcd(n,x)==1){
			return x;
		}
		--x;
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	llu n;
	while(t--){
		scanf("%llu",&n);
		printf("%llu\n",get_max_coprime(n));
	}
	
	return 0;
}

