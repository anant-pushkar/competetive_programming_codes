#include<stdio.h>
#include<stdlib.h>
int solve(int,int,int);
int kVal[100001];
int val[100001];
void init();
int main()
{
	int T,t,a,b,k;
	scanf("%d",&T);
	for(t=0;t<T;t++){
		scanf("%d %d %d",&a,&b,&k);
		printf("%d\n",solve(a,b,k));
	}
	return 0;
}
int solve(int a,int b,int k)
{
	int i,count=0;
	init(a,b+1);
	for(i=a;i<=b;i++){
		if(kVal[i]==k || (k==1 && kVal[i]==-1)){
			count++;
			//printf("%d\n",i);
		}
	}
	return count;
}
void init(int a , int b)
{
	int i,j;
	for(i=a;i<b;i++){
		kVal[i]=0;
		val[i]=i;
	}
	/*for(i=a;i<=b;i++)
		printf("%d  ",kVal[i]);
	printf("\n");
	for(i=a;i<=b;i++)
		printf("%d ",val[i]);
	printf("\n");*/
	for(i=2;i<b;i++){
		//for(i=a;i<=b;i++)
			//printf("%d ",kVal[i]);
		//printf("\n");
		if(kVal[i]==0 || kVal[i]==-1){
			kVal[i]=-1;
			for(j=a>i+1?a:i+1;j<b;j++){
				if(val[j]%i==0 && kVal[j]<5){
					while(val[j]%i==0)
						val[j]=val[j]/i;
					kVal[j]++;
				}
			}
		}
	}
	//for(i=a;i<=b;i++)
		//printf("%d ",val[i]);
	//printf("\n");
}