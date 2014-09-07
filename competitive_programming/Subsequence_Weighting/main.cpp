/*
Project name : Subsequence_Weighting
Created on : Sun Sep  7 17:31:03 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/subsequence-weighting
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	vector<lld> a , w;
public:
	Solver(int x):
	n(x),
	a(vector<lld>(x)),
	w(vector<lld>(x)){
		for(int i=0;i<n;++i){
			scanf("%lld",&a[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%lld",&w[i]);
		}
	}
	lld solve(){
		map<lld,lld> mem;
		map<lld,lld>::iterator it , temp;
		
		mem[0] = 0;
		lld sum;
		bool flag;
		for(int i=0;i<n;++i){
			it  = mem.lower_bound(a[i]);
			
			--it;
			sum = w[i] + it->second ;
			
			++it;
			flag = true;
			while(it!=mem.end()){
				if(it->first==a[i] && it->second>sum){
					flag = false;
				}
				if(it->second <= sum){
					temp = it;
					++it;
					mem.erase(temp);
				}else{
					break;
				}
			}
			
			if(flag){
				mem[a[i]] = sum;
			}
		}
		
		lld max = LLONG_MIN;
		it = mem.begin();
		for(;it!=mem.end();++it){
			max = max<it->second ? it->second : max;
		}
		
		return max;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n;
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%lld\n",s.solve());
	}
	
	return 0;
}

