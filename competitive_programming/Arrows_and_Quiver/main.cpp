/*
Project name : Arrows_and_Quiver
Created on : Thu Oct  9 22:24:17 2014
Author : Anant Pushkar
https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=606&page=show_problem&problem=4744
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
#include<map>
using namespace std;
bool debug=false;
typedef long long int lld;
typedef unsigned long long int llu;
class Solver{
	int n , m , c;
	vector<int> arrow;
	bool is_valid(int q){
		vector<bool> is_present(n , false);
		vector<int>  last_used(n,INT_MIN);
		map<int,int> lookup;
		map<int,int>::iterator it;
		
		int time=0;
		for(int i=0;i<m;++i){
			if(!is_present[arrow[i]]){
				if(debug)cout<<arrow[i]+1<<" not found"<<endl;
				if(lookup.size()<q){
					if(debug)cout<<"\tno replacement needed"<<endl;
					lookup[i] = arrow[i];
					last_used[arrow[i]] = i;
					is_present[arrow[i]] = true;
				}else{
					it = lookup.begin();
					last_used[it->second] = INT_MIN;
					is_present[it->second]= false;
					
					if(debug)cout<<"\treplacing "<<it->second+1<<endl;
					
					lookup.erase(it);
					lookup[i] = arrow[i];
					last_used[arrow[i]] = i;
					is_present[arrow[i]]= true;
				}
				++time;
				if(debug)cout<<"time : "<<time<<endl;
				if(time>c){
					if(debug)cout<<q<<" not possible"<<endl;
					return false;
				}
			}else{
				if(debug)cout<<arrow[i]+1<<" found. Updating"<<endl;
				it = lookup.find(last_used[arrow[i]]);
				lookup.erase(it);
				lookup[i] = arrow[i];
				last_used[arrow[i]] = i;
			}
		}
		
		if(debug)cout<<"time for "<<q<<" : "<<time<<endl;
		return time<=c;
	}
public:
	Solver(){
		scanf("%d %d %d",&n,&m,&c);
		if(debug)cout<<"MAX TIME : "<<c<<endl;
		arrow = vector<int>(m);
		for(int i=0;i<m;++i){
			scanf("%d",&arrow[i]);
			--arrow[i];
		}
	}
	int solve(){
		int start=1 , end=m+1 , mid;
		while(end>start+1){
			mid = (start+end)/2;
			if(debug)cout<<"===================="<<endl<<"seraching for "<<mid<<endl;
			if(is_valid(mid)){
				end   = mid;
			}else{
				start = mid;
			}
		}
		if(debug)cout<<"returning "<<end<<endl<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
		return end>m ? -1 : end;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;
	scanf("%d",&t);
	
	int n , m , c;
	while(t--){
		Solver s;
		printf("%d\n",s.solve());
	}
	
	return 0;
}

