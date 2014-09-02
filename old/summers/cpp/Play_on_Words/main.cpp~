/*
Project name : Play_on_Words
Created on : Fri Jun 13 15:57:09 2014
Author : Anant Pushkar
http://www.spoj.com/problems/WORDS1/
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
#include<cmath>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Graph{
	vector<int> inDegree , outDegree ;
	vector<deque<int> > adjList;
	int nWords;
	bool isConnected(int c1,int c2){
		vector<bool>lookup(26,false);
		queue<int> q;
		int count=0 , index , nodeCount=0 ;
		for(int i=0;i<26;++i){
			if(outDegree[i]!=0){
				index = i;
			}
			if(outDegree[i]!=0 || inDegree[i]!=0){
				++nodeCount;
			}
		}
		if(debug)cout<<"pushing "<<index<<endl;
		q.push(index);
		lookup[index]=true;
		++count;
		while(!q.empty()){
			for(int i=0;i<outDegree[q.front()];++i)if(!lookup[adjList[q.front()][i]]){
				if(debug)cout<<"pushing "<<adjList[q.front()][i]<<endl;
				lookup[adjList[q.front()][i]] = true;
				q.push(adjList[q.front()][i]);
				++count;
			}
			q.pop();
		}
		if(debug)printf("count = %d , nodeCount = %d\n",count,nodeCount-c1);
		return count == nodeCount-(c1&c2);
	}
public:
	Graph(int n):
		nWords(n),
		inDegree(vector<int>(26,0)),
		outDegree(vector<int>(26,0)),
		adjList(vector<deque<int> >(26)){
			char str[1001];
			for(int i=0;i<n;++i){
				scanf("%s",str);
				++outDegree[str[0]-'a'];
				adjList[str[0]-'a'].push_back(str[strlen(str)-1]-'a');
				++inDegree[str[strlen(str)-1]-'a'];
			}
		}
	bool hasEulerianPath(){
		if(nWords==1){
			return true;
		}
		int count1=0 , count2=0 , count=0;;
		for(int i=0;i<26;++i){
			if(inDegree[i]==outDegree[i]+1){
				++count1;
			}else if(outDegree[i]==inDegree[i]+1){
				++count2;
			}else if(outDegree[i]!=inDegree[i]){
				++count;
			}
			if(debug)cout<<inDegree[i]<<" "<<outDegree[i]<<endl;
			if(abs(inDegree[i]-outDegree[i])>1){
				return false;
			}
		}
		return isConnected(count1,count2) && ((count1==1 && count2==1) || (count1==0 && count2==0));
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		Graph g(n);
		printf("%s\n",g.hasEulerianPath()? "Ordering is possible." : "The door cannot be opened.");
	}
	return 0;
}

