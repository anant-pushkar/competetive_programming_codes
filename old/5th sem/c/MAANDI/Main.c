#include<stdio.h>
#include<stdlib.h>
int checkOverLucky(int n){
	while(n){
		if(n%10==4 || n%10==7)return 1;
		n/=10;
	}
	return 0;
}
int countOverLucky(int n){
	int i=1,count=0;
	for(;i*i<n;++i){
		if(n%i==0){
			if(checkOverLucky(i))++count;
			if(checkOverLucky(n/i))++count;
		}
	}
	if(i*i==n && checkOverLucky(i))count+=2;
	return count;
}
int main()
{
	int t,n;scanf("%d",&t);
	while(t){
		scanf("%d",&n);
		printf("%d\n",countOverLucky(n));
		--t;
	}
	return 0;
}
