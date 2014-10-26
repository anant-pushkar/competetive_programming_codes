/*
Project name : FIZZ_BUZZ
Created on : Thu Oct 16 23:18:09 2014
Author : Anant Pushkar
https://www.codeeval.com/open_challenges/1/
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
	int a , b , n;
	while(true){
		if(!(cin>>a))break;
		if(!(cin>>b))break;
		if(!(cin>>n))break;
		for(int i=1;i<=n;++i){
			if(i%a==0 && i%b!=0){
				cout<<"F ";
			}else if(i%b==0 && i%a!=0){
				cout<<"B ";
			}else if(i%a==0 && i%b==0){
				cout<<"FB ";
			}else{
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

