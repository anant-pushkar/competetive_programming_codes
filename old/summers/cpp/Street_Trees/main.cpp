/*
Project name : Street_Trees
Created on : Mon Jun 16 14:48:10 2014
Author : Anant Pushkar
http://www.spoj.com/problems/STREETR/
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
int gcd(int a , int b){
	if(debug)cout<<"Finding GCD of "<<a<<" "<<b<<endl;
	if(a<b){
		a = a^b;
		b = a^b;
		a = a^b;
	}
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	vector<int> pos(n);
	
	for(int i=0;i<n;++i){
		scanf("%d",&pos[i]);
	}
	
	int temp = pos[1] - pos[0];
	for(int i=2;i<n;++i){
		temp = gcd(temp , pos[i]-pos[i-1]);
	}
	
	if(debug)cout<<"GCD = "<<temp<<endl;
	int count = 0;
	for(int i=1;i<n;++i){
		count += (pos[i]-pos[i-1])/temp - 1;
	}
	
	printf("%d\n",count);
	
	return 0;
}

