#include<stdio.h>
#include<vector>
using namespace std;
class Graph{
	int E;								 //number of Edges
	int V; 								 //number of vertices
	std::vector< std::vector<int> > adj; //vector containing edjecendy lists
public:
	Graph(int v):
	V(v),
	E(0)
	{
		for(int i=0;i<v;i++)
			adj.push_back(std::vector<int>(0));
	}
	int nVertices(){return V;}
	int nEdges()   {return E;}
	void addEdge(int v , int w)
	{
		adj[v].push_back(w);
		adj[w].push_back(v);
		E++;
	}
	std::vector<int> adjList(int v)
	{
		return adj[v];
	}
};
class CC{
	vector<int> CSet;
	vector<int> checkList;
	void dfs(Graph g, int v)
	{
		this->checkList[v]=1;
		CSet.push_back(v);
		vector<int> adj=g.adjList(v);
		for(int i=0;i<adj.size();i++){
			if(this->checkList[adj[i]]==0)
				this->dfs(g,adj[i]);
		}
	}
public:
	vector<vector<int> > set;
	CC(Graph g):
	checkList(vector<int>(g.nVertices(),0))
	{
		for(int i=0;i<g.nVertices();i++){
			if(checkList[i]==0){
				CSet.clear();
				dfs(g,i);
				set.push_back(CSet);
			}
		}
	}
};
int main()
{
	int N,M,a,b;
	scanf("%d %d",&N,&M);
	Graph g(N);vector<int> costList(N);
	for(int m=0;m<M;m++)
	{
		scanf("%d %d",&a , &b );
		g.addEdge(a-1,b-1);
	}
	CC connects(g);
	for(int i=0;i<N;i++)
		scanf("%d",&costList[i]);
	if(N==connects.set[0].size()){
		printf("0\n");;
		return 0;
	}
	vector<int> minCostList(connects.set.size(),20000);
	for(int i=0;i<connects.set.size();i++){
		for(int j=0;j<connects.set[i].size();j++){
			if(costList[connects.set[i][j]]!=-1)
				minCostList[i] = minCostList[i]>costList[connects.set[i][j]] ? costList[connects.set[i][j]] : minCostList[i];
		}
	}
	int sum=0;
	for(int i=0;i<minCostList.size();i++){
		if(minCostList[i]==20000){
			printf("-1\n");
			return 0;
		}else{
			sum+=minCostList[i];
		}
	}
	printf("%d\n",sum);
	return 0;
}
