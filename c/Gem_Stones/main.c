/*
Project name : Gem_Stones
Created on : Mon Jul 21 18:49:08 2014
Author : Anant Pushkar
https://www.hackerrank.com/challenges/gem-stones
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int count[26];
int n;
void init(){
	int i=0;;
	for(i=0;i<26;++i){
		count[i]=0;
	}
}
int get_mask(char c){
	return 1<<(c-'a');
}
int get_tok_info(char str[]){
	int l = strlen(str);
	int info = 0 , i , mask;
	for(i=0;i<l;++i){
		mask = get_mask(str[i]);
		info = info | mask;
	}
	return info;
}
void update_count(int info){
	int mask =1 , i;
	for(i=0;i<26;++i){
		if(mask&info){
			++count[i];
		}
		mask = mask<<1;
	}
}
int get_gem_count(){
	int num=0 , i;
	for(i=0;i<26;++i){
		if(count[i]==n){
			++num;
		}
	}
	return num;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int i;
	scanf("%d",&n);
	init();
	
	char composition[n][101];
	int tok_info=0;
	for(i=0;i<n;++i){
		scanf("%s",composition[i]);
		tok_info = get_tok_info(composition[i]);
		update_count(tok_info);
	}
	
	printf("%d\n",get_gem_count());
	return 0;
}
