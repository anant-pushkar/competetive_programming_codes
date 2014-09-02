#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
bool debug=false;
int N,M;
struct Graph{
	vector<deque<int> > adjList;
	int nVertices,nEdges,nCuts;
	
	Graph(int n):
	adjList(vector<deque<int> >(n+1)),
	nVertices(n),
	nEdges(0),
	nCuts(0)
	{
		if(debug){
			cout<<"Created Graph : "<<endl;
			print();
			cout<<endl;
		}
	}
	
	void print(){
		cout<<"\nnVertices : "<<nVertices<<endl;
		cout<<"nEdges    : "<<nEdges<<endl;
		for(int i=1;i<nVertices;i++){
			cout<<"\n\t"<<i<<" : ";
			for(int j=0;j<adjList[i].size();j++){
				cout<<adjList[i][j]<<" ";
			}
		}
		cout<<endl<<endl;
	}
	
	void populate(int e){
		nEdges=e;
		int a,b;
		if(debug)cout<<"Populating.."<<endl;
		while(e){
			scanf("%d %d",&a,&b);
			adjList[a].push_back(b);
			adjList[b].push_back(a);
			e--;
		}
		if(debug){
			cout<<nEdges<<" edges added. New Graph : ";
			print();
		}
	}
	
	int countCuts(int node , int parent){
		int childCount=0,tempCount=0;
		if(debug)cout<<"countCuts called on "<<node<<" from "<<parent<<endl;
		for(int i=0;i<adjList[node].size();i++){
			if(adjList[node][i]!=parent){
				tempCount=countCuts(adjList[node][i],node);
				if(tempCount%2==0){
					if(debug)cout<<"Creating cut "<<node<<"->"<<adjList[node][i]<<endl;
					nCuts++;
				}else{
					if(debug)cout<<"Adding to the block "<<node<<"->"<<adjList[node][i]<<endl;
					childCount+=tempCount;
				}
			}
		}
		if(debug)cout<<"Returning from "<<node<<" with count "<<childCount<<endl;
		return childCount+1;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	scanf("%d %d",&N,&M);
	Graph g(N);
	g.populate(M);
	g.countCuts(1,-1);
	printf("%d\n",g.nCuts);
	return 0;
}

