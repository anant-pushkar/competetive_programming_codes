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
int debug=0;
#define MAXLINE 100
int execute(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	FILE *fptr=fopen("/bin/ls","w+");
	int errsys=errno;
	printf("msg : %s\n",strerror(errsys));
	perror(argv[0]);
	switch(errsys){
		case EACCES:
			printf("EACCES\n");
			break;
		default:
			printf("errsys:%d\n",errsys);
			break;
	}
	return 0;
}
