/*
Project name : Think_I_will_Buy_Me_a_Football_Team
Created on : Sat Sep 20 15:39:29 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ANARC08G/
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
	int n;
	vector<int> debt;
	
	int c , sum , k=1;
	lld e;
	while(true){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		e = 0;
		debt = vector<int>(n , 0);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&c);
				debt[i] += c;
				debt[j] -= c;
				e += c;
			}
		}
		
		sum=0;
		for(int i=0;i<n;++i){
			sum += debt[i]>0 ? debt[i] : 0;
		}
		printf("%d. %lld %d\n",k++ , e , sum);
	}
	return 0;
}

