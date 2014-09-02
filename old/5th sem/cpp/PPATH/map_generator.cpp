#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<deque>
using namespace std;
int main(){
	vector<bool>lookup(10000,true);
	for(int i=2;i<10000;++i){
		if(lookup[i]){
			for(int j=2*i;j<10000;++j)if(j%i==0)lookup[j]=false;
		}
	}
	map<int,int> indexOf;
	int index=0;
	printf("int primeList = { 2");
	for(int i=3;i<10000;++i)if(lookup[i]) {
		indexOf[i]=index++;
		printf(" , %d",i);
	}
	printf("};");
	vector<deque<int> > adjList(indexOf.size());
	index=0;
	int num,temp,l;
	for(int i=2;i<10000;++i)if(lookup[i]){
		num=i;l=1;
		while(num>0){
			temp=i-(num%10)*l;
			for(int j=0;j<=9;++j){
				if(i!=num%10 && indexOf.find(temp+j*l)!=indexOf.end()){
					adjList[indexOf[i]].push_back(indexOf[temp+j*l]);
				}
			}
			l*=10;
			num=num/10;
		}
		++index;
	}
	/*for(int i=0;i<adjList.size();++i){
		printf("%d : ",i);
		for(int j=0;j<adjList[i].size();++j){
			printf("%d ",adjList[i][j]);
		}
		printf("\n");
	}*/
	printf("\n\nint adjList = { { %d ",adjList[0][0]);
	for(int i=1;i<adjList[0].size();++i){
		printf(" , %d",adjList[0][i]);
	}
	printf(" } ");
	for(int i=1;i<adjList.size();++i){
		printf(" , { %d ",adjList[i][0]);
		for(int j=1;j<adjList[i].size();++j){
			printf(" , %d",adjList[i][j]);
		}
		printf(" } ");
	}
	printf(" } ;\n");
	return 0;
}