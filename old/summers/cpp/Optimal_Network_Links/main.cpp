/*
Project name : Optimal_Network_Links
Created on : Wed May 21 19:11:51 2014
Author : Anant Pushkar
https://www.hackerrank.com/contests/apc/challenges/optimal-network-links
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<utility>
#include<vector>
#include<climits>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;
bool debug=false;
typedef long long int lld;
class  Solver{
	int nEdges,nVertices;
	vector<pair<string,string> > edgelist;
	unordered_map<string,int> nodeset;
	vector<vector<pair<int,int> > > adjList,rAdjList;
public:
	Solver(int num):
		nEdges(num),
		edgelist(vector<pair<string,string> >(num)){
		unordered_map<string,int> reverseset;
		for(int i=0;i<nEdges;++i){
			cin>>edgelist[i].first>>edgelist[i].second;
			
			if(nodeset.find(edgelist[i].first) == nodeset.end())nodeset[edgelist[i].first] = 1;
			else ++nodeset[edgelist[i].first];
			
			if(nodeset.find(edgelist[i].second) == nodeset.end())nodeset[edgelist[i].second] = 0;
			
			if(reverseset.find(edgelist[i].second) == reverseset.end())reverseset[edgelist[i].second] = 1;
			else ++reverseset[edgelist[i].second];
			
			if(reverseset.find(edgelist[i].first) == reverseset.end())reverseset[edgelist[i].first] = 0;
		}
		nVertices = nodeset.size();
		adjList = vector<vector<pair<int,int> > >(nVertices);
		rAdjList = vector<vector<pair<int,int> > >(nVertices);
		
		unordered_map<string,int>::iterator iter;
		int index[nVertices],rIndex[nVertices],idx=0;
		for(iter=nodeset.begin();iter!=nodeset.end();++iter){
			adjList[idx] = vector<pair<int,int> >(iter->second);
			index[idx] = iter->second - 1;
			iter->second = idx;
			++idx;
		}
		
		for(iter=reverseset.begin();iter!=reverseset.end();++iter){
			idx = nodeset[iter->first];
			rAdjList[idx] = vector<pair<int,int> >(iter->second);
			rIndex[idx] = iter->second - 1;
		}
		
		for(int i=0;i<nEdges;++i){
			idx = nodeset[edgelist[i].first];
			adjList[idx][index[idx]--] = make_pair(nodeset[edgelist[i].second] , i);
			
			idx = nodeset[edgelist[i].second];
			rAdjList[idx][rIndex[idx]--] = make_pair(nodeset[edgelist[i].first] , i);
		}
		if(debug){
			cout<<"AdjList : "<<endl;
			for(int i=0;i<nVertices;++i){
				cout<<"#"<<i<<" : ";
				for(int j=0;j<adjList[i].size();++j)cout<<adjList[i][j].first<<" ";
				cout<<endl;
			}
			cout<<"Reverse AdjList : "<<endl;
			for(int i=0;i<nVertices;++i){
				cout<<"#"<<i<<" : ";
				for(int j=0;j<rAdjList[i].size();++j)cout<<rAdjList[i][j].first<<" ";
				cout<<endl;
			}
		}
	}
	vector<pair<string,string> > solve(){
		vector<unordered_map<int,int> > connectionSet(nVertices);
		queue<pair<int,int> > q;
		for(int i=0;i<nVertices;++i){
			for(int j=0;j<adjList[i].size();++j){
				connectionSet[i][adjList[i][j].first] = adjList[i][j].second;
				for(int k=0;k<rAdjList[i].size();++k){
					if(debug)cout<<"Pushing event : "<< rAdjList[i][k].first<<","<<adjList[i][j].first<<endl;
					q.push(make_pair(rAdjList[i][k].first,adjList[i][j].first));
				}
			}
		}
		queue<int> redundant;
		int rec , dest;
		while(!q.empty()){
			rec = q.front().first;
			dest= q.front().second;
			if(debug)cout<<"Receiver : "<<rec<<" Dest : "<<dest<<endl;
			q.pop();
			if(connectionSet[rec].find(dest) != connectionSet[rec].end()){
				if(connectionSet[rec][dest]!=-1){
					if(debug)cout<<"Pushing edge#"<<connectionSet[rec][dest]<<endl;
					redundant.push(connectionSet[rec][dest]);
				}
			}else{
				for(int i=0;i<adjList[rec].size();++i){
					q.push(make_pair(adjList[rec][i].first,dest));
				}
			}
			connectionSet[rec][dest] = -1;
		}
		int index = redundant.size()-1;
		vector<pair<string,string> > rList(index+1);
		while(!redundant.empty()){
			rList[index] = edgelist[redundant.front()];
			redundant.pop();
			--index;
		}
		return rList;
	}
};
bool compare(const pair<string,string> &p1 , const pair<string,string> &p2){
	return p1.first<p2.first ? true : p1.first!=p2.first ? false : p1.second<p2.second;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	vector<pair<string,string> > rList;
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%d",&n);
		Solver s(n);
		rList = s.solve();
		cout<<"Case "<<(i+1)<<": "<<rList.size()<<" " ;
		sort(rList.begin(),rList.end(),compare);
		for(int i=0;i<rList.size();++i)cout<<rList[i].first<<","<<rList[i].second<<" ";
		cout<<endl;
	}
	return 0;
}

