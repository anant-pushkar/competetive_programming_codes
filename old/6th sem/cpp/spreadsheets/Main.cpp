/*
Project name : spreadsheets
Created on : Sun Jan 12 21:15:00 2014
Author : Anant Pushkar
2010 Codeforces Beta Round #1 problem B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
bool debug=false;
char str[16];
const int alpha=1;
const int num  =2;
int checkType(){
    int state=0;
    for(int i=0;i<strlen(str);++i){
        if(isalpha(str[i])){
            if(state==1)return num;
        }else{
            if(state==0)++state;
        }
    }
    return alpha;
}
char* getAlpha(){
    int index;
    for(int i=0;i<strlen(str);++i)if(str[i]=='C'){
        index=i+1;
        break;
    }
    int c=atoi(str+index);
    str[index-1]='\0';
    int val[10];
    index=0;
    while(c>0){
        val[index++]=c%26!=0?c%26:26;
        c/=26;
    }
    int idx=0;
    char *s=(char*)calloc(16,sizeof(char));
    while(index>0){
        s[idx++]='A'+val[--index]-1;
    }
    strcat(s,str+1);
    return s;
}
char *getNum(){
    int index=0;
    int v=0;
    while(isalpha(str[index])){
        v=str[index++]-'A'+1+v*26;
    }
    char *s=(char*)calloc(16,sizeof(char));
    sprintf(s,"R%sC%d",str+index,v);
    return s;
}
int main(int argc , char **argv)
{
    if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
    int t;scanf("%d",&t);
    char*s;
    while(t--){
        scanf("%s",str);
        int type=checkType();
        switch(type){
            case num:
                s=getAlpha();
                printf("%s\n",s);
                free(s);
                break;
            case alpha:
                s=getNum();
                printf("%s\n",s);
                free(s);
                break;
        }
    }
    return 0;
}
