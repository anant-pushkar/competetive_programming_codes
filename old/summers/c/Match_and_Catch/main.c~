/*
Project name : Match_and_Catch
Created on : Sun May 11 14:58:23 2014
Author : Anant Pushkar
http://codeforces.com/contest/427/problem/D
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define SIZE 5001
#define LEN 26
typedef long long int lld;
typedef unsigned long long int llu;

struct _str_set_node{
	int val,count;
	struct _str_set_node **children;
};
typedef struct _str_set_node Node;

typedef struct{
	Node *head;
} Set;
int debug=0;
char s1[SIZE] , s2[SIZE];
Node *newNode(){
	Node *node = (Node*)malloc(sizeof(Node));
	node->val=INT_MAX;
	node->count=0;
	node->children= (Node**)calloc(LEN,sizeof(Node*));
	int i=0;
	for(i=0;i<LEN;++i)node->children[i]=NULL;
	return node;
}
Set *newSet(){
	Set * set = (Set*)malloc(sizeof(Set));
	set->head = newNode();
	return set;
}
void insert(Set *set , char* str , int n){
	int i;
	if(debug)printf("Inserting ");
	Node *node = set->head;
	int val;
	for(i=0;i<n;++i){
		if(debug)printf("%c",str[i]);
		if(node->children[str[i]-'a']==NULL){
			node->children[str[i]-'a'] = newNode();
		}
		node = node->children[str[i]-'a'];
	}
	node->val = n;
	++node->count;
	if(debug)printf(" : val=%d, count=%d\n",node->val,node->count);
}
int search(Set *set , char* str){
	int n = strlen(str) , i;
	Node *node = set->head;
	for(i=0;i<n;++i){
		if(node->children[str[i]-'a']==NULL){
			return 0;
		}
		node = node->children[str[i]-'a'];
	}
	return 1;
}
int getMin(Node *node){
	if(node==NULL){
		return INT_MAX;
	}
	if(debug)printf("val=%d,count=%d\n",node->val,node->count);
	int m = node->count==3 ? node->val : INT_MAX , i , l;
	for(i=0;i<LEN;++i){
		l = getMin(node->children[i]);
		m = m>l ? l : m;
	}
	return m;
}
char* append(char* str , char c){
	if(str==NULL){
		str = (char*)calloc(SIZE,sizeof(char));
	}
	int n = strlen(str);
	str[n] = c;
	return str;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=1;
	scanf("%s",s1);
	scanf("%s",s2);
	int l1=strlen(s1) , l2=strlen(s2) , i , j , k;
	char***lookup = (char***)calloc(l1+1,sizeof(char**));
	for(i=0;i<=l1;++i){
		lookup[i] = (char**)calloc(l2+1,sizeof(char*));
		for(j=0;j<=l2;++j)lookup[i][j]=NULL;
	}
	Set *set = newSet();
	
	if(debug)printf("s1 : \n");
	for(i=0;i<l1;++i){
		for(j=i;j<l1;++j)insert(set,s1+i,j-i+1);
	}
	if(debug)printf("s2 :\n");
	for(i=0;i<l2;++i){
		for(j=i;j<l2;++j)insert(set,s2+i,j-i+1);
	}
	
	if(debug)printf("s :\n");
	for(i=1;i<=l1;++i){
		for(j=1;j<=l2;++j){
			if(s1[i-1]==s2[j-1]){
				lookup[i][j] = append(lookup[i-1][j-1],s1[i-1]);
				insert(set,lookup[i][j],strlen(lookup[i][j]));
			}
		}
	}
	int m = getMin(set->head);
	printf("%d\n",m==INT_MAX ? -1 : m);
	return 0;
}
