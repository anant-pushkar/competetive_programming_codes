/*
Project name : Simplify_Path
Created on : Wed Oct  1 19:34:49 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/simplify-path/
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
class Solution{
public:
	bool debug;
	string simplifyPath(string path) {
        int n=path.size();
        if(n==0){
            return path;
        }
        if(debug){
        	cout<<"======================="<<endl;
        	cout<<"original path : "<<path<<endl;
        }
        queue<int> pos;
        for(int i=0;i<n;++i){
        	if(debug)cout<<i<<" : "<<endl;
        	if(i<n-1 && path[i]=='/' && path[i+1]!='/'){
		    	if(debug)cout<<"pushing position "<<i<<endl;
		        pos.push(i);
		    }
		}
        if(pos.empty()){
        	path.erase (std::remove(path.begin(), path.end(), '/'), path.end());
            return "/" + path;
        }
        
        int index=pos.front();
        if(debug)cout<<"index : "<<index<<endl;
        pos.pop();
        deque<string> dir;
        while(!pos.empty()){
        	if(debug)cout<<"appending "<<path.substr(index+1 , pos.front() - index-1)<<endl;
            dir.push_back(path.substr(index+1 ,pos.front() - index-1));
            index = pos.front();
            pos.pop();
            if(debug)cout<<"index : "<<index<<endl;
        }
        if(debug)cout<<"appending "<<path.substr(index+1 , n-index-1 - (path[n-1]=='/' ? 1 : 0))<<endl;
        dir.push_back(path.substr(index+1 ,n-index-1 - (path[n-1]=='/' ? 1 : 0)));
        stack<string> s;
        int m = dir.size();
        for(int i=0;i<m;++i){
        	dir[i].erase (std::remove(dir[i].begin(), dir[i].end(), '/'), dir[i].end());
            if(dir[i]=="."){
                continue;
            }else if(dir[i]==".."){
            	if(s.empty()){
            		break;
            	}
                s.pop();
            }else{
                s.push(dir[i]);
            }
            
        }
        
        string simple_path="";
        if(!s.empty()){
        	simple_path=s.top();
	        s.pop();
	    }
        while(!s.empty()){
        	if(debug)cout<<"simple path : "<<simple_path<<endl;
            simple_path = s.top() + "/" + simple_path;
            s.pop();
        }
        
        if(debug)cout<<"================"<<endl;
        return "/" + simple_path;
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug=false;
	}
	
	int t;
	scanf("%d",&t);
	
	string path;
	while(t--){
		cin>>path;
		cout<<s.simplifyPath(path)<<endl;
	}
	
	return 0;
}

