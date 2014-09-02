#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
string getNum(int N){
	string num="";
	if(N<3) return "-1";
	if(N==3) return "555";
	if(N==4) return "-1";
	if(N==5) return "33333";
	if(N%3==0){
		for(int i=0;i<N;i++) num+="5";
		return num;
	}
	vector<pair<int,int> >lookup(N+1,make_pair(-1,-1));
	lookup[3]=make_pair(3,0);
	lookup[5]=make_pair(0,5);
	for(int i=6;i<=N;i++){
		if(lookup[i-3].first!=-1){
			lookup[i].first=lookup[i-3].first+3;
			lookup[i].second=lookup[i-3].second;
		}else if(lookup[i-5].first!=-1){
			lookup[i].first=lookup[i-5].first;
			lookup[i].second=lookup[i-5].second+5;
		}
	}
	/*cout<<"lookup : "<<endl;
	for(int i=0;i<=N;i++) cout<<lookup[i].first<<" "<<lookup[i].second<<endl;
	cout<<endl;*/
	if(lookup[N].first==-1) return "-1";
	for(int i=0;i<lookup[N].first;i++) num="5"+num;
	for(int i=0;i<lookup[N].second;i++) num=num+"3";
	return num;
}
int main() {
    int T,N;cin>>T;
	for(int t=0;t<T;t++){
		cin>>N;
		cout<<getNum(N)<<endl;
	}
    return 0;
}
