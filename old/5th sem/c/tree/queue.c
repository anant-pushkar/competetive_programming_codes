#include"queue.h"
queue* initQ()
{
	queue *q = (queue*)malloc(sizeof(queue));
	q->front= NULL;
	q->back = NULL;
	q->size=0;
	return q;
}
void enqueue(queue *q , node* n,int level)
{
	link *newLink = (link*)malloc(sizeof(link));
	newLink->n = n;
	newLink->next=NULL;
	newLink->level=level;
	
	if(q->back==NULL){
		q->back = newLink;
		q->front= newLink;
	}else{
		q->back->next = newLink;
		q->back = q->back->next;
	}
	q->size++;
}
void dequeue(queue *q)
{
	if(q->front==NULL) return;
	link* ptr= q->front;
	q->front = q->front->next;
	q->size--;
	free(ptr);
}
node* getFront(queue *q)
{
	return q->front->n;
}
node* getBack(queue *q)
{
	return q->back->n;
}
int getFrontLevel(queue *q)
{
	return q->front->level;
}