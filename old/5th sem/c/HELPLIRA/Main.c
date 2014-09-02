#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;scanf("%d",&n);
	int x1,x2,x3,y1,y2,y3,max=0,min=10000000,a,i=1,max_index=1,min_index=1;
	while(n){
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
		a=x1*y2-y1*x2+x2*y3-y2*x3+x3*y1-x1*y3;a=a>0?a:-a;
		if(max<=a){
			max=a;
			max_index=i;
		}
		if(min>=a){
			min=a;
			min_index=i;
		}
		--n;++i;
	}
	printf("%d %d\n",min_index,max_index);
	return 0;
}
