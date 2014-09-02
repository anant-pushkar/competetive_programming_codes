/*
Project name : msg_q
Created on : Sun Feb  9 14:04:22 2014
Author : Anant Pushkar
OS lab assignment 3 part#2
Before compiling run : 
 alias gcc='gcc -Wall -pedantic -D_GNU_SOURCE -std=c99'

*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE     256
#define UP 1234
#define DOWN 1235
int debug=0;
typedef long long int lld;
void die(char *s){
	perror(s);
	exit(1);
}
/*struct msgbuf{
	lld    mtype;
	char    mtext[MAXSIZE];
};*/
int upqid,downqid;
key_t key_up=UP , key_down=DOWN;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int msgflg = 0666;
	struct msgbuf sbuf,rcvbuffer;
	size_t buflen;
	if ((upqid = msgget(key_up, msgflg)) < 0)
		die("Error connecting to Up queue ");
	if ((downqid = msgget(key_down, msgflg)) < 0)
      die("Error connecting to Down queue ");
	
	//send request for connection
	sbuf.mtype = 1;
	srand(time(NULL));
	long int id=(rand()%1000+1)*(rand()%1000+1)*(rand()%1000+1);
	sprintf(sbuf.mtext,"%ld",id);
	buflen=strlen(sbuf.mtext)+1;
	if(debug)printf("Sending request with id : %ld\n",id);
	if (msgsnd(upqid, &sbuf, buflen, IPC_NOWAIT) < 0)
	{
		if(debug)printf ("%d, %ld, %s, %d\n", upqid, sbuf.mtype, sbuf.mtext, (int)buflen);
		die("connection request ");
	}
	if (msgrcv(downqid, &rcvbuffer, MAXSIZE, id, 0) < 0)
		die("Could not receive connection ack from server ");
	int cid=atoi(rcvbuffer.mtext);
	if(debug)printf("Connection ID : %d\n",cid);
	sbuf.mtype=cid;
	printf("Insert message to send to server:");
	scanf("%[^\n]",sbuf.mtext);
	getchar();

	buflen = strlen(sbuf.mtext) + 1 ;

	if (msgsnd(upqid, &sbuf, buflen, IPC_NOWAIT) < 0)
	{
		printf ("%d, %ld, %s, %d\n", upqid, sbuf.mtype, sbuf.mtext, (int)buflen);
		die("msgsnd");
	}

	else
		if(debug)printf("Message Sent\n");
	if (msgrcv(downqid, &sbuf, MAXSIZE, cid, 0) < 0)
		die("Could not receive response from client ");
	if(debug)printf("Received response with type %ld and msg:%s\n",sbuf.mtype,sbuf.mtext);
	printf("Processed msg from server: %s\n",sbuf.mtext);
	exit(0);
}
