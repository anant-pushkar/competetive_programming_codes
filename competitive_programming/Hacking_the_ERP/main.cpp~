/*
Project name : Hacking_the_ERP
Created on : Sat Aug  2 21:09:35 2014
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
int mask;
lld reduce(lld n){
	while(n>0 && n%10==0){
		n /= 10;
	}
	return n;
}

int get_mask(lld n){
	int temp=0 , i;
	while(n>0){
		i = n%10;
		temp = temp|(1<<(i+1)) ;
		if(temp==mask){
			return temp;
		}
		n/=10;
	}
	return temp;
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , temp=0 , k;
	scanf("%d",&t);
	
	for(int i=0;i<10;++i){
		mask = mask|(1<<(i+1));
	}
	
	lld n , m;
	while(t--){
		scanf("%lld",&n);
		temp = get_mask(n);
		k=2;
		while(temp!=mask){
			m= k*n;
			temp = temp | (get_mask(m));
			++k;
		}
		cout<<k-1<<endl;
	}
	
	return 0;
}

