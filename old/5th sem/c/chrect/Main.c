#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int T,t,n,m,k;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		scanf("%d %d %d",&n,&m,&k);
		printf("%d\n",(n+m>3 ? (int)ceil((float)(k)/((n>1 && m>1) ? 2 : 1)) : 0 ));
	}
	return 0;
}