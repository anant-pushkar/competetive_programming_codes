/*
Project name : Between_the_Mountains
Created on : Tue Jun  3 17:39:49 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ACPC11B/
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
class Solver{
	int n1 , n2;
	vector<int> h1 , h2;
	void init(int &n , vector<int> &h){
		scanf("%d",&n);
		h = vector<int>(n);
		for(int i=0;i<n;++i)
			scanf("%d",&h[i]);
		sort(h.begin() , h.end());
	}
	int match(const vector<int> &v1 , const vector<int> &v2){
		int min = INT_MAX , val1 , val2 , val , i1 , i2;
		for(int i=0;i<v2.size();++i){
			i1 = lower_bound(v1.begin() , v1.end() , v2[i]) - v1.begin();
			i2 = upper_bound(v1.begin() , v1.end() , v2[i]) - v1.begin();
			i1 = i1<v1.size() && i1>-1 && v1[i1]>v2[i] ? i1-1 : i1;
			
			val1 = i1<v1.size() ? abs(v2[i] -v1[i1]) : INT_MAX ;
			val2 = i2<v1.size() ? abs(v1[i2]- v2[i]) : INT_MAX ;
			
			val = val1<val2 ? val1 : val2 ;
			if(debug)cout<<"h = "<<v2[i]<<" h1:"<<v1[i1]<<" h2:"<<v1[i2]<<endl;
			min = min < val ? min  : val  ;
			if(min == 0)
				break;
		}
		return min;
	}
public:
	Solver(){
		init(n1,h1);
		init(n2,h2);
	}
	int solve(){
		return match(n1>n2 ? h1 : h2 , n1<=n2 ? h1 : h2);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	while(t--){
		Solver s;
		printf("%d\n",s.solve());
	}
	return 0;
}

