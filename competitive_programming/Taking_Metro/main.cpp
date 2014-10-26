/*
Project name : Taking_Metro
Created on : Mon Oct 13 11:55:19 2014
Author : Anant Pushkar
https://code.google.com/codejam/contest/5214486/dashboard#s=p1
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
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
struct compare_vertex{
    bool operator()(const pair<int,lld> &p1 , const pair<int,lld> &p2){
        return p1.second>p2.second;
    }
};
typedef priority_queue<pair<int,lld> , vector<pair<int,lld> > , compare_vertex> node_pq;
class Solver{
    int n , e , t , m;
    vector<deque<pair<int,lld> > > adjList;
    vector<lld> min_dist;
    vector<vector<int> > station_index;
    node_pq pq;
    void push_node(int index , lld dist){
    	//if(debug)cout<<"attempting to push "<<index<<" with dist "<<dist<<" , "<<min_dist[index]<<endl;
        if(min_dist[index] < dist){
            return;
        }
        if(debug)cout<<"pushed "<<index<<endl;
        pq.push(make_pair(index , dist));
        min_dist[index] = dist;
    }
public:
    Solver(){
        int n_lines;
        scanf("%d",&n_lines);
        
        if(debug)cout<<"number of lines : "<<n_lines<<endl;
        
        int index=0;
        vector<int> n_stations(n_lines);
        vector<int> wait_times(n_lines);
        vector<vector<int> > btwn_times(n_lines) ;
        station_index = vector<vector<int> >(n_lines);
        for(int i=0;i<n_lines;++i){
        	scanf("%d %d",&n_stations[i] , &wait_times[i]);
        	btwn_times[i] = vector<int>(n_stations[i]-1);
        	station_index[i] = vector<int>(n_stations[i]);
        	for(int j=0;j<n_stations[i]-1;++j){
        		scanf("%d",&btwn_times[i][j]);
        		station_index[i][j] = index++;
        		if(debug)cout<<"station_index of "<<i<<" "<<j<<" : "<<station_index[i][j]<<endl;
        	}
        	station_index[i][n_stations[i]-1] = index++;
        	if(debug)cout<<"station_index of "<<i<<" "<<n_stations[i]-1<<" : "<<station_index[i][n_stations[i]-1]<<endl;
        }
        
        int n_tunnels;
        scanf("%d",&n_tunnels);
        
        vector<int> start_line(n_tunnels);
        vector<int> start_station(n_tunnels);
        vector<int> end_line(n_tunnels);
        vector<int> end_station(n_tunnels);
        vector<int> time(n_tunnels);
        for(int i=0;i<n_tunnels;++i){
        	scanf("%d %d %d %d %d",&start_line[i],&start_station[i],&end_line[i],&end_station[i],&time[i]);
        	--start_line[i];
        	--start_station[i];
        	--end_line[i];
        	--end_station[i];
        	if(debug)cout<<"Tunnel#"<<i<<" : "<<start_line[i]<<" "<<start_station[i]<<" "<<end_line[i]<<" "<<end_station[i]<<endl;
        }
        
        int start , end;
        lld val;
        adjList = vector<deque<pair<int,lld> > >(index+1);
        for(int i=0;i<n_lines;++i){
        	for(int j=0;j<n_stations[i]-1;++j){
        		start = station_index[i][j];
        		
        		val   = wait_times[i];
        		for(int k=j+1;k<n_stations[i];++k){
        			end  = station_index[i][k];
        			val += btwn_times[i][k-1];
        			
        			adjList[start].push_back(make_pair(end , val));
        			adjList[end].push_back(make_pair(start , val));
        			if(debug)cout<<"Edge : "<<start<<"->"<<end<<" : "<<val<<endl;
        		}
        		
        		val   = wait_times[i];
        		for(int k=j-1;k>-1;--k){
        			end  = station_index[i][k];
        			val += btwn_times[i][k];
        			
        			adjList[start].push_back(make_pair(end , val));
        			adjList[end].push_back(make_pair(start , val));
        			if(debug)cout<<"Edge : "<<start<<"->"<<end<<" : "<<val<<endl;
        		}
        	}
        }
        
        if(debug)cout<<"Adding tunnels"<<endl;
        
        for(int i=0;i<n_tunnels;++i){
        	start = station_index[start_line[i]][start_station[i]];
        	end   = station_index[end_line[i]][end_station[i]];
        	val   = time[i];
        	
        	adjList[start].push_back(make_pair(end , val));
        	if(debug)cout<<"Edge : "<<start<<"->"<<end<<" : "<<val<<endl;
        	
        	adjList[end].push_back(make_pair(start , val));
        	if(debug)cout<<"Edge : "<<end<<"->"<<start<<" : "<<val<<endl;
        }
        
    }
    int solve(int x1 , int y1 , int x2 , int y2){
    	if(debug)cout<<"solving "<<x1-1<<","<<y1-1<<" "<<x2-1<<","<<y2-1<<endl;
    	if(debug)cout<<"start : "<<station_index[x1-1][y1-1]<<" end:"<<station_index[x2-1][y2-1]<<endl;
    	
    	e = station_index[x1-1][y1-1];
    	min_dist = vector<lld>(adjList.size() , INT_MAX);
        push_node(e , 0);

        int size;
        pair<int,lld> vertex;
        while(!pq.empty()){
            vertex = pq.top();
            pq.pop();
			
			if(debug)cout<<"expanding "<<vertex.first<<" at dist "<<vertex.second<<endl;
			
            size = adjList[vertex.first].size();
            for(int i=0;i<size;++i){
                push_node(adjList[vertex.first][i].first , vertex.second +   adjList[vertex.first][i].second);
            }
            
            /*if(debug){
            	cout<<"min dist :";
            	for(int i=0;i<min_dist.size();++i){
            		cout<<min_dist[i]<<" ";
            	}
            	cout<<endl;
            }*/
        }

        return min_dist[station_index[x2-1][y2-1]];
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int T;
	scanf("%d",&T);
	
	int q , x1 , y1 , x2 , y2 , dist;
	for(int t=1;t<=T;++t){
		Solver s;
		printf("Case #%d:\n" , t);
		
		scanf("%d",&q);
		while(q--){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			dist = s.solve(x1,y1,x2,y2);
			if(dist!=INT_MAX){
				cout<<dist<<endl;
			}else{
				cout<<-1<<endl;
			}
			if(debug)cout<<"============="<<endl;
		}
	}
	
	return 0;
}

