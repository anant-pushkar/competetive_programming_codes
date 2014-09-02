/*
Project name : break_pipe
Created on : Sun Jan 19 18:37:05 2014
Author : Anant Pushkar
test project to test pipe breaking
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int p[2];
	pipe(p);
	int pid=fork();
	if(pid){
		printf("Sending parent to Wait\n");
		wait();
		//sleep(1);
		printf("Parent is now awake\n");
		printf("Closing parent write end\n");
		close(p[1]);
		printf("Parent's write end closed\n");
		char buffer[20];
		sprintf(buffer,"default");
		printf("Parent trying to read\n");
		read(p[0],buffer,sizeof(buffer));
		perror("pipe status in parent : ");
		//exit(EXIT_FAILURE);
		printf("Parent read : %s\n",buffer);
	}else{
		printf("-------------------\n");
		printf("Closing child's write end\n");
		close(p[1]);close(p[0]);
		printf("Child's write end closed\n");
		printf("Exiting child\n");
		perror("pipe status in child : ");
		printf("-------------------\n");
        exit(EXIT_FAILURE);
	}
	return 0;
}
