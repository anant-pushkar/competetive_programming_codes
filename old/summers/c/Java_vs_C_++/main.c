/*
Project name : Java_vs_C_++
Created on : Sun May 25 16:42:32 2014
Author : Anant Pushkar
http://www.spoj.com/problems/JAVAC/
*/
#include<ctype.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CPP 1
#define JAVA 2
#define ERR 3
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
char str[101];
int l;
int getType(){
	int i , type=0;
	for(i=0;i<l;++i){
		if(str[i]=='_'){
			if(type!=JAVA && i<l-1 && !isupper(str[i+1]) && str[i+1]!='_' && i>0 )type=CPP;
			else return ERR;
		}else if(isupper(str[i])){
			if(type!=CPP && i>0 && str[i-1]!='_')type=JAVA;
			else return ERR;
		}
	}
	return type;
}
void printCamel(){
	int i;
	for(i=0;i<l;++i){
		if(str[i]=='_'){
			str[i+1] = toupper(str[i+1]);
			++i;
		}
		printf("%c",str[i]);
	}
	printf("\n");
}
void printSnake(){
	int i;
	for(i=0;i<l;++i){
		if(isupper(str[i])){
			printf("_");
			str[i] = tolower(str[i]);
		}
		printf("%c",str[i]);
	}
	printf("\n");
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int type;
	while( scanf( "%s" , str ) !=EOF ){
		if(debug)printf("%s : ",str);
		l = strlen(str);
		type = getType();
		switch(type){
			case CPP:
				printCamel();
				break;
			case JAVA:
				printSnake();
				break;
			case ERR:
				printf("Error!\n");
				break;
			default:
				printf("%s\n",str);
				break;
		}
	}
	return 0;
}
