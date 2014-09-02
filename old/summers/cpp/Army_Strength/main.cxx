/*
Project name : Army_Strength
Created on : Sat May 24 12:31:08 2014
Author : Anant Pushkar
http://www.spoj.com/problems/ARMY/
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
bool debug=false;
class Solver{
	int g,m;
	vector<int> gArr , mArr;
public:
	Solver(){
		scanf("%d %d",&g,&m);
		gArr=vector<int>(g);
		mArr=vector<int>(m);
		for(int i=0;i<g;++i)scanf("%d",&gArr[i]);
		for(int i=0;i<m;++i)scanf("%d",&mArr[i]);
		sort(gArr.begin(),gArr.end());
		sort(mArr.begin(),mArr.end());
	}
	string solve(){
		int i=0,j=0;
		while(true){
			if(gArr[i]<mArr[j])++i;
			else ++j;
			if(j==m)return string("Godzilla");
			if(i==g)return string("MechaGodzilla");
		}
	}
};
typedef long long int lld;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t;scanf("%d",&t);
	while(t--){
		Solver s;
		cout<<s.solve()<<endl;
	}
	return 0;
}

