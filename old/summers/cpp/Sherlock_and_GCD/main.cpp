/*
Project name : Sherlock_and_GCD
Created on : Tue Jul  1 10:27:40 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101jun14/challenges/sherlock-and-gcd
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
class Solver{
	bool areCoPrime;
	int gcd(int a,int b){
		if(a%b==0){
			return b;
		}
		return gcd(b,a%b);
	}
public:
	Solver(int n):
	areCoPrime(false){
		int a,b,c;
		scanf("%d",&a);
		for(int i=1;i<n;++i){
			scanf("%d",&b);
			if(!areCoPrime){
				if(a<b){
					a = a^b;
					b = a^b;
					a = a^b;
				}
				c = gcd(a,b);
				if(c==1){
					areCoPrime = true;
					continue;
				}
				a=b;
			}
		}
	}
	char *solve(){
		if(areCoPrime){
			return "YES";
		}
		return "NO";
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
		printf("%s\n",s.solve());
	}
	return 0;
}

