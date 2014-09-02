#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,k,i,countInc,countDec;scanf("%d",&t);
	char *arr,cMax,cMin;
	while(t){
		scanf("%d",&n);
		scanf("%d",&k);
		arr=(char*)calloc(n,sizeof(char));
		for(i=0;i<n;++i){
			scanf("%c",&arr[i]);
		}
		countInc=0;countDec=0;cMin=arr[0];cMax=arr[0];
		for(i=1;i<n;++i){
			if(arr[i]-cMin>0){
				countDec+=2;
			}else{
				cMin=arr[i];
			}
			if(cMax-arr[i]>0){
				countInc+=2;
			}else{
				cMax=arr[i];
			}
		}
		int count=countDec<countInc+1 ? countDec : countInc+1;
		printf("%d\n",count);
		--t;
		scanf("%c",&arr[0]);scanf("%c",&arr[0]);
		free(arr);
	}
	return 0;
}
