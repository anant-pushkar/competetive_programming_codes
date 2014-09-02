/*
Project name : OS_lab5_part2
Created on : Wed Mar 19 09:53:55 2014
Author : Anant Pushkar
dining philosoher with deadlock handling
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
#define LEFT index
#define RIGHT (index+1)%N
int debug=0;
struct sembuf pop, vop ;
int adjId[N],pID[N],stateId,forkMutexId,graphID;
void eat(int index){
	printf("Philosopher %d is eating\n",index);
	sleep(1);
}
void think(int index){
	printf("Philosopher %d is thinking\n",index);
	sleep(1);
}
void philosopher(int index){
	int *state=(int *) shmat(stateId, 0, 0);
	int *forkMutex=(int *) shmat(forkMutexId, 0, 0);
	int *arr=(int *) shmat(adjId[index], 0, 0);
	
	while(1){
		P(graphID);arr[LEFT]=1;V(graphID);
		if(debug)printf("Philosopher %d waits for left fork(%d)\n",index,LEFT);
		P(forkMutex[LEFT]);
		
		printf("Philosopher %d grabs left fork(%d)\n",index,LEFT);
		P(graphID);arr[LEFT]=-1;V(graphID);
		
		sleep(1);
		
		P(graphID);arr[RIGHT]=1;V(graphID);
		if(debug)printf("Philosopher %d waits for right fork(%d)\n",index,RIGHT);
		P(forkMutex[RIGHT]);
		P(graphID);if(arr[LEFT]==0){
			V(graphID);
			continue;
		}
		V(graphID);
		printf("Philosopher %d grabs right fork(%d)\n",index,RIGHT);
		P(graphID);arr[RIGHT]=-1;V(graphID);
		
		P(graphID);
		if(arr[LEFT]==-1 && arr[RIGHT]==-1){
			V(graphID);
			eat(index);
		}
		P(graphID);
		if(arr[LEFT]!=-1 || arr[RIGHT]!=-1){
			V(graphID);
			continue;
		}
		V(graphID);
		P(graphID);arr[LEFT]=0;V(graphID);
		V(forkMutex[LEFT]);
		printf("Philosopher %d has released left fork(%d)\n",index,LEFT);
		
		P(graphID);arr[RIGHT]=0;V(graphID);
		V(forkMutex[RIGHT]);
		printf("Philosopher %d has released right fork(%d)\n",index,RIGHT);
		
		think(index);
	}
}
void exit_all(int sigid){
	printf("Killing philosophers\n");
	int i;
	int *forkMutex=(int *) shmat(forkMutexId, 0, 0);
	for(i=0;i<N;++i){
		kill(pID[i],SIGKILL);
		shmctl(adjId[i], IPC_RMID, 0);
		semctl(forkMutex[i], 0, IPC_RMID, 0);
	}
	shmctl(forkMutexId, IPC_RMID, 0);
	shmctl(stateId, IPC_RMID, 0);
	shmctl(graphID, IPC_RMID, 0);
	printf("Exting\n");
	exit(0);
}
void detect_deadlock(){
	int**adjMat=(int**)calloc(N,sizeof(int*));
	int *forkMutex=(int *) shmat(forkMutexId, 0, 0);
	int i,j,k;
	
	for(i=0;i<N;++i){
		adjMat[i]=(int *) shmat(adjId[i], 0, 0);
	}
	
	int index;
	for(i=0;i<N;++i){
		index=i;
		while(1){
			for(j=0;j<N;++j){
				P(graphID);
				if(adjMat[index][j]==1){
					V(graphID);
					break;
				}
				V(graphID);
			}
			if(debug)if(j!=N)printf("%d waiting for %d\n",index,j);
			P(graphID);
			for(k=0;k<N && j<N;++k){
				if(adjMat[k][j]==-1){
					if(debug)printf("%d holding %d\n",k,j);
					index=k;
					if(index==i){
						printf("Deadlock detected.Preempting philosopher %d\n",i);
						for(j=0;j<N;++j)if(adjMat[i][j]==-1){
							printf("Philosopher %d releases fork %d\n",i,j);
							adjMat[i][j]=0;
							V(forkMutex[j]);
						}
						V(graphID);
						return;
					}
					break;
				}
			}
			V(graphID);
			if(debug)printf("i=%d j=%d k=%d\n",i,j,k);
			if(j==N || k==N){
				if(debug)printf("no deadlock\n");
				/*P(graphID);
				for(j=0;j<N;++j){
					if(adjMat[index][j]==1){
						break;
					}
				}
				for(k=0;k<N && j<N;++k)if(adjMat[k][j]==-1)break;
				V(graphID);
				if(j!=N && k==N){
					if(debug)printf("Realeasing fork %d\n",j);
					V(forkMutex[j]);
				}*/
				break;
			}
		}
	}
	printf("No deadlocks detected\n\n");
}
void check(){
	while(1){
		detect_deadlock();
		sleep(5);
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	pop.sem_num = vop.sem_num = 0;
	pop.sem_flg = vop.sem_flg = 0;
	pop.sem_op = -1 ; vop.sem_op = 1 ;
	
	srand(time(NULL));
	
	stateId=shmget(IPC_PRIVATE, N*sizeof(int), 0777|IPC_CREAT);
	int *state=(int *) shmat(stateId, 0, 0);
	
	forkMutexId=shmget(IPC_PRIVATE, N*sizeof(int), 0777|IPC_CREAT);
	int *forkMutex=(int *) shmat(forkMutexId, 0, 0);
	
	graphID=semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
	semctl(graphID, 0, SETVAL, 1);
	
	int i,j,*arr;
	for(i=0;i<N;++i){
		adjId[i]=shmget(IPC_PRIVATE, N*sizeof(int), 0777|IPC_CREAT);
		arr=(int *) shmat(adjId[i], 0, 0);
		memset(arr,0,N*sizeof(int));
		
		forkMutex[i]=semget(IPC_PRIVATE, 1, 0777|IPC_CREAT);
		semctl(forkMutex[i], 0, SETVAL, 1);
	}	
	for(i=0;i<N;++i){
		pID[i]=fork();
		if(pID[i]==0){
			state[i]=THINKING;
			philosopher(i);
		}
	}
	signal(SIGKILL,exit_all);
	signal(SIGSEGV,exit_all);
	signal(SIGINT,exit_all);
	check();
	for(i=0;i<N;++i){
		shmctl(adjId[i], IPC_RMID, 0);
		semctl(forkMutex[i], 0, IPC_RMID, 0);
	}
	shmctl(forkMutexId, IPC_RMID, 0);
	shmctl(stateId, IPC_RMID, 0);
	shmctl(graphID, IPC_RMID, 0);
	
	return 0;
}
