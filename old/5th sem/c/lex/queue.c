#include"queue.h"
queue* initQ()
{
	queue *q = (queue*)malloc(sizeof(queue));
	q->front= NULL;
	q->back = NULL;
	q->size=0;
	return q;
}
void enqueue(queue *q , int v)
{
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
void dequeue(queue *q)
{
	if(q->front==NULL) return;
	node* ptr= q->front;
	q->front = q->front->next;
	q->size--;
	free(ptr);
}
int getFront(queue *q)
{
	return q->front->val;
}
int getBack(queue *q)
{
	return q->back->val;
}