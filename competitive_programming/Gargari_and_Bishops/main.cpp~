/*
Project name : Gargari_and_Bishops
Created on : Sat Aug 30 13:15:21 2014
Author : Anant Pushkar
http://codeforces.com/contest/463/problem/C
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
struct Soln{
	int x1,x2,y1,y2;
	lld sum;
};
class Solver{
	int n;
	vector<vector<lld> > grid ;
	vector<vector<lld> > right_down , left_up , right_up , left_down , val , max_lookup;
	void print_intermediate(){
		cout<<"RIGHT DOWN : "<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<right_down[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		cout<<"RIGHT UP : "<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<right_up[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		cout<<"LEFT DOWN : "<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<left_down[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		cout<<"LEFT UP : "<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<left_up[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		cout<<"VAL : "<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<val[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		
		cout<<"======================"<<endl;
	}
	void preprocess(){
		for(int i=1;i<n;++i){
			for(int j=1;j<n;++j){
				right_up[i][n-j-1] = grid[i-1][n-j] + right_up[i-1][n-j];
				left_up[i][j]  = grid[i-1][j-1] + left_up[i-1][j-1];
				
				right_down[n-i-1][n-j-1] = grid[n-i][n-j] + right_down[n-i][n-j];
				left_down[n-i-1][j]  = grid[n-i][j-1] + left_down[n-i][j-1];
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				val[i][j]  = grid[i][j] + right_down[i][j] + left_up[i][j] + right_up[i][j] + left_down[i][j];
			}
		}
		lld x , y;
		lld max = INT_MIN;
		for(int s=0;s<2*n-1;s+=2){
			for(int j=0;j<n;++j)if(s-j<n && s-j>-1){
				max = max<val[j][s-j] ? val[j][s-j] : max;
				if(max==val[j][s-j]){
					x = j;
					y = s-j;
				}
				
			}
		}
		for(int s=0;s<2*n-1;s+=2){
			for(int j=0;j<n;++j)if(s-j<n && s-j>-1){
				right_up[j][s-j] = max;
				right_down[j][s-j] = x*n+y;
			}
		}
		
		max = INT_MIN;
		for(int s=1;s<2*n-1;s+=2){
			for(int j=0;j<n;++j)if(s-j<n && s-j>-1){
				max = max<val[j][s-j] ? val[j][s-j] : max;
				if(max==val[j][s-j]){
					x = j;
					y = s-j;
				}
				
			}
		}
		for(int s=1;s<2*n-1;s+=2){
			for(int j=0;j<n;++j)if(s-j<n && s-j>-1){
				right_up[j][s-j] = max;
				right_down[j][s-j] = x*n+y;
			}
		}
		
		max = INT_MIN;
		for(int s=1-n;s<n;s+=2){
			for(int j=0;j<n;++j)if(j-s<n && j-s>-1){
				max = max<val[j][j-s] ? val[j][j-s] : max;
				if(max==val[j][j-s]){
					x = j;
					y = j-s;
				}
			}
		}
		for(int s=1-n;s<n;s+=2){
			for(int j=0;j<n;++j)if(j-s<n && j-s>-1){
				left_up[j][j-s] = max;
				left_down[j][j-s] = x*n+y;
			}
		}
		
		max = INT_MIN;
		for(int s=2-n;s<n;s+=2){
			for(int j=0;j<n;++j)if(j-s<n && j-s>-1){
				max = max<val[j][j-s] ? val[j][j-s] : max;
				if(max==val[j][j-s]){
					x = j;
					y = j-s;
				}
			}
		}
		for(int s=2-n;s<n;s+=2){
			for(int j=0;j<n;++j)if(j-s<n && j-s>-1){
				left_up[j][j-s] = max;
				left_down[j][j-s] = x*n+y;
			}
		}
		
		
		if(debug){
			print_intermediate();
		}
	}
	Soln solve(){
		Soln s;
		s.sum = INT_MIN;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i>0  && s.sum<val[i][j]+right_up[i-1][j]){
					s.x1=i;
					s.y1=j;
					s.x2=right_down[i-1][j]/n;
					s.y2=right_down[i-1][j]%n;
					s.sum = val[i][j]+right_up[i-1][j];
				}
				
				if(i<n-1 && s.sum<val[i][j]+right_up[i+1][j]){
					s.x1=i;
					s.y1=j;
					s.x2=right_down[i+1][j]/n;
					s.y2=right_down[i+1][j]%n;
					s.sum = val[i][j]+right_up[i+1][j];
				}
				
				if(j<n-1 && s.sum<val[i][j]+left_up[i][j+1]){
					s.x1=i;
					s.y1=j;
					s.x2=left_down[i][j+1]/n;
					s.y2=left_down[i][j+1]%n;
					s.sum = val[i][j]+left_up[i][j+1];
				}
				
				if(j>0 && s.sum<val[i][j]+left_up[i][j-1]){
					s.x1=i;
					s.y1=j;
					s.x2=left_down[i][j-1]/n;
					s.y2=left_down[i][j-1]%n;
					s.sum = val[i][j]+left_up[i][j-1];
				}
			}
		}
		return s;
	}
public:
	Solver(int x):
	n(x),
	grid(vector<vector<lld> >(x , vector<lld>(x,0))),
	left_up(vector<vector<lld> >(x , vector<lld>(x,0))),
	left_down(vector<vector<lld> >(x , vector<lld>(x,0))),
	right_up(vector<vector<lld> >(x , vector<lld>(x,0))),
	right_down(vector<vector<lld> >(x , vector<lld>(x,0))),
	val(vector<vector<lld> >(x , vector<lld>(x,0))),
	max_lookup(vector<vector<lld> >(x , vector<lld>(x,0))){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>grid[i][j];
			}
		}
		preprocess();
	}
	void print_soln(){
		Soln s = solve();
		cout<<s.sum<<endl;
		cout<<s.x1+1<<" "<<s.y1+1<<" "<<s.x2+1<<" "<<s.y2+1<<endl;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;
	scanf("%d",&n);
	
	Solver s(n);
	s.print_soln();
	
	return 0;
}

