/*
Project name : Store_Credit
Created on : Tue Oct 14 12:08:31 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/351101/dashboard#s=p0
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
	int n , x;
	vector<pair<int , int> > arr;
public:
	Solver(){
		scanf("%d",&x);
		
		int val;
		scanf("%d",&n);
		arr = vector<pair<int , int> >(n);
		for(int i=0;i<n;++i){
			scanf("%d",&val);
			arr[i] = make_pair(val , i);
		}
		sort(arr.begin() , arr.end());
	}
	pair<int,int> solve(){
		int i=0 , j=n-1 , sum , a , b;
		while(i<j){
			sum = arr[i].first+arr[j].first;
			if(sum<x){
				++i;
			}else if(sum>x){
				--j;
			}else{
				a = arr[i].second+1;
				b = arr[j].second+1;
				if(a>b){
					a = a^b;
					b = a^b;
					a = a^b;
				}
				return make_pair(a,b);
			}
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	pair<int,int> soln;
	for(int t=1;t<=T;++t){
		Solver s;
		soln = s.solve();
		printf("Case #%d: %d %d\n" , t , soln.first , soln.second);
	}
	
	return 0;
}

