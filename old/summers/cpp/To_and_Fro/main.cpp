/*
Project name : To_and_Fro
Created on : Thu May 15 09:44:08 2014
Author : Anant Pushkar
http://www.spoj.com/problems/TOANDFRO/
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
	int c,r,index;
	char str[200];
	while(true){
		scanf("%d",&c);
		if(c==0)break;
		scanf("%s",str);
		r =strlen(str)/c;
		if(debug)cout<<str<<"len:"<<strlen(str)<<" c:"<<c<<" r:"<<r<<endl;
		for(int j=0;j<c;++j){
			for(int i=0;i<r;++i){
				index=i*c + (i%2==0 ? j : c-1-j);
				printf("%c",str[index]);
				//cout<<index<<" ";
			}
		}
		printf("\n");
	}
	return 0;
}

