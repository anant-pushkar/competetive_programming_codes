#include<stdio.h>
#include<stdlib.h>
unsigned long long int getGCD(unsigned long long int a , unsigned long long int b){
	if(a%b==0) return b;
	else return getGCD(b,a%b);
}	
/*unsigned long long int sumOfDivisors(unsigned long long int  n){
    unsigned long long int  prod=1,k=2;
    for(;k*k<=n;k++){
        unsigned long long int p=1;
        while(n%k==0){
            p=p*k+1;
            n/=k;
        }
        prod*=p;
    }
    if(n>1)
        prod*=1+n;
    return prod;
}*/
int main()
{
	int T,t=0;scanf("%d",&T);
	unsigned long long int n,count,s,gcd,i;
	for(;t<T;t++){
		scanf("%lld",&n);
		if(n==1){
			printf("1/1\n");
			continue;
		}
		if(n==2){
			printf("3/4\n");
			continue;
		}
		if(n==3){
			printf("5/9\n");
			continue;
		}
		if(n==4){
			printf("1/2\n");
			continue;
		}
		if(n==5){
			printf("2/5\n");
			continue;
		}
		count=0;i=1;
		unsigned long long int temp=n;
		while(temp>0){
			temp=n/i - n/(i+1);
			//printf("i=%lld temp=%lld \n",i,temp);
			count+=temp*i;
			i++;
		}
		i=n/i;
		while(i>0){
			count+=n/i;
			i--;
		}
		s=n*n;
		//printf("s=%lld , count=%lld ",s,count);
		gcd=getGCD(s,count);
		//printf("gcd=%lld | ",gcd);
		s/=gcd;count/=gcd;
		printf("%lld/%lld\n",count,s);
	}
	return 0;
}
