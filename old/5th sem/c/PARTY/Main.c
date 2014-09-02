#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int cost , n , *fee , *fun;
void printMaxFun(int* lookup , int *arr , int*lookupCost , int*arrCost , int index){
	if(index==n){
		printf("%d %d\n",lookupCost[cost],lookup[cost]);
		return;
	}
	int i=0,val,nextCost;
	while(i<fee[index]){
		arrCost[i]=lookupCost[i];
		arr[i]=lookup[i];
		++i;
	}
	while(i<=cost){
		val  = fun[index] + lookup[i-fee[index]];
		nextCost = fee[index] + lookupCost[i-fee[index]];
		if(val>lookup[i] || (val==lookup[i] && nextCost<lookupCost[i])){
			arr[i] = val;
			arrCost[i] = nextCost;
		}else{
			arr[i]=lookup[i];
			arrCost[i] = lookupCost[i];
		}
		++i;
	}
	printMaxFun(arr,lookup,arrCost,lookupCost,index+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int *lookup,*arr,*lookupCost,*arrCost;
	char c;
	while(1){
		scanf("%d %d",&cost,&n);
		if(cost==0 && n==0) break;
		fee=(int*)calloc(n,sizeof(int));
		fun=(int*)calloc(n,sizeof(int));
		
		int i=0;
		for(;i<n;++i) scanf("%d %d",&fee[i],&fun[i]);
		scanf("%c",&c);
		
		lookup = (int*)calloc(cost+1,sizeof(int));
		arr    = (int*)calloc(cost+1,sizeof(int));
		lookupCost = (int*)calloc(cost+1,sizeof(int));
		arrCost    = (int*)calloc(cost+1,sizeof(int));
		
		i=0;
		while(i<fee[0]){
			lookupCost[i]=0;
			lookup[i++]=0;
		}
		while(i<=cost){
			lookupCost[i]=fee[0];
			lookup[i++]=fun[0];
		}
		
		printMaxFun(lookup,arr,lookupCost,arrCost,1);
		
		free(fee);
		free(fun);
	}
	return 0;
}

