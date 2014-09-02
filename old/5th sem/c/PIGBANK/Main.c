#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int t,e,f,n,*w,*v;
int main(){
	scanf("%d",&t);
	int *arr,i,j,min=INT_MAX;
	while(t--){
		scanf("%d %d",&e,&f);f=f-e;
		scanf("%d",&n);
		w=(int*)calloc(n,sizeof(int));
		v=(int*)calloc(n,sizeof(int));
		
		for(i=0;i<n;++i)scanf("%d %d",&v[i],&w[i]);
		
		//for(i=0;i<n;++i)printf("v[%d]=%d , w[%d]=%d\n",i,v[i],i,w[i]);
		arr=(int*)calloc(f+1,sizeof(int));
		
		for(i=1;i<=f;++i){
			min=INT_MAX;
			for(j=0;j<n;++j)if(i-w[j]==0 || (i-w[j]>0 && arr[i-w[j]]!=0)){
				min=min>v[j]+arr[i-w[j]] ? v[j]+arr[i-w[j]] : min ;
			}
			arr[i]=min==INT_MAX?0:min;//printf("arr[%d]=%d(min=%d)\n",i,arr[i],min);
		}
		//printf("\n\n");
		//for(i=0;i<=f;++i)printf("%d\n",arr[i]);
		
		int soln=arr[f];
		if(soln!=0)printf("The minimum amount of money in the piggy-bank is %d.\n",soln);
		else printf("This is impossible.\n");
		
		free(w);free(v);free(arr);
	}
	return 0;
}