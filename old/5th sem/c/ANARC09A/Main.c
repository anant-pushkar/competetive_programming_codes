#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[2001];
	int level=0 , count=0 , i , t=1;
	while(1){
		scanf("%s",str);
		if(str[0]=='-') break;
		level=0; 
		count=0;
		for(i=0;i<strlen(str);++i){
			if(str[i]=='}'){
				if(level==0){
					++count;
					++level;
				}else{
					--level;
				}
			}
			if(str[i]=='{') ++level;
		}
		level=level>0 ? level : -level;
		count+=level/2;
		printf("%d. %d\n",t++,count);
	}
	return 0;
}
