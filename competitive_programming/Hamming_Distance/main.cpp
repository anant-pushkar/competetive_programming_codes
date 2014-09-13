/*
Project name : Hamming_Distance
Created on : Sat Sep 13 11:39:24 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/w10/challenges/hamming-distance
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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d" , &n);
	
	char str[n+1];
	scanf("%s",str);
	
	int m;
	scanf("%d",&m);
	
	string q;
	int a,b,l,r,len , i1 , i2 , index;
	char temp[50000];
	while(m--){
		if(debug)cout<<m<<",";
		cin>>q;
		if(debug)cout<<q<<" : ";
		switch(q[0]){
			case 'C':
				cin>>l>>r>>q;
				--l;--r;
				if(debug)cout<<"changing "<<l<<","<<r<<endl;
				for(int i=l;i<=r;++i){
					str[i] = q[0];
				}
				break;
			case 'S':
				cin>>l>>r>>a>>b;
				if(l>a){
					l = l^a;
					a = l^a;
					l = l^a;
					
					r = r^b;
					b = r^b;
					r = r^b;
				}
				--l;--r;--a;--b;
				if(debug)cout<<"swapping "<<l<<","<<r<<" "<<a<<","<<b<<endl;
				index = 0;
				i1 = r+1;
				while(i1<a){
					temp[index] = str[i1];
					++index;
					++i1;
				}
				i1=l;
				while(i1<=r){
					temp[index] = str[i1];
					++index;
					++i1;
				}
				
				i1 = a;
				index=l;
				while(i1<=b){
					str[index] = str[i1];
					++i1;
					++index;
				}
				i1 = 0;
				while(index<n){
					str[index] = temp[i1];
					++index;
					++i1;
				}
				
				break;
			case 'R':
				cin>>l>>r;
				--l;--r;
				if(debug)cout<<"reversing "<<l<<","<<r<<endl;
				while(l<r){
					q[0] = str[l];
					str[l] = str[r];
					str[r] = q[0];
					++l;
					--r;
				}
				if(debug)cout<<"reverse complete"<<endl;
				break;
			case 'W':
				if(debug)cout<<"w"<<endl;
				cin>>l>>r;
				--l;--r;
				if(debug)cout<<"printing "<<l<<","<<r<<endl;
				for(int i=l;i<=r;++i){
					printf("%c",str[i]);
				}
				printf("\n");
				break;
			case 'H':
				if(debug)cout<<"h"<<endl;
				cin>>a>>b>>len;
				--a;--b;
				if(debug)cout<<"hamming "<<a<<","<<b<<" "<<len<<endl;
				l=0;
				while(len--){
					if(str[a]!=str[b]){
						++l;
					}
					++a;
					++b;
				}
				printf("%d\n",l);
				break;
		}
		if(debug)cout<<"end of query"<<endl;
	}
	
	
	return 0;
}

