/*
Project name : os_Assignment_4
Created on : Tue Mar  4 16:45:23 2014
to compile: gcc parMergeSort.c -o out
to run : ./out
to run in debug mode : ./out DEBUG
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<time.h>
#include<signal.h>
#define MAX 1000000
#define ML 10
#define ms 10
int debug=0;
int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}
void merge_back(int shmid , int rid, int sid){
	int *state=(int *) shmat(rid, 0, 0) ;
	int start=state[0] , end=state[1];
	
	int *arr=(int *) shmat(shmid, 0, 0) ;
	int mid=(end+start)/2 ;
	
	int i=mid-1 , j=end-1 , idx=0;
	int*temp=(int*)calloc(end-mid,sizeof(int));
	while(i>=start && j>=mid && idx<end-mid){
		//printf("%d , %d\n",arr[i],arr[j]);
		if(arr[i]>=arr[j]){
			temp[idx++]=arr[i--];
		}else{
			temp[idx++]=arr[j--];
		}
	}
	while(i>=start && idx<end-mid){
		temp[idx++]=arr[i--];
	}
	while(j>=mid && idx<end-mid){
		temp[idx++]=arr[j--];
	}
	state=(int *) shmat(sid, 0, 0) ;
	state[0]=1;
	while(state[1]==0);
	
	if(debug)printf("%d-%d Backward merge : ",start,end);
	for(i=mid;i<end;++i){
		arr[i]=temp[end-i-1];
		if(debug)printf("%d ",arr[i]);
	}
	if(debug)printf("\n\n");
	free(temp);
}
void merge_front(int shmid , int rid , int sid){
	int *state=(int *) shmat(rid, 0, 0) ;
	int start=state[0] , end=state[1];
	
	int *arr=(int *) shmat(shmid, 0, 0) ;
	int mid=(end+start)/2 ;
	
	int i=start , j=mid , idx=0;
	int*temp=(int*)calloc(mid-start,sizeof(int));
	/*printf("%d-%d input : ",start,end);
	for(i=start;i<end;++i)printf("%d ",arr[i]);
	printf("\n");
	i=start;*/
	while(i<mid && j<end && idx<mid-start){
		//printf("%d(%d) , %d(%d)\n",arr[i],i,arr[j],j);
		if(arr[i]<arr[j]){
			temp[idx++]=arr[i++];
		}else{
			temp[idx++]=arr[j++];
		}
	}
	while(i<mid && idx<mid-start){
		temp[idx++]=arr[i++];
	}
	while(j<end && idx<mid-start){
		temp[idx++]=arr[j++];
	}
	
	state=(int *) shmat(sid, 0, 0) ;
	state[1]=1;
	while(state[0]==0)if(debug)printf("Syncing for write after merge\n");
	
	if(debug)printf("%d-%d Forward merge : ",start,end);
	for(i=start;i<mid;++i){
		arr[i]=temp[i-start];
		if(debug)printf("%d ",arr[i]);
	}
	if(debug)printf("\n\n");
	free(temp);
}
void sort(int shmid , int s , int e , int l , int mid, int index , int rid , int sid){
	int *arr=(int *) shmat(shmid, 0, 0) , status , *init;
	if(l>ML || e-s<ms){
		if(index==1)exit(0);
		int *state=(int *) shmat(rid, 0, 0) ;
		int start=state[0] , end=state[1];
		qsort(arr+start,(end-start),sizeof(int),compare);
		exit(0);
	}else{
		int memid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);
		init=(int *) shmat(memid, 0, 0) ;
		init[0]=0;init[1]=0;
		
		int rangeid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);
		init=(int *) shmat(rangeid, 0, 0) ;
		init[0]=s;init[1]=e;
		
		int syncid = shmget(IPC_PRIVATE, 2*sizeof(int), 0777|IPC_CREAT);
		init=(int *) shmat(syncid, 0, 0) ;
		init[0]=0;init[1]=0;
		
		if(fork()==0)sort(shmid,s,(s+e)/2,l+1,memid,0,rangeid,syncid);
		else{
			if(fork()==0)sort(shmid,(s+e)/2,e,l+1,memid,1,rangeid,syncid);
			else{
				wait(&status);wait(&status);
			}
		}
		if(mid==-1)return;
		int *state=(int *) shmat(mid, 0, 0) ;
		state[index]=1;
		while(state[1-index]==0)if(debug)printf("syncing before merge\n");
		
		shmctl(memid, IPC_RMID, 0);
		shmctl(rangeid, IPC_RMID, 0);
		shmctl(syncid, IPC_RMID, 0);
	}
	
	if(index==0)merge_front(shmid,rid,sid);
	else merge_back(shmid,rid,sid);
	
	exit(0);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	int n;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	
	int shmid = shmget(IPC_PRIVATE, n*sizeof(int), 0777|IPC_CREAT);
	
	if(fork()==0){
		sleep(1);
		sort(shmid,0,n,0,-1,-1,-1,-1);
		int *arr=(int *) shmat(shmid, 0, 0) , i ;
		
		FILE *optr;
		if(n>100)optr=fopen("output","w+");
		else optr=stdout;
		
		fprintf(optr,"Sorted Array : ");
		for(i=0;i<n;++i){
			fprintf(optr,"%d ",arr[i]);
		}
		fprintf(optr,"\n");
	}else{
		int *arr=(int *) shmat(shmid, 0, 0) , i , status;
		srand(time(NULL));
		for(i=0;i<n;++i){
			arr[i]=rand()%MAX;
		}
		FILE *iptr;
		if(n>100)iptr=fopen("input","w+");
		else iptr=stdout;
		
		fprintf(iptr,"Generated Array : ");
		for(i=0;i<n;++i){
			fprintf(iptr,"%d ",arr[i]);
		}
		fprintf(iptr,"\n\n");
		wait(&status);
	}
	shmctl(shmid, IPC_RMID, 0);
	
	return 0;
}

