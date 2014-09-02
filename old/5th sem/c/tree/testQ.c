#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
int main()
{
	queue *q=initQ();
	
	int i;
	for(i=0;i<20;i++){
		enqueue(q,i);
		printf("%d added to queue\n\n",i);
	}
	for(i=0;i<20;i++){
		printf("Removing %d from queue\n",getFront(q));
		dequeue(q);
	}
	return 0;
}