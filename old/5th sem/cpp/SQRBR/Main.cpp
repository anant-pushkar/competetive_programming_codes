#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
bool debug=false;
class Solver{
	map<pair<pair<int,int> , int> , int> mem;
	vector<int> s;
	int size;
	int getCount(int start , int end , int level , int index){
		if(debug)cout<<"\n\nCalled on start="<<start<<" end="<<end<<" level="<<level<<" index="<<index<<endl;
		if(end-start==1){
			if(level==1 && index==s.size()){
				if(debug)cout<<"Returning with 1"<<endl;
				return 1;
			}
			if(debug)cout<<"Returning with 0"<<endl;
			return 0;
		}
		if(level>end-start){
			if(debug)cout<<"Returning with 0 due to overflow"<<endl;
			return 0;
		}
		pair<pair<int,int> , int> instance=make_pair(make_pair(start,end),level);
		if(mem.find(instance)!=mem.end()){
			if(debug)cout<<"memoization found:"<<mem[instance]<<endl;
			return mem[instance];
		}
		int count=0;
		if(index<s.size() && start==s[index]){
			++index;
		}else if(level>0){
			count+=getCount(start+1,end,level-1,index);
		}
		count+=getCount(start+1,end,level+1,index);
		mem[instance]=count;
		if(debug)cout<<"Returning "<<start<<","<<end<<","<<level<<" with "<<count<<endl;
		return count;
	}
public:
	Solver(int n , int k):
	s(vector<int>(k,-1)),
	size(2*n){
		for(int i=0;i<k;++i){
			scanf("%d",&s[i]);
			--s[i];
		}
	}
	int solve(){
		return getCount(0,size,0,0);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,k;scanf("%d",&t);
	while(t){
		scanf("%d %d",&n,&k);
		Solver s(n,k);
		printf("%d\n",s.solve());
		--t;
	}
	return 0;
}

