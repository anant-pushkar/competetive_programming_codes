/*
Project name : Multitasking
Created on : Mon Jan 20 21:45:07 2014
Author : Anant Pushkar
codeforces 384 : B 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
typedef long long int lld;
int n,m,mode;
bool isOrdered(int a,int b){
	return mode==1?a>b:a<b;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	cin>>n>>m;
	cin>>mode;
	
	vector<vector<int> > arr(n,vector<int>(m,0));
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			cin>>arr[i][j];
	if(debug)cout<<"input over"<<endl;
	vector<vector<int> > lookup(m,vector<int>(m,0));
	int count;
	for(int i=1;i<m;i++){
		for(int j=0;j<i;++j){
			count=0;
			for(int k=0;k<n;++k)if(!isOrdered(arr[k][j],arr[k][i])){
				++count;
			}
			lookup[j][i]=count;
			if(debug)cout<<"lookup "<<j<<" "<<i<<" "<<count<<endl;
		}
	}
	if(debug)cout<<"precomputation over"<<endl;
	deque<pair<int,int> > soln;
	int max,x,y;
	bool check;
	while(1){
		max=-1;
		for(int i=1;i<m;++i){
			for(int j=0;j<i;++j){
				if(lookup[j][i]!=-1 && max<lookup[j][i]){
					max=lookup[j][i];
					x=j;
					y=i;
				}
			}
		}
		if(debug)cout<<"swapping "<<x<<","<<y<<endl;
		for(int i=x+1;i<=y;++i)if(lookup[x][i]>0)lookup[x][i]=n-lookup[x][i];
		for(int i=x;i<y;++i)if(lookup[y][i]>0)lookup[y][i]=n-lookup[y][i];
		lookup[x][y]=-1;
		soln.push_back(make_pair(x,y));
		check=true;
		for(int i=1;i<m;++i){
			for(int j=0;j<i;++j)if(lookup[j][i]>0){
				check=false;
				break;
			}
		}
		if(check)break;
	}
	vector<deque<int> > adjList(m);
	for(int i=0;i<soln.size();++i){
		if(debug)cout<<"connectng "<<soln[i].first<<" "<<soln[i].second<<endl;
		adjList[soln[i].first].push_back(soln[i].second);
		//adjList[soln[i].second].push_back(soln[i].first);
	}
	vector<vector<int> > mat(m,vector<int>(m,0));
	for(int i=0;i<m;++i){
		if(debug)cout<<i<<":"<<endl;
		for(int j=0;j<adjList[i].size();++j){
			for(int k=j+1;k<adjList[i].size();++k){
				mat[adjList[i][j]][adjList[i][k]]=1;
				if(debug)cout<<"eleminating "<<adjList[i][j]<<" "<<adjList[i][k]<<endl;
			}
		}
		if(debug)cout<<endl;
	}
	count=0;
	for(int i=0;i<soln.size();++i)if(mat[soln[i].first][soln[i].second]==1)++count;
	cout<<(soln.size()-count)<<endl;
	for(int i=0;i<soln.size();++i)if(mat[soln[i].first][soln[i].second]!=1)cout<<soln[i].first+1<<" "<<soln[i].second+1<<endl;
	return 0;
}

