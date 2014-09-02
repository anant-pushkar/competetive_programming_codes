/*
Project name : PIE
Created on : Tue May  6 15:59:55 2014
Author : Anant Pushkar
Binary search on function
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define SIZE 10001
int debug=0;
typedef long long int lld;
int n,f,r[SIZE],max;
int func(double r2){
	int count=0 , i;
	double lo;
	for(i=0;i<n;++i)if(r[i]*r[i] >= r2){
		lo = r[i]*r[i];
		do{
			++count;
			lo -= r2;
		}while(lo > r2 && count<f);
		if(count>=f){
			if(debug)printf("\treturning true on %f\n",r2);
			return 1;
		}
	}
	if(debug)printf("\treturning %d on %f\n",count>=f,r2);
	return count>=f;
}
double search(){
	double s=0 , e = max*max+1;
	while(e-s>0.00001){
		if(debug)printf("%f %f\n",e,s);
		if(func((e+s)/2)==1)s=(e+s)/2;
		else e=(e+s)/2;
	}
	return s;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,i;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&f);
		++f;
		max = INT_MIN;
		for(i=0;i<n;++i){
			scanf("%d",&r[i]);
			max = max<r[i] ? r[i] : max ;
		}
		printf("%0.4f\n",M_PI*search());
	}
	return 0;
}
