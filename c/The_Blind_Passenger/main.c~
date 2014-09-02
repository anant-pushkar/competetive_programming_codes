/*
Project name : The_Blind_Passenger
Created on : Wed Jul 30 21:06:19 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MYQ1/
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
	int t , n , r;
	scanf("%d",&t);
	
	char dir[5][4];
	strcpy(dir[0],"W L");
	strcpy(dir[1],"A L");
	strcpy(dir[2],"A R");
	strcpy(dir[3],"M R");
	strcpy(dir[4],"W R");
	
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("poor conductor \n");
		}else{
			n -= 2;
			r = (n/5)+1;
			printf("%d %s\n", r , r%2==1 ? dir[n%5] : dir[4-(n%5)]);
		}
	}
	return 0;
}
