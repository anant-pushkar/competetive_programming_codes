#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int debug=0;
typedef long long int lld;
const lld MOD = 1000000007;
lld lookup[]={45 , 9810 , 1483650 , 197982000 , 749774832 , 997279217 , 966074507 , 362800007};
int nDigits(int  n){
	int count=0;
	while(n){
		++count;
		n/=10;
	}
	return count;
}
lld powten(int n){
	lld p=1,i;
	for(i=0;i<n;++i)p*=10;
	return p;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,d1,d2,d;scanf("%d",&t);
	lld l,r,sum,num;
	while(t--){
		scanf("%lld %lld",&l,&r);
		d1=nDigits(l);
		d2=nDigits(r);
		if(d1==d2){
			sum=((l+r)%MOD)*((r-l+1)%MOD)*d1/2;
			sum=sum%MOD;
		}else{
			num=powten(d1);
			d=d1+1;
			sum=((num+l-1)%MOD)*((num-l)%MOD)*d1/2;
			sum=sum%MOD;if(debug)printf("%lld\n",sum);
			while(d!=d2){
				sum+=lookup[(d++) - 1];
				sum=sum%MOD;if(debug)printf("%lld\n",sum);
				num*=10;
			}
			sum+=((num+r)%MOD)*((r-num+1)%MOD)*d2/2;
			sum=sum%MOD;if(debug)printf("%lld\n",sum);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
