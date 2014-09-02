/*
Project name : Red_John_is_Back
Created on : Fri Jul 25 14:01:20 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/red-john-is-back

1 1
2 1
3 1
4 2
5 3
6 4
f(n) = f(n-1) + f(n-4)
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
	int n;
	lld m;
	lld get_prime_count(){
		if(m<2){
			return 0;
		}
		lld count=1;
		vector<bool> lookup(m+1,false);
		for(lld i=3;i<=m;i+=2){
			if(!lookup[i]){
				++count;
				for(lld j=2*i;j<=m;j+=i){
					lookup[j]=true;
				}
			}
		}
		return count;
	}
public:
	Solver(int num):
	n(num){
		lld a=1 , b=1 , c=1 , d=2 , next;
		switch(n){
			case 1:
				m=1;
				break;
			case 2:
				m=1;
				break;
			case 3:
				m=1;
				break;
			case 4:
				m=2;
				break;
			default:
				for(int i=5;i<=n;++i){
					next = d+a;
					a=b;
					b=c;
					c=d;
					d=next;
				}
				m = d;
				break;
		}
	}
	lld solve(){
		return get_prime_count();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%lld\n",s.solve());
	}
	return 0;
}

