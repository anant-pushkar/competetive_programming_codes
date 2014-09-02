/*
Project name : Arithmetic_Progression
Created on : Mon Jan 20 16:56:22 2014
Author : Anant Pushkar
codeforces 382 : C
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	if(n==1){
		lld a;
		scanf("%lld",&a);
		printf("-1\n");
		return 0;
	}
	if(n==2){
		lld a,b;
		scanf("%lld %lld",&a,&b);
		if(a<b){
			a=a^b;
			b=a^b;
			a=a^b;
		}
		if(a!=b){
			if(a-b!=1 && (a+b)%2==0)printf("3\n%lld %lld %lld\n",(2*b-a),(a+b)/2,(2*a-b));
			else {
				printf("2\n%lld %lld",(2*b-a),(2*a-b));
			}
		}else printf("1\n%lld\n",a);
		return 0;
	}
	lld arr[n];
	for(int i=0;i<n;++i)scanf("%lld",&arr[i]);
	sort(arr,arr+n);
	
	lld diff[n-1];
	for(int i=1;i<n;++i)diff[i-1]=arr[i]-arr[i-1];
	
	bool check=true;
	int count=0,index;
	for(int i=1;i<n-1;++i)if(diff[i]!=diff[i-1]){
		check=false;
		++count;
		index=i-1;
	}
	if(check){
		if(diff[0]==0){
			printf("1\n%lld\n",arr[0]);
		}else{
			printf("2\n%lld %lld\n",arr[0]-diff[0],arr[n-1]+diff[0]);
		}
	}else{
		if(count>2){
			printf("0\n");
		}else if(count==1){
			if(diff[0]==0 || diff[1]==0)printf("0\n");
			else if(diff[0]==2*diff[1] && (arr[0]+arr[1])%2==0)printf("1\n%lld\n",(arr[0]+arr[1])/2);
			else if(diff[n-2]==2*diff[n-3] && (arr[n-2]+arr[n-1])%2==0)printf("1\n%lld\n",(arr[n-2]+arr[n-1])/2);
			else printf("0\n");
		}else if(count==2){
			if(diff[index]==2*diff[index-1] && diff[index]==2*diff[index+1] && (arr[index]+arr[index+1])%2==0)
				printf("1\n%lld\n",(arr[index]+arr[index+1])/2);
			else printf("0\n");
		}
	}
	
	return 0;
}

