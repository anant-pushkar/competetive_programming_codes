#include<stdio.h>
#include<stdlib.h>
int main(int argc , char **argv)
{
	int i;
	for(i=0;i<argc;++i)printf("%s\n",argv[i]);
	scanf("%d",&i);
	printf("i=%d\n",i);
}