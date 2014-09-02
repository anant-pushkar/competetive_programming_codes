/*
Project name : the_druken_jailer
Created on : Mon Dec  9 02:47:16 IST 2013
http://poj.org/problem?id=1218

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,n;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<4)printf("1\n");
		else if(n<9)printf("2\n");
		else if(n<16)printf("3\n");
		else if(n<25)printf("4\n");
		else if(n<36)printf("5\n");
		else if(n<49)printf("6\n");
		else if(n<64)printf("7\n");
		else if(n<81)printf("8\n");
		else if(n<100)printf("9\n");
		else if(n<121)printf("10\n");
	}
	return 0;
}
