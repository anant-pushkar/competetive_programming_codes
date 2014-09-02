#include<stdio.h>
#include<stdlib.h>
#include <sys/ipc.h>
#include <unistd.h>
int main(){
	execlp("gnome-terminal","gnome-terminal","-e" , "bash -c \"./main 50\"",NULL); 
	return 0;
}