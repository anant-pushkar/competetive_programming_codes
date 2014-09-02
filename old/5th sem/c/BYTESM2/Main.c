#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t,m,n,i,j,**floor,val;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&m,&n);
		floor=(int**)calloc(m,sizeof(int*));
		for(i=0;i<m;++i){
			floor[i]=(int*)calloc(n,sizeof(int));
			for(j=0;j<n;++j){
				scanf("%d",&floor[i][j]);
			}
		}
		for(i=1;i<m;++i){
			for(j=0;j<n;++j){
				val = floor[i-1][j];
				if(j>0)val = val>floor[i-1][j-1] ? val : floor[i-1][j-1] ;
				if(j<n-1)val = val>floor[i-1][j+1] ? val : floor[i-1][j+1];
				
				floor[i][j]+=val;
			}
		}
		if(debug){
			printf("\n\n");
			for(i=0;i<m;++i){
				for(j=0;j<n;++j)printf("%d ",floor[i][j]);
				printf("\n");
			}
		}
		for(i=0;i<n;++i)val=val>floor[m-1][i]?val:floor[m-1][i];
		printf("%d\n",val);
	}
	return 0;
}
