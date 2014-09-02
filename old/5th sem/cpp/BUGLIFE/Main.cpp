#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
bool debug=false;
enum gType{NONE=0 , G1=1 , G2=2};
gType comp(gType g){
	if(g==G1)return G2;
	if(g==G2)return G1;
	return NONE;
}
class Solver{
	vector<deque<int> >adjList;
	vector<gType> group;
	int nEdges,nVertices,v;
	gType g;
	bool assign(){
		queue<int> q;
		queue<gType> groupQ;
		for(int i=0;i<nVertices;++i)if(group[i]==NONE){
			group[i]=G1;
			q.push(i);groupQ.push(group[i]);
			while(!q.empty()){
				v=q.front();q.pop();
				g=groupQ.front();groupQ.pop();
				for(int i=0;i<adjList[v].size();++i){
					switch(group[adjList[v][i]]){
					case NONE:
						group[adjList[v][i]]=comp(g);
						q.push(adjList[v][i]);
						groupQ.push(group[adjList[v][i]]);
						break;
					case G1:
						if(g==G1)return false;
						break;
					case G2:
						if(g==G2)return false;
						break;
					}
				}
			}
		}
		return true;
	}
public:
	Solver(int v , int e):
	nVertices(v),
	nEdges(e),
	adjList(vector<deque<int> >(v+1)),
	group(vector<gType>(v+1,NONE)){
		int x,y;
		while(e){
			scanf("%d %d",&x,&y);
			adjList[x].push_back(y);
			adjList[y].push_back(x);
			--e;
		}
	}
	bool solve(){
		bool check=assign();
		if(check){
			printf("No suspicious bugs found!\n");
		}else{
			printf("Suspicious bugs found!\n");
		}
		return check;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,i=1,v,e;scanf("%d",&t);
	while(t){
		scanf("%d %d",&v,&e);
		Solver s(v,e);
		printf("Scenario #%d:\n",i);
		s.solve();
		--t;++i;
	}
	return 0;
}

