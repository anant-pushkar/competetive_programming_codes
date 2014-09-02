#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
bool debug=false;
int count;
vector<bool> lookup;
vector<bool> visited;
vector<deque<int> > adjList;
void dfs(int index){
	visited[index]=true;
	for(int i=0;i<adjList[index].size();++i)if(visited[adjList[index][i]]==false){
		dfs(adjList[index][i]);
		if(!lookup[index] && !lookup[adjList[index][i]]){
			lookup[index]=true;
			++count;
		}
	}
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	
	int n;scanf("%d",&n);
	lookup  = vector<bool>(n,false) ;
	visited = vector<bool>(n,false) ;
	adjList = vector<deque<int> >(n);
	--n;
	
	int x,y;
	while(n--){
		scanf("%d %d",&x,&y);
		--x;--y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	
	count=0;
	dfs(0);
	printf("%d\n",count);
	
	return 0;
}

