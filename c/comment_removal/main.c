/*
Project name : comment_removal
Created on : Wed Oct  8 23:49:04 2014
Author : Anant Pushkar

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define PRINT 0
#define EXPECT 1
#define LINE 2
#define MULTI 3
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int state=PRINT;
	char c;
	while(scanf("%c",&c)!=EOF){
		switch(state){
			case PRINT:
				if(c!='/'){
					printf("%c",c);
				}else{
					state = EXPECT;
				}
				break;
			case EXPECT:
				if(c=='/'){
					state = LINE;
				}else if(c=='*'){
					state = MULTI;
				}else{
					printf("/%c",c);
					state = PRINT;
				}
				break;
			case LINE:
				if(c=='\n'){
					state = PRINT;
				}
				break;
			case MULTI:
				if(c=='*'){
					scanf("%c",&c);
					if(c=='/'){
						state = PRINT;
					}
				}
				break;
		}
	}
	return 0;
}
