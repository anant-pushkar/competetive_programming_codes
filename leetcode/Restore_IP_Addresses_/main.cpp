/*
Project name : Restore_IP_Addresses_
Created on : Tue Sep 30 12:32:17 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/restore-ip-addresses/
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
class Solution {
    vector<stack<int> > segment(const string s , int index , int level){
    	if(debug){
    		cout<<"called on "<<s.substr(0,index+1)<<" , level : "<<level<<endl;
    	}
        if(level==3){
        	lld val = 0;
        	while(index<s.size()){
        		val = val*10 + s[index++]-'0';
        	}
            return val<256 ? vector<stack<int> >(1,stack<int>())  : vector<stack<int> >(0);
        }
        vector<stack<int> > soln ;
        int val=s[index]-'0';
        if(debug)cout<<"val : "<<val<<endl;
        vector<stack<int> > temp = segment(s , index+1 , level+1);
        for(int i=0;i<temp.size();++i){
            temp[i].push(index+1);
            soln.push_back(temp[i]);
        }
        if(index<s.size()-1){
            val = val*10 + s[index+1]-'0';
            if(debug)cout<<"val : "<<val<<endl;
            if(val<10){
                return soln;;
            }
            temp = segment(s,index+2,level+1);
            for(int i=0;i<temp.size();++i){
                temp[i].push(index+2);
                soln.push_back(temp[i]);
            }
            if(index<s.size()-2){
                val = val*10 + s[index+2]-'0';
                if(debug)cout<<"val : "<<val<<endl;
                if(val<100){
                    return soln;
                }
                if(val<256){
                    temp = segment(s,index+3,level+1);
                    for(int i=0;i<temp.size();++i){
                        temp[i].push(index+3);
                        soln.push_back(temp[i]);
                    }
                }
            }
        }
        return soln;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<stack<int> > soln = segment(s,0,0);
        vector<string> ans;
        int idx=0;
        int size = soln.size() , len = s.size();
        bool check=false;
        if(debug)cout<<"extracting soln"<<endl;
        for(int i=0;i<size;++i){
        	check = false;
            char str[s.size()+3];
            int index=0;
            int count = 0;
            if(soln[i].size()!=3){
            	continue;
            }
            if(debug)cout<<"starting "<<i<<endl;
            for(int j=0;j<len;++j){
            	if(debug)cout<<"adding "<<j<<" index : "<<index<<endl;
            	if(!soln[i].empty() && j==soln[i].top()){
                    str[index++] = '.';
                    if(index>=s.size()+3){
                    	check = true;
                    	continue;
                    }
                    ++count;
                    soln[i].pop();
                    if(s[j]=='0'){
                    	if((soln[i].empty() && j==len-1) || (!soln[i].empty() && soln[i].top()==j+1) ){
                    	
                    	}else{
	                    	check = true;
	                    	continue;
	                    }
                    }
                }
                if(debug)cout<<"here"<<endl;
                str[index++] = s[j];
                if(count!=3 && soln[i].empty()){
                	check = true;
                	continue;
                }
            }
            if(check || count!=3){
            	check = false;
            	continue;
            }
            if(debug)cout<<"adding "<<str<<endl;
            str[len+3] = '\0';
            ans.push_back(string(str));
        }
        return ans;
    }
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	Solution s;
	string str;
	while(t--){
		cin>>str;
		if(debug)cout<<str<<endl;
		vector<string> soln = s.restoreIpAddresses(str);
		for(int i=0;i<soln.size();++i){
			cout<<soln[i]<<endl;
		}
	}
	return 0;
}

