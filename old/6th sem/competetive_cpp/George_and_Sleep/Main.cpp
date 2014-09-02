/*
Project name : George_and_Sleep
Created on : Thu Feb  6 14:12:10 2014
Author : Anant Pushkar
codeforces 387 A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
inline int read(){
	char h1,h2,c,m1,m2;
	scanf("%c%c%c%c%c",&h1,&h2,&c,&m1,&m2);
	int t = m2-'0'+10*(m1-'0') + 60*(h2-'0'+10*(h1-'0'));
	if(debug)cout<<"returning : "<<t<<endl;
	scanf("%c",&c);
	return t;
}
inline char *getTime(int t){
	if(debug)cout<<"converting : "<<t<<endl;
	char* str=new char[7];
	sprintf(str,"%.2d:%.2d",(t/60),(t%60));
	return str;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t1=read() , t2=read();
	int t=t1-t2;
	t=t<0?t+24*60:t;
	printf("%s\n",getTime(t));
	return 0;
}

