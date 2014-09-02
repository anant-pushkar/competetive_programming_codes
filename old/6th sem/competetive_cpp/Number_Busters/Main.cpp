/*
Project name : Number_Busters
Created on : Mon Jan 20 18:14:36 2014
Author : Anant Pushkar
codeforces 382 B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	lld a,b,w,x,c,count=0,n;
	cin>>a>>b>>w>>x>>c;
	while(c>a){
		n=(x-b)/(w-x)+((x-b)%(w-x)==0?0:1);
		count+=n+1;
		c=c-n-1;
		a=a-n;
		b=n*(w-x)+b;
		//while(b>=x){
			b=b-x;
			//++count;
		//}
	}
	cout<<count<<endl;
	return 0;
}
//n(w-x)+b<x
//n < (x-b)/(w-x)
