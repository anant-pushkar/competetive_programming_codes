#include"sort.h"
#include<stdio.h>
#include<time.h>
int comp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
void Sort(Array arr , int opt)
{
	switch(opt){
	case 1: 
		_mergeSort(arr.head,0,arr.count);
		break;
	case 2:
		_heapSort(&arr);
		break;
	case 3:
		_quickSort(&arr,0,arr.count);
		break;
	case 4:
		qsort(arr.head,arr.count,sizeof(int),comp);
		break;
	}
}
void _mergeSort(int* arr, long int start, long int end)
{
	if(end>start+1){
		long int mid=(start+end)>>1;
		_mergeSort(arr,start,mid);//sort left half
		_mergeSort(arr,mid,end);//sort right half
		_merge(arr,start,end);//merge
	}
}
void _merge(int* arr, long int start, long int end)
{
	long int mid=(start+end)>>1,i=start,j=mid,k=0;
	int *temp=(int*)calloc(end-start,sizeof(int));
	while(i<mid && j<end){
		if(arr[i]< arr[j]) temp[k++]=arr[i++];
		if(arr[i]>=arr[j]) temp[k++]=arr[j++];
	}
	while(i<mid) temp[k++]=arr[i++];
	while(j<end) temp[k++]=arr[j++];
	for(i=0;i<end-start;i++) arr[start+i]=temp[i];
	free(temp);
}
Array* initPq(int n)
{
	Array *ptr=(Array*)malloc(sizeof(Array));
	ptr->count=n;
	ptr->head=(int*)calloc(ptr->count,sizeof(int));
	return ptr;
}
Array* makeHeap(Array *arrPtr)
{
	int i,j;
	for(i=arrPtr->count-1;i>-1;i--)
		heapify(arrPtr,i);
}
void _heapSort(Array *arrPtr)
{
	int i,min,n=arrPtr->count;
	makeHeap(arrPtr);
	for(i=0;i<n;i++){
		min=extractMin(arrPtr);
		arrPtr->head[n-i-1]=min;
	}
	arrPtr->count=n;
	for(i=0;i<(n>>1);i++) swap(arrPtr,i,n-i-1);
}
void heapify(Array *ptr , int index)
{
	if(2*index+1>=ptr->count) return;
	int minIndex = ptr->head[2*index+1]<ptr->head[index] ? 2*index+1 : index ;
	if(2*index+2<ptr->count)
		minIndex = ptr->head[2*index+2]<ptr->head[minIndex] ? 2*index+2 : minIndex ;
	if(minIndex!=index){
		swap(ptr,index,minIndex);
		heapify(ptr,minIndex);
	}
}
void swap(Array* ptr, int a , int b)
{
	int c=ptr->head[a];
	ptr->head[a]=ptr->head[b];
	ptr->head[b]=c;
}
int extractMin(Array *ptr)
{
	int min=ptr->head[0];
	ptr->head[0]=ptr->head[ptr->count-1];
	ptr->count--;
	heapify(ptr,0);
	return min;
}
void insert(Array *ptr , int n)
{
	ptr->count++;
	ptr->head=(int*)realloc(ptr->head,ptr->count*sizeof(int));
	ptr->head[ptr->count-1]=n;
	bubbleUp(ptr,ptr->count-1);
}
void bubbleUp(Array *ptr , int i)
{
	int parent=i>>1;
	if(ptr->head[parent] > ptr->head[i]){
		swap(ptr,parent,i);
		bubbleUp(ptr,parent);
	}
}
int countLessThan(Array *ptr,int x,int count,int index)
{
	if(count<=0 || index>=ptr->count) return count;
	if(ptr->head[index]<x){
		count=countLessThan(ptr,x,count-1,2*index+1);
		count=countLessThan(ptr,x,count  ,2*index+2);
	}
	return count;
}
void _quickSort(Array *arrPtr ,int start , int end)
{
	if(end-start<2) return;
	int index=(int)(rand()%(end-start-1)+start);
	int pivot=arrPtr->head[index] , i=start , j=end-1 , x ;
	while(1){
		while(arrPtr->head[i]<=pivot) i++;
		while(arrPtr->head[j]> pivot) j--;
		if(i>j) break;
		swap(arrPtr,i,j);
	}
	for(x=start;x<j;x++) if(arrPtr->head[x]==pivot) {swap(arrPtr,x,j);j--;}
	_quickSort(arrPtr,start,j+1);
	_quickSort(arrPtr,i , end);
}























