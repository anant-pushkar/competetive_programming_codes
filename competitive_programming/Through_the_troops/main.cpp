/*
Project name : Through_the_troops
Created on : Sat Sep 20 17:31:54 2014
Author : Anant Pushkar
http://www.spoj.com/problems/WPC4F/
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
inline int get_min(int a , int b){
	return a<b ? a : b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n , a , d , b , a_sum=0 , d_sum=0 , b_sum=0 , a_next , d_next , b_next;
	while(t--){
		scanf("%d",&n);
		a_sum=0;
		d_sum=0;
		b_sum=0;
		while(n--){
			scanf("%d %d %d",&a,&d,&b);
		
			a_next = get_min(d_sum , b_sum) + a;
			d_next = get_min(a_sum , b_sum) + d;
			b_next = get_min(a_sum , d_sum) + b;
		
			a_sum = a_next;
			d_sum = d_next;
			b_sum = b_next;
		}
		printf("%d\n" , get_min(get_min(a_sum , d_sum) , b_sum));
	}
	
	return 0;
}

