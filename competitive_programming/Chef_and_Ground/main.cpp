/*
Project name : Chef_and_Ground
Created on : Tue Oct  7 08:14:20 2014
Author : Anant Pushkar
http://www.codechef.com/OCT14/problems/CHEFGR
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
inline int get_max(int a , int b){
	return a>b ? a : b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n,m,max,diff;
	vector<int> a(101);
	while(t--){
		scanf("%d %d",&n,&m);
		max=INT_MIN;
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
			max = get_max(max,a[i]);
		}
		diff=0;
		for(int i=0;i<n;++i){
			diff += max-a[i];
		}
		printf("%s\n",(diff-m)%n==0 ? "Yes" : "No");
	}
	return 0;
}

