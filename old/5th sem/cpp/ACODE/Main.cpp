/*
Project name : ACODE
Created on : Fri Dec  6 22:13:35 IST 2013
http://www.spoj.com/problems/ACODE/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
char str[5000];
inline int decode1(int index){
	if(str[index]-'0'>0 && str[index]-'0'<10)return 1;
	return 0;
}
inline int decode2(int index){
	int a=str[index-1]-'0' , b=str[index]-'0';
	if(10*a+b<27 && 10*a+b>9) return 1;
	return 0;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	vector<int>lookup;
	int l;
	while(1){
		scanf("%s",str);if(str[0]=='0')break;
		l=strlen(str);
		if(l==1){
			printf("%d\n",decode1(0));
			continue;
		}
		if(l==2){
			printf("%d\n",(decode2(1)+(decode1(0)&decode1(1))));
			continue;
		}
		lookup=vector<int>(l,0);
		lookup[0]=decode1(0);
		lookup[1]=decode2(1)+(decode1(0)&decode1(1));
		for(int i=2;i<l;++i){
			lookup[i]= decode1(i)*lookup[i-1]+decode2(i)*lookup[i-2] ;
		}
		if(debug){
			for(int i=0;i<l;++i)cout<<lookup[i]<<" ";
			cout<<endl;
		}
		printf("%d\n",lookup[l-1]);
	}
	return 0;
}

