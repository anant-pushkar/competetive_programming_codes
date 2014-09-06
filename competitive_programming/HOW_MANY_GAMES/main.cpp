/*
Project name : HOW_MANY_GAMES
Created on : Sat Sep  6 17:35:26 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GAMES/
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
class Solver{
	float avg , frac_part , int_part;
	int get_gcd(int a , int b){
		if(a%b==0){
			return b;
		}
		return get_gcd(b,a%b);
	}
public:
	Solver(float f):
	avg(f){
		frac_part = modf(avg , &int_part);
	}
	int solve(){
		if(frac_part==0){
			return 1;
		}
		int gcd = get_gcd(10000 , frac_part*10000);
		return 10000/gcd;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	float avg;
	while(t--){
		scanf("%f",&avg);
		Solver s(avg);
		printf("%d\n",s.solve());
	}
	
	return 0;
}

