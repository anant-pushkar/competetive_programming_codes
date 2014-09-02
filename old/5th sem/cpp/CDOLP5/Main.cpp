#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<utility>
#include<queue>
#include<unordered_set>
#include<set>
using namespace std;
bool debug=false;
struct Graph{
	vector<deque<pair<int,int> > > adjList;
	set<pair<int,int> > criticalEdges;
	Graph(int n, int e):
	adjList(vector<deque<pair<int,int> > > (n)){
		int v1,v2,c;
		while(e){
			scanf("%d %d %d",&v1,&v2,&c);
			adjList[v1-1].push_back(make_pair(v2-1,c));
			//adjList[v2-1].push_back(make_pair(v1-1,c));
			//if(debug)cout<<"scanned : "<<v1<<"-"<<v2<<"("<<c<<")"<<endl;
			--e;
		}
		if(debug){
			for(int i=0;i<adjList.size();++i){
				cout<<"AdjList #"<<i<<endl;
				for(int j=0;j<adjList[i].size();++j){
					cout<<"\tto:"<<adjList[i][j].first<<" ("<<adjList[i][j].second<<")"<<endl;
				}
				cout<<endl;
			}
		}
	}
	deque<pair<int,int> > getPath(){
		if(debug)cout<<"getPath() called..."<<endl;
		int index=0;
		queue<int> q;q.push(index);
		if(debug)cout<<"\tEnqued:"<<index<<endl;
		vector<pair<int,int> > edgeTo(adjList.size());
		vector<bool>lookup(adjList.size(),false);
		edgeTo[0]=make_pair(0,0);lookup[0]=true;
		while(!q.empty()){
			index=q.front();q.pop();
			if(debug)cout<<"Processing "<<index<<endl;
			if(index==adjList.size()-1)break;
			for(int i=0;i<adjList[index].size();++i)if(!lookup[adjList[index][i].first] && adjList[index][i].second!=0){
				edgeTo[adjList[index][i].first]=make_pair(index,adjList[index][i].second);
				q.push(adjList[index][i].first);
				if(debug)cout<<"\tEnqued:"<<adjList[index][i].first<<endl;
				lookup[adjList[index][i].first]=true;
			}
		}
		deque<pair<int,int> > d;
		index=adjList.size()-1;
		while(edgeTo[index].first!=index){
			d.push_front(make_pair(index,edgeTo[index].second));
			index=edgeTo[index].first;
		}
		if(debug){
			cout<<"Returning path of length "<<d.size()<<endl;
			for(int i=0;i<d.size();++i){
				cout<<"\t to:"<<d[i].first<<" capacity:"<<d[i].second<<endl;
			}
		}
		return d;
	}
	int  getMaxFlow(){
		deque<pair<int,int> > path;
		int minCapacity=100000,flow=0,count=0;
		do{
			path=getPath();
			minCapacity=100000;
			for(int i=0;i<path.size();++i){
				if(minCapacity>path[i].second){	
					minCapacity=path[i].second;
				}
			}
			int index=0;
			for(int i=0;i<=path.size();++i){
				for(int j=0;j<adjList[index].size();++j){
					if(adjList[index][j].first==path[i].first){
						if(debug)cout<<"Reducing flow"<<endl;
						adjList[index][j].second-=minCapacity;
						if(adjList[index][j].second==0){
							if(debug)cout<<"Adding critical edge"<<endl;
							criticalEdges.insert(make_pair(path[i].first*index,path[i].first+index));
						}
						if(debug)cout<<"Adding reverse flow"<<endl;
						bool check=false;
						for(int k=0;k<adjList[path[i].first].size();++k){
							if(adjList[path[i].first][k].first==index){
								if(debug)cout<<"Edge Previously added, incrementing value"<<endl;
								adjList[path[i].first][k].second+=minCapacity;
								check=true;
								break;
							}
						}
						if(!check){
							if(debug)cout<<"Addign new edge"<<endl;
							adjList[path[i].first].push_back(make_pair(index,minCapacity));
						}
					}
				}
				if(i!=path.size())index=path[i].first;
			}
			if(minCapacity!=100000){
				flow+=minCapacity;
				++count;
			}
		}while(path[0].second!=0);
		return flow;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,e;
	scanf("%d %d",&n,&e);
	Graph g(n,e);
	int flow=g.getMaxFlow();
	if(debug)cout<<"Max Flow : "<<flow<<endl; 
	printf("%d\n",(e-g.criticalEdges.size()));
	return 0;
}

