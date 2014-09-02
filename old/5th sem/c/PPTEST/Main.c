#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef struct{
	int w;
	int v;
}Item;
int binarySoln(int *lookup , int *arr , int W , Item *item , int n)
{
	int j=0;
	if(debug)for(;j<=W;++j)printf(" %d",lookup[j]);
	if(debug)printf("\n");
	if(n==0) return lookup[W];
	int i,index;
	int  val;
	for(i=0;i<=W;i++){
		index=i-item->w ;
		if(index>=0) {
			val=lookup[index]+item->v ;
			arr[i] = lookup[i]<val ? val : lookup[i];
		}else{
			arr[i] = lookup[i];
		}
	}
	return binarySoln(arr,lookup,W,item+1,n-1);
}
int getBinarySoln(Item *itemArr , int n , int W)
{
	int *lookup= (int*)calloc(W+1,sizeof(int));
	int * arr  = (int*)calloc(W+1,sizeof(int));
	int i=0;
	while(i<itemArr->w && i<=W) lookup[i++]=0;
	while(i<=W) lookup[i++] = itemArr->v;
	int soln=binarySoln(lookup,arr,W,itemArr+1,n-1);
	return soln;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,c,p,time,n,w,soln,i;scanf("%d",&t);
	Item* itemArr;
	while(t--){
		scanf("%d %d",&n,&w);
		itemArr=(Item*)calloc(n,sizeof(Item));
		for(i=0;i<n;++i){
			scanf("%d %d %d",&c,&p,&time);
			itemArr[i].w=time;
			itemArr[i].v=c*p;
		}
		soln=getBinarySoln(itemArr,n,w);
		printf("%d\n",soln);
	}
	return 0;
}
