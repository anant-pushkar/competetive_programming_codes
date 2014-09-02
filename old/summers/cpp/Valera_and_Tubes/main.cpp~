/*
Project name : Valera_and_Tubes
Created on : Sun Jun 29 11:50:43 2014
Author : Anant Pushkar
http://codeforces.com/contest/441/problem/C
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
vector<pair<int,int> > getSeq(int n , int m){
	vector<pair<int,int> > seq(n*m);
	int index = 0;
	for(int i=0;i<n;++i){
		if(i%2==0){
			for(int j=0;j<m;++j){
				seq[index++] = make_pair(i+1,j+1);
			}
		}else{
			for(int j=m-1;j>-1;--j){
				seq[index++] = make_pair(i+1,j+1);
			}
		}
	}
	return seq;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n, m , k;
	scanf("%d %d %d",&n,&m,&k);
	vector<pair<int,int> > seq = getSeq(n,m);
	int index=0 , count=n*m;
	while(k>1 && index<n*m){
		printf("2 %d %d %d %d\n",seq[index].first,seq[index].second,seq[index+1].first,seq[index+1].second);
		count -= 2;
		--k;
		index+=2;
	}
	printf("%d ",count);
	while(index<n*m){
		printf("%d %d ",seq[index].first,seq[index].second);
		++index;
	}
	printf("\n");
	return 0;
}

