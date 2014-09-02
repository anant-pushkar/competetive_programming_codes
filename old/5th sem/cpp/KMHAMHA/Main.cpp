#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#include<queue>
#include<vector>
#include<map>
using namespace std;
bool debug=false;
void print(vector<int> v){
	for(int i=0;i<v.size();++i)cout<<v[i]<<" ";
	cout<<endl;
}
struct Edge{
	int to;
	int capacity;
	Edge(int v,int c):
	to(v),
	capacity(c){}
};
class Solver{
	vector< deque<Edge> > adjList;
	int s , t;
	void add_edge(int from , int to){
		adjList[from].push_back(Edge(to,1));
		adjList[to].push_back(Edge(from,0));
	}
	vector<int> find_path(){
		vector<int> edgeTo(t+1,-1);
		vector<bool> lookup(t+1,false);
		queue<int> q,len;
		q.push(s);len.push(0);lookup[s]=true;edgeTo[s]=s;
		int v,node,l;
		while(!q.empty()){
			v=q.front();q.pop();
			l=len.front();len.pop();
			if(v==t)break;
			for(int i=0;i<adjList[v].size();++i)if(adjList[v][i].capacity!=0 && !lookup[adjList[v][i].to]){
				node=adjList[v][i].to;
				q.push(node);len.push(l+1);lookup[node]=true;edgeTo[node]=v;
			}
		}
		if(v!=t)return vector<int>(0);
		vector<int> path(l);
		for(int i=l-1;i>-1;--i){
			path[i]=v;
			v=edgeTo[v];
		}
		if(debug){
			cout<<"Path : ";
			print(path);
		}
		return path;
	}
	int annotate(vector<int> &v,int start){
		int val=start;
		map<int,int> m;
		for(int i=0;i<v.size();++i){
			if(m.find(v[i])==m.end()){
				m[v[i]]=val++;
			}
		}
		for(int i=0;i<v.size();++i){
			//if(debug)cout<<v[i]<<" changed to "<<m[v[i]]<<endl;
			v[i]=m[v[i]];
		}
		return val;
	}
	void augment(int a,int b){
		for(int i=0;i<adjList[a].size();++i)if(adjList[a][i].to==b){
			adjList[a][i].capacity=0;
		}
		for(int i=0;i<adjList[b].size();++i)if(adjList[b][i].to==a){
			adjList[b][i].capacity=1;
		}
		if(debug) print_adjList();
	}
	void print_adjList(){
		for(int i=0;i<adjList.size();++i){
			for(int j=0;j<adjList[i].size();++j){
				cout<<i<<"->"<<adjList[i][j].to<<":"<<adjList[i][j].capacity<<endl;
			}
			cout<<endl;
		}
	}
public:
	Solver(){
		int num;scanf("%d",&num);
		vector<int>x(num);vector<int>y(num);
		while(num){
			scanf("%d %d",&x[num-1],&y[num-1]);
			--num;
		}
		int x_max=annotate(x,1),y_max=annotate(y,x_max);
		adjList=vector<deque<Edge> >(y_max+2);
		s=0;t=y_max+1;
		for(int i=0;i<x.size();++i) add_edge(x[i],y[i]);
		for(int i=1;i<x_max;++i) add_edge(s,i);
		for(int i=x_max;i<y_max;++i) add_edge(i,t);
		if(debug) print_adjList();
	}
	int solve(){
		vector<int> path;
		int flow=0,v;
		while(1){
			path=find_path();
			if(path.size()==0)break;
			++flow;
			v=s;
			for(int i=0;i<path.size();++i){
				augment(v,path[i]);
				v=path[i];
			}
		}
		return flow;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;scanf("%d",&t);
	while(t){
		Solver s;
		printf("%d\n",s.solve());
		--t;
	}
	return 0;
}

