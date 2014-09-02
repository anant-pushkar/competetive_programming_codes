#include<stdio.h>
#include<stdlib.h>
int main()
{
	double val,*lookup=(double*)calloc(277,sizeof(double));
	int n,i,hi,lo,mid;	
	lookup[0]=0;
	for(i=1;i<277;++i)lookup[i]=lookup[i-1]+1/(double)(i+1);
	while(1){
		scanf("%lf",&val);if(val==0.00)break;
		hi=1;
		while(hi<277 && lookup[hi]<val)hi=hi*2;
		if(lookup[hi]==val){
			printf("%d\n",hi);
			continue;
		}
		if(hi>=277)hi=276;
		lo=hi/2;
		mid=(hi+lo)/2;
		while((lookup[mid]-val)*(lookup[mid-1]-val)>0 && hi-lo>1){
			if(lookup[mid]>val)hi=mid;
			else lo=mid;
			mid=(hi+lo)/2;
		}
		if(lookup[mid-1]==val)printf("%d card(s)\n",(mid-1));
		else if(lookup[mid]>=val)printf("%d card(s)\n",mid);
		else printf("%d card(s)\n",hi);
	}
	return 0;
}
