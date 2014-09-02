#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
bool debug=false;
bool compare(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.first<p2.first;
}
inline bool match(const pair<int,int> &p1 , const pair<int,int> &p2){
	return ( abs(p1.first-p2.first)==abs(p2.second-p1.second) ) || p1.second==p2.second ;
}
vector<pair<int,int> > ptArr;
map<int,int> follow;
vector<bool>lookup;
ostream& operator<<(ostream& out , pair<int,int> p){
	out<<" "<<p.first<<","<<p.second<<" ";
	return out;
}
static int callId=0;
int getFollow(int index){
	if(debug)cout<<callId++<<" getFollow called on "<<ptArr[index]<<endl;
	if(follow.find(index)!=follow.end()){
		return follow[index];
	}
	if(index>=ptArr.size()-1){
		return 0;
	}
	int max=-1,f=-1,idx=-1;
	for(int i=index+1;i<ptArr.size();++i){	
		if(match(ptArr[i],ptArr[index])){
			f=getFollow(i);
			if(debug)cout<<"Finding "<<ptArr[i]<<endl;
			if(max<f){
				max=f;
				idx=i;
			}
		}
		if(debug)cout<<"match failed at "<<ptArr[i]<<"("<<(max < (ptArr.size()-i))<<")"<<endl;
	}
	if(debug)cout<<"removing "<<ptArr[idx]<<endl;
	follow[index]=f+1;
	if(idx!=-1)lookup[idx]=false;
	if(debug)cout<<"returning from call "<<--callId<<endl<<endl;
	return f+1;
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n;scanf("%d",&n);
	ptArr = vector<pair<int,int> >(n);
	lookup= vector<bool>(n,true);
	while(n--){
		scanf("%d %d",&ptArr[n].first,&ptArr[n].second);
	}
	sort(ptArr.begin(),ptArr.end(),compare);
	
	int count=0;
	for(int i=0;i<ptArr.size();++i){
		if(lookup[i]){
			getFollow(i);
			++count;
		}
	}
	printf("%d\n",count);
	
	return 0;
}

