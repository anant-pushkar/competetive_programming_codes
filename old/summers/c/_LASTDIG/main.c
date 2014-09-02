#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int t,a,b,arr[10][4];
	for(a=0;a<10;++a)for(b=1;b<=4;++b)arr[a][b%4]=((int)pow(a,b))%10;
	arr[0][0]=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%d\n",a==0 ? 0 : b==0 ? 1 : arr[a%10][b%4]);
	}
	return 0;
}
