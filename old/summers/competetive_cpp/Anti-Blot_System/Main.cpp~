/*
Project name : Anti-Blot_System
Created on : Thu May 22 11:26:16 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ABSYS/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	string a,b,c;
	char op,eq;
	int t;scanf("%d",&t);
	int x,y,z;
	while(t--){
		cin>>a>>op>>b>>eq>>c;
		if(a.find("machula") != string::npos) x= -1;
		else x = atoi(a.c_str());
		if(b.find("machula") != string::npos) y= -1;
		else y = atoi(b.c_str());
		if(c.find("machula") != string::npos) z= -1;
		else z = atoi(c.c_str());
		if(x==-1)x=z-y;
		if(y==-1)y=z-x;
		if(z==-1)z=x+y;
		printf("%d + %d = %d\n",x,y,z);
	}
	return 0;
}

