/*
Project name : Candies
Created on : Sat Jul 26 14:41:22 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/candies
10
2  1
4  2
2  1
6  2 
1  1 
7  2
8  3
9  3
2  1
1  1
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
	vector<int> rating;
	vector<lld> min_candies;
public:
	Solver(int num):
	n(num),
	rating(vector<int>(num)),
	min_candies(vector<lld>(num)){
		for(int i=0;i<n;++i){
			scanf("%d",&rating[i]);
		}
	}
	lld solve(){
		lld val=1;
		min_candies[0] = 1;
		for(int i=1;i<n;++i){
			if(rating[i-1]<rating[i]){
				++val;
			}else{
				val=1;
			}
			min_candies[i] = val;
		}
		
		for(int i=n-2;i>-1;--i){
			if(rating[i]>rating[i+1] && min_candies[i]<=min_candies[i+1]){
				min_candies[i] = min_candies[i+1]+1;
			}
		}
		
		lld sum=0;
		for(int i=0;i<n;++i){
			sum += min_candies[i];
		}
		
		return sum;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	printf("%lld\n",s.solve());
	
	return 0;
}

