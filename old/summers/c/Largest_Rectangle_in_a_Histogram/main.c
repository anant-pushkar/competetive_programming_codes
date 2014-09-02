/*
Project name : Largest_Rectangle_in_a_Histogram
Created on : Thu Jun 12 16:08:25 2014
Author : Anant Pushkar
http://www.spoj.com/problems/HISTOGRA/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , h[10000] , i ;
	lld maxArea , maxH , globalMax , area;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<n;++i){
			scanf("%d",&h[i]);
		}
		globalMax = h[0];
		maxArea   = h[0];
		maxH      = h[0];
		for(i=1;i<n;++i){
			area = (maxH>h[i] ? h[i] : maxH)*(maxArea/maxH+1);
			if(maxArea<area){
				maxArea = area;
				maxH    = maxH>h[i] ? h[i] : maxH;
				globalMax = globalMax<maxArea ? maxArea : globalMax;
			}else{
				maxArea = h[i];
				maxH    = h[i];
			}
			if(debug)printf("At %d , globalMax:%lld maxArea:%lld maxH:%lld\n",h[i],globalMax,maxArea,maxH);
		}
		printf("%lld\n",globalMax);
	}
	return 0;
}
