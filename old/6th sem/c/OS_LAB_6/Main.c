/*
Project name : OS_LAB_6
Created on : Thu Apr 10 14:03:33 2014
Author : Anant Pushkar
multi-threaded ticket-reservation system
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#define down(s) semop(s, &pop, 1)
#define up(s) semop(s, &vop, 1)
#define t 100
#define c 500
#define k_range 5
#define k_min 5
#define s 20
#define MAX 5
#define T 120
#define sleep_max 5
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

typedef struct{
	int type;
	int ticket;
	int train;
	int response;
} Query;

Query *query_list;
pthread_mutex_t *lock;
int *taken;

struct _node{
	int val;
	struct _node *next;
};
typedef struct _node node;

typedef struct{
	node *front;
	node *back;
	int size;
}queue;

queue* initQ(){
	queue *q = (queue*)malloc(sizeof(queue));
	q->front= NULL;
	q->back = NULL;
	q->size=0;
	return q;
}

void enqueue(queue *q , int v){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->val = v;
	newnode->next=NULL;
	
	if(q->size==0){
		q->back = newnode;
		q->front= newnode;
	}else{
		q->back->next = newnode;
		q->back = q->back->next;
	}
	q->size++;
}

int dequeue(queue *q){
	if(q->front==NULL) return;
	node* ptr= q->front;
	q->front = q->front->next;
	q->size--;
	int val = ptr->val;
	free(ptr);
	return val;
}

int getFront(queue *q){
	return q->front->val;
}

int getBack(queue *q){
	return q->back->val;
}

int debug = 0;
int *available;
int active = 0;

int get_index(){
	while(1){
		sleep( rand() % sleep_max );
		int i;
		for(i=0;i<MAX;++i){
			if( taken[i] == 0 ) {
				pthread_mutex_lock(&lock[i]);
				if(taken[i] == 0){
					return i;
				}
			}
		}
	}
}

void book_tickets(int index , queue* ticket_list , int id){
	int train = rand() % t;
	int n_tickets = query_list[index].response ;
	while(available[train] <=0 )train = rand() % t;
	query_list[index].train =  train;
	query_list[index].response = -1;
	
	int k = (rand() % k_range) + k_min;
	query_list[index].ticket = k;
	printf("Thread#%d : Booking %d tickets in train#%d , queryNo : %d\n" , id, k , query_list[index].train , index);
	
	taken[index] = -1;
	printf("Thread#%d : sleeping to simulate transaction\n" , id);
	pthread_mutex_unlock(&lock[index]);
	sleep( rand() % sleep_max );
	if(debug)printf("lock %d released\n" , index);
	
	while(query_list[index].response==-1){
		sleep(rand() % sleep_max);
	}
	int ticket_num = query_list[index].ticket;
	printf("\n\n\n");
	printf("Thread#%d : %d tickets booked in train#%d\n",id ,n_tickets, query_list[index].train);
	printf("\n\n\n");
	
	int i;
	for(i=0;i<query_list[index].response;++i){
		printf("Thread#%d : ticket#%d addedto ticket list\n" , id , ticket_num + i);
		enqueue( ticket_list, ticket_num + i );
	}
	
	printf("Thread#%d : sleeping at the end of query\n" , id);
	pthread_mutex_unlock(&lock[index]);
}

void cancel_ticket(int index , int ticket_num , int id){
	query_list[index].response = -1;
	query_list[index].ticket   = ticket_num;
	printf("Thread#%d : Canceling ticket#%d\n", id , ticket_num);
	
	taken[index] = -1;
	pthread_mutex_unlock(&lock[index]);
	if(debug)printf("lock %d released\n" , index);
	
	while(query_list[index].response==-1){
		sleep(rand() % sleep_max);
	}
	printf("\n\n\n");
	printf("Thread#%d : ticket #%d canceled\n" , id , ticket_num);
	printf("\n\n\n");
}

void worker(void* ptr){
	queue** list = (queue**) calloc(s , sizeof(queue*));
	int i;
	for(i=0;i<s;++i)list[i] = initQ();
	Query q;
	
	int type;
	int index[MAX];
	while(active){
		if(debug)printf("worker : %d\n" , ((int*)ptr));
		type = rand() % 3;
		if(type==0){
			int train = rand() % t ;
			printf("Thread#%d : Enquiring availibility for train#%d\n", (int)ptr , train);
			sleep( rand() % sleep_max );
			printf("\n\n\n");
			printf("Thread#%d : Availibility in train#%d : %d\n", (int)ptr , train , available[train]);
			printf("\n\n\n");
			continue;
		}
		if(list[(int)ptr]->size == 0 && type != 1){
			printf("Thread#%d : No tickets to cancel, booking new ones instead\n", (int)ptr);
			type = 1;
		}
		
		printf("Thread#%d : sleeping untill active slot is available\n" , (int)ptr);
		index[(int)ptr] = get_index();
		
		taken[index[(int)ptr]] = 1;
		if(debug)printf("lock %d acquired by %d\n" , index[(int)ptr] , (int)ptr);
		
		query_list[index[(int)ptr]].type = type;
		if(type==1)book_tickets(index[(int)ptr] , list[(int)ptr] , (int)ptr);
		else cancel_ticket(index[(int)ptr] , dequeue(list[(int)ptr]) , (int)ptr);
	}
	printf("Worker#%d exiting\n" , *((int*)ptr));
}

void init(){
	int i;
	
	available = ( int* ) calloc( t , sizeof(int) );
	for(i=0;i<t;++i){
		available[i] = c ;
	}
	
	query_list = (Query*) calloc( MAX , sizeof(Query) );
	lock = (pthread_mutex_t*) calloc( MAX , sizeof(pthread_mutex_t) );
	taken = (int*) calloc( MAX ,sizeof(int) );
	
	for(i=0;i<MAX;++i){
		pthread_mutex_init(&lock[i], NULL);
	}
	
	active = 1;
	srand( time(NULL) );
}
int*lookup;
void process(void* ptr){
	int k ,i = (int)ptr, train= query_list[i].train , count;
	if(debug)printf("Main acquired lock %d\n" , i);
	
	switch(query_list[i].type){
	case 1:
		k = query_list[i].ticket ;
		count = 0;
		
		printf("\t\tChecking for concurrent queries on same train\n");
		if(lookup[train] == 1){
			printf("\t\tProceeding to next query\n");
			return ;
		}
		
		while(lookup[train] == 1)sleep(1);
		lookup[train] = 1;
		if(debug)printf("Processing book request on train#%d : %d books\n",train,k);
		
		query_list[i].ticket = train * 1000 + available[train] ;
		available[train] -= k;
		if(available[train] < 0){
			if(debug)printf("cannot book all tickets\n");
			count = -available[train];
			available[train] = 0;
		}
		
		if(debug)printf("count = %d , k = %d\n" , count , k);
		
		query_list[i].response = k - count;
		break;
	default:
		train = query_list[i].ticket / 1000;
		printf("\t\tChecking for concurrent queries on same train\n");
		if(lookup[train] == 1){
			printf("\t\tProceeding to next query\n");
			return ;
		}
		lookup[train] = 1;
		--available[train];
		query_list[i].response = 1;
		break;
	}
	lookup[train] = 0;
}

int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	
	init();
	
	time_t start, stop;
	time(&start);
	if(debug)printf("Starting at %d\n" , (int) start);
	
	int i;
	pthread_t threads[s];
	for(i=0;i<s;++i){
		pthread_create (&threads[i] , 0 , (void *) &worker, (void*)i );
	}
	
	time(&stop);
	lookup = (int*)calloc(t,sizeof(int));
	while(stop-start < T){
		printf("Running active queries:\n");
		for(i=0;i<MAX;++i)if(taken[i] == -1){
			printf("Starting query#%d\n" , i);
			pthread_mutex_lock(&lock[i]);
			taken[i] = 1;
			
			printf("\tProcessing query : %d\n" , i);
			pthread_t th;
			pthread_create( &th , 0 , (void*) &process , (void*)i );
			//process((void*)i);
			
			taken[i] = 0;
			pthread_mutex_unlock(&lock[i]);
			
			if(debug)printf("Main released lock %d\n" , i);
		}
		sleep( rand() % sleep_max );
		time(&stop);
	}
	if(debug)printf("Stopping at %d\n" , (int)stop);
	active=0;
	
	for(i=0;i<t;++i){
		printf("train#%d : %d seats left\n" , i , available[i]);
	}
	
	for(i=0;i<MAX;++i){
		printf("Destroying mutex#%d\n",i);
		pthread_mutex_destroy(&lock[i]);
	}
	for(i=0;i<s;++i){
		pthread_cancel(threads[i]);
	}
	
	return 0;
}
