#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
using namespace std;
bool debug=false;
class Graph{
	vector<deque<int> > adjList;
public:
	Graph(int n , int m):
	adjList(vector<deque<int> >(n))
	{	
		int a,b;
		while(m){
			scanf("%d %d",&a,&b);
			adjList[a-1].push_back(b-1);
			adjList[b-1].push_back(a-1);
			--m;
		}
	}
	bool isTree(){
		queue<int> q,parent;
		vector<bool> lookup(adjList.size(),false);
		
		for(int j=0;j<adjList.size();++j)if(!lookup[j]){
			q.push(j);lookup[j]=true;parent.push(-1);
			int v,p;
			while(!q.empty()){
				v=q.front();q.pop();
				p=parent.front();parent.pop();
				for(int i=0;i<adjList[v].size();++i){
					int node=adjList[v][i];
					if(node!=p){
						if(lookup[node])return false;
						else{
							lookup[node]=true;
							q.push(node);
							parent.push(v);
						}
					}
				}
			}
		}
		return true;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n , m ;
	scanf("%d %d",&n,&m);
	Graph g(n,m);
	if(g.isTree())printf("YES\n");
	else printf("NO\n");
	return 0;
}

