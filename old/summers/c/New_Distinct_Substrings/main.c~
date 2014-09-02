/*
Project name : New_Distinct_Substrings
Created on : Mon Jun 16 20:02:05 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SUBST1/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
char str[50001];
char ** sArr;
int l;
int cstring_cmp(const void *a, const void *b) { 
	const char **ia = (const char **)a;
	const char **ib = (const char **)b;
	return strcmp(*ia, *ib);
} 
lld getLcpLen(char* s1 , char* s2){
	int l=strlen(s1)<strlen(s2) ? strlen(s1) : strlen(s2);
	lld i=0;
	while(i<l && s1[i]==s2[i]) 
		++i;
	return i;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , i ;
	lld count;
	scanf("%d",&t);
	while(t--){
		scanf("%s",str);
		l = strlen(str);
		sArr = (char**) calloc(l,sizeof(char*));
		for(i=0;i<l;++i)
			sArr[i] = str+i;
		qsort(sArr , l , sizeof(char*) , cstring_cmp);
		
		if(debug)for(i=0;i<l;++i)printf("%s\n",sArr[i]);
		
		count=strlen(sArr[0]);
		for(i=1;i<l;++i)
			count += strlen(sArr[i]) - getLcpLen(sArr[i-1] , sArr[i]);
		printf("%lld\n",count);
		
		free(sArr);
	}
	return 0;
}
 