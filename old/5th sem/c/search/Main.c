#include<stdio.h>
#include"search.h"
int main()
{
	int opt=-1,i,k;
	long int n=0;
	Array arr;
	scanf("%d",&opt);
	do{
		switch(opt){
		case 1:
			scanf("%ld",&n);
			arr.count=n;arr.head=(int*)calloc(n,sizeof(int));
			for(i=0;i<n;i++) scanf("%d",&arr.head[i]);
			printf("Array object successfully created.\n");
			break;
		case 2:
			scanf("%d",&k);
			n=Search(arr,k);
			if(n==-1) printf("Key not found.\n");
			else printf("Key successfully found at %ld\n",n);
			break;
		case 3:
			free(arr.head);arr.count=0;
			printf("Array object freed successfully.\n");
			break;
		default:
			printf("Exiting programme.\n");
			break;
		}
		if(opt<0 || opt>4) break;
		scanf("%d",&opt);
	}while(1);
	return 0;
}
