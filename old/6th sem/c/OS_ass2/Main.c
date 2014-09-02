/*
Project name : OS_ass2
Created on : Sat Jan 18 00:11:50 2014
Author : Anant Pushkar
OS Lab Assignment 2 Part#1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include<time.h>
#include<signal.h>
#define MIN 1
#define MAX 0
const int max=100;
int debug=0 , left_pipe[2] , right_pipe[2];
pid_t   left_pid ,right_pid;
void signal_handler(int signo){
	if(right_pid==-1)printf("C : ");
	else printf("D : ");
	switch(signo){
		case SIGUSR2:
			printf("Well,it was nice playing the game anyways. Bye!!\n");
			break;
		case SIGUSR1:
			printf("Well!!Thats the way its done.Good Bye!!\n");
	}
	exit(0);
}
void child(int pipe[2]){
	char buffer[10];
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
	
	srand(time(NULL));
	while(1){
		read(pipe[0],buffer,sizeof(buffer));
		sprintf(buffer,"0%d",rand()%max+1+right_pid);
		write(pipe[1],buffer,sizeof(buffer));
	}
}
void parent(){
	char buffer[100];
	
	printf("OK!! So, let the game begin\n");
	int left_score=0,right_score=0,left_val,right_val,flag;
	srand(time(NULL));
	while(left_score<10 && right_score<10){
		sprintf(buffer,"ok");
		printf("SCORE BOARD\n+-------+\n|C : %d\t|\n+-------+\n|D : %d\t|\n+-------+\n",left_score,right_score);
		do{
			write(left_pipe[1],buffer,sizeof(buffer));
			read(left_pipe[0],buffer,sizeof(buffer));
		}while(buffer[0]!='0');
		printf("C : %s\n",buffer+1);
		left_val=atoi(buffer+1);
		
		sprintf(buffer,"ok");
		do{
			write(right_pipe[1],buffer,sizeof(buffer));
			read(right_pipe[0],buffer,sizeof(buffer));
		}while(buffer[0]!='0');
		printf("D : %s\n",buffer+1);
		right_val=atoi(buffer+1);
		
		flag=rand()%2;
		switch(flag){
			case MIN:
				printf("MIN flag chosen\n");
				left_score += left_val<right_val?1:0;
				right_score+= right_val<left_val?1:0;
				break;
			case MAX:
				printf("MAX flag chosen\n");
				left_score += left_val>right_val?1:0;
				right_score+= right_val>left_val?1:0;
				break;
		}
		printf("\n\n");
	}
	if(left_score>right_score){
		printf("C wins\n");
		kill(right_pid,SIGUSR2);
		kill(left_pid,SIGUSR1);
	}else{
		printf("D wins\n");
		kill(right_pid,SIGUSR1);
		kill(left_pid,SIGUSR2);
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	char buffer[100];
	left_pid=-1;
	right_pid=-1;
	printf("P : Creating Pipes\n");
	pipe(left_pipe);pipe(right_pipe);
	
	printf("P : Creating left child\n");
	left_pid=fork();
	if(left_pid==0){
		child(left_pipe);
	}else{
		printf("P : Creating right child\n");
		right_pid=fork();
		if(right_pid==0){
			child(right_pipe);
		}else{
			parent();
		}
	}
	return 0;
}
