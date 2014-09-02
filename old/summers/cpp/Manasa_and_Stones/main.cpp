/*
Project name : Manasa_and_Stones
Created on : Sat May 17 16:33:22 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w2/challenges/manasa-and-stones
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
#include<unordered_set>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,a,b,val;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%d",&a);
		scanf("%d",&b);
		if(a<b){
			a = a^b;
			b = a^b;
			a = a^b;
		}
		unordered_set<int> s;
		for(int i=0;i<n;++i){
			val = i*a+(n-i-1)*b;
			if(s.find(val) == s.end()){
				printf("%d ",val);
				s.insert(val);
			}
		}
		printf("\n");
	}
	return 0;
}

