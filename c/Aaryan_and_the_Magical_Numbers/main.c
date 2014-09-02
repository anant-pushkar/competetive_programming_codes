/*
Project name : Aaryan_and_the_Magical_Numbers
Created on : Wed Aug 27 18:19:39 2014
Author : Anant Pushkar

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int lookup[10]={0,1,2,2,2,3,3,4,4,5};
lld get_val(const char * str){
	lld val=0;
	int l = strlen(str) , i;
	for(i=0;i<l;++i){
		val = val*10 + str[i]-'0';
	}
	return val;
}
lld count(int index , const char * str){
	int l = strlen(str);
	if(index==l){
		return 0;
	}
	return count(index+1 , str) + pow(6 , l-index-1)*lookup[str[index]-'0'];
}
int has_prime(const char * str){
	int l = strlen(str) , i;
	for(i=0;i<l;++i){
		if(str[i]=='2' || str[i]=='3' || str[i]=='5' || str[i]=='7'){
			return 1;
		}
	}
	return 0;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t;
	scanf("%d",&t);
	
	char n[19];
	while(t--){
		scanf("%s",n);
		printf("%lld\n" , get_val(n) - count(0,n) + has_prime(n));
	}
	
	return 0;
}
