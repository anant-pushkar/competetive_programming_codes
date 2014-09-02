/*
Project name : SCUBADIV
Created on : Mon Dec  9 02:15:52 IST 2013
http://www.spoj.com/problems/SCUBADIV/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
struct Cylinder{
	int t,a,w;
};
vector<Cylinder> list;
int c,t,a,n;
int solve(vector<vector<int> > &lookup,vector<vector<int> >&arr,int index){
	if(index==n){
		return lookup[t][a];
	}
	int val,x,y;
	for(int i=0;i<=t;++i){
		for(int j=0;j<=a;++j){
			if(i<=list[index].t && j<=list[index].a){
				arr[i][j]=lookup[i][j]<list[index].w?lookup[i][j]:list[index].w;
			}else{
				x=i-list[index].t>0?i-list[index].t:0;
				y=j-list[index].a>0?j-list[index].a:0;
				val=list[index].w+lookup[x][y];
				arr[i][j]=val<lookup[i][j]?val:lookup[i][j];
			}
		}
	}
	return solve(arr,lookup,index+1);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d",&c);
	vector<vector<int> >lookup,arr;
	while(c--){
		scanf("%d %d",&t,&a);
		scanf("%d",&n);
		list=vector<Cylinder>(n);
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&list[i].t,&list[i].a,&list[i].w);
		}
		lookup=vector<vector<int> >(t+1,vector<int>(a+1,1<<29));
		arr=vector<vector<int> >(t+1,vector<int>(a+1,0));
		int x=list[0].t<t?list[0].t:t;
		int y=list[0].a<a?list[0].a:a;
		for(int i=0;i<=x;++i){
			for(int j=0;j<=y;++j){
				lookup[i][j]=list[0].w;
			}
		}
		printf("%d\n",solve(lookup,arr,1));
	}
	return 0;
}

