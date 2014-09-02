#include"knapsack.h"
#include<time.h>
int compItem(const void *i1 , const void *i2)
{
	return ((Item*)i2)->v/((Item*)i2)->w - ((Item*)i1)->v/((Item*)i1)->w;
}
void printItems(Item *itemList, int n)
{
	int i=0;
	printf("Items are : \n");
	for(i=0;i<n;i++) printf("\t%d.\tw:%d , v:%f\n",(i+1),itemList[i].w,itemList[i].v);
	printf("\n");
}
#define MAX_W 100
#define MAX_V 100
Item *generateItems(int n)
{
	srand(time(NULL));
	Item *arr=(Item*)calloc(n,sizeof(Item));
	int i=0;
	while(i<n){
		arr[i].v=(double)(rand()%MAX_V)*(rand()%10)/10+1;
		arr[i].w=(unsigned int)(rand()%MAX_W);
		i++;
	}
	printItems(arr,n);
	return arr;
}
double getFractionalSoln(Item* arr , int n , int W)
{
	qsort(arr,n,sizeof(Item),compItem);
	printf("After sorting , ");printItems(arr,n);
	double val=0;
	int w=0 ,i=0;
	do{
		val+=arr[i].v;
		w  +=arr[i].w;
		i++;
		printf("w=%f\n",w);
	}while(w<W && i<n);
	if(w<W){
		printf("Fractional Solution is %f.\n",w);
		return w;
	}
	i--;
	val-=arr[i].v;
	w  -=arr[i].w;
	val+=(W-w)*(arr[i].v)/(arr[i].w);
	printf("Fractional Solution is %f\n",val);
	return val;
}
double binarySoln(double *lookup , double *arr , int W , Item *item , int n)
{
	if(n==0) return lookup[W-1];
	int i,index;
	double  val;
	for(i=0;i<W;i++){
		index=i-item->w ; val=lookup[index]+item->v ;
		arr[i] = (index>=0 && lookup[i]>val) ? lookup[i] : val;
	}
	return binarySoln(arr,lookup,W,item+1,n-1);
}
double getBinarySoln(Item *itemArr , int n , int W)
{
	double *lookup= (double*)calloc(W,sizeof(double));
	double * arr  = (double*)calloc(W,sizeof(double));
	int i=0;
	while(i<itemArr->w && i<W) lookup[i++]=0;
	while(i<W) lookup[i++] = itemArr->v;
	double soln=binarySoln(lookup,arr,W,itemArr+1,n-1);
	printf("Binary Solution is %f\n",soln);
	return soln;
}

















