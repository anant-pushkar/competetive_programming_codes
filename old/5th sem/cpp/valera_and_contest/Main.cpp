/*
Project name : valera_and_contest
Created on : Fri Dec 13 15:24:36 IST 2013
http://codeforces.com/contest/369/problem/B

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int n,k,l,r,sall,sk;
	cin>>n>>k>>l>>r>>sall>>sk;
	vector<int> score(n,0);
	int diff=(sall-sk)-(n-k)*l;
	for(int i=k;i<n;++i){
		score[i]=l+(n!=k?diff/(n-k):0);
	}
	if(n!=k)for(int i=k;i<diff%(n-k)+k;++i)++score[i];
	diff=sk-(n!=k?score[k]:l)*k;
	for(int i=0;i<k;++i){
		score[i]=(n!=k?score[k]:l)+diff/k;
	}
	for(int i=0;i<diff%k;++i)++score[i];
	for(int i=0;i<n;++i)cout<<score[i]<<" ";
	cout<<endl;
	return 0;
}

