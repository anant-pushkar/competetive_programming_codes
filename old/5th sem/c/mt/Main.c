#include<stdio.h>
#include<stdlib.h>
int main()
{
	unsigned int t=-1;
	printf("%d\n",t);
	printf("%u\n",t);
	long long int s=1;
	s=s<<33;
	s=s-1;
	printf("\n%d\n",s);
	printf("%lld\n",s);
	return 0;
}
