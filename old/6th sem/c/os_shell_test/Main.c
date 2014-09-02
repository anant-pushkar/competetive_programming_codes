/*
11CS10003 Anant Pushkar
11CS30041 Vivek Kumar Jaiswal

To compile use gcc myshell.c -o main
To run in debug mode use ./main DEBUG
	This will print all debug mesages 
To run in normal mode use ./main
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
#include <fcntl.h>
#include<signal.h>
int debug=0 ;
size_t nbytes=400;
char* cmd;
int count;
static void _cd(){
	if(debug)printf("in cd with |%s|\n",cmd+3);
	int status=chdir(cmd+3);
	if(status==-1)perror("Could not change Directory ");
	else if(debug){
		system("pwd");
	}
}
static void _pwd(){
	if(debug)printf("in pwd\n");
	size_t size=200;
	char buf[size];
	char *ret=getcwd(buf,size);
	if(ret==NULL)perror("Could not fetch current directory ");
	else printf("%s\n",buf);
}
static void _mkdir(){
	if(debug)printf("in mkdir with |%s|\n",cmd+6);
	int status = mkdir(cmd+6, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(status==-1)perror("Could not create directory ");
	else if(debug){
		printf("Directory created\n");
		system("ls");
	}
}
static void _rmdir(){
	if(debug)printf("in rmdir with |%s|\n",cmd+6);
	int status = rmdir(cmd+6);
	if(status==-1)perror("Could not remove directory ");
	else if(debug){
		printf("Directory removed\n");
		system("ls");
	}
	
}
static void _ls(){
	if(debug)printf("in ls with |%s|\n",cmd+3);
	DIR *dir;
	int errno;
	struct dirent *dp;
	if ((dir = opendir (".")) == NULL) {
		perror ("Cannot open ");
	}
	do {
		errno = 0;
		if ((dp = readdir(dir)) != NULL) {
			printf("%s\n",dp->d_name);
		}
	} while (dp != NULL);
	closedir(dir);
}
static void _run_exit(){
	if(debug)printf("in exit\n");
	exit(0);
}
static void _execute(){
	
	if(debug)printf("in execute with |%s|\n",cmd);
	int status;
	
	char *arg[100];
	int i=0,j=0,index = 0;
	for(index=0;cmd[index]!='\0';index++)
	{
		arg[i] = (char*)malloc(100*sizeof(char));
		while(cmd[index]!=' ' && cmd[index]!='\0')
		{
			arg[i][j++] =cmd[index++];
		}
		arg[i][j] = '\0';
		j = 0;
		i++;
	}
	arg[i] = '\0';
	
	index=0;
	while(index<nbytes && cmd[index]!=' ' && cmd[index]!='\0' && cmd[index]!='\t' && cmd[index]!='\n')++index;
	while(cmd[index]==' ' || cmd[index]=='\t'){
		if(cmd[index]=='\n' || cmd[index]=='\0' || cmd[index]==' ')break;
		++index;
		if(index>=nbytes)break;
	}
	cmd[index]='\0';
	//char *args[100];
	
	
	
	//args[0]=cmd+index;
	//args[1]=NULL;
	//if(debug)printf("%d %s : %s %s\n",index,cmd,args[0],args[1]);
	if(fork()==0){
		if(execvp(cmd,arg)<0)
		{
		printf("error %s\n",strerror(errno));
		exit(0);
		}
			
	}else{
		wait(NULL);
	}
	
}
int tempin=0,tempout=1;
void director(){
	tempin=0;tempout=1;
	if(debug)printf("in director\n");
	while(*cmd==' ' || *cmd=='\t')++cmd;
	int len=strlen(cmd);
	char *tempptr=cmd;
	cmd[strlen(cmd)-1]='\0';
	int i=strlen(cmd),pid=-1,j,in,out,p2id;
	while(cmd[i]=='\0' || cmd[i]=='\t' || cmd[i]==' ')--i;
	if(cmd[i]=='&'){
		cmd[i]='\0';
		++count;
		pid=fork();
		if(pid!=0){
			printf("[%d] %d\n",count,pid);
			return;
		}
	}
	while(*cmd==' ' || *cmd=='\t')++cmd;
	int idx[len],index=0;
	for(i=0;i<len;++i)if(cmd[i]=='|')idx[index++]=i;
	int check=0;
	for(i=0;i<index;++i){
		int p[2];
		pipe(p);
		p2id=fork();
		if(p2id==0){
			check=1;
			cmd=tempptr+idx[i]+1;
			if(debug)printf("child to exeecute : %s\n",cmd);
			tempin = open("/dev/fd/0", O_RDONLY);
			dup2(0,tempin);
			dup2(p[0],0);
			close(p[0]);
		}else{
			tempout = open("/dev/fd/1", O_RDONLY);
			dup2(1,tempout);
			cmd[idx[i]]='\0';
			if(debug)printf("exiting loop in parent with : %s\n",cmd);
			dup2(p[1],1);
			close(p[1]);
			break;
		}
	}
	char file[100];
	int last=strlen(cmd);
	while(*cmd==' ' || *cmd=='\t')++cmd;
	for(i=0;i<strlen(cmd);++i){
		while(*cmd==' ' || *cmd=='\t')++cmd;
		if(cmd[i]=='<'){
			last=last>i?i:last;
			++i;
			while(i<strlen(cmd) && (cmd[i]==' ' || cmd[i]=='\t') )++i;
			j=i;
			while(j<strlen(cmd) && cmd[j]!=' ' && cmd[j]!='\t' )++j;
			cmd[j]='\0';
			sprintf(file,"%s",cmd+i);
			if(debug)printf("rerouting stdin to %s\n",file);
			i=j+1;
			in = open(file, O_RDONLY);
			if(in==-1)perror("Could not open file ");
			tempin = open(file, O_RDONLY);
			if(tempin==-1)perror("Could not open file ");
			if(debug)printf("in=%d , tempin=%d\n",in,tempin);
			dup2(0,tempin);
			dup2(in, 0);
			close(in);
			cmd[j]=' ';
		}
		if(cmd[i]=='>'){
			last=last>i?i:last;
			++i;
			while(i<strlen(cmd) && (cmd[i]==' ' || cmd[i]=='\t') )++i;
			j=i;
			while(j<strlen(cmd) && cmd[j]!=' ' && cmd[j]!='\t' )++j;
			cmd[j]='\0';
			sprintf(file,"%s",cmd+i);
			if(debug)printf("rerouting stdout to %s\n",file);
			i=j+1;
			out = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			if(out==-1)perror("Could not open file ");
			tempout = open(file, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
			if(tempout==-1)perror("Could not open file ");
			if(debug)printf("out=%d , tempout=%d\n",out,tempout);
			dup2(1,tempout);
			dup2(out, 1);
			close(out);
			cmd[j]=' ';
		}
	}
	cmd[last]='\0';
	while(*cmd==' ' || *cmd=='\t')++cmd;
	switch(cmd[0]){
		case 'c':
			if(strncmp(cmd,"cd ",3)==0)_cd();
			else _execute();
			break;
		case 'l':
			if(strncmp(cmd,"ls",2)==0)_ls();
			else _execute();
			break;
		case 'e':
			if(strcmp(cmd,"exit")==0)_run_exit();
			else _execute();
			break;
		case 'p':
			if(strcmp(cmd,"pwd")==0)_pwd();
			else _execute();
			break;
		case 'm':
			if(strncmp(cmd,"mkdir ",6)==0)_mkdir();
			else _execute();
			break;
		case 'r':
			if(strncmp(cmd,"rmdir ",6)==0)_rmdir();
			else _execute();
			break;
		default:
			if(debug)printf("in default\n");
			_execute();
			break;
	}
	if(pid==0){
		printf("[%d] Done %s\n",count,cmd);
		printf("myshell>");
		exit(0);
	}
	if(p2id!=0)wait(0);
	dup2(tempout, 1);
	if(tempout!=1 && tempout!=-1)close(tempout);
	dup2(tempin, 0);
	if(tempin!=0 && tempin!=-1)close(tempin);
	if(check)exit(0);
}
void int_handler(){
	if(debug)printf("Received SIGINT\n");
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	//debug=0;
	cmd=(char*)calloc(nbytes,sizeof(char));
	int bytes_read;
	size_t lim=199;
	count=0;
	signal(SIGINT,int_handler);
	while(1){
		printf("myshell>");
		if ( feof(stdin) ) exit(0);
		bytes_read = getline (&cmd, &nbytes, stdin);
		if(bytes_read==-1){
			perror("Could not read from stdin");
		}else{
			director();
		}
	}
	return 0;
}
