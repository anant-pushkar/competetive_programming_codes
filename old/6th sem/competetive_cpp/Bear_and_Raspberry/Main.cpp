/*
Project name : Bear_and_Raspberry
Created on : Fri Jan 24 21:09:58 2014
Author : Anant Pushkar
codefirces 385 : A
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,c;
	cin>>n>>c;
	int max=-(1<<29);
	vector<int> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];
	for(int i=0;i<n-1;++i){
		max=max>(arr[i]-arr[i+1]-c)?max:(arr[i]-arr[i+1]-c);
	}
	cout<<(max>0?max:0)<<endl;
	return 0;
}

