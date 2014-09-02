/*
Project name : manhatten_2025
Created on : Fri Dec  6 15:59:01 IST 2013
http://poj.org/problem?id=1806

*/

#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
bool debug=false;
class Cube{
	int n,size;
	vector<vector<vector<char> > > slices;
	void spread(){
		int base;
		for(int l=0;l<size;++l){
			base = l>n ? 2*n-l : l ;
			for(int q=0;q<base;++q){
				for(int i=0;i<size;++i){
					for(int j=0;j<size;++j)if(slices[l][i][j]!='.' && slices[l][i][j]-'0'<n){
						if(i-1>=0 && slices[l][i-1][j]=='.')slices[l][i-1][j]=slices[l][i][j]+'1'-'0';
						if(i+1<size && slices[l][i+1][j]=='.')slices[l][i+1][j]=slices[l][i][j]+'1'-'0';
						if(j-1>=0 && slices[l][i][j-1]=='.')slices[l][i][j-1]=slices[l][i][j]+'1'-'0';
						if(j+1<size && slices[l][i][j+1]=='.')slices[l][i][j+1]=slices[l][i][j]+'1'-'0';
					}
				}
			}
		}
	}
public:
	Cube(int num):
	n(num),
	size(2*num+1),
	slices(vector<vector<vector<char> > >(2*num+1 , vector<vector<char> >(2*num+1,vector<char>(2*num+1,'.')))){
		slices[n][n][n]='0';
		for(int i=1;i<=n;++i){
			slices[n-i][n][n]=i+'0';
			slices[n+i][n][n]=i+'0';
		}
		spread();
	}
	void print(){
		for(int i=0;i<size;++i){
			printf("slice #%d:\n",i+1);
			for(int j=0;j<size;++j){
				for(int k=0;k<size;++k){
					printf("%c",slices[i][j][k]);
				}
				printf("\n");
			}
		}
	}
};
int main(int argc , char **argv)
{
	if(argc>1 && strcmp(argv[1],"DEBUG")==0) debug=true;
	int t,n;scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%d",&n);
		Cube c(n);
		printf("Scenario #%d:\n",i+1);
		c.print();
		printf("\n");
	}
	return 0;
}

