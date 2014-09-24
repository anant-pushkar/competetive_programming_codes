/*
Project name : Subarray_GCD
Created on : Sun Sep 21 21:41:07 2014
Author : Anant Pushkar
http://www.codechef.com/COOK50/problems/SUBGCD
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
	vector<int> arr;
	int get_gcd(int a, int b){
		if(a<b){
			int c = a;
			a = b;
			b = c;
		}
		return a%b==0 ? b : get_gcd(b,a%b);
	}
public:
	Solver(int x):
	n(x),
	arr(vector<int>(n)){
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
	}
	int solve(){
		int g = get_gcd(arr[0],arr[1]);
		for(int i=2;i<n;++i){
			g = get_gcd(g,arr[i]);
		}
		return g==1 ? n : -1;
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
		cout<<s.solve()<<endl;
	}
	return 0;
}

