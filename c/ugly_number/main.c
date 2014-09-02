/*
Project name : ugly_number
Created on : Sun Jul 20 09:39:03 2014
Author : Anant Pushkar
Find nth ugly number using DP-bottom up approach
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
lld get_min(lld a ,lld b , lld c){
	lld n = a>b ? b : a;
	return n>c ? c : n;
}
void update(lld *ugly , int *i , lld *next , int *index , int val){
	if(ugly[(*i)-1] != (*next)){
		ugly[(*i)] = (*next);
	}else{
		--(*i);
	}
	++(*index);
	*next = ugly[*index]*val;
}
lld get_ugly(int n){
	lld *ugly = (lld*) calloc(n,sizeof(lld));
	ugly[0]=1;
	
	int i2=0 , i3=0 , i5=0 ;
	lld next_2=ugly[i2]*2 , next_3=ugly[i3]*3 , next_5=ugly[i5]*5 , next;
	for(int i=1;i<n;++i){
		next = get_min(next_2 , next_3 , next_5);
		if(next == next_2){
			update(ugly , &i , &next_2 , &i2 , 2);
		}else if(next == next_3){
			update(ugly , &i , &next_3 , &i3 , 3);
		}else if(next == next_5){
			update(ugly , &i , &next_5 , &i5 , 5);
		}
	}
	
	lld num = ugly[n-1];
	free(ugly);
	return num;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int t , n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",get_ugly(n));
	}
	return 0;
}
