#include<stdio.h>
#include<time.h>
#include"sort.h"
int arrSize,maxVal,*arr,opt;
void refresh()
{
	int i=0;
	for(i=0;i<arrSize;i++) arr[i]=rand()%maxVal;
}
int main()
{
	srand(time(NULL));
	printf("Enter array size: ");scanf("%d",&arrSize);
	printf("Enter Max value of Elements: ");scanf("%d",&maxVal);	
	printf("Enter 1:Merge sort 2:Heapsort 3:quicksort 4:qsort : ");scanf("%d",&opt);
	arr=(int*)calloc(arrSize,sizeof(int));
	Array arrObj;arrObj.count=arrSize;arrObj.head=arr;
	
	clock_t  tic , toc;
	
	refresh();
	tic = clock();
	Sort(arrObj,opt);
	toc = clock();
	printf("Time Elapsed : %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);`
	
	return 0;
}
