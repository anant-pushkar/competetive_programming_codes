#include"wis.h"
#include<time.h>
int scheduleCount;
int compEnd(const void *i1 , const void *i2)
{
	return((Interval*)i1)->end - ((Interval*)i2)->end;
}
#define MAX  1000
Interval* generateIntervalSet(int n)
{
	Interval *set = (Interval*)calloc(n,sizeof(Interval));
	srand(time(NULL));
	int i,a,b,c;
	for(i=0;i<n;i++){
		a=(int)rand()%MAX;
		b=(int)rand()%MAX;
		
		set[i].start = a>b ? b : a ;
		set[i].end   = a>b ? a : b ;
		set[i].weight= ((double)rand()/(double)RAND_MAX);
	}
	qsort(set,n,sizeof(Interval),compEnd);
	return set;
}
void printIntervalSet(Interval*set,int n)
{
	int i;
	for(i=0;i<n;i++) printf("%d:  (%d,%d):%f\n",i,set[i].start,set[i].end,set[i].weight);
}
int search(Interval *set , int lo , int hi , int k)
{
	if(lo+1==hi) return set[lo].end<=k ? lo : -1 ;
	
	int mid = (lo+hi)>>1; //mid=(lo+hi)/2;
	if(set[mid].end <=k && set[mid+1].end> k) return mid;
	if(set[mid].end < k && set[mid+1].end<=k) return search(set,mid,hi,k);
	if(set[mid].end > k) return search(set,lo,mid,k);
}
int *populatePrevious(Interval *set , int n)
{
	int *previous = (int*)calloc(n,sizeof(int)) , i;
	previous[0]=-1;
	for(i=1;i<n;i++) previous[i]=search(set,0,n,set[i].start);
	return previous;
}
void printfPrevious(int *previous , int n)
{
	int i;
	for(i=0;i<n;i++) printf("%d ",previous[i]);
	printf("\n");
}
int *getSchedule(double *lookup , int* previous , int n , int cnt)
{
	int i=n-1,count=0,index=0,*arr;
	if(cnt!=0) arr=(int*)calloc(cnt,sizeof(int));
	while(i>=0){
		if((i==0 && lookup[1]!=lookup[0])||lookup[i]!=lookup[i-1]){
			count++;
			if(cnt!=0){
				arr[index]=i;
				index++;
			}
			i=previous[i];
		}else i--;
	}
	scheduleCount=count;
	return arr;
}
int getScheduleCount(double* lookup , int* previous , int n)
{
	getSchedule(lookup,previous,n,0);
	return scheduleCount;
}
void traverse(Interval *set , int *previous , int n)
{
	double *lookup = (double*)calloc(n,sizeof(double)) ;
	int i=0 ;
	while(previous[i]==-1){
		lookup[i]=set[i].weight;
		i++;
	}
	for(;i<n;i++) lookup[i] = lookup[previous[i]]+set[i].weight<lookup[i-1] ? lookup[i-1] : lookup[previous[i]]+set[i].weight;
	printf("\nWeight found: %f\n",lookup[n-1]);
	int *sc = getSchedule(lookup,previous,n,getScheduleCount(lookup,previous,n));
	printf("Interval List : \n");
	double check=0;
	for(i=0;i<scheduleCount;i++){
		printf("%d : %f\n",sc[i],set[sc[i]].weight);
		check+=set[sc[i]].weight;
	}
	if(check==lookup[n-1])printf("Path successfuly retreived.\n");
	else printf("weight from path: %f\n",check);
	printf("Freeing memory.\n\n");
	free(lookup);free(set);free(previous);
}




