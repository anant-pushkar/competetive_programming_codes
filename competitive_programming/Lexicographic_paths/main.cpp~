/*
Project name : Lexicographic_paths
Created on : Tue Aug 26 22:18:28 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w9/challenges/lexicographic-steps
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
lld factorial[21] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,
	39916800,479001600,6227020800,87178291200,1307674368000,20922789890000
	,355687428100000,6402373706000000,121645100400000000,2432902008000000000};
class Solver{
	int n , m , k;
	queue<char> soln;
	void extract(int index , int pos , int h_count , int v_count){
		if(debug)cout<<"index:"<<index<<" n:"<<n<<" h:"<<h_count<<" v:"<<v_count<<endl;
		if(index==m+n){
			return;
		}
		
		if(h_count==0){
			while(v_count--){
				soln.push('V');
			}
			return;
		}
		
		if(v_count==0){
			while(h_count--){
				soln.push('H');
			}
			return;
		}
		
		
		lld count = factorial[h_count-1+v_count]/(factorial[h_count-1]*factorial[v_count]);
		if(debug)cout<<"count "<<count<<endl;
		
		if(pos>=count){
			if(debug)cout<<"pushing v"<<endl;
			soln.push('V');
			extract(index+1 , pos-count , h_count , v_count-1);
		}else{
			if(debug)cout<<"pushing h"<<endl;
			soln.push('H');
			extract(index+1 , pos , h_count-1 , v_count);
		}
	}
public:
	Solver(int a , int b , int c):
	n(a),
	m(b),
	k(c){
		if(debug)cout<<"n:"<<n<<" m:"<<m<<" k:"<<k<<endl;
	}
	string solve(){
		extract(0,k,n,m);
		
		int index=0;
		string ans(n+m,'\0');
		while(!soln.empty()){
			ans[index++] = soln.front();
			soln.pop();
		}
		
		return ans;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n , m , k;
	scanf("%d",&t);
	
	while(t--){
		scanf("%d %d %d",&n , &m , &k);
		Solver s(n,m,k);
		cout<<s.solve()<<endl;
	}
	
	return 0;
}

