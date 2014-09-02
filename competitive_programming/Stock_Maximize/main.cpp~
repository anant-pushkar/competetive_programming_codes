/*
Project name : Stock_Maximize
Created on : Fri Jul 25 14:57:38 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/stockmax
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
inline lld get_max(lld a , lld b , lld c){
	return a>b ? a>c ? a : c : b>c ? b : c;
}
class Solver{
	int n;
	vector<lld> price ;
	vector<bool> gets_better;
	void populate_next(){
		int max_val     = price[n-1];
		gets_better[n-1]= false;
		for(int i=n-2;i>-1;--i){
			if(price[i]<max_val){
				gets_better[i] = true;
			}else{
				max_val = price[i];
				gets_better[i] = false;
			}
		}
	}
public:
	Solver(int num):
	n(num),
	price(vector<lld>(num)),
	gets_better(vector<bool>(num)){
		for(int i=0;i<n;++i){
			scanf("%lld",&price[i]);
		}
	}
	lld solve(){
		populate_next();
		lld profit=0;
		int count=0;
		for(int i=0;i<n;++i){
			if(gets_better[i]){
				if(debug)cout<<"buying at "<<price[i]<<endl;
				profit -= price[i];
				++count;
			}else{
				if(debug)cout<<"selling at "<<price[i]<<endl;
				profit += count*price[i];
				count = 0;
			}
		}
		return profit;
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

