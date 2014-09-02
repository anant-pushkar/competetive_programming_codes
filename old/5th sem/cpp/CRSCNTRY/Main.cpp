/*
Project name : CRSCNTRY
Created on : Fri Dec  6 23:52:17 IST 2013
http://www.spoj.com/problems/CRSCNTRY/

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<deque>
using namespace std;
bool debug=false;
deque<deque<int> > routes;
deque<int> mainRoute;
void readMain(deque<int> &d){
	int n;
	while(1){
		scanf("%d",&n);if(n==0)break;
		d.push_back(n);
	}
	if(debug){
		cout<<"Route read : ";
		for(int i=0;i<d.size();++i){
			cout<<d[i]<<" ";
		}
		cout<<endl;
	}
}
void readAll(){
	int n,i=0;
	while(1){
		scanf("%d",&n);if(n==0)break;
		routes.push_back(deque<int>(1,n));
		readMain(routes[i++]);
	}
}
int getLCS(const deque<int> &d1 , const deque<int> &d2){
	vector<vector<int> >lookup(d1.size(),vector<int>(d2.size(),0));
	if(d1[0]==d2[0])lookup[0][0]=1;
	for(int i=1;i<d1.size();++i){
		lookup[i][0]=lookup[i-1][0]|(d1[i]==d2[0]?1:0);
	}
	for(int j=1;j<d2.size();++j){
		lookup[0][j]=lookup[0][j-1]|(d1[0]==d2[j]?1:0);
	}
	for(int i=1;i<d1.size();++i){
		for(int j=1;j<d2.size();++j){
			if(d1[i]==d2[j]){
				lookup[i][j]=lookup[i-1][j-1]+1;
			}
			else {
				lookup[i][j]=lookup[i-1][j]>lookup[i][j-1]?lookup[i-1][j]:lookup[i][j-1];
			}
		}
	}
	if(debug){
		for(int i=0;i<d1.size();++i){
			for(int j=0;j<d2.size();++j){
				cout<<lookup[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return lookup[d1.size()-1][d2.size()-1];
}
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,max,val;scanf("%d",&t);
	while(t--){
		readMain(mainRoute);
		readAll();
		
		max=0;
		for(int i=0;i<routes.size();++i){
			val=getLCS(mainRoute,routes[i]);
			max=max<val?val:max;
		}
		printf("%d\n",max);
		
		routes.clear();
		mainRoute.clear();
	}
	return 0;
}

