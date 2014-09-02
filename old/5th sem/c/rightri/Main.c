#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,n,x1,x2,x3,y1,y2,y3,count=0;;
	scanf("%d",&N);
	for(n=0;n<N;n++){
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		if( (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1)==0 ){
			count++;
		}
		else if( (x1-x2)*(x3-x2)+(y1-y2)*(y3-y2)==0 ){
			count++;
		}
		else if( (x1-x3)*(x2-x3)+(y1-y3)*(y2-y3)==0 ){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
