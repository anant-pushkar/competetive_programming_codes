#include<stdio.h>
#include<stdlib.h>
int check=1;
int main()
{
	check++;
	printf("%d\n",check);
	if(check<4)main();
	return 0;
}
