/*
Project name : Modular_Fibonacci_Period
Created on : Thu Jul 17 14:35:15 2014
Author : Anant Pushkar
http://www.spoj.com/problems/PISANO/
f(n)   = f(n-1) + f(n-2)
	   = 2f(n-2)+ f(n-3)
f(n-1) = f(n-2) + f(n-3)

/         \   /      \   /        \
| f(n)    | = | 2 1  | * | f(n-2) |
| f(n-1)  |   | 1 1  |   | f(n-3) |
\         /   \      /   \        /

n = 2k+1
F(n) = M * F(n-2)
     = M**k * F(1)

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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	lld n;
	vector<vector<lld> > M;
	void multiply(vector<vector<lld> > &A , const vector<vector<lld> > &B){
		int size = A.size() , temp[size][size];
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j){
				temp[i][j] = 0;
				for(int k=0;k<size;++k){
					temp[i][j] += A[i][k]*B[k][j];
				}
			}
		}
		for(int i=0;i<size;++i){
			for(int j=0;j<size;++j){
				A[i][j] = temp[i][j];
			}
		}
	}
	lld gcd(lld a , lld b){
		if(a%b==0){
			return b;
		}
		return gcd(b,a%b);
	}
	lld getLCM(lld a , lld b){
		return a*b/gcd(a,b);
	}
	lld newLCM(lld lcm , int m){
		lcm = getLCM(lcm,m);
		lcm = getLCM(lcm,n/m);
		return lcm;
	}
	vector<vector<lld> > getMat(lld n){
		vector<vector<lld> > temp=M , product({{1,0} , {0,1}});
		lld k = n/2;
		while(k>0){
			if( (k&1) == 1){
				multiply(product,temp);
			}
			multiply(temp,temp);
			k = k>>1;
		}
		return product;
	}
	bool isValid(lld p){
		vector<vector<lld> > Mat = getMat(p);
		lld a = Mat[0][0] , b = Mat[1][0];
		if(p%2==0){
			lld temp=b;
			b = a-b;
			a = temp;
		}
		return a==1 && b==0 ;
	}
public:
	Solver(int num):
	n(num){
		M = vector<vector<lld> >({{2,1},{1,1}});
	}
	lld solve(){
		lld lcm=1;
		for(int i=2;i<=sqrt(n);++i){
			if(n%i==0){
				lcm = newLCM(lcm , i);
			}
		}
		if(debug){
			cout<<"final LCM : "<<lcm<<endl;
		}
		return lcm;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	lld n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		Solver s(n);
		printf("%lld\n",s.solve());
	}
	return 0;
}

