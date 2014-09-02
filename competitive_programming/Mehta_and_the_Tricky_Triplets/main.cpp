/*
Project name : Mehta_and_the_Tricky_Triplets
Created on : Tue Aug 26 23:08:10 2014
Author : Anant Pushkar
http://www.hackerearth.com/august-clash/algorithm/mehta-and-the-tricky-triplets/
2,3,4,7
0010101100 = 4+8+32+128=162
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
lld factorial[21] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,
	39916800,479001600,6227020800,87178291200,1307674368000,20922789890000
	,355687428100000,6402373706000000,121645100400000000,2432902008000000000};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	int a , mask;
	vector<int> count(4,0);
	while(n--){
		scanf("%d",&a);
		mask=0;
		while(a>0){
			mask = mask | (1<<(a%10));
			a /= 10;
		}
		count[0] += mask&(1<<2) ? 1 : 0;
		count[1] += mask&(1<<3) ? 1 : 0;
		count[2] += mask&(1<<5) ? 1 : 0;
		count[3] += mask&(1<<7) ? 1 : 0;
	}
	
	return 0;
}

