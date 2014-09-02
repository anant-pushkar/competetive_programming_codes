#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int debug=0 , arr1[10000] , arr2[10000] , n1 , n2;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int i;
	while(1){
		scanf("%d",&n1);if(n1==0)break;
		for(i=0;i<n1;++i)scanf("%d",&arr1[i]);
		scanf("%d",&n2);
		for(i=0;i<n2;++i)scanf("%d",&arr2[i]);
		
	}
	return 0;
}
