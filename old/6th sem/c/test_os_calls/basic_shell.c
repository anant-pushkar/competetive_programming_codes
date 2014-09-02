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
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char buf[MAXLINE];
	pid_t pid;
	int status;
	
	/* from apue.h */
	printf("%% "); /* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL) {
	if (buf[strlen(buf) - 1] == '\n')
	buf[strlen(buf) - 1] = 0; /* replace newline with null */
	if ((pid = fork()) < 0) {
	perror("fork error");
	} else if (pid == 0) {
	/* child */
	execlp(buf, buf, (char *)0);
	perror("couldn't execute cmd");
	exit(127);
	}
	/* parent */
	if ((pid = waitpid(pid, &status, 0)) < 0)
	perror("waitpid error");
	printf("%% ");
	}
	exit(0);
	return 0;
}
