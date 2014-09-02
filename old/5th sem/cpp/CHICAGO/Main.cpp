#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
using namespace std;
bool debug=false;
struct Edge{
	int to;
	double weight;
	
	Edge(int v , double w):
	to(v),
	weight(w/100){}
	
	Edge():
	to(-1),
	weight(-1){}
};
struct Vertex{
	int index;
	double dist;
	
	Vertex(int v):
	index(v){}
	
	Vertex(int v , double d):
	index(v),
	dist(d){}
	
	Vertex(Edge e):
	index(e.to),
	dist(e.weight){}
	
	Vertex():
	index(-1),
	dist(-1){}
};
bool operator==(Vertex v1 , Vertex v2){
	return v1.index==v2.index;
}
struct compare{
	bool operator()(Vertex v1,Vertex v2){
		return v1.dist>v2.dist;
	}
};
class Solver{
	vector< deque<Edge> > adjList;
	vector<int> edgeTo;
	int nVertices,nEdges;
public:
	Solver(int v , int e):
	nVertices(v),
	nEdges(e),
	edgeTo(vector<int>(v,-1)),
	adjList(vector<deque<Edge> >(v))
	{
		int x , y , w;
		while(e){
			scanf("%d %d %d",&x,&y,&w);
			w=100-w;--x;--y;
			adjList[x].push_back(Edge(y,w));
			adjList[y].push_back(Edge(x,w));
			--e;
		}
	}
	double solve(){
		vector<double> distTo(nVertices,1);
		vector<int> edgeTo(nVertices,0);
		priority_queue<Vertex,vector<Vertex>,compare> q;
		set<int> tree;
		
		distTo[0]=1;edgeTo[0]=0;
		q.push(Vertex(0,1));
		
		Vertex v,node;
		double oldDist,newDist;
		while(!q.empty()){
			v=q.top();q.pop();
			tree.insert(v.index);
			if(debug) cout<<"Adding "<<v.index+1<<" to tree"<<endl;
			for(int i=0;i<adjList[v.index].size();++i){
				if(tree.find(adjList[v.index][i].to)==tree.end()){
					node=adjList[v.index][i];
					oldDist=distTo[node.index];
					newDist=distTo[v.index]*node.dist;
					if(newDist<oldDist){
						if(debug)cout<<"relaxing distTo["<<node.index+1<<"] to "<<newDist<<endl;
						distTo[node.index]=newDist;
						edgeTo[node.index]=v.index;
					}else{
						if(debug)cout<<"distTo["<<node.index+1<<"]="<<oldDist<<endl;
					}
					q.push(node);
				}
			}
		}
		double p=1;
		int vIndex=nVertices-1;
		while(vIndex!=0){
			for(int i=0;i<adjList[vIndex].size();++i)if(adjList[vIndex][i].to==edgeTo[vIndex]){
				p*=1-adjList[vIndex][i].weight;
				if(debug){
					cout<<"Moving to "<<adjList[vIndex][i].to+1<<endl;
					cout<<"p="<<p<<endl<<endl;
				}
				vIndex=edgeTo[vIndex];
				break;
			}
		}
		return p*100;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int e,v;
	while(1){
		scanf("%d",&v);
		if(v==0)break;
		scanf("%d",&e);
		Solver s(v,e);
		printf("%f percent\n",s.solve());
	}
	return 0;
}

