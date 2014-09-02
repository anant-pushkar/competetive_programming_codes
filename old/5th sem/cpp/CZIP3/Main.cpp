#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n,k,countInc,countDec;scanf("%d",&t);
	vector<char> v;
	char cMax,cMin;
	while(t){
		cin>>n>>k;
		v=vector<char>(n);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		countInc=0;countDec=0;cMin=v[0];cMax=v[0];
		for(int i=1;i<n;++i){
			if(v[i]-cMin>0){
				countDec+=2;
			}else{
				cMin=v[i];
			}
			if(cMax-v[i]>0){
				countInc+=2;
			}else{
				cMax=v[i];
			}
		}
		int count=countDec<countInc+1 ? countDec : countInc+1;
		printf("%d\n",count);
		--t;
	}
	return 0;
}

