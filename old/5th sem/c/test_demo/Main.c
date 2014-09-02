#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		printf("%d\n",n>0?(n+1):0); 
	}
	return 0;
}
