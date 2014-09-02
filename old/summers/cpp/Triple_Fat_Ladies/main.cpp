/*
Project name : Triple_Fat_Ladies
Created on : Sat May 17 10:32:01 2014
Author : Anant Pushkar
http://www.spoj.com/problems/EIGHTS/
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	double v,val;
	int i;
	while(true){
		scanf("%lf",&v);
		if(v==0.00)break;
		val=0.5;i=2;
		while(val<v)val += 1/static_cast<double>(++i);
		printf("%d card(s)\n",i-1);
	}
	return 0;
}

