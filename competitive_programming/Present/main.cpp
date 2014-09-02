/*
Project name : Present
Created on : Fri Aug 22 14:43:16 2014
Author : Anant Pushkar
http://codeforces.com/contest/460/problem/C
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
const lld max_val = 1000100001;
class Solver{
	int n , m , w;
	vector<int> a;
	inline int get_st(vector<int> &st , int index){
		if(index<0 || index>n-1){
			return 0;
		}
		return st[index];
	}
	bool validate(lld x){
		if(debug)cout<<"Validating "<<x<<endl;
		lld n_covers=0 , val , sum=0;
		vector<int> st(n , 0);
		
		for(int i=0;i<n;++i){
			n_covers -= get_st(st , i-w);
			val = a[i] + n_covers;
			if(val < x){
				n_covers += x - val;
				st[i] = x-val;
				sum  += x-val;
			}
			if(sum>m){
				return false;
			}
		}
		
		return true;
	}
public:
	Solver(){
		scanf("%d %d %d",&n , &m , &w);
		a = vector<int>(n);
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
	}
	lld solve(){
		lld s=0 , e = max_val , m;
		while(e!=s+1){
			m = (e+s)/2;
			if(debug)cout<<s<<","<<e<<endl;
			if(validate(m)){
				if(!validate(m+1)){
					return m;
				}
				s = m;
			}else{
				e = m+1;
			}
		}
		return s;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	Solver s;
	cout<<s.solve()<<endl;
	
	return 0;
}

