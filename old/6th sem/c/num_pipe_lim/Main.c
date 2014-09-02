/*
Project name : num_pipe_lim
Created on : Wed Jan 22 17:34:55 2014
Author : Anant Pushkar
dummyproject to test max number of pipes allowed
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
int debug=0;
int count;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	count=0;
	int *fd,s;
	while(1){
		fd=(int*)calloc(2,sizeof(int));
		s=pipe(fd);
		printf("count=%d , s=%d\n",count,s);
		if(s==-1)break;
		++count;
	}
	printf("max count=%d\n",count);
	return 0;
}
