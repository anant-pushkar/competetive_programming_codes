/*
Project name : Maximal_Rectangle
Created on : Tue Sep 30 22:06:56 2014
Author : Anant Pushkar
00010111
01100101
10111101
00010000
00100010
11100111
10011001
01001100
10010000
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
typedef long long int lld;
typedef unsigned long long int llu;
class Solution {
public:
	bool debug;
    int maximalRectangle(vector<vector<char> > &matrix) {
    	int n = matrix.size();
    	if(n==0){
    		return 0;
    	}
    	int m = matrix[0].size();
    	vector<vector<int> > parent(n , vector<int>(m , 0));
    	for(int i=1;i<n;++i){
    		for(int j=0;j<m;++j)if(matrix[i][j]=='1'){
    			if(matrix[i-1][j]=='1'){
    				parent[i][j] = parent[i-1][j];
    			}else{
    				parent[i][j] = i;
    			}
    		}
    	}
    	if(debug){
    		cout<<"Grid : "<<endl;
    		for(int i=0;i<n;++i){
    			for(int j=0;j<m;++j){
    				cout<<matrix[i][j]<<" ";
    			}
    			cout<<endl;
    		}
    		cout<<"=============="<<endl<<"Parent Mat : "<<endl;
			for(int i=0;i<n;++i){
				for(int j=0;j<m;++j){
					cout<<parent[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<"================="<<endl;
		}
    	
    	int max_a=0 , a , index , p;
    	for(int i=0;i<n;++i){
    		for(int j=0;j<m;++j)if(matrix[i][j]=='1'){
    			if(debug)cout<<"At "<<i<<","<<j<<endl;
    			index = j;
    			p = parent[i][j];
    			while(index>-1 && matrix[i][index]=='1'){
    				p = parent[i][index]<=p ? p : parent[i][index];
    				a = (j-index+1)*(i-p+1);
    				max_a = max_a>a ? max_a : a;
    				if(debug)cout<<"\tindex:"<<index<<" p:"<<p<<" a:"<<a<<" max_a:"<<max_a<<endl;
    				--index;
    			}
    			if(debug)cout<<"================="<<endl;
    		}
    	}
        return max_a;
    }
};
int main(int argc , char **argv)
{
	Solution s;
	if(argc>1 && strcmp(argv[1],"DEBUG")==0){
		s.debug=true;
	}else{
		s.debug = false;
	}
	
	int t;
	scanf("%d",&t);
	
	int n,m;
	string row;
	while(t--){
		cin>>n>>m;
		vector<vector<char> > grid(n , vector<char>(m));
		for(int i=0;i<n;++i){
			cin>>row;
			for(int j=0;j<m;++j){
				grid[i][j] = row[j];
			}
		}
		cout<<s.maximalRectangle(grid)<<endl;
	}
	
	return 0;
}

