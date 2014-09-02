#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int debug=0;
long long int sum(long long int n){
	long long int count=0;
	if(debug)printf("sum(%lld)=",n);
	while(n){
		count+=n%10;
		n/=10;
	}
	if(debug)printf("%lld\n",count);
	return count;
}
long long int getCount(long long int n){
	if(debug)printf("\n\ngetCOunt called on %d\n",n);
	long long int lhs=n , rhs=0 , i , level=1;
	long long int count = 0 , sum;
	while(lhs){
		if(debug){
			printf("\nlhs=%lld , rhs=%lld , level=%lld\n",lhs,rhs,level);
		}
		sum = 45 * (lhs/10) * level;
		if(debug)printf("\t%lld\n",sum);
		
		for(i=1;i<lhs%10;++i){
			sum += i * level ;
			if(debug)printf("\t%lld\n",sum);
		}
		sum += (rhs+1) * (lhs%10);
		if(debug)printf("\t%lld\n",sum);
		
		count += sum;
		if(debug)printf("count=%lld\n\n",count);
		
		rhs += (lhs%10)*level;
		lhs/=10;
		level *= 10;
	}
	if(debug)printf("Returning %lld with %lld\n",n,count);
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	long long int a , b;
	long long int count;
	while(1){
		scanf("%lld %lld",&a,&b);
		if(a==-1) break;
		if(a<b){
			a=a^b;
			b=a^b;
			a=a^b;
		}
		count = getCount(a) - getCount(b) + sum(b);
		printf("%lld\n",count);
	}
	return 0;
}
