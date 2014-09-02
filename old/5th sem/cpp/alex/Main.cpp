#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int getCount(int n , int m){
	if(n==1 || m==1) return n+m-1;
	if(n&1){
		if(m&1){
			return n*m;
		}else{
			return (n*m) - (n-2)*(m-2);
		}
	}else{
		return 2*n;
	}
}
void nextDir(pair<int,int> &dir){
	if(dir.first==1){
		dir.first=0;
		dir.second=1;
		return;
	}
	if(dir.first==-1){
		dir.first=0;
		dir.second=-1;
		return;
	}
	if(dir.second==1){
		dir.first=-1;
		dir.second=0;
		return;
	}
	if(dir.second==-1){
		dir.first=1;
		dir.second=0;
		return;
	}
}
int check( pair<int,int> &pos , const vector< vector<int> > &lookup , pair<int,int> &dir, int n , int m){
	for(int i=0;i<4;i++){
		nextDir(dir);	
		cout<<"Dir : "<<dir.first<<","<<dir.second<<endl;
		cout<<"Checking at "<<pos.first+dir.first<<","<<pos.second+dir.second<<endl;
		if(pos.first+dir.first < 0 || pos.first+dir.first >= n){cout<<"x out of bound"<<endl;}
		else if(pos.second+dir.second >= m || pos.second+dir.second < 0){cout<<"y out of bound"<<endl;}
		else if(lookup[pos.first+dir.first][pos.second+dir.second]==-1){
			cout<<"Moving"<<endl;
			pos.first+=dir.first;
			pos.second+=dir.second;
			return 1;
		}
	}	
	return 0;
}
void printMap(int n , int m){
	vector< vector<int> > lookup(n,vector<int>(m,-1));
	pair<int,int> dir=make_pair(0,-1),pos=make_pair(0,0);
	int count=1;
	do{
		lookup[pos.first][pos.second]=count;
		cout<<"At "<<pos.first<<","<<pos.second<<endl;
		count++;
	}while(check(pos,lookup,dir,n,m)==1);
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			cout<<lookup[i][j]<<"\t";
		}
		cout<<endl;
	}
}	
int main()
{
	int T,n,m;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>n>>m;
		cout<<getCount(n,m)<<endl;
		printMap(n,m);
	}
	return 0;
}
