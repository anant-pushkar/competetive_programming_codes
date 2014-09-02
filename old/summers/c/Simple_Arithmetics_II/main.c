/*
Project name : Simple_Arithmetics_II
Created on : Sun May 25 11:48:01 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ARITH2/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	llu t,m,n;scanf("%llu",&t);
	char c;
	while(t--){
		scanf("%llu",&n);
		while(1){
			if(debug)printf("n=%llu\n",n);
			do{
				scanf("%c",&c);
			}while(c!='+' && c!='-' && c!='*' && c!='/' && c!='=');
			if(c=='='){
				printf("%llu\n",n);
				break;
			}
			scanf("%llu",&m);
			switch(c){
				case '+':
					n += m;
					break;
				case '-':
					n -= m;
					break;
				case '*':
					n *= m;
					break;
				case '/':
					n /= m;
					break;
			}
		}
	}
	return 0;
}
