/*
Project name : NICEDAY
Created on : Mon Dec 16 20:01:37 IST 2013
http://www.spoj.com/problems/NICEDAY/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long int lld;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,temp;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<vector<int> > list(3,vector<int>(n+1)),rank(3,vector<int>(n+1));
		vector<bool> lookup(n+1,true);
		for(int i=0;i<3;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&list[i][j]);
				rank[i][list[i][j]]=j;
			}
		}
		int count=0,stream;
		for(int i=1;i<=n;++i)if(lookup[i]){
			stream=rank[0][i]>rank[1][i]?0:1;
			stream=rank[stream][i]>rank[2][i]?stream:2;
			if(debug)cout<<"player : "<<i<<" stream:"<<stream<<" #"<<rank[stream][i]<<endl;
			for(int j=rank[stream][i]+1;j<=n;++j)if(lookup[list[stream][j]]){
				if(rank[0][list[stream][j]]>rank[0][i] && rank[1][list[stream][j]]>rank[1][i] && rank[2][list[stream][j]]>rank[2][i]){
					++count;
					if(debug)cout<<"blacklisting "<<list[stream][j]<<endl;
					lookup[list[stream][j]]=false;
				}else{
					if(debug)cout<<"sparing "<<list[stream][j]<<"("<<rank[0][list[stream][j]]<<","<<rank[1][list[stream][j]]<<","<<rank[2][list[stream][j]]<<")"<<endl;
				}
			}
			if(debug)cout<<endl;
		}
		printf("%d\n",n-count);
	}
	return 0;
}

