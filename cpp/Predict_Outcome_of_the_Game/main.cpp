/*
Project name : Predict_Outcome_of_the_Game
Created on : Thu Jul 24 21:55:47 2014
Author : Anant Pushkar
http://codeforces.com/contest/451/problem/C

a + b + c = k
a2 + b2 + c2 + 2ab + 2bc + 2ac = k^2

|a-b| = d1
a2 + b2 -2ab = d1^2
a = b +- d1

|b-c| = d2
b2 + c2 - 2bc = d2^2
c = b -+ d2

3b +- d1 -+ d2 = k
3b = k +- d2 -+ d1


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
	lld n , k , d1 , d2 , a , b , c;
	bool is_solvable(){
		lld max  = get_max();
		lld diff = max-a + max-b + max-c;
		lld temp = n;

		temp -= k + diff;
		return temp>=0 && temp%3 == 0;
	}	
	bool is_valid(lld x1 , lld x2){
		lld r = k - (x1%3) + (x2%3) + 3;
		if(r%3==0){
			b = ((k - x1) + x2)/3;
			a = b + x1;
			c = b - x2;
			if(a>=0 && b>=0 && c>=0){
				return is_solvable();
			}else{
				return false;
			}
		}
		return false;
	}
	bool find_wins(){
		if(is_valid(d1,d2)){
			return true;
		}
		
		if(is_valid(-d1,d2)){
			return true;
		}
			
		if(is_valid(-d1,-d2)){
			return true;
		}
			
		if(is_valid(d1,-d2)){
			return true;
		}
		return false;
	}
	inline lld get_min(){
		return a>b ? b>c ? c : b : a>c ? c : a;
	}
	inline lld get_max(){
		return a>b ? a>c ? a : c : b>c ? b : c;
	}
public:
	Solver(){
		scanf("%lld %lld %lld %lld",&n,&k,&d1,&d2);
	}
	bool solve(){
		if(n%3!=0){
			return false;
		}
		if(k==n){
			return d1==0 && d2==0;
		}
		return find_wins();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	while(t--){
		Solver s;
		printf("%s\n",s.solve() ? "yes" : "no");
	}
	return 0;
}

