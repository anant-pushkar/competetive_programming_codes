#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,i,j;lld m,sum,max=0;
	scanf("%d %lld",&n,&m);
	int *arr = (int*)calloc(n,sizeof(int));
	for(i=0;i<n;++i)scanf("%d",&arr[i]);
	i=0;j=1;sum=arr[0];
	while(i!=n && j!=n ){
		if(j<n && sum+arr[j] <= m ){
			sum += arr[j++];
		}else{
			sum -= arr[i++];
		}
		max = max < sum ? sum : max ;
	}
	printf("%lld\n",max);
	return 0;
}
