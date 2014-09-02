/*
Project name : SERVICE
Created on : Thu Jan  9 11:25:34 2014
Author : Anant Pushkar
http://www.spoj.com/problems/SERVICE/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef long long int lld;
bool debug=false;
int l,n,cost[201][201],query[1001];
inline void set(lld**v , int a , int b , lld val){
	if(a<b){
		a=a^b;
		b=a^b;
		a=a^b;
	}
	if(v[a][b]==-1 || v[a][b]>val)v[a][b]=val;
}
lld getDist(int index , lld**lookup , lld**arr ){
	if(debug){
		printf("Index : %d\n",index);
		for(int i=0;i<l;++i){
			for(int j=0;j<l;++j){
				printf("%lld\t",lookup[i][j]);
			}
			printf("\n");
		}
		printf("\n");printf("\n");
	}
	if(index==n){
		lld min = 1<<28;
		for(int i=1;i<l;++i){
			for(int j=0;j<i;++j){
				if(lookup[i][j]!=-1)min=min<lookup[i][j]?min:lookup[i][j];
			}
		}
		return min;
	}
	for(int i=1;i<l;++i){
		for(int j=0;j<i;++j){
			if(lookup[i][j]!=-1){
				set(arr,i,j,lookup[i][j] + cost[query[index-1]][query[index]]);
				set(arr,query[index-1],i, lookup[i][j] + cost[j][query[index]]);
				set(arr,query[index-1],j, lookup[i][j] + cost[i][query[index]]);
			}
		}
	}
	for(int i=0;i<l;++i){
		for(int j=0;j<l;++j){
			lookup[i][j]=-1;
		}
	}
	return getDist(index+1,arr,lookup);
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	lld **lookup=(lld**)calloc(201,sizeof(lld)) , **arr=(lld**)calloc(201,sizeof(lld));
	for(int i=0;i<201;++i){
		lookup[i]=(lld*)calloc(201,sizeof(lld));
		arr[i]=(lld*)calloc(201,sizeof(lld));
	}
	while(t--){
		scanf("%d %d",&l,&n);
		for(int i=0;i<l;++i)for(int j=0;j<l;++j) scanf("%d",&cost[i][j]);
		for(int i=0;i<n;++i){
			scanf("%d",&query[i]);
			--query[i];
		}
		for(int i=0;i<l;++i){
			for(int j=0;j<l;++j){
				lookup[i][j]=-1;
				arr[i][j]=-1;
			}
		}
		if(query[0]>2){
			lookup[1][0]=cost[2][query[0]];
			lookup[2][0]=cost[1][query[0]];
			lookup[2][1]=cost[0][query[0]];
		}else{
			if(query[0]==0)lookup[2][1]=0;
			if(query[0]==1)lookup[2][0]=0;
			if(query[0]==2)lookup[1][0]=0;
		}
		cout<<getDist(1,lookup,arr)<<endl;
	}
	return 0;
}

