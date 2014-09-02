#include<iostream>
#include<cstring>
#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;
bool debug=false;
bool compare(const pair<int,int> &p1 , const pair<int,int> &p2){
	return p1.second>p2.second;
}
class Solver{
	vector<pair<int,int> > blocks;
	int nBlocks;
	void normalize(int &a , int &b){
		if(a>b){
			a=a^b;
			b=a^b;
			a=a^b;
		}
	}
public:
	Solver(int n):
	nBlocks(n),
	blocks(vector<pair<int,int> >(n)){
		int a,b;
		while(n){
			scanf("%d %d",&a,&b);
			normalize(a,b);
			blocks[n-1]=make_pair(a,b);
			--n;
		}
	}
	int solve(){
		int sum1=blocks[0].second,h1=blocks[0].first;
		int sum2=blocks[0].first,h2=blocks[0].second;
		int temp1,temp2,s1,s2;
		for(int i=1;i<nBlocks;++i){
			s1=sum1;s2=sum2;
			
			temp1=h1-blocks[i].first;temp1=temp1>0?temp1:-temp1;
			temp2=h2-blocks[i].first;temp2=temp2>0?temp2:-temp2;
			if(s1+temp1>s2+temp2) sum1=s1+temp1+blocks[i].second;
			else sum1=s2+temp2+blocks[i].second;
			
			temp1=h1-blocks[i].second;temp1=temp1>0?temp1:-temp1;
			temp2=h2-blocks[i].second;temp2=temp2>0?temp2:-temp2;
			if(s1+temp1>s2+temp2) sum2=s1+temp1+blocks[i].first;
			else sum2=s2+temp2+blocks[i].first;
			
			h2=blocks[i].second;
			h1=blocks[i].first;
			
			if(debug){
				cout<<"sum1 : "<<sum1<<" h1 : "<<h1<<endl;
				cout<<"sum2 : "<<sum2<<" h2 : "<<h2<<endl;
				cout<<endl<<endl;
			}
		}
		return sum1>sum2 ? sum1 : sum2 ;
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t){
		int n;scanf("%d",&n);
		Solver s(n);
		printf("%d\n",s.solve());
		--t;
	}
	return 0;
}