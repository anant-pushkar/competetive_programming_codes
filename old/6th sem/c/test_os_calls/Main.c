/*
Project name : test_os_calls
Created on : Sat Feb  1 19:24:57 2014
Author : Anant Pushkar
dummy project to test os calls
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>
#include <errno.h>
#include<signal.h>
int debug=0;
int test;
#define MAXLINE 100
void exit_handler(){
	printf("This message was printed by exit handler\n\n");
}
void sigseg_handler(int intnum){
	printf("At sigseg handler with error : %s\n",strerror(intnum));
	exit(0);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	extern char ** environ;
	atexit(exit_handler);
	char ** ptr;
	signal(SIGSEGV,sigseg_handler);
	for(ptr=environ;ptr!=NULL;++ptr)printf("%s\n",*(ptr));
	return 0;
}
