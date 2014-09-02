#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int N,n,Q,q,L,R,K,count,i,p,temp;
	scanf("%d %d",&N,&Q);
	
	int *arr=(int*)calloc(N,sizeof(int)),*ptr=arr;
	for(n=0;n<N;n++){
		scanf("%d",ptr);
		ptr++;
	}
	
	for(q=0;q<Q;q++){
		scanf("%d %d %d",&L,&R,&K);
		count=0;
		for(i=L-1;i<=R-1;i++){
			temp=arr[i];
			p = K;
			if(temp<p){
				printf("1#p=%d\n",p);
				continue;
			}
			if(temp&1!=p&1){
				printf("1#p=%d\n",p);
				continue;
			}
			if(p&1==0)printf("--%d,%d--",p&1,temp&1);
			while(p&1==0 && temp&1==0){
				printf("--Shifting--");
				p=p>>1;
				temp=temp>>1;
			}
			if(p==1){
				count++;
			}
			else if(p&1==1){
				if(temp%p==0)count++;
			}
			printf("3#p=%d temp=%d\n",p,temp);
		}
		printf("%d\n",count);
	}
	
	return 0;
}
