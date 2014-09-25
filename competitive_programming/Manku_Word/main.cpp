/*
Project name : Manku_Word
Created on : Thu Sep 25 14:29:46 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MAY99_2/
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
	int t;
	scanf("%d",&t);
	
	lld n;
	stack<char> s;
	char alpha[5] = {'m' , 'a' , 'n' , 'k' , 'u'};
	while(t--){
		scanf("%lld",&n);
		while(n>0){
			s.push(alpha[(n-1)%5]);
			n = (n-1)/5;
			if(debug)cout<<n<<endl;
		}
		while(!s.empty()){
			printf("%c" , s.top());
			s.pop();
		}
		printf("\n");
	}
	
	return 0;
}

