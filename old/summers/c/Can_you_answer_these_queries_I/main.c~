/*
Project name : Can_you_answer_these_queries_I
Created on : Fri May 30 14:06:50 2014
Author : Anant Pushkar
http://www.spoj.com/problems/GSS1/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define LEFT  1
#define RIGHT 2
#define MIN  -2000000000
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int n;
lld ** lookup;
int *arr;
lld getVal(int a , int b){
	if(a<0 || a>n-1 || b<0 || b>n-1)
		return MIN;
	return lookup[a][b];
}
int getFlag(int** flag , int a , int b){
	if(a<0 || a>n-1 || b<0 || b>n-1)
		return 0;
	return flag[a][b];
}
void init(){
	int **flag = (int**) calloc(n,sizeof(int));
	lookup = (lld**) calloc(n,sizeof(lld*));
	int i , j;
	for(i=0;i<n;++i){
		lookup[i] = (lld*) calloc(n,sizeof(lld));
		flag[i]   = (int*) calloc(n,sizeof(int));
	}
	for(i=0;i<n;++i){
		lookup[i][i] = arr[i];
		flag[i][i]   = LEFT & RIGHT;
	}
	lld v1 , v2 ;
	int f1 , f2 ;
	for(i=0;i<n;++i){
		for(j=i+1;j<n;++j){
			v1 = getVal(i+1,j);
			f1 = getFlag(flag,i+1,j);
			
			v2 = getVal(i,j-1);
			f2 = getFlag(flag,i,j-1);
			
			if(f1&LEFT)
				v1 += arr[i];
			if(f2&RIGHT)
				v2 += arr[j];
			
			if(v1>v2){
				flag[i][j] = f1&LEFT;
				lookup[i][j] = v1;
			}else if(v1<v2){
				flag[i][j] = f2&RIGHT;
				lookup[i][j] = v2;
			}else{
				flag[i][j] = f1&LEFT & f2&RIGHT;
				lookup[i][j] = v1;
			}
		}
	}
	/*
	for(i=n-1;i>-1;--i)
		free(flag[i]);
	free(flag);
	free(arr);
	*/
}
void clean(){
	int i;
	for(i=n-1;i>-1;--i)
		free(lookup[i]);
	free(lookup);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	scanf("%d",&n);
	arr = (int*) calloc(n,sizeof(int));
	
	int i;
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	init();
	
	int m , a , b ;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&a,&b);
		printf("%lld\n",lookup[a-1][b-1]);
	}
	
	//clean();
	return 0;
}
