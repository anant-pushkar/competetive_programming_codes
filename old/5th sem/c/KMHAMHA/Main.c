#include<stdio.h>
#include<stdlib.h>
int t,num,*xArr,*yArr;
int getCount(){
	
}
int annotate(int * arr ,int size){
	int i=0,max=0;
	for(;i<size;++i){
		if(arr[i]>i){
			int j=i+1;
			for(;j<size;++j){
				if(arr[j]==arr[i])arr[j]=i;
			}
			arr[i]=i;
			if(max<i)max=i;
		}
	}
	return max;
}	
int main()
{
	int n;
	int x_max,y_max;
	scanf("%d",&t);
	while(t){
		scanf("%d",&n);num=n;
		xArr=(int*)calloc(n,sizeof(int));
		yArr=(int*)calloc(n,sizeof(int));
		while(n){
			scanf("%d %d",xArr[n-1],yArr[n-1]);
			--n;
		}
		x_max=annotate(xArr,num);y_max=annotate(yArr,num);
		int *sList=(int*)calloc(x_max+1,sizeof(int));
		int *tList=(int*)calloc(y_max+1,sizeof(int));
		int count=0;
		while(num){
			if(sList[xArr[num-1]]==0 && tList[yArr[num-1]]==0){
				++flow;
				sList[xArr[num-1]]=1;
				tList[yArr[num-1]]=1;
			}
			--num;
		}
		printf("%d\n",getcount());
		--t;
	}
	return 0;
}
