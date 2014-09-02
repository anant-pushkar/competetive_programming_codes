/*
Project name : NOTATRI
Created on : Fri Mar 21 11:39:32 2014
Author : Anant Pushkar
binary search
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int *arr , n;
int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}
int search(int start,int end,int val){
	if(end-start<2){
		if(arr[start]>val)return start;
		if(end==n || arr[end]>val)return end;
		return end+1;
	}
	int mid=(start+end)/2;
	if(arr[mid]<val)return search(mid,end,val);
	if(arr[mid]>val)return search(start,mid,val);
	while(mid<n && arr[mid]==val)++mid;
	return mid;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int i,j,count,index,diff;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		arr=(int*)calloc(n,sizeof(int));
		
		for(i=0;i<n;++i)scanf("%d",&arr[i]);
		qsort(arr, n, sizeof(int), compare);
		
		count=0;
		for(i=0;i<n;++i){
			for(j=i+1;j<n;++j){
				diff=n-search(j+1,n,arr[i]+arr[j]);
				count+=diff>0 ? diff : 0;
			}
		}
		
		printf("%d\n",count);
		
		free(arr);
	}
	return 0;
}
