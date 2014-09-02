/*
Project name : ABCDEF
Created on : Tue May  6 17:04:38 2014
Author : Anant Pushkar
binary search
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
struct _node{
	int val;
	struct _node *next;
};
typedef struct _node node;
struct _queue{
	node *front;
	node *back;
	int size;
};
typedef struct _queue queue;
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
void dequeue(queue *q){
	if(q->front==NULL) return;
	node* ptr= q->front;
	q->front = q->front->next;
	q->size--;
	free(ptr);
}
int getFront(queue *q){
	return q->front->val;
}
int arr[100];
int sum[1000000];
int n;
int search(int k){
	int s=0 , e=n , m;
	while(e-s>1){
		m = (e+s)/2;
		if(arr[m]==k)return 1;
		if(arr[m]<k)s=m;
		else e=m;
	}
	return arr[s]==k;
}
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int j , k , s;
	lld index , i=0;
	while(scanf("%d",&arr[i++])==1);
	n=i;
	index=0;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			for(k=0;k<n;++k){
				sum[index++] = arr[i]*arr[j] + arr[k] ;
			}
		}
	}
	queue *q = initQ();
	for(i=0;i<index;++i){
		for(j=0;j<n;++j)if(arr[j]!=0 && sum[i]%arr[j]==0){
			enqueue(q,sum[i]);
		}
	}
	lld count=0;
	qsort(arr,n,sizeof(int),cmpfunc);
	while(q->size>0){
		s=getFront(q);
		if(debug)printf("checking %d\n",s-arr[i]);
		dequeue(q);
		for(i=0;i<n;++i)if(search(s-arr[i])==1)++count;
	}
	printf("%lld\n",count);
	return 0;
}
