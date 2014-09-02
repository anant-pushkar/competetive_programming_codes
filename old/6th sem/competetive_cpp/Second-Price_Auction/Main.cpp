/*
Project name : Second-Price_Auction
Created on : Fri Jan 17 20:26:42 2014
Author : Anant Pushkar
codeforces Testing round Problem A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	int bid,max1=-1,i1,max2=-2,i2;
	scanf("%d",&max1);
	scanf("%d",&max2);
	if(max1<max2){
		max1=max1^max2;
		max2=max1^max2;
		max1=max1^max2;
		i1=2;i2=1;
	}else{
		i1=1;i2=2;
	}
	for(int i=2;i<n;++i){
		scanf("%d",&bid);
		if(bid>max1){
			max2=max1;
			i2=i1;
			max1=bid;
			i1=i+1;
		}else if(bid>max2){
			max2=bid;
			i2=i+1;
		}
	}
	printf("%d %d\n",i1,max2);
	return 0;
}

