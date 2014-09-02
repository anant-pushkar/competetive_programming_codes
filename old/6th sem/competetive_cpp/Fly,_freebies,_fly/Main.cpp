/*
Project name : Fly,_freebies,_fly
Created on : Fri Jan 17 20:34:20 2014
Author : Anant Pushkar
codeforces testing round problem B
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	vector<int> t(n+1,-2000);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	
	int T;
	scanf("%d",&T);
	
	sort(t.begin(),t.end());
	
	int j=0,max=0;
	for(int i=1;i<n+1;++i){
		while(t[j]<t[i]-T)++j;
		max=max>i-j+1?max:i-j+1;
		if(debug)cout<<i<<","<<j<<endl;
	}
	if(debug)cout<<endl;
	printf("%d\n",max);
	return 0;
}

