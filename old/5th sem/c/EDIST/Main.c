#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t,l1,l2,i,j;
	scanf("%d",&t);
	
	char str1[2001] , str2[2001];
	int **lookup;
	
	while(t--){
		scanf("%s",str1);
		scanf("%s",str2);
		
		l1 = strlen(str1);
		l2 = strlen(str2);
		
		lookup=(int**)calloc(l1+1,sizeof(int*));
		for(i=0;i<=l1;++i){
			lookup[i]=(int*)calloc(l2+1,sizeof(int));
		}
		
		for(i=0;i<=l1;++i)lookup[i][0]=i;
		for(i=0;i<=l2;++i)lookup[0][i]=i;
		
		int d1,d2,d3;
		for(i=1;i<=l1;++i){
			for(j=1;j<=l2;++j){
				//printf("%c,%c\n",str1[i-1],str2[j-1]);
				d1 = lookup[i-1][j-1] + (str1[i-1]==str2[j-1] ? 0 : 1);
				d2 = lookup[i][j-1]+1;
				d3 = lookup[i-1][j]+1;
				if(d1<d2){
					if(d1<d3){
						lookup[i][j]=d1;
					}else{
						lookup[i][j]=d3;
					}
				}else{
					if(d2<d3){
						lookup[i][j]=d2;
					}else{
						lookup[i][j]=d3;
					}
				}
			}
		}
		/*printf("%d,%d\n",l1,l2);
		for(i=0;i<=l1;++i){
			for(j=0;j<=l2;++j){
				printf("\t%d",lookup[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n",lookup[l1][l2]);
		
		free(lookup);
	}
	return 0;
}
