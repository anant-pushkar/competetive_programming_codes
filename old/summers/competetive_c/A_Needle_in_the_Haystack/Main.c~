/*
Project name : A_Needle_in_the_Haystack
Created on : Thu May 29 13:32:23 2014
Author : Anant Pushkar
http://www.spoj.com/problems/NHAY/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int debug=0;
typedef long long int lld;
int n;
char *needle , hChar;
int ** compile(char *pat){
	int l = strlen(pat) , i , j , k , index;
	int ** automata = (int**) calloc(l+1,sizeof(int*));
	for(i=0;i<=l;++i)
		automata[i] = (int*) calloc(26,sizeof(int));
	automata[0][ pat[0]-'a' ] = 1;
	i=0; j=1;
	while(j<=l){
		for(k=0;k<26;++k)
			automata[j][k] = automata[i][k];
		if(j!=l){
			index = pat[j]-'a';
			automata[j][index] = j+1 ;
			i = automata[i][index];
		}
		++j;
	}
	
	return automata;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int ** automata , state , index , found;
	while( scanf("%d",&n)!=EOF ){
		needle = (char*) calloc(n+1,sizeof(int));
		scanf("%s",needle);
		automata = compile(needle);
		
		state = 0;
		index = 0;
		found = 0; 
		scanf("%c",&hChar);
		while(1){
			scanf("%c",&hChar);
			if(debug)printf("read : |%c| ",hChar);
			if(hChar<'a' || hChar>'z')
				break;
			state = automata[state][hChar-'a'];
			if(debug)printf("state : %d",state);
			if(state == n){
				printf("%d\n",index-n+1);
				found = 1;
			}
			if(debug)printf("\n");
			++index;
		}
		if(!found)
			printf("\n");
		
		free(automata);
		free(needle);
	}
	return 0;
}
