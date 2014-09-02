/*
Project name : valera_and_plates
Created on : Fri Dec 13 14:22:59 IST 2013
http://codeforces.com/contest/369/problem/A

*/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,m,k,count=0,type_count[2];cin>>n>>m>>k;
	type_count[0]=0;type_count[1]=0;
	int type[n];
	for(int i=0;i<n;++i){
		cin>>type[i];
		++type_count[type[i]-1];
	}
	for(int i=0;i<n;++i){
		switch(type[i]){
		case 1:
			if(m>0)--m;
			else ++count;
			--type_count[0];
			break;
		case 2:
			if(k>0)--k;
			else if(type_count[0]<m && m>0)--m;
			else ++count;
			--type_count[1];
			break;
		}
	}
	cout<<count<<endl;
	return 0;
}

