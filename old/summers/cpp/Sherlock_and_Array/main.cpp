/*
Project name : Sherlock_and_Array
Created on : Tue Jun 17 16:55:38 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/101may14/challenges/sherlock-and-array
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
	vector<lld> leftSum , rightSum;
public:
	Solver(int num):
		n(num),
		arr(vector<int>(num)),
		leftSum(vector<lld>(num)),
		rightSum(vector<lld>(num)){
			for(int i=0;i<n;++i){
				scanf("%d",&arr[i]);
			}
			lld sum = 0;
			for(int i=0;i<n;++i){
				leftSum[i] = sum;
				sum += arr[i];
			}
			sum=0;
			for(int i=n-1;i>-1;--i){
				rightSum[i] = sum;
				sum += arr[i];
			}
		}
	bool solve(){
		for(int i=0;i<n;++i){
			if(leftSum[i]==rightSum[i]){
				return true;
			}
		}
		return false;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Solver s(n);
		printf("%s\n",s.solve()? "YES" : "NO");
	}
	return 0;
}

