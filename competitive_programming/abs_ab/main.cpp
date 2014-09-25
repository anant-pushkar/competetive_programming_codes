/*
Project name : abs_ab
Created on : Fri Sep 26 02:14:41 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ABSP1/
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
public:
	Solver(int x):
	n(x),
	arr(vector<int>(x)){
		for(int i=0;i<n;++i){
			scanf("%d",&arr[i]);
		}
	}
	lld solve(){
		lld solo = arr[1]-arr[0] , sum = arr[1]-arr[0];
		for(int i=2;i<n;++i){
			solo = solo + (arr[i]-arr[i-1])*i ;
			sum  = solo + sum;
			if(debug)cout<<"solo : "<<solo<<" sum:"<<sum<<endl;
		}
		return sum;
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

