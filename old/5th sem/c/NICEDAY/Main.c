/*
Project name : NICEDAY
Created on : Mon Dec 16 21:46:05 IST 2013
http://www.spoj.com/problems/NICEDAY/

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,n,temp,i,j,**rank,**list,count,stream,*lookup;
	//scanf("%d",&t);
	//while(t--){
		scanf("%d",&n);
		rank=(int**)calloc(3,sizeof(int*));
		list=(int**)calloc(3,sizeof(int*));
		lookup=(int*)calloc(n+1,sizeof(int));
		for(i=0;i<3;++i){
			rank[i]=(int*)calloc(n+1,sizeof(int));
			list[i]=(int*)calloc(n+1,sizeof(int));
		}
		for(i=0;i<3;++i){
			for(j=1;j<=n;++j){
				scanf("%d",&list[i][j]);
				rank[i][list[i][j]]=j;
			}
		}
		count=0;
		for(i=1;i<=n;++i)if(!lookup[i]){
			stream=rank[0][i]>rank[1][i]?0:1;
			stream=rank[stream][i]>rank[2][i]?stream:2;
			if(debug)printf("player : %d stream:%d #%d\n",i,stream,rank[stream][i]);
			for(j=rank[stream][i]+1;j<=n;++j)if(!lookup[list[stream][j]]){
				if(rank[0][list[stream][j]]>rank[0][i] && rank[1][list[stream][j]]>rank[1][i] && rank[2][list[stream][j]]>rank[2][i]){
					++count;
					if(debug)printf("blacklisting %d\n",list[stream][j]);
					lookup[list[stream][j]]=1;
				}else{
					if(debug)printf("sparing %d(%d,%d,%d)",list[stream][j],rank[0][list[stream][j]],rank[1][list[stream][j]],rank[2][list[stream][j]]);
				}
			}
			if(debug)printf("\n");
		}
		printf("%d\n",n-count);
	//}
	return 0;
}
