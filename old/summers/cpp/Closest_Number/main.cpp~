/*
Project name : Closest_Number
Created on : Wed Jun 18 09:45:06 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w5/challenges/closest-number
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld t , a , b , x , soln;
	double p , val;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld %lld",&a,&b,&x);
		p = pow(a,b);
		val = p-static_cast<lld>(p)%x;
		soln = val<1 ? 0  : static_cast<lld>(val);
		if(abs(soln+x-p)<abs(soln-p)){
			soln += x;
		}else if(abs(soln-x-p)<=abs(soln-p)){
			soln -= x;
		}
		printf("%lld\n",soln);
	}
	return 0;
}

