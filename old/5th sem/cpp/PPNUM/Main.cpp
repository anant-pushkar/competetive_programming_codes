#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
const lld MOD = 1000000007;
lld lookup[]={45 , 9810 , 1483650 , 14848650 , 849864902 , 998639612 , 985460507};
inline int nDigits(int  n){
	int count=0;
	while(n){
		++count;
		n/=10;
	}
	return count;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,d1,d2,d;scanf("%d",&t);
	lld l,r,sum,num;
	while(t--){
		scanf("%lld %lld",&l,&r);
		d1=nDigits(l);
		d2=nDigits(r);
		if(d1==d2){
			sum=(l+r)*(r-l+1)*d1/2;
		}else{
			num=pow(10,d1);
			d=d1+1;
			sum=((num+l-1)%MOD)*((num-l)%MOD)*d1/2;
			if(debug)cout<<sum<<endl;
			sum=sum%MOD;
			while(d!=d2){
				sum+=lookup[d++ - 1];
				sum=sum%MOD;
				if(debug)cout<<sum<<endl;
				num*=10;
			}
			if(d1-d2>1)num=num*10;
			sum+=((num+r)%MOD)*((r-num+1)%MOD)*d2/2;
			sum=sum%MOD;
			if(debug)cout<<sum<<endl;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

