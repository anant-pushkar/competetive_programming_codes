/*
Project name : ScoringSystems
Created on : Sat Dec  7 22:34:47 IST 2013
Input format : 
t{number of tets cases}
n{number of questions} 
<c[i]> 
<s[i]> 
eg : 
1
3 
250 500 1000 
300 600 900

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<float.h>
int debug=0;
int t,n,i,*s,*c,check;
int testEquivalence(int s1,int s2,int c1,int c2){
	if(s1>s2 && c1>c2)return 1;
	if(s1<s2 && c1<c2)return 1;
	if(s1==s2 && c1==c2)return 1;
	return 0;
}
int incrementalCheck(int index){
	int s_sum1=0,s_sum2=s[0],c_sum1=0,c_sum2=c[0];
	int i1=index,i2=1;
	while(i1>0){
		s_sum1+=s[i1];
		s_sum2+=s[i2];
		c_sum1+=c[i1];
		c_sum2+=c[i2];
		if(!testEquivalence(s_sum1,s_sum2,c_sum1,c_sum2))return 0;
		--i1;++i2;
	}
	return 1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		s=(int*)calloc(n,sizeof(int)); 
		c=(int*)calloc(n,sizeof(int));
		for(i=0;i<n;++i)scanf("%d",&c[i]);
		for(i=0;i<n;++i)scanf("%d",&s[i]);
		
		if(!testEquivalence(s[0],s[1],c[0],c[1])){
			printf("Not Equivalent\n");
			continue;
		}
		check=1;
		for(i=2;i<n;++i){
			if(!incrementalCheck(i)){
				printf("Not Equivalent\n");
				check=0;
				break;
			}
		}
		if(check)printf("Equivalent\n");
		free(s);free(c);
	}
	return 0;
}
