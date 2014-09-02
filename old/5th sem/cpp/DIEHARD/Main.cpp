#include<iostream>
#include<cstring>
#include<cstdio>
#include<utility>
#include<map>
#include<vector>
using namespace std;
bool debug=false;
const int AIR=1 , WATER=2 , FIRE=3;
struct Place{
	int type;
	
	Place(int p):
	type(p){}
	
	int health(){
		switch(type){
		case AIR:
			return 3;
		case WATER:
			return -5;
		case FIRE:
			return -20;
		}
	}
	
	int armor(){
		switch(type){
		case AIR:
			return 2;
		case WATER:
			return -10;
		case FIRE:
			return 5;
		}
	}
};
class Solver{
	int health,armor;
	map< pair< pair<int,int> , int> , long long int > lookup;
	void print(pair< pair<int,int> , int> state){
		cout<<"\n\tHealth : "<<state.first.first;
		cout<<"\n\tArmor : "<<state.first.second;
		cout<<"\n\tPlace : ";
		switch(state.second){
		case AIR:
			cout<<"Air";
			break;
		case WATER:	
			cout<<"Water";
			break;
		case FIRE:
			cout<<"Fire";
			break;
		}
		cout<<endl;
	}
	long long int recurse(pair< pair<int,int> , int> state , long long int count){
		if(debug){
			cout<<"recurse called on :";
			print(state);
			cout<<endl;
		}
		if(lookup.find(state)!=lookup.end())return lookup[state];
		if(state.first.first<=0 || state.first.second<=0){
			lookup[state]=count;
			return count;
		}
		int index=0 ;
		pair< pair<int,int> , int> newState;
		vector<long long int> childCount(2,0);
		for(int i=1;i<4;++i)if(state.second!=i){
			Place p(i);
			newState.first.first = state.first.first + p.health();
			newState.first.second = state.first.second + p.armor();
			newState.second = i;
			
			childCount[index++]=recurse(newState , count+1);
		}
		int maxCount=childCount[0]>childCount[1] ? childCount[0] : childCount[1] ;
		lookup[state]=maxCount;
		return maxCount;
	}
public:
	Solver(int h,int a):
	health(h),
	armor(a){}
	
	long long int solve(){
		pair< pair<int,int> , int> state;
		Place p(AIR);
		
		state.first.first=health+p.health();
		state.first.second=armor+p.armor();
		state.second=AIR;
		
		return recurse(state,0);
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,h,a;scanf("%d",&t);
	while(t){
		scanf("%d %d",&h,&a);
		Solver s(h,a);
		printf("%lld\n",s.solve());
		--t;
	}
	return 0;
}

