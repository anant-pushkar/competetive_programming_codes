#include<iostream>
#include<cstring>
#include<cstdio>
#include<utility>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
bool debug=false;
inline double getSlope(pair<int,int> p1 , pair<int,int> p2){
	int deltaY=p1.second- p2.second ;
	int deltaX=p1.first - p2.first  ;
	return static_cast<double>(deltaX)/(deltaY);
}
inline int getDist(pair<int,int> p1 , pair<int,int> p2){
	int dist=(p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second);
	return abs(dist);
}
struct Graph{
	vector<unordered_map<double,int > > adjList;
	vector<pair<int,int> > plane;
	int nVertices;
	
	Graph(int n):
	adjList(vector<unordered_map<double,int > >(n)),
	plane(vector<pair<int,int> >(n)),
	nVertices(n)
	{}
	
	void populate(){
		int x,y;
		for(int i=0;i<nVertices;i++){
			scanf("%d %d",&x,&y);
			plane[i]=make_pair(x,y);
		}
	}
	
	void computeAdjList(){
		double slope;
		int index;
		for(int i=0;i<nVertices;i++){
			for(int j=0;j<nVertices;j++)if(i!=j){
				slope=getSlope(plane[i],plane[j]);
				if(adjList[i].find(slope)==adjList[i].end()){
					adjList[i][slope]=j;
				}else{
					index=adjList[i][slope];
					if(getDist(plane[index],plane[i])<getDist(plane[j],plane[i])){
						adjList[i][slope]=index;
					}
				}
			}
		}
	}
	
	void printAdjList(){
		cout<<"AdjList : "<<endl;
		unordered_map<double,int>::iterator it;
		for(int i=0;i<nVertices;i++){
			cout<<"#"<<i<<endl;
			for(it=adjList[i].begin();it!=adjList[i].end();++it){
				cout<<"\t"<<it->first<<" : "<<it->second<<endl;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	
	void printPlane(){
		cout<<"Plane Points : "<<endl;
		for(int i=0;i<nVertices;i++){
			cout<<"\t#"<<i<<" : "<<plane[i].first<<","<<plane[i].second<<endl;
		}
		cout<<endl<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T,N;scanf("%d",&T);
	while(T){
		scanf("%d",&N);
		Graph g(N);
		
		g.populate();
		if(debug)g.printPlane();
		
		g.computeAdjList();
		if(debug)g.printAdjList();
		
		--T;
	}
	return 0;
}

