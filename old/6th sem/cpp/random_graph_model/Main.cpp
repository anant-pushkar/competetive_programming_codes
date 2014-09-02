/*
Project name : random_graph_model
Created on : Wed Jan 15 18:21:15 2014
Author : Anant Pushkar
project to test and visualise degree distribution in random graph model
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<ctime>
#include<deque>
#include<queue>
#include<cstdlib>
using namespace std;
bool debug=false;
const int MAX=100;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,v,count;scanf("%d",&t);
	float p;
	srand(time(NULL));
	vector<double> avg_degree(t);
	while(t--){
		scanf("%d %f",&n,&p);
		vector<deque<int> > adjList(n);
		vector<int> freq(n-1,0);
		//uncomment to draw graph
		printf("^{\"type\":\"graph\",\"name\":\"Random Graph(%d,%f)\",\"obj\":[",n,p);
		double sum=0;
		for(int i=1;i<n;++i){
			count=0;
			for(int j=0;j<i;++j){
				v=rand()%MAX+1;
				if(v+(adjList[j].size()*14/n)*MAX<p*MAX){
					//uncomment to draw graph
					printf("[%d,%d,\"\"]\n,",i+1,j+1);
					adjList[i].push_back(j);
					adjList[j].push_back(i);
					++count;
				}
			}
			++freq[count];
			sum+=count;
		}
		//uncomment to draw graph
		printf("[1,1,\"\"]]}\n");
		//printf("Average Degree:%f\n",(sum/n));
		//avg_degree[t]=(sum/n);
		sum=0;
		for(int i=0;i<n;++i){
			vector<int>dist(n,1<<29);
			
			dist[i]=0;
			queue<int> q;
			q.push(i);
			int v;
			while(!q.empty()){
				v=q.front();
				q.pop();
				for(int j=0;j<adjList[v].size();++j)if(dist[adjList[v][j]]>dist[v]+1)
				{
					q.push(adjList[v][j]);
					dist[adjList[v][j]]=dist[v]+1;
				}
			}
			int max=0;
			for(int j=0;j<n;++j)if(dist[j]!=1<<29){
				max=max>dist[j]?max:dist[j];
			}
			sum+=max;
		}
		avg_degree[t]=(sum/n);
		
		/*printf("inverse Average Eccentricity : %f\n",avg_degree[t]!=0?1/avg_degree[t]:1);*/
		//uncomment to draw Degree Distribution
		
		printf("^{\"type\":\"data\",\"name\":\"Degree Distribution(%d,%f)\",\"obj\":[[",n,p);
		for(int i=0;i<n/2-1;++i)printf("%d,",freq[i]);
		printf("%d],\n",freq[n-1]);
		
		freq=vector<int>(n-1,0);
		for(int i=0;i<n;++i){
			sum=0;
			for(int j=0;j<adjList[i].size();++j)sum+=adjList[adjList[i][j]].size();
			++freq[sum/adjList[i].size()];
		}
		printf("[",n,p);
		for(int i=0;i<n/2-1;++i)printf("%d,",freq[i]);
		printf("%d]]}\n",freq[n-1]);
	}
	/*printf("^{\"type\":\"data\",\"name\":\"Inverse Average Eccentricity\",\"obj\":[");
	for(int i=avg_degree.size()-1;i>0;--i)printf("\"%f\",",avg_degree[i]!=0?1/avg_degree[i]:2);
	printf("\"%f\"]}\n",avg_degree[0]!=0?1/avg_degree[0]:2);
	printf("^{\"type\":\"data\",\"name\":\"Average Eccentricity\",\"obj\":[");
	for(int i=avg_degree.size()-1;i>0;--i)printf("\"%f\",",avg_degree[i]);
	printf("\"%f\"]}\n",avg_degree[0]);*/
	return 0;
}

