/*
Project name : Friends_of_Friends
Created on : Tue Jun  3 16:13:31 2014
Author : Anant Pushkar
http://www.spoj.com/problems/FACEFRND/
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef long long int lld;
typedef unsigned long long int llu;
int debug=0;
int *lookup;
int friendCount;
void addFriend(int id){
	if(lookup[id]==1)
		--friendCount;
	lookup[id] = -1;
	if(debug)printf("f : %d , friendCount%d\n",id , friendCount);
}
void addFriendOfFriend(int id){
	if(lookup[id]==-1)
		return;
	if(lookup[id]==0)
		++friendCount;
	lookup[id] = 1;
	if(debug)printf("fof : %d , friendCount : %d\n",id,friendCount);
}
void init(){
	friendCount = 0;
	lookup = (int*) calloc(10000 , sizeof(int));
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	int n , id , count;
	scanf("%d",&n);
	init();
	while(n--){
		scanf("%d",&id);
		addFriend(id);
		
		scanf("%d",&count);
		while(count--){
			scanf("%d",&id);
			addFriendOfFriend(id);
		}
	}
	
	printf("%d\n",friendCount);
	free(lookup);
	return 0;
}
