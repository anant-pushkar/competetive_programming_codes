/*
Project name : maxSumRec
Created on : Sun Jul 27 12:47:55 2014
Author : Anant Pushkar
find rectangle with maximum sum
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
class MaxRecFinder{
	int m , n;
	vector<vector<int> > grid , h_sum , v_sum , lookup;
	void preprocess_sum(){
		for(int i=0;i<m;++i){
			h_sum[i][0] = grid[i][0];
			for(int j=1;j<n;++j){
				h_sum[i][j] = h_sum[i][j-1] + grid[i][j];
			}
		}
		for(int i=0;i<n;++i){
			v_sum[0][i] = grid[0][i];
			for(int j=1;j<m;++j){
				v_sum[j][i] = v_sum[j-1][i] + grid[j][i];
			}
		}
	}
	inline int get_max(int a , int b){
		return a>b ? a : b;
	}
	void calc_lookup(){
		lookup[m-1][n-1] = grid[m-1][n-1];
		for(int i=m-2;i>-1;--i){
			lookup[i][n-1] = get_max(lookup[i+1][n-1] , 0) + grid[i][n-1];
		}
		for(int i=n-2;i>-1;;--i){
			lookup[m-1][i] = get_max(lookup[m-1][i+1] , 0) + grid[i][n-1];
		}
		
		int sum_right , sum_bottom;
		for(int i=m-2;i>-1;--i){
			for(int j=m-2;j>-1;++j){
				
			}
		}
	}
public:
	MaxRecFinder(int a , int b):
	m(a),
	n(b),
	grid(vector<vector<int> >(a , vector<int>(b))),
	h_sum(vector<vector<int> >(a , vector<int>(b))),
	v_sum(vector<vector<int> >(a , vector<int>(b))),
	lookup(vector<vector<int> >(a , vector<int>(b))){
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&grid[i][j]);
			}
		}
	}
	void find(){
		preprocess_sum();
		calc_lookup();
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t , m , n;
	scanf("%d",&t);
	vector<pair<int,int> > rec;
	
	while(t--){
		scanf("%d %d",&m , &n);
		
		MaxRecFinder mrf(m,n);
		rec = mrf.find();
		mrf.print_rec(rec[0].first , rec[0].second , rec[1].first , rec[1].second);
	}
	return 0;
}

