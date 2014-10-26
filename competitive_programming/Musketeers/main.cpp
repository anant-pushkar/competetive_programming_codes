/*
Project name : Musketeers
Created on : Thu Oct 16 22:01:17 2014
Author : Anant Pushkar
http://www.spoj.com/problems/MUSKET/
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
#include<set>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n;
	vector<string> grid;
	set<int> soln;
	void solve(){
		vector<vector<bool> > scope(n , vector<bool>(n,false));
		for(int i=0;i<n;++i){
			scope[i][i] = true;
		}
		int j;
		for(int i=0;i<n;++i){
			scope[i][i] = true;
			j = (i+1)%n;
			while(j!=i && grid[i][j]=='1'){
				scope[i][j] = true;
				++j;
				j = j%n;
			}
			
			j = (i-1+n)%n;
			while(i!=j && grid[i][j]=='1'){
				scope[i][j] = true;
				--j;
				j = (j+n)%n;
			}
		}
		for(int x=0;x<n;++x){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j)if(i!=j && scope[i][j]){
					if(debug)cout<<i<<","<<j<<endl;
					for(int k=0;k<n;++k){
						scope[i][k] = scope[i][k] || scope[j][k];
					}
				}
				if(debug){
					for(int i=0;i<n;++i){
						for(int j=0;j<n;++j){
							cout<<scope[i][j];
						}
						cout<<endl;
					}
					cout<<"============"<<endl;
				}
			}
		}
		if(debug){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					cout<<scope[i][j];
				}
				cout<<endl;
			}
		}
		bool check;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)if(i!=j && grid[i][j]=='1'){
				check = true;
				for(int k=0;k<n;++k){
					check = check && ( scope[i][k] || scope[j][k] );
					if(!check){
						break;
					}
				}
				if(check){
					soln.insert(i+1);
					break;
				}
			}
		}
	}
public:
	Solver(){
		scanf("%d",&n);
		grid = vector<string>(n);
		for(int i=0;i<n;++i){
			cin>>grid[i];
		}
	}
	void print_soln(){
		solve();
		cout<<soln.size()<<endl;
		
		set<int>::iterator it=soln.begin();
		for(;it!=soln.end();++it){
			cout<<*it<<endl;
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	while(t--){
		Solver s;
		s.print_soln();
	}
	
	return 0;
}


