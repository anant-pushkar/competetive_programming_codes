#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int stuffLeft;
	int stuffReq;
	int doughAmt;
	int cost;
}Bun;
Bun bunArr[11];
int n,m,c0,d0;
int getMax(int *lookup , int *arr , int index){
	if(index==m+1){
		return lookup[n];
	}
	//printf("populating at %d\n",index);
	int idx,i=0,qty=bunArr[index].stuffLeft/bunArr[index].stuffReq,val,maxVal;
	//for(i=0;i<=n;i++) printf("%d ",lookup[i]);
	//printf("\n");
	for(i=0;i<=n;++i){
		maxVal=-1;
		qty=bunArr[index].stuffLeft/bunArr[index].stuffReq;
		while(qty>=0){
			idx=i-qty*bunArr[index].doughAmt;
			if(idx>=0){
				maxVal = maxVal<lookup[idx]+qty*bunArr[index].cost ? lookup[idx]+qty*bunArr[index].cost : maxVal ;
			}
			--qty;
		}
		arr[i] = maxVal;
	}
	return getMax(arr,lookup,index+1);
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c0,&d0);
	bunArr[0].stuffLeft= -1;
	bunArr[0].stuffReq = -1;
	bunArr[0].doughAmt = c0;
	bunArr[0].cost     = d0;
	int i=1;
	for(;i<=m;++i){
		scanf("%d %d %d %d",&bunArr[i].stuffLeft,&bunArr[i].stuffReq,&bunArr[i].doughAmt,&bunArr[i].cost);
	}
	int* lookup=(int*)calloc(n+1,sizeof(int)) , *arr=(int*)calloc(n+1,sizeof(int));
	int expCount;
	//printf("Prepopulating lookup\n");
	for(i=0;i<=n;++i){
		expCount=i/bunArr[0].doughAmt;
		if(bunArr[i].stuffLeft>=expCount*bunArr[i].stuffReq){
			lookup[i]=bunArr[0].cost*expCount;
		}
	}
	printf("%d\n",getMax(lookup,arr,1));
	return 0;
}

