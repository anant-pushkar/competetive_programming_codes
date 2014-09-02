/*
Project name : Jzzhu_and_Chocolate
Created on : Sat Jul 19 19:32:52 2014
Author : Anant Pushkar
http://codeforces.com/contest/450/problem/C
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
lld m , n , k;
lld getMax(int i){
	lld val , val1 , val2 , max = 0 , d1 , d2;
	d1 = i+1;
	d2 = k - i + 1;
	val1 = (m/d1)*(n/d2) , val2 = (m/d2)* (n/d1);
	val = val1>val2 ? val1 : val2;
	max = val>max ? val : max;
	if(debug)cout<<val1<<" "<<val2<<endl;
	return max;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%lld %lld %lld",&m,&n,&k);
	lld max = getMax(0);
	printf("%lld\n",max==0 ? -1 : max);
	return 0;
}

