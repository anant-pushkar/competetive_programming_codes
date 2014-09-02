#include "Hamiltonian.h"
//#include<iostream>
void Hamiltonian::dfs(Graph g, int v,int s)
{
	//std::cout<<"DFS Called at "<<v<<" from "<<s<<"with count "<<count<<std::endl;
	if(checkList[0]>(2<<g.nVertices()))
		return;
	if(v==0) {
		checkList[0]++;
		if(checkList[0]!=1)return;
	}
	this->checkList[v]=1;
	cycle[count]=v;count++;
	std::vector<int> adj=g.adjList(v);
	for(int i=0;i<adj.size();i++){
		if(this->checkList[adj[i]]==0 && adj[i]!=s){
			this->dfs(g,adj[i],v);
			//std::cout<<"Exited from "<<adj[i]<<std::endl;
			if(count!=g.nVertices()){
				checkList[adj[i]]=0;
				cycle[count]=-1;count--;
				//std::cout<<adj[i]<<" re,oved from cycle"<<std::endl;
			}
		}
	}
}
Hamiltonian::Hamiltonian(Graph g):
checkList(std::vector<int>(g.nVertices(),0)),
cycle(std::vector<int>(g.nVertices(),0)),
count(0)
{
	dfs(g,0,0);
}
int Hamiltonian::cycleSize(){
	return count;
}