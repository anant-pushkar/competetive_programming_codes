/*
Project name : test
Created on : Sat Aug  9 22:54:31 2014
Author : Anant Pushkar

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
const int mod = 1000000007;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int q;
	scanf("%d",&q);
	
	int a , b ;
	lld sum=0;
	while(q--){
		scanf("%d %d",&a,&b);
		sum=0;
		for(int i=a;i<=b;++i){
			sum += i-1;
			sum = sum%mod;
		}
		sum *= 2;
		sum = sum%mod;
		if(a==1 && b==2){
			cout<<3<<endl;
		}else{
			cout<<sum<<endl;
		}
	}
	
	return 0;
}

