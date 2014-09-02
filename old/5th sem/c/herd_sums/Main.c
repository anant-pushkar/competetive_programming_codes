#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int debug=0;
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n,i,m,count=1;scanf("%d",&n);n=n*2;
	float limit=sqrt(n);
	for(i=2;i<limit;++i)if(n%i==0){
		m=n/i-i;
		if(m%2==1)count++;
	}
	printf("%d\n",count);
	return 0;
}
