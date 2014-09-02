#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int t;scanf("%d",&t);
	char str[100000];
	while(t){
		scanf("%s",str);
		int count=strlen(str),size=strlen(str);
		int i=1,index;
		for(;i<size;++i){
			int j=0,index=i;
			while(index<size){
				if(str[index++]==str[j++])++count;
				else break;
			}
		}
		printf("%d\n",count);
		--t;
	}
	return 0;
}
