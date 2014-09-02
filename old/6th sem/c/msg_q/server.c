/*
 * 
 * Before compiling run : 
 alias gcc='gcc -Wall -pedantic -D_GNU_SOURCE -std=c99'
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#define MAXSIZE     128
#define UP 1234
#define DOWN 1235
typedef long long int lld;
void die(char *s){
	perror(s);
	exit(1);
}
/*typedef struct msgbuf{
	lld    mtype;
	char    mtext[MAXSIZE];
};*/
int debug=0;
int cid=2;
int upqid,downqid;
key_t key_up=UP , key_down=DOWN;
void listen_for_connection(){
	while(1){
		//if(debug)printf("listening for connections\n");
		struct msgbuf rcvbuffer,sbuf;
		if (msgrcv(upqid, &rcvbuffer, MAXSIZE, 1, 0) < 0)
			die("Could not receive connection request from client ");
		sbuf.mtype=atoi(rcvbuffer.mtext);
		//if(debug)printf("Received connection request with id %ld\n",sbuf.mtype);
		cid=cid+1;
		//if(debug)printf("Allocating cid %d\n",cid);
		sprintf(sbuf.mtext,"%d",cid);
		size_t buflen=strlen(sbuf.mtext)+1;
		if (msgsnd(downqid, &sbuf, buflen, IPC_NOWAIT) < 0){
			//if(debug)printf ("%d, %ld, %s, %d\n", downqid, sbuf.mtype, sbuf.mtext, (int)buflen);
			die("msgsnd");
		}
		else{
			//if(debug)printf("Connection ack sent\n\n\n");
		}
		//sleep(1);
	}
	exit(0);
}
#define SIZE 256
void print_now(){
	time_t ticks;
	ticks=time(NULL);
	printf("Msg received at time: %.24s\r\n", ctime(&ticks));
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int msgflg = IPC_CREAT | 0666;
	if ((upqid = msgget(key_up, msgflg)) < 0)
		die("Error connecting to Up queue ");
	if ((downqid = msgget(key_down, msgflg)) < 0)
      die("Error connecting to Down queue ");
	int pid=fork();
	if(pid==0)listen_for_connection();
	//if(debug)printf("After connection\n");
	struct msgbuf buffer;
	int len,i;
	while(1){
		if (msgrcv(upqid, &buffer, MAXSIZE, 1, MSG_EXCEPT) < 0)
			die("Could not receive msg from client ");
		if(buffer.mtype==1)continue;
		//if(debug)printf("Received msg with type %ld and msg:%s\n",buffer.mtype,buffer.mtext);
		len=strlen(buffer.mtext);
		for(i=0;i<len;++i){
			if(buffer.mtext[i]-'a'>=0 && buffer.mtext[i]-'a'<=26)
				buffer.mtext[i]=buffer.mtext[i]-'a'+'A';
			else if(buffer.mtext[i]-'A'>=0 && buffer.mtext[i]-'A'<=26)
				buffer.mtext[i]=buffer.mtext[i]-'A'+'a';
		}
		print_now();
		size_t buflen=strlen(buffer.mtext)+1;
		if (msgsnd(downqid, &buffer, buflen, IPC_NOWAIT) < 0){
			//if(debug)printf ("%d, %ld, %s, %d\n", downqid, buffer.mtype, buffer.mtext, (int)buflen);
			die("msgsnd");
		}
		else{
			//if(debug)printf("response sent : %s\n\n\n",buffer.mtext);
		}
		
	}
	waitpid(pid,NULL,WUNTRACED);
}