/*
Project name : Substring_with_Concatenation_of_All_Words
Created on : Sun Oct  5 13:13:30 2014
Author : Anant Pushkar
https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
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
class Solution{
typedef unsigned long long int llu;
	bool is_valid(const string S , unordered_map<string,int> &wordlist , int index , int len , int l){
		if(debug)cout<<"checking vaidity of "<<index<<endl;
		unordered_map<string,int> count;
		for(int i=0;i<l;++i){
			string str = S.substr(index+i*len , len);
			if(debug)cout<<"checking "<<str<<endl;
			if(wordlist.find(str)!=wordlist.end() && wordlist[str]>count[str]){
				if(debug)cout<<"Adding "<<str<<endl;
				++count[str];
			}else{
				return false;
			}
		}
		unordered_map<string,int>::iterator it=wordlist.begin();
		for(;it!=wordlist.end();++it)if(count.find(it->first)==count.end() || count[it->first]!=it->second){
			return false;
		}
		return true;
	}
public:
	bool debug;
	vector<int> findSubstring(string S, vector<string> &L) {
        int n=L.size();
        vector<int> result;
        if(n==0){
        	return result;
        }
        int len=L[0].size() , l=S.size();
        unordered_map<string , int> wordlist;
        for(int i=0;i<n;++i){
        	if(debug)cout<<"Adding "<<L[i]<<" to wordlist"<<endl;
        	++wordlist[L[i]];
        }
        
        for(int i=0;i+n*len-1<l;++i){
        	if(debug)cout<<"checking "<<i<<endl;
        	if(is_valid(S,wordlist,i,len,n)){
        		result.push_back(i);
        	}
        }
        
        return result;
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
	
	int n;
	string str;
	while(t--){
		cin>>str;
		cin>>n;
		vector<string> L(n);
		for(int i=0;i<n;++i){
			cin>>L[i];
		}
		vector<int> soln = s.findSubstring(str,L);
		for(int i=0;i<soln.size();++i){
			cout<<soln[i]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

