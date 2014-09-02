/*
Project name : Sherlock_and_The_Beast
Created on : Mon Jul 21 21:55:02 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/sherlock-and-the-beast
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
	int get_five(){
		if(n%3==0){
			return n;
		}else if(n%3==1){
			return n-10;
		}else{
			return n-5;
		}
	}
public:
	Solver(int num):
	n(num){
		
	}
	void print_soln(){
		int n_five = get_five();
		if(n_five<=0){
			if(n%5==0){
				for(int i=0;i<n;++i){
					printf("3");
				}
				printf("\n");
			}else{
				printf("-1\n");
			}
		}else{
			for(int i=0;i<n_five;++i){
				printf("5");
			}
			for(int i=0;i<n-n_five;++i){
				printf("3");
			}
			printf("\n");
		}
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
		s.print_soln();
	}
	return 0;
}

