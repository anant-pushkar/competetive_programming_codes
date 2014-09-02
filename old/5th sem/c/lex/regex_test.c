#include "regex.h"
int main(){
	printf("Enter number of test cases:");
	int T,t=0;scanf("%d",&T);
	char regex[200],str[200];
	for(t=0;t<T;t++){
		printf("Enter regex : ");
		scanf("%s",regex);
		printf("Regex scanned : %s\n",regex);
		scanf("%s",str);
		if(matchRegex(regex,str)) printf("\n\tMatched");
		else printf("\n\tNot Matched");
		printf("\n");
	}
	return 0;
}