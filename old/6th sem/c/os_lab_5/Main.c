/*
Project name : os_lab_5
Created on : Sun Mar 16 12:39:14 2014
Author : Anant Pushkar
Dinning Philosopher Problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <signal.h>
#include <time.h>
#define P(s) semop(s, &pop, 1)
#define V(s) semop(s, &vop, 1)
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define N 5
#define LEFT (index+N-1)%N
#define RIGHT (index+1)%N

int debug=0;
int stateId , sId , mutexId;
struct sembuf pop, vop ;

void test(int index){
	int *state=(int *) shmat(stateId, 0, 0);
	int *s=(int *) shmat(sId, 0, 0);
	
	printf("Testing Philosopher#%d\n",index);
	if(state[index]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING){
		state[index]=EATING;
		printf("Philosopher#%d may eat now\n",index);
		V(s[index]);
	}
}

void take_forks(int index){
	int *state=(int *) shmat(stateId, 0, 0);
	int *s=(int *) shmat(sId, 0, 0);
	int *mutex=(int *) shmat(mutexId, 0, 0);
	
	printf("Philosopher#%d attempts to take forks\n",index);
	P(*mutex);
	state[index]=HUNGRY;
	test(index);
	V(*mutex);
	P(s[index]);
	printf("Philosopher#%d takes both forks\n",index);
}

void put_forks(int index){
	int *state=(int *) shmat(stateId, 0, 0);
	int *s=(int *) shmat(sId, 0, 0);
	int *mutex=(int *) shmat(mutexId, 0, 0);
	
	P(*mutex);
	state[index]=THINKING;
	test(LEFT);
	test(RIGHT);
	V(*mutex);
	printf("Philosopher#%d puts both forks\n",index);
}

void think(int index){
	printf("Philosopher#%d is thinking\n",index);
	sleep(rand()%2);
}

void eat(int index){
	printf("Philosopher#%d is eating\n",index);
	sleep(rand()%2);
}

void philosopher(int index){
	while(1){
		think(index);
		take_forks(index);
		eat(index);
		put_forks(index);
	}
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	srand(time(NULL));
	
	stateId=shmget(IPC_PRIVATE, N*sizeof(int), 0777|IPC_CREAT);
	int *state=(int *) shmat(stateId, 0, 0);
	
	sId=shmget(IPC_PRIVATE, N*sizeof(int), 0777|IPC_CREAT);
	int *s=(int *) shmat(sId, 0, 0);
	
	mutexId=shmget(IPC_PRIVATE, sizeof(int), 0777|IPC_CREAT);
	int *mutex=(int *) shmat(mutexId, 0, 0);
	
	*mutex=semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	semctl(*mutex, 0, SETVAL, 1);
	
	int i;
	for(i=0;i<N;++i){
		s[i]=semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
		semctl(s[i], 0, SETVAL, 0);
	}
	
	pop.sem_num = vop.sem_num = 0;
	pop.sem_flg = vop.sem_flg = 0;
	pop.sem_op = -1 ; vop.sem_op = 1 ;
	
	for(i=0;i<N;++i){
		if(fork()==0){
			state[i]=THINKING;
			philosopher(i);
		}
	}
	
	int status;
	for(i=0;i<N;++i)wait(&status);
	
	shmctl(sId, IPC_RMID, 0);
	shmctl(mutexId, IPC_RMID, 0);
	shmctl(stateId, IPC_RMID, 0);
	
	semctl(*mutex, 0, IPC_RMID, 0);
	for(i=0;i<N;++i){
		semctl(s[i], 0, IPC_RMID, 0);
	}
	
	return 0;
}

